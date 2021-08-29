#pragma config[1] = 0xF1 // Osilat�r: XT#pragma config[1] = 0xF1 // Osilat�r: XT
void ayarlar();
void bekle(unsigned long t);	// t milisaniye gecikme sa�layan fonksiyon tan�m�

void main()
{
	
	ayarlar();

//-----------------------------------------------

anadongu:
	GO=1;	// adc cevrimi baslar
	bekle(1);	// Acquisition Time(Sample & Hold kapasit�r�n�n �arj olmas� i�in gerekli zaman)
	//INTCON=0x90; // 
     while(GO);	//cevirme bitene kadar calisir, cevirme bitince go=0 olur
	PORTC=ADRESH;	//adc'den okunan deger PORTC ye aktarilirak sonuc gozlemlenir.          
goto anadongu;

//-----------------------------------------------	
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
	TRISA=0xFF;		// A portu giri� yap�ld�
	TRISC=0x00;		// C portu ��k�� yap�ld�
	
	ADCON0=0b.0100.0001;// Anlog kanal 0 aktif, A/D conversion is not in progress
	ADCON1=0b.0000.0000;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
