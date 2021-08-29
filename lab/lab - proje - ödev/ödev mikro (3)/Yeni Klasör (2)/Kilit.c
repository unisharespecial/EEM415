#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
#pragma config[3] = 0xFE // Watchdog Timer kapal�

void ayarlar();
void bekle(unsigned long t);
void kesme() //kesme gelince yapilacak komutlar, kesmede calisacak fonksiyon main fonksiyonunun ustunde yazilir...	
{
    INTCON=0x90; // kesmeler acilir RBO/INT0 girisi interrupt enable edilir.
    T0CON=0b.0000.0101;//Timer baslatilir.
   	TMR0ON = 1;	// Timer0'� saymaya ba�lat
    PORTD.1 = 0;	//	ye�il ledi s�nd�r
	PORTD.0 = 1;	//	mavi ledi yak
     nop();
	 T0CON=0b.0000.0000;//Timer durdurulur.
     TMR0ON=0;
     PORTD.1=1;
     PORTD.0=0;	 
	 TMR0H=0b.0000;
	 nop();

    INT0IF=0;  // yeni kesmeler gelmesi icin butona bagli olan INT0 portundaki interrupt flagi kapatilir.
	GIE=1;	//kesmeler acilir, yeni kesme gelmesine musade edilir	

}		

void main()
{
 
	ayarlar();

	anadongu: 
   

	 
     	
 		bekle(1000);

	goto anadongu;
//-----------------------------------------------

}

//////////////////////////////////////////////////////////////////////////////////////////////////

void ayarlar()	
{	

  	GIE=0;			// B�t�n kesmeleri kapat
	TRISA=0xFF;		// PORTA giri�
	TRISB=0xFF;		// PORTB giri�	
	TRISD=0x00;		// PORTD ��k��

 	PORTD=0x00;

/*	ADCON0=0b.0100.0001;	//	ADC ayarlar�
	ADCON1=0b.0000.0000;*/
	
	T0CON = 0b.1101.1000;	// Timer0 ayarlar�
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void bekle(unsigned long t)	//t milisaniye gecikme sa�lar
{
	unsigned x;
	
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
