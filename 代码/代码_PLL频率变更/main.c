#include "stm32f4xx.h"

GPIO_InitTypeDef GPIO_InitStructure;

void delay(void)
{
	uint32_t i=0x200000;
	
	while(i--);

}

int main(void)
{
	//ʹ�ܶ˿�A��Ӳ��ʱ�ӣ���������
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);	
	
	
	//ʹ�ܶ˿�E��Ӳ��ʱ�ӣ���������
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);	
	
	//ʹ�ܶ˿�F��Ӳ��ʱ�ӣ���������
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	
	
	//����PA0����
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;//��0������
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN;	//����
	//GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//��Ϊ����Ϊ����ģʽ��ʱ��������������ر�
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;//��ʹ������������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_2MHz;//�����ٶȵͣ�����Ҳ��
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	//����PE2~4�����ţ�
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_2;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//����PF9~PF10����
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9|GPIO_Pin_10;//��9 10������
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;	//���
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//����
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;//��ʹ������������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_2MHz;//�����ٶȵͣ�����Ҳ��
	GPIO_Init(GPIOF,&GPIO_InitStructure);
	
	//����PE13~PE14����
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13|GPIO_Pin_14;//��13 14������
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	
	
	//��ʼ��������ϣ�LED�Ƴ�ʼ״̬ΪϨ��
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
			
			RCC_PLLConfig(RCC_PLLSource_HSE,8,336,4,7);//PLL���Ƶ��84MHz
			
			RCC_PLLCmd(ENABLE);
			
			RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		}
		
		
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)==Bit_RESET)
		{
			RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI); 
	
			RCC_PLLCmd(DISABLE);
			
			RCC_PLLConfig(RCC_PLLSource_HSE,8,336,6,7);//PLL���Ƶ��56MHz
			
			RCC_PLLCmd(ENABLE);
			
			RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		}
		
		
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==Bit_RESET)
		{
			RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI); 
	
			RCC_PLLCmd(DISABLE);
			
			RCC_PLLConfig(RCC_PLLSource_HSE,8,336,8,7);//PLL���Ƶ��42MHz
			
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
