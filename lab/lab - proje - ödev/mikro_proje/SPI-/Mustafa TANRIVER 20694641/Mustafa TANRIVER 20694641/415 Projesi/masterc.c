#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý

void ayarlar();
void SPIayar();
void bekle(unsigned long t);   // t milisaniye gecikme saðlayan fonksiyon tanýmý
void main()
{  
   
   
   ayarlar();

//-----------------------------------------------   
while(1)
{
if(PORTA.0==1)
{PORTD.0=0;
   SSPBUF=0x1;
   while(!SSPIF);
   SSPIF=0;
   PORTD.0=1;
 bekle(1000);
  }

if(PORTA.1==1)
{PORTD.0=0;
   SSPBUF=0x2;
   while(!SSPIF);
   SSPIF=0;
   PORTD.0=1;
 bekle(1000);
  }

if(PORTA.2==1)
{PORTD.0=0;
   SSPBUF=0x3;
   while(!SSPIF);
   SSPIF=0;
   PORTD.0=1;
 bekle(1000);
  }
if(PORTA.3==1)
{PORTD.0=0;
   SSPBUF=0xA;
   while(!SSPIF);
   SSPIF=0;
   PORTD.0=1;
 bekle(1000);
  }

if(PORTA.4==1)
{PORTD.0=0;
   SSPBUF=0x4;
   while(!SSPIF);
   SSPIF=0;
   PORTD.0=1;
 bekle(1000);
  }
if(PORTA.5==1)
{PORTD.0=0;
   SSPBUF=0x5;
   while(!SSPIF);
   SSPIF=0;
   PORTD.0=1;
 bekle(1000);
  }

if(PORTC.6==1)
{PORTD.0=0;
   SSPBUF=0x6;
   while(!SSPIF);
   SSPIF=0;
   PORTD.0=1;
 bekle(1000);
  }

if(PORTB.0==1)
{PORTD.0=0;
   SSPBUF=0xB;
   while(!SSPIF);
   SSPIF=0;
   PORTD.0=1;
 bekle(1000);
  }
if(PORTB.1==1)
{PORTD.0=0;
   SSPBUF=0x7;
   while(!SSPIF);
   SSPIF=0;
   PORTD.0=1;
 bekle(1000);
  }
if(PORTB.2==1)
{PORTD.0=0;
   SSPBUF=0x8;
   while(!SSPIF);
   SSPIF=0;
   PORTD.0=1;
 bekle(1000);
  }
if(PORTB.3==1)
{PORTD.0=0;
   SSPBUF=0x9;
   while(!SSPIF);
   SSPIF=0;
   PORTD.0=1;
 bekle(1000);
  }
if(PORTB.4==1)
{PORTD.0=0;
   SSPBUF=0xC;
   while(!SSPIF);
   SSPIF=0;
   PORTD.0=1;
 bekle(1000);
  }
if(PORTB.5==1)
{PORTD.0=0;
   SSPBUF=0xF;
   while(!SSPIF);
   SSPIF=0;
   PORTD.0=1;
 bekle(1000);
  }
if(PORTB.6==1)
{PORTD.0=0;
   SSPBUF=0xE;
   while(!SSPIF);
   SSPIF=0;
   PORTD.0=1;
 bekle(1000);
  }
if(PORTB.7==1)
{PORTD.0=0;
   SSPBUF=0xD;
   while(!SSPIF);
   SSPIF=0;
   PORTD.0=1;
 bekle(1000);
  }

if(PORTC.7==1)
{PORTD.0=0;
   SSPBUF=0x0;
   while(!SSPIF);
   SSPIF=0;
   PORTD.0=1;
 bekle(1000);
  }


}

   
  

//-----------------------------------------------   
}

//////////////////////////////////////////////////////////////////////////////////////////////////
void ayarlar()   // Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
{   
   GIE=0;         // Bütün kesmeleri kapat
   TRISA=0xFF;
   TRISB=0xFF;
  // TRISE=0xFF;
   TRISD=0x00; 
   TRISC=0xD0;
   PORTC=0x00;     
   SPIayar();

   
}
//////////////////////////////////////////////////////////////////////////////////

void SPIayar()   // Seri Portu veri göndermeye hazýr hale getirir
{
   //SPBRG=25;   // Baud Rate=9.6k
   BRGH=1;      // Yüksek Hýz
   SYNC=1;      // senkron mod
   SMP=0;
   CKE=0;
   BF=0;
   //WCOL=0;
   //SSPOV=0;
   SSPEN=0;
   SSPEN=1;
   CKP=1;
SSPCON1.3=0;
SSPCON1.2=0;
SSPCON1.1=0;
SSPCON1.0=1;
ADCON0.0=0; // A/D modülü kapat.
ADCON1.3=0;
ADCON1.2=1;
ADCON1.1=1;

}

//////////////////////////////////////////////////////////////////////////////////////////////////

void bekle(unsigned long t)   //t milisaniye gecikme saðlar
{
   unsigned x;
   
   for(;t>0;t--)
      for(x=140;x>0;x--)
         nop();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

