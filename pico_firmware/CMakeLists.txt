cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

pico_sdk_init()

add_executable(pico_firmware main.c)
pico_enable_stdio_usb(pico_firmware 1)
pico_add_extra_outputs(pico_firmware)