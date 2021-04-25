/*
 * BIT_MATH.h
 *
 *  Created on: Sep 9, 2020
 *      Author: Kareem
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG,BIT_NO)    ((REG) |= (1<<BIT_NO))
#define CLEAR_BIT(REG,BIT_NO)  ((REG) &= ~(1<<BIT_NO))
#define TOGGLE_BIT(REG,BIT_NO) ((REG) ^= (1<<BIT_NO))
#define GET_BIT(REG,BIT_NO) (((REG)>>(BIT_NO)) & (1))

#endif /* BIT_MATH_H_ */
