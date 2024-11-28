/******************************************************************************
 *
 * Module: MDIO (MCAL Digital I/O)
 *
 * File Name: MDIO_Program.c
 *
 * Description: Source file for the MDIO module functions
 *
 * Author: Omar Khedr
 *
 ******************************************************************************/

#include "MDIO_Interface.h"

/************************************************************************************
 * Function Name: MDIO_VOIDSetPinDirection
 * Description: Sets the direction of a specific pin in a specific port
 * Parameters:
 *      - Copy_U8Port: The port number (0 to 3)
 *      - Copy_U8Pin: The pin number (0 to 7)
 *      - Copy_U8Direction: The direction (1 for output, 0 for input)
 * Return: None
 ************************************************************************************/
void MDIO_VOIDSetPinDirection(u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Direction)
{
	/* Check if the desired direction is output (1) */
	if (1 == Copy_U8Direction)
	{
		/* Use the switch statement to handle different ports */
		switch (Copy_U8Port)
		{
		case 0:
			/* Set the corresponding bit in DDRA register to configure as output */
			SET_BIT(DDRA_REG, Copy_U8Pin);
			break;
		case 1:
			/* Set the corresponding bit in DDRB register to configure as output */
			SET_BIT(DDRB_REG, Copy_U8Pin);
			break;
		case 2:
			/* Set the corresponding bit in DDRC register to configure as output */
			SET_BIT(DDRC_REG, Copy_U8Pin);
			break;
		case 3:
			/* Set the corresponding bit in DDRD register to configure as output */
			SET_BIT(DDRD_REG, Copy_U8Pin);
			break;
		default:
			/* Invalid port, do nothing */
			break;
		}
	}
	/* Check if the desired direction is input (0) */
	else if (0 == Copy_U8Direction)
	{
		/* Use the switch statement to handle different ports */
		switch (Copy_U8Port)
		{
		case 0:
			/* Clear the corresponding bit in DDRA register to configure as input */
			CLR_BIT(DDRA_REG, Copy_U8Pin);
			break;
		case 1:
			/* Clear the corresponding bit in DDRB register to configure as input */
			CLR_BIT(DDRB_REG, Copy_U8Pin);
			break;
		case 2:
			/* Clear the corresponding bit in DDRC register to configure as input */
			CLR_BIT(DDRC_REG, Copy_U8Pin);
			break;
		case 3:
			/* Clear the corresponding bit in DDRD register to configure as input */
			CLR_BIT(DDRD_REG, Copy_U8Pin);
			break;
		default:
			/* Invalid port, do nothing */
			break;
		}
	}
	else
	{
		/* Invalid direction value, do nothing */
	}
}

/************************************************************************************
 * Function Name: MDIO_U8GetPinValue
 * Description: Reads the value of a specific pin in a specific port
 * Parameters:
 *      - Copy_U8Port: The port number (0 to 3)
 *      - Copy_U8Pin: The pin number (0 to 7)
 * Return: The value of the pin (0 or 1)
 ************************************************************************************/
u8 MDIO_U8GetPinValue(u8 Copy_U8Port, u8 Copy_U8Pin)
{
	u8 LOC_U8RetValue;  /* Variable to store the pin value */

	/* Use the switch statement to handle different ports */
	switch (Copy_U8Port)
	{
	case 0:
		/* Get the value of the specified pin from PINA register */
		LOC_U8RetValue = GET_BIT(PINA_REG, Copy_U8Pin);
		break;
	case 1:
		/* Get the value of the specified pin from PINB register */
		LOC_U8RetValue = GET_BIT(PINB_REG, Copy_U8Pin);
		break;
	case 2:
		/* Get the value of the specified pin from PINC register */
		LOC_U8RetValue = GET_BIT(PINC_REG, Copy_U8Pin);
		break;
	case 3:
		/* Get the value of the specified pin from PIND register */
		LOC_U8RetValue = GET_BIT(PIND_REG, Copy_U8Pin);
		break;
	default:
		/* Invalid port, do nothing */
		break;
	}

	/* Return the value of the pin (0 or 1) */
	return LOC_U8RetValue;
}

/************************************************************************************
 * Function Name: MDIO_VOIDSetPortValue
 * Description: Sets the value of all pins in a specific port
 * Parameters:
 *      - Copy_U8Port: The port number (0 to 3)
 *      - Copy_U8PortValue: The value to set (8-bit value)
 * Return: None
 ************************************************************************************/
void MDIO_VOIDSetPortValue(u8 Copy_U8Port, u8 Copy_U8PortValue)
{
	/* Use the switch statement to handle different ports */
	switch (Copy_U8Port)
	{
	case 0:
		/* Assign the value to the PORTA register */
		PORTA_REG = Copy_U8PortValue;
		break;
	case 1:
		/* Assign the value to the PORTB register */
		PORTB_REG = Copy_U8PortValue;
		break;
	case 2:
		/* Assign the value to the PORTC register */
		PORTC_REG = Copy_U8PortValue;
		break;
	case 3:
		/* Assign the value to the PORTD register */
		PORTD_REG = Copy_U8PortValue;
		break;
	default:
		/* Invalid port, do nothing */
		break;
	}
}

/************************************************************************************
 * Function Name: MDIO_VOIDSetPinValue
 * Description: Sets the value of a specific pin in a specific port
 * Parameters:
 *      - Copy_U8Port: The port number (0 to 3)
 *      - Copy_U8Pin: The pin number (0 to 7)
 *      - Copy_U8Value: The value to set (1 for HIGH, 0 for LOW)
 * Return: None
 ************************************************************************************/
