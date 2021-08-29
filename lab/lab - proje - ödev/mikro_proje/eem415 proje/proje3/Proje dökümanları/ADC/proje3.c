
#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý

void ayarlar();
void seriTXayar();
void serigonder(unsigned deger);
void bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý

void main()
{	
	unsigned sayi='0';
	unsigned sayi1='0';
	ayarlar();

//-----------------------------------------------	
anadongu:
	bekle(10);
	GO=1;
	while(GO);
	sayi=ADRESH; //okunan analog degerin digital karsiligi, sayi degiskenine atýlýyor
	portc=sayi;
	serigonder(sayi);
	bekle(10);
	serial(sayi1);
	
goto anadongu;
//-----------------------------------------------	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void ayarlar()	// Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
{	
	GIE=0;			// Bütün kesmeleri kapat
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
	
	ADCON0=0b.0100.0001;;
	ADCON1=0b.0000.0000;;
	seriTXayar();
	seriRXayar();
	
}
//////////////////////////////////////////////////////////////////////////////////


void serigonder(unsigned deger)	 // Seri porttan veri gönderir
{	
	while(!TXIF);
	nop(); nop(); nop(); nop();
	TXREG=deger;
}

//////////////////////////////////////////////////////////////////////////////////


void serial(unsigned deger)	 // Seri porttan veri gönderir
{	
	while(!RXIF);
	nop(); nop(); nop(); nop();
	deger=RXREG;
}


//////////////////////////////////////////////////////////////////////////////////


void seriTXayar()	// Seri Portu veri göndermeye hazýr hale getirir
{
	TRISC.6=0;
	TRISC.7=1;
	SPBRG=25;	// Baud Rate=9.6k
	BRGH=1;		// Yüksek Hýz
	SYNC=0;		// Asenkron mod
	SPEN=1;		// Seri port etkin
	TXIE=0;
	TX9=0;		// 8 bit Veri Gönderme
	TXEN=1;	// Gönderme etkin	
}

//////////////////////////////////////////////////////////////////////////////////


void seriRXayar()	// Seri Portu veri göndermeye hazýr hale getirir
{
	TRISC.6=1;
	TRISC.7=0;
	SPBRG=25;	// Baud Rate=9.6k
	BRGH=1;		// Yüksek Hýz
	SYNC=0;		// Asenkron mod
	SPEN=1;		// Seri port etkin
	RXIE=0;
	RX9=0;		// 8 bit Veri Gönderme
	RXEN=1;	// Gönderme etkin	
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

