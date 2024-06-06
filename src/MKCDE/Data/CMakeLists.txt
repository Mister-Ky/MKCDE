
set(INCROOT ${PROJECT_SOURCE_DIR}/include/MKCDE/Data)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/MKCDE/Data)

set(SRC
    ${SRCROOT}/MKRF.cpp
    ${INCROOT}/MKRF.hpp
)

mkcde_add_library(mkcde-data SOURCES ${SRC})
target_link_libraries(mkcde-data PUBLIC mkcde-system)
