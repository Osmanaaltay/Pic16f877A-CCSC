output_low(pin_b4);#include <16F877A.h>
#fuses HS,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG
#use delay(clock=4M)
#use fast_io(b)
int a;
#int_ext
void RB0()
{output_low(pin_b4);output_low(pin_b5);output_low(pin_b6);
output_high(pin_b4);if(input(pin_b3)==1){a=1;while(input(pin_b3)==1});
output_high(pin_b4);if(input(pin_b2)==1){a=2;while(input(pin_b3)==1)};
output_low(pin_b4);

}
void main()
{  
delay_ms(1000);
ext_int_edge(L_TO_H);
enable_interrupts(INT_EXT);
enable_interrupts(GLOBAL);
   set_tris_b(0x0f);
   set_tris_d(0x00);
   output_d(0x00);
   while(1){output_high(pin_b4);output_high(pin_b5);output_high(pin_b6);
   for(int i=0;i=a;i++){output_toggle(pin_d1);delay_ms(200);}
   }
}






