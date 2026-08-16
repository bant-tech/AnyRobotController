#ifndef __LED_H
#define	__LED_H

#include "stm32h7xx.h"


// LED1
#define LED1_PIN                  GPIO_PIN_8               
#define LED1_GPIO_PORT            GPIOE                      
#define LED1_GPIO_CLK_ENABLE()    __GPIOE_CLK_ENABLE()

// LED2
#define LED2_PIN                  GPIO_PIN_9                 
#define LED2_GPIO_PORT            GPIOE                     
#define LED2_GPIO_CLK_ENABLE()    __GPIOE_CLK_ENABLE()

// LED3
#define LED3_PIN                  GPIO_PIN_10                 
#define LED3_GPIO_PORT            GPIOE                 
#define LED3_GPIO_CLK_ENABLE()    __GPIOE_CLK_ENABLE()

// LED4
#define LED4_PIN                  GPIO_PIN_11                 
#define LED4_GPIO_PORT            GPIOE                       
#define LED4_GPIO_CLK_ENABLE()    __GPIOE_CLK_ENABLE()

// LED5
#define LED5_PIN                  GPIO_PIN_12               
#define LED5_GPIO_PORT            GPIOE                      
#define LED5_GPIO_CLK_ENABLE()    __GPIOE_CLK_ENABLE()

// LED6
#define LED6_PIN                  GPIO_PIN_13                 
#define LED6_GPIO_PORT            GPIOE                     
#define LED6_GPIO_CLK_ENABLE()    __GPIOE_CLK_ENABLE()

// LED7
#define LED7_PIN                  GPIO_PIN_14                 
#define LED7_GPIO_PORT            GPIOE                 
#define LED7_GPIO_CLK_ENABLE()    __GPIOE_CLK_ENABLE()

// LED8
#define LED8_PIN                  GPIO_PIN_15                 
#define LED8_GPIO_PORT            GPIOE                       
#define LED8_GPIO_CLK_ENABLE()    __GPIOE_CLK_ENABLE()


//ETH_RST
#define ETH_RST                  GPIO_PIN_0                 
#define ETH_RST_GPIO_PORT            GPIOC                       
#define ETH_RST_GPIO_CLK_ENABLE()    __GPIOC_CLK_ENABLE()
/************************************************************/



#define OFF  GPIO_PIN_RESET
#define ON GPIO_PIN_SET


#define LED1(a)	HAL_GPIO_WritePin(LED1_GPIO_PORT,LED1_PIN,a)

#define LED2(a)	HAL_GPIO_WritePin(LED2_GPIO_PORT,LED2_PIN,a)

#define LED3(a)	HAL_GPIO_WritePin(LED3_GPIO_PORT,LED3_PIN,a)

#define LED4(a)	HAL_GPIO_WritePin(LED4_GPIO_PORT,LED4_PIN,a)

#define LED5(a)	HAL_GPIO_WritePin(LED5_GPIO_PORT,LED1_PIN,a)

#define LED6(a)	HAL_GPIO_WritePin(LED6_GPIO_PORT,LED2_PIN,a)

#define LED7(a)	HAL_GPIO_WritePin(LED7_GPIO_PORT,LED3_PIN,a)

#define LED8(a)	HAL_GPIO_WritePin(LED8_GPIO_PORT,LED4_PIN,a)

#define	digitalHi(p,i)				{p->BSRR=i;}			  //����Ϊ�ߵ�ƽ		
#define digitalLo(p,i)				{p->BSRR=i<<16;}				//����͵�ƽ
#define digitalToggle(p,i)		{p->ODR ^=i;}			//�����ת״̬



#define LED1_TOGGLE		digitalToggle(LED1_GPIO_PORT,LED1_PIN)
#define LED1_ON			digitalHi(LED1_GPIO_PORT,LED1_PIN)
#define LED1_OFF				digitalLo(LED1_GPIO_PORT,LED1_PIN)

#define LED2_TOGGLE		digitalToggle(LED2_GPIO_PORT,LED2_PIN)
#define LED2_ON			digitalHi(LED2_GPIO_PORT,LED2_PIN)
#define LED2_OFF				digitalLo(LED2_GPIO_PORT,LED2_PIN)

#define LED3_TOGGLE		digitalToggle(LED3_GPIO_PORT,LED3_PIN)
#define LED3_ON			digitalHi(LED3_GPIO_PORT,LED3_PIN)
#define LED3_OFF				digitalLo(LED3_GPIO_PORT,LED3_PIN)

