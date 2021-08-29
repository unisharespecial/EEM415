void init();
void bekle(unsigned long t);
/*void LcdInit();
void LcdYaz(char );
void LcdKomut(unsigned kom);
void MesajYaz(const char *msj,unsigned adr);*/
void ayarlar();
void bekle_kesme(unsigned long a);
void sifirla(unsigned long s);

void kesme() //kesme gelince yapilacak komutlar, kesmede calisacak fonksiyon main fonksiyonunun ustunde yazilir...	
{
    INTCON=0x90; // kesmeler acilir RBO/INT0 girisi interrupt enable edilir.
    INT0IF=0;  // yeni kesmeler gelmesi icin butona bagli olan INT0 portundaki interrupt flagi kapatilir.
	GIE=1;	//kesmeler acilir, yeni kesme gelmesine musade edilir	
    int sayac=0;
    int sayac1=0;
    int zaman=0;
    while(TMR1H<=9){
	 T1CON=0b.0000.0101;//Timer baslatilir.
	 nop();
     sayac=TMR1H;
	 T1CON=0b.0000.0000;//Timer durdurulur.
	if(TMR1H>9){//9'dan sonra A yazmamasý için deger sifirlanir.
	            TMR1H=0b.0000;
	            nop();
	            PORTC=TMR1H;
	            break;
             }
     nop();
     sayac1=TMR1H;
     zaman=sayac1-sayac;
	 PORTC=zaman;
	 bekle_kesme(1000);
	 	}
}	
	

bit e @ PORTE.0, rs @ PORTE.1, rw @ PORTE.2;
unsigned disp @ PORTD;

void main(){
    ayarlar();
	INTCON=0x90;
	/*init();
	LcdInit();*/
  
anadongu:
/*	MesajYaz("\f zaman= %d,zaman ",0x80);
	bekle(1500);
	MesajYaz("application file    ",0x80);
	bekle(1500);*/
	
goto anadongu;
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
/*void init()
{
	TRISD=0X00;
	TRISE=0X00;
}
*/

void bekle(unsigned long t)	//t milisaniye gecikme saðlar
{
	unsigned n;
	for(;t>0;t--)
		for(n=140;n>0;n--)
			nop();
}

/*void LcdKomut(unsigned kom)
{
	
	bekle(20);
	disp=kom;
	rs=0;
	e=0;
	e=1;
}

void LcdYaz(char c)
{
	bekle(100);
	disp=c;
	rs=1;
	e=0;
	e=1;
	bekle(1);	
}


void LcdInit()
{
	rw=0;
	e=1;
	rs=1;
	LcdKomut(0x38);	
	LcdKomut(0x01);	//Clear display
	LcdKomut(0x0D); //Display,Cursor,Blink on
	LcdKomut(0x06); //Increment ddram adres, do not shift disp.
}

void MesajYaz(const char *msj,unsigned adr)
{
	unsigned i,j,k;
	i=0;
	while(msj[i]!=0)	i++;
	
	LcdKomut(adr);
	for(j=0;j<i;j++){
		LcdYaz(msj[j]);
		for(k=0;k<30;k++)nop();
	}
}*/