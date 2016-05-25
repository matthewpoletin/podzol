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

	int iAccelX = 0;
	int iAccelY = 0;
	int iAccelZ = 0;
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
		iAccelX = g_system->GetAccelerometer()->GetX();
		iAccelZ = g_system->GetAccelerometer()->GetZ();

		g_system->GetController()->Update();

		double fAccelX = ((double)iAccelX - 130.0)/70.0;
		double fAccelZ = ((double)iAccelZ - 130.0)/70.0;

		sprintf(accelXline, "xAxis: %.2f", fAccelX);
		sprintf(accelZline, "yAxis: %.2f", fAccelZ);

		DrawText(u8g_font_4x6, accelXline, 0, 6);
		DrawText(u8g_font_4x6, accelZline, 0, 12);

		//for(unsigned int butCounter = 0; butCounter < 8; butCounter++)
		//{
			//if(g_system->GetController()->IsKeyClicked(butCounter))
			//{
				//DrawText(u8g_font_4x6, "Key   clicked",	0, 24 + butCounter * 6);
				//DrawText(u8g_font_4x6, itoa(butCounter, nullptr, 10), 15, 24 + butCounter * 6);
			//}
		//}
		if(g_system->GetController()->IsKeyClicked(0))
		{
			DrawText(u8g_font_4x6, "Key 1 clicked",	0, 24 + 0 * 6);
		}
		if(g_system->GetController()->IsKeyClicked(1))
		{
			DrawText(u8g_font_4x6, "Key 2 clicked",	0, 24 + 1 * 6);
		}
		if(g_system->GetController()->IsKeyClicked(2))
		{
			DrawText(u8g_font_4x6, "Key 3 clicked",	0, 24 + 2 * 6);
		}
		if(g_system->GetController()->IsKeyClicked(3))
		{
			DrawText(u8g_font_4x6, "Key 4 clicked",	0, 24 + 3 * 6);
		}
		if(g_system->GetController()->IsKeyClicked(4))
		{
			DrawText(u8g_font_4x6, "Key 5 clicked",	0, 24 + 4 * 6);
		}
		if(g_system->GetController()->IsKeyClicked(5))
		{
			DrawText(u8g_font_4x6, "Key 6 clicked",	0, 24 + 5 * 6);
		}
		if(g_system->GetController()->IsKeyClicked(6))
		{
			DrawText(u8g_font_4x6, "Key 7 clicked",	0, 24 + 6 * 6);
		}
		if(g_system->GetController()->IsKeyClicked(7))
		{
			DrawText(u8g_font_4x6, "Key 8 clicked",	0, 24 + 7 * 6);
		}

		//DrawBitmap(rook_bitmap, 40, 40, 8);

		itoa(uiIterator, cIterator, 10);
		DrawText(u8g_font_4x6, cIterator, 116, 6);
		uiIterator++;
	}

	return 0;
}