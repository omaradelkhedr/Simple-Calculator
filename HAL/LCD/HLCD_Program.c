/******************************************************************************
 *
 * Module: HLCD (HAL LCD Program)
 *
 * File Name: HLCD_Program.c
 *
 * Description: Source file containing the implementation of APIs for LCD control
 *              and display operations.
 *
 * Author: Omar Khedr
 *
 ******************************************************************************/

#include "HLCD_Interface.h"

/************************************************************************************
 * Function Name: HLCD_VOIDSendCharacter
 * Description: Sends a character to the LCD for display.
 * Parameters:
 *      - Copy_U8Data: The character to be displayed.
 * Return: None
 ************************************************************************************/
void HLCD_VOIDSendCharacter(u8 Copy_U8Data)
{
    MDIO_VOIDSetPinValue(CONTROL_PORT, RS_PIN, 1);
    MDIO_VOIDSetPinValue(CONTROL_PORT, RW_PIN, 0);
    MDIO_VOIDSetPortValue(DATA_PORT, Copy_U8Data);

    MDIO_VOIDSetPinValue(CONTROL_PORT, EN_PIN, 1);
    _delay_us(10);
    MDIO_VOIDSetPinValue(CONTROL_PORT, EN_PIN, 0);
    _delay_ms(2);
}

/************************************************************************************
 * Function Name: HLCD_VOIDSendCommand
 * Description: Sends a command to the LCD for configuration.
 * Parameters:
 *      - Copy_U8Command: The command to be sent.
 * Return: None
 ************************************************************************************/
void HLCD_VOIDSendCommand(u8 Copy_U8Command)
{
    MDIO_VOIDSetPinValue(CONTROL_PORT, RS_PIN, 0);
    MDIO_VOIDSetPinValue(CONTROL_PORT, RW_PIN, 0);
    MDIO_VOIDSetPortValue(DATA_PORT, Copy_U8Command);

    MDIO_VOIDSetPinValue(CONTROL_PORT, EN_PIN, 1);
    _delay_us(10);
    MDIO_VOIDSetPinValue(CONTROL_PORT, EN_PIN, 0);
    _delay_ms(2);
}

/************************************************************************************
 * Function Name: HLCD_VOIDInitialization
 * Description: Initializes the LCD by configuring the required pins and sending
 *              initialization commands.
 * Parameters: None
 * Return: None
 ************************************************************************************/
void HLCD_VOIDInitialization(void)
{
    MDIO_VOIDSetPortDirection(DATA_PORT, 0b11111111);
    MDIO_VOIDSetPinDirection(CONTROL_PORT, RS_PIN, 1);
    MDIO_VOIDSetPinDirection(CONTROL_PORT, RW_PIN, 1);
    MDIO_VOIDSetPinDirection(CONTROL_PORT, EN_PIN, 1);

    _delay_ms(40);
    HLCD_VOIDSendCommand(0b00111000); /* Function Set */
    _delay_ms(1);
    HLCD_VOIDSendCommand(0b00001111); /* Display ON */
    _delay_ms(1);
    HLCD_VOIDSendCommand(0b00000001); /* Clear Display */
    _delay_ms(5);
    HLCD_VOIDSendCommand(0b00000110); /* Entry Mode Set */
}

/************************************************************************************
 * Function Name: HLCD_VOIDSendNumber
 * Description: Displays a numerical value on the LCD.
 * Parameters:
 *      - Copy_U32Number: The number to be displayed.
 * Return: None
 ************************************************************************************/
void HLCD_VOIDSendNumber(u32 Copy_U32Number)
{
    u32 LOC_U32Reversed = 1, LOC_U32SentCharacter;

    if (Copy_U32Number == 0)
    {
        HLCD_VOIDSendCharacter('0');
    }

    while (Copy_U32Number > 0)
    {
        LOC_U32Reversed = (LOC_U32Reversed * 10) + (Copy_U32Number % 10);
        Copy_U32Number /= 10;
    }

    while (LOC_U32Reversed > 1)
    {
        LOC_U32SentCharacter = LOC_U32Reversed % 10;
        HLCD_VOIDSendCharacter(LOC_U32SentCharacter + '0');
        LOC_U32Reversed /= 10;
    }
}

/************************************************************************************
 * Function Name: HLCD_VOIDSetPosition
 * Description: Sets the cursor position on the LCD.
 * Parameters:
 *      - Copy_U8Row: The row number (0 or 1).
 *      - Copy_U8Column: The column number (0 to 15).
 * Return: None
 ************************************************************************************/
void HLCD_VOIDSetPosition(u8 Copy_U8Row, u8 Copy_U8Column)
{
    if (Copy_U8Row == 0)
    {
        HLCD_VOIDSendCommand(128 + Copy_U8Column);
    }
    else if (Copy_U8Row == 1)
    {
        HLCD_VOIDSendCommand(128 + 64 + Copy_U8Column);
    }
}