void MDIO_VOIDSetPinValue(u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Value)
{
	/* Check if the desired value is HIGH (1) */
	if (1 == Copy_U8Value)
	{
		/* Use the switch statement to handle different ports */
		switch (Copy_U8Port)
		{
		case 0:
			/* Set the corresponding bit in PORTA register to HIGH */
			SET_BIT(PORTA_REG, Copy_U8Pin);
			break;
		case 1:
			/* Set the corresponding bit in PORTB register to HIGH */
			SET_BIT(PORTB_REG, Copy_U8Pin);
			break;
		case 2:
			/* Set the corresponding bit in PORTC register to HIGH */
			SET_BIT(PORTC_REG, Copy_U8Pin);
			break;
		case 3:
			/* Set the corresponding bit in PORTD register to HIGH */
			SET_BIT(PORTD_REG, Copy_U8Pin);
			break;
		default:
			/* Invalid port, do nothing */
			break;
		}
	}
	/* Check if the desired value is LOW (0) */
	else if (0 == Copy_U8Value)
	{
		/* Use the switch statement to handle different ports */
		switch (Copy_U8Port)
		{
		case 0:
			/* Clear the corresponding bit in PORTA register to LOW */
			CLR_BIT(PORTA_REG, Copy_U8Pin);
			break;
		case 1:
			/* Clear the corresponding bit in PORTB register to LOW */
			CLR_BIT(PORTB_REG, Copy_U8Pin);
			break;
		case 2:
			/* Clear the corresponding bit in PORTC register to LOW */
			CLR_BIT(PORTC_REG, Copy_U8Pin);
			break;
		case 3:
			/* Clear the corresponding bit in PORTD register to LOW */
			CLR_BIT(PORTD_REG, Copy_U8Pin);
			break;
		default:
			/* Invalid port, do nothing */
			break;
		}
	}
	else
	{
		/* Invalid value, do nothing */
	}
}

/************************************************************************************
 * Function Name: MDIO_VOIDTogglePinValue
 * Description: Toggles the value of a specific pin in a specific port
 * Parameters:
 *      - Copy_U8Port: The port number (0 to 3)
 *      - Copy_U8Pin: The pin number (0 to 7)
 * Return: None
 ************************************************************************************/
void MDIO_VOIDTogglePinValue(u8 Copy_U8Port, u8 Copy_U8Pin)
{
	/* Use the switch statement to handle different ports */
	switch (Copy_U8Port)
	{
	case 0:
		/* Toggle the value of the pin in PORTA register */
		TOGGLE_BIT(PORTA_REG, Copy_U8Pin);
		break;
	case 1:
		/* Toggle the value of the pin in PORTB register */
		TOGGLE_BIT(PORTB_REG, Copy_U8Pin);
		break;
	case 2:
		/* Toggle the value of the pin in PORTC register */
		TOGGLE_BIT(PORTC_REG, Copy_U8Pin);
		break;
	case 3:
		/* Toggle the value of the pin in PORTD register */
		TOGGLE_BIT(PORTD_REG, Copy_U8Pin);
		break;
	default:
		/* Invalid port, do nothing */
		break;
	}
}


/************************************************************************************
 * Function Name: MDIO_VOIDSetPortDirection
 * Description: Sets the direction of all pins in a specific port
 * Parameters:
 *      - Copy_U8Port: The port number (0 to 3)
 *      - Copy_U8Direction: The direction to set (8-bit value, each bit represents a pin)
 * Return: None
 ************************************************************************************/
void MDIO_VOIDSetPortDirection(u8 Copy_U8Port, u8 Copy_U8Direction)
{
	/* Use the switch statement to handle different ports */
	switch (Copy_U8Port)
	{
	case 0:
		/* Set the direction for all pins in PORTA register */
		DDRA_REG = Copy_U8Direction;
		break;
	case 1:
		/* Set the direction for all pins in PORTB register */
		DDRB_REG = Copy_U8Direction;
		break;
	case 2:
		/* Set the direction for all pins in PORTC register */
		DDRC_REG = Copy_U8Direction;
		break;
	case 3:
		/* Set the direction for all pins in PORTD register */
		DDRD_REG = Copy_U8Direction;
		break;
	default:
		/* Invalid port, do nothing */
		break;
	}
}

/************************************************************************************
 * Function Name: MDIO_U8GetPortValue
 * Description: Reads the value of all pins in a specific port
 * Parameters:
 *      - Copy_U8Port: The port number (0 to 3)
 * Return: The value of the port (8-bit value where each bit represents a pin)
 ************************************************************************************/
u8 MDIO_U8GetPortValue(u8 Copy_U8Port)
{
	u8 LOC_U8RetValue;  /* Variable to store the port value */

	/* Use the switch statement to handle different ports */
	switch (Copy_U8Port)
	{
	case 0:
		/* Get the value of all pins from PINA register */
		LOC_U8RetValue = PINA_REG;
		break;
	case 1:
		/* Get the value of all pins from PINB register */
		LOC_U8RetValue = PINB_REG;
		break;
	case 2:
		/* Get the value of all pins from PINC register */
		LOC_U8RetValue = PINC_REG;
		break;
	case 3:
		/* Get the value of all pins from PIND register */
		LOC_U8RetValue = PIND_REG;
		break;
	default:
		/* Invalid port, do nothing */
		break;
	}

	/* Return the value of the port (8-bit value) */
	return LOC_U8RetValue;
}

