#include <16F877A.h>
#include<math.h>
#fuses HS,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG
#use delay(clock=4M)
#use fast_io(b)
#define ekran1 pin_c0
#define ekran2 pin_c1
#define ekran3 pin_c2
#define ekran4 pin_c4
int x,y,z,w;
int16 saniye=0,dakika=0,sure=260;
int16 sayi=0;
int digit[10]={0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6};
#int_timer0
void timer0_kesmasi()
{set_timer0(60);
sayi++;
if(sayi==18){
sayi=0;
sure++;}}
void ekran(){
output_high(ekran1);output_d(w);delay_ms(1);output_low(ekran1);
output_high(ekran2);output_d(x);delay_ms(1); output_low(ekran2);
output_high(ekran3);output_d(y);delay_ms(1);output_low(ekran3);
output_high(ekran4);output_d(z);delay_ms(1);output_low(ekran4);}
void main()
{   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);
   set_tris_c(0x00);
   set_tris_b(0x00);
   output_b(0x00);
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256);
   set_timer0(60);
   enable_interrupts(INT_timer0);
   enable_interrupts(GLOBAL);
   delay_ms(500);
while(1){
saniye=sure%60;
dakika=sure/60;
w=digit[saniye%10];
x=digit[saniye/10];
y=digit[dakika%10];
z=digit[dakika/10];
ekran();
if(sure==3600){sure=0;delay_ms(1000);}}}






