#include "INT18XXX.H"
#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý
#pragma origin 0x8    //Aþaðýdaki kesme fonksiyonunun hangi program satýrýndan baþlayacaðý ayarlandý
       					//(0x8 adresi yüksek öncelikli kesme baþlangýç adresidir)


void ayarlar();
void bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý

interrupt int_server(void)  // KESME SUNUCU FONKSÝYONU
{
	if(INT0IF)	//Gelen kesme, INT0 kesmesi mi?
	{
      PORTD.0=1;
	  while(PORTB.0==1);	
      INT0IF = 0;			// INT0 kesme bayraðýný sýfýrla

	}

}

void main()
{
	ayarlar();

//-----------------------------------------------	
anadongu:

 	bekle(1);	// Acquisition Time(Sample & Hold kapasitörünün þarj olmasý için gerekli zaman)
  	PORTD.0=0;
	goto anadongu;
//-----------------------------------------------	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void ayarlar()	// Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
{	

	INT0IE=1;		// INT0 kesmesi açýk
	INTEDG0=1;		// INT0 kesmesi yükselen kenarda aktif olacak
	GIE=1;			// Bütün kesmeler kullanýlabilir
	TRISB=0xFF;		// PORTB giriþ yapýldý(Buton)
	TRISD=0x00;		// PORTD çýkýþ yapýldý(LED)
	PORTD=0;		// PORTD çýkýþlarý sýfýrlandý
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void bekle(unsigned long t)	//t milisaniye gecikme saðlar
{
	unsigned x;
	
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}

//////////////////////////////////////////////////////////////////////////////////////////////////