
#pragma config[1] = 0xF1 // Osilat�r: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
#pragma config[3] = 0xFE // Watchdog Timer kapal�

void ayarlar();
void bekle(unsigned long t);	// t milisaniye gecikme sa�layan fonksiyon tan�m�

bit fan @ PORTD.0;

void main()
{
	unsigned sicaklik=0, hys=0, altsinir=0, ustsinir=0;
	
	ayarlar();

//-----------------------------------------------	
anadongu:

	CHS0=0;
	bekle(1);	// Acquisition Time(Sample & Hold kapasit�r�n�n �arj olmas� i�in gerekli zaman)
	GO=1;		// �evrimi ba�lat
	while(GO);	// �evrim bitti mi?
	sicaklik=ADRESH;
	
	CHS0=1;
	bekle(1);
	GO=1;		
	while(GO);	
	hys=ADRESH/2;
	
	ustsinir=128+hys;
	altsinir=128-hys;
	
	if(fan==0)
	{
		if(sicaklik>ustsinir)
			fan=1;
	}
	else
	{
		if(sicaklik<altsinir)
			fan=0;
	}

goto anadongu;
//-----------------------------------------------	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void ayarlar()	// B�t�n ba�lang�� ayarlar�n�n tamamland��� k�s�m
{	
	GIE=0;			// B�t�n kesmeleri kapat
	TRISA=0xFF;
	TRISB=0;
	TRISC=0;	
	TRISD=0;
	TRISE.0=1;
	TRISE.1=1;
	TRISE.2=1;
	
	PORTC=0;		
	PORTD=0;
	PORTB=0;
	
	ADCON0=0b.0100.0001;
	ADCON1=0b.0000.0000;
	
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