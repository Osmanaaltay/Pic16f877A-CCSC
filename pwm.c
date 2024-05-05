#include <16F877A.h>
#fuses HS,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG
#use delay(clock=4M)
int a=10;
#int_timer0
void timer0_kesmesi()
{
if(input(pin_d0)==0){set_timer0(a);}
if(input(pin_d0)==1){set_timer0(255-a);}
output_toggle(pin_d0);
}
void main()
{  delay_ms(100);
enable_interrupts(INT_timer0);
   enable_interrupts(GLOBAL);
   set_tris_d(0x01);
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256);
   set_timer0(0);
   output_d(0x00);
while(true){a=a+10;
}}
