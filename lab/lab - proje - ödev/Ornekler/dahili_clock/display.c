//#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý

void ayarlar();
void bekle(unsigned long t);
void sifirla(unsigned long s);


void main()
{
	ayarlar();

anadongu:


T1CON=0b.0000.0101;
PORTC=TMR1H;
T1CON=0b.0000.0000;
bekle(5);
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
	GIE=0;	
	TRISC=0x00;		
}
