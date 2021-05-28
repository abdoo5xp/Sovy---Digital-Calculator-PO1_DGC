/******************************************************/
/* Author       : Nihal Khaled                        */
/* Date         : 23 March 2021                       */
/* Component	: Gpt					              */
/* Layer		: MCAL						          */
/* Version      : V01                                 */
/******************************************************/

#ifndef GPT_INT_H_
#define GPT_INT_H_

/* Data type of pointer to function */

#define E_OK                       0
#define E_NOK                      1


/* Timer modes */
#define TIMER0_MODE_NORMAL                                     0b00000000
#define TIMER0_MODE_PHASE_CORRECT                              0b00001000
#define TIMER0_MODE_CTC                                        0b01000000
#define TIMER0_MODE_FAST_PWM                                   0b01001000

/* OPtion for   CTC and Normal modes */

#define TIMER0_OUTPUTCOMPARE_MODE_NONPWM_DISCONNECT			   0b00000000
//0 1 Toggle OC0 on compare match
#define TIMER0_OUTPUTCOMPARE_MODE_NONPWM_TOGGLE				   0b00010000
//1 0 Clear OC0 on compare match
#define TIMER0_OUTPUTCOMPARE_MODE_NONPWM_CLEAR				   0b00100000
//1 1 Set OC0 on compare match
#define TIMER0_OUTPUTCOMPARE_MODE_NONPWM_SET				   0b00110000

/* Options for fast PWM */

//0 0 Normal port operation, OC0 disconnected.
#define TIMER0_OUTPUTCOMPARE_MODE_FASTPWM_DISCONNECT			0b00000000
//1 0 Clear OC0 on compare match, set OC0 at BOTTOM,(non-inverting mode)
#define TIMER0_OUTPUTCOMPARE_MODE_FASTPWM_NONINVERTING			0b00100000
//1 1 Set OC0 on compare match, clear OC0 at BOTTOM,(inverting mode)
#define TIMER0_OUTPUTCOMPARE_MODE_FASTPWM_INVERTING			    0b00110000


/* OPtions for Phase correct mode */
#define TIMER0_OUTPUTCOMPARE_MODE_PHASEPWM_DISCONNECT           0b00000000
#define TIMER0_OUTPUTCOMPARE_MODE_PHASEPWM_CLEAR                0b00100000
#define TIMER0_OUTPUTCOMPARE_MODE_PHASEPWM_SET                  0b00110000




/* Options for CLK                        */
#define TIMER0_CLK_STOP                                         0b0000000
#define TIMER0_CLK_NO_PRESCALLER                                0b0000001
#define TIMER0_CLK_PRESCALLER8                                  0b0000010
#define TIMER0_CLK_PRESCALLER64                                 0b0000011
#define TIMER0_CLK_PRESCALLER256                                0b0000100
#define TIMER0_CLK_PRESCALLER1024                               0b0000101
#define TIMER0_CLK_EXTERNAL_CLK_FALLING_EDGE                    0b0000110
#define TIMER0_CLK_EXTERNAL_CLK_RISING_EDGE                     0b0000111




/**
 * \par Req Id:
 * @n Req_PO1_CDD_Timer_001-V1.0
 *
 * \par Covers:
 * @n Req_PO1_DGC_GDD_TIMER_006-V1.2
 *
 *\par Covers:
 * @ This Api function is used to initialize the Timer
 *
 * @param Input : N/A
 * @param Input : N/A
 * @param Input/Output : N/A
 * @return
 * @n - E_OK
 * @n - E_NOK
 *
 *\callgraph
 *\callergraph
 *
 * @startuml
 *
 *:Init Gpt;
 *:Clear the timer mode bits with the mask;
 *:Set Timer mode with the configured mode;
 *stop
 * @enduml
 */
extern u8 Gpt_u8Init(void);

