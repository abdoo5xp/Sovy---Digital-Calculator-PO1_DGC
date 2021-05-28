/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!     \file     Keypad_Manager_int.h
 *      \brief    prototypes and struct definition for Keypad_Manager module
 *
 *********************************************************************************************************************/


#ifndef KEYPAD_MANAGER_INT_H_
#define KEYPAD_MANAGER_INT_H_

/*! \typedef
 *  \struct <Keypad_Manager_s>
 *  structure to save user inputs
 * */
typedef struct{
	s16 Operands[4];
	u8 Operations[3];
	u8 NumOfOperands;
	u8 NumOfOperations;
}Keypad_Manager_s;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPE
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
void Keypad_Manager_MultiLineDisplay(Keypad_Manager_s * Keypad_manager_s);


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
 *********************************************************************************************************************/
ReturnStatus_e Keypad_Manager_PlayTone(void);

#endif /* KEYPAD_MANAGER_INT_H_ */
