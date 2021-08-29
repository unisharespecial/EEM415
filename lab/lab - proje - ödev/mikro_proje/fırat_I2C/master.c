#include "INT18XXX.H"


#pragma config[1] = 0xF1 // Osilat�r: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
#pragma config[3] = 0xFE // Watchdog Timer kapal�

void ayarlar()
{
	TRISA.0=1; //Analog Giri� Portu
	TRISC.3=1; //I2C SCL Ayar�
	TRISC.4=1; //I2C SDA Ayar�
	SSPCON1.3=1; //I2C Master Modu se�
	SSPCON1.2=0;
	SSPCON1.1=0;
	SSPCON1.0=0;
	SSPADD=0x0A; //100kHZ H�z Modu se�
	SSPEN=1; //MSSP'yi Etkinle�tir
	ADCON0=0b.0000.0001; //ADC Etkinle�tir
	ADCON1=0b.0000.0000; //ADC H�z� FClock/2	
}
void bekle(unsigned long t)	//t milisaniye gecikme sa�lar
{
	unsigned x;
	
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}
void i2cgonder(uns8 data)
{
	SEN=1; //I2C Start Biti Yolla
	while(SEN); //Ba�latma i�lemi ge�erli olana kadar bekle
	SSPIF=0; //SSPIF Bayra��n� S�f�rla
	SSPBUF=0x02; //Se�ilecek I2C Cihaz�n�n Adresini G�nder ve Yazma Bitini Aktifle�tir
	while(!SSPIF); //Adres G�nderilene Kadar Bekle
	SSPIF=0; //SSPIF Bayra��n� S�f�rla
	SSPBUF=data; //Se�ilen Cihaza Veriyi G�nder
	while(!SSPIF); //Veri G�nderilene Kadar Bekle
	SSPIF=0; //SSPIF Bayra��n� S�f�rla
	PEN=1; //I2C Stop Biti Yolla
	while(PEN); //Bitirme i�lemi ge�erli olana kadar bekle
	SSPIF=0; //SSPIF Bayra��n� S�f�rla
}
uns8 data;
void main()
{
	ayarlar(); //Ayarlar� yap
	while(1) //Her zaman
	{
		bekle(10); //Sampla Hold kapasit�r�n�n de�arj� i�in 10 ms bekle 
		GO=1; //�evirme i�lemini ba�lat
		while(GO); //��lem bitene kadar bekle
		data=ADRESH; //�evrilen de�erin �st 8 bitini kaydet
		i2cgonder(data); //Kaydedilen de�eri kar��ya I2C ile yolla
	}
}

		