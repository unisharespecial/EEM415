#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý

void ayarlar();
void bekle(unsigned long t);	
void oku_yaz();


void main()
{
	ayarlar();

	bekle(1);
	anadongu:
	
 	if(PORTB.0==1)	// set-3 butonuna basýldýysa
	{
		PORTD.0 = 0;	// yeþil ledi söndür
		PORTD.1 = 1;	// kýrmýzý ledi yak
		bekle(50);
	}

	if(PORTB.1==1)	//	reset-3 butonuna basýldýysa
	{
		PORTD.1 = 0;	//	kýrmýzý ledi söndür
		PORTD.0 = 1;	//	yeþil ledi yak
		bekle(50);
	}
	goto anadongu;
//-----------------------------------------------

}

//////////////////////////////////////////////////////////////////////////////////////////////////

void ayarlar()	
{	

	TRISD=0x00;	//	PORTD çýkýþ		
	PORTD=0;
	PORTD.0 = 1;	//	yeþil ledi yak
	
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
