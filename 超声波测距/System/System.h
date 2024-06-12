#ifndef __DELAY_H
#define __DELAY_H

//#define GPint(a,b,c) GPint(a,b,c,GPIO_Speed_50MHz)
#define GPA RCC_APB2Periph_GPIOA 
#define GPB RCC_APB2Periph_GPIOB 
#define GPC RCC_APB2Periph_GPIOC 
//#define GPD RCC_APB2Periph_GPIOD 
#define GA GPIOA
#define GB GPIOB
#define GC GPIOC
//#define GD GPIOD
#define OutPP GPIO_Mode_Out_PP
#define OutOD  GPIO_Mode_Out_OD 
#define AIN  GPIO_Mode_AIN 
#define InFLOATING  GPIO_Mode_IN_FLOATING 
#define IPD GPIO_Mode_IPD 
#define IPU GPIO_Mode_IPU 
#define AfOD GPIO_Mode_AF_OD 
#define AfPP  GPIO_Mode_AF_PP 
//#define Bit_RESET 0
//#define Bit_SET 1
#define P15 GPIO_Pin_15 
#define P14 GPIO_Pin_14 
#define P13 GPIO_Pin_13 
#define P12 GPIO_Pin_12 
#define P11 GPIO_Pin_11 
#define P10 GPIO_Pin_10 
#define P9 GPIO_Pin_9 
#define P8 GPIO_Pin_8 
#define P7 GPIO_Pin_7 
#define P6 GPIO_Pin_6 
#define P5 GPIO_Pin_5 
#define P4 GPIO_Pin_4 
#define P3 GPIO_Pin_3 
#define P2 GPIO_Pin_2 
#define P1 GPIO_Pin_1 
#define P0 GPIO_Pin_0 

/*********GPOIO**********/
void GPint(uint32_t RCC_APB2Periph, GPIOMode_TypeDef GPIO_mode, uint16_t GPIO_Pin, GPIOSpeed_TypeDef GPIO_Speed);

/*********EXTI**********/
void EXTIint(void);
uint16_t EXTI_Get(void);

/*********Delay**********/
void Delay_us(uint32_t us);
void Delay_ms(uint32_t ms);
void Delay_s(uint32_t s);

/*********oled**********/
void OLED_Init(void);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

#endif
