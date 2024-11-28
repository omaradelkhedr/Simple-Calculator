/******************************************************************************
 *
 * Module: Calculator
 *
 * File Name: Calculator_Program.c
 *
 * Description: Source file for the Calculator module, containing function
 *              implementations for performing calculations and evaluating
 *              mathematical expressions.
 *
 * Author: Omar Khedr , Ali Ashraf
 *
 ******************************************************************************/

/* Include the header file for the Calculator module */
#include "Calculator_Interface.h"

/************************************************************************************
 * Function Name: Calculator_U8ErrorState
 * Description: Checks the input expression for syntax errors or invalid operations,
 *              such as misplaced operators or division by zero.
 * Parameters:
 *      - Copy_U8ExpressionArray: Pointer to the array containing the expression to check.
 * Return:
 *      - u8: Error state (0: No error, 1: Syntax error, 2: Math error).
 ************************************************************************************/
u8 Calculator_U8ErrorState(u8 * Copy_U8ExpressionArray)
{
	u8 LOC_U8State=0,LOC_U8Iterator=0;
	/*
	 * Checking if the second character of the expression is an operator.
	 * If it's '+' or '*' or '/', set error state to 1.
	 */
	if(Copy_U8ExpressionArray[1]=='+' || Copy_U8ExpressionArray[1]=='*' || Copy_U8ExpressionArray[1]=='/' )
	{
		LOC_U8State=1;
	}
	/*
	 * Looping through the expression starting from the third character,
	 * checking if there are any invalid operations (consecutive operators).
	 */
	for(LOC_U8Iterator=2;Copy_U8ExpressionArray[LOC_U8Iterator]!='=' && !LOC_U8State;LOC_U8Iterator++)
	{
		/*
		 * Checking if a valid operator is followed by another operator,
		 * if so, set error state to 1.
		 */
		if(Copy_U8ExpressionArray[LOC_U8Iterator]== '+' || Copy_U8ExpressionArray[LOC_U8Iterator]== '-' || Copy_U8ExpressionArray[LOC_U8Iterator]== '*' || Copy_U8ExpressionArray[LOC_U8Iterator]== '/')
		{
			if(Copy_U8ExpressionArray[LOC_U8Iterator+1]=='+'  || Copy_U8ExpressionArray[LOC_U8Iterator+1]== '*' || Copy_U8ExpressionArray[LOC_U8Iterator+1]== '/')
			{
				LOC_U8State=1;
			}
		}
		/*
		 * Checking for division by zero error. If division by zero is detected, set error state to 2.
		 */
		if(Copy_U8ExpressionArray[LOC_U8Iterator]== '/')
		{
			if(Copy_U8ExpressionArray[LOC_U8Iterator+1]=='0')
			{
				if(Copy_U8ExpressionArray[LOC_U8Iterator+2]=='+'  || Copy_U8ExpressionArray[LOC_U8Iterator+2]== '*' || Copy_U8ExpressionArray[LOC_U8Iterator+2]== '/' || Copy_U8ExpressionArray[LOC_U8Iterator+2]== '-' || Copy_U8ExpressionArray[LOC_U8Iterator+2]== '=')
				{
					LOC_U8State=2;
				}
			}
		}
	}
	/*
	 * If the last character is an operator, set error state to 1.
	 */
	if((Copy_U8ExpressionArray[LOC_U8Iterator-1]== '+' || Copy_U8ExpressionArray[LOC_U8Iterator-1]== '-' || Copy_U8ExpressionArray[LOC_U8Iterator-1]== '*' || Copy_U8ExpressionArray[LOC_U8Iterator-1]== '/') && !LOC_U8State)
	{
		LOC_U8State=1;
	}
	return LOC_U8State;
}


/************************************************************************************
 * Function Name: Calculator_U8OperationsOrder
 * Description: Identifies the order of operations in the expression based on precedence
 *              and stores the order in a separate array.
 * Parameters:
 *      - Copy_U8ExpressionArray: Pointer to the array containing the mathematical expression.
 *      - Copy_U8OrderArray: Pointer to the array used to store the order of operations.
 * Return:
 *      - u8: The total number of operations detected in the expression.
 ************************************************************************************/
