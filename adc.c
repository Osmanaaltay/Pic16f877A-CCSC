#include <16F877A.h>
#device ADC=10
#fuses XT,NOWDT,NOLVP,NOBROWNOUT
#use delay(clock=4M)
#byte  ADC0 = 0x1f//ADCON0 KAYDEDÝCÝSÝNÝ ADRESLE
#byte  ADC1 = 0x9f//ADCON1 KAYDEDÝCÝSÝNÝ ADRESLE
#byte  adrh = 0x1E//ADRH   KAYDEDÝCÝSÝNÝ ADRESLE
#byte  adrl = 0x9E//ADRL   KAYDEDÝCÝSÝNÝ ADRESLE
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
    ADC0=0x85; // adcon0 kaydedicisine deðer ata analog okumayý baþlatýr
    while(ADC0==0x085){} //analog giriþ alma bitene kadar döngüde kal
    h=adrh<<8; //yüksek seviye registerdaki veriyi bit düzeyi kaydýr h deðiþkenine ata
    l=adrl;   // düþük seviye registerdaki veryiyi l deðiþkenine ata
    a=l+h;// l ve h deðikenlerini topla a deðiþkenine ata
    return a;// a deðerini döndür
 }

void main()
{ 
   delay_ms(100);
   lcd_init();
   ADC0=0X85;//ADCON0 KAYDEDÝCÝSÝNE DEÐER ATA
   ADC1=0X8f;//ADCON1 KAYDEDÝCÝSÝNE DEÐER ATA
   while(TRUE)
 {  deger=analog_oku(0);//analog_oku fonksiyonundan döndürülen deðeri deger deðiþkenine ata
    gerilim=deger*0.9765625; //deger fadesini çözünürlükle(mV) çarp
    sicaklik=(gerilim/10);//sicaklýk deðiþkenine gerilim/10 deðerini ata
    lcd_gotoxy(1,1);//lcd ilk satýr ilk sütuna git
    printf(lcd_putc,"sicaklik=%fC",sicaklik);//sicaklik float deðiþkenini lcd'ye bastýr
    delay_ms(200);
 }
}
