void ayarlar();
void bekle(unsigned long t);
void bekle_kesme(unsigned long a);
void sifirla(unsigned long s);

void kesme() //kesme gelince yapilacak komutlar, kesmede calisacak fonksiyon main fonksiyonunun ustunde yazilir...	
{
    INTCON=0x90; // kesmeler acilir RBO/INT0 girisi interrupt enable edilir.
    INT0IF=0;  // yeni kesmeler gelmesi icin butona bagli olan INT0 portundaki interrupt flagi kapatilir.
	GIE=1;	//kesmeler acilir, yeni kesme gelmesine musade edilir	
    while(TMR1H<=9){
	 T1CON=0b.0000.0101;//Timer baslatilir.
	 nop();
    PORTC.4 = 0;	//	yeþil ledi söndür
	PORTC.5 = 1;	//	mavi led
	 T1CON=0b.0000.0000;//Timer durdurulur.
PORTC.4=1;
     PORTC.5=0;	 
	 if(TMR1H>9){//9'dan sonra A yazmamasý için deger sifirlanir.
	            TMR1H=0b.0000;
	            nop();
	            PORTC=TMR1H;
	            break;
             }
     nop();
	 PORTC=TMR1H;
	 bekle_kesme(1000);
	 
    }	
}	

void main()
{
	ayarlar();
	INTCON=0x90;
	
anadongu:
	PORTC.4=1;
	bekle(1);
	PORTC.4=0;
	bekle(1);
goto anadongu;

}

void bekle(unsigned long t)
{
	for(t=1400*t;t>0;t--)              
			nop();
}

void bekle_kesme(unsigned long a)
{
	for(a=1400*a;a>0;a--)
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
