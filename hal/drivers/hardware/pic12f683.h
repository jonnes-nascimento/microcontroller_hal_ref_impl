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

unsigned char const GIE1_BIT_MASK   = (unsigned char) 0x80;   /**< INTCON GIE1 (global interrupt enable) bit mask */
unsigned char const INTE_BIT_MASK   = (unsigned char) 0x10;   /**< INTCON INTE (GP2/INT - external interrupt enable) bit mask */
unsigned char const INTF_BIT_MASK   = (unsigned char) 0x02;   /**< INTCON INTF (GP2/INT - external interrupt flag) bit mask */
unsigned char const INTEDG_BIT_MASK = (unsigned char) 0x40;   /**< OPTION INTEDG (GP2/INT - external interrupt edge trigger) bit mask */

volatile unsigned char * const FSR    = (unsigned char *) 0x04;  /**< Indirect data memory adrress pointer  */
volatile unsigned char * const GPIO   = (unsigned char *) 0x05;  /**< General purpose I/O port register */
volatile unsigned char * const INTCON = (unsigned char *) 0x0B;  /**< Interrupt control register */
volatile unsigned char * const PIR1   = (unsigned char *) 0x0C;  /**< Peripheral interrupt request register 1 */
volatile unsigned char * const CMCON0 = (unsigned char *) 0x19;  /**< Comparator configuration register */
volatile unsigned char * const ADCON0 = (unsigned char *) 0x1F;  /**< Analog/Digital converter register */
volatile unsigned char * const OPTION = (unsigned char *) 0x85;  /**< Control bits register */
volatile unsigned char * const TRISIO = (unsigned char *) 0x85;  /**< General purpose I/O pin direction register */
volatile unsigned char * const PIE1   = (unsigned char *) 0x8C;  /**< Peripheral interrupt enable register 1 */
volatile unsigned char * const OSCCON = (unsigned char *) 0x8F;  /**< System oscillator control register */
volatile unsigned char * const ANSEL  = (unsigned char *) 0x9F;  /**< General purpose I/O port analog mode register */

#endif //_PIC12F683_H

/************************************************************************************************
 * EOF
 ************************************************************************************************/
/** @} */
