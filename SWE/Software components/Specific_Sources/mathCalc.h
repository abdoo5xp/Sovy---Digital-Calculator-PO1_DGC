
/**
 *@file
 *
 *  @date : Feb 14, 2021
 *   @author: Andrew Ezzat
 *
 * <table>
*<caption id="multi_row">Document History</caption>
*<tr><th>Version	<th>Author        		<th>Date   			<th>Change
*<tr><td>0.1	   	<td>Andrew Ezzat.    	<td>27-04-2021.  	<td>Initial creation.
*</table>
 */


#ifndef MATHCALC_H_
#define MATHCALC_H_
#include "Data_Types.h"






/**
* \par Req Id:
* 	@n    Req_PO1_DGC_CDD_MATH_CALC_001-V1.0
*
* \par Covers:
* 	@n	Req_PO1_DGC_GDD_MATH_CALC_0011-V1.1
*
* \par Description
* 	@n This API  is responsible for calculate all the operations that came from the "Operation Manger".
*
* @param Input:
* 	@n inputNumbers : It is sturct that contain the operand and the operation.
* @param Output:
* 	@n result : It is pointer that will contain the operations result.
* @param Input/Output:
* 	@n N/A
* @return
* 	@n - E_OK
* 	@n - E_NOK
*
*\callgraph
*\callergraph
*
*
*@startuml
*start
*:returnStatus = E_OK;
*: i = 0;
*:tempResult = inputNumbers->Operands[0];
*repeat
*  if (inputNumbers->Operations[i] == '+') then (yes)
*  :*result = tempResult + inputNumbers->Operands[i+1];
*elseif (inputNumbers->Operations[i] =='-') then (yes)
*  :*result = tempResult - inputNumbers->Operands[i+1];
*elseif (inputNumbers->Operations[i] =='/') then (yes)
*  if (!(inputNumbers->Operands[i+1])) then (yes)
*  :*result =  tempResult / inputNumbers->Operands[i+1];
*else (no)
*  :returnStatus = E_NOK;
*endif
*elseif (inputNumbers->Operations[i] =='*') then (yes)
*  :*result = tempResult * inputNumbers->Operands[i+1];
*else (nothing)
*  :returnStatus = E_NOK;
*endif
*:tempResult = *result;
*:i++;
*repeat while (i<inputNumbers->NumOfOperations) is (yes)
*->no;
*:return returnStatus;
*stop
*@enduml
*
*/

ReturnStatus_e Math_Calc(Keypad_Manager_s *inputNumbers, u64 *result);

#endif /* MATHCALC_H_ */
