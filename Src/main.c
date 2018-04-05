/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"

/* USER CODE BEGIN Includes */
#include "ws28xx.h"
#include <stdbool.h>
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;
DMA_HandleTypeDef hdma_spi1_tx;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
bool ledON = false;
bool stop = false;
bool key_on=false;
bool led_clean = false;
uint8_t mode=0;

uint8_t sample1[]={1,2,3,5,6,7,8,9,12,13,16,
										17,18,19,22,24,27,31,38,42,43,48,52,55,57,
										60,62,63,64,66,69,73,77,85,89,93,96,98,102,
										105,106,111,116,117}; 

uint8_t sample2[]={1,2,19,20,21,23,26,28,30,32,33,34,38,42,46,49,51,53,54,56,59,
										62,65,66,68,70,72,75,78,
										82,83,87,91,94,97,100};

uint8_t sample3[]={9,28,30,43,48,52,
										61,62,63,64,68,74,76,77,79,80,81,87,95,97,104};

uint8_t sample4[]={117,116,115,114,113,112,111,
										110,109,108,107,106,105,104,103,102,101,117,98,99,100, 63,62,61,58,59,60,21,20,19,17,18 
										};		

uint8_t sample5[]={101,102,103,104,105,106,
										107,108,109,110,110,111,112,113,114,115,116,117,82,83,84,79,80,81,40,41,42,37,38,39,0,1
										};	

uint8_t sample6[]={3,4,5,6,12,13,14,15,
										22,27,31,36,43,48,52,57,61,62,65,
										66,67,68,74,75,76,77,80,81,82,83,99,100,
										101,102,103,104,105,106,107,108,109,110,111,112,
										113,114,115,116,117};

uint8_t sample7[]={12,13,14,15,22,27,
										43,44,45,46,47,48,52,57,61,62,65,66,67,68,74,75,76,77,80,81,82,83,99,
										100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117 };

										
uint8_t sample8[]={3,4,5,6,31,36,43,48,52,53,54,55,56,57,
										61,62,65,66,67,68,74,75,76,77,80,81,
										82,83,99,100,101,102,103,104,105,106,107,108,
										109,110,111,112,113,114,115,116,117};

										

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_SPI1_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_SPI1_Init();

  /* USER CODE BEGIN 2 */
	ws28xx_init();
//	ws28xx_test();
	//ws28xx_Update();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */
	
//		for(int i=0;i<188;i++)
//		{
//			ws28xx_SetColorRGB(i,200,0,0);
//			ws28xx_Update();
//		}
		
		
//		ws28xx_SetColorArray(0,118,ws28xx_Color_Red);
//		ws28xx_Update();
//		ws28xx_SetColorArray(0,118,ws28xx_Color_Black);
//		ws28xx_Update();
//		for (int i=0;i<100;i++)
//		HAL_Delay(i);
		
