/************************************************************************************************
 * @Title          :    Main function
 * @Filename       :    main.c
 * @Author         :    Eng. Jonnes F. Nascimento
 * @Origin Date    :    16/12/2021
 * @Version        :    0.0.1
 * @Compiler       :    GCC
 * @Target         :    --
 * @Notes          :    None
 * @Revision Date  :    20/12/2021
 ************************************************************************************************/
/** **********************************************************************************************
 * @file main.c
 * @brief Main program
 *
 *  This is the entrypoint of the firmware.
 *
 *! \mainpage
 *
 * \section intro_sec Project Introduction
 * Microcontroller HAL Reference Implementation <br />
 *
 * *** Work in Progress *** <br />
 *
 * This work has been written as a basis for the study of microcontrollers drivers and is based mainly on Jacob Beningo's book <a target="_blank" href="https://www.amazon.com/Reusable-Firmware-Development-Practical-Approach/dp/1484232968">Reusable Firmware Development</a>. Apress. 2017.
 *
 * Author: Eng. Jonnes F. Nascimento. 2021
 *
 * \section ver_sec Version Log
 * \section acron_sec Acronyms
 * \section soft_sec Software Architecture Overview
 * \section api_sec APIs
 * \section hal_sec HALs
 * \section mid_sec Middleware
 * \section os_sec OS Information
 * \section std_sec Coding Standards
 * \section doc_seq Documentation
 * \section req_sec Project Requirements
 * \section test_sec Testing and Validation
 * <br>
 * \section tools Tools
 * \subsection compiler Compiler
 * GNU C Compiler (GCC)
 *
 */

/************************************************************************************************
 * Includes
 ************************************************************************************************/
#include <stdio.h>
#include "hal/drivers/gpio/gpio.h"

/************************************************************************************************
 * Defines and Macros
 ************************************************************************************************/
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

/************************************************************************************************
 * Static Typedefs
 ************************************************************************************************/

/************************************************************************************************
 * Global Variables
 ************************************************************************************************/

/************************************************************************************************
 * Functions Prototypes
 ************************************************************************************************/
void LedBlink(void);

/************************************************************************************************
 * Functions Definitions
 ************************************************************************************************/
int main() {

    GpioPort_t port;
    port.Byte = 0x08;
    port.Bit0 = 0x01;

    printf("\r\nLedBlink Function Address: %x\r\n\n", LedBlink);

    Gpio_Callback_Register(GPIO_EXTERNAL_INTERRUPT, LedBlink);

    Gpio_Init(GpioConfigGet());
    //Gpio_Write(CHANNEL_GP3, GPIO_PIN_STATE_HIGH);
    //Gpio_Write(CHANNEL_GP3, GPIO_PIN_STATE_LOW);
    //Gpio_Register_Write(port);

    Gpio_Toggle(CHANNEL_GP2);
    Gpio_Toggle(CHANNEL_GP2);
    Gpio_Toggle(CHANNEL_GP2);
    Gpio_Toggle(CHANNEL_GP2);
    Gpio_Toggle(CHANNEL_GP2);

    //printf("=====TEST: "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(1 << 0));

    return 0;
}

void LedBlink(void)
{
    printf("LED BLINKING...\r\n");
}
/************************************************************************************************
 * EOF
 ************************************************************************************************/