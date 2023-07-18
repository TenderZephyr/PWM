#include "stm32f10x.h"                  // Device header//
#include "PWM.h"
#include "Delay.h"

int main(void)
{
	uint8_t i;

	TIM2_PWM_Init();

	while (1){
		for (i = 0; i < 100; i++){
			TIM2_PWM_change(i);
			Delay_ms(10);
		}
		for (i = 0; i < 100; i++){
			TIM2_PWM_change(100 - i);
			Delay_ms(10); 
		}
	}
}
