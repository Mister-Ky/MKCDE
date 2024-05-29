
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

macro(mkcde_add_library target)
    cmake_parse_arguments(THIS "STATIC" "" "SOURCES" ${ARGN})
    if (NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments when calling mkcde_add_library: ${THIS_UNPARSED_ARGUMENTS}")
    endif()

    if (THIS_STATIC)
        add_library(${target} STATIC ${THIS_SOURCES})
    else()
        add_library(${target} ${THIS_SOURCES})
    endif()

    #set_file_warnings(${THIS_SOURCES})

    string(REPLACE "-" "_" NAME_UPPER "${target}")
    string(TOUPPER "${NAME_UPPER}" NAME_UPPER)
    set_target_properties(${target} PROPERTIES DEFINE_SYMBOL ${NAME_UPPER}_EXPORTS)

    if(BUILD_SHARED_LIBS AND NOT THIS_STATIC)
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -d)
        set_target_properties(${target} PROPERTIES SUFFIX "-${VERSION_MAJOR}${CMAKE_SHARED_LIBRARY_SUFFIX}")

        string(TIMESTAMP RC_CURRENT_YEAR "%Y")
        string(REGEX REPLACE "mkcde-([a-z])([a-z]*)" "\\1" RC_MODULE_NAME_HEAD "${target}")
        string(REGEX REPLACE "mkcde-([a-z])([a-z]*)" "\\2" RC_MODULE_NAME_TAIL "${target}")
        string(TOUPPER "${RC_MODULE_NAME_HEAD}" RC_MODULE_NAME_HEAD)
        set(RC_MODULE_NAME "${RC_MODULE_NAME_HEAD}${RC_MODULE_NAME_TAIL}")
        set(RC_VERSION_SUFFIX "")
        set(RC_PRERELEASE "0")
        set(RC_TARGET_NAME "${target}")
        set(RC_TARGET_FILE_NAME_SUFFIX "-${VERSION_MAJOR}${CMAKE_SHARED_LIBRARY_SUFFIX}")

        #configure_file(
        #    "${MKCDE_SOURCE_DIR}/tools/windows/resource.rc.in"
        #    "${CMAKE_CURRENT_BINARY_DIR}/${target}.rc"
        #    @ONLY
        #)
        #target_sources(${target} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/${target}.rc")
        #source_group("" FILES "${CMAKE_CURRENT_BINARY_DIR}/${target}.rc")
        if (MKCDE_COMPILER_GCC OR MKCDE_COMPILER_CLANG)
            set_target_properties(${target} PROPERTIES PREFIX "")
            set_target_properties(${target} PROPERTIES IMPORT_SUFFIX ".a")
        endif()
    else()
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -s-d)
        set_target_properties(${target} PROPERTIES RELEASE_POSTFIX -s)
        set_target_properties(${target} PROPERTIES MINSIZEREL_POSTFIX -s)
        set_target_properties(${target} PROPERTIES RELWITHDEBINFO_POSTFIX -s)
    endif()

    set_target_properties(${target} PROPERTIES SOVERSION ${VERSION_MAJOR}.${VERSION_MINOR})
    set_target_properties(${target} PROPERTIES VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

    set_target_properties(${target} PROPERTIES FOLDER "MKCDE")

    mkcde_set_stdlib(${target})

    if(MKCDE_GENERATE_PDB)
        if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
            set(MKCDE_PDB_POSTFIX "-d")
        else()
            set(MKCDE_PDB_POSTFIX "")
        endif()

        if(BUILD_SHARED_LIBS AND NOT THIS_STATIC)
            set_target_properties(${target} PROPERTIES
                                  PDB_NAME "${target}${MKCDE_PDB_POSTFIX}"
                                  PDB_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
        else()
            set_target_properties(${target} PROPERTIES
                                  COMPILE_PDB_NAME "${target}-s${MKCDE_PDB_POSTFIX}"
                                  COMPILE_PDB_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
        endif()
    endif()

    install(TARGETS ${target} EXPORT MKCDEConfigExport
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT bin
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT bin
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT mik
            FRAMEWORK DESTINATION "." COMPONENT bin)

    target_include_directories(${target}
                               PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                               PRIVATE ${PROJECT_SOURCE_DIR}/src)

    if (MKCDE_BUILD_FRAMEWORKS)
        target_include_directories(${target} INTERFACE $<INSTALL_INTERFACE:MKCDE.framework>)
    else()
        target_include_directories(${target} INTERFACE $<INSTALL_INTERFACE:include>)
    endif()

    if(NOT BUILD_SHARED_LIBS)
        target_compile_definitions(${target} PUBLIC "MKCDE_STATIC")
    endif()

endmacro()