u8 Calculator_U8OperationsOrder(u8 * Copy_U8ExpressionArray,u8 *Copy_U8OrderArray)
{
	u8 LOC_U8OperationsNumber=0,LOC_U8Iterator2=0;
	/*
	 * First loop: Finding positions of multiplication operations ('*') in the expression.
	 */
	for(u8 LOC_U8Iterator=0;Copy_U8ExpressionArray[LOC_U8Iterator];LOC_U8Iterator++)
	{
		if(Copy_U8ExpressionArray[LOC_U8Iterator]=='*')
		{
			Copy_U8OrderArray[LOC_U8Iterator2]=LOC_U8Iterator;
			LOC_U8Iterator2++;
			LOC_U8OperationsNumber++;
		}
	}
	/*
	 * Second loop: Finding positions of division operations ('/') in the expression.
	 */
	for(u8 iterator=0;Copy_U8ExpressionArray[iterator];iterator++)
	{
		if(Copy_U8ExpressionArray[iterator]=='/')
		{
			Copy_U8OrderArray[LOC_U8Iterator2]=iterator;
			LOC_U8Iterator2++;
			LOC_U8OperationsNumber++;
		}
	}
	/*
	 * Third loop: Finding positions of addition operations ('+') in the expression.
	 */
	for(u8 iterator=0;Copy_U8ExpressionArray[iterator];iterator++)
	{
		if(Copy_U8ExpressionArray[iterator]=='+')
		{
			Copy_U8OrderArray[LOC_U8Iterator2]=iterator;
			LOC_U8Iterator2++;
			LOC_U8OperationsNumber++;
		}
	}
	/*
	 * Fourth loop: Finding positions of subtraction operations ('-') in the expression.
	 */
	for(u8 iterator=2;Copy_U8ExpressionArray[iterator];iterator++)
	{
		if(Copy_U8ExpressionArray[iterator]=='-')
		{
			Copy_U8OrderArray[LOC_U8Iterator2]=iterator;
			LOC_U8Iterator2++;
			LOC_U8OperationsNumber++;
		}
	}
	/*
	 * Null-terminating the order array of operations.
	 */
	Copy_U8OrderArray[LOC_U8Iterator2]='\0';
	return LOC_U8OperationsNumber;
}


/************************************************************************************
 * Function Name: Calculator_U32GetPower
 * Description: Computes the power of a base number raised to an exponent.
 * Parameters:
 *      - Copy_U32Number: The base number to calculate the power of.
 *      - Copy_U8Power: The exponent to raise the base number to.
 * Return:
 *      - u32: The result of the power calculation.
 ************************************************************************************/
u32 Calculator_U32GetPower (u32 Copy_U32Number, u8 Copy_U8Power)
{
	u32 LOC_U32Result = 1;
	/*
	 * If the power is 0, the result is always 1 (any number raised to the power of 0 is 1).
	 */
	if(Copy_U8Power == 0)
	{
		LOC_U32Result = 1;
	}
	else
	{
		/*
		 * Loop to calculate the number raised to the given power.
		 */
		for(u8 LOC_U8Iterator = 0; LOC_U8Iterator < Copy_U8Power; LOC_U8Iterator++)
		{
			LOC_U32Result = LOC_U32Result*Copy_U32Number;
		}
	}
	return LOC_U32Result;
}
/************************************************************************************
 * Function Name: Calculator_VOIDGetNumberBefore
 * Description: Extracts the number immediately preceding an operator in the
 *              expression and stores it in the provided array.
 * Parameters:
 *      - Copy_U8ExpressionArray: Pointer to the array containing the mathematical expression.
 *      - Copy_S32NumbersArray: Pointer to the array where the extracted number will be stored.
 *      - Copy_U8Index: The index in the expression where extraction begins.
 * Return:
 *      - void
 ************************************************************************************/
void Calculator_VOIDGetNumberBefore(u8 *Copy_U8ExpressionArray , s32 *Copy_S32NumbersArray,u8 Copy_U8Index)
{
	u8 LOC_U8NumberOfnumbers=0;
	s32 LOC_S32Accumlator = 0;
	/*
	 * Loop to accumulate the number before the operator.
	 */
	while(1)
	{
		if(Copy_U8ExpressionArray[Copy_U8Index-1] == '*' || Copy_U8ExpressionArray[Copy_U8Index-1] == '+' || Copy_U8ExpressionArray[Copy_U8Index-1] == '/' || Copy_U8ExpressionArray[Copy_U8Index-1] == '=' || Copy_U8ExpressionArray[Copy_U8Index-1] == '!' )
		{
			break;
		}
		if(Copy_U8ExpressionArray[Copy_U8Index-1]=='-')
		{
			LOC_S32Accumlator=(~LOC_S32Accumlator)+1;
			break;
		}
		/*
		 * Accumulating number from expression.
		 */
		LOC_S32Accumlator = LOC_S32Accumlator + ((Copy_U8ExpressionArray[Copy_U8Index-1]-48) * Calculator_U32GetPower(10,LOC_U8NumberOfnumbers));
		Copy_U8Index--;
		LOC_U8NumberOfnumbers++;
	}
	/*
	 * Storing the accumulated number in the numbers array.
	 */
	Copy_S32NumbersArray[0] = LOC_S32Accumlator;
}

