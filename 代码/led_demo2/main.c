#include "stm32f4xx.h"

#define RCC_AHB1ENR  	(*(volatile uint32_t *)RCC_BASE+0x30)
	
#define GPIO_MODER   	(*(volatile uint32_t *)GPIOF_BASE+0x00)
#define GPIO_OTYPER   	(*(volatile uint32_t *)GPIOF_BASE+0x04)
#define GPIO_OSPEEDR   	(*(volatile uint32_t *)GPIOF_BASE+0x08)	
#define GPIO_PUPDR   	(*(volatile uint32_t *)GPIOF_BASE+0x0C)
#define GPIO_BSRRL   	(*(volatile uint32_t *)GPIOF_BASE+0x18)	
#define GPIO_BSRRH   	(*(volatile uint32_t *)GPIOF_BASE+0x1A)	
	
	
//裸机编程（就是没有操作系统的加持）
//main函数不能退出
int main(void)
{
	//打开端口F的电源供电,就是使能该端口的硬件时钟
	RCC_AHB1ENR|=1<<5;
	
	
	while(1)
	{
	
	
	
	}


}
