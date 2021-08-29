#pragma config[1] = 0xF1 // Osilatör: XT#pragma config[1] = 0xF1 // Osilatör: XT
void ayarlar();
void bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý
void kesme();	


void kesme() //kesme gelince yapilacak komutlar, kesmede calisacak fonksiyon main fonksiyonunun ustunde yazilir...	
{
	INTCON=0x90; // kesmeler acilir RBO/INT0 girisi interrupt enable edilir. 
 	GO=1;	// adc cevrimi baslar
	while(GO);	//cevirme bitene kadar calisir, cevirme bitince go=0 olur
	PORTC=ADRESH;	//adc'den okunan deger PORTC ye aktarilirak sonuc gozlemlenir.
	INT0IF=0;  // yeni kesmeler gelmesi icin butona bagli olan INT0 portundaki interrupt flagi kapatilir.
	GIE=1;	//kesmeler acilir, yeni kesme gelmesine musade edilir
}	


void main()
{
	
	ayarlar();

//-----------------------------------------------	
anadongu:

	bekle(1);	// Acquisition Time(Sample & Hold kapasitörünün þarj olmasý için gerekli zaman)
	INTCON=0x90; // 
	
	unsigned u;
    unsigned y=0;
    while(y==0)            
	   nop();
	while(u==ADRESH)
		{
	TRISC=0xFF;	
	TRISD=0xFF;
		}


goto anadongu;
//-----------------------------------------------	
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

void ayarlar()	// Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
{	
	GIE=1;			// Bütün kesmeleri ac
	TRISA=0xFF;
	TRISB=0xFF;
	TRISC=0x00;	
	TRISD=0x00;		
	TRISE=0xFF;
	
	PORTC=0x00;		
	PORTD=0x00;
	
	ADCON0=0b.0100.0001;// Anlog kanal 0 aktif, A/D conversion is not in progress
	ADCON1=0b.0000.0000;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
