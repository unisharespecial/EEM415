
#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý


 void bekle(unsigned long t)	//t milisaniye gecikme saðlar
{
	unsigned x;
	
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}
void ayarlar()   // Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
{   
   GIE=0;         // Bütün kesmeleri kapat
   TRISB=0xFF;    // B portu giriþ yapýldý(Butonlar)
   TRISC=0;
   TRISD=0;       // D portu çýkýþ yapýldý(DC-Motor)      
   PORTD=0xFF;       
}

void basla()
{

	while(PORTB.1) // stop butonuna basýlmadýðý sürece program devam edecek
	{
		PORTD=0xFF;
		if(PORTB.2==0)   	//  saga donme butonuna basýldý mý?
		{PORTD = 0x01;bekle(10);}

		if(PORTB.3==0)    	// sola dönme butonuna basýldý mý?
		{PORTD = 0x02;bekle(10);}
				
	}
}


void main()
{
anadongu:		
    bekle(1);	
    ayarlar();
    unsigned STOP,START,RIGHT,LEFT;
    
    if(PORTB.0==0) // start butonuna basýldý mý?
      {basla(); }
goto anadongu;
	
}
	