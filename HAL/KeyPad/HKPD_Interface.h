/******************************************************************************
 *
 * Module: HKPD (HAL Keypad Interface)
 *
 * File Name: HKPD_Interface.h
 *
 * Description: Header file for the keypad module, containing function
 *              declarations for keypad initialization and key detection.
 *
 * Author: Omar Khedr
 *
 ******************************************************************************/

#ifndef _HKPD_INTERFACE_H_
#define _HKPD_INTERFACE_H_

/* Include Standard Types Library */
#include "../../LIB/STD_TYPES.h"

/* Include MDIO Interface for DIO functionalities */
#include "../../MCAL/DIO/MDIO_Interface.h"

/* Include Delay Library for timing functions */
#include <avr/delay.h>

/************************************************************************************
 * Function Name: HKPD_VOIDInitialization
 * Description: Configures the keypad pins as input and output and initializes them.
 * Parameters: None
 * Return: None
 ************************************************************************************/
void HKPD_VOIDInitialization(void);

/************************************************************************************
 * Function Name: HKPD_U8GetPressedValue
 * Description: Scans the keypad to detect a pressed key and returns its value.
 * Parameters: None
 * Return:
 *      - u8: The ASCII value of the pressed key or 30 (indicating no key pressed).
 ************************************************************************************/
u8 HKPD_U8GetPressedValue(void);

#endif /* _HKPD_INTERFACE_H_ */
