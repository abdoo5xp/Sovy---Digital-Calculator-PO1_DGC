/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!     \file     Keypad_Manager.c
 *      \brief    implementation of keypad multiline functions and
 *      \details  implements the static functions( isOperation - numberState - operationState)
 *      and global functions (Keypad_Manager_MultiLineDisplay, )
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "../lib/Bit_Math.h"
#include "../lib/Std_Types.h"
#include "ATmega32_Registers.h"
#include <util/delay.h>
#include "keypad_int.h"
#include "Lcd_int.h"
#include "Keypad_Manager_int.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#undef F_CPU
#define  F_CPU 8000000
#define ASCI_NUM_CONVERTER 	48

//! An enum.
/*! Enum for the states that is used in Keypad_Manager_MultiLineDisplay function */
typedef enum{
	ErrorState,
	ClearState,
	stateNum1,
	stateOp1,
	stateNum2,
	stateOp2,
	stateNum3,
	stateOp3,
	stateNum4
}states_e;

/**********************************************************************************************************************
 *  GLOCAL VARIABLES
 *********************************************************************************************************************/
u8 state = stateNum1;    /*!< initial state*/


/**********************************************************************************************************************
 *  LOCAL FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  u8 isOperation(u8 key)
 *********************************************************************************************************************/
/*! \static
 *  \details       function that checks wether input in a operation or not
 *  \param[in]     u8
 *  \param[in,out] None
 *  \param[out]    None
 *  \return        u8
 *  \pre           None
 *  \context       TASK
 *********************************************************************************************************************/
static u8 isOperation(u8 key){
	if(key == '+' || key == '/' || key == '*' || key == '-' ){
		return 1;
	}
	else {
		return 0;
	}
}

/**********************************************************************************************************************
 *  LOCAL FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  void numberState(u8 flag, u8 counter,u8 keyPressed,u8 curentState,u8 nextState,s32 operand,u8 numOfOperands)
 *********************************************************************************************************************/
/*! \static
 *  \details       function that saves operand input in the array of operands inside of the struct, increments number of operands
 *  , displays operand on lcd and decides which state is next
 *  \param[in]     u8 flag, u8 counter,u8 keyPressed,u8 curentState,u8 nextStates
 *  \param[in,out] s16 operand,u8 numOfOperands
 *  \param[out]    None
 *  \return        void
 *  \pre           None
 *  \context       TASK
 *********************************************************************************************************************/
static void numberState(u8 flag, u8 counter,u8 keyPressed,u8 curentState,u8 nextState,s16 operand,u8 numOfOperands){
	if(keyPressed=='C'){
		state= ClearState;
	}
	else if(!flag && !isOperation(keyPressed))     /*if it is the first digit in the operand*/
	{
		flag=1;
		counter=1;
		Lcd_Send_Packet(keyPressed,IS_DATA);  /*display first digit */
		operand= keyPressed-ASCI_NUM_CONVERTER;            /* convert to number and save in operand array in Keypad_Manager_s structure */
		numOfOperands++;                                   /* increment number of operands */
		state = curentState;                               /* state still in same operand state*/
	}
	else if(flag && !isOperation(keyPressed))      /*if it is not the first digit in the operand & number is pressed*/
	{
		counter++;                                         /* operands should not exceed 3 digits */
		if(counter < 4)
		{
			Lcd_Send_Packet(keyPressed,IS_DATA);                  /* display digit */
			operand = operand*10+(keyPressed-ASCI_NUM_CONVERTER); /* convert to number and save in operand array in Keypad_Manager_s structure */
			state = curentState;                                  /* state still in same operand state*/
		}
		else                                               /* if operand exceeded 3 digits*/
		{
			state = curentState;                                  /* do nothing & state still in same operand state*/
		}
	}
	else if(flag && isOperation(keyPressed))       /*if it is not the first digit in the operand & operation is pressed*/
	{
		state = nextState;                                        /* state goes to operation state*/
	}
}

/**********************************************************************************************************************
 *  LOCAL FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  void operationState(u8 keyPressed,u8 nextState, u8 operations, u8 numOfOperations)
 *********************************************************************************************************************/
/*! \static
 *  \details       function that saves operation input in the array of operands inside of the struct, increments number of operations
 *  , displays operation on lcd and decides which state is next
 *  \param[in]     u8 keyPressed,u8 nextState
 *  \param[in,out] u8 operations, u8 numOfOperations
 *  \param[out]    None
 *  \return        void
 *  \pre           None
 *  \context       TASK
 *********************************************************************************************************************/
