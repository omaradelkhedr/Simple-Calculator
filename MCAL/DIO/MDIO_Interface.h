/******************************************************************************
 *
 * Module: MDIO (MCAL Digital I/O)
 *
 * File Name: MDIO_Interface.h
 *
 * Description: Header file for the MDIO module functions
 *
 * Author: Omar Khedr
 *
 ******************************************************************************/
#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "MDIO_Private.h"

/************************************************************************************
 * Function Name: MDIO_VOIDSetPinDirection
 * Description: Sets the direction of a specific pin in a given port (input or output)
 * Parameters:
 *      - Copy_U8Port: The port number (0 to 3)
 *      - Copy_U8Pin: The pin number (0 to 7)
 *      - Copy_U8Direction: The direction (1 for output, 0 for input)
 * Return: None
 ************************************************************************************/
void MDIO_VOIDSetPinDirection(u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Direction);

/************************************************************************************
 * Function Name: MDIO_U8GetPinValue
 * Description: Gets the current value of a specific pin in a given port
 * Parameters:
 *      - Copy_U8Port: The port number (0 to 3)
 *      - Copy_U8Pin: The pin number (0 to 7)
 * Return: The value of the pin (0 or 1)
 ************************************************************************************/
u8 MDIO_U8GetPinValue(u8 Copy_U8Port, u8 Copy_U8Pin);

/************************************************************************************
 * Function Name: MDIO_VOIDSetPortValue
 * Description: Sets the value of all pins in a specific port
 * Parameters:
 *      - Copy_U8Port: The port number (0 to 3)
 *      - Copy_U8PortValue: The value to set for all pins in the port (0 to 255)
 * Return: None
 ************************************************************************************/
void MDIO_VOIDSetPortValue(u8 Copy_U8Port, u8 Copy_U8PortValue);

/************************************************************************************
 * Function Name: MDIO_VOIDSetPinValue
 * Description: Sets the value of a specific pin in a given port
 * Parameters:
 *      - Copy_U8Port: The port number (0 to 3)
 *      - Copy_U8Pin: The pin number (0 to 7)
 *      - Copy_U8Value: The value to set (1 or 0)
 * Return: None
 ************************************************************************************/
void MDIO_VOIDSetPinValue(u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Value);

/************************************************************************************
 * Function Name: MDIO_VOIDTogglePinValue
 * Description: Toggles the value of a specific pin in a given port
 * Parameters:
 *      - Copy_U8Port: The port number (0 to 3)
 *      - Copy_U8Pin: The pin number (0 to 7)
 * Return: None
 ************************************************************************************/
void MDIO_VOIDTogglePinValue(u8 Copy_U8Port, u8 Copy_U8Pin);

/************************************************************************************
 * Function Name: MDIO_VOIDSetPortDirection
 * Description: Sets the direction (input or output) of all pins in a given port
 * Parameters:
 *      - Copy_U8Port: The port number (0 to 3)
 *      - Copy_U8Direction: The direction for all pins in the port (0 for input, 255 for output)
 * Return: None
 ************************************************************************************/
void MDIO_VOIDSetPortDirection(u8 Copy_U8Port, u8 Copy_U8Direction);

/************************************************************************************
 * Function Name: MDIO_U8GetPortValue
 * Description: Gets the current value of all pins in a given port
 * Parameters:
 *      - Copy_U8Port: The port number (0 to 3)
 * Return: The value of all pins in the port (0 to 255)
 ************************************************************************************/
u8 MDIO_U8GetPortValue(u8 Copy_U8Port);

#endif
