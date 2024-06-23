#include <reg51.h> 
unsigned char newkey,oldkey,p;
signed char tmp;
sbit sd = P2^0; 
unsigned char look_up[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,
0x77,0x7c,0x39,0x5e,0x79,0x71};
unsigned char motor_sequence[]={8,4,2,1,8,4,2,1,8,4,2,1,8,4,2,1}; 
void key_scan (void); 
void get_key (void); 
void display (unsigned char); 
void delay (unsigned int time); 
void main (void)
{ 
P0=0xf0; 
while (1) 
{
key_scan (); 
get_key (); 
}
} 
void key_scan (void)
{ 
oldkey=newkey; 
while (1) 
{
P0=0xfe; 
P0 &=0xfe; 
if (P0!=0xfe) 
break; 
P0=0xfd; 
P0 &=0xfd; 
if (P0!=0xfd) 
break; 
P0=0xfb; 
P0 &=0xfb; 
if (P0!=0xfb) 
break; 
P0=0xf7; 
P0 &=0xf7; 
if (P0!=0xf7) 
break; 
}
newkey=P0; 
do {
P0=0xf0; 
 } 
while (P0!=0xf0); 
} 
void get_key (void)
{ 
if (newkey==0xee) 
display (0); 
else if (newkey==0xed) 
display(1); 
else if (newkey==0xeb) 
display(2); 
else if (newkey==0xe7)
display (3); 
else if (newkey==0xde) 
display (4); 
else if (newkey==0xdd) 
display (5); 
else if (newkey==0xdb) 
display (6); 
else if (newkey==0xd7) 
display (7); 
else if (newkey==0xbe) 
display (8); 
else if (newkey==0xbd) 
display (9); 
else if (newkey==0xbb) 
display (10); 
else if (newkey==0xb7) 
display (11); 
else if (newkey==0x7e) 
display (12); 
else if (newkey==0x7d) 
display (13); 
else if (newkey==0x7b) 
display(14); 
else if (newkey==0x77) 
display(15); 
} 
void display (unsigned char x)
{ 
newkey=x; 
tmp=newkey-oldkey; 
sd=0; 
if (tmp<0x00)

{
for (p=oldkey;p>newkey;p--) 
{ 
P3=motor_sequence[p]; 
P1=look_up[p];
delay (10000); 
} 
P3=motor_sequence[p]; 
P1=look_up[p]; 
delay (10000); 
} 
else
{
for (p=oldkey;p<newkey;p++) 
{ 
P3=motor_sequence[p]; 
P1=look_up[p]; 
delay (10000); 
} 
P3=motor_sequence[p]; 
P1=look_up[p]; 
delay (10000); 
} 
} 
void delay (unsigned int time) 
{
unsigned int i; 
for (i=0;i<=time;i++); 
}
