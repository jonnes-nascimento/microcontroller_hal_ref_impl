/************************************************************************************************
 * @Title          :    General purpose input/output (GPIO)
 * @Filename       :    gpio.c
 * @Author         :    Eng. Jonnes F. Nascimento
 * @Origin Date    :    16/12/2021
 * @Version        :    0.0.1
 * @Compiler       :    GCC
 * @Target         :    --
 * @Notes          :    None
 * @Revision Date  :    20/12/2021
 ************************************************************************************************/
/** **********************************************************************************************
 * @file gpio.c
 * @brief Interface implementation for general purpose input/output (GPIO)
 *
 *  This is the implementation file for the interface of a digital
 *  input / output peripheral on a standard microcontroller. Some microcontrollers
 *  call this digital I/O as PORT_x. In this case, this is called GPIO.
 *
 * @addtogroup Drivers
 * Peripheral drivers group (GPIO, TIMERS, SPI, etc).
 *  @{
 * */

/************************************************************************************************
 * Includes
 ************************************************************************************************/
#include <stdio.h>
#include "pic12f683.h"
#include "gpio.h"

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
 * Global Variables
 ************************************************************************************************/
/* DUMMY TEST VARS */
uint8_t trisio = 0;
uint8_t gpio = 0;
uint8_t ansel = 0;

/************************************************************************************************
 * Module Variables Definitions
 ************************************************************************************************/
/* This is for test only - this code must be moved */
static ARCH_ADDR_SIZE volatile * const SystemOscilator = {
        (ARCH_ADDR_SIZE *) OSCCON
};

static ARCH_ADDR_SIZE volatile * const SystemComparator = {
        (ARCH_ADDR_SIZE *) CMCON0
};

static ARCH_ADDR_SIZE volatile * const SystemADConverter = {
        (ARCH_ADDR_SIZE *) ADCON0
};
/* *************************************************************************/

static ARCH_ADDR_SIZE volatile * const GpioPort[NUMBER_OF_PORTS] = {
        (ARCH_ADDR_SIZE *) GPIO
};

static ARCH_ADDR_SIZE volatile * const GpioDirection[NUMBER_OF_PORTS] = {
        (ARCH_ADDR_SIZE *) TRISIO
};

static ARCH_ADDR_SIZE volatile * const GpioFunction[NUMBER_OF_PORTS] = {
        (ARCH_ADDR_SIZE *) ANSEL
};
/************************************************************************************************
 * Functions Prototypes
 ************************************************************************************************/

/************************************************************************************************
 * Functions Definitions
 ************************************************************************************************/

/************************************************************************************************
 * Function: void Gpio_Init(const GpioConfig_t * const Config);
 *//**
 *
 * \b Description:
 *
 * This function is used to initializes the GPIO port based on the
 * configuration table defined in gpio_config module.
 *
 * Pre-condition: Configuration table defined (sizeof > 0) <br>
 * Pre-condition: NUMBER_OF_PORTS > 0 <br>
 * Pre-condition: GPIO_MAX_PIN_NUMBER > 0 <br>
 * Pre-condition: System's oscillator, comparator and A/D converters initialized <br>
 *
 * Post-condition: GPIO port initialized and configured
 *
 * @param [in]          Config is a pointer to configuration table for
 *                      the GPIO peripheral.
 *
 * @return              void
 *
 * \b Example:
 *
 * @code
 * Gpio_Init(GpioConfigGet());
 * @endcode
 *
 * @see GpioConfigGet
 * @see Gpio_Write
 * @see Gpio_Write_Register
 *
 * <b>HISTORY OF CHANGES</b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 16/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Interface Created </td></tr>
 * <tr><td> 17/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Documentation Created </td></tr>
 * </table><br><br><hr>
 ************************************************************************************************/
