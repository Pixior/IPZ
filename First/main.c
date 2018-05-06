#include "stm32f10x.h"                  // Device header

//inicjalizacja zegarów w system_stm32f10x.c - wybor ok. 110 linii
//aktualnie taktowanie procesora ustawione na:	24MHz

int main(void){
		
	RCC->APB2ENR = RCC_APB2ENR_IOPBEN;		//zalaczenie zegara do PB

	GPIOB->CRH |= GPIO_CRH_MODE12_0;		//OUTPUT 10MHz max
	GPIOB->CRH &= ~GPIO_CRH_CNF12_0;		//GPIO push-pull

	SysTick_Config(1000000 * 3);		//SysTick jest 24-bitowy!
	SysTick->CTRL &= ~SysTick_CTRL_CLKSOURCE_Msk;		//Zmniejszenie taktowania do AHB/8
	
	while(1)
	{			//kod dzialajacy w petli
		
	}
} /* main */

void SysTick_Handler(void) __irq {		//przerwanie wykonuje sie co 1 s i zmienia stan diody na przeciwny
	
	GPIOB->ODR ^= GPIO_ODR_ODR12;  //PB12 toggle	
}

