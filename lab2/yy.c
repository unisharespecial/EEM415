#pragma config[1] = 0xF1 // Osilat�r: XT#pragmaconfig[1] = 0xF1 // Osilat�r: XT
void ayarlar();
void bekle(unsigned long t);	// t milisaniye gecikme sa�layan fonksiyon tan�m�
	
void main()
{
	ayarlar();
anadongu:
    PORTC.0=1;
	bekle(0xFF); // %50 High � ADC kullan�ld���nda ADRESH de�eri olmal�d�r
	PORTC.0=0;
	bekle(0xFF-0xFF); // %50 Low � ADC kullan�ld���nda 0xFF-ADRESH de�eri olmal�d�r
	bekle(1);	// Acquisition Time(Sample&Holdkapasit�r�n�n �arj olmas� i�in gerekli zaman)

	nop();
goto anadongu;
//-----------------------------------------------	
}
void bekle(unsigned long t)	//t milisaniye gecikme sa�lar
{
	unsigned x;
	t=t/2;
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}
void ayarlar()	// B�t�n ba�lang�� ayarlar�n�n tamamland��� k�s�m
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
