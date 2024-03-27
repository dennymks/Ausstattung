/*
 * blinker_led.c
 *
 *  Created on: Mar 20, 2024
 *      Author: Lukas, Denny
 */
#include "blinker_led.h"


//---Initalisierungsfunktion---

void LED_Init(void){

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	//Clock für Ports aktivieren

	if (LED_PORT_LINKS == GPIOA){ __HAL_RCC_GPIOA_CLK_ENABLE();}
	else if (LED_PORT_LINKS == GPIOB){ __HAL_RCC_GPIOB_CLK_ENABLE();}
	else if (LED_PORT_LINKS == GPIOC){ __HAL_RCC_GPIOC_CLK_ENABLE();}
	else if (LED_PORT_LINKS == GPIOD){ __HAL_RCC_GPIOD_CLK_ENABLE();}

	if (LED_PORT_RECHTS == GPIOA){ __HAL_RCC_GPIOA_CLK_ENABLE();}
	else if (LED_PORT_RECHTS == GPIOB){ __HAL_RCC_GPIOB_CLK_ENABLE();}
	else if (LED_PORT_RECHTS == GPIOC){ __HAL_RCC_GPIOC_CLK_ENABLE();}
	else if (LED_PORT_RECHTS == GPIOD){ __HAL_RCC_GPIOD_CLK_ENABLE();}




	//Konfiguartion Blinker Links

	//Konfiguration für rote LED

	GPIO_InitStruct.Pin = RED_LED_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_PORT_LINKS, &GPIO_InitStruct);

	// Konfiguration für grüne LED

    GPIO_InitStruct.Pin = GREEN_LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_PORT_LINKS, &GPIO_InitStruct);

	// Konfiguration für blaue LED

    GPIO_InitStruct.Pin = BLUE_LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_PORT_LINKS, &GPIO_InitStruct);



    //Konfiguartion Blinker Rechts

    //Konfiguration für rote LED

    GPIO_InitStruct.Pin = RED_LED_PIN;
   	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
   	GPIO_InitStruct.Pull = GPIO_NOPULL;
   	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_PORT_RECHTS, &GPIO_InitStruct);

   	// Konfiguration für grüne LED

    GPIO_InitStruct.Pin = GREEN_LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_PORT_RECHTS, &GPIO_InitStruct);

    // Konfiguration für blaue LED

    GPIO_InitStruct.Pin = BLUE_LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_PORT_RECHTS, &GPIO_InitStruct);

}


//----Einschaltfunktion----




