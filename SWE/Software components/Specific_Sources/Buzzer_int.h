/******************************************************/
/* Author       : Nihal Khaled                        */
/* Date         : 2 May 2021                          */
/* Component	: Buzzer				              */
/* Layer		: HAL						          */
/* Version      : V01                                 */
/******************************************************/

#ifndef BUZZER_INT_H_
#define BUZZER_INT_H_

#include "Buzzer_cfg.h"

#define E_OK                       0
#define E_NOK                      1

/**
 * \par Req Id:
 * @n Req_PO1_DGC_CDD_Buzzer_001-V1.0
 *
 * \par Covers:
 * @n Req_PO1_DGC_GDD_BUZZER_001-V1.1
 *
 *\par Covers:
 * @n This Api is used to initialize the Buzzer
 *
 * @param Input : N/A
 * @param Ouput : N/A
 * @param Input/Output : N/A
 * @return
 * @n - E_OK
 * @n - E_NOK

 *\callgraph
 *
 *
 * @startuml
 *
 *
 *:Initialize the Buzzer ;
 *:Enable Global interrupts ;
 *:Initialize the timer ;
 *:Load the timer with the configured value ;
 *:Set the Overflow CallBack Function with the Buzzer_App ;
 *:Enable the overflow interrupt ;
 * stop
 * @enduml
 */
u8 Buzzer_u8Init(void);

/**
 * \par Req Id:
 * @n Req_PO1_DGC_CDD_Buzzer_002-V1.0
 *
 * \par Covers:
 * @n Req_PO1_DGC_GDD_BUZZER_002-V1.0
 *
 *\par Covers:
 * @n This Api is used to set the Buzzer on for the required time (ms) based on the configuration
 *
 * @param Input : N/A
 * @param Ouput : N/A
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
 *:Start the Buzzer;
 *:Start the timer;
 *:Set the buzzer pin to High till the overflow occurs ;
 * stop
 * @enduml
 */
u8 Buzzer_u8Start(void);

#endif /* BUZZER_INT_H_ */