/************************************************************************************
 * Function Name: Calculator_VOIDGetNumberAfter
 * Description: Extracts the number immediately following an operator in the
 *              expression and stores it in the provided array.
 * Parameters:
 *      - Copy_U8ExpressionArray: Pointer to the array containing the mathematical expression.
 *      - Copy_S32NumbersArray: Pointer to the array where the extracted number will be stored.
 *      - Copy_U8Index: The index in the expression where extraction begins.
 * Return:
 *      - void
 ************************************************************************************/
void Calculator_VOIDGetNumberAfter(u8 *Copy_U8ExpressionArray , s32 *Copy_S32NumbersArray,u8 Copy_U8Index)
{
	u8 LOC_U8NumberOfnumbers=0;
	u32 LOC_U32Accumlator = 0;
	/*
	 * Loop to accumulate the number after the operator.
	 */
	while(1)
	{
		if(Copy_U8ExpressionArray[Copy_U8Index+1] == '*' || Copy_U8ExpressionArray[Copy_U8Index+1] == '+' || Copy_U8ExpressionArray[Copy_U8Index+1] == '-' || Copy_U8ExpressionArray[Copy_U8Index+1] == '/' || Copy_U8ExpressionArray[Copy_U8Index+1] == '=' || Copy_U8ExpressionArray[Copy_U8Index+1] == '!' )
		{
			break;
		}
		Copy_U8Index++;
		LOC_U8NumberOfnumbers++;
	}
	/*
	 * Adjust the index back to where the number starts.
	 */
	Copy_U8Index=Copy_U8Index-LOC_U8NumberOfnumbers;
	/*
	 * Loop to store the number after the operator in the numbers array.
	 */
	while (LOC_U8NumberOfnumbers)
	{
		LOC_U32Accumlator=LOC_U32Accumlator+((Copy_U8ExpressionArray[Copy_U8Index+1]-48)*Calculator_U32GetPower(10,LOC_U8NumberOfnumbers-1));
		LOC_U8NumberOfnumbers--;
		Copy_U8Index++;
	}
	Copy_S32NumbersArray[1] = LOC_U32Accumlator;
}

/************************************************************************************
 * Function Name: Calculator_VOIDOperationCalculation
 * Description: Executes a single mathematical operation from the input expression,
 *              updates the expression with the result, and adjusts indices accordingly.
 * Parameters:
 *      - Copy_U8OrderArray: Pointer to the array containing the indices of operations
 *                           in the expression based on their precedence.
 *      - Copy_U32NumbersArray: Pointer to an array that stores the operands for the
 *                              current operation.
 *      - Copy_U8ExpressionArray: Pointer to the input expression array.
 * Return:
 *      - u8: Length of the resulting number after the operation.
 ************************************************************************************/
