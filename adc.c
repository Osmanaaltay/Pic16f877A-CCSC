#include <16F877A.h>
#device ADC=10
#fuses XT,NOWDT,NOLVP,NOBROWNOUT
#use delay(clock=4M)
#byte  ADC0 = 0x1f//ADCON0 KAYDED�C�S�N� ADRESLE
#byte  ADC1 = 0x9f//ADCON1 KAYDED�C�S�N� ADRESLE
#byte  adrh = 0x1E//ADRH   KAYDED�C�S�N� ADRESLE
#byte  adrl = 0x9E//ADRL   KAYDED�C�S�N� ADRESLE
#define LCD_ENABLE_PIN PIN_C2
#define LCD_RS_PIN PIN_C0
#define LCD_RW_PIN PIN_C1
#define LCD_DATA4 PIN_D4
#define LCD_DATA5 PIN_D5
#define LCD_DATA6 PIN_D6
#define LCD_DATA7 PIN_D7
#include <lcd.c>
unsigned long int l,h,a;
unsigned long int deger;
float gerilim,sicaklik;
unsigned long int analog_oku(unsigned long int a){
    ADC0=0x85; // adcon0 kaydedicisine de�er ata analog okumay� ba�lat�r
    while(ADC0==0x085){} //analog giri� alma bitene kadar d�ng�de kal
    h=adrh<<8; //y�ksek seviye registerdaki veriyi bit d�zeyi kayd�r h de�i�kenine ata
    l=adrl;   // d���k seviye registerdaki veryiyi l de�i�kenine ata
    a=l+h;// l ve h de�ikenlerini topla a de�i�kenine ata
    return a;// a de�erini d�nd�r
 }

void main()
{ 
   delay_ms(100);
   lcd_init();
   ADC0=0X85;//ADCON0 KAYDED�C�S�NE DE�ER ATA
   ADC1=0X8f;//ADCON1 KAYDED�C�S�NE DE�ER ATA
   while(TRUE)
 {  deger=analog_oku(0);//analog_oku fonksiyonundan d�nd�r�len de�eri deger de�i�kenine ata
    gerilim=deger*0.9765625; //deger fadesini ��z�n�rl�kle(mV) �arp
    sicaklik=(gerilim/10);//sicakl�k de�i�kenine gerilim/10 de�erini ata
    lcd_gotoxy(1,1);//lcd ilk sat�r ilk s�tuna git
    printf(lcd_putc,"sicaklik=%fC",sicaklik);//sicaklik float de�i�kenini lcd'ye bast�r
    delay_ms(200);
 }
}
