cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(temp-tester)

pico_sdk_init()

add_executable(temp-tester
        temp-tester.c
        )
        
pico_enable_stdio_usb(temp-tester 1)
pico_enable_stdio_uart(temp-tester 0)

target_link_libraries(temp-tester pico_stdlib hardware_adc)

pico_add_extra_outputs(temp-tester)
