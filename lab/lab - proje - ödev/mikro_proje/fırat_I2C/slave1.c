#include "INT18XXX.H"


#pragma config[1] = 0xF1 // Osilat�r: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
#pragma config[3] = 0xFE // Watchdog Timer kapal�

uns8 dummy;
uns8 rx;
void ayarlar();
void bekle(unsigned long);

#pragma origin 0x8
interrupt ISR(void) //Kesme Rutini
{
	int_save_registers //�nemli yazma�lar� sakla
	if(SSPIF==1) //Kesme, Senkron �leti�im Kesmesi mi?
	{
		SSPIF=0; //Kesme bayra��n� temizle
		if(S==1 && DA_==0 && RW_==0 && BF==1) //E�er gelen mesaj bir adres bilgisi ise
		
			dummy=SSPBUF; //Buffer� bo�altmak i�in sahte okuma yap
		}
		if(S==1 && DA_==1 && RW_==0 && BF==1) //E�er gelen mesaj bir veri ise
		{
			rx=SSPBUF; //Veriyi oku
		}
	}
	int_restore_registers //Kaydedilen yazma�lar� yerine koy
	CKP=1; //Clock'u serbest b�rak
}

void main()
{
	rx=0; 
	ayarlar(); //Ayarlar� yap
	while(1)//Her zaman
	{
		PORTB=rx; //Gelen veriyi PORTB'e ��k
	}
}

void ayarlar()
{
	TRISB=0;  //PORTB'i ��k�� yap
	PORTB=0;  //PORTB'i s�f�rla
	TRISC.3=1; //I2C SCL Portunu Ayarla
	TRISC.4=1; //I2C SDA Portunu Ayarla
	SSPADD=0x02; //Cihaz�n Adresini Belirle
	SSPCON1=0x36; //I2C Slave Modunu se�
	SSPSTAT=0x00;
	SSPCON2=0x00;
	SEN=1; //Clock esnetmeyi etkinle�tir
	SSPIF=0; //SSPIF Bayra��n� temizle
	SSPIE=1; //Senkron ileti�im kesmesini etkinle�tir
	INTCON=0xC0; //Genel kesmeleri ve �evre kesmelerini etkinle�tir
	return;
}
void bekle(unsigned long t)	//t milisaniye gecikme sa�lar
{
	unsigned x;
	
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}