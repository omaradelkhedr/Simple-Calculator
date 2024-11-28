/******************************************************************************
 *
 * Module: HKPD (HAL Keypad Interface)
 *
 * File Name: HKPD_Interface.c
 *
 * Description: Source file for the keypad module, containing functions for
 *              initializing the keypad and detecting pressed keys.
 *
 * Author: Omar Khedr
 *
 ******************************************************************************/

#include "HKPD_Interface.h"

/************************************************************************************
 * Function Name: HKPD_VOIDInitialization
 * Description: Configures the keypad pins as input and output and initializes them.
 * Parameters: None
 * Return: None
 ************************************************************************************/
void HKPD_VOIDInitialization(void)
{
    /* Set lower nibble (R0-R3) as output and upper nibble (C0-C3) as input */
    MDIO_VOIDSetPortDirection(0, 0b00001111);

    /* Activate pull-up resistors on input pins (C0-C3) */
    MDIO_VOIDSetPortValue(0, 0b11111111);
}

/************************************************************************************
 * Function Name: HKPD_U8GetPressedValue
 * Description: Scans the keypad to detect a pressed key and returns its value.
 * Parameters: None
 * Return:
 *      - u8: The ASCII value of the pressed key or 30 (indicating no key pressed).
 ************************************************************************************/
u8 HKPD_U8GetPressedValue(void)
{
    u8 LOC_U8Row, LOC_U8Column, LOC_U8PinValue, LOC_U8ReturnedValue = 30;

    /* 2D array representing the keypad layout */
    u8 LOC_U8CalculatorKeys[4][4] = {
        {'7', '8', '9', '/'},
        {'4', '5', '6', '*'},
        {'1', '2', '3', '-'},
        {'C', '0', '=', '+'}
    };

    /* Iterate through each column */
    for (LOC_U8Column = 0; LOC_U8Column < 4; LOC_U8Column++)
    {
        /* Activate the current column by driving it LOW */
        MDIO_VOIDSetPinValue(0, LOC_U8Column, 0);

        /* Check each row in the current column */
        for (LOC_U8Row = 0; LOC_U8Row < 4; LOC_U8Row++)
        {
            /* Read the state of the current row pin */
            LOC_U8PinValue = MDIO_U8GetPinValue(0, LOC_U8Row + 4);

            /* If a key is pressed (row pin is LOW) */
            if (0 == LOC_U8PinValue)
            {
                /* Get the corresponding key value from the layout array */
                LOC_U8ReturnedValue = LOC_U8CalculatorKeys[LOC_U8Row][LOC_U8Column];

                /* Wait until the key is released */
                while (0 == MDIO_U8GetPinValue(0, LOC_U8Row + 4))
                {
                    /* Do nothing */
                }

                /* Debounce delay */
                _delay_ms(10);
            }
        }

        /* Deactivate the current column by driving it HIGH */
        MDIO_VOIDSetPinValue(0, LOC_U8Column, 1);
    }

    /* Return the detected key value (or 30 if no key is pressed) */
    return LOC_U8ReturnedValue;
}
