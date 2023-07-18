#include "stm32f10x.h"                  // Device header

/*** 
 * @description: PWM初始化
 * @return {*}
 */
void TIM2_PWM_Init(void);
/*** 
 * @description: 改变TIM2 PWM的CCR的值
 * @param {uint16_t} compare; 参数描述：CCR的值
 * @return {*}
 */
void TIM2_PWM_change(uint16_t compare);

void TIM2_PWM_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM2_InitStructure;
    GPIO_InitTypeDef GPIO_PWM_InitStructure;
    TIM_OCInitTypeDef TIM2_PWM_InitStructure;
    TIM_OCStructInit(&TIM2_PWM_InitStructure);

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_PWM_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_PWM_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_PWM_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_PWM_InitStructure);

    TIM_InternalClockConfig(TIM2);

    TIM2_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM2_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM2_InitStructure.TIM_Period = 99;
    TIM2_InitStructure.TIM_Prescaler = 719;
    TIM2_InitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &TIM2_InitStructure);
    

    TIM2_PWM_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM2_PWM_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM2_PWM_InitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM2_PWM_InitStructure.TIM_Pulse = 0;
    TIM_OC1Init(TIM2, &TIM2_PWM_InitStructure);

    TIM_Cmd(TIM2, ENABLE);
}

void TIM2_PWM_change(uint16_t compare)
{
	TIM_SetCompare1(TIM2, compare);
}
