

#include "Data_Types.h"
#include "calc_temp.h"


/**
\param Final_Result will contain the final result received from MATH_CALC.
*/
u64 *Final_Result=0;    // result will be multiplied by 100 then i need to take the read it and seperate the floating points
/*final result is global bec will be used in calling to a diff function so it cant be static 
and has to be global bec i will return from my function & there is a case i will need the old result
*/

//u64 res_temp = *result;    // assume = 750  (7.5) or 7523  (75.23)
                       // 7523%10 , 3 , 7523/10 = 752 , again 752%10 = 2 , i++ assign in array those values 
                       /* if(res_temp==0){print on lcd arr[i],i-- for loop  and display on that lcd };
                        lcd-goto 16-i if i==1 then print dot (.) then number 
                       */

                       /*if received an equal command again then assign in the inputnumbers 
                       //in the next command i make last result /100 because it was multiplied by 100 in the math calc
                       // bec of the floating number handling so i return it to int
                       input[0]=input[NumberOfInputNumbers-1] ,  input[1]=(*result/100);
                       NumberOfInputNumbers=2;
                    
                       InputOperations[0]=InputOperations[NumberOfInputOperations-1];
                       NumberOfInputOperations=1;
                       */

/*lets make a status flag and make 3 status the keypad will send me the state*/
/*3 cases 
1- normal case numbers & operations 
2- after the  '=' receive operation then a number // not gonna handele it as well wil be only a clear then equal 
(then should display 
Ans(operation)number)
*/

/*
if i pressed equal 
equalflag==1
after equal there is 3 status  (ask for the next pressedkey)
if
1- enter equal again will print the same answer (equalflag=1 still)
else if
2- enter a value (normal state ) (clear old and buffer new values)(equalflag=1 still)
else if
3- enter operation (should print  {ANS (operation) num} ex. Ans+2 )(and i should ) {in this case should buffer the operation
only and the next numbers up to 4 numbers and 3 operations & consider Ans(OldResult) one of the numbers then send it to
the operation mnager}
// then if the equalflag==1 & nextInput is operation not number  
// in this last case op mang take the struct from keypad manager with max 3 input numbers & 3 op max so i can add the result
// to the struct andd then give it to the math calc  (will have a statusflag 0 is normal 1 add the result to the stuct 
received from keypad mang )
*/


/*
extra
3- after press the 1st '=' then repeated '='    // will keep it as it is  (wont make the multiple equals)
(should save the last operation (                 InputOperations[NumberOfInputOperations-1]) 
                                & the last number Inputnumbers[NumberOfInputNumbers-1])
if received 2nd '=' so make the struct keypad_s points to only the result & the last number then send it with the operation
*/



/*andrew will give me the answer multiplied by 100 , ex 11.26  = 1126

call andrew Func and give him the stuct
Math_CALC(&mystruct); // will find the result inside it

PrintArray[i]= 1126%10 = 6
i++;
num = 1126/10=112
PrintArray[i]= 112%10=2
num = 112/10=11
PrintArray[i]= 11%10=1
num = 11/10=1
PrintArray[i]=num;
num=1/10=0; // here it will break the loop

*/




E_STATUS Operation_Manager(Keypad_Manager_s *Keypad_Struct)
{
	u64 Loc_u64Num;
	u8 Loc_u8aPrintArray[16];		//use this array to just save result digit by digit localy and print it on the LCD
	u8 Return_Status=E_OK;

/*before calling the MATH_CALC i need to check if the received struct from keypad module is a repeated equal or normal
if normal equal then wont add the old result to the struct
else if it's equal to the repeated equal operation that means i need to add the old result to the struct 
so the math calc will make the operation on it
*/


	if( Keypad_Struct->InputOperations == Keypad_Struct->Inputnumbers && Keypad_Struct->Status_Flag==1){
		Keypad_Struct->Inputnumbers[0]=*Final_Result/100;	// result here will be the old result
			/* must put the result in the 1st place because its the place will print ANS then operations & inputs  after
				e.g. :  Ans+1+2+3 = 
				 so 1st aplce for Ans then the operation want to be done on the old result (Ans) so in keypad manager
				 should leave the 1st place empty and add values from 2nd place arr[1] till arr[3]
				 and will count only the numbers that keypad manager will enter only not inculding the result 
				 won't count the Ans as an input for the array
				*/
		//   last place if array of inputs = result , if input number is 3 then i but in the 4th place which is a[3]
	}
	else if(Keypad_Struct->InputOperations >= Keypad_Struct->Inputnumbers && Keypad_Struct->Status_Flag==0){
		Lcd_Send_Packet(LCD_CMD_CLEAR,IS_CMD);
		Lcd_GoTo(0,0);
		Lcd_WriteString("Syntax Error");
		return E_NOK;
	} 
	/*
	1+2+3+4
	1+  		SYNTAX ERROR
	1+1+		SYNTAX ERROR
	1+1+1+		SYNTAX ERROR
	1+1+++		SYNTAX ERROR
	1++++ syntax error 
	*/
	
	Return_Status=Math_CALC(&mystruct,&Final_Result);
	
	if(Return_Status==E_NOK){
		Lcd_Send_Packet(LCD_CMD_CLEAR,IS_CMD);
		Lcd_GoTo(0,0);
		Lcd_WriteString("Math Error");		
		return E_NOK;
	}	
	else {} // else will just continue the code 

	Loc_u64Num=*Final_Result;
	
	
	while (Loc_u64Num!=0){
		Loc_u8aPrintArray[i]= Loc_u64Num%10;
		if( (16-i) == 14 ){		// will display the point at the 14th place on the LCD
			Lcd_GoTo(1,16-i);	// row 2 last column to display the last digit
			Lcd_Send_Packet('.',IS_DATA);
		}
		else{
			Lcd_GoTo(1,16-i);	// row 2 last colom to display the last digit
			Lcd_Send_Packet(Loc_u8aPrintArray[i],IS_DATA);
		}
		i++;
		Loc_u64Num /=10;
	}

}




/*2nd part of the function is to check the received struct from Keypad manager will contain the 1st value is empty to 
add the result to the struct or not 

if(struct->InputOperations == struct->Inputnumbers ){
	struct-> u8 Inputnumbers[0]=result;	// result here will be the old result
}

*/
