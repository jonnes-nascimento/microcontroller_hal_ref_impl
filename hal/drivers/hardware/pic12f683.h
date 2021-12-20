/************************************************************************************************
 * @Title          :    PIC12F683 hardware definitions and specifications
 * @Filename       :    pic12f683.h
 * @Author         :    Eng. Jonnes F. Nascimento
 * @Origin Date    :    16/12/2021
 * @Version        :    0.0.1
 * @Compiler       :    GCC
 * @Target         :    --
 * @Notes          :    None
 * @Revision Date  :    20/12/2021
 ************************************************************************************************/
/** **********************************************************************************************
 * @file pic12f683.h
 * @brief PIC12F683 hardware definitions and specifications
 *
 *  This is the hardware definitions for PIC12F683.
 *
 * @addtogroup Hardware
 * Peripheral hardware and registers configuration group.
 *  @{
 * */
#ifndef _PIC12F683_H
#define _PIC12F683_H

volatile unsigned char * const GPIO   = (unsigned char *) 0x05;  /**< General purpose I/O port register memory address */
volatile unsigned char * const CMCON0 = (unsigned char *) 0x19;  /**< Comparator configuration register memory address */
volatile unsigned char * const ADCON0 = (unsigned char *) 0x1F;  /**< Analog/Digital converter register memory address */
volatile unsigned char * const TRISIO = (unsigned char *) 0x85;  /**< General purpose I/O pin direction register memory address */
volatile unsigned char * const OSCCON = (unsigned char *) 0x8F;  /**< System oscillator control register memory address */
volatile unsigned char * const ANSEL  = (unsigned char *) 0x9F;  /**< General purpose I/O port analog mode register memory address */

#endif //_PIC12F683_H

/************************************************************************************************
 * EOF
 ************************************************************************************************/
/** @} */
