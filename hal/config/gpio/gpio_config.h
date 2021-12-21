/************************************************************************************************
 * @Title          :    General purpose input/output configuration interface
 * @Filename       :    gpio_config.h
 * @Author         :    Eng. Jonnes F. Nascimento
 * @Origin Date    :    16/12/2021
 * @Version        :    0.0.1
 * @Compiler       :    GCC
 * @Target         :    --
 * @Notes          :    None
 * @Revision Date  :    20/12/2021
 ************************************************************************************************/
/** **********************************************************************************************
 * @file gpio_config.h
 * @brief Interface definition for general purpose input/output configurations
 *
 *  This is the header file for the definition of the configuration for a digital
 *  input / output peripheral.
 *
 * <b>INTERFACE CHANGE LIST</b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 16/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Interface Created </td></tr>
 * <tr><td> 20/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Documentation Created </td></tr>
 * </table><br><br><hr>
 ************************************************************************************************/
#ifndef _GPIO_CFG_H_
#define _GPIO_CFG_H_

/************************************************************************************************
 * Includes
 ************************************************************************************************/

/************************************************************************************************
 * Defines and Macros
 ************************************************************************************************/
/**
 * Microcontroller's architecture memory address size.
 **/
#define ARCH_ADDR_SIZE  unsigned char

/************************************************************************************************
 * Typedefs
 ************************************************************************************************/
/**
 * Byte type definition.
 **/
typedef unsigned char uint8_t;

/**
 * Microcontroller's GPIO ports.
 **/
typedef enum
{
    GPIO_PORT,       /**< Gpio port */
    GPIO_PORT_COUNT  /**< Number of ports on microcontroller */
} Port_t;

/**
 * Union that represents the GPIO port.
 **/
typedef union
{
    uint8_t Byte;        /**< Gpio port byte */

    uint8_t      : 2;    /**< Gpio port unused bits (reads 0) */
    uint8_t Bit5 : 1;    /**< Gpio port bit 5 (GP5) */
    uint8_t Bit4 : 1;    /**< Gpio port bit 4 (GP4) */
    uint8_t Bit3 : 1;    /**< Gpio port bit 3 (GP3) */
    uint8_t Bit2 : 1;    /**< Gpio port bit 2 (GP2) */
    uint8_t Bit1 : 1;    /**< Gpio port bit 1 (GP1) */
    uint8_t Bit0 : 1;    /**< Gpio port bit 0 (GP0) */
} GpioPort_t;

/**
 * Channels definitions for each GPIO pins.
 * GPIO_MAX_PIN_NUMBER is the control item for pin quantity.
 **/
typedef enum
{
    CHANNEL_GP0,        /**< Channel for GP0 */
    CHANNEL_GP1,        /**< Channel for GP1 */
    CHANNEL_GP2,        /**< Channel for GP2 */
    CHANNEL_GP3,        /**< Channel for GP3 */
    CHANNEL_GP4,        /**< Channel for GP4 */
    CHANNEL_GP5,        /**< Channel for GP5 */
    GPIO_CHANNEL_COUNT  /**< Number of gpio channels */
} GpioChannel_t;

/**
 * GPIO pin directions definitions.
 **/
typedef enum
{
    GPIO_PIN_DIRECTION_OUTPUT,  /**< Pin is output */
    GPIO_PIN_DIRECTION_INPUT    /**< Pin is input */
} GpioPinDirection_t;

/**
 * GPIO pin functions definitions.
 **/
typedef enum
{
    GPIO_PIN_FUNCTION_DIGITAL,               /**< Pin is digital mode */
    GPIO_PIN_FUNCTION_ANALOG,                /**< Pin is analog mode */
    GPIO_PIN_FUNCTION_COMPARATOR,            /**< Pin is comparator mode */
    GPIO_PIN_FUNCTION_TIMER,                 /**< Pin is timer enabled */
    GPIO_PIN_FUNCTION_CAPTURE_COMPARE,       /**< Pin is capture/compare mode */
    GPIO_PIN_FUNCTION_INTERRUPT_ON_CHANGE,   /**< Pin is interrupt-on-change enabled */
    GPIO_PIN_FUNCTION_EXTERNAL_INTERRUPT     /**< Pin is external interrupt enabled */
} GpioPinFunction_t;

/**
 * GPIO pin pullup resistors definitions.
 **/
typedef enum
{
    GPIO_PIN_PULLUP_DISABLED,  /**< Pin pull-up is disabled */
    GPIO_PIN_PULLUP_ENABLED    /**< Pin pull-up is enabled */
} GpioPinPullUp_t;

/**
 * GPIO pin interrupts definitions.
 **/
typedef enum
{
    GPIO_PIN_INTERRUPT_ON_CHANGE_DISABLED,  /**< Pin interrupts disabled */
    GPIO_PIN_INTERRUPT_ON_CHANGE_ENABLED    /**< Pin interrupts enabled */
} GpioPinInterruptOnChange_t;

/**
 * GPIO pin states definitions.
 **/
typedef enum
{
    GPIO_PIN_STATE_LOW,    /**< Low pin state */
    GPIO_PIN_STATE_HIGH,   /**< High pin state */
    GPIO_PIN_MAX_STATES    /**< Max pin states */
} GpioPinState_t;

/**
 * GPIO interrupt trigger edge types
 **/
typedef enum
{
    GPIO_INTERRUPT_EDGE_FALLING,    /**< Interrupt is enabled on falling edge (0) */
    GPIO_INTERRUPT_EDGE_RISING,     /**< Interrupt is enabled on rising edge (1) */
    GPIO_INTERRUPT_EDGE_NONE        /**< Interrupts are disabled */
} GpioInterruptEdge_t;

/**
 * GPIO callback events
 **/
typedef enum
{
    GPIO_EXTERNAL_INTERRUPT,
    GPIO_CALLBACK_EVENT_COUNT
} GpioCallbackEvent_t;

/**
 * GPIO configurations.
 **/
typedef struct
{
    GpioChannel_t       Channel;         /**< Name of gpio pin */
    GpioPinFunction_t   Function;        /**< Function of gpio pin */
    GpioPinDirection_t  Direction;       /**< Direction of gpio pin */
    GpioPinPullUp_t     PullUp;          /**< Pull-Up resistor of gpio pin */
    GpioPinState_t      State;           /**< Pin state */
    GpioInterruptEdge_t InterruptEdge;   /**< Interrupt edge trigger */
} GpioConfig_t;

/************************************************************************************************
 * Global Variables
 ************************************************************************************************/

/************************************************************************************************
 * Functions Prototypes
 ************************************************************************************************/
/**
 * Helper function to get GPIO configuration table.
 **/
const GpioConfig_t * const GpioConfigGet(void);

#endif //_GPIO_CFG_H_
/************************************************************************************************
 * EOF
 ************************************************************************************************/