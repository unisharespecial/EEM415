void ayarlar();
void bekle(unsigned long t);
void sifirla(unsigned long s);

void kesme() //kesme gelince yapilacak komutlar, kesmede calisacak fonksiyon main fonksiyonunun ustunde yazilir...	
{
	/*INTCON=0x90; // kesmeler acilir RBO/INT0 girisi interrupt enable edilir.
	PORTC.4=1;
	bekle(1000);
	PORTC.4=0;
	INT0IF=0;  // yeni kesmeler gelmesi icin butona bagli olan INT0 portundaki interrupt flagi kapatilir.
	GIE=1;	//kesmeler acilir, yeni kesme gelmesine musade edilir
	sifirla(TMR1H);*/

INTCON=0x90;
	T1CON=0b.0000.0101;
	PORTC=TMR1H;
	T1CON=0b.0000.0000;
	bekle(5);
	sifirla(TMR1H);
}	

void main()
{
	ayarlar();
	
anadongu:
/*	INTCON=0x90;
	T1CON=0b.0000.0101;
	PORTC=TMR1H;
	T1CON=0b.0000.0000;
	bekle(5);
	sifirla(TMR1H);*/
INTCON=0x90; // kesmeler acilir RBO/INT0 girisi interrupt enable edilir.
	PORTC.4=1;
	bekle(1000);
	PORTC.4=0;
	INT0IF=0;  // yeni kesmeler gelmesi icin butona bagli olan INT0 portundaki interrupt flagi kapatilir.
	GIE=1;	//kesmeler acilir, yeni kesme gelmesine musade edilir
	sifirla(TMR1H);
goto anadongu;

}

void bekle(unsigned long t)
{
	unsigned x;
	
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}

void sifirla(unsigned long s)
{
	if(s>9)
		TMR1H=0b.0000;
}

void ayarlar()
{	
	GIE=1;			
	TRISA=0xFF;
	TRISB=0xFF;
	TRISC=0x00;	

		
}
