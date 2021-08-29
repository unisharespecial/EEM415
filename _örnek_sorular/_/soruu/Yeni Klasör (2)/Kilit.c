#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý

void ayarlar();
void bekle(unsigned long t);	

void main()
{
    unsigned int deger;
	ayarlar();

	anadongu:
	
	PORTD.0 = 1;	//	mavi ledi yak
	
	if(PORTB.0==0)	//	BUTTON_1'e basýldýysa
	{
		PORTD.0 = 0;	//	mavi ledi söndür
		PORTD.1 = 1;	//	yeþil ledi yak
				
		GO=1;	//	ADC çevrimini baþlat
		while(GO);
		deger=ADRESH; //okunan analog deðerin digital karþýlýðýný deger deðiþkenine at

    	TMR0ON = 1;	// Timer0'ý saymaya baþlat
		

		while(TMR0L < deger);	//	Timer0 "deger" deðiþkenindeki deðere ulaþana kadar say
		bekle(3000);
				
		PORTD.1 = 0;	//	yeþil ledi söndür
		PORTD.0 = 1;	//	mavi ledi yak
				
 		
	}
	goto anadongu;
//-----------------------------------------------

}

//////////////////////////////////////////////////////////////////////////////////////////////////

void ayarlar()	
{	

  	GIE=0;			// Bütün kesmeleri kapat
	TRISA=0xFF;		// PORTA giriþ
	TRISB=0xFF;		// PORTB giriþ	
	TRISD=0x00;		// PORTD çýkýþ

 	PORTD=0x00;

	ADCON0=0b.0100.0001;	//	ADC ayarlarý
	ADCON1=0b.0000.0000;
	
	T0CON = 0b.1101.1000;	// Timer0 ayarlarý
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void bekle(unsigned long t)	//t milisaniye gecikme saðlar
{
	unsigned x;
	
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