/************************************************************************************
 * Function Name: HLCD_VOIDDrawPattern
 * Description: Draws predefined custom patterns on the LCD.
 * Parameters: None
 * Return: None
 ************************************************************************************/
void HLCD_VOIDDrawPattern(void)
{
    /* Set CGRAM Address */
    HLCD_VOIDSendCommand(0b01000000);

    /* Pattern 1: Heart */
    HLCD_VOIDSendCharacter(0b00000000);
    HLCD_VOIDSendCharacter(0b00000000);
    HLCD_VOIDSendCharacter(0b00001010);
    HLCD_VOIDSendCharacter(0b00011111);
    HLCD_VOIDSendCharacter(0b00001110);
    HLCD_VOIDSendCharacter(0b00000100);
    HLCD_VOIDSendCharacter(0b00000000);
    HLCD_VOIDSendCharacter(0b00000000);

    /* Additional patterns omitted for brevity */
}

/************************************************************************************
 * Function Name: HLCD_VOIDSendString
 * Description: Displays a string on the LCD.
 * Parameters:
 *      - Copy_U8String[]: The string to be displayed.
 * Return: None
 ************************************************************************************/
void HLCD_VOIDSendString(u8 Copy_U8String[])
{
    u8 LOC_U8Character, LOC_U8Iterator = 0;
    while (Copy_U8String[LOC_U8Iterator]) 
    {
        LOC_U8Character = Copy_U8String[LOC_U8Iterator];
        HLCD_VOIDSendCharacter(LOC_U8Character);
        LOC_U8Iterator++;
    }
}

/************************************************************************************
 * Function Name: HLCD_VOIDShiftCursorRight
 * Description: Shifts the cursor one position to the right.
 * Parameters: None
 * Return: None
 ************************************************************************************/
void HLCD_VOIDShiftCursorRight(void)
{
    HLCD_VOIDSendCommand(0b00010100);
}

/************************************************************************************
 * Function Name: HLCD_VOIDShiftCursorLeft
 * Description: Shifts the cursor one position to the left.
 * Parameters: None
 * Return: None
 ************************************************************************************/
void HLCD_VOIDShiftCursorLeft(void)
{
    HLCD_VOIDSendCommand(0b00010000);
}

/************************************************************************************
 * Function Name: HLCD_VOIDShiftDisplayRight
 * Description: This function shifts the entire display to the right by a
 * 				specified number of positions.
 * Parameters: u8 Copy_U8Shift - value of shift positions
 * Return: None
 ************************************************************************************/

void HLCD_VOIDShiftDisplayRight(u8 Copy_U8Shift)
{
    for (u8 LOC_U8Index = 0; LOC_U8Index < Copy_U8Shift; LOC_U8Index++)
    {
        HLCD_VOIDSendCommand(0b00011100); /* Shift display to the right */
    }
}


/************************************************************************************
 * Function Name: HLCD_VOIDShiftDisplayLeft
 * Description: This function shifts the entire display to the left by a
 * 				specified number of positions.
 * Parameters: u8 Copy_U8Shift - value of shift positions
 * Return: None
 ************************************************************************************/

void HLCD_VOIDShiftDisplayLeft(u8 Copy_U8Shift)
{
    for (u8 LOC_U8Index = 0; LOC_U8Index < Copy_U8Shift; LOC_U8Index++)
    {
        HLCD_VOIDSendCommand(0b00011000); /* Shift display to the left */
    }
}

/************************************************************************************
 * Function Name: HLCD_VOIDDeleteCharacter
 * Description: This function deletes a character at a specific index by
 * 				overwriting it with a space. The position is reset after deleting the character.
 * Parameters: u8 Copy_U8Index - index of deleted character
 * Return: None
 ************************************************************************************/

void HLCD_VOIDDeleteCharacter(u8 Copy_U8Index)
{
    if (Copy_U8Index > 0 && Copy_U8Index < 40)
    {
        HLCD_VOIDSetPosition(0, Copy_U8Index); /* Set the cursor to the given position */
        HLCD_VOIDSendCharacter(0b10000001); /* Send a blank character to delete the current character */
        HLCD_VOIDSetPosition(0, Copy_U8Index); /* Reset the position after deletion */
    }
    else
    {
        HLCD_VOIDSetPosition(0, 0); /* If index is invalid, reset to the start of the line */
        HLCD_VOIDSendCharacter(0b10000001); /* Send a blank character to delete */
        HLCD_VOIDSetPosition(0, 0); /* Reset position */
    }
}

/*
 * HLCD_VOIDClearDisplay function:
 * This function clears the entire LCD display by sending the clear display command.
 */


/************************************************************************************
 * Function Name: HLCD_VOIDClearDisplay
 * Description: This function clears the entire LCD display by sending the clear
 * 				display command.
 * Parameters: None
 * Return: None
 ************************************************************************************/

void HLCD_VOIDClearDisplay (void)
{
    HLCD_VOIDSendCommand(0b00000001); /* Send command to clear display */
}