//////		
//////		for(uint8_t b=0;b<10;b++)
//////		{
//////		for(uint8_t i =0;i<5;i++)
//////				{
//////					ws28xx_SetColorArray(0,9,ws28xx_Color_Red);
//////					ws28xx_SetColorArray(29,39,ws28xx_Color_Red);
//////					ws28xx_SetColorArray(40,50,ws28xx_Color_Red);
//////					ws28xx_SetColorArray(71,81,ws28xx_Color_Red);
//////					ws28xx_SetColorArray(82,91,ws28xx_Color_Red);
//////					ws28xx_SetColorArray(109,118,ws28xx_Color_Red);
//////					HAL_Delay(25);
//////					ws28xx_Update();
//////					HAL_Delay(25);
//////					ws28xx_SetColorArray(0,9,ws28xx_Color_Black);
//////					ws28xx_SetColorArray(29,39,ws28xx_Color_Black);
//////					ws28xx_SetColorArray(40,50,ws28xx_Color_Black);
//////					ws28xx_SetColorArray(71,81,ws28xx_Color_Black);
//////					ws28xx_SetColorArray(82,91,ws28xx_Color_Black);
//////					ws28xx_SetColorArray(109,118,ws28xx_Color_Black);
//////					ws28xx_Update();
//////				}
//////		for(uint8_t i =0;i<8;i++)
//////				{
//////					ws28xx_SetColorArray(10,18,ws28xx_Color_Blue);
//////					ws28xx_SetColorArray(19,28,ws28xx_Color_Blue);
//////					ws28xx_SetColorArray(51,60,ws28xx_Color_Blue);
//////					ws28xx_SetColorArray(61,70,ws28xx_Color_Blue);
//////					ws28xx_SetColorArray(92,100,ws28xx_Color_Blue);
//////					ws28xx_SetColorArray(101,108,ws28xx_Color_Blue);
//////				//	HAL_Delay(5);
//////					ws28xx_Update();
//////					HAL_Delay(25);
//////					ws28xx_SetColorArray(10,18,ws28xx_Color_Black);
//////					ws28xx_SetColorArray(19,28,ws28xx_Color_Black);
//////					ws28xx_SetColorArray(51,60,ws28xx_Color_Black);
//////					ws28xx_SetColorArray(61,70,ws28xx_Color_Black);
//////					ws28xx_SetColorArray(92,100,ws28xx_Color_Black);
//////					ws28xx_SetColorArray(101,108,ws28xx_Color_Black);
//////					ws28xx_Update();
//////				}
//////			}
//////		
//////		for(uint8_t i =0; i<sizeof(sample1);i++)
//////				{
//////					ws28xx_SetColorRGB(sample1[i],255,0,0);
//////				
//////				}
//////		ws28xx_Update();
//////				
//////				HAL_Delay(2000);
//////				ws28xx_SetColorArray(0,118,ws28xx_Color_Black);
//////				ws28xx_Update();
//////			
//////			for(uint8_t i =0; i<sizeof(sample2);i++)
//////				{
//////					ws28xx_SetColorRGB(sample2[i],0,0,200);
//////				
//////				}
//////				ws28xx_Update();	
//////			HAL_Delay(2000);
//////			ws28xx_SetColorArray(0,118,ws28xx_Color_Black);
//////				ws28xx_Update();
//////				
//////				
//////				for(uint8_t i =0; i<sizeof(sample3);i++)
//////				{
//////					ws28xx_SetColorRGB(sample3[i],255,0,0);
////////					ws28xx_Update();
////////					HAL_Delay(100);
//////				}
//////				ws28xx_Update();	
//////			HAL_Delay(2000);
//////			ws28xx_SetColorArray(0,118,ws28xx_Color_Black);
//////			ws28xx_Update();
//////				
//////				
//////				for(int8_t i =sizeof(sample4)-1; i>-1;i--)
//////				{
//////					ws28xx_SetColorRGB(sample4[i],200,45,0);
//////					ws28xx_Update();
//////					HAL_Delay(10);
//////				
//////				}
//////				ws28xx_Update();	
//////			HAL_Delay(2000);
//////			ws28xx_SetColorArray(0,118,ws28xx_Color_Black);
//////				ws28xx_Update();
			
			
			if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5)&&HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4))
			{
				key_on=true;
					if(key_on==true)
					{
						mode++;
						key_on=false;
						HAL_Delay(100);
					}
			}
					
		
		switch (mode)
			
			case 0:
				for(uint8_t i =0; i<sizeof(sample6);i++)
						{
							ws28xx_SetColorRGB(sample6[i],200,0,0);
						//	ws28xx_Update();
						//	HAL_Delay(10);
						}
				ws28xx_Update();	
				break;
						

				

		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5))	
		{
			ledON=true;
			led_clean=false;
		
		for(uint8_t b=0;b<10;b++)
		{
			if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5))	{
		for(uint8_t i =0;i<5;i++)
				{
					ws28xx_SetColorArray(0,9,ws28xx_Color_Red);
					ws28xx_SetColorArray(29,39,ws28xx_Color_Red);
					ws28xx_SetColorArray(40,50,ws28xx_Color_Red);
					ws28xx_SetColorArray(71,81,ws28xx_Color_Red);
					ws28xx_SetColorArray(82,91,ws28xx_Color_Red);
					ws28xx_SetColorArray(109,118,ws28xx_Color_Red);
					HAL_Delay(25);
					ws28xx_Update();
					HAL_Delay(25);
					ws28xx_SetColorArray(0,9,ws28xx_Color_Black);
					ws28xx_SetColorArray(29,39,ws28xx_Color_Black);
					ws28xx_SetColorArray(40,50,ws28xx_Color_Black);
					ws28xx_SetColorArray(71,81,ws28xx_Color_Black);
					ws28xx_SetColorArray(82,91,ws28xx_Color_Black);
					ws28xx_SetColorArray(109,118,ws28xx_Color_Black);
					ws28xx_Update();
				}
		for(uint8_t i =0;i<8;i++)
				{
					ws28xx_SetColorArray(10,18,ws28xx_Color_Blue);
					ws28xx_SetColorArray(19,28,ws28xx_Color_Blue);
					ws28xx_SetColorArray(51,60,ws28xx_Color_Blue);
					ws28xx_SetColorArray(61,70,ws28xx_Color_Blue);
					ws28xx_SetColorArray(92,100,ws28xx_Color_Blue);
					ws28xx_SetColorArray(101,108,ws28xx_Color_Blue);
				//	HAL_Delay(5);
					ws28xx_Update();
					HAL_Delay(25);
					ws28xx_SetColorArray(10,18,ws28xx_Color_Black);
					ws28xx_SetColorArray(19,28,ws28xx_Color_Black);
					ws28xx_SetColorArray(51,60,ws28xx_Color_Black);
					ws28xx_SetColorArray(61,70,ws28xx_Color_Black);
					ws28xx_SetColorArray(92,100,ws28xx_Color_Black);
					ws28xx_SetColorArray(101,108,ws28xx_Color_Black);
					ws28xx_Update();
				}
			}}
		
		
		}
		else
			ledON=false;



				
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6))		
			{
				ledON=true;
				led_clean=false;
				
				for(uint8_t i =0; i<sizeof(sample5);i++)
				{
					ws28xx_SetColorRGB(sample5[i],200,45,0);
					ws28xx_Update();
					//HAL_Delay(2);
				
				}
				ws28xx_Update();	
			}
			else
				ledON=false;
