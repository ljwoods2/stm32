
set(MODULES_Include_Dirs
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)


set(MODULES_Src
    ${CMAKE_CURRENT_SOURCE_DIR}/blinky/blinky.c
    ${CMAKE_CURRENT_SOURCE_DIR}/cmd/cmd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/console/console.c
    ${CMAKE_CURRENT_SOURCE_DIR}/dio/dio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/gps_gtu7/gps_gtu7.c
    ${CMAKE_CURRENT_SOURCE_DIR}/log/log.c
    ${CMAKE_CURRENT_SOURCE_DIR}/mem/mem.c
    ${CMAKE_CURRENT_SOURCE_DIR}/stat/stat.c
    ${CMAKE_CURRENT_SOURCE_DIR}/tmr/tmr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ttys/ttys.c
)

add_library(modules INTERFACE ${MODULES_Src})
target_include_directories(modules INTERFACE ${MODULES_Include_Dirs})
target_sources(modules PUBLIC ${MODULES_Src})
