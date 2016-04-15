//**************************************************************//
//System Clock			:1MHz
//Software				:Atmel Studio 7
//LCD Data Interfacing	:8-Bit
//Created:				15.03.2016 13:06:25
//Author :				Matthew Poletin
//**************************************************************//

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "System.h"

#include <stdio.h>

extern System* g_system;

int blinkDelayTime = 500;
bool shouldBlink = true;

void BlinkLED(int delayTime);
void BlikLEDInit(void);
void PrepareToGetInput(void);
void delay_ms(int ms);

void BlikLEDInit()
{
	//Set the Data Direction Register to output (b pins)
	DDRB = 0b11111111;
}

void BlinkLED(int delayTime)
{
	PORTB = 0b11111111;
	delay_ms(delayTime);
	PORTB = 0b00000000;
	delay_ms(delayTime);
}

int main(void)
{
	g_system = new System();
	g_system->Init();

	delay_ms(2500);

	int x, y, z;

	char line1[50], line2[50], line3[50];

	while(true)
	{
		g_system->GetAccelerometer()->Update();

		x = g_system->GetAccelerometer()->GetX();
		y = g_system->GetAccelerometer()->GetY();
		z = g_system->GetAccelerometer()->GetZ();

		sprintf(line1, "x:%2d", x);
		sprintf(line2, "y:%2d", y);
		sprintf(line3, "z:%2d", z);

		g_system->GetGraphics()->DrawText(u8g_font_4x6, line1, 0, 6);
		g_system->GetGraphics()->DrawText(u8g_font_4x6, line2, 5, 12);
		g_system->GetGraphics()->DrawText(u8g_font_4x6, line3, 10, 18);

		g_system->GetGraphics()->Update();
	}

	return 0;
}