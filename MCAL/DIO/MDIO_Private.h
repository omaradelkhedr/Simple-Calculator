/******************************************************************************
 *
 * Module: MDIO (MCAL Digital I/O)
 *
 * File Name: MDIO_Private.h
 *
 * Description: Private header file for the MDIO module
 *
 * Author: Omar Khedr
 *
 ******************************************************************************/

#ifndef _MDIO_PRIVATE_H_
#define _MDIO_PRIVATE_H_

/* Data Direction Register for Port A */
#define DDRA_REG *((u8*)0x3A)

/* Data Direction Register for Port B */
#define DDRB_REG *((u8*)0x37)

/* Data Direction Register for Port C */
#define DDRC_REG *((u8*)0x34)

/* Data Direction Register for Port D */
#define DDRD_REG *((u8*)0x31)

/* Port Output Register for Port A */
#define PORTA_REG *((u8*)0x3B)

/* Port Output Register for Port B */
#define PORTB_REG *((u8*)0x38)

/* Port Output Register for Port C */
#define PORTC_REG *((u8*)0x35)

/* Port Output Register for Port D */
#define PORTD_REG *((u8*)0x32)

/* Port Input Register for Port A (volatile) */
#define PINA_REG *((volatile u8*)0x39)

/* Port Input Register for Port B (volatile) */
#define PINB_REG *((volatile u8*)0x36)

/* Port Input Register for Port C (volatile) */
#define PINC_REG *((volatile u8*)0x33)

/* Port Input Register for Port D (volatile) */
#define PIND_REG *((volatile u8*)0x30)

#endif /* _MDIO_PRIVATE_H_ */
