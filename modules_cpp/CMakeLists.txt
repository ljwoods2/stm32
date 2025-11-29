
set(MODULES_CXX_Include_Dirs
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)


set(MODULES_CXX_Src
    ${CMAKE_CURRENT_SOURCE_DIR}/display/display.cpp
)

add_library(modules_cpp STATIC ${MODULES_CXX_Src})
target_include_directories(modules_cpp PUBLIC ${MODULES_CXX_Include_Dirs})
# target_sources(modules_cpp PUBLIC ${MODULES_CXX_Src})
