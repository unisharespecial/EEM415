#include "INT18XXX.H"
#pragma config[1] = 0xF1 // Osilat�r: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
#pragma config[3] = 0xFE // Watchdog Timer kapal�
#pragma origin 0x8    //A�a��daki kesme fonksiyonunun hangi program sat�r�ndan ba�layaca�� ayarland�
       					//(0x8 adresi y�ksek �ncelikli kesme ba�lang�� adresidir)


void ayarlar();
void bekle(unsigned long t);	// t milisaniye gecikme sa�layan fonksiyon tan�m�

interrupt int_server(void)  // KESME SUNUCU FONKS�YONU
{
	if(INT0IF)	//Gelen kesme, INT0 kesmesi mi?
	{
      PORTD.0=1;
	  while(PORTB.0==1);	
      INT0IF = 0;			// INT0 kesme bayra��n� s�f�rla

	}

}

void main()
{
	ayarlar();

//-----------------------------------------------	
anadongu:

 	bekle(1);	// Acquisition Time(Sample & Hold kapasit�r�n�n �arj olmas� i�in gerekli zaman)
  	PORTD.0=0;
	goto anadongu;
//-----------------------------------------------	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void ayarlar()	// B�t�n ba�lang�� ayarlar�n�n tamamland��� k�s�m
{	

	INT0IE=1;		// INT0 kesmesi a��k
	INTEDG0=1;		// INT0 kesmesi y�kselen kenarda aktif olacak
	GIE=1;			// B�t�n kesmeler kullan�labilir
	TRISB=0xFF;		// PORTB giri� yap�ld�(Buton)
	TRISD=0x00;		// PORTD ��k�� yap�ld�(LED)
	PORTD=0;		// PORTD ��k��lar� s�f�rland�
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void bekle(unsigned long t)	//t milisaniye gecikme sa�lar
{
	unsigned x;
	
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}

//////////////////////////////////////////////////////////////////////////////////////////////////