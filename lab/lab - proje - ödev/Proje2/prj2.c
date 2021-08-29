
#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý

char	tus_oku();
char	TUS;
char	TUS1;
char	TUS2;
void	ayarlar();
void 	bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý


void main()
{
	ayarlar();

//-----------------------------------------------	
anadongu:
	bekle(1);	// Acquisition Time(Sample & Hold kapasitörünün þarj olmasý için gerekli zaman)
  	while(PORTB.0==1)
 {
	PORTD=0x00;
	if (PORTB.1==1)
	{PORTD=0xF1;bekle(1);}
	if (PORTB.2==1)
	{PORTD=0xF2;bekle(1);}
	PORTE=tus_oku();
 }   
	PORTD=0x00;
	goto anadongu;
//-----------------------------------------------	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void ayarlar()	// Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
{	
	GIE=0;			// Bütün kesmeleri kapat
	TRISC=0xFF;		// C portu giriþ yapýldý
	TRISD=0;		// D portu çýkýþ yapýldý
	TRISB=0xFF;		// B portu çýkýþ yapýldý
	TRISE=0;		// E portu çýkýþ yapýldý
	
	PORTB=0;		// B portu çýkýþlarý sýfýrlandý
	PORTE=0;		// E portu çýkýþlarý sýfýrlandý	
	PORTD=0;		// D portu çýkýþlarý sýfýrlandý
	PORTC=0;		// C portu çýkýþlarý sýfýrlandý

	
	
}

////////////////////////////////////////////////////////////////////////////////////////////
char tus_oku()	// tarama keypad'ýn okunduðu kýsým
{

	TUS1=PORTC;
	bekle(5);
	TUS2=PORTC;
	bekle(5);
	if(TUS1<TUS2)
	{TUS=0x01;bekle(2);}
	if(TUS1>TUS2)
	{TUS=0x02;bekle(2);}	

	return TUS;	
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