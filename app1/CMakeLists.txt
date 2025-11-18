

set(APP_Src
    ${CMAKE_CURRENT_SOURCE_DIR}/app_main.c
)

add_library(app1 INTERFACE ${APP_Src})
target_sources(app1 PUBLIC ${APP_Src})