void LED_On(uint8_t colour, uint8_t Blinker){
	GPIO_TypeDef* gpio_port = NULL;

	if (Blinker == BLINKERLINKS){
		gpio_port = LED_PORT_LINKS;
	}

	else gpio_port = LED_PORT_RECHTS;

	switch (colour)
	{
		case RED:
			HAL_GPIO_WritePin(gpio_port, RED_LED_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(gpio_port, GREEN_LED_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(gpio_port, BLUE_LED_PIN, GPIO_PIN_RESET);

			break;

		case GREEN:
			HAL_GPIO_WritePin(gpio_port, GREEN_LED_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(gpio_port, RED_LED_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(gpio_port, BLUE_LED_PIN, GPIO_PIN_RESET);
			break;

		case BLUE:
			HAL_GPIO_WritePin(gpio_port, BLUE_LED_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(gpio_port, RED_LED_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(gpio_port, GREEN_LED_PIN, GPIO_PIN_RESET);
			break;

		case ORANGE:
			HAL_GPIO_WritePin(gpio_port, RED_LED_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(gpio_port, GREEN_LED_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(gpio_port, BLUE_LED_PIN, GPIO_PIN_RESET);
			break;

		case WHITE:
			HAL_GPIO_WritePin(gpio_port, RED_LED_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(gpio_port, GREEN_LED_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(gpio_port, BLUE_LED_PIN, GPIO_PIN_SET);
			break;

		default: break;
	}
}


void LED_Off(uint8_t colour, uint8_t Blinker){

	GPIO_TypeDef* gpio_port = NULL;

	if (Blinker == BLINKERLINKS){
		 gpio_port = LED_PORT_LINKS;
	}

	else gpio_port = LED_PORT_RECHTS;

	switch (colour)
		{
			case RED:
				HAL_GPIO_WritePin(gpio_port, RED_LED_PIN, GPIO_PIN_RESET);
				break;

			case GREEN:
				HAL_GPIO_WritePin(gpio_port, GREEN_LED_PIN, GPIO_PIN_RESET);
				break;

			case BLUE:
				HAL_GPIO_WritePin(gpio_port, BLUE_LED_PIN, GPIO_PIN_RESET);
				break;

			case ORANGE:
				HAL_GPIO_WritePin(gpio_port, RED_LED_PIN, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(gpio_port, GREEN_LED_PIN, GPIO_PIN_RESET);
				break;

			case WHITE:
						HAL_GPIO_WritePin(gpio_port, RED_LED_PIN, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(gpio_port, GREEN_LED_PIN, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(gpio_port, BLUE_LED_PIN, GPIO_PIN_RESET);
						break;

			default: break;
		}

}


void LED_Toggle(uint8_t colour, uint8_t Blinker){

	GPIO_TypeDef* gpio_port = NULL;

	if (Blinker == BLINKERLINKS){
			gpio_port = LED_PORT_LINKS;
	}

	else gpio_port = LED_PORT_RECHTS;

	switch (colour)
			{
				case RED:
					if(Colour_Status(ORANGE, Blinker) || Colour_Status(WHITE, Blinker) || !Colour_Status(RED, Blinker))
						{
							LED_On(RED, Blinker);
						}

					else {HAL_GPIO_TogglePin(gpio_port, RED_LED_PIN);}

					break;

				case GREEN:
					if(!Colour_Status(GREEN, Blinker) || Colour_Status(WHITE, Blinker) || Colour_Status(ORANGE, Blinker))
					{
						LED_On(GREEN, Blinker);
					}
					else {HAL_GPIO_TogglePin(gpio_port, GREEN_LED_PIN);}

					break;

				case BLUE:
					if(!Colour_Status(BLUE, Blinker) || Colour_Status(WHITE, Blinker) || Colour_Status(ORANGE, Blinker))
					{
						LED_On(BLUE, Blinker);
					}

					else {HAL_GPIO_TogglePin(gpio_port, BLUE_LED_PIN);}

					break;

				case ORANGE:
					if(!Colour_Status(ORANGE, Blinker) || Colour_Status(WHITE, Blinker))
						{
							LED_On(ORANGE, Blinker);
						}

					else{
						HAL_GPIO_TogglePin(gpio_port, RED_LED_PIN);
						HAL_GPIO_TogglePin(gpio_port, GREEN_LED_PIN);
						}

					break;

				case WHITE:
					if(!Colour_Status(WHITE, Blinker))
						{
							LED_On(WHITE, Blinker);
							break;
						}

					else{
						HAL_GPIO_TogglePin(gpio_port, RED_LED_PIN);
						HAL_GPIO_TogglePin(gpio_port, GREEN_LED_PIN);
						HAL_GPIO_TogglePin(gpio_port, BLUE_LED_PIN);
						break;
					}




				default: break;
			}

}


void LED_AlternateColour(uint8_t colour1, uint8_t colour2, uint8_t Blinker){


	if (Colour_Status(colour1, Blinker) == Colour_Status(colour2, Blinker)){
		LED_Toggle(colour1, Blinker);
	}

	else if (Colour_Status(colour1, Blinker) != Colour_Status(colour2, Blinker)){
		if(Colour_Status(colour1, Blinker))
		{
			LED_Toggle(colour1, Blinker);
			LED_Toggle(colour2, Blinker);
		}
		else
		{
			LED_Toggle(colour2, Blinker);
			LED_Toggle(colour1, Blinker);
		}
	}


}


uint8_t Colour_Status(uint8_t colour, uint8_t Blinker){

	GPIO_TypeDef* gpio_port = NULL;

	if (Blinker == BLINKERLINKS){
			gpio_port = LED_PORT_LINKS;
		}

	else gpio_port = LED_PORT_RECHTS;

	switch (colour)
			{
				case RED:
					return HAL_GPIO_ReadPin(gpio_port, RED_LED_PIN) && !HAL_GPIO_ReadPin(gpio_port, GREEN_LED_PIN) && !HAL_GPIO_ReadPin(gpio_port, BLUE_LED_PIN);
					break;

				case GREEN:
					return HAL_GPIO_ReadPin(gpio_port, GREEN_LED_PIN) && !HAL_GPIO_ReadPin(gpio_port, RED_LED_PIN) && !HAL_GPIO_ReadPin(gpio_port, BLUE_LED_PIN);
					break;

				case BLUE:
					return HAL_GPIO_ReadPin(gpio_port, BLUE_LED_PIN) && !HAL_GPIO_ReadPin(gpio_port, GREEN_LED_PIN) && !HAL_GPIO_ReadPin(gpio_port, RED_LED_PIN);
					break;

				case ORANGE:
					return HAL_GPIO_ReadPin(gpio_port, RED_LED_PIN) && HAL_GPIO_ReadPin(gpio_port, GREEN_LED_PIN) && !HAL_GPIO_ReadPin(gpio_port, BLUE_LED_PIN);
					break;

				case WHITE:
					return HAL_GPIO_ReadPin(gpio_port, RED_LED_PIN) && HAL_GPIO_ReadPin(gpio_port, GREEN_LED_PIN) && HAL_GPIO_ReadPin(gpio_port, BLUE_LED_PIN);
					break;

				default:
					return 31;
					break;
			}
}


void LED_BothOn(uint8_t colour){

	switch (colour)
	{
		case RED:
			LED_On(RED, BLINKERRECHTS);
			LED_On(RED, BLINKERLINKS);
			break;

		case GREEN:
			LED_On(GREEN, BLINKERRECHTS);
			LED_On(GREEN, BLINKERLINKS);
			break;

		case BLUE:
			LED_On(BLUE, BLINKERRECHTS);
			LED_On(BLUE, BLINKERLINKS);
			break;

		case ORANGE:
			LED_On(ORANGE, BLINKERRECHTS);
			LED_On(ORANGE, BLINKERLINKS);
			break;

		case WHITE:
			LED_On(WHITE, BLINKERRECHTS);
			LED_On(WHITE, BLINKERLINKS);
			break;

		default: break;
	}
}

void LED_BothOff(uint8_t colour){

	LED_Off(WHITE, BLINKERRECHTS);
	LED_Off(WHITE, BLINKERLINKS);
}
