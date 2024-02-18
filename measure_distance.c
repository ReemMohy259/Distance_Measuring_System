/*
 ================================================================================================
 Name        : measure_distance.c
 Author      : Reem Mohy
 Description : Measure distance using ultrasonic sensor
 Date        : 16/10/2022
 ================================================================================================
 */

#include<avr/io.h>
#include"lcd.h"
#include"ultrasonic.h"
#include"common_macros.h"

int main(void)
{
	uint16 distanceValue;  /*To store the value of the distance returned from ultrasonuc*/

	LCD_init();  /*To initialize the LCD*/

	ULTRASONIC_init();  /*To initialize the ultrasonic*/

	SET_BIT(SREG,7);  /*Enable the global interrupt I-bit*/

	/*Setup the initially display messages on LCD as required*/
	LCD_displayStringRowColumn(1,0,"Distance =    cm");
	LCD_displayStringRowColumn(2,2,"*----------*");
	LCD_displayStringRowColumn(3,6,"*--*");

	while(1)
	{
		LCD_moveCursor(1,11);  /*Overwrite to the same place*/

		distanceValue = Ultrasonic_readDistance();  /*Read the measured distance from the ultrasonic*/

		if(distanceValue >= 100)
		{
			LCD_intgerToString(distanceValue);  /*Display the value of the distance on the screen*/
		}
		else
		{
			/*if value is two digits or one digit display extra space to display correct value  */
			LCD_intgerToString(distanceValue);
			LCD_displayCharacter(' ');
		}
	}
}