/**
 * \par Req Id:
 * @n Req_PO1_CDD_Timer_002-V1.0
 *
 * \par Covers:
 * @n Req_PO1_DGC_GDD_TIMER_007-V1.1
 *
 *\par Covers:
 * @n This Api function is used to start the timer by select the clock source.
 *
 * @param Input : N/A
 * @param Input : N/A
 * @param Input/Output : N/A
 * @return : N/A
 *
 *\callgraph
 *\callergraph
 *
 * @startuml
 *
 *:Start Timer;
 *:Clear the clk_prescaler bits with the mask;
 *:Set clk prescaler bits with the configured prescaler;
 *stop
 * @enduml
 *
 */
extern void Gpt_vidStartTimer(void);



/**
 * \par Req Id:
 * @n Req_PO1_CDD_Timer_003-V1.0
 *
 * \par Covers:
 * @n Req_PO1_DGC_GDD_TIMER_008-V1.1
 *
 *\par Covers:
 * @n This Api function is used to stop the timer.
 *
 * @param Input : N/A
 * @param Ouput : N/A
 * @param Input/Output : N/A
 * @return : N/A
 *
 *\callgraph
 *\callergraph
 *
 * @startuml
 *
 *:Stop Timer;
 *:Set clk_mode with stop mode;
 *stop
 * @enduml
 *
 */
extern void Gpt_vidStopTimer(void);


/**
 * \par Req Id:
 * @n Req_PO1_CDD_Timer_004-V1.0
 *
 * \par Covers:
 * @n Req_PO1_DGC_GDD_TIMER_009-V1.1
 *
 *\par Covers:
 * @n This Api function is used to set the call back function for overflow interrupt.
 *
 * @param Input : void(*ptr)(void)
 * @param Ouput : N/A
 * @param Input/Output : N/A
 * @return : N/A
 *
 *\callgraph
 *\callergraph
 *
 * @startuml
 *
 *
 *:Set callback function with the user Api;
 *stop
 * @enduml
 *
 */
extern u8 Gpt_vidSetCBF( void(*ptr)(void) );


/**
 * \par Req Id:
 * @n Req_PO1_CDD_Timer_005-V1.0
 *
 * \par Covers:
 * @n Req_PO1_DGC_GDD_TIMER_0010-V1.1
 *
 *\par Covers:
 * @n This Api function is used to set the reload value of the timer.
 *
 * @param Input : u8 Copy_u8Value: in range {0-255}
 * @param Ouput : N/A
 * @param Input/Output : N/A
 * @return : N/A
 *
 *\callgraph
 *\callergraph
 *
 * @startuml
 *
 *:Load Timer;
 *:Load Timer counter register with Copy_u8Value;
 *stop
 * @enduml
 *
 */
extern void Gpt_vidLoadTimer(u8 Copy_u8Value);


/**
 * \par Req Id:
 * @n Req_PO1_CDD_Timer_006-V1.0
 *
 * \par Covers:
 * @n Req_PO1_DGC_GDD_TIMER_0011-V1.0
 *
 *\par Covers:
 *@n This Api function is used to enable the timer interrupt.
 *
 * @param Input : N/A
 * @param Input : N/A
 * @param Input/Output : N/A
 * @return : N/A
 *
 *\callgraph
 *\callergraph
 *
 * @startuml
 *
 *: Set the overflow Interrupt Enable bit Timer interrupt msk register ;
 *stop
 * @enduml
 */
extern void Gpt_vidEnableNotification(void);

/**
 * \par Req Id:
 * @n Req_PO1_CDD_Timer_007-V1.0
 *
 * \par Covers:
 * @n Req_PO1_DGC_GDD_TIMER_0012-V1.0
 *
 *\par Covers:
 * @n This Api function is used to disable the timer interrupt.
 *
 * @param Input : N/A
 * @param Input : N/A
 * @param Input/Output : N/A
 * @return : N/A
 *
 *\callgraph
 *\callergraph
 *
 * @startuml
 *
 *: clear the overflow Interrupt Enable bit Timer interrupt msk register ;
 *stop
 * @enduml
 */
extern void Gpt_vidDisableNotification(void);


#endif /*GPT_INT_H_ */
