cmake_minimum_required(VERSION 3.21)
project(pic12f683_drivers C)

set(CMAKE_C_STANDARD 99)

include_directories(hal/drivers/hardware)
include_directories(hal/config)
include_directories(hal/drivers/gpio/interface)
include_directories(hal/drivers/gpio/impl)

add_executable(pic12f683_drivers
        hal/config/gpio/gpio_config.c
        hal/config/gpio/gpio_config.h
        hal/drivers/gpio/gpio.c
        hal/drivers/gpio/gpio.h
        main.c hal/drivers/hardware/pic12f683.h)
