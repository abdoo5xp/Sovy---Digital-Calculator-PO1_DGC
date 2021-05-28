#ifndef PORT_INT_H_
#define PORT_INT_H_

/*Return Values*/
typedef enum
{
	E_OK,
	E_NOK

}ReturnStatus_e;

/*PORT Software PINS*/
#define PORT_u8PIN_0  0
#define PORT_u8PIN_1  1
#define PORT_u8PIN_2  2
#define PORT_u8PIN_3  3
#define PORT_u8PIN_4  4
#define PORT_u8PIN_5  5
#define PORT_u8PIN_6  6
#define PORT_u8PIN_7  7
#define PORT_u8PIN_8  8
#define PORT_u8PIN_9  9
#define PORT_u8PIN_10 10
#define PORT_u8PIN_11 11
#define PORT_u8PIN_12 12
#define PORT_u8PIN_13 13
#define PORT_u8PIN_14 14
#define PORT_u8PIN_15 15
#define PORT_u8PIN_16 16
#define PORT_u8PIN_17 17
#define PORT_u8PIN_18 18
#define PORT_u8PIN_19 19
#define PORT_u8PIN_20 20
#define PORT_u8PIN_21 21
#define PORT_u8PIN_22 22
#define PORT_u8PIN_23 23
#define PORT_u8PIN_24 24
#define PORT_u8PIN_25 25
#define PORT_u8PIN_26 26
#define PORT_u8PIN_27 27
#define PORT_u8PIN_28 28
#define PORT_u8PIN_29 29
#define PORT_u8PIN_30 30
#define PORT_u8PIN_31 31

/*Port Pin Modes*/
#define PORT_u8OUTPUT_HIGH   1
#define PORT_u8OUTPUT_LOW     2
#define PORT_u8INPUT_HIGH_IMP 3
#define PORT_u8INPUT_PULL_UP  4

/*Port Pin Directions*/
#define PORT_u8OUTPUT     1
#define PORT_u8INPUT      0

/**
 * \par Req Id:
 * @n Req_PO1_DGC_CDD_PORT_001-V1.0
 *
 * \par Covers:
 * @n	Req_PO1_DGC_GDD_PORT_001-V1.1
 *
 * \par Description
 * @n This API function that is responsible for initializing all pins and ports to their operation mode and initial values.
 *
 * @param Input: void
 * @param Output: N/A
 * @param Input/Output: N/A
 * @return: void
 *
 *\par Main Steps
 *@n	1- Check for the initial mode (ex:PORT_u8PIN_0_INIT_MODE) assigned to each pin in the configuration file
 * @n	2- un-define the default value and direction for each pin (ex: PORT_u8PIN_0_DEFAULT_VALUE & PORT_u8PIN_0_DEFAULT_DIR)
 * @n	3- re-define the default value and direction for each pin as stated in the configuration file
 * @n   4- If one of the pins is not configured correctly a warning message shall appear and then the default value of this pin shall be set to low and the direction to output.
 * @n	5- finally, using the CONC function each port shall be set with the corresponding values and directions previously set in the configuration file. (CONC function shall place the defined value in both DDRx and PORTx registers)
 *
 * \par Function sequence
 *
 *\callgraph
 *\callergraph
 *
 *@startuml
*start
*  - "Initialization"
*  - check for the initial value of the pins
*  - undef the default value and direction of all the pins
*  - set the default value and direction according to the initial mode configured in the cfg file
*
* if(one of the pins is not initialized correctly) then (yes)
*  - a warning message shall appear stating that initializing was done wrong
*  - its default value and direction are set to output low
*endif
*  - the values of DDRx and PORTx registers shall be concatenated first from the default values
*  - assign the concatenated values to the physical registers of DDRx and PORTx
*stop
*@enduml
 */





/***************************
 * Function Description : responsible for initializing all pins and ports to their operation mode and initial values.
 *
 *
 * Parameters : void
 *
 *
 * Return : void
 *
 * Example : Port_vidInit();
 *
 *
 ***************************/

void Port_vidInit(void);

