//PROJE2
#pragma config[1] = 0xF1 // Osilat�r: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
#pragma config[3] = 0xFE // Watchdog Timer kapal�

void ayarlar();
void bekle(unsigned long t);	// t milisaniye gecikme sa�layan fonksiyon tan�m�
void PWMayar();

void main()
{
    unsigned int deger;
 
    PWMayar();
	ayarlar();
    PORTC=0;
anadongu:
    
	bekle(1);	
	GO=1;
	while(GO);
	deger=ADRESH; //okunan analog degerin digital karsiligi, deger degiskenine at�l�yor
    CCPR1L=deger;
   // CCPR2L=deger;
   //PORTC=deger;
    

goto anadongu;
	
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

void ayarlar()	// B�t�n ba�lang�� ayarlar�n�n tamamland��� k�s�m
{	
	GIE=0;			// B�t�n kesmeleri kapat
	TRISA=0xFF;
	TRISB=0xFF;
	TRISC=0x00;	
	TRISD=0x00;		
	TRISE=0xFF;
	
	PORTC=0x00;		
	PORTD=0x00;
	
	ADCON0=0b.0100.0001;;
	ADCON1=0b.0000.0000;;
}
void PWMayar()
{
	PR2=0XFF;		//Periyod yazmac�(Timer2 peryodu=255)
	
	CCP1CON=0;		//PWM MODE OFF
	CCPR1L=0;		
	CCP1CON.4=0;	
	CCP1CON.5=0;
	
	CCP2CON=0;		//PWM MODE OFF
	CCPR2L=0;		
	CCP2CON.4=0;	
	CCP2CON.5=0;
	
	TRISC.2=0;
	TRISC.1=0;
			
	T2CON = 0b.0000.0100; // TMR2 ON, PRESCALE 1:1, POSTSCALE 1:1

	CCP1CON=0b.0000.1100; //CCP1 ON
	//CCP2CON=0b.0000.1100; //CCP2 OFF
}