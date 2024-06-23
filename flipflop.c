#include <reg51.h>
void delay(unsigned int time);
void main()
{
	while(1)
	{
		P2=0xAA;
		delay(1000);
		P2=0x55;
		delay(1000);
	}
}
void delay(unsigned int time)
{
	unsigned int i, j;
	for(i=0;i<time;i++)
	{
		for(j=0;j<23;j++)
		{
		}
	}
}
