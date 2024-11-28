/******************************************************************************
 *
 * Module: HLCD (HAL LCD Configuration)
 *
 * File Name: HLCD_Cfg.h
 *
 * Description: Configuration file for the HLCD module to set up ports and pins
 *              for LCD interfacing and customization options.
 *
 * Author: Omar Khedr
 *
 *
 ******************************************************************************/

#ifndef _HLCD_CFG_H_
#define _HLCD_CFG_H_

/************************************************************************************
 * Description: Configure the data port (D0-D7) for LCD connection.
 * Default: Port C is used for data connections.
 * Options:
 *      - PORTA: 0
 *      - PORTB: 1
 *      - PORTC: 2
 *      - PORTD: 3
 ************************************************************************************/
#define DATA_PORT 2

/************************************************************************************
 * Description: Configure the control port (RS, RW, EN) for LCD control signals.
 * Default: Port B is used for control connections.
 * Options:
 *      - PORTA: 0
 *      - PORTB: 1
 *      - PORTC: 2
 *      - PORTD: 3
 ************************************************************************************/
#define CONTROL_PORT 1

/************************************************************************************
 * Description: Configure the control pins for RS, RW, and EN signals.
 * Default:
 *      - RS_PIN is connected to Pin 0 of the control port.
 *      - RW_PIN is connected to Pin 1 of the control port.
 *      - EN_PIN is connected to Pin 2 of the control port.
 * Options: Any pin from the chosen control port (0 to 7).
 ************************************************************************************/
#define RS_PIN 0
#define RW_PIN 1
#define EN_PIN 2

#endif
