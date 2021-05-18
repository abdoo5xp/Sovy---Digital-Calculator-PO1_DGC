/*
 * mathCalc.c
 *
 *  Created on: May 17, 2021
 *      Author: Andrew
 */

#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Math.h"
#include "../Lib/ATmega32_Registers.h"
#include "../Lib/ErrorCode.h"



ReturnStatus_e Math_Calc(keypad_s *inputNumbers, u64 *result)
{
	ReturnStatus_e returnStatus = E_OK;
	u64 tempResult ;
	tempResult = inputNumbers->NumberOfInputNumbers[0];
	for(u8 i = 0; i<inputNumbers->NumberOfInputOperations; i++)
	{
		switch(inputNumbers->InputOperations[i])
		{
		case '+':
			*result = tempResult + inputNumbers->NumberOfInputNumbers[i+1];
			break;
		case '-':
			*result =  tempResult - inputNumbers->NumberOfInputNumbers[i+1];
			break;
		case '/':
			if (!(inputNumbers->NumberOfInputNumbers[i+1]))
			{
				*result =  tempResult / inputNumbers->NumberOfInputNumbers[i+1];
			}
			else
			{
				returnStatus = E_NOK;
			}
			break;
		case'*':
			*result =  tempResult * inputNumbers->NumberOfInputNumbers[i+1];
			break;

		}
		tempResult = *result;

	}
	return returnStatus;
}
