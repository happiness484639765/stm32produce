#include "stm32f4xx.h"


GPIO_InitTypeDef GPIO_InitStructure;

//裸机编程（就是没有操作系统的加持）
//main函数不能退出
int main(void)
{
	//打开端口F的电源供电,就是使能该端口的硬件时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	
	//配置端口F的9号引脚，配置为推挽输出模式
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;//9号引脚
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;//输出模式
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//推挽 Push Pull；开漏 Open Drain
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;//不使能上下拉电阻
	GPIO_InitStructure.GPIO_Speed=GPIO_Low_Speed;//低速，功耗低，但是引脚响应时间更长
	GPIO_Init(GPIOF,&GPIO_InitStructure);
	
	
	//控制端口F的9号引脚输出相应的电平（高电平/低电平）
	//GPIO_WriteBit(GPIOF,GPIO_Pin_9,Bit_RESET); //点灯

	GPIO_WriteBit(GPIOF,GPIO_Pin_9,Bit_SET); //灭灯	
	
	while(1)
	{
	
	
	
	}


}
