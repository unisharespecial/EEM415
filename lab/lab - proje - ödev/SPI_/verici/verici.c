void init();	//Baslang�c ayarlar� fonksiyonu
void spi_init();//SPI Ayarlar� fonksiyonu
void spi_gonder(uns8);	//SPI veri gonderme fonksiyonu 
void bekle(unsigned long);	//Bekleme fonksiyonu

void main()
{
	init();		//baslang�c ayarlar� yap�l�yor
dongu:
	if(PORTB.0 == 1 ){ 
		spi_gonder(0x01);
		bekle(200);
	}
	if(PORTB.1 == 1 ){ 
		spi_gonder(0x02);
		bekle(200);
	}

	if(PORTB.2 == 1 ){ 
		spi_gonder(0x04);
		bekle(200);
	}
	if(PORTB.3 == 1 ){ 
		spi_gonder(0x08);
		bekle(200);
	}
	goto dongu;
}
void init()
{
	TRISA=0XFF;
	TRISE=0x00;
	TRISD=0x00;	// PORTD.0 = CS, PORTD ��k�� yap�l�yor.
	TRISC=0x00;	//	SPI pinleri ��k�� yap�l�yor.
	//TRISC.5=1;
	TRISB=0xFF;	//  Buton = PORTB.0, giri� yap�l�yor
	spi_init();	// SPI Ayarlar� yap�l�yor
}
void spi_init()
{
	CKP = 0 ;	//Clock polarity 
	CKE=1;		//Clock edge select
	//SPI Master mode, Fosc\4
	SSPCON1.3=0;
	SSPCON1.2=0;
	SSPCON1.1=0;
	SSPCON1.0=0;
	//////////////////////
	SSPEN=1;	//Synchronous Serial Port Enable bit //5. bit
	SSPOV=0;	// Receive overflow indicator bit
	WCOL=0;		// Write collision detect bit
}
void spi_gonder(uns8 data1)
{
	uns8 temp;
	PORTD.0=0;	//CS = 0 
	SSPBUF = data1;		//Instruction register verisi
	while(!SSPIF);  //	Buffer kontrol�
  	SSPIF = 0;
	temp=SSPBUF;  //yedekleme i�lemi   
	PORTD.0=1;	//CS=1
}
void bekle(unsigned long t)	/*t milisaniye gecikme sa�lar*/
{
	unsigned x;	
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}


