/******************************************************************
* @Title : LCD "Liquid Crystal Display"                           *
* @Filename : LCD.h                                               *
* @Author : Kareem Mohamed                                        *
* @Origin Date : 9/10/2020                                        *
* @Version : 1.0.0                                                *
* @Compiler : GCC AVR                                             *
* @Target : Atmega32                                              *
* @Notes : None                                                   *
/******************************************************************/
#ifndef LCD_H_
#define LCD_H_
/**
 *  6 variables which specify the LCD configuration struct
 */
 typedef  struct {

	u8 LCD_Data_Port_Reg ;    /**< Port which the LCD will connected */
	u8 LCD_Control_port_Reg ; /**< Port which the LCD will connected */
	u8 LCD_RS ;               /**< LCD Register Select pin */
	u8 LCD_RW ;               /**< LCD Read/Write pin */
	u8 LCD_E ;                /**< LCD Enable pin */
	u8 LCD_Mode ;             /**< LCD Mode which will be 4 or 8 pins mode  */
}LCD_Config_t ;


#define LCD_4Bit_Mode                                                      4
#define LCD_8Bit_Mode                                                      8

#define LCD_CLEAR                                                          0x01
#define LCD_RETURN_HOME                                                    0x02
#define LCD_SHIFT_CURSOR_LEFT                                              0x04
#define LCD_ENTRY_MODE_SET                                                 0x06 /* Entry Mode Set */
#define LCD_SHIFT_DISPLAY_LEFT                                             0x07
#define LCD_SHIFT_DISPLAY_RIGHT                                            0x05
#define LCD_DISPLAY_OFF_CURSOR_OFF                                         0x0A
#define LCD_DISPLAY_OFF_CURSOR_ON                                          0x0A
#define LCD_DISPLAY_ON_CURSOR_OFF                                          0x0C
#define LCD_DISPLAY_ON_CURSOR_ON                                           0x0E
#define LCD_DISPLAY_ON_CURSOR_BLINKING                                     0x0F
#define LCD_DISPLAY_OFF_CURSOR_OFF                                         0x0A
#define LCD_SHIFT_CURSOR_POS_LEFT                                          0x10
#define LCD_SHIFT_CURSOR_POS_RIGHT                                         0x14
#define LCD_SHIFT_ENTIRE_DISPLAY_LEFT                                      0x18
#define LCD_SHIFT_ENTIRE_DISPLAY_RIGHT                                     0x1C
#define LCD_FUN_SET_8BIT_2LINE                                             0x38
#define LCD_FUN_SET_4BIT_2LINE                                             0x28
#define LCD_SET_CGRAM_ADDRESS                                              0x40
#define LCD_SET_DDRAM_ADDRESS                                              0x80
#define LCD_FONT_LARGE_8BIT                                                0x3C
#define LCD_FONT_SMALL_8BIT                                                0x38
#define LCD_FONT_LARGE_4BIT                                                0x2C
#define LCD_FONT_SMALL_4BIT                                                0x28

#define LCD_CGRAM_START_ADDRESS                                            0x40
#define LCD_DDRAM_START_ADDRESS                                            0x80

#define LCD_1ST_LINE_BEGGING                                               0x80
#define LCD_2ND_LINE_BEGGING                                               0xC0
#define LCD_3RD_LINE_BEGGING                                               0x90
#define LCD_4TH_LINE_BEGGING                                               0xD0




#define EXIT_FAILED                                                        0
#define EXIT_SUCCEED                                                       1

/**
 *
 * @param Copy_ConfigPtr: configuration table to initialize the LCD
 * @return status of that API
 */

extern u8 LCD_u8Init(LCD_Config_t *Copy_ConfigPtr)  ;


extern u8 LCD_u8SendCommand(u8 Copy_u8Command) ;


/**************************************************************************************************************
 * LCD Send Character to send the required character to be displayed in the current position
 * Input: Required Character
 * Output:Nothing
 *
 */
extern u8 LCD_u8SendCharCp(u8 Copy_u8Char) ;


/**************************************************************************************************************
 * LCD Send Text to send the required String to be displayed in the current position
 * Input: Array Of Character
 * Output:Nothing
 *
 */
extern u8  LCD_u8SendTextCp( u8 *Copy_u8Str) ;


/**************************************************************************************************************
 * LCD Goto X , Y : This function make the cursor to be placed in a specified location
 * Input: X Row , Y Column
 * Output:Nothing
 *
 */
extern u8 LCD_u8GotoX_Y(u8 Copy_u8Row, u8 Copy_u8Column)  ;

/**************************************************************************************************************
 * LCD Send Character to send the required character to be displayed in the specified position
 * Input: Required Character
 * Output:Nothing
 *
 */
extern u8 LCD_u8SendChar(u8 Copy_u8Row, u8 Copy_u8Column,
		u8 Copy_u8Data);


/**************************************************************************************************************
 * LCD Send Text to send the required String to be displayed in the specified position
 * Input: Array Of Character
 * Output:Nothing
 *
 */
extern u8 LCD_u8SendText( u8 Copy_u8Row, u8 Copy_u8Column,
		u8 *Copy_u8data) ;


/***************************************************************************************************************
 * CheckIfBusy: This function check if the current data can be written or read from LCD at this moment
 * Input: Nothing
 * Output: 0 when it is not busy 1 when it is busy
 */
extern u8 LCD_u8CheckIfBusy(void) ;

/***************************************************************************************************************
 * Generate_Character: This function enable the user to generate a custome character
 * Input: Array of character which contain the 7 rows of character pattern and address to where to store this character
 * output: Nothing
 */
extern u8 LCD_u8GenerateCharacter( u8 Copy_u8Address, u8 *Copy_u8CharRows);

/***************************************************************************************************************************
 * LCD Read: This Function Return a 8bit character from DDRAM or CGRAM
 * Input: Address of the byte you want to read
 * Output: The required character
 */
extern u8 LCD_u8ReadByte(u8 Copy_u8Row , u8 Copy_u8Column) ;
#endif /* LCD_H_ */
