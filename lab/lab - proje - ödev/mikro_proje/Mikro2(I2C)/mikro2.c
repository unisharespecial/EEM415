#include "INT18XXX.H"


#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý

void ayarlar()
{
	TRISC.3=1; //I2C SCL Ayarý
	TRISC.4=1; //I2C SDA Ayarý
	TRISB=0x00;
	PORTB=0x00;
	SSPCON1.3=1; //I2C Master Modu seç
	SSPCON1.2=0;
	SSPCON1.1=0;
	SSPCON1.0=0;
	SSPADD=0x0A; //100kHZ Hýz Modu seç
	SSPEN=1; //MSSP'yi Etkinleþtir
}
uns8 data;
void main()
{
	ayarlar(); //Ayarlarý yap
	while(1) //Her zaman
	{
		SEN=1; //I2C Start Biti Yolla
		while(SEN); //Baþlatma iþlemi geçerli olana kadar bekle
		SSPIF=0; //SSPIF Bayraðýný Sýfýrla
		SSPBUF=0b.1001.1010; //Adres yolla ve yazma bitini aktifleþtir
		while(!SSPIF); //Adres Gönderilene Kadar Bekle	
		SSPIF=0;
		SSPBUF=0b.0000.0000; //Komut biti yolla (KOmut=00000000 olurse derece okunur)
		while(!SSPIF); //Komut biti yollanana kadar bekle
		SSPIF=0; //SSPIF bayraðý sýfýrla
		RSEN=1; //Tekrar baþlat
		while(RSEN); //Tekrar baþlatma aktifleþene kadar bekle
		SSPIF=0; //SSPIF bayraðýný sil
		SSPBUF=0b.1001.1011; //Adresi gönder ve okuma bitini aktifleþtir
		while(!SSPIF); //Adres gönderilene kadar bekle
		SSPIF=0; //SSPIF bayraðýný sýfýrla
		RCEN=1; //Master alým bitini aktfileþtir (derece okumak için)
		while(RCEN); //Aktifleþene kadar bekle
		data=SSPBUF; //8'bitlik dereceyi al
		PEN=1; //Gönderim iþlemini durdur
		while(PEN); //Durana kadar bekle
		SSPIF=0; //SSPIF bayraðýný sil
		PORTB=data; //Okunan veriyi PORT'e çýk			
	}
}

		