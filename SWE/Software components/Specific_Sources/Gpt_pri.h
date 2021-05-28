/******************************************************/
/* Author       : Nihal Khaled                        */
/* Date         : 23 March 2021                       */
/* Component	: Gpt					              */
/* Layer		: MCAL						          */
/* Version      : V01                                 */
/******************************************************/

#ifndef GPT_PRI_H_
#define GPT_PRI_H_

void __vector_10 (void) __attribute__ ((signal)) ;
void __vector_11 (void) __attribute__ ((signal)) ;




#define TIMER0_MODE_MASK                 0b10110111
#define TIMER0_CLK_MASK                  0b11111000
#define TIMER0_COMPARE_OUTPUT_MASK       0b11001111



/* Interrupts */
#define TIMER0_INTERRUPT_COMPARE_MATCH       0b00000010

#define TIMER0_INTERRUPT_OVER_FLOW           0b00000001


#endif /* GPT_PRI_H_ */
