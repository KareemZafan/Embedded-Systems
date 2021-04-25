/********************************************************************************************/
/*   Author             :    Kareem Mohamed  				                                */
/*	 Date 				:    7 SEPTEMBER 2020					                            */
/*	 Version 			:    1.0V 							 	                            */
/*	 Description 		:  Program to Implement GPIO driver for MCU                        	*/
/********************************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define PINS_ON_PORT             8
#define NO_OF_PORTS              4

#define DIO_PORTA                0
#define DIO_PORTB                1
#define DIO_PORTC                2
#define DIO_PORTD	             3

#define EXIT_FAILED              0
#define EXIT_SUCCEED             1

#define DIO_PIN_OUTPUT           1
#define DIO_PIN_INPUT            0

#define DIO_PIN_HIGH             1
#define DIO_PIN_LOW              0


#if ( 8 == PINS_ON_PORT )
#define PIN0          0
#define PIN1          1
#define PIN2          2
#define PIN3          3
#define PIN4          4
#define PIN5          5
#define PIN6          6
#define PIN7          7


#define DIO_DEFAULT_PORT_DIRECTION   0x00
#define DIO_DEFAULT_PORT_VALUE       0x00

#define DIO_PORT_OUTPUT          0xFF
#define DIO_PORT_INPUT           0x00

#endif

#if ( 16 == PINS_ON_PORT )
#define PIN0          0
#define PIN1          1
#define PIN2          2
#define PIN3          3
#define PIN4          4
#define PIN5          5
#define PIN6          6
#define PIN7          7
#define PIN8          8
#define PIN9          9
#define PIN10         10
#define PIN11         11
#define PIN12         12
#define PIN13         13
#define PIN14         14
#define PIN15         15

#define DEFAULT_PORT_DIRECTION   0x0000
#define DEFAULT_PORT_VALUE       0x0000

#endif

#if ( 32 == PINS_ON_PORT )
#define PIN0          0
#define PIN1          1
#define PIN2          2
#define PIN3          3
#define PIN4          4
#define PIN5          5
#define PIN6          6
#define PIN7          7
#define PIN8          8
#define PIN9          9
#define PIN10         10
#define PIN11         11
#define PIN12         12
#define PIN13         13
#define PIN14         14
#define PIN15         15
#define PIN16         16
#define PIN17         17
#define PIN18         18
#define PIN19         19
#define PIN20         20
#define PIN21         21
#define PIN22         22
#define PIN23         23
#define PIN24         24
#define PIN25         25
#define PIN26         26
#define PIN27         27
#define PIN28         28
#define PIN29         29
#define PIN30         30
#define PIN31         31

#define DEFAULT_PORT_DIRECTION  0x00000000
#define DEFAULT_PORT_VALUE      0x00000000
#endif

/****************************************************************************************/
/*     Function    : u8 DIO_voidInit(void)                                              */
/*     Description : It initializes the DIO Drive                                       */
/*     Input       : Nothing                                                            */
/*     Output      : Status of the Driver                                               */
/****************************************************************************************/
extern u8 DIO_voidInit(void) ;
/****************************************************************************************/
/*     Function    :                                                                    */
/*     Description :                                                                    */
/*     Input       :                                                                    */
/*     Output      :                                                                    */
/****************************************************************************************/

extern u8 DIO_u8SetPortDirection(u8 Copy_portNumber, u8 Copy_portdirectionValue) ;
/****************************************************************************************/
/*     Function    :                                                                    */
/*     Description :                                                                    */
/*     Input       :                                                                    */
/*     Output      :                                                                    */
/*****************************************************************************************/

extern u8 DIO_u8GetPortDirection(u8 Copy_portNumber, u8 *Copy_portDirectionValue) ;

/****************************************************************************************/
/*     Function    :                                                                    */
/*     Description :                                                                    */
/*     Input       :                                                                    */
/*     Output      :                                                                    */
/****************************************************************************************/

extern u8 DIO_u8SetPortValue(u8 Copy_portNumber, u8 Copy_portValue) ;

/****************************************************************************************/
/*     Function    :                                                                    */
/*     Description :                                                                    */
/*     Input       :                                                                    */
/*     Output      :                                                                    */
/****************************************************************************************/
extern u8 DIO_u8GetPortValue(u8 Copy_portNumber, u8 *Copy_PortValue) ;

/****************************************************************************************/
/*     Function    :                                                                    */
/*     Description :                                                                    */
/*     Input       :                                                                    */
/*     Output      :                                                                    */
/****************************************************************************************/

extern u8 DIO_u8SetPintDirection(u8 Copy_portNumber, u8 Copy_pinNumber , u8 Copy_pinDirectionValue) ;
/****************************************************************************************/
/*     Function    :                                                                    */
/*     Description :                                                                    */
/*     Input       :                                                                    */
/*     Output      :                                                                    */
/****************************************************************************************/

extern u8 DIO_u8SetPinValue(u8 Copy_portNumber, u8 Copy_pintNumber  , u8 Copy_pinValue) ;
/****************************************************************************************/
/*     Function    :                                                                    */
/*     Description :                                                                    */
/*     Input       :                                                                    */
/*     Output      :                                                                    */
/****************************************************************************************/

extern u8 DIO_u8GetPinValue(u8 Copy_portNumber, u8 Copy_pintNumber , u8 *Copy_pinValue) ;


/****************************************************************************************/
/*     Function    :                                                                    */
/*     Description :                                                                    */
/*     Input       :                                                                    */
/*     Output      :                                                                    */
/****************************************************************************************/

extern u8 DIO_u8GetPinDirection(u8 Copy_portNumber, u8 Copy_pintNumber , u8 *Copy_pinDirectionValue) ;

/****************************************************************************************/
/*     Function    :                                                                    */
/*     Description :                                                                    */
/*     Input       :                                                                    */
/*     Output      :                                                                    */
/****************************************************************************************/

extern u8 DIO_u8TogglePinValue(u8 Copy_portNumber, u8 Copy_pinNumber) ;


#endif /* DIO_INTERFACE_H_ */
