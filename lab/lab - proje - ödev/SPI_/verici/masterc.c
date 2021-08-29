#pragma config[1] = 0xF1 // Osilat�r: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
#pragma config[3] = 0xFE // Watchdog Timer kapal�

void ayarlar();
void I2Cayar();
void bekle(unsigned long t);   // t milisaniye gecikme sa�layan fonksiyon tan�m�
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
void ayarlar()   // B�t�n ba�lang�� ayarlar�n�n tamamland��� k�s�m
{   
   GIE=0;         // B�t�n kesmeleri kapat
   TRISA=0xFF;
   TRISB=0xFF;
  // TRISE=0xFF;
   TRISD=0x00; 
   TRISC=0xD0;
   PORTC=0x00;     
}
//////////////////////////////////////////////////////////////////////////////////

void I2Cayar()
{
    TRISC.3=1; //I2C SCL Ayar�
	TRISC.4=1; //I2C SDA Ayar�
	SSPCON1.3=1; //I2C Master Modu se�
	SSPCON1.2=0;
	SSPCON1.1=0;
	SSPCON1.0=0;
	SSPADD=0x0A; //100kHZ H�z Modu se�
	SSPEN=1; //MSSP'yi Etkinle�tir
	ADCON0=0b.0000.0001; //ADC Etkinle�tir
	ADCON1=0b.0000.0000; //ADC H�z� FClock/2
}
//////////////////////////////////////////////////////////////////////////////////////////////////

void bekle(unsigned long t)   //t milisaniye gecikme sa�lar
{
   unsigned x;
   
   for(;t>0;t--)
      for(x=140;x>0;x--)
         nop();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

