

/****************************************************************/
/*   Author             :    Kareem Mohamed  				    */
/*	 Date 				:    7 SEPTEMBER 2020					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:     This is the header file of        */
/*                                     the GPIO                 */
/*                                  Driver for ATmega32         */
/****************************************************************/
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/* Casting the Register addresses to volatile u8 *const as ...*/
#define PORTA_REG    ((volatile u8 *const)(0x3B))
#define DDRA_REG     ((volatile u8 *const)(0x3A))
#define PINA_REG     ((volatile u8 *const)(0x39))

#define PORTB_REG    ((volatile u8 *const)(0x38))
#define DDRB_REG     ((volatile u8 *const)(0x37))
#define PINB_REG     ((volatile u8 *const)(0x36))

#define PORTC_REG    ((volatile u8 *const)(0x35))
#define DDRC_REG     ((volatile u8 *const)(0x34))
#define PINC_REG     ((volatile u8 *const)(0x33))

#define PORTD_REG    ((volatile u8 *const)(0x32))
#define DDRD_REG     ((volatile u8 *const)(0x31))
#define PIND_REG     ((volatile u8 *const)(0x30))



#endif /* DIO_PRIVATE_H_ */
