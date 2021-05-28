#ifndef DATA_TYPES_H_
#define DATA_TYPES_H_


/** @struct Keypad_Manager_s
 *  	@brief This structure contain the entered operands and operation and their numbers.
 * @param Operands[4]
 *  	@n Contain the enterted operands.
 * @param Operations[3]
 *  	@n Contain the enterted operations.
 *  @param NumOfOperands
 *  	@n Contain the nubmer of operands.
 *  @param NumOfOperations
 *  	@n Contain the nubmer of operations.
 *  @param Status_Flag
 *  	@n Contains the status of the equal if repeated or not, based on it will take actions in Operation_Manager.
 */

typedef struct{
	s16 Operands[4];
	u8 Operations[3];
	u8 NumOfOperands;
	u8 NumOfOperations;
    u8 Status_Flag; 
	//status flag to know if operation manager will add the old result to the struct or not befor sending it to the Math cal
}Keypad_Manager_s;

#endif //DATA_TYPES