u8 Calculator_VOIDOperationCalculation(u8 *Copy_U8OrderArray, s32 *Copy_U32NumbersArray, u8 *Copy_U8ExpressionArray)
{
    s32 LOC_S32Result = 0; /* Variable to store the result of the operation */
    u8 LOC_U8Length1 = 0, LOC_U8Length2 = 0, LOC_U8ResultLength = 0, LOC_U8StartIndex, LOC_U8EndIndex;
    s32 LOC_S32UsedNum1, LOC_S32UsedNum2;

    /* Retrieve the number before the operator in the expression */
    Calculator_VOIDGetNumberBefore(Copy_U8ExpressionArray, Copy_U32NumbersArray, Copy_U8OrderArray[0]);

    /* Retrieve the number after the operator in the expression */
    Calculator_VOIDGetNumberAfter(Copy_U8ExpressionArray, Copy_U32NumbersArray, Copy_U8OrderArray[0]);

    LOC_S32UsedNum1 = Copy_U32NumbersArray[0]; /* First operand */
    LOC_S32UsedNum2 = Copy_U32NumbersArray[1]; /* Second operand */

    /* Calculate the length of the first operand, considering its sign */
    if (LOC_S32UsedNum1 < 0)
    {
        LOC_S32UsedNum1 = (~LOC_S32UsedNum1) + 1;
        LOC_U8Length1++;
    }
    if (LOC_S32UsedNum2 < 0)
    {
        LOC_S32UsedNum2 = (~LOC_S32UsedNum2) + 1;
        LOC_U8Length2++;
    }

    /* Handle cases where operands are zero */
    if (LOC_S32UsedNum1 == 0)
    {
        LOC_U8Length1++;
    }
    if (LOC_S32UsedNum2 == 0)
    {
        LOC_U8Length2++;
    }

    /* Calculate the length of each operand */
    while (LOC_S32UsedNum1)
    {
        LOC_S32UsedNum1 = LOC_S32UsedNum1 / 10;
        LOC_U8Length1++;
    }
    while (LOC_S32UsedNum2)
    {
        LOC_S32UsedNum2 = LOC_S32UsedNum2 / 10;
        LOC_U8Length2++;
    }

    /* Determine the start and end indices for the operation in the expression */
    LOC_U8StartIndex = Copy_U8OrderArray[0] - LOC_U8Length1;
    LOC_U8EndIndex = Copy_U8OrderArray[0] + LOC_U8Length2;

    /* Perform the mathematical operation based on the operator */
    switch (Copy_U8ExpressionArray[Copy_U8OrderArray[0]])
    {
    case '*': LOC_S32Result = LOC_S32Result + (Copy_U32NumbersArray[0] * Copy_U32NumbersArray[1]); break;
    case '+': LOC_S32Result = LOC_S32Result + (Copy_U32NumbersArray[0] + Copy_U32NumbersArray[1]); break;
    case '-': LOC_S32Result = LOC_S32Result + (Copy_U32NumbersArray[0] - Copy_U32NumbersArray[1]); break;
    case '/': LOC_S32Result = LOC_S32Result + (Copy_U32NumbersArray[0] / Copy_U32NumbersArray[1]); break;
    default: break;
    }

    s32 LOC_S32UsedResult = LOC_S32Result; /* Store the result for further processing */
    s32 LOC_S32Reversed = 1, LOC_S32SentCharacter;

    /* Handle the result if it is zero */
    if (0 == LOC_S32UsedResult)
    {
        Copy_U8ExpressionArray[LOC_U8StartIndex] = 48; /* Replace with '0' */

        /* Adjust the indices to remove extra characters */
        while (Copy_U8ExpressionArray[LOC_U8EndIndex])
        {
            for (u8 LOC_U8Iterator = LOC_U8EndIndex + 1; LOC_U8Iterator > LOC_U8StartIndex + LOC_U8ResultLength + 1; LOC_U8Iterator--)
            {
                Copy_U8ExpressionArray[LOC_U8Iterator - 1] = Copy_U8ExpressionArray[LOC_U8Iterator];
            }
            LOC_U8EndIndex++;
            LOC_U8StartIndex++;
            LOC_U8ResultLength++;
        }
    }

    /* Handle the result if it is positive */
    else if (LOC_S32UsedResult > 0)
    {
        /* Reverse the digits of the result */
        while (LOC_S32UsedResult > 0)
        {
            LOC_S32Reversed = (LOC_S32Reversed * 10) + (LOC_S32UsedResult % 10);
            LOC_S32UsedResult = LOC_S32UsedResult / 10;
        }

        /* Store the digits of the result back into the expression array */
        u8 LOC_U8Iterator2 = 0;
        while (LOC_S32Reversed > 1)
        {
            LOC_S32SentCharacter = LOC_S32Reversed % 10;
            Copy_U8ExpressionArray[LOC_U8StartIndex + LOC_U8Iterator2] = LOC_S32SentCharacter + 48;
            LOC_S32Reversed = LOC_S32Reversed / 10;
            LOC_U8Iterator2++;
        }

        /* Calculate the length of the result */
        while (LOC_S32Result)
        {
            LOC_S32Result = LOC_S32Result / 10;
            LOC_U8ResultLength++;
        }

        /* Adjust the indices to remove extra characters */
        while (Copy_U8ExpressionArray[LOC_U8EndIndex])
        {
            for (u8 LOC_U8Iterator = LOC_U8EndIndex + 1; LOC_U8Iterator > LOC_U8StartIndex + LOC_U8ResultLength; LOC_U8Iterator--)
            {
                Copy_U8ExpressionArray[LOC_U8Iterator - 1] = Copy_U8ExpressionArray[LOC_U8Iterator];
            }
            LOC_U8EndIndex++;
            LOC_U8StartIndex++;
        }
    }

    /* Handle the result if it is negative */
    else
    {
        LOC_S32UsedResult = (~LOC_S32UsedResult) + 1; /* Convert to positive */
        Copy_U8ExpressionArray[LOC_U8StartIndex] = '-'; /* Add the negative sign */
        LOC_U8ResultLength++;

        /* Reverse the digits of the result */
        while (LOC_S32UsedResult > 0)
        {
            LOC_S32Reversed = (LOC_S32Reversed * 10) + (LOC_S32UsedResult % 10);
            LOC_S32UsedResult = LOC_S32UsedResult / 10;
        }

        /* Store the digits of the result back into the expression array */
        u8 LOC_U8Iterator2 = 0;
        while (LOC_S32Reversed > 1)
        {
            LOC_S32SentCharacter = LOC_S32Reversed % 10;
            Copy_U8ExpressionArray[LOC_U8StartIndex + 1 + LOC_U8Iterator2] = LOC_S32SentCharacter + 48;
            LOC_S32Reversed = LOC_S32Reversed / 10;
            LOC_U8Iterator2++;
        }

        /* Calculate the length of the result */
        LOC_S32Result = (~LOC_S32Result) + 1;
        while (LOC_S32Result)
        {
            LOC_S32Result = LOC_S32Result / 10;
            LOC_U8ResultLength++;
        }

        /* Adjust the indices to remove extra characters */
        while (Copy_U8ExpressionArray[LOC_U8EndIndex])
        {
            for (u8 LOC_U8Iterator = LOC_U8EndIndex + 1; LOC_U8Iterator > LOC_U8StartIndex + LOC_U8ResultLength; LOC_U8Iterator--)
            {
                Copy_U8ExpressionArray[LOC_U8Iterator - 1] = Copy_U8ExpressionArray[LOC_U8Iterator];
            }
            LOC_U8EndIndex++;
            LOC_U8StartIndex++;
        }
    }

    return LOC_U8ResultLength; /* Return the length of the result */
}



