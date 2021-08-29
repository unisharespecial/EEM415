//Polling Tabanlý Klavyeden Basýlan Butonu Algýlama

// Mikrodenetleyici Timer ve Clock Ayarlamalarý
#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý

void ayarlar(); // Port ayarlamalarýnýn yapýldýðý fonksiyonlarýn tanýmý
void bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý
void kesme();	


void kesme() //kesme gelince yapilacak komutlar, kesmede calisacak fonksiyon main fonksiyonunun ustunde yazilir...	
{
	INTCON=0xFF; // kesmeler acilir RBO/INT0 girisi interrupt enable edilir. 
 	goto anadongu;
		GIE=1;	//kesmeler acilir, yeni kesme gelmesine musade edilir
}	
void main()
{	
	ayarlar(); // Port Ayarlamalarý Programýn ilk adýmýnda yapýlýyor.

//-----------------------------------------------	
anadongu:
	PORTB.0=1; // Port B' nin 0. biti high yapýlýyor
	PORTB.1=0; // Port B' nin 1. biti low yapýlýyor
	PORTB.2=0; // Port B' nin 2. biti low yapýlýyor
	if(PORTB.0==1){ // Port B' nin 0. biti high olduðu sürece, input bitlerine tek tek bakýlacak
	if(PORTB.5 == 1){ // Port B' nin 5. biti high olmuþsa göstergede 1 göster.
		PORTD=0x06;
		bekle(300);
		PORTD=0;
	}
	if(PORTB.4 == 1){ // Port B' nin 4. biti high olmuþsa göstergede 2 göster.
		PORTD=0x5B;
		bekle(300);
		PORTD=0;
	}
	if(PORTB.3 == 1){ // Port B' nin 3. biti high olmuþsa göstergede 3 göster.
		PORTD=0x4F;
		bekle(300);
		PORTD=0;
	}
	if(PORTB.6 == 1){// Port B' nin 6. biti high olmuþsa göstergede 0 göster.
		PORTD=0x03F;
		bekle(300);
		PORTD=0;
	}
	}
	PORTB.1=1; // Port B' nin 1. biti high, 0 ve 2. bitleri low yapýlýr.
	PORTB.0=0;
	PORTB.2=0;
	if(PORTB.1==1){ // Port B' nin 1. biti high olduðu sürece, input bitlerine tek tek bakýlacak
	if(PORTB.5 == 1){ // Port B' nin 5. biti high olmuþsa göstergede 4 göster.
		PORTD=0x66;
		bekle(300);
		PORTD=0;
	}
	if(PORTB.4 == 1){ // Port B' nin 4. biti high olmuþsa göstergede 5 göster.
		PORTD=0x6D;
		bekle(300);
		PORTD=0;
	}
	if(PORTB.3 == 1){ // Port B' nin 3. biti high olmuþsa göstergede 6 göster.
		PORTD=0x7D;
		bekle(300);
		PORTD=0;
	}
	}
	PORTB.2=1; // Port B' nin 2. biti high, 0 ve 1. bitleri low yapýlýr.
	PORTB.0=0;
	PORTB.1=0;
	if(PORTB.2==1){ // Port B' nin 2. biti high olduðu sürece, input bitlerine tek tek bakýlacak
	if(PORTB.5 == 1){ // Port B' nin 5. biti high olmuþsa göstergede 7 göster.
		PORTD=0x07;
		bekle(300);
		PORTD=0;
	}
	if(PORTB.4 == 1){ // Port B' nin 4. biti high olmuþsa göstergede 8 göster.
		PORTD=0x7F;
		bekle(300);
		PORTD=0;
	}
	if(PORTB.3 == 1){ // Port B' nin 3. biti high olmuþsa göstergede 9 göster.
		PORTD=0x6F;
		bekle(300);
		PORTD=0;
	}
}

goto anadongu; // Döngü baþýna dönüþ
//-----------------------------------------------	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void ayarlar()	// Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
{	
	GIE=0;			// Bütün kesmeleri kapat
	TRISA=0xFF;		// Port A input
	TRISB=0xF8;		// Port B' nin 0-3 arasý bitleri output, 4-7 arasý bitleri input 
	TRISC=0;		// Port C output	
	TRISD=0;		// Port D output
	TRISE=0;		// Port E output

	// Program ilk çalýþtýrýldýðýnda çýkýþlarda deðer görülmemesi için ilk çýkýþ deðerleri 0 alýnýr.	
	PORTC=0;		
	PORTD=0;
	PORTB=0;
		
}

void bekle(unsigned long t)	//t milisaniye gecikme saðlar
{
	unsigned x;
	
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
