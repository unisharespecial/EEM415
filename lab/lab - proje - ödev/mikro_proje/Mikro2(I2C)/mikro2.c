#include "INT18XXX.H"


#pragma config[1] = 0xF1 // Osilat�r: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
#pragma config[3] = 0xFE // Watchdog Timer kapal�

void ayarlar()
{
	TRISC.3=1; //I2C SCL Ayar�
	TRISC.4=1; //I2C SDA Ayar�
	TRISB=0x00;
	PORTB=0x00;
	SSPCON1.3=1; //I2C Master Modu se�
	SSPCON1.2=0;
	SSPCON1.1=0;
	SSPCON1.0=0;
	SSPADD=0x0A; //100kHZ H�z Modu se�
	SSPEN=1; //MSSP'yi Etkinle�tir
}
uns8 data;
void main()
{
	ayarlar(); //Ayarlar� yap
	while(1) //Her zaman
	{
		SEN=1; //I2C Start Biti Yolla
		while(SEN); //Ba�latma i�lemi ge�erli olana kadar bekle
		SSPIF=0; //SSPIF Bayra��n� S�f�rla
		SSPBUF=0b.1001.1010; //Adres yolla ve yazma bitini aktifle�tir
		while(!SSPIF); //Adres G�nderilene Kadar Bekle	
		SSPIF=0;
		SSPBUF=0b.0000.0000; //Komut biti yolla (KOmut=00000000 olurse derece okunur)
		while(!SSPIF); //Komut biti yollanana kadar bekle
		SSPIF=0; //SSPIF bayra�� s�f�rla
		RSEN=1; //Tekrar ba�lat
		while(RSEN); //Tekrar ba�latma aktifle�ene kadar bekle
		SSPIF=0; //SSPIF bayra��n� sil
		SSPBUF=0b.1001.1011; //Adresi g�nder ve okuma bitini aktifle�tir
		while(!SSPIF); //Adres g�nderilene kadar bekle
		SSPIF=0; //SSPIF bayra��n� s�f�rla
		RCEN=1; //Master al�m bitini aktfile�tir (derece okumak i�in)
		while(RCEN); //Aktifle�ene kadar bekle
		data=SSPBUF; //8'bitlik dereceyi al
		PEN=1; //G�nderim i�lemini durdur
		while(PEN); //Durana kadar bekle
		SSPIF=0; //SSPIF bayra��n� sil
		PORTB=data; //Okunan veriyi PORT'e ��k			
	}
}

		