/************************************************************************************
 * Function Name: Calculator_VOIDCalculation
 * Description: Evaluates the entire mathematical expression by parsing operators and
 *              operands, performing calculations, and displaying the result on an LCD.
 * Parameters:
 *      - Copy_U8ExpressionArray: Pointer to the input expression array.
 * Return:
 *      - u8: Final counter value after the calculations are completed.
 ************************************************************************************/
u8 Calculator_VOIDCalculation(u8 *Copy_U8ExpressionArray)
{
	u8 LOC_U8State = 0, LOC_U8RetCounterValue = 0;

	/* Clear the LCD display */
	HLCD_VOIDClearDisplay();

	/* Check for any syntax or mathematical errors in the expression */
	LOC_U8State = Calculator_U8ErrorState(Copy_U8ExpressionArray);

	/* Display error message if syntax error */
	if (1 == LOC_U8State)
	{
		HLCD_VOIDSendString("SYNTAX ERROR!");
	}
	/* Display error message if mathematical error (e.g., division by zero) */
	else if (2 == LOC_U8State)
	{
		HLCD_VOIDSendString("MATH ERROR!");
	}
	/* No errors, proceed with calculations */
	else if (0 == LOC_U8State)
	{
		u8 LOC_U8OperationsOrder[20];  /* Array to store the order of operations */
		s32 LOC_S32NumbersArray[2];    /* Array to store operands for the current operation */
		u8 LOC_U8NumberofOperations = Calculator_U8OperationsOrder(Copy_U8ExpressionArray, LOC_U8OperationsOrder);  /* Get the number of operations to perform */

		/* Loop through and perform each operation */
		while (LOC_U8NumberofOperations > 0)
		{
			/* Perform the current operation */
			LOC_U8RetCounterValue = Calculator_VOIDOperationCalculation(LOC_U8OperationsOrder, LOC_S32NumbersArray, Copy_U8ExpressionArray);

			/* Recalculate the order of operations after each calculation */
			LOC_U8NumberofOperations = Calculator_U8OperationsOrder(Copy_U8ExpressionArray, LOC_U8OperationsOrder);
		}

		u8 LOC_U8Iterator = 1;

		/* Display the result on the LCD screen until '=' is encountered */
		while (Copy_U8ExpressionArray[LOC_U8Iterator] != '=')
		{
			HLCD_VOIDSendCharacter(Copy_U8ExpressionArray[LOC_U8Iterator]);
			LOC_U8Iterator++;
		}
	}

	return LOC_U8RetCounterValue;  /* Return the counter value after calculation */
}