void Gpio_Init(const GpioConfig_t * const Config)
{
    printf("\r\nInitializing GPIO...\r\n");
    printf("GPIO Byte "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(gpio));

    /* This is for test only - this code must be moved */
    //*SystemOscilator    = 0x70; /**< Switch to 8 MHz system clock */
    //*SystemComparator   = 0x07; /**< Comparators off */
    //*SystemADConverters = 0x00; /**< AD Converters off */

    for (uint8_t port = 0; port < NUMBER_OF_PORTS; port++)
    {
        //*GpioPort[port] = 0x00; /**< Resets all GPIO pins */

        /* Sets the GPIOs */
        for (uint8_t i = 0; i < GPIO_MAX_PIN_NUMBER; i++)
        {
           // *GpioDirection[port] = (Config[i].Direction << i);
           trisio |= (Config[i].Direction << i);

            // *GpioPort[port] = (Config[i].State << i);
           gpio |= (Config[i].State << i);

           if (Config[i].Function == GPIO_PIN_FUNCTION_ANALOG && Config[i].Direction == GPIO_PIN_DIRECTION_INPUT)
           {
               ansel |= (Config[i].Direction << i);
           }
           else
           {
               ansel |= (0 << i);
           }
        }
    }

    printf("TRISIO Byte "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(trisio));
    printf("ANSEL Byte "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(ansel));
    printf("GPIO Byte "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(gpio));
    printf("GPIO initialized!\r\n");
    printf("GPIO Port Address: %x\n", GpioDirection[0]);
}

/************************************************************************************************
 * Function: void Gpio_Write(GpioChannel_t channel, GpioPinState_t state);
 *//**
 *
 * \b Description:
 *
 * This function is used to write a bit, specified by a channel, to GPIO port.
 *
 * Pre-condition: GPIO port must have been initialized <br>
 *
 * Post-condition: GPIO port bit setted or cleared
 *
 * @param [in]          channel is a GpioChannel_t that represents a bit on GPIO port
 * @param [in]          state is a GpioPinState_t that represents a state of the bit on GPIO port
 *
 * @return              void
 *
 * \b Example:
 *
 * @code
 * Gpio_Write(CHANNEL_GP3, GPIO_PIN_STATE_HIGH);
 * @endcode
 *
 * @see Gpio_Init
 * @see Gpio_Write_Register
 *
 * <b>HISTORY OF CHANGES</b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 16/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Interface Created </td></tr>
 * <tr><td> 17/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Documentation Created </td></tr>
 * </table><br><br><hr>
 ************************************************************************************************/
void Gpio_Write(GpioChannel_t channel, GpioPinState_t state)
{
    printf("\r\nWriting to GPIO...\r\n");
    gpio |= (state << channel);
    //*GpioPort[GPIO_PORT] |= (state << channel);
    printf("GPIO Byte "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(gpio));
}

/************************************************************************************************
 * Function: void Gpio_Write_Register(GpioPort_t Port);
 *//**
 *
 * \b Description:
 *
 * This function is used to write a byte that represents all GPIO port bits to GPIO port.
 *
 * Pre-condition: GPIO port must have been initialized <br>
 *
 * Post-condition: All GPIO port bits sets according to the byte parameter
 *
 * @param [in]          Port is a GpioPort_t that represents all GPIO bits
 *
 * @return              void
 *
 * \b Example:
 *
 * @code
 * Gpio_Write_Byte(0x04);
 * @endcode
 *
 * @see Gpio_Init
 * @see Gpio_Write
 *
 * <b>HISTORY OF CHANGES</b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 16/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Interface Created </td></tr>
 * <tr><td> 17/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Documentation Created </td></tr>
 * </table><br><br><hr>
 ************************************************************************************************/
void Gpio_Write_Register(GpioPort_t Port)
{
    printf("\r\nWriting byte to GPIO...\r\n");
    gpio = Port.Byte;
    //*GpioPort[GPIO_PORT] = Port.Byte;
    printf("GPIO Byte "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(gpio));
}

/************************************************************************************************
 * EOF
 ************************************************************************************************/
/** @} */