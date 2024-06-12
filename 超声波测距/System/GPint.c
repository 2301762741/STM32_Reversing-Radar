#include "stm32f10x.h"
uint32_t GPIO[]={RCC_APB2Periph_GPIOA,RCC_APB2Periph_GPIOC,RCC_APB2Periph_GPIOC,RCC_APB2Periph_GPIOC};

/**
  * @brief  GPIO初始化函数
  * @param  第一个参数为GPIO选择，可选为 A,B,C,D;   
						第二个参数为mode模式选择，可选 OutPP推挽输出，OutOD开漏输出 ,IPD下拉输入 ,IPU上拉输入 
						第三个为引脚选择，可P1~P13
  * @retval 无
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

		
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph, ENABLE);	//开启GPIO C与A的时钟
															//使用各个外设前必须开启时钟，否则对外设的操作无效
	
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;					//定义结构体变量
	
	GPIO_InitStructure.GPIO_Mode = GPIO_mode;		//GPIO模式，赋值为推挽输出模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;				//GPIO引脚，批量赋值为13,14号引脚   
//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_ALL ;       //GPIO_Pin_ALL  选择所有引脚置1	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed;		//GPIO速度，赋值为50MHz
	
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
	
	//GPIO_Init(GPIO_k, &GPIO_InitStructure);					//将赋值后的构体变量传递给GPIO_Init函数
															//函数内部会自动根据结构体的参数配置相应寄存器
															//实现GPIOC的初始化
	
/***设置GPIO引脚的高低电平输出模块*****/
	/*若不设置GPIO引脚的电平，则在GPIO初始化为推挽输出后，上面Pin口指定引脚（c13,14）默认输出低电平，未指定的则上电高电平（C15）*/
	}
}
