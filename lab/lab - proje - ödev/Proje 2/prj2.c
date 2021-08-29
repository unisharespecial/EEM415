
#pragma config[1] = 0xF1 // Osilat�r: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
#pragma config[3] = 0xFE // Watchdog Timer kapal�


 void bekle(unsigned long t)	//t milisaniye gecikme sa�lar
{
	unsigned x;
	
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}
void ayarlar()   // B�t�n ba�lang�� ayarlar�n�n tamamland��� k�s�m
{   
   GIE=0;         // B�t�n kesmeleri kapat
   TRISB=0xFF;    // B portu giri� yap�ld�(Butonlar)
   TRISC=0;
   TRISD=0;       // D portu ��k�� yap�ld�(DC-Motor)      
   PORTD=0xFF;       
}

void basla()
{

	while(PORTB.1) // stop butonuna bas�lmad��� s�rece program devam edecek
	{
		PORTD=0xFF;
		if(PORTB.2==0)   	//  saga donme butonuna bas�ld� m�?
		{PORTD = 0x01;bekle(10);}

		if(PORTB.3==0)    	// sola d�nme butonuna bas�ld� m�?
		{PORTD = 0x02;bekle(10);}
				
	}
}


void main()
{
anadongu:		
    bekle(1);	
    ayarlar();
    unsigned STOP,START,RIGHT,LEFT;
    
    if(PORTB.0==0) // start butonuna bas�ld� m�?
      {basla(); }
goto anadongu;
	
}
	