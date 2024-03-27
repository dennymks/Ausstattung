#include "stm32f4xx_hal.h"
#include "blinker_led.h"


int main(void)
{
    HAL_Init();

    LED_Init();



    while (1)
    {
    	//LED_AlternateColour(BLUE, ORANGE, BLINKERRECHTS);
    	//LED_Toggle(WHITE, BLINKERRECHTS);
    	HAL_Delay(750);

    }

}




