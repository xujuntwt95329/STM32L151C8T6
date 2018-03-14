#ifndef __I2C_OLED_H
#define	__I2C_OLED_H

/**
		This file is used for OLED only
*/

#include "stm32l1xx_hal.h"

/*I2C接口*/
#define OLED_I2Cx                         I2C1
#define OLED_I2C_CLK                      RCC_APB1Periph_I2C1
#define OLED_I2C_CLK_INIT								  RCC_APB1PeriphClockCmd

#define OLED_I2C_SCL_PIN                  GPIO_Pin_6                 
#define OLED_I2C_SCL_GPIO_PORT            GPIOB                       
#define OLED_I2C_SCL_GPIO_CLK             RCC_AHB1Periph_GPIOB
#define OLED_I2C_SCL_SOURCE               GPIO_PinSource6
#define OLED_I2C_SCL_AF                   GPIO_AF_I2C1

#define OLED_I2C_SDA_PIN                  GPIO_Pin_7                  
#define OLED_I2C_SDA_GPIO_PORT            GPIOB                       
#define OLED_I2C_SDA_GPIO_CLK             RCC_AHB1Periph_GPIOB
#define OLED_I2C_SDA_SOURCE               GPIO_PinSource7
#define OLED_I2C_SDA_AF                   GPIO_AF_I2C1



/* STM32 I2C 快速模式 */
#define I2C_Speed              400000  //*

/* 这个地址只要与STM32外挂的I2C器件地址不一样即可 */
#define I2Cx_OWN_ADDRESS7      0X0A   


/*信息输出*/
#define OLED_DEBUG_ON         0

#define OLED_INFO(fmt,arg...)           printf("<<-OLED-INFO->> "fmt"\n",##arg)
#define OLED_ERROR(fmt,arg...)          printf("<<-OLED-ERROR->> "fmt"\n",##arg)
#define OLED_DEBUG(fmt,arg...)          do{\
                                          if(OLED_DEBUG_ON)\
                                          printf("<<-OLED-DEBUG->> [%d]"fmt"\n",__LINE__, ##arg);\
                                          }while(0)

#define OLED_ADDRESS	0x78 
//#define OLED_ADDRESS	0x7A 

void OLED_Test(void);
void I2C_WriteByte(uint8_t addr,uint8_t data);
void WriteCmd(unsigned char I2C_Command);
void WriteDat(unsigned char I2C_Data);
void OLED_Init(void);
void OLED_SetPos(unsigned char x, unsigned char y);
void OLED_Fill(unsigned char fill_Data);
void OLED_CLS(void);
void OLED_ON(void);
void OLED_OFF(void);
void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize);
void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N);
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);

#endif /* __I2C_OLED_H */
