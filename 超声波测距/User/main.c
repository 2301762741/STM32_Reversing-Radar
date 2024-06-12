#include "stm32f10x.h"                  // Device header
#include "System.h"
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
#include "HCSR04.h"
#include "System.h"
#define GPint(a,b,c) GPint(a,b,c,GPIO_Speed_50MHz)

uint64_t numlen(uint64_t num)//计算数字的长度
{
    uint64_t len = 1;        // 初始长度为1
    for(; num > 9; ++len)    // 判断num是否大于9，否则长度+1
        num /= 10;	         // 使用除法进行运算，直到num小于1
    return len;              // 返回长度的值
}

int main(void)
{	
	OLED_Init();		//初始化OLED屏
	Timer_Init();		//初始化定时器
	HC_SR04_Init();		//初始化超声波测距模块
	
	GPint(GPA,OutPP,P9 |P4|P5|P6);	//电灯与蜂鸣器的初始化
	GPIO_ResetBits(GA,P4); GPIO_SetBits(GA,P6); //将蜂鸣器上电
	GPIO_SetBits(GA,P5|P9);   //蜂鸣器和灯上电高平
	
	OLED_ShowString(1, 1, "Distance:");		//OLED屏输出字符串
	
	while (1)
	{
		int Distance_mm=sonar_mm();			//获取距离测量结果，单位毫米（mm）		
		int Distance_m=Distance_mm/1000;	//转换为米（m）为单位，将整数部分放入Distance_m
		int Distance_m_p=Distance_mm%1000;	//转换为米（m）为单位，将小数部分放入Distance_m_p
		OLED_Clear_Part(2,1,16);			//将OLDE屏第2行清屏
		OLED_ShowNum(2, 1,Distance_m,numlen(Distance_m));	//显示测量结果的整数部分
		OLED_ShowChar(2, 1+numlen(Distance_m), '.');		//显示小数点
		if(Distance_m_p<100){								//判断是否小于100毫米
			OLED_ShowString(4,4,"BYD,STOP!!");
			GPIO_ResetBits(GA,P9|P5);

			OLED_ShowChar(2, 1+numlen(Distance_m)+1,'0');								//因为单位是米，所以小于10cm时要加0
			OLED_ShowNum(2, 1+numlen(Distance_m)+2,Distance_m_p,numlen(Distance_m_p));	//显示测量结果的小数部分
			OLED_ShowChar(2, 1+numlen(Distance_m)+2+numlen(Distance_m_p), 'm');			//显示单位
		}else																			
		{
			OLED_Clear_Part(4,1,16);
			GPIO_SetBits(GA,P9|P5);
			
			OLED_ShowNum(2, 1+numlen(Distance_m)+1,Distance_m_p,numlen(Distance_m_p));	//显示测量结果的小数部分
			OLED_ShowChar(2, 1+numlen(Distance_m)+1+numlen(Distance_m_p), 'm');			//显示单位
		}
		
		OLED_Clear_Part(3,1,16);			//将OLDE屏第3行清屏
		OLED_ShowNum(3, 1,Distance_mm,numlen(Distance_mm));		//显示单位为毫米的距离结果
		OLED_ShowString(3, 1 + numlen(Distance_mm), "mm");
		Delay_ms(300);						//延时300毫秒
	}
}
