#include "Includes.h"

unsigned char arr[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x98};
int h1,h2,m1,m2,s1,s2;



void dist(unsigned char r, int k)
{
	P3=k;
	switch (r)
	{
		case 0:
		P1=arr[0];
		break;
		
		case 1:
		P1=arr[1];
		break;
		
		case 2:
		P1=arr[2];
		break;
		
		case 3:
		P1=arr[3];
		break;
		
		case 4:
		P1=arr[4];
		break;
		
		case 5:
		P1=arr[5];
		break;
		
		case 6:
		P1=arr[6];
		break;
		
		case 7:
		P1=arr[7];
		break;
		
		case 8:
		P1=arr[8];
		break;
		
		case 9:
		P1=arr[9];
		break;
	}
}

void led()
{
	int k=0;
	P3=0x3f;
	for (k=0;k<10;k++)
	{
		P1=arr[k];
		delay(50000);
	}
}

void DisplayTimeTo7seg( unsigned char* pTimeArray )   // Displays time in HH:MM:SS AM/PM format
{
	// Display Hour
	h1=(pTimeArray[2]/10);
	dist(h1,0x01);
	delay(100);
	h2=(pTimeArray[2]%10);
	dist(h2,0x02);
	delay(100);
	
	//Display Minutes
	m1=(pTimeArray[1]/10);
	dist(m1,0x04);
	delay(100);
	m2=(pTimeArray[1]%10);
	dist(m2,0x08);
	delay(100);

	//Display Seconds
	s1=(pTimeArray[0]/10);
	dist(s1,0x10);
	delay(100);
	s2=(pTimeArray[0]%10);
	dist(s2,0x20);
}


// Main function
void main()
{	
	InitI2C();	// Initialize i2c pins											

	// Set initial time
	Set_DS1307_RTC_Time(AM_Time, 8, 32, 50);	// Set time 08:32:59 AM

	while(1)
	{
		// Display RTC time on first line of LCD
		DisplayTimeTo7seg(Get_DS1307_RTC_Time());
	}
}