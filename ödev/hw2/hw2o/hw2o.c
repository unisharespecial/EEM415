#pragma config[1] = 0xF1 // Osilatör: XT#pragma config[1] = 0xF1 // Osilatör: XT
void ayarlar();
void bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý
void main()
{
	ayarlar();
anadongu:
  bekle(1);	// Acquisition Time(Sample & Hold kapasitörünün þarj olmasý için gerekli zaman)
  INTCON=0x90; 

PWM_dongu:
	PORTC.0=1;
   	bekle(2); 
    	PORTC.0=0;
    	bekle(2);
goto PWM_dongu;

goto anadongu;
//-----------------------------------------------	
}
void bekle(unsigned long t)	//t milisaniye gecikme saðlar
{
	unsigned x;
	t=t/2;
	for(;t>0;t--)
		for(x=35;x>0;x--)
			nop();
}
void ayarlar()	// Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
{	
	GIE=1;			// Bütün kesmeleri ac
	TRISA=0xFF;
	TRISB=0xFF;
	TRISC=0x00;	
	TRISD=0x00;		
	TRISE=0xFF;
	PORTC=0x00;		
	PORTD=0x00;
	//ADCON0=0b.0100.0001;// Anlog kanal 0 aktif, A/D conversion is not in progress
	//ADCON1=0b.0000.0000;
}
//////////////////////////////////////////////////////////////////////////////////////////////////

