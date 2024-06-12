#include "stm32f10x.h"
uint32_t GPIO[]={RCC_APB2Periph_GPIOA,RCC_APB2Periph_GPIOC,RCC_APB2Periph_GPIOC,RCC_APB2Periph_GPIOC};

/**
  * @brief  GPIO��ʼ������
  * @param  ��һ������ΪGPIOѡ�񣬿�ѡΪ A,B,C,D;   
						�ڶ�������Ϊmodeģʽѡ�񣬿�ѡ OutPP���������OutOD��©��� ,IPD�������� ,IPU�������� 
						������Ϊ����ѡ�񣬿�P1~P13
  * @retval ��
  */
void GPint(uint32_t RCC_APB2Periph, GPIOMode_TypeDef GPIO_mode, uint16_t GPIO_Pin, GPIOSpeed_TypeDef GPIO_Speed)
	{
	/*GPIO_TypeDef* GPIO_k;
	switch(RCC_APB2Periph)
	{
		case RCC_APB2Periph_GPIOA: 
					GPIO_k=GPIOA;break;
		case RCC_APB2Periph_GPIOB:
					GPIO_k=GPIOB;break;
		case RCC_APB2Periph_GPIOC:
					GPIO_k=GPIOC;break;
		case RCC_APB2Periph_GPIOD: 
					GPIO_k=GPIOD;break;
	}*/

		
	/*����ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph, ENABLE);	//����GPIO C��A��ʱ��
															//ʹ�ø�������ǰ���뿪��ʱ�ӣ����������Ĳ�����Ч
	
	/*GPIO��ʼ��*/
	GPIO_InitTypeDef GPIO_InitStructure;					//����ṹ�����
	
	GPIO_InitStructure.GPIO_Mode = GPIO_mode;		//GPIOģʽ����ֵΪ�������ģʽ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;				//GPIO���ţ�������ֵΪ13,14������   
//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_ALL ;       //GPIO_Pin_ALL  ѡ������������1	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed;		//GPIO�ٶȣ���ֵΪ50MHz
	
	switch(RCC_APB2Periph)
	{
		case RCC_APB2Periph_GPIOA: 
					GPIO_Init(GPIOA, &GPIO_InitStructure);break;
		case RCC_APB2Periph_GPIOB:
					GPIO_Init(GPIOB, &GPIO_InitStructure);break;
		case RCC_APB2Periph_GPIOC:
					GPIO_Init(GPIOC, &GPIO_InitStructure);break;
		case RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB:
					GPIO_Init(GPIOA, &GPIO_InitStructure);
					GPIO_Init(GPIOB, &GPIO_InitStructure);
					break;
		case RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC:
					GPIO_Init(GPIOA, &GPIO_InitStructure);
					GPIO_Init(GPIOC, &GPIO_InitStructure);
					break;
		case RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC:
					GPIO_Init(GPIOB, &GPIO_InitStructure);
					GPIO_Init(GPIOC, &GPIO_InitStructure);
					break;
	
	//GPIO_Init(GPIO_k, &GPIO_InitStructure);					//����ֵ��Ĺ���������ݸ�GPIO_Init����
															//�����ڲ����Զ����ݽṹ��Ĳ���������Ӧ�Ĵ���
															//ʵ��GPIOC�ĳ�ʼ��
	
/***����GPIO���ŵĸߵ͵�ƽ���ģ��*****/
	/*��������GPIO���ŵĵ�ƽ������GPIO��ʼ��Ϊ�������������Pin��ָ�����ţ�c13,14��Ĭ������͵�ƽ��δָ�������ϵ�ߵ�ƽ��C15��*/
	}
}
