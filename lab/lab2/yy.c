#pragma config[1] = 0xF1 // Osilatör: XT#pragmaconfig[1] = 0xF1 // Osilatör: XT
void ayarlar();
void bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý
	
void main()
{
	ayarlar();
anadongu:
    PORTC.0=1;
	bekle(0xFF); // %50 High – ADC kullanýldýðýnda ADRESH deðeri olmalýdýr
	PORTC.0=0;
	bekle(0xFF-0xFF); // %50 Low – ADC kullanýldýðýnda 0xFF-ADRESH deðeri olmalýdýr
	bekle(1);	// Acquisition Time(Sample&Holdkapasitörünün þarj olmasý için gerekli zaman)

	nop();
goto anadongu;
//-----------------------------------------------	
}
void bekle(unsigned long t)	//t milisaniye gecikme saðlar
{
	unsigned x;
	t=t/2;
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}
void ayarlar()	// Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
{	
	TRISA=0xFF;
	TRISB=0xFF;
	TRISC=0x00;	
	TRISD=0x00;		
	TRISE=0xFF;
	PORTC=0x00;		
	PORTD=0x00;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
