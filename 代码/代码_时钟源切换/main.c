#include "stm32f4xx.h"                  // Device header


GPIO_InitTypeDef GPIO_InitStruct;

void delay(uint32_t time)
{
	uint32_t count = time; 
	while(count--);
}


int main(void)
{
	uint32_t i=0;
	// Enable the GPIO AHB clock using the following function
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
	 // Configure the GPIO pin(s) using GPIO_Init()
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10; // 9 10 号引脚
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;	// 输入模式
	GPIO_InitStruct.GPIO_Speed =  GPIO_Low_Speed; // 速度为低速，功耗更低
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;	// 推挽输出 Pull Push
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL; // 不需要配置上下拉电阻
	GPIO_Init(GPIOF, &GPIO_InitStruct);	// 初始化引脚
	
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14; 
	GPIO_Init(GPIOE, &GPIO_InitStruct);
	
	
//	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2| GPIO_Pin_3 |GPIO_Pin_4; 
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
//	GPIO_InitStruct.GPIO_Speed =  GPIO_Low_Speed;
//	GPIO_Init(GPIOE, &GPIO_InitStruct);
	
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOA, &GPIO_InitStruct);	// 初始化引脚
	
	
	
	// 配置完输出模式后，每个引脚都要有一个初始电平的状态
	GPIO_WriteBit(GPIOF, GPIO_Pin_9, Bit_SET);
	GPIO_WriteBit(GPIOF, GPIO_Pin_10, Bit_SET);
	GPIO_WriteBit(GPIOE, GPIO_Pin_13, Bit_SET);
	GPIO_WriteBit(GPIOE, GPIO_Pin_14, Bit_SET);
	
	
	while(1)
	{
		
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==Bit_RESET)
		{
			i++;
			
			if(i==1)RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI);
			if(i==2)RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE);					
			if(i==3)RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);		

			if(i>=3)
				i=0;
		}
		
		GPIO_WriteBit(GPIOF, GPIO_Pin_9, Bit_RESET);
		
		delay(0x200000);
		
		
		GPIO_WriteBit(GPIOF, GPIO_Pin_9, Bit_SET);
		delay(0x200000);
		
		
		
		GPIO_WriteBit(GPIOF, GPIO_Pin_10, Bit_RESET);
		delay(0x200000);
		GPIO_WriteBit(GPIOF, GPIO_Pin_10, Bit_SET);
		delay(0x200000);
		
		
		GPIO_WriteBit(GPIOE, GPIO_Pin_13, Bit_RESET);
		delay(0x200000);
		
		GPIO_WriteBit(GPIOE, GPIO_Pin_13, Bit_SET);
		delay(0x200000);
		
		
		GPIO_WriteBit(GPIOE, GPIO_Pin_14, Bit_RESET);
		delay(0x200000);
		
		GPIO_WriteBit(GPIOE, GPIO_Pin_14, Bit_SET);
		delay(0x200000);
		
		
	
	}
	
}
