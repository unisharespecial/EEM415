#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
#pragma config[3] = 0xFE // Watchdog Timer kapal�

void ayarlar();
void bekle(unsigned long t);	

void main()
{
    unsigned int deger;
	ayarlar();

	anadongu:
	
	PORTD.0 = 1;	//	mavi ledi yak
	
	if(PORTB.0==0)	//	BUTTON_1'e bas�ld�ysa
	{
		PORTD.0 = 0;	//	mavi ledi s�nd�r
		PORTD.1 = 1;	//	ye�il ledi yak
				
		GO=1;	//	ADC �evrimini ba�lat
		while(GO);
		deger=ADRESH; //okunan analog de�erin digital kar��l���n� deger de�i�kenine at

    	TMR0ON = 1;	// Timer0'� saymaya ba�lat
		

		while(TMR0L < deger);	//	Timer0 "deger" de�i�kenindeki de�ere ula�ana kadar say
		bekle(3000);
				
		PORTD.1 = 0;	//	ye�il ledi s�nd�r
		PORTD.0 = 1;	//	mavi ledi yak
				
 		
	}
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

	ADCON0=0b.0100.0001;	//	ADC ayarlar�
	ADCON1=0b.0000.0000;
	
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
