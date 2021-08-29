void init();	//Baslangýc ayarlarý fonksiyonu
void spi_init();//SPI Ayarlarý fonksiyonu
uns8 spi_gonder_al(uns8);	//SPI veri gonderme fonksiyonu 
void bekle(unsigned long);	//Bekleme fonksiyonu

bit e @ PORTE.0, rs @ PORTE.1, rw @ PORTE.2;
unsigned disp @ PORTD;

void main()
{
	uns8 gelen;
	init();		//baslangýc ayarlarý yapýlýyor
dongu:
	SSPBUF=0x00;
	while(!SSPIF);  //	Buffer kontrolü
	gelen=SSPBUF;  
  	SSPIF = 0;
	PORTB=gelen;
	if(gelen == 0x01) 
		PORTD=0x01;
	if(gelen == 0x02) 
		PORTD=0x02;
	if(gelen == 0x04) 
		PORTD=0x03;
	if(gelen == 0x08) 
		PORTD=0x04;
	if(gelen == 0x10) 
		PORTD=0x05;
	if(gelen == 0x20) 
		PORTD=0x06;
	if(gelen == 0x40) 
		PORTD=0x07;
	if(gelen == 0x80) 
		PORTD=0x08;
	bekle(100);
	goto dongu;
}
void init()
{
	TRISA=0XFF;
	TRISE=0x00;
	TRISD=0x00;	// PORTD.0 = CS, PORTD çýkýþ yapýlýyor.
	TRISC=0x00;	//	SPI pinleri çýkýþ yapýlýyor.
	TRISC.3=1;
	TRISC.5=1;
	TRISB=0x00;	//  Buton = PORTB.0, giriþ yapýlýyor
	spi_init();	// SPI Ayarlarý yapýlýyor
}
void spi_init()
{
	CKP = 0 ;	//Clock polarity 
	CKE=0;		//Clock edge select
	//SPI Slave Mode
	SSPCON1.3=0;
	SSPCON1.2=1;
	SSPCON1.1=0;
	SSPCON1.0=1;
	SSPEN=1;	//Synchronous Serial Port Enable bit //5. bit
	SSPOV=0;	// Receive overflow indicator bit
	WCOL=0;		// Write collision detect bit
}
uns8 spi_gonder_al(uns8 data1)
{
	uns8 temp;
	PORTD.0=0;	//CS = 0 
	SSPBUF = data1;		//Instruction register verisi
	while(!SSPIF);  //	Buffer kontrolü
	temp=SSPBUF;  
  	SSPIF = 0;
	PORTD.0=1;	//CS=1
	PORTB=temp;
	return temp;
}
void bekle(unsigned long t)	/*t milisaniye gecikme saðlar*/
{
	unsigned x;	
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}
