
set(INCROOT ${PROJECT_SOURCE_DIR}/include/MKCDE/App)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/MKCDE/App)

set(SRC
    ${SRCROOT}/ClassDB.cpp
    ${INCROOT}/ClassDB.hpp
    ${SRCROOT}/GraphicalApp.cpp
    ${INCROOT}/GraphicalApp.hpp
    ${SRCROOT}/Node.cpp
    ${INCROOT}/Node.hpp
    ${SRCROOT}/Object.cpp
    ${INCROOT}/Object.hpp
)

mkcde_add_library(mkcde-app SOURCES ${SRC})
target_link_libraries(mkcde-app PUBLIC mkcde-graphics)
