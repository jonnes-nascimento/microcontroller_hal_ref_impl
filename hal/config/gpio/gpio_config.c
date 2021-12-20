/************************************************************************************************
 * @Title          :    General purpose input/output configurations
 * @Filename       :    gpio_config.c
 * @Author         :    Eng. Jonnes F. Nascimento
 * @Origin Date    :    16/12/2021
 * @Version        :    0.0.1
 * @Compiler       :    GCC
 * @Target         :    --
 * @Notes          :    None
 * @Revision Date  :    20/12/2021
 ************************************************************************************************/
/** **********************************************************************************************
 * @file gpio_config.c
 * @brief Interface implementation for general purpose input/output configurations
 *
 *  This is the implementation file for the configurations of a digital
 *  input / output peripheral.
 *
 * @addtogroup Configurations
 * Peripheral configurations group.
 *  @{
 * */

/************************************************************************************************
 * Includes
 ************************************************************************************************/
#include "gpio_config.h"

/************************************************************************************************
 * Defines and Macros
 ************************************************************************************************/

/************************************************************************************************
 * Global Variables
 ************************************************************************************************/

/**
 * GPIO channels configuration table.
 **/
static const GpioConfig_t GpioConfig[] = {
        {CHANNEL_GP0, GPIO_PIN_FUNCTION_DIGITAL, GPIO_PIN_DIRECTION_OUTPUT, GPIO_PIN_PULLUP_DISABLED, GPIO_PIN_STATE_HIGH},
        {CHANNEL_GP1, GPIO_PIN_FUNCTION_DIGITAL, GPIO_PIN_DIRECTION_INPUT,  GPIO_PIN_PULLUP_DISABLED, GPIO_PIN_STATE_LOW},
        {CHANNEL_GP2, GPIO_PIN_FUNCTION_DIGITAL, GPIO_PIN_DIRECTION_OUTPUT, GPIO_PIN_PULLUP_DISABLED, GPIO_PIN_STATE_HIGH},
        {CHANNEL_GP3, GPIO_PIN_FUNCTION_DIGITAL, GPIO_PIN_DIRECTION_INPUT,  GPIO_PIN_PULLUP_DISABLED, GPIO_PIN_STATE_LOW},
        {CHANNEL_GP4, GPIO_PIN_FUNCTION_DIGITAL, GPIO_PIN_DIRECTION_OUTPUT, GPIO_PIN_PULLUP_DISABLED, GPIO_PIN_STATE_HIGH},
        {CHANNEL_GP5, GPIO_PIN_FUNCTION_DIGITAL, GPIO_PIN_DIRECTION_OUTPUT, GPIO_PIN_PULLUP_DISABLED, GPIO_PIN_STATE_HIGH}
};

/************************************************************************************************
 * Functions Definitions
 ************************************************************************************************/

/************************************************************************************************
* Function: const GpioConfig_t * const GpioConfigGet(void);
*//**
 *
 * \b Description:
 *
 * Helper function to get GPIO configuration table.
 *
 * Pre-condition: Configuration table defined (sizeof > 0) <br>
 *
 * Post-condition: Pointer with first item of the GPIO configurations table
 *
 * @param []          void
 *
 * @return            const GpioConfig_t *
 *
 * \b Example:
 *
 * @code
 * const GpioConfig_t Config = GpioConfigGet();
 * @endcode
 *
 * <b>HISTORY OF CHANGES</b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 16/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Interface Created </td></tr>
 * <tr><td> 20/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Documentation Created </td></tr>
 * </table><br><br><hr>
 ************************************************************************************************/
const GpioConfig_t * const GpioConfigGet(void)
{
    return (const GpioConfig_t *) &GpioConfig[0];
}

/************************************************************************************************
 * EOF
 ************************************************************************************************/
/** @} */