#pragma config[1] = 0xF1 // Osilat�r: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
#pragma config[3] = 0xFE // Watchdog Timer kapal�

void ayarlar();
void bekle(unsigned long t);	// t milisaniye gecikme sa�layan fonksiyon tan�m�
void main()
{
	ayarlar();
//-----------------------------------------------	
anadongu:
 	PORTD.0=0; 			// port D nin 0. aya�� high
	while(PORTB.0==1){
		bekle(10);	 	// 10ms debounce s�resi bekle
        PORTD.0=1;   	// port D nin 0. aya�� low
	}

	goto anadongu;
//-----------------------------------------------	
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void ayarlar()	// B�t�n ba�lang�� ayarlar�n�n tamamland��� k�s�m
{	
	GIE=0;			// B�t�n kesmeleri kapat
	TRISB=0xFF;		// B portu giri� yap�ld�
	TRISD=0;		// D portu ��k�� yap�ld�		
	PORTD=0;		// D portu ��k��lar� s�f�rland�	
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
