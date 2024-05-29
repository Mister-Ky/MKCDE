
set(INCROOT ${PROJECT_SOURCE_DIR}/include/MKCDE/Utils)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/MKCDE/Utils)

set(SRC
    ${SRCROOT}/ArgsProcessor.cpp
    ${INCROOT}/ArgsProcessor.hpp
    ${SRCROOT}/EMath.cpp
    ${INCROOT}/EMath.hpp
)

mkcde_add_library(mkcde-utils SOURCES ${SRC})
target_link_libraries(mkcde-utils PUBLIC mkcde-system)
