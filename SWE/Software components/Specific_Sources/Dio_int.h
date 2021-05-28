#ifndef DIO_INT_H_
#define DIO_INT_H_

/*DIO Software PINS*/
#define DIO_u8PIN_0  0
#define DIO_u8PIN_1  1
#define DIO_u8PIN_2  2
#define DIO_u8PIN_3  3
#define DIO_u8PIN_4  4
#define DIO_u8PIN_5  5
#define DIO_u8PIN_6  6
#define DIO_u8PIN_7  7
#define DIO_u8PIN_8  8
#define DIO_u8PIN_9  9
#define DIO_u8PIN_10 10
#define DIO_u8PIN_11 11
#define DIO_u8PIN_12 12
#define DIO_u8PIN_13 13
#define DIO_u8PIN_14 14
#define DIO_u8PIN_15 15
#define DIO_u8PIN_16 16
#define DIO_u8PIN_17 17
#define DIO_u8PIN_18 18
#define DIO_u8PIN_19 19
#define DIO_u8PIN_20 20
#define DIO_u8PIN_21 21
#define DIO_u8PIN_22 22
#define DIO_u8PIN_23 23
#define DIO_u8PIN_24 24
#define DIO_u8PIN_25 25
#define DIO_u8PIN_26 26
#define DIO_u8PIN_27 27
#define DIO_u8PIN_28 28
#define DIO_u8PIN_29 29
#define DIO_u8PIN_30 30
#define DIO_u8PIN_31 31

/*DIO pin values*/
#define DIO_u8HIGH 1
#define DIO_u8LOW  0


/**
 * \par Req Id:
 * @n Req_PO1_DGC_CDD_PORT_004-V1.0
 *
 * \par Covers:
 * @n Req_PO1_DGC_GDD_DIO_004-V1.2
 *
 * \par Description
 * @n This function is used to change the Software pin value
 *
 * @param Input: Copy_u8SwPinNo , Copy_u8PinVal
 * @param Output: N/A
 * @param Input/Output: N/A
 * @return
 * @n - E_OK
 * @n - E_NOK
 *
 *\par Main Steps
 *@n	1- Determine the pin ID and the port ID from the the SW pin number passed to the function as a parameter.
 * @n	2- Using the PORT ID a switch case is made to assign the desired mode to the desired pin in the right port
 * @n	3- There are 2 values in which a pin can be changed to (HIGH and LOW).
 * @n   4- For HIGH Value the PORTx register is set to 1 at the bit corresponding to the pin ID.
 * @n	5- For LOW Value the PORTx register is set to 0 at the bit corresponding to the pin ID.
 *
 * \par Function sequence
 *
 *\callgraph
 *\callergraph
 *
 *@startuml
*start
*  - Determine the Port ID by dividing the Software pin value by 8
*  - Determine the Pin ID by getting the remainder of the division process of the software pin value by 8
*  - Using switch case, switch on the port ID to start assigning the desired direction to the pin determined
*  - check for the value parameter
*
* if(the value is HIGH) then (yes)
*  - set the PORTx register to 1 at the bit corresponding to the Pin ID
*  else (no)
*   if(the value is LOW) then(yes)
*  - set the PORTx register to 0 at the bit corresponding to the Pin ID
*endif
*endif
*stop
*@enduml
 */





/***************************
 * Function Description : Change the value of the software pins
 *
 *
 * Parameters : u8 Copy_u8SwPinNo, u8 Copy_u8SwPinDir
 *
 *
 * Return : ReturnStatus_e
 *
 * Example : DIO_u8SetPinVal(DIO_u8PIN_0, DIO_u8HIGH);
 *
 *
 ***************************/

ReturnStatus_e Dio_u8SetPinVal(u8 Copy_u8SwPinNo, u8 Copy_u8SwPinVal);

/**
 * \par Req Id:
 * @n Req_PO1_DGC_CDD_PORT_005-V1.0
 *
 * \par Covers:
 * @n Req_PO1_DGC_GDD_DIO_005-V1.2
 *
 * \par Description
 * @n This function is used to change the Software pin Mode
 *
 * @param Input: Copy_u8SwPinNo , Copy_u8PinDir
 * @param Output: N/A
 * @param Input/Output: N/A
 * @return
 * @n - u8
 *
 *\par Main Steps
 *@n	1- Determine the pin ID and the port ID from the the SW pin number passed to the function as a parameter.
 * @n	2- Using the PORT ID a switch case is made to assign the desired mode to the desired pin in the right port
 * @n	3- There are 2 values for each software pin (HIGH and LOW)
 * \par Function sequence
 *
 *\callgraph
 *\callergraph
 *
 *@startuml
*start
*  - Determine the Port ID by dividing the Software pin value by 8
*  - Determine the Pin ID by getting the remainder of the division process of the software pin value by 8
*  - Using switch case, switch on the port ID to start assigning the desired direction to the pin determined
*  - Read the PORTx register corresponding to the Port ID determined above
*
* if(the value is HIGH) then (yes)
*  - Return high(1)
*  else (no)
*   if(the value is LOW) then(yes)
*  - Return low (0)
*endif
*endif
*stop
*@enduml
 */





/***************************
 * Function Description : Gets the value of the software pin
 *
 *
 * Parameters : u8 Copy_u8SwPinNo
 *
 *
 * Return : u8
 *
 * Example : Dio_u8GetPinVal(DIO_u8PIN_0);
 *
 *
 ***************************/

u8 Dio_u8GetPinVal(u8 Copy_u8SwPinNo);

#endif /* DIO_INT_H_ */
