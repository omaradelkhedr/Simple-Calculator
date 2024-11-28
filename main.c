/******************************************************************************
 *
 * Module: Main
 *
 * File Name: main.c
 *
 * Description: Main program to operate the calculator application, handling
 *              user inputs via keypad and displaying results on an LCD.
 *
 * Author: Omar Khedr, Ali Ashraf
 *
 ******************************************************************************/

#include "Application/Calculator_Interface.h"

/******************************************************************************
 * Function Name: main
 * Description: The entry point for the calculator program. Initializes the
 *              LCD and keypad modules, processes user inputs, evaluates
 *              mathematical expressions, and displays results.
 *
 * Parameters:
 *      - None
 *
 * Returns:
 *      - int: Program exit status (0 for success).
 ******************************************************************************/
int main(void)
{
    /* Initialization of LCD and Keypad modules */
    HLCD_VOIDInitialization();
    HKPD_VOIDInitialization();

    /* Local variables */
    u8 LOC_U8KeyPressed, LOC_U8ShiftDisplay = 0, LOC_U8Flag = 1, LOC_U8Counter = 0;
    u8 LOC_U8ExpressionArray[45];
    LOC_U8ExpressionArray[0] = '!'; /* Initial marker for the expression */

    while (1)
    {
        /* Get the pressed key from the keypad */
        LOC_U8KeyPressed = HKPD_U8GetPressedValue();

        /* Process the key if it's valid and the flag is active */
        if (30 != LOC_U8KeyPressed && LOC_U8Flag)
        {
            LOC_U8Counter++;
            if (LOC_U8KeyPressed == 'C') /* Handle clear operation */
            {
                HLCD_VOIDDeleteCharacter(LOC_U8Counter - 2);
                LOC_U8Counter -= 2;
            }
            else if (LOC_U8KeyPressed == '=') /* Handle calculation */
            {
                LOC_U8ExpressionArray[LOC_U8Counter] = LOC_U8KeyPressed;
                LOC_U8Counter = Calculator_VOIDCalculation(LOC_U8ExpressionArray);
            }
            else /* Add the character to the expression and display it */
            {
                LOC_U8ExpressionArray[LOC_U8Counter] = LOC_U8KeyPressed;
                HLCD_VOIDSendCharacter(LOC_U8KeyPressed);
            }

            /* Check if the display needs to shift for longer expressions */
            if (LOC_U8Counter == 15)
            {
                LOC_U8ShiftDisplay = 1;
            }

            while (LOC_U8ShiftDisplay)
            {
                LOC_U8KeyPressed = HKPD_U8GetPressedValue();
                if (LOC_U8KeyPressed != 30)
                {
                    if (LOC_U8KeyPressed == 'C') /* Handle clear in shifted display */
                    {
                        HLCD_VOIDDeleteCharacter(LOC_U8Counter - 1);
                        LOC_U8Counter--;
                        HLCD_VOIDShiftDisplayRight(1);
                        if (LOC_U8Counter <= 15)
                        {
                            LOC_U8ShiftDisplay = 0;
                        }
                    }
                    else if (LOC_U8KeyPressed == '=') /* Handle calculation in shifted display */
                    {
                        LOC_U8ExpressionArray[LOC_U8Counter + 1] = LOC_U8KeyPressed;
                        LOC_U8Counter = Calculator_VOIDCalculation(LOC_U8ExpressionArray);
                    }
                    else /* Add character and shift display left */
                    {
                        LOC_U8Counter++;
                        HLCD_VOIDShiftDisplayLeft(1);
                        LOC_U8ExpressionArray[LOC_U8Counter] = LOC_U8KeyPressed;
                        HLCD_VOIDSendCharacter(LOC_U8KeyPressed);
                    }

                    /* Disable shifting and input if the maximum limit is reached */
                    if (LOC_U8Counter >= 39)
                    {
                        LOC_U8ShiftDisplay = 0;
                        LOC_U8Flag = 0;
                    }
                }
            }
        }
    }

    return 0; /* Return success status */
}
