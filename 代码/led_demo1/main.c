#include "stm32f4xx.h"


GPIO_InitTypeDef GPIO_InitStructure;

//�����̣�����û�в���ϵͳ�ļӳ֣�
//main���������˳�
int main(void)
{
	//�򿪶˿�F�ĵ�Դ����,����ʹ�ܸö˿ڵ�Ӳ��ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	
	//���ö˿�F��9�����ţ�����Ϊ�������ģʽ
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;//9������
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
	
	
	
	}


}
