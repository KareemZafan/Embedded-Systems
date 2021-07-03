/********************************************************************************************/
/*   Author             :    Kareem Mohamed  				                                */
/*	 Date 				:    7 SEPTEMBER 2020					                            */
/*	 Version 			:    1.0V 							 	                            */
/*	 Description 		:  Program to Implement GPIO driver for ATmega32 MCU               	*/
/********************************************************************************************/

#include "..\APP\STD_TYPES.h"
#include "..\APP\BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"

/* Limit the scope of these arrays */
static volatile u8 * const DIO_dirs[]  = { DDRA_REG,  DDRB_REG,  DDRC_REG,  DDRD_REG };
static volatile u8 * const DIO_pins[]  = { PINA_REG,  PINB_REG,  PINC_REG,  PIND_REG };
static volatile u8 * const DIO_ports[] = { PORTA_REG, PORTB_REG, PORTC_REG, PORTD_REG };

/****************************************************************************************/
/*     Function    : u8 DIO_voidInit(void)                                              */
/*     Description : It initializes the DIO Drive                                       */
/*     Input       : Nothing                                                            */
/*     Output      : Status of the that API                                             */
/****************************************************************************************/

u8 DIO_voidInit(void) {

	u8 Init_Status = EXIT_FAILED;
	/* Initialize all DDrx registers to be Input as  default initialization */
	*(DIO_dirs[DIO_PORTA]) = DEFAULT_PORT_DIRECTION;
	*(DIO_dirs[DIO_PORTB]) = DEFAULT_PORT_DIRECTION;
	*(DIO_dirs[DIO_PORTC]) = DEFAULT_PORT_DIRECTION;
	*(DIO_dirs[DIO_PORTD]) = DEFAULT_PORT_DIRECTION;

	return Init_Status;
}

/********************************************************************************************************/
/*     Function    :   DIO_u8SetPortDirection(u8 Copy_portNumber, u8 Copy_portdirectionValue)           */
/*     Description :                                                                                    */
/*     Input       :                                                                                    */
/*     Output      :                                                                                    */
/********************************************************************************************************/

u8 DIO_u8SetPortDirection(u8 Copy_portNumber, u8 Copy_portDirectionMode) {
	u8 API_Status = EXIT_FAILED;
	if (Copy_portNumber >= DIO_PORTA && Copy_portNumber <= DIO_PORTD) {
		*(DIO_dirs[Copy_portNumber]) = Copy_portDirectionMode ;
	} else {
		API_Status = EXIT_FAILED;
	}
	return API_Status;
}
/****************************************************************************************/
/*     Function    :                                                                    */
/*     Description :                                                                    */
/*     Input       :                                                                    */
/*     Output      :                                                                    */
/*****************************************************************************************/
u8 DIO_u8SetPortValue(u8 Copy_portNumber, u8 Copy_portValue) {
	u8 API_Status = EXIT_FAILED;
	if (Copy_portNumber >= DIO_PORTA && Copy_portNumber <= DIO_PORTD) {
		*(DIO_ports[Copy_portNumber]) = Copy_portValue;
		API_Status = EXIT_SUCCEED;
	} else {
		API_Status = EXIT_FAILED;
	}

	return API_Status;
}

/****************************************************************************************/
/*     Function    :                                                                    */
/*     Description :                                                                    */
/*     Input       :                                                                    */
/*     Output      :                                                                    */
/****************************************************************************************/
u8 DIO_u8GetPortValue(u8 Copy_portNumber, u8 *Copy_PortValue) {
	u8 API_Status = EXIT_FAILED;
	if (Copy_portNumber >= DIO_PORTA && Copy_portNumber <= DIO_PORTD) {

		*Copy_PortValue = *(DIO_pins[Copy_portNumber]);
		API_Status = EXIT_SUCCEED;
	} else {
		API_Status = EXIT_FAILED;
	}
	return API_Status;
}

/****************************************************************************************/
/*     Function    :                                                                    */
/*     Description :                                                                    */
/*     Input       :                                                                    */
/*     Output      :                                                                    */
/*****************************************************************************************/

u8 DIO_u8GetPortDirection(u8 Copy_portNumber, u8 *Copy_portDirectionValue) {
	u8 API_Status = EXIT_FAILED;
	if (Copy_portNumber >= DIO_PORTA && Copy_portNumber <= DIO_PORTD) {
		*Copy_portDirectionValue = *(DIO_dirs[Copy_portNumber]);
		API_Status = EXIT_SUCCEED;
	} else {
		API_Status = EXIT_FAILED;
	}
	return API_Status;
}

/****************************************************************************************/
/*     Function    :                                                                    */
/*     Description :                                                                    */
/*     Input       :                                                                    */
/*     Output      :                                                                    */
/****************************************************************************************/

