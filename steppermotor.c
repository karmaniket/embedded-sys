#include<reg51.h>
 void delay();
 void main()
 {
 while(1)
 {
 P2=0x3;
 delay();
 P2=0x6;
 delay();
 P2=0xc;
 delay();
 P2=0x9;
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
