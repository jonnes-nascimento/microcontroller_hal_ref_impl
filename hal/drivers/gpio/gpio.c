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
#include "constants.h"

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
 * Typedefs
 ************************************************************************************************/

/************************************************************************************************
 * Global Variables
 ************************************************************************************************/
/* DUMMY TEST VARS */
uint8_t trisio = 0;
uint8_t gpio = 0;
uint8_t ansel = 0;
uint8_t option = 0;
uint8_t intcon = 0;

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

static ARCH_ADDR_SIZE volatile * const GpioInterruptControl[NUMBER_OF_PORTS] = {
        (ARCH_ADDR_SIZE *) INTCON
};

static ARCH_ADDR_SIZE volatile * const GpioOption[NUMBER_OF_PORTS] = {
        (ARCH_ADDR_SIZE *) OPTION
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
 * @see Gpio_Write
 * @see Gpio_Read
 * @see Gpio_Toggle
 * @see Gpio_Register_Write
 * @see Gpio_Register_Read
 * @see Gpio_Callback_Register
 *
 * <b>HISTORY OF CHANGES</b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 16/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Creation Date </td></tr>
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

           switch (Config[i].Function)
           {
               case GPIO_PIN_FUNCTION_ANALOG:
                   if (Config[i].Direction == GPIO_PIN_DIRECTION_INPUT)
                   {
                       //*GpioFunction[port] |= (Config[i].Direction << i);
                       ansel |= (Config[i].Direction << i);
                   }
                   else
                   {
                       //*GpioFunction[port] |= (HIGH << i);
                       ansel &= ~(HIGH << i);
                   }
                   break;
               case GPIO_PIN_FUNCTION_EXTERNAL_INTERRUPT:

                   // Enables the external interrupt on GP2/INT
                   //*GpioInterruptControl[port] |= GIE1_BIT_MASK;
                   //*GpioInterruptControl[port] |= INTE_BIT_MASK;
                   intcon |= GIE1_BIT_MASK;
                   intcon |= INTE_BIT_MASK;

                   // Clears the external interrupt flag INTF
                   //*GpioInterruptControl[port] &= ~INTF_BIT_MASK;
                   intcon &= ~INTF_BIT_MASK;

                   // Sets the edge trigger of the interrupt
                   if (Config[i].InterruptEdge == GPIO_INTERRUPT_EDGE_FALLING)
                   {
                       //*GpioOption[port] &= ~INTEDG_BIT_MASK;
                       option &= ~INTEDG_BIT_MASK;
                   }
                   else if (Config[i].InterruptEdge == GPIO_INTERRUPT_EDGE_RISING)
                   {
                       //*GpioOption[port] |= INTEDG_BIT_MASK;
                       option |= INTEDG_BIT_MASK;
                   }
                   else
                   {
                       // do nothing
                   }

                   break;
           }

        }
    }

    printf("OPTION Byte "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(option));
    printf("INTCON Byte "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(intcon));
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
 * @see Gpio_Read
 * @see Gpio_Toggle
 * @see Gpio_Register_Write
 * @see Gpio_Register_Read
 * @see Gpio_Callback_Register
 *
 * <b>HISTORY OF CHANGES</b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 16/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Creation Date </td></tr>
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
 * Function: GpioPinState_t Gpio_Read(GpioChannel_t channel);
 *//**
 *
 * \b Description:
 *
 * This function is used to read a pin state, specified by a channel, from GPIO port.
 *
 * Pre-condition: GPIO port must have been initialized <br>
 *
 * Post-condition: GPIO port state is returned
 *
 * @param [in]          channel is a GpioChannel_t that represents a bit on GPIO port
 *
 * @return              GpioPinState_t
 *
 * \b Example:
 *
 * @code
 * GpioPinState_t PinState = Gpio_Read(CHANNEL_GP3);
 * @endcode
 *
 * @see Gpio_Init
 * @see Gpio_Write
 * @see Gpio_Toggle
 * @see Gpio_Register_Write
 * @see Gpio_Register_Read
 * @see Gpio_Callback_Register
 *
 * <b>HISTORY OF CHANGES</b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 20/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Creation Date </td></tr>
 * </table><br><br><hr>
 ************************************************************************************************/
GpioPinState_t Gpio_Read(GpioChannel_t channel)
{

}