/**
 * \par Req Id:
 * @n Req_PO1_DGC_CDD_PORT_002-V1.0
 *
 * \par Covers:
 * @n Req_PO1_DGC_GDD_PORT_002-V1.2
 *
 * \par Description
 * @n This function is used to change the Software pin Mode
 *
 * @param Input: Copy_u8SwPinNo , Copy_u8PinMode
 * @param Output: N/A
 * @param Input/Output: N/A
 * @return
 * @n - E_OK
 * @n - E_NOK
 *
 *\par Main Steps
 *@n	1- Determine the pin ID and the port ID from the the SW pin number passed to the function as a parameter.
 * @n	2- Using the PORT ID a switch case is made to assign the desired mode to the desired pin in the right port
 * @n	3- There are 4 modes in which a pin can be set to (output low, output high, input high impedance, input pull up).
 * @n   4- For the 2 output modes the DDR register is set to high at the bit corresponding to the pin ID, and the PORT register is set to 1 for HIGH and 0 for LOW.
 * @n	5- For the 2 input modes the DDR register is set to 0 at the bit corresponding to the pin ID, and the PORT register is set to 1 in case of PULL UP option and 0 for the HIGH IMPEDANCE option.
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
*  - Using switch case, switch on the port ID to start assigning the desired mode to the pin determined
*  - check for the mode parameter
*
* if(the mode is output high) then (yes)
*  - set the DDRx register to 1 at the bit corresponding to the Pin ID
*  - set the PORTx register to 1 at the bit corresponding to the Pin ID
*  else (no)
*   if(the mode is output low) then(yes)
*  - set the DDRx register to 1 at the bit corresponding to the Pin ID
*  - set the PORTx register to 0 at the bit corresponding to the Pin ID
*  else (no)
*  if(the mode is input high impedance) then (yes)
*  - set the DDRx register to 0 at the bit corresponding to the Pin ID
*  - set the PORTx register to 0 at the bit corresponding to the pin ID
*  else (no)
*  if(the mode is input pull up) then (yes)
*  - set the DDRx register to 0 at the bit corresponding to the Pin ID
*  - set the PORTx register to 1 at the bit corresponding to the Pin ID
*endif
*endif
*endif
*endif
*stop
*@enduml
 */





/***************************
 * Function Description : Set the mode for software pins
 *
 *
 * Parameters : u8 Copy_u8SwPinNo, u8 Copy_u8SwPinMode
 *
 *
 * Return : ReturnStatus_e
 *
 * Example : Port_vidSetPinMode(PORT_u8PIN_0, PORT_u8OUTPUT_HIGH);
 *
 *
 ***************************/
ReturnStatus_e Port_vidSetPinMode(u8 Copy_u8SwPinNo, u8 Copy_u8SwPinMode);

/**
 * \par Req Id:
 * @n Req_PO1_DGC_CDD_PORT_003-V1.0
 *
 * \par Covers:
 * @n Req_PO1_DGC_GDD_PORT_003-V1.2
 *
 * \par Description
 * @n This function is used to change the Software pin Mode
 *
 * @param Input: Copy_u8SwPinNo , Copy_u8PinDir
 * @param Output: N/A
 * @param Input/Output: N/A
 * @return
 * @n - E_OK
 * @n - E_NOK
 *
 *\par Main Steps
 *@n	1- Determine the pin ID and the port ID from the the SW pin number passed to the function as a parameter.
 * @n	2- Using the PORT ID a switch case is made to assign the desired mode to the desired pin in the right port
 * @n	3- There are 2 directions in which a pin can be changed to (output and input).
 * @n   4- For output direction of the desired pin the DDR register is set to high at the bit corresponding to the pin ID.
 * @n	5- For input direction of the desired pin the DDR register is set to 0 at the bit corresponding to the pin ID.
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
*  - check for the direction parameter
*
* if(the direction is output) then (yes)
*  - set the DDRx register to 1 at the bit corresponding to the Pin ID
*  else (no)
*   if(the direction is input) then(yes)
*  - set the DDRx register to 0 at the bit corresponding to the Pin ID
*endif
*endif
*stop
*@enduml
 */





/***************************
 * Function Description : Change the direction for software pins
 *
 *
 * Parameters : u8 Copy_u8SwPinNo, u8 Copy_u8SwPinDir
 *
 *
 * Return : ReturnStatus_e
 *
 * Example : Port_vidSetPinDir(PORT_u8PIN_0, PORT_u8OUTPUT);
 *
 *
 ***************************/
ReturnStatus_e Port_vidSetPinDir(u8 Copy_u8SwPinNo, u8 Copy_u8SwPinDir);

#endif /* PORT_INT_H_ */
