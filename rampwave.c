#include<reg51.h>
void main()
{
	unsigned int i;
	while(1)
	{
	for(i=0;i<250;i++)
			P1=i;
			P1=0x00;
	}
}
