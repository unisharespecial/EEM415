//Polling Tabanl� Klavyeden Bas�lan Butonu Alg�lama

// Mikrodenetleyici Timer ve Clock Ayarlamalar�
#pragma config[1] = 0xF1 // Osilat�r: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
#pragma config[3] = 0xFE // Watchdog Timer kapal�

void ayarlar(); // Port ayarlamalar�n�n yap�ld��� fonksiyonlar�n tan�m�
void bekle(unsigned long t);	// t milisaniye gecikme sa�layan fonksiyon tan�m�
void kesme();	


void kesme() //kesme gelince yapilacak komutlar, kesmede calisacak fonksiyon main fonksiyonunun ustunde yazilir...	
{
	INTCON=0xFF; // kesmeler acilir RBO/INT0 girisi interrupt enable edilir. 
 	goto anadongu;
		GIE=1;	//kesmeler acilir, yeni kesme gelmesine musade edilir
}	
void main()
{	
	ayarlar(); // Port Ayarlamalar� Program�n ilk ad�m�nda yap�l�yor.

//-----------------------------------------------	
anadongu:
	PORTB.0=1; // Port B' nin 0. biti high yap�l�yor
	PORTB.1=0; // Port B' nin 1. biti low yap�l�yor
	PORTB.2=0; // Port B' nin 2. biti low yap�l�yor
	if(PORTB.0==1){ // Port B' nin 0. biti high oldu�u s�rece, input bitlerine tek tek bak�lacak
	if(PORTB.5 == 1){ // Port B' nin 5. biti high olmu�sa g�stergede 1 g�ster.
		PORTD=0x06;
		bekle(300);
		PORTD=0;
	}
	if(PORTB.4 == 1){ // Port B' nin 4. biti high olmu�sa g�stergede 2 g�ster.
		PORTD=0x5B;
		bekle(300);
		PORTD=0;
	}
	if(PORTB.3 == 1){ // Port B' nin 3. biti high olmu�sa g�stergede 3 g�ster.
		PORTD=0x4F;
		bekle(300);
		PORTD=0;
	}
	if(PORTB.6 == 1){// Port B' nin 6. biti high olmu�sa g�stergede 0 g�ster.
		PORTD=0x03F;
		bekle(300);
		PORTD=0;
	}
	}
	PORTB.1=1; // Port B' nin 1. biti high, 0 ve 2. bitleri low yap�l�r.
	PORTB.0=0;
	PORTB.2=0;
	if(PORTB.1==1){ // Port B' nin 1. biti high oldu�u s�rece, input bitlerine tek tek bak�lacak
	if(PORTB.5 == 1){ // Port B' nin 5. biti high olmu�sa g�stergede 4 g�ster.
		PORTD=0x66;
		bekle(300);
		PORTD=0;
	}
	if(PORTB.4 == 1){ // Port B' nin 4. biti high olmu�sa g�stergede 5 g�ster.
		PORTD=0x6D;
		bekle(300);
		PORTD=0;
	}
	if(PORTB.3 == 1){ // Port B' nin 3. biti high olmu�sa g�stergede 6 g�ster.
		PORTD=0x7D;
		bekle(300);
		PORTD=0;
	}
	}
	PORTB.2=1; // Port B' nin 2. biti high, 0 ve 1. bitleri low yap�l�r.
	PORTB.0=0;
	PORTB.1=0;
	if(PORTB.2==1){ // Port B' nin 2. biti high oldu�u s�rece, input bitlerine tek tek bak�lacak
	if(PORTB.5 == 1){ // Port B' nin 5. biti high olmu�sa g�stergede 7 g�ster.
		PORTD=0x07;
		bekle(300);
		PORTD=0;
	}
	if(PORTB.4 == 1){ // Port B' nin 4. biti high olmu�sa g�stergede 8 g�ster.
		PORTD=0x7F;
		bekle(300);
		PORTD=0;
	}
	if(PORTB.3 == 1){ // Port B' nin 3. biti high olmu�sa g�stergede 9 g�ster.
		PORTD=0x6F;
		bekle(300);
		PORTD=0;
	}
}

goto anadongu; // D�ng� ba��na d�n��
//-----------------------------------------------	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void ayarlar()	// B�t�n ba�lang�� ayarlar�n�n tamamland��� k�s�m
{	
	GIE=0;			// B�t�n kesmeleri kapat
	TRISA=0xFF;		// Port A input
	TRISB=0xF8;		// Port B' nin 0-3 aras� bitleri output, 4-7 aras� bitleri input 
	TRISC=0;		// Port C output	
	TRISD=0;		// Port D output
	TRISE=0;		// Port E output

	// Program ilk �al��t�r�ld���nda ��k��larda de�er g�r�lmemesi i�in ilk ��k�� de�erleri 0 al�n�r.	
	PORTC=0;		
	PORTD=0;
	PORTB=0;
		
}

void bekle(unsigned long t)	//t milisaniye gecikme sa�lar
{
	unsigned x;
	
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
