#include <reg51.h> 
void delay (void); 
sbit IN1 = P2^0;
sbit EN = P2^1;
sbit IN2 = P2^2;
void main (void)
{ 
P1=0xff; 
while (1) 
{
if (P1>0x99) 
{
EN=1; 
IN1=1; 
IN2=0; 
delay(); 
}
else
EN=0; 
}
} 
void delay (void)
{ 
unsigned int i; 
for (i=0;i<=600;i++); 
}
