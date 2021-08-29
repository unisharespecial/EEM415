#include "INT18XXX.H"


#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý

void ayarlar()
{
	TRISA.0=1; //Analog Giriþ Portu
	TRISC.3=1; //I2C SCL Ayarý
	TRISC.4=1; //I2C SDA Ayarý
	SSPCON1.3=1; //I2C Master Modu seç
	SSPCON1.2=0;
	SSPCON1.1=0;
	SSPCON1.0=0;
	SSPADD=0x0A; //100kHZ Hýz Modu seç
	SSPEN=1; //MSSP'yi Etkinleþtir
	ADCON0=0b.0000.0001; //ADC Etkinleþtir
	ADCON1=0b.0000.0000; //ADC Hýzý FClock/2	
}
void bekle(unsigned long t)	//t milisaniye gecikme saðlar
{
	unsigned x;
	
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}
void i2cgonder(uns8 data)
{
	SEN=1; //I2C Start Biti Yolla
	while(SEN); //Baþlatma iþlemi geçerli olana kadar bekle
	SSPIF=0; //SSPIF Bayraðýný Sýfýrla
	SSPBUF=0x02; //Seçilecek I2C Cihazýnýn Adresini Gönder ve Yazma Bitini Aktifleþtir
	while(!SSPIF); //Adres Gönderilene Kadar Bekle
	SSPIF=0; //SSPIF Bayraðýný Sýfýrla
	SSPBUF=data; //Seçilen Cihaza Veriyi Gönder
	while(!SSPIF); //Veri Gönderilene Kadar Bekle
	SSPIF=0; //SSPIF Bayraðýný Sýfýrla
	PEN=1; //I2C Stop Biti Yolla
	while(PEN); //Bitirme iþlemi geçerli olana kadar bekle
	SSPIF=0; //SSPIF Bayraðýný Sýfýrla
}
uns8 data;
void main()
{
	ayarlar(); //Ayarlarý yap
	while(1) //Her zaman
	{
		bekle(10); //Sampla Hold kapasitörünün deþarjý için 10 ms bekle 
		GO=1; //Çevirme iþlemini baþlat
		while(GO); //Ýþlem bitene kadar bekle
		data=ADRESH; //Çevrilen deðerin üst 8 bitini kaydet
		i2cgonder(data); //Kaydedilen deðeri karþýya I2C ile yolla
	}
}

		