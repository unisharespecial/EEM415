#pragma config[1] = 0xF1 // Osilat�r: XT#pragma config[1] = 0xF1 // Osilat�r: XT
void ayarlar();
void deger();	
void bekle(unsigned long t);
void deger()
{

	GO=1;	// adc cevrimi baslar
	while(GO);	//cevirme bitene kadar calisir, cevirme bitince go=0 olur
	PORTC=ADRESH;	//adc'den okunan deger PORTC ye aktarilirak sonuc gozlemlenir.
}

void main()
{
	
	ayarlar();

//-----------------------------------------------	
anadongu:
	INTCON=0x90; 
	bekle(1); // Acquisition Time(Sample & Hold kapasit�r�n�n �arj olmas� i�in gerekli zaman)
    unsigned y=0;
    while(y==0)    
	deger();        

goto anadongu;
//-----------------------------------------------	
}

//////////////////////////////////////////////////////////////////////////////////////////////////


void ayarlar()	// B�t�n ba�lang�� ayarlar�n�n tamamland��� k�s�m
{	
	GIE=1;			// B�t�n kesmeleri ac
	TRISA=0xFF;
	TRISB=0xFF;
	TRISC=0x00;	
	TRISD=0x00;		
	TRISE=0xFF;
	
	PORTC=0x00;		
	PORTD=0x00;
	
	ADCON0=0b.0100.0001;// Anlog kanal 0 aktif, A/D conversion is not in progress
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
