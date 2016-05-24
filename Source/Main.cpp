//**************************************************************//
//System Clock			:1MHz
//Software				:Atmel Studio 7
//LCD Data Interfacing	:8-Bit
//Created:				15.03.2016 13:06:25
//Author :				Matthew Poletin
//**************************************************************//

#include <stdio.h>
#include <string.h>

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include <stdlib.h>

#include "Globals.h"
#include "System.h"
#include "MyCpp/MyString.h"

extern System* g_system;

int main(void)
{
	g_system = new System();
	g_system->Init();

	int accelX = 0;
	int accelY = 0;
	int accelZ = 0;
	char accelXline[50];
	char accelYline[50];
	char accelZline[50];

	//const uint8_t rook_bitmap[] PROGMEM = {
		//0b00000000,         // 00000000
		//0b01010101,         // 01010101
		//0b01111111,         // 01111111
		//0b00111110,         // 00111110
		//0b00111110,         // 00111110
		//0b00111110,         // 00111110
		//0b00111110,         // 00111110
		//0b01111111          // 01111111
	//};

	char cIterator[5];
	unsigned int uiIterator = 0;

	while(true)
	{
		g_system->GetGraphics()->Update();

		g_system->GetAccelerometer()->Update();
		accelX = g_system->GetAccelerometer()->GetX();
		accelY = g_system->GetAccelerometer()->GetY();
		accelZ = g_system->GetAccelerometer()->GetZ();

		g_system->GetController()->Update();

		sprintf(accelXline, "x: %4d", accelX);
		sprintf(accelYline, "y: %4d", accelY);
		sprintf(accelZline, "z: %4d", accelZ);

		DrawText(u8g_font_4x6, accelXline, 0, 6);
		DrawText(u8g_font_4x6, accelYline, 0, 12);
		DrawText(u8g_font_4x6, accelZline, 0, 18);

		for(unsigned int butCounter = 0; butCounter < 8; butCounter++)
		{
			if(g_system->GetController()->IsKeyClicked(butCounter))
			{
				DrawText(u8g_font_4x6, "Key   clicked",	0, 24 + butCounter * 6);
				DrawText(u8g_font_4x6, itoa(1, nullptr, 10), 4, 24 + butCounter * 6);
			}
		}
		//DrawBitmap(rook_bitmap, 40, 40, 8);

		itoa(uiIterator, cIterator, 10);
		DrawText(u8g_font_4x6, cIterator, 116, 6);
		uiIterator++;
	}

	return 0;
}