
#pragma config[1] = 0xF1 // Osilat�r: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
#pragma config[3] = 0xFE // Watchdog Timer kapal�

char	tus_oku();
char	TUS;
char	TUS1;
char	TUS2;
void	ayarlar();
void 	bekle(unsigned long t);	// t milisaniye gecikme sa�layan fonksiyon tan�m�


void main()
{
	ayarlar();

//-----------------------------------------------	
anadongu:
	bekle(1);	// Acquisition Time(Sample & Hold kapasit�r�n�n �arj olmas� i�in gerekli zaman)
  	while(PORTB.0==1)
 {
	PORTD=0x00;
	if (PORTB.1==1)
	{PORTD=0xF1;bekle(1);}
	if (PORTB.2==1)
	{PORTD=0xF2;bekle(1);}
	PORTE=tus_oku();
 }   
	PORTD=0x00;
	goto anadongu;
//-----------------------------------------------	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void ayarlar()	// B�t�n ba�lang�� ayarlar�n�n tamamland��� k�s�m
{	
	GIE=0;			// B�t�n kesmeleri kapat
	TRISC=0xFF;		// C portu giri� yap�ld�
	TRISD=0;		// D portu ��k�� yap�ld�
	TRISB=0xFF;		// B portu ��k�� yap�ld�
	TRISE=0;		// E portu ��k�� yap�ld�
	
	PORTB=0;		// B portu ��k��lar� s�f�rland�
	PORTE=0;		// E portu ��k��lar� s�f�rland�	
	PORTD=0;		// D portu ��k��lar� s�f�rland�
	PORTC=0;		// C portu ��k��lar� s�f�rland�

	
	
}

////////////////////////////////////////////////////////////////////////////////////////////
char tus_oku()	// tarama keypad'�n okundu�u k�s�m
{

	TUS1=PORTC;
	bekle(5);
	TUS2=PORTC;
	bekle(5);
	if(TUS1<TUS2)
	{TUS=0x01;bekle(2);}
	if(TUS1>TUS2)
	{TUS=0x02;bekle(2);}	

	return TUS;	
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