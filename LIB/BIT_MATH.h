/******************************************************************************
 *
 * Module: Bit-Wise Math
 *
 * File Name: BIT_MATH.h
 *
 * Description: Header file for bit-wise operation functions
 *
 * Author: Omar Khedr
 *
 ******************************************************************************/
#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_ 

/************************************************************************************
 * Macro Name: SET_BIT
 * Description: Sets a specific bit in a variable to 1
 * Parameters:
 *      - var: The variable in which the bit is to be set
 *      - bit: The bit position to set (0 to 31 for a 32-bit variable)
 * Return: None
 ************************************************************************************/
#define SET_BIT(var, bit) var = var | (1 << bit)

/************************************************************************************
 * Macro Name: CLR_BIT
 * Description: Clears (sets to 0) a specific bit in a variable
 * Parameters:
 *      - var: The variable in which the bit is to be cleared
 *      - bit: The bit position to clear (0 to 31 for a 32-bit variable)
 * Return: None
 ************************************************************************************/
#define CLR_BIT(var, bit) var = var & (~(1 << bit))

/************************************************************************************
 * Macro Name: TOGGLE_BIT
 * Description: Toggles (flips) the value of a specific bit in a variable
 * Parameters:
 *      - var: The variable in which the bit is to be toggled
 *      - bit: The bit position to toggle (0 to 31 for a 32-bit variable)
 * Return: None
 ************************************************************************************/
#define TOGGLE_BIT(var, bit) var = var ^ (1 << bit)

/************************************************************************************
 * Macro Name: GET_BIT
 * Description: Returns the value of a specific bit in a variable (either 0 or 1)
 * Parameters:
 *      - var: The variable from which the bit value is to be fetched
 *      - bit: The bit position to get (0 to 31 for a 32-bit variable)
 * Return: The value of the bit (either 0 or 1)
 ************************************************************************************/
#define GET_BIT(var, bit) ((var >> bit) & 1)

#endif
