
# thanks to sfml for the cmake sample code for the Marcos.cmake modular library
# https://github.com/SFML/SFML/blob/2.6.x/cmake/Macros.cmake

macro (mkcde_set_xcode_property TARGET XCODE_PROPERTY XCODE_VALUE)
    set_property (TARGET ${TARGET} PROPERTY XCODE_ATTRIBUTE_${XCODE_PROPERTY} ${XCODE_VALUE})
endmacro ()

function(mkcde_set_stdlib target)
    if(MKCDE_OS_WINDOWS AND MKCDE_COMPILER_GCC AND NOT MKCDE_GCC_VERSION VERSION_LESS "4")
        if(MKCDE_USE_STATIC_STD_LIBS AND NOT MKCDE_COMPILER_GCC_TDM)
            target_link_libraries(${target} PRIVATE "-static-libgcc" "-static-libstdc++")
        elseif(NOT MKCDE_USE_STATIC_STD_LIBS AND MKCDE_COMPILER_GCC_TDM)
            target_link_libraries(${target} PRIVATE "-shared-libgcc" "-shared-libstdc++")
        endif()
    endif()

    if(${CMAKE_GENERATOR} MATCHES "Xcode")
        mkcde_set_xcode_property(${target} CLANG_CXX_LIBRARY "libc++")
    endif()
endfunction()


function(mkcde_set_common_ios_properties target)
    # enable automatic reference counting on iOS
    mkcde_set_xcode_property(${target} CLANG_ENABLE_OBJC_ARC YES)
    mkcde_set_xcode_property(${target} IPHONEOS_DEPLOYMENT_TARGET "${MKCDE_IOS_DEPLOYMENT_TARGET}")
    mkcde_set_xcode_property(${target} CODE_SIGN_IDENTITY "${MKCDE_CODE_SIGN_IDENTITY}")

    get_target_property(target_type ${target} TYPE)
    if (target_type STREQUAL "EXECUTABLE")
        set_target_properties(${target} PROPERTIES
            MACOSX_BUNDLE TRUE # Bare executables are not usable on iOS, only bundle applications
            MACOSX_BUNDLE_GUI_IDENTIFIER "org.mister-mir.${target}" # If missing, trying to launch an example in simulator will make Xcode < 9.3 crash
            MACOSX_BUNDLE_BUNDLE_NAME "${target}"
            MACOSX_BUNDLE_LONG_VERSION_STRING "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}"
        )
    endif()
endfunction()


