
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


/** @struct keypad_s
 *  	@brief This structure contain the entered operands and operation and their numbers.
 * @param Inputnumbers[4]
 *  	@nContain the enterted operands.
 * @param InputOperations[3]
 *  	@nContain the enterted operations.
 *  @param NumberOfInputNumbers
 *  	@nContain the nubmer of operands.
 *  @param NumberOfInputOperations
 *  	@nContain the nubmer of operations.
 */
typedef struct{

    u32 Inputnumbers[4];
    u8 InputOperations[3];
    u8 NumberOfInputNumbers;
    u8 NumberOfInputOperations;

}keypad_s;





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
*:tempResult = inputNumbers->NumberOfInputNumbers[0];
*repeat
*  if ('+') then (yes)
*  :*result = tempResult + inputNumbers->NumberOfInputNumbers[i+1];
*elseif ('-') then (yes)
*  :*result = tempResult - inputNumbers->NumberOfInputNumbers[i+1];
*elseif ('/') then (yes)
*  if (!(inputNumbers->NumberOfInputNumbers[i+1])) then (yes)
*  :*result =  tempResult / inputNumbers->NumberOfInputNumbers[i+1];
*else (no)
*  :returnStatus = E_NOK;
*endif
*elseif ('*') then (yes)
*  :*result = tempResult * inputNumbers->NumberOfInputNumbers[i+1];
*else (nothing)
*  :returnStatus = E_NOK;
*endif
*:tempResult = *result;
*:i++;
*repeat while (i<inputNumbers->NumberOfInputOperations) is (yes)
*->no;
*:return returnStatus;
*stop
*@enduml
*
*/

ReturnStatus_e Math_Calc(keypad_s *inputNumbers, u64 *result);

#endif /* MATHCALC_H_ */
