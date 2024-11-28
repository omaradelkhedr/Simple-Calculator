/******************************************************************************
 *
 * Module: Calculator
 *
 * File Name: Calculator_Interface.h
 *
 * Description: Header file for the calculator module, containing function
 *              declarations for performing calculations and evaluating
 *              mathematical expressions.
 *
 * Author: Omar Khedr , Ali Ashraf
 *
 ******************************************************************************/

#ifndef CALCULATOR_INTERFACE_H_
#define CALCULATOR_INTERFACE_H_

/* Include Standard Types Library */
#include "../LIB/STD_TYPES.h"

/* Include LCD and Keypad HAL Layers */
#include "../HAL/LCD/HLCD_Interface.h"
#include "../HAL/KeyPad/HKPD_Interface.h"

/************************************************************************************
 * Function Name: Calculator_U8ErrorState
 * Description: Validates the input expression for errors, such as incorrect
 *              operators or missing elements.
 * Parameters:
 *      - Copy_U8ExpressionArray: Pointer to the input expression array.
 * Return:
 *      - u8: Error state (0: No error, 1: Error).
 ************************************************************************************/
u8 Calculator_U8ErrorState(u8 *Copy_U8ExpressionArray);

/************************************************************************************
 * Function Name: Calculator_U8OperationsOrder
 * Description: Determines the precedence order of operations in the given expression.
 * Parameters:
 *      - Copy_U8ExpressionArray: Pointer to the input expression array.
 *      - Copy_U8OrderArray: Pointer to the array that stores the order of operations.
 * Return:
 *      - u8: Number of operations found in the expression.
 ************************************************************************************/
u8 Calculator_U8OperationsOrder(u8 *Copy_U8ExpressionArray, u8 *Copy_U8OrderArray);

/************************************************************************************
 * Function Name: Calculator_U32GetPower
 * Description: Calculates the power of a number (base^exponent).
 * Parameters:
 *      - Copy_U32Number: The base number.
 *      - Copy_U8Power: The exponent.
 * Return:
 *      - u32: The result of the power calculation.
 ************************************************************************************/
u32 Calculator_U32GetPower(u32 Copy_U32Number, u8 Copy_U8Power);

/************************************************************************************
 * Function Name: Calculator_VOIDGetNumberBefore
 * Description: Extracts the number located before a specified index in the expression.
 * Parameters:
 *      - Copy_U8ExpressionArray: Pointer to the input expression array.
 *      - Copy_S32NumbersArray: Pointer to the array storing extracted numbers.
 *      - Copy_U8Index: The index of the operator in the expression.
 * Return: None
 ************************************************************************************/
void Calculator_VOIDGetNumberBefore(u8 *Copy_U8ExpressionArray, s32 *Copy_S32NumbersArray, u8 Copy_U8Index);

/************************************************************************************
 * Function Name: Calculator_VOIDGetNumberAfter
 * Description: Extracts the number located after a specified index in the expression.
 * Parameters:
 *      - Copy_U8ExpressionArray: Pointer to the input expression array.
 *      - Copy_S32NumbersArray: Pointer to the array storing extracted numbers.
 *      - Copy_U8Index: The index of the operator in the expression.
 * Return: None
 ************************************************************************************/
void Calculator_VOIDGetNumberAfter(u8 *Copy_U8ExpressionArray, s32 *Copy_S32NumbersArray, u8 Copy_U8Index);

/************************************************************************************
 * Function Name: Calculator_VOIDOperationCalculation
 * Description: Performs a calculation for a single operation based on its precedence.
 * Parameters:
 *      - Copy_U8OrderArray: Pointer to the array storing the order of operations.
 *      - Copy_U32NumbersArray: Pointer to the array of numbers involved in the calculation.
 *      - Copy_U8ExpressionArray: Pointer to the input expression array.
 * Return:
 *      - u8: Operation status (0: Success, 1: Error).
 ************************************************************************************/
u8 Calculator_VOIDOperationCalculation(u8 *Copy_U8OrderArray, s32 *Copy_U32NumbersArray, u8 *Copy_U8ExpressionArray);

/************************************************************************************
 * Function Name: Calculator_VOIDCalculation
 * Description: Evaluates the entire expression and calculates the final result.
 * Parameters:
 *      - Copy_U8ExpressionArray: Pointer to the input expression array.
 * Return:
 *      - u8: Calculation status (0: Success, 1: Error).
 ************************************************************************************/
u8 Calculator_VOIDCalculation(u8 *Copy_U8ExpressionArray);

#endif /* CALCULATOR_INTERFACE_H_ */
