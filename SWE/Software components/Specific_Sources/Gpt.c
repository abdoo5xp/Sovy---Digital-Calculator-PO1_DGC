#include "../../lib/Std_Types.h"
#include "../../lib/Bit_Math.h"
#include"../../lib/Atmega32_Registers.h"
#include "Gpt_cfg.h"
#include "Gpt_int.h"
#include "Gpt_pri.h"



typedef void (* CallBackFunc) (void);

static CallBackFunc Timer_CompInt_Cbkfn;
static CallBackFunc Timer_OvfInt_Cbkfn;



u8 Gpt_u8Init(void)
{

	TCCR0.Byte &= (TIMER0_MODE_MASK |TIMER0_COMPARE_OUTPUT_MASK);
	TCCR0.Byte |= (TIMER0_MODE |TIMER0_OUTPUTCOMPARE_MODE);
    return E_OK;
}

void Gpt_vidStartTimer(void)
{

	TCCR0.Byte &= TIMER0_CLK_MASK;
	TCCR0.Byte |= TIMER0_CLOCK_PRESC_SELECTION ;

}

void Gpt_vidStopTimer(void){

	    TCCR0.Bits.Bit0=(TIMER0_CLK_STOP& 0x01);
		TCCR0.Bits.Bit1=((TIMER0_CLK_STOP & 0x02)>>1);
		TCCR0.Bits.Bit2=((TIMER0_CLK_STOP & 0x02)>>2);
}


void Gpt_vidLoadTimer(u8 Copy_u8Value)
{
	TCNT0.Byte=Copy_u8Value;
}

void Gpt_vidEnableNotification(void)
{
	TIMSK.Byte|=TIMER0_INTERRUPT_OVER_FLOW;

}


void Gpt_vidDisbleNotification(void){
	TIMSK.Byte &= ~TIMER0_INTERRUPT_OVER_FLOW;
}


u8 Gpt_vidSetCBF(CallBackFunc Add_Cbkfn){
	u8 Loc_u8Ret=E_NOK;
	if(Add_Cbkfn!=0){
		Timer_OvfInt_Cbkfn=Add_Cbkfn;
		Loc_u8Ret=E_OK;
	}
	return Loc_u8Ret;
}

// Timer/Counter0 Compare Match isr (10)
void __vector_10 (void){
	if(Timer_CompInt_Cbkfn!=0){
		Timer_CompInt_Cbkfn();
	}
}
// Timer/Counter0 Overflow isr (11)
void __vector_11 (void){
	if(Timer_OvfInt_Cbkfn!=0){
		Timer_OvfInt_Cbkfn();
	}
}



