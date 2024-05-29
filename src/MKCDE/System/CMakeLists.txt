
set(INCROOT ${PROJECT_SOURCE_DIR}/include/MKCDE/System)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/MKCDE/System)

set(SRC
    ${SRCROOT}/SystemTime.cpp
    ${INCROOT}/SystemTime.hpp
    ${SRCROOT}/EnvironmentVariables.cpp
    ${INCROOT}/EnvironmentVariables.hpp
    ${SRCROOT}/Logger.cpp
    ${INCROOT}/Logger.hpp
    ${SRCROOT}/ProcessManager.cpp
    ${INCROOT}/ProcessManager.hpp
    ${SRCROOT}/FileManager.cpp
    ${INCROOT}/FileManager.hpp
    ${SRCROOT}/SystemInfo.cpp
    ${INCROOT}/SystemInfo.hpp
)

add_library(mkcde-system ${SRC})
set_target_properties(mkcde-system PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
#target_link_libraries(mkcde-system PUBLIC sfml-system)
