#include<reg51.h>
void delay();
void main()
{
while(1)
{
P1=0xff;
delay();
P1=0x00;
delay();
}
}
void delay()
{
unsigned int i,j,k;
for(i=0;i<8;i++)
for(j=0;j<100;j++)
for(k=0;k<100;k++);
}
