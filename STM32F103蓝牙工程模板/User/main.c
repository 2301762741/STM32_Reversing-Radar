#include <string.h>
#include "stm32f10x.h"                  // Device header
#include "System.h"


uint16_t num=0;
uint8_t zu[]={0x09,'A','B'};

char RxData[100];   //数据缓存

 // GPint(GPB,OutOD,P6);												//GPIO初始化
 //	GPIO_SetBits(GPIOC, GPIO_Pin_13);						//将PC13引脚设置为高电平
 // GPIO_ResetBits(GPIOC, GPIO_Pin_13);						//将PC13引脚设置为低电平
 //	GPIO_WriteBit(GPIOC, GPIO_Pin_14,0);
 //	GPIO_Write(GPIOA,0x0001);                     //将A整块寄存器地址设置 （上面引脚选择应为GPIO_Pin_ALL）
int main(void)
{
	OLED_Init();
	//OLED_Clear();
	//OLED_ShowString(1,7,"OLED");

	
//	USEint();
	HCint();   
	USE_SendString("OK!");
	
	//MyI2C_Init();
	//MySPI_Init();
	
	
	//Music_TIM();

		
	while (1)
	{
		//USE_SendByte(0x01);   //发送一个数据
		//USE_SendPacket(zu,sizeof(zu)/sizeof(zu[0])); //发送数据包,以FF开头，FE结尾
		//Delay_ms(500);

		HC_GetData(RxData);    //获取蓝牙串口数据     
		num=HC_Orde(RxData);     //使用蓝牙命令控制
//		__WFI();  //睡眠中断唤醒模式	
		//if(num == 1)
		//	huxiLED();
		
 		

	///MusicTm();
	
//		IWDGint(IWDG_Prescaler_16,2499);             //设置1000ms的喂狗时长  T=0.025ms * Prescaler * ('Reload'+1)
//		Delay_ms(1200);								//设置喂狗间隔800ms
//		IWDG_ReloadCounter();					//重装计数器，喂狗
//		OLED_ShowString(1,7,"wLED");

			
	}	
	
}

//void TIM2_IRQHandler(void)
//{
//	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
//	{
//		num++;
//		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//	}
//}