#define LED4_TOGGLE		digitalToggle(LED4_GPIO_PORT,LED4_PIN)
#define LED4_ON			digitalHi(LED4_GPIO_PORT,LED4_PIN)
#define LED4_OFF				digitalLo(LED4_GPIO_PORT,LED4_PIN)

#define LED5_TOGGLE		digitalToggle(LED5_GPIO_PORT,LED5_PIN)
#define LED5_ON			digitalHi(LED5_GPIO_PORT,LED5_PIN)
#define LED5_OFF				digitalLo(LED5_GPIO_PORT,LED5_PIN)

#define LED6_TOGGLE		digitalToggle(LED2_GPIO_PORT,LED2_PIN)
#define LED6_ON			digitalHi(LED6_GPIO_PORT,LED6_PIN)
#define LED6_OFF				digitalLo(LED6_GPIO_PORT,LED6_PIN)

#define LED7_TOGGLE		digitalToggle(LED7_GPIO_PORT,LED7_PIN)
#define LED7_ON			digitalHi(LED7_GPIO_PORT,LED7_PIN)
#define LED7_OFF				digitalLo(LED7_GPIO_PORT,LED7_PIN)

#define LED8_TOGGLE		digitalToggle(LED8_GPIO_PORT,LED8_PIN)
#define LED8_ON			digitalHi(LED8_GPIO_PORT,LED8_PIN)
#define LED8_OFF				digitalLo(LED8_GPIO_PORT,LED8_PIN)

#define ETH_RST_TOGGLE		digitalToggle(ETH_RST_GPIO_PORT,ETH_RST)
#define ETH_RST_ON			digitalHi(ETH_RST_GPIO_PORT,ETH_RST)
#define ETH_RST_OFF				digitalLo(ETH_RST_GPIO_PORT,ETH_RST)


#define LED_ALLON	\
					LED1_ON;\
					LED2_ON\
					LED3_ON\
					LED4_ON\
					LED5_ON\
					LED6_ON\
					LED7_ON\
					LED8_ON
					

#define LED_ALLOFF	\
					LED1_OFF;\
					LED2_OFF\
					LED3_OFF\
					LED4_OFF\
					LED5_OFF\
					LED6_OFF\
					LED7_OFF\
					LED8_OFF

#define LED_ALLTOGGLE \
					LED1_TOGGLE;\
					LED2_TOGGLE\
					LED3_TOGGLE\
					LED4_TOGGLE


/*******************************************************/
#define KEY1_PIN                  GPIO_PIN_0                 
#define KEY1_GPIO_PORT            GPIOD                      
#define KEY1_GPIO_CLK_ENABLE()    __GPIOD_CLK_ENABLE()

#define KEY2_PIN                  GPIO_PIN_1               
#define KEY2_GPIO_PORT            GPIOD                 
#define KEY2_GPIO_CLK_ENABLE()    __GPIOD_CLK_ENABLE()

#define KEY3_PIN                  GPIO_PIN_2              
#define KEY3_GPIO_PORT            GPIOD                 
#define KEY3_GPIO_CLK_ENABLE()    __GPIOC_CLK_ENABLE()

#define KEY4_PIN                  GPIO_PIN_3               
#define KEY4_GPIO_PORT            GPIOD                 
#define KEY4_GPIO_CLK_ENABLE()    __GPIOD_CLK_ENABLE()

#define KEY5_PIN                  GPIO_PIN_4              
#define KEY5_GPIO_PORT            GPIOD                 
#define KEY5_GPIO_CLK_ENABLE()    __GPIOD_CLK_ENABLE()

#define KEY6_PIN                  GPIO_PIN_5              
#define KEY6_GPIO_PORT            GPIOD                 
#define KEY6_GPIO_CLK_ENABLE()    __GPIOD_CLK_ENABLE()

#define KEY7_PIN                  GPIO_PIN_6              
#define KEY7_GPIO_PORT            GPIOD                 
#define KEY7_GPIO_CLK_ENABLE()    __GPIOD_CLK_ENABLE()

#define KEY8_PIN                  GPIO_PIN_7              
#define KEY8_GPIO_PORT            GPIOD                 
#define KEY8_GPIO_CLK_ENABLE()    __GPIOD_CLK_ENABLE()


#define KEY_ON	1
#define KEY_OFF	0

void MX_GPIO_Init(void);

//void Key_GPIO_Config(void);
//uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);

#endif /* __LED_H */
