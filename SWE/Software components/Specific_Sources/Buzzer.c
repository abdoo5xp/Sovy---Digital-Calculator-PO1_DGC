/******************************************************/
/* Author       : Nihal Khaled                        */
/* Date         : 2 May 2021                          */
/* Component	: Buzzer				              */
/* Layer		: HAL						          */
/* Version      : V01                                 */
/******************************************************/

#undef F_CPU
#define F_CPU 	8000000

#include "../../lib/Std_Types.h"
#include "../../lib/Bit_Math.h"
#include"Port_int.h"
#include"Dio_int.h"
#include "INTGBL_int.h"
#include "Gpt_int.h"
#include "Buzzer_int.h"

static u8 BuzzerReloadVal = Reload_val;
static u8 BuzzerOverflowNum = Number_Overflow;
static u8 counter;
static void Buzzer_App();



u8 Buzzer_u8Init(){

	INT_voidEnableGlobal();
	Gpt_u8Init();
	Gpt_vidLoadTimer(Reload_val);
	Gpt_vidSetCBF(Buzzer_App);
	Gpt_vidEnableNotification();
    return E_OK;
}

u8 Buzzer_u8Start()
{
	Gpt_vidStartTimer();
	Dio_vidSetPinVal(Buzzer,DIO_u8HIGH);
    return E_OK;

}

static void Buzzer_App()
{

	counter++;
		if (counter == BuzzerOverflowNum)
		{
			Dio_vidSetPinVal(Buzzer,DIO_u8LOW);
			Gpt_vidStopTimer();
			Gpt_vidLoadTimer(BuzzerReloadVal);

			counter=0;
		}


}
