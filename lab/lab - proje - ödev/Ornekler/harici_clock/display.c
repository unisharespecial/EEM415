void ayarlar();
void bekle(unsigned long t);
void sifirla(unsigned long s);


void main()
{
	ayarlar();

anadongu:


T0CON=0b.1110.1000;
PORTC=TMR0L;
//T0CON=0b.0000.0000;
bekle(5);
sifirla(TMR0L);



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
		TMR0L=0b.0000;
}

void ayarlar()
{	
	GIE=0;	
	TRISA=0xFF;
	TRISC=0x00;		
}