/************************************************************************************************
 * Function: void Gpio_Toggle(GpioChannel_t channel);
 *//**
 *
 * \b Description:
 *
 * This function is used to toggle a pin state, specified by a channel, from GPIO port.
 *
 * Pre-condition: GPIO port must have been initialized <br>
 *
 * Post-condition: GPIO port state is toggled
 *
 * @param [in]          channel is a GpioChannel_t that represents a bit on GPIO port
 *
 * @return              void
 *
 * \b Example:
 *
 * @code
 * Gpio_Toggle(CHANNEL_GP3);
 * @endcode
 *
 * @see Gpio_Init
 * @see Gpio_Write
 * @see Gpio_Read
 * @see Gpio_Register_Write
 * @see Gpio_Register_Read
 * @see Gpio_Callback_Register
 *
 * <b>HISTORY OF CHANGES</b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 20/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Creation Date </td></tr>
 * </table><br><br><hr>
 ************************************************************************************************/
void Gpio_Toggle(GpioChannel_t channel)
{

}

/************************************************************************************************
 * Function: void Gpio_Register_Write(GpioPort_t Port);
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
 * Gpio_Register_Write(0x04);
 * @endcode
 *
 * @see Gpio_Init
 * @see Gpio_Write
 * @see Gpio_Read
 * @see Gpio_Toggle
 * @see Gpio_Register_Read
 * @see Gpio_Callback_Register
 *
 * <b>HISTORY OF CHANGES</b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 16/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Creation Date </td></tr>
 * <tr><td> 17/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Documentation Created </td></tr>
 * </table><br><br><hr>
 ************************************************************************************************/
void Gpio_Register_Write(GpioPort_t Port)
{
    printf("\r\nWriting byte to GPIO...\r\n");
    gpio = Port.Byte;
    //*GpioPort[GPIO_PORT] = Port.Byte;
    printf("GPIO Byte "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(gpio));
}

/************************************************************************************************
 * Function: GpioPort_t Gpio_Register_Read(void);
 *//**
 *
 * \b Description:
 *
 * This function is used to read GPIO port byte.
 *
 * Pre-condition: GPIO port must have been initialized <br>
 *
 * Post-condition: None
 *
 * @param [in]          void
 *
 * @return              GpioPort_t
 *
 * \b Example:
 *
 * @code
 * GpioPort_t Port = Gpio_Register_Read();
 * @endcode
 *
 * @see Gpio_Init
 * @see Gpio_Write
 * @see Gpio_Read
 * @see Gpio_Toggle
 * @see Gpio_Register_Write
 * @see Gpio_Callback_Register
 *
 * <b>HISTORY OF CHANGES</b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 20/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Creation Date </td></tr>
 * </table><br><br><hr>
 ************************************************************************************************/
GpioPort_t Gpio_Register_Read(void)
{
    // return *GpioPort[GPIO_PORT];
}

/************************************************************************************************
 * Function: void Gpio_Callback_Register(GpioCallbackEvent_t event, void (*CallbackFunction)(void));
 *//**
 *
 * \b Description:
 *
 * This function is used to register a callback function to an interrupt event
 *
 * Pre-condition: GPIO port must have been initialized <br>
 * Pre-condition: The GPIO port bit must have been configured to trigger the interrupt
 *
 * Post-condition: The callback function is called to handles the interrupt event
 *
 * @param [in]          event is a pre-configured interrupt event
 * @param [in]          (*CallbackFunction)(void) is the callback function to call
 *
 * @return              void
 *
 * \b Example:
 *
 * @code
 * Gpio_Callback_Register(GPIO_EXTERNAL_INTERRUPT, BlinkLED);
 * @endcode
 *
 * @see Gpio_Init
 * @see Gpio_Write
 * @see Gpio_Read
 * @see Gpio_Toggle
 * @see Gpio_Register_Write
 * @see Gpio_Register_Read
 *
 * <b>HISTORY OF CHANGES</b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 20/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Creation Date </td></tr>
 * </table><br><br><hr>
 ************************************************************************************************/
void Gpio_Callback_Register(GpioCallbackEvent_t event, void (*CallbackFunction)(void))
{

}

/************************************************************************************************
 * EOF
 ************************************************************************************************/
/** @} */