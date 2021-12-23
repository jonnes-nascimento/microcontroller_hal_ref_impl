cmake_minimum_required(VERSION 3.21)
project(microcontroller_hal_ref_impl C)

set(CMAKE_C_STANDARD 99)

include_directories(hal/drivers/hardware)
include_directories(hal/config)
include_directories(hal/library)
include_directories(hal/drivers/gpio/interface)
include_directories(hal/drivers/gpio/impl)

add_executable(microcontroller_hal_ref_impl
        hal/config/gpio/gpio_config.c
        hal/config/gpio/gpio_config.h
        hal/drivers/gpio/gpio.c
        hal/drivers/gpio/gpio.h
        main.c hal/drivers/hardware/pic12f683.h
        hal/library/constants.h)
