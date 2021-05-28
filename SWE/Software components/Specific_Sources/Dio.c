#include <stdio.h>
#include "Std_Types.h"
#include "BIT_math.h"
#include "ATmega32_Registers2.h"

#include "Dio_int.h"

ReturnStatus_e Dio_u8SetPinVal(u8 Copy_u8SwPinNo, u8 Copy_u8SwPinVal)
{
	ReturnStatus_e ReturnValue = E_OK;

	u8 Loc_u8PortId;
	u8 Loc_u8PinId;

	Loc_u8PortId = Copy_u8SwPinNo / 8;
	Loc_u8PinId = Copy_u8SwPinNo % 8;

	switch(Loc_u8PortId)
	{
	case 0: //PORTA
		if(Copy_u8SwPinVal == DIO_u8HIGH)
		{
			SET_BIT(PORTA, Loc_u8PinId);

		}
		else
		{
			CLR_BIT(PORTA, Loc_u8PinId);
		}
		break;

	case 1: //PORTB
		if(Copy_u8SwPinVal == DIO_u8HIGH)
		{
			SET_BIT(PORTB, Loc_u8PinId);
		}
		else
		{
			CLR_BIT(PORTB, Loc_u8PinId);
		}
		break;

	case 2: //PORTC
		if(Copy_u8SwPinVal == DIO_u8HIGH)
		{
			SET_BIT(PORTC, Loc_u8PinId);
		}
		else
		{
			CLR_BIT(PORTC, Loc_u8PinId);
		}
		break;

	case 3: //PORTD
		if(Copy_u8SwPinVal == DIO_u8HIGH)
		{
			SET_BIT(PORTD, Loc_u8PinId);
		}
		else
		{
			CLR_BIT(PORTD, Loc_u8PinId);
		}
		break;

	default:
		ReturnValue = E_NOK;
		break;
	}

	return ReturnValue;

}
u8 Dio_u8GetPinVal(u8 Copy_u8SwPinNo)
{
	u8 Loc_u8PortId;
		u8 Loc_u8PinId;
		u8 Loc_u8PinVal;

		Loc_u8PortId = Copy_u8SwPinNo / 8;
		Loc_u8PinId = Copy_u8SwPinNo % 8;

		switch(Loc_u8PortId)
		{
		case 0: //PORTA
			Loc_u8PinVal = GET_BIT(PINA, Loc_u8PinId);
			break;

		case 1: //PORTB
			Loc_u8PinVal = GET_BIT(PINB, Loc_u8PinId);
			break;

		case 2: //PORTC
			Loc_u8PinVal = GET_BIT(PINC, Loc_u8PinId);
			break;

		case 3: //PORTD
			Loc_u8PinVal = GET_BIT(PIND, Loc_u8PinId);
			break;

		default:
			break;
		}

		return Loc_u8PinVal;


}

