#include <16F877A.h>
#fuses HS,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG
#use delay(clock=20M)
#use fast_io(b)
#define sut1   pin_b7
#define sut2   pin_b6
#define sut3   pin_b5
#define sut4   pin_b4
#define sat1   pin_b3
#define sat2   pin_b2
#define sat3   pin_b1
#define sat4   pin_b0
#define ekran1 pin_c0
#define ekran2 pin_c1
#define ekran3 pin_c2
#define ekran4 pin_c4
int x,y,z,w;
int a[16]={0x60,0xda,0xf2,0xee,0x66,0xb6,0xbe,0x3e,0xe0,0xfe,0xf6,0x9c,0x9e,0xfc,0x8e,0x7a};
void ekran(){
output_high(ekran1);output_d(w);delay_ms(5);output_low(ekran1);
output_high(ekran2);output_d(x);delay_ms(5); output_low(ekran2);
output_high(ekran3);output_d(y);delay_ms(5);output_low(ekran3);
output_high(ekran4);output_d(z);delay_ms(5);output_low(ekran4);}
void main()
{set_tris_d(0x00);set_tris_c(0x00);set_tris_b(0xf0);output_b(0x00);output_d(0x00);
 
while(1)
{ekran();
output_high(sat1);
if(input(sut1)==1){z=y;y=x;x=w;w=a[0];delay_ms(5);while(input(sut1)==1){ekran();}}
if(input(sut2)==1){z=y;y=x;x=w;w=a[1];delay_ms(5);while(input(sut2)==1){ekran();}}
if(input(sut3)==1){z=y;y=x;x=w;w=a[2];delay_ms(5);while(input(sut3)==1){ekran();}}
if(input(sut4)==1){z=y;y=x;x=w;w=a[3];delay_ms(5);while(input(sut4)==1){ekran();}}
output_low(sat1);
output_high(sat2);
if(input(sut1)==1){z=y;y=x;x=w;w=a[4];delay_ms(5);while(input(sut1)==1){ekran();}}
if(input(sut2)==1){z=y;y=x;x=w;w=a[5];delay_ms(5);while(input(sut2)==1){ekran();}}
if(input(sut3)==1){z=y;y=x;x=w;w=a[6];delay_ms(5);while(input(sut3)==1){ekran();}}
if(input(sut4)==1){z=y;y=x;x=w;w=a[7];delay_ms(5);while(input(sut4)==1){ekran();}}
output_low(sat2);
output_high(sat3);
if(input(sut1)==1){z=y;y=x;x=w;w=a[8];delay_ms(5);while(input(sut1)==1){ekran();}}
if(input(sut2)==1){z=y;y=x;x=w;w=a[9];delay_ms(5);while(input(sut2)==1){ekran();}}
if(input(sut3)==1){z=y;y=x;x=w;w=a[10];delay_ms(5);while(input(sut3)==1){ekran();}}
if(input(sut4)==1){z=y;y=x;x=w;w=a[11];delay_ms(5);while(input(sut4)==1){ekran();}}
output_low(sat3);
output_high(sat4);
if(input(sut1)==1){z=y;y=x;x=w;w=a[12];delay_ms(5);while(input(sut1)==1){ekran();}}
if(input(sut2)==1){z=y;y=x;x=w;w=a[13];delay_ms(5);while(input(sut2)==1){ekran();}}
if(input(sut3)==1){z=y;y=x;x=w;w=a[14];delay_ms(5);while(input(sut3)==1){ekran();}}
if(input(sut4)==1){z=y;y=x;x=w;w=a[15];delay_ms(5);while(input(sut4)==1){ekran();}}
output_low(sat4);}
}