static void operationState(u8 keyPressed,u8 nextState, u8 operations, u8 numOfOperations){
	Lcd_Send_Packet(keyPressed,IS_DATA);                           /* display operation */
	operations= keyPressed;                                        /* save in operation array in Keypad_Manager_s structure */
	if(keyPressed=='C'){
		state= ClearState;
	}
	else if(isOperation(keyPressed))                               /* if operation is pressed after operation "3 + / "      */
	{
		state= ErrorState;
	}
	else if (!isOperation(keyPressed))                             /* if operand is pressed after operation */
	{
		state= nextState;                                          /* state goes to operand state*/
	}
}

/**********************************************************************************************************************
 *  LOCAL FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  void Keypad_Manager_MultiLineDisplay(Keypad_Manager_s * Keypad_manager_s)
 *********************************************************************************************************************/
/*! \details       state machine that displays key pressed on lcd and saves user input (operation and operands) in a struct
 *  \param[in]     None
 *  \param[in,out] None
 *  \param[out]    Keypad_manager_s
 *  \return        void
 *  \pre           None
 *  \context       TASK
 *********************************************************************************************************************/
void Keypad_Manager_MultiLineDisplay(Keypad_Manager_s * Keypad_manager_s){
	u8 flag1=0, flag2=0, flag3=0, flag4=0 ;             /* flag for first digit in each operand */
	u8 counter1=0, counter2=0, counter3=0, counter4=0;  /*counter for size of digits of each operand */
	Keypad_manager_s->NumOfOperands=0;
	Keypad_manager_s->NumOfOperations=0;
	u8 Loc_keyPressed = KEYPAD_u8NO_KEY;
	while(Loc_keyPressed != '=')
	{
		Keypad_u8GetKey(&Loc_keyPressed);
		if (Loc_keyPressed != KEYPAD_u8NO_KEY)
		{
			switch(state){
			case stateNum1:  /*   1   */
				numberState(flag1,counter1,Loc_keyPressed,stateNum1,stateOp1,Keypad_manager_s->Operands[0],Keypad_manager_s->NumOfOperands);
				break;

			case stateOp1:  /*   1 +   */
				operationState(Loc_keyPressed,stateNum2, Keypad_manager_s->Operations[0], Keypad_manager_s->NumOfOperations);
				break;

			case stateNum2:   /*   1 + 12   */
				numberState(flag2,counter2,Loc_keyPressed,stateNum2,stateOp2,Keypad_manager_s->Operands[1],Keypad_manager_s->NumOfOperands);
				break;

			case stateOp2:  /*   1 + 12 *   */
				operationState(Loc_keyPressed,stateNum3, Keypad_manager_s->Operations[1], Keypad_manager_s->NumOfOperations);
				break;


			case stateNum3:    /*   1 + 12 * 2  */
				numberState(flag3,counter3,Loc_keyPressed,stateNum3,stateOp3,Keypad_manager_s->Operands[2],Keypad_manager_s->NumOfOperands);
				break;

			case stateOp3:   /*   1 + 12 * 2 -  */
				operationState(Loc_keyPressed,stateNum4, Keypad_manager_s->Operations[2], Keypad_manager_s->NumOfOperations);
				break;

			case stateNum4:    /*   1 + 12 * 2 - 6 */
				numberState(flag4,counter4,Loc_keyPressed,stateNum4,ErrorState,Keypad_manager_s->Operands[3],Keypad_manager_s->NumOfOperands);
				break;

			case ClearState:
				flag1=0, flag2=0, flag3=0, flag4=0;
				counter1=0, counter2=0, counter3=0, counter4=0;
				Keypad_manager_s->NumOfOperands=0;
				Keypad_manager_s->NumOfOperations=0;
				Lcd_Send_Packet(LCD_CMD_CLEAR,IS_CMD);
				if(!isOperation(Loc_keyPressed) && !Loc_keyPressed=='C')
				{
					state=stateNum1;
				}
				else
				{
					state = ClearState;
				}
				break;

			case ErrorState:
				Lcd_Send_Packet(LCD_CMD_CLEAR,IS_CMD);  /* clear lcd */
				Lcd_WriteString("Syntax Error");                         /* display "syntax error" msg on lcd */
				_delay_ms(500);                                             /* delay 0.5 second */
				state = ClearState;                                        /* clear state */
				break;
			}
		}
	}
}


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPE
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ReturnStatus_e Keypad_Manager_PlayTone(void);
 *********************************************************************************************************************/
/*! \details       Plays a tone when a key is pressed on the keypad
 *  \param[in]     None
 *  \param[in,out] None
 *  \param[out]    void
 *  \return        ReturnStatus_e
 *  \pre           None
 *  \context       TASK
 *  \reentrant     TRUE
 *********************************************************************************************************************/
ReturnStatus_e Keypad_Manager_PlayTone(void){
	return E_NOK;
}