//			else
//			//HAL_Delay(2000);
//		{	ws28xx_SetColorArray(0,118,ws28xx_Color_Black);
//			ws28xx_Update();
//				
//		}	

		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3))		
			{
				ledON=true;
				led_clean=false;
				for(uint8_t i =0; i<sizeof(sample4);i++)
				{
					ws28xx_SetColorRGB(sample4[i],200,45,0);
					ws28xx_Update();
					//HAL_Delay(2);
				
				}
				ws28xx_Update();	
			}
			else
				ledON=false;
//			else
//			//HAL_Delay(2000);
//		{	ws28xx_SetColorArray(0,118,ws28xx_Color_Black);
//				ws28xx_Update();
//				
//		}	
		
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4))		
		{
			ledON=true;
			led_clean=false;
			stop=true;
				for (uint8_t i =0;i<118;i++)
					{
						ws28xx_SetColorRGB(i,200,0,0);
					}
					ws28xx_Update();
		
		}
		else
			ledON=false;
		
		
		if(stop==true&&ledON==false)
		{
			for(uint8_t b = 180;b>0;b-=10){
				for (uint8_t i =0;i<118;i++)
					{
						ws28xx_SetColorRGB(i,b,0,0);
					}
					ws28xx_Update();
				}
			stop=false;
		}
		
		if(ledON==false&&led_clean==false)
		{
			led_clean=true;
			ws28xx_SetColorArray(0,118,ws28xx_Color_Black);
			ws28xx_Update();
		}

		
			
			
		




		
//////					for(uint8_t i =0; i<sizeof(sample6);i++)
//////				{
//////					ws28xx_SetColorRGB(sample6[i],200,0,0);
//////				//	ws28xx_Update();
//////				//	HAL_Delay(10);
//////				
//////				}
//////				ws28xx_Update();	
//////			HAL_Delay(2000);
//////			ws28xx_SetColorArray(0,118,ws28xx_Color_Black);
//////				ws28xx_Update();
//////				
//////				
//////					for(uint8_t i =0; i<sizeof(sample7);i++)
//////				{
//////					ws28xx_SetColorRGB(sample7[i],0,200,0);
//////				//	ws28xx_Update();
//////				//	HAL_Delay(10);
//////				
//////				}
//////				ws28xx_Update();	
//////			HAL_Delay(2000);
//////			ws28xx_SetColorArray(0,118,ws28xx_Color_Black);
//////				ws28xx_Update();
//////				
//////				
//////					for(uint8_t i =0; i<sizeof(sample8);i++)
//////				{
//////					ws28xx_SetColorRGB(sample8[i],0,200,0);
//////				//	ws28xx_Update();
//////				//	HAL_Delay(10);
//////				
//////				}
//////				ws28xx_Update();	
//////			HAL_Delay(2000);
//////			ws28xx_SetColorArray(0,118,ws28xx_Color_Black);
//////				ws28xx_Update();
//////			

//////			for(uint8_t i =0;i<100;i++)
//////				{
//////					ws28xx_SetColorArray(0,118,ws28xx_Color_Red);
//////				//	HAL_Delay(5);
//////					ws28xx_Update();
//////					HAL_Delay(5);
//////					ws28xx_SetColorArray(0,118,ws28xx_Color_Black);
//////					ws28xx_Update();
//////				}
//////				for(uint8_t i =0;i<100;i++)
//////				{
//////					ws28xx_SetColorArray(0,118,ws28xx_Color_Pink);
//////					
//////					ws28xx_Update();
//////					HAL_Delay(5);
//////					ws28xx_SetColorArray(0,118,ws28xx_Color_Black);
//////					ws28xx_Update();
//////				}
//////				for(uint8_t i =0;i<100;i++)
//////				{
//////					ws28xx_SetColorArray(0,118,ws28xx_Color_Green);
//////					
//////					ws28xx_Update();
//////					HAL_Delay(5);
//////					ws28xx_SetColorArray(0,118,ws28xx_Color_Black);
//////					ws28xx_Update();
//////				}
//////				for(uint8_t i =0;i<100;i++)
//////				{
//////					ws28xx_SetColorArray(0,118,ws28xx_Color_Blue);
//////					
//////					ws28xx_Update();
//////					HAL_Delay(5);
//////					ws28xx_SetColorArray(0,118,ws28xx_Color_Black);
//////					ws28xx_Update();
//////				}
//////				for(uint8_t i =0;i<100;i++)
//////				{
//////					ws28xx_SetColorArray(0,118,ws28xx_Color_Yellow);
//////				//	HAL_Delay(5);
//////					ws28xx_Update();
//////					HAL_Delay(5);
//////					ws28xx_SetColorArray(0,118,ws28xx_Color_Black);
//////					ws28xx_Update();
//////				}
//////				
				
			
				
				
		
  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV2;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* SPI1 init function */
static void MX_SPI1_Init(void)
{

  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** 
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void) 
{
  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel3_IRQn);

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pins : PB3 PB4 PB5 PB6 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
