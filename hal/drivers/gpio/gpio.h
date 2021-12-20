/************************************************************************************************
 * @Title          :    General purpose input/output interface
 * @Filename       :    gpio.h
 * @Author         :    Eng. Jonnes F. Nascimento
 * @Origin Date    :    16/12/2021
 * @Version        :    0.0.1
 * @Compiler       :    GCC
 * @Target         :    --
 * @Notes          :    None
 * @Revision Date  :    20/12/2021
 ************************************************************************************************/
/** **********************************************************************************************
 * @file gpio.h
 * @brief Interface definition for general purpose input/output (GPIO)
 *
 *  This is the header file for the definition of the interface for a digital
 *  input / output peripheral on a standard microcontroller. Some microcontrollers
 *  call this digital I/O as PORT_x. In this case, this is called GPIO.
 *
 * <b>INTERFACE CHANGE LIST</b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 16/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Interface Created </td></tr>
 * <tr><td> 20/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Documentation Created </td></tr>
 * </table><br><br><hr>
 ************************************************************************************************/
#ifndef _GPIO_H_
#define _GPIO_H_

/************************************************************************************************
 * Includes
 ************************************************************************************************/
#include "gpio/gpio_config.h"

/************************************************************************************************
 * Defines and Macros
 ************************************************************************************************/

/************************************************************************************************
 * Typedefs
 ************************************************************************************************/

/************************************************************************************************
 * Global Variables
 ************************************************************************************************/

/************************************************************************************************
 * Functions Prototypes
 ************************************************************************************************/
void Gpio_Init(const GpioConfig_t * const Config);
void Gpio_Write(GpioChannel_t channel, GpioPinState_t state);
void Gpio_Write_Register(GpioPort_t port);

#endif //_GPIO_H_
/************************************************************************************************
 * EOF
 ************************************************************************************************/