# add a new target which is a MKCDE library
# example: mkcde_add_library(mkcde-graphics
#                           SOURCES sprite.cpp image.cpp ...
#                           [STATIC]) # Always create a static library and ignore BUILD_SHARED_LIBS
macro(mkcde_add_library target)
    # parse the arguments
    cmake_parse_arguments(THIS "STATIC" "" "SOURCES" ${ARGN})
    if (NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments when calling mkcde_add_library: ${THIS_UNPARSED_ARGUMENTS}")
    endif()

    # create the target
    if (THIS_STATIC)
        add_library(${target} STATIC ${THIS_SOURCES})
    else()
        add_library(${target} ${THIS_SOURCES})
    endif()

    #set_file_warnings(${THIS_SOURCES})

    # define the export symbol of the module
    string(REPLACE "-" "_" NAME_UPPER "${target}")
    string(TOUPPER "${NAME_UPPER}" NAME_UPPER)
    set_target_properties(${target} PROPERTIES DEFINE_SYMBOL ${NAME_UPPER}_EXPORTS)

    # adjust the output file prefix/suffix to match our conventions
    if(BUILD_SHARED_LIBS AND NOT THIS_STATIC)
        if(MKCDE_OS_WINDOWS)
            # include the major version number in Windows shared library names (but not import library names)
            set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -d)
            set_target_properties(${target} PROPERTIES SUFFIX "-${VERSION_MAJOR}${CMAKE_SHARED_LIBRARY_SUFFIX}")

            # fill out all variables we use to generate the .rc file
            string(TIMESTAMP RC_CURRENT_YEAR "%Y")
            string(REGEX REPLACE "mkcde-([a-z])([a-z]*)" "\\1" RC_MODULE_NAME_HEAD "${target}")
            string(REGEX REPLACE "mkcde-([a-z])([a-z]*)" "\\2" RC_MODULE_NAME_TAIL "${target}")
            string(TOUPPER "${RC_MODULE_NAME_HEAD}" RC_MODULE_NAME_HEAD)
            set(RC_MODULE_NAME "${RC_MODULE_NAME_HEAD}${RC_MODULE_NAME_TAIL}")
            set(RC_VERSION_SUFFIX "") # Add something like the git revision short SHA-1 in the future
            set(RC_PRERELEASE "0") # Set to 1 to mark the DLL as a pre-release DLL
            set(RC_TARGET_NAME "${target}")
            set(RC_TARGET_FILE_NAME_SUFFIX "-${VERSION_MAJOR}${CMAKE_SHARED_LIBRARY_SUFFIX}")

            # generate the .rc file
            configure_file(
                "${MKCDE_SOURCE_DIR}/tools/windows/resource.rc.in"
                "${CMAKE_CURRENT_BINARY_DIR}/${target}.rc"
                @ONLY
            )
            target_sources(${target} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/${target}.rc")
            source_group("" FILES "${CMAKE_CURRENT_BINARY_DIR}/${target}.rc")
        else()
            set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -d)
        endif()
        if (MKCDE_OS_WINDOWS AND (MKCDE_COMPILER_GCC OR MKCDE_COMPILER_CLANG))
            # on Windows + gcc/clang get rid of "lib" prefix for shared libraries,
            # and transform the ".dll.a" suffix into ".a" for import libraries
            set_target_properties(${target} PROPERTIES PREFIX "")
            set_target_properties(${target} PROPERTIES IMPORT_SUFFIX ".a")
        endif()
    else()
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -s-d)
        set_target_properties(${target} PROPERTIES RELEASE_POSTFIX -s)
        set_target_properties(${target} PROPERTIES MINSIZEREL_POSTFIX -s)
        set_target_properties(${target} PROPERTIES RELWITHDEBINFO_POSTFIX -s)
    endif()

    # set the version and soversion of the target (for compatible systems -- mostly Linuxes)
    # except for Android which strips soversion suffixes
    if(NOT MKCDE_OS_ANDROID)
        set_target_properties(${target} PROPERTIES SOVERSION ${VERSION_MAJOR}.${VERSION_MINOR})
        set_target_properties(${target} PROPERTIES VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
    endif()

    # set the target's folder (for IDEs that support it, e.g. Visual Studio)
    set_target_properties(${target} PROPERTIES FOLDER "MKCDE")

    # set the target flags to use the appropriate C++ standard library
    mkcde_set_stdlib(${target})

    # For Visual Studio on Windows, export debug symbols (PDB files) to lib directory
    if(MKCDE_GENERATE_PDB)
        # PDB files are only generated in Debug and RelWithDebInfo configurations, find out which one
        if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
            set(MKCDE_PDB_POSTFIX "-d")
        else()
            set(MKCDE_PDB_POSTFIX "")
        endif()

        if(BUILD_SHARED_LIBS AND NOT THIS_STATIC)
            # DLLs export debug symbols in the linker PDB (the compiler PDB is an intermediate file)
            set_target_properties(${target} PROPERTIES
                                  PDB_NAME "${target}${MKCDE_PDB_POSTFIX}"
                                  PDB_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
        else()
            # Static libraries have no linker PDBs, thus the compiler PDBs are relevant
            set_target_properties(${target} PROPERTIES
                                  COMPILE_PDB_NAME "${target}-s${MKCDE_PDB_POSTFIX}"
                                  COMPILE_PDB_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
        endif()
    endif()

    # if using gcc >= 4.0 or clang >= 3.0 on a non-Windows platform, we must hide public symbols by default
    # (exported ones are explicitly marked)
    if(NOT MKCDE_OS_WINDOWS AND ((MKCDE_COMPILER_GCC AND NOT MKCDE_GCC_VERSION VERSION_LESS "4") OR (MKCDE_COMPILER_CLANG AND NOT MKCDE_CLANG_VERSION VERSION_LESS "3")))
        set_target_properties(${target} PROPERTIES COMPILE_FLAGS -fvisibility=hidden)
    endif()

    # build frameworks or dylibs
    if(MKCDE_OS_MACOSX AND BUILD_SHARED_LIBS AND NOT THIS_STATIC)
        if(MKCDE_BUILD_FRAMEWORKS)
            # adapt target to build frameworks instead of dylibs
            set_target_properties(${target} PROPERTIES
                                  FRAMEWORK TRUE
                                  FRAMEWORK_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}
                                  MACOSX_FRAMEWORK_IDENTIFIER org.sfml-dev.${target}
                                  MACOSX_FRAMEWORK_SHORT_VERSION_STRING ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}
                                  MACOSX_FRAMEWORK_BUNDLE_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
        endif()

        # adapt install directory to allow distributing dylibs/frameworks in user's frameworks/application bundle
        # but only if cmake rpath options aren't set
        if(NOT CMAKE_SKIP_RPATH AND NOT CMAKE_SKIP_INSTALL_RPATH AND NOT CMAKE_INSTALL_RPATH AND NOT CMAKE_INSTALL_RPATH_USE_LINK_PATH AND NOT CMAKE_INSTALL_NAME_DIR)
            set_target_properties(${target} PROPERTIES INSTALL_NAME_DIR "@rpath")
            if(NOT CMAKE_SKIP_BUILD_RPATH)
                if (CMAKE_VERSION VERSION_LESS 3.9)
                    set_target_properties(${target} PROPERTIES BUILD_WITH_INSTALL_RPATH TRUE)
                else()
                    set_target_properties(${target} PROPERTIES BUILD_WITH_INSTALL_NAME_DIR TRUE)
                endif()
            endif()
        endif()
    endif()

    if (MKCDE_OS_IOS)
        mkcde_set_common_ios_properties(${target})
    endif()

    # mkcde-activity library is our bootstrap activity and must not depend on stlport_shared
    # (otherwise Android will fail to load it)
    if (MKCDE_OS_ANDROID)
        if (${target} MATCHES "mkcde-activity")
            set_target_properties(${target} PROPERTIES COMPILE_FLAGS -fpermissive)
            set_target_properties(${target} PROPERTIES LINK_FLAGS "-landroid -llog")
            set(CMAKE_CXX_CREATE_SHARED_LIBRARY ${CMAKE_CXX_CREATE_SHARED_LIBRARY_WITHOUT_STL})
        else()
            set(CMAKE_CXX_CREATE_SHARED_LIBRARY ${CMAKE_CXX_CREATE_SHARED_LIBRARY_WITH_STL})
        endif()
    endif()

    # add the install rule
    install(TARGETS ${target} EXPORT MKCDEConfigExport
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT bin
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT bin
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT mik
            FRAMEWORK DESTINATION "." COMPONENT bin)

    # add <project>/include as public include directory
    target_include_directories(${target}
                               PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                               PRIVATE ${PROJECT_SOURCE_DIR}/src)

    if (MKCDE_BUILD_FRAMEWORKS)
        target_include_directories(${target} INTERFACE $<INSTALL_INTERFACE:MKCDE.framework>)
    else()
        target_include_directories(${target} INTERFACE $<INSTALL_INTERFACE:include>)
    endif()

    # define MKCDE_STATIC if the build type is not set to 'shared'
    if(NOT BUILD_SHARED_LIBS)
        target_compile_definitions(${target} PUBLIC "MKCDE_STATIC")
    endif()

endmacro()
