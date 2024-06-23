#include<reg51.h>
void send(char x);
void main(void)
{
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	TR1=1;
	send('K');
	send('A');
	send('R');
	send('M');
	send('A');
	send('N');
	send('I');
	send('K');
	send('E');
	send('T');
	send('\r');
	while(1);
}
void send(char x)
{
SBUF=x;
while(TI==0);
TI=0;
}
