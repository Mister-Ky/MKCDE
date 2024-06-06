
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

mkcde_add_library(mkcde-system SOURCES ${SRC})
target_link_libraries(mkcde-system PUBLIC sfml-system)