u8 DIO_u8SetPinDirection(u8 Copy_portNumber, u8 Copy_pinNumber, u8 Copy_pinDirectionMode) {
	u8 API_Status = EXIT_FAILED;
	if (Copy_portNumber >= DIO_PORTA && Copy_portNumber <= DIO_PORTD) {
		if (Copy_pinNumber >= PIN0 && Copy_pinNumber <= PIN7) {
			switch (Copy_pinDirectionMode) {
			case DIO_PIN_OUTPUT:
				CLEAR_BIT((*(DIO_dirs[Copy_portNumber])), Copy_pinNumber);
				API_Status = EXIT_SUCCEED;
				break;
			case DIO_PIN_INPUT:
				SET_BIT((*(DIO_dirs[Copy_portNumber])), Copy_pinNumber);
				API_Status = EXIT_SUCCEED;
				break;
			default:
				API_Status = EXIT_FAILED;
				break;
			}

		} else {
			API_Status = EXIT_FAILED;
		}
	} else {
		API_Status = EXIT_FAILED;
	}

	return API_Status;
}

/****************************************************************************************/
/*     Function    :                                                                    */
/*     Description :                                                                    */
/*     Input       :                                                                    */
/*     Output      :                                                                    */
/****************************************************************************************/

u8 DIO_u8SetPinValue(u8 Copy_portNumber, u8 Copy_pinNumber, u8 Copy_pinValue) {
	u8 API_Status = EXIT_FAILED;
	if (Copy_portNumber >= DIO_PORTA && Copy_portNumber <= DIO_PORTD) {
		if (Copy_pinNumber >= PIN0 && Copy_pinNumber <= PIN7) {
			switch (Copy_pinValue) {
			case DIO_PIN_LOW:
				CLEAR_BIT((*(DIO_ports[Copy_portNumber])), Copy_pinNumber);
				API_Status = EXIT_SUCCEED;
				break;
			case DIO_PIN_HIGH:
				SET_BIT((*(DIO_ports[Copy_portNumber])), Copy_pinNumber);
				API_Status = EXIT_SUCCEED;
				break;
			default: API_Status = EXIT_FAILED ;
				break;
			}

		} else {
			API_Status = EXIT_FAILED;
		}
	} else {
		API_Status = EXIT_FAILED;
	}

	return API_Status;
}
/****************************************************************************************/
/*     Function    :                                                                    */
/*     Description :                                                                    */
/*     Input       :                                                                    */
/*     Output      :                                                                    */
/****************************************************************************************/

u8 DIO_u8GetPinValue(u8 Copy_portNumber, u8 Copy_pinNumber)
{
	u8 LocalBitValue = 0xFF ;
	if (Copy_portNumber >= DIO_PORTA && Copy_portNumber <= DIO_PORTD){
		if (Copy_pinNumber >= PIN0 && Copy_pinNumber <= PIN7) {
           LocalBitValue = GET_BIT(*DIO_pins[Copy_portNumber],Copy_pinNumber) ;

	}else {

	}
} else {

}
	return LocalBitValue ;
}

/****************************************************************************************/
/*     Function    :                                                                    */
/*     Description :                                                                    */
/*     Input       :                                                                    */
/*     Output      :                                                                    */
/****************************************************************************************/
 u8 DIO_u8GetPinDirection(u8 Copy_portNumber , u8 Copy_pinNumber , u8 *Copy_pinDirectionValue)
 {
	   u8 API_Status = EXIT_FAILED ;
	   if (Copy_portNumber >= DIO_PORTA && Copy_portNumber <= DIO_PORTD){
	   		if (Copy_pinNumber >= PIN0 && Copy_pinNumber <= PIN7){
	   			*Copy_pinDirectionValue = GET_BIT((*(DIO_dirs[Copy_portNumber])),Copy_pinNumber) ;
	   			API_Status = EXIT_SUCCEED ;
	   		}
	   }
		return API_Status ;
 }

 /****************************************************************************************/
 /*     Function    :                                                                    */
 /*     Description :                                                                    */
 /*     Input       :                                                                    */
 /*     Output      :                                                                    */
 /****************************************************************************************/

 extern u8 DIO_u8TogglePinValue(u8 Copy_portNumber, u8 Copy_pinNumber) {
	u8 API_Status = EXIT_FAILED  ;
	if (Copy_portNumber >= DIO_PORTA && Copy_portNumber <= DIO_PORTD){
		   		if (Copy_pinNumber >= PIN0 && Copy_pinNumber <= PIN7){
		   			TOGGLE_BIT((*DIO_ports[Copy_pinNumber]),Copy_pinNumber) ;
		   			API_Status = EXIT_SUCCEED ;
		   		}else {
					 API_Status = EXIT_FAILED ;
				}
	}else {
		API_Status = EXIT_FAILED ;
	}
	 return API_Status ;

 }

