# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/deps/pico-sdk AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/deps/arm-toolchain)
    # If the dependencies are local.
    set(PICO_SDK_PATH ${CMAKE_CURRENT_SOURCE_DIR}/deps/pico-sdk)
    set(PICO_TOOLCHAIN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/deps/arm-toolchain)
    include(${PICO_SDK_PATH}/pico_sdk_init.cmake)
else()
    # If the dependencies are global.
    include(pico_sdk_import.cmake)
endif()

if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/lib/pico-extras)
    set(PICO_EXTRAS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/pico-extras)
    include(${PICO_EXTRAS_PATH}/external/pico_extras_import.cmake)
endif()

set(PROJECT alpakka_mod_dual_thumbstick)
project(${PROJECT} C CXX ASM)
pico_sdk_init()

add_executable(${PROJECT}
    src/main.c
)

# alpakka_v0
# target_compile_definitions(${PROJECT} PUBLIC DEVICE_ALPAKKA_V0=1)
# target_compile_definitions(${PROJECT} PUBLIC DEVICE_IS_ALPAKKA=1)

# alpakka_mod_dual_thumbstick 
# target_compile_definitions(${PROJECT} PUBLIC DEVICE_ALPAKKA_V0=2)
# target_compile_definitions(${PROJECT} PUBLIC DEVICE_IS_ALPAKKA=1)

# alpakka_v1 
# target_compile_definitions(${PROJECT} PUBLIC DEVICE_ALPAKKA_V1=1)
# target_compile_definitions(${PROJECT} PUBLIC DEVICE_IS_ALPAKKA=1)
# target_compile_definitions(${PROJECT} PUBLIC DEVICE_HAS_MARMOTA=1)

# alpakka_v1_mod_linghu
target_compile_definitions(${PROJECT} PUBLIC DEVICE_ALPAKKA_V1=1)
target_compile_definitions(${PROJECT} PUBLIC DEVICE_IS_ALPAKKA=1)
target_compile_definitions(${PROJECT} PUBLIC DEVICE_HAS_MARMOTA=1)
target_compile_definitions(${PROJECT} PUBLIC MOD_LINGHU=1)

# dongle 
# target_compile_definitions(${PROJECT} PUBLIC DEVICE_DONGLE=1)
# target_compile_definitions(${PROJECT} PUBLIC DEVICE_HAS_MARMOTA=1)

# llama
# target_compile_definitions(${PROJECT} PUBLIC DEVICE_LLAMA=1)
# target_compile_definitions(${PROJECT} PUBLIC DEVICE_HAS_MARMOTA=1)

target_link_libraries(${PROJECT}
    pico_stdlib
    # pico_multicore
    pico_time
    pico_unique_id
    pico_bootrom
    pico_bootsel_via_double_reset
    pico_rand
    hardware_adc
    hardware_flash
    hardware_i2c
    hardware_pwm
    hardware_spi
    hardware_sync
    hardware_timer
    hardware_sleep
    tinyusb_device
)

target_include_directories(${PROJECT} PUBLIC
    src
    src/headers
)

file(GLOB_RECURSE srcs 
    src/*.c 
    src/*.cpp
)

target_sources(${PROJECT} PUBLIC
    ${srcs}
)

pico_enable_stdio_uart(${PROJECT} 1)
pico_add_extra_outputs(${PROJECT})
