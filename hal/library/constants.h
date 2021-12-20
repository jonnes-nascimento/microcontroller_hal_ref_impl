/************************************************************************************************
 * @Title          :    Support functions, types and constants
 * @Filename       :    constants.h
 * @Author         :    Eng. Jonnes F. Nascimento
 * @Origin Date    :    20/12/2021
 * @Version        :    0.0.1
 * @Compiler       :    GCC
 * @Target         :    --
 * @Notes          :    None
 * @Revision Date  :    --
 ************************************************************************************************/
/** **********************************************************************************************
 * @file constants.h
 * @brief Interface definition for support functions, types and constants
 *
 * <b>INTERFACE CHANGE LIST</b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 20/12/2021 </td><td> 0.0.1            </td><td> JFN      </td><td> Interface Created </td></tr>
 * </table><br><br><hr>
 ************************************************************************************************/
#ifndef _CONSTANTS_H
#define _CONSTANTS_H

/**
 * Microcontroller's commons electrical states
 **/
typedef enum
{
    LOW,           /**< Low state (0) */
    HIGH,          /**< High state (1) */
    TRI_STATED     /**< High Impedance (HiZ) */
} State_t;

#endif //_CONSTANTS_H
