#include<reg51.h>
void delay(unsigned int ms)
{
	unsigned int i, j;
	for(i=0;i<ms;i++)
	for(j=0;j<=1257;j++);
}
void main()
{
char number[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x05,0x7f,0x6f};
int i,j;
P2=0x00;
P3=0x00;
while(1)
{	
	for(i=0;i<=9;i++)
	{
		P2=number[i];
		for(j=0;j<=9;j++)
		{
			P3=number[j];
			delay(50);
		}
	}
}
}
