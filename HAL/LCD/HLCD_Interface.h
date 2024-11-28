/******************************************************************************
 *
 * Module: HLCD (HAL LCD Interface)
 *
 * File Name: HLCD_Interface.h
 *
 * Description: Header file for the HLCD module, providing APIs for LCD control
 *              and display operations.
 *
 * Author: Omar Khedr
 *
 ******************************************************************************/

#ifndef _HLCD_INTERFACE_H_
#define _HLCD_INTERFACE_H_

/* Include standard and required libraries */
#include "../../LIB/STD_TYPES.h"       /* Standard data types */
#include "../../LIB/BIT_MATH.h"        /* Bit manipulation macros */
#include "../../MCAL/DIO/MDIO_Interface.h" /* DIO module interface */
#include <avr/delay.h>                 /* AVR delay functions */
#include "HLCD_CFG.h"                  /* HLCD configuration file */

/************************************************************************************
 * Function Name: HLCD_VOIDSendCharacter
 * Description: Sends a character to the LCD for display.
 * Parameters:
 *      - Copy_U8Data: The character to be displayed.
 * Return: None
 ************************************************************************************/
void HLCD_VOIDSendCharacter(u8 Copy_U8Data);

/************************************************************************************
 * Function Name: HLCD_VOIDSendCommand
 * Description: Sends a command to the LCD for configuration.
 * Parameters:
 *      - Copy_U8Command: The command to be sent.
 * Return: None
 ************************************************************************************/
void HLCD_VOIDSendCommand(u8 Copy_U8Command);

/************************************************************************************
 * Function Name: HLCD_VOIDInitialization
 * Description: Initializes the LCD by configuring the required pins and sending
 *              initialization commands.
 * Parameters: None
 * Return: None
 ************************************************************************************/
void HLCD_VOIDInitialization(void);

/************************************************************************************
 * Function Name: HLCD_VOIDSendNumber
 * Description: Displays a numerical value on the LCD.
 * Parameters:
 *      - Copy_U32Number: The number to be displayed.
 * Return: None
 ************************************************************************************/
void HLCD_VOIDSendNumber(u32 Copy_U32Number);

/************************************************************************************
 * Function Name: HLCD_VOIDSetPosition
 * Description: Sets the cursor position on the LCD.
 * Parameters:
 *      - Copy_U8Row: The row number (0 or 1).
 *      - Copy_U8Column: The column number (0 to 15).
 * Return: None
 ************************************************************************************/
void HLCD_VOIDSetPosition(u8 Copy_U8Row, u8 Copy_U8Column);

/************************************************************************************
 * Function Name: HLCD_VOIDDrawPattern
 * Description: Draws a custom pattern on the LCD.
 * Parameters: None
 * Return: None
 ************************************************************************************/
void HLCD_VOIDDrawPattern(void);

/************************************************************************************
 * Function Name: HLCD_VOIDSendString
 * Description: Displays a string on the LCD.
 * Parameters:
 *      - Copy_U8String[]: The string to be displayed.
 * Return: None
 ************************************************************************************/
void HLCD_VOIDSendString(u8 Copy_U8String[]);

/************************************************************************************
 * Function Name: HLCD_VOIDShiftCursorRight
 * Description: Shifts the cursor one position to the right.
 * Parameters: None
 * Return: None
 ************************************************************************************/
void HLCD_VOIDShiftCursorRight(void);

/************************************************************************************
 * Function Name: HLCD_VOIDShiftCursorLeft
 * Description: Shifts the cursor one position to the left.
 * Parameters: None
 * Return: None
 ************************************************************************************/
void HLCD_VOIDShiftCursorLeft(void);

/************************************************************************************
 * Function Name: HLCD_VOIDShiftDisplayRight
 * Description: Shifts the entire LCD display to the right by a specified amount.
 * Parameters:
 *      - Copy_U8Shift: Number of positions to shift.
 * Return: None
 ************************************************************************************/
void HLCD_VOIDShiftDisplayRight(u8 Copy_U8Shift);

/************************************************************************************
 * Function Name: HLCD_VOIDShiftDisplayLeft
 * Description: Shifts the entire LCD display to the left by a specified amount.
 * Parameters:
 *      - Copy_U8Shift: Number of positions to shift.
 * Return: None
 ************************************************************************************/
void HLCD_VOIDShiftDisplayLeft(u8 Copy_U8Shift);

/************************************************************************************
 * Function Name: HLCD_VOIDDeleteCharacter
 * Description: Deletes a character from a specified position on the LCD.
 * Parameters:
 *      - Copy_U8Index: The position index of the character to delete.
 * Return: None
 ************************************************************************************/
void HLCD_VOIDDeleteCharacter(u8 Copy_U8Index);

/************************************************************************************
 * Function Name: HLCD_VOIDClearDisplay
 * Description: Clears the entire LCD display.
 * Parameters: None
 * Return: None
 ************************************************************************************/
void HLCD_VOIDClearDisplay(void);

#endif
