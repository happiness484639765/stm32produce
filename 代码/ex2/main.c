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
	//�򿪶˿�A F�ĵ�Դ����,����ʹ�ܸö˿ڵ�Ӳ��ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);

	//���ö˿�A��0 �����ţ�����Ϊ����ģʽ
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;//0 ������
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN;//����ģʽ
	//GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//������Ϊ����ģʽ���������/��©���������Ч
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;//��ʹ������������
	GPIO_InitStructure.GPIO_Speed=GPIO_Low_Speed;//���٣����ĵͣ�����������Ӧʱ�����
	GPIO_Init(GPIOA,&GPIO_InitStructure);	
	
	//���ö˿�F��9 �����ţ�����Ϊ�������ģʽ
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;//9 ������
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;//���ģʽ
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//���� Push Pull����© Open Drain
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;//��ʹ������������
	GPIO_InitStructure.GPIO_Speed=GPIO_Low_Speed;//���٣����ĵͣ�����������Ӧʱ�����
	GPIO_Init(GPIOF,&GPIO_InitStructure);
	
	
	//���ƶ˿�F��9�����������Ӧ�ĵ�ƽ���ߵ�ƽ/�͵�ƽ��
	//GPIO_WriteBit(GPIOF,GPIO_Pin_9,Bit_RESET); //���

	GPIO_WriteBit(GPIOF,GPIO_Pin_9,Bit_SET); //���	


	while(1)
	{
		if(Bit_RESET==GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0))
		{
			GPIO_WriteBit(GPIOF,GPIO_Pin_9,Bit_RESET);
		}
		else
		{
			GPIO_WriteBit(GPIOF,GPIO_Pin_9,Bit_SET);
		
		}

	
	}


}
