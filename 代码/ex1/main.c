#include "stm32f4xx.h"


GPIO_InitTypeDef GPIO_InitStructure;


//�����ʱ
void delay(void)
{
	uint32_t i=0x500000;
	
	while(i--);
}

//�����̣�����û�в���ϵͳ�ļӳ֣�
//main���������˳�
int main(void)
{
	//�򿪶˿�E F�ĵ�Դ����,����ʹ�ܸö˿ڵ�Ӳ��ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);	
	
	//���ö˿�F��9 10�����ţ�����Ϊ�������ģʽ
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9|GPIO_Pin_10;//9 10������
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;//���ģʽ
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//���� Push Pull����© Open Drain
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;//��ʹ������������
	GPIO_InitStructure.GPIO_Speed=GPIO_Low_Speed;//���٣����ĵͣ�����������Ӧʱ�����
	GPIO_Init(GPIOF,&GPIO_InitStructure);
	
	//���ö˿�E��13 14�����ţ�����Ϊ�������ģʽ
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13|GPIO_Pin_14;//13 14������
	GPIO_Init(GPIOE,&GPIO_InitStructure);

	
	//���ƶ˿�F��9�����������Ӧ�ĵ�ƽ���ߵ�ƽ/�͵�ƽ��
	//GPIO_WriteBit(GPIOF,GPIO_Pin_9,Bit_RESET); //���

	GPIO_WriteBit(GPIOF,GPIO_Pin_9,Bit_SET); //���	
	GPIO_WriteBit(GPIOF,GPIO_Pin_10,Bit_SET); //���	

	GPIO_WriteBit(GPIOE,GPIO_Pin_13,Bit_SET); //���	
	GPIO_WriteBit(GPIOE,GPIO_Pin_14,Bit_SET); //���

	while(1)
	{
	
		GPIO_WriteBit(GPIOF,GPIO_Pin_9,Bit_RESET); //���
		delay();
		GPIO_WriteBit(GPIOF,GPIO_Pin_9,Bit_SET);   //���	
		delay();
		
		GPIO_WriteBit(GPIOF,GPIO_Pin_10,Bit_RESET); //���
		delay();
		GPIO_WriteBit(GPIOF,GPIO_Pin_10,Bit_SET);   //���	
		delay();		
		
		GPIO_WriteBit(GPIOE,GPIO_Pin_13,Bit_RESET); //���
		delay();
		GPIO_WriteBit(GPIOE,GPIO_Pin_13,Bit_SET);   //���	
		delay();

		GPIO_WriteBit(GPIOE,GPIO_Pin_14,Bit_RESET); //���
		delay();
		GPIO_WriteBit(GPIOE,GPIO_Pin_14,Bit_SET);   //���	
		delay();		
	}


}
