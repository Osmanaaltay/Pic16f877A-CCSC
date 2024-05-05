#include<16F877A.h>
#include<stdlib.h>
#fuses HS,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NOWRT,NODEBUG,NOCPD
#use delay(clock=4M)
#byte TRISD  =0X08
void main()

{int sayi;
TRISD=0X00;
    while(1)
    {sayi=rand() % 100 + 1;
    TRISD=sayi;
   }

}
