/**
 *@file
 *
 *  @date : May 17, 2021
 *   @author: Hossam
 *
 * <table>
*<caption id="multi_row">Document History</caption>
*<tr><th>Version	<th>Author        		<th>Date   			<th>Change
*<tr><td>1.1	   	<td>Hossam Magdy.    	<td>17-05-2021.  	<td>Initial creation.
*<tr><td>1.2		<td>Hossam Magdy.		<td>17-05-2021.		<td>Test Table.
*</table>
*/

#ifndef OPERATION_MANG_H
#define OPERATION_MANG_H



 /**
 * \par Req Id:
 * @n Req_PO1_DGC_OPERATION_MANAGER_001-V1.0
 *
 * \par Covers:
 * @n	Req_PO1_DGC_GDD_OPERATION_MANAGER_0012-V1.1
 * \par Description
 * @n This API function is responsible for Display Result and Errors.
 * @param Input: struct type keypad_s
 * @param Output: Result value or Error Massage
 * @return
 * @n - E_NOK
 * @n - E_OK
 *
 *
 *\callgraph
 *\callergraph
 *
*
*@startuml
*start
*if (Keypad_Struct->InputOperations == \n Keypad_Struct->Inputnumbers && \n Keypad_Struct->Status_Flag == 1) then (true)
*  :Keypad_Struct->Inputnumbers[0] \n =*Final_Result/100;
*elseif (Keypad_Struct->InputOperations >= \n Keypad_Struct->Inputnumbers && \n Keypad_Struct->Status_Flag==0) then (true)
*  :Lcd_Send_Packet(LCD_CMD_CLEAR,IS_CMD);
*  :Lcd_GoTo(0,0);
*  :Lcd_WriteString("Syntax Error");
*  :return E_NOK;
*  end
*else (neither correct)
*endif
*:Return_Status=Math_CALC(&mystruct,&Final_Result);
*if (Return_Status==E_NOK) then (true)
*  :Lcd_Send_Packet(LCD_CMD_CLEAR,IS_CMD);
*  :Lcd_GoTo(0,0);
*  :Lcd_WriteString("Math Error");
*  :return E_NOK;
*  stop
*endif
*:Loc_u64Num=*Final_Result;
*while (Loc_u64Num!=0 ?) is (true)
*  :Loc_u8aPrintArray[i]= Loc_u64Num%10;
*
* if ((16-i) == 14 ) then (true)
*  :Lcd_GoTo(1,16-i);
*  :LCD_DISPLAY('.');
* else (false)
*  :Lcd_GoTo(1,16-i);
*  :LCD_DISPLAY(Loc_u8aPrintArray[i]);
* endif
* :i++;
* :Loc_u64Num /=10;
*endwhile (false)
*:return E_OK;
*stop
*@enduml
 */



extern E_STATUS Operation_Manager(Keypad_Manager_s *Keypad_Struct);


#endif // OPERATION_MANG_H