//**************************************************************//
//System Clock			:1MHz
//Software				:AVR Studio 4
//LCD Data Interfacing	:8-Bit
//Created:				15.03.2016 13:06:25
//Author :				Matthew Poletin
//**************************************************************//

#include <avr/io.h>
//#define F_CPU 1000000
#include <util/delay.h>
#include <avr/interrupt.h>

#include "System.h"
//#include "Extensions.h"

#include <stdio.h>

extern System* g_system;

int blinkDelayTime = 500;
bool shouldBlink = true;

void BlinkLED(int delayTime);
void BlikLEDInit(void);
void PrepareToGetInput(void);
void delay_ms(int ms);

#include "ADC/adc.h"
#include "ADXL335/adxl335.h"
//
//void sys_init(void);
//void draw(void);

//void u8g_setup(void);
//
//void SendPulsesInit()
//{
	//DDRC = 0x00;
	//DDRC |= (1<<PC3)|(1<<PC4);
//}
//
//void GetPulsesInit()
//{
	//DDRC &= ~(1<<PC0|1<<PC1);
	//printf("%c/n", DDRC);
//}
//
//bool CheckPort(int port, int number)
//{
	//if((port >> number) & 1)
	//{
		//BlinkLED(250);
		//return true;
	//}
	//else return false;
//}
//
//void SendPulses(int delayTime)
//{
	//PORTC &= ~(1<<PC4);
	//PORTC |= (1<<PC3);
	//if (CheckPort(PORTC, 1)) shouldBlink = true;
	//delay_ms(delayTime);
	//PORTC &= ~(1<<PC3);
	//PORTC |= (1<<PC4);
	//delay_ms(delayTime);
//}

void BlikLEDInit()
{
	//Set the Data Direction Register to output (b pins)
	DDRB = 0b11111111;
}

void BlinkLED(int delayTime)
{
	//Set the signal to high
	PORTB = 0b11111111;
	//wait 0.5 sec
	delay_ms(delayTime);
	//Set the signal to low
	PORTB = 0b00000000;
	//wait 0.5 sec
	delay_ms(delayTime);
}


int main(void)
{
	g_system = new System();
	if(!g_system->Init()) printf("Error: system initialization failed");


	//int x_axis, y_axis, z_axis;
//
	//adc_init();
//
	//delay_ms(2000);
//
	/*if (shouldBlink) */BlikLEDInit();
//
	////int pulsesDelayTime = 50;
	////bool shouldSendPulses = true;
	////if (shouldSendPulses) SendPulsesInit();
	//
	while(true)
	{
		if (shouldBlink) BlinkLED(blinkDelayTime);
		
		//if (shouldSendPulses) SendPulses(pulsesDelayTime);
		//
		//x_axis = read_adxl335_x_value(0);
		//y_axis = read_adxl335_y_value(1);
		//z_axis = read_adxl335_z_value(2);
	}

	//sys_init();
	//u8g_setup();
	//
	//for(;;)
	//{
		//u8g_FirstPage(&u8g);
		//do
		//{
			//draw();
		//} while ( u8g_NextPage(&u8g) );
		//u8g_Delay(100);
	//}

	return 0;
}