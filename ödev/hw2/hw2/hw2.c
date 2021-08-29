#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý

void ayarlar();
void bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý
void main()
{
	ayarlar();
//-----------------------------------------------	
anadongu:
 	PORTD.0=0; 			// port D nin 0. ayaðý high
	while(PORTB.0==1){
		bekle(10);	 	// 10ms debounce süresi bekle
        PORTD.0=1;   	// port D nin 0. ayaðý low
	}

	goto anadongu;
//-----------------------------------------------	
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void ayarlar()	// Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
{	
	GIE=0;			// Bütün kesmeleri kapat
	TRISB=0xFF;		// B portu giriþ yapýldý
	TRISD=0;		// D portu çýkýþ yapýldý		
	PORTD=0;		// D portu çýkýþlarý sýfýrlandý	
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
