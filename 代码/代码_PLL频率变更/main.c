#include "stm32f4xx.h"

GPIO_InitTypeDef GPIO_InitStructure;

void delay(void)
{
	uint32_t i=0x200000;
	
	while(i--);

}

int main(void)
{
	//使能端口A的硬件时钟，对它供电
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);	
	
	
	//使能端口E的硬件时钟，对它供电
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);	
	
	//使能端口F的硬件时钟，对它供电
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	
	
	//配置PA0引脚
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;//第0根引脚
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN;	//输入
	//GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//因为配置为输入模式的时候，输出缓冲器被关闭
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;//不使能上下拉电阻
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_2MHz;//工作速度低，功耗也低
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	//配置PE2~4号引脚）
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_2;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//配置PF9~PF10引脚
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9|GPIO_Pin_10;//第9 10根引脚
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;	//输出
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//推挽
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;//不使能上下拉电阻
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_2MHz;//工作速度低，功耗也低
	GPIO_Init(GPIOF,&GPIO_InitStructure);
	
	//配置PE13~PE14引脚
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13|GPIO_Pin_14;//第13 14根引脚
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	
	
	//初始化引脚完毕，LED灯初始状态为熄灭
	GPIO_SetBits(GPIOF,GPIO_Pin_9|GPIO_Pin_10);
	GPIO_SetBits(GPIOE,GPIO_Pin_13|GPIO_Pin_14);


	RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI); 
	
	RCC_PLLCmd(DISABLE);
	
	RCC_PLLConfig(RCC_PLLSource_HSE,8,336,2,7);
	
	RCC_PLLCmd(ENABLE);
	
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK); 	
	
	while(1)
	{
		
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==Bit_RESET)
		{
			RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI); 
	
			RCC_PLLCmd(DISABLE);
			
			RCC_PLLConfig(RCC_PLLSource_HSE,8,336,4,7);//PLL输出频率84MHz
			
			RCC_PLLCmd(ENABLE);
			
			RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		}
		
		
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)==Bit_RESET)
		{
			RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI); 
	
			RCC_PLLCmd(DISABLE);
			
			RCC_PLLConfig(RCC_PLLSource_HSE,8,336,6,7);//PLL输出频率56MHz
			
			RCC_PLLCmd(ENABLE);
			
			RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		}
		
		
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==Bit_RESET)
		{
			RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI); 
	
			RCC_PLLCmd(DISABLE);
			
			RCC_PLLConfig(RCC_PLLSource_HSE,8,336,8,7);//PLL输出频率42MHz
			
			RCC_PLLCmd(ENABLE);
			
			RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		}
		
		
		
		
		GPIO_WriteBit(GPIOF, GPIO_Pin_9, Bit_RESET);
		
		delay();
		
		
		GPIO_WriteBit(GPIOF, GPIO_Pin_9, Bit_SET);
		delay();
		
		
		
		GPIO_WriteBit(GPIOF, GPIO_Pin_10, Bit_RESET);
		delay();
		GPIO_WriteBit(GPIOF, GPIO_Pin_10, Bit_SET);
		delay();
		
		
		GPIO_WriteBit(GPIOE, GPIO_Pin_13, Bit_RESET);
		delay();
		
		GPIO_WriteBit(GPIOE, GPIO_Pin_13, Bit_SET);
		delay();
		
		
		GPIO_WriteBit(GPIOE, GPIO_Pin_14, Bit_RESET);
		delay();
		
		GPIO_WriteBit(GPIOE, GPIO_Pin_14, Bit_SET);
		delay();
		
		
	
	}
}
