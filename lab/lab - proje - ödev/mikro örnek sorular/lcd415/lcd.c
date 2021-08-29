#pragma config[1]= 0xF1
#pragma config[2]= 0xFE & 0XF9
#pragma config[3]= 0xFE 

void init();
void bekle(unsigned long t);
void LcdInit();
void LcdYaz(char );
void LcdKomut(unsigned kom);
void MesajYaz(const char *msj,unsigned adr);

bit e @ PORTE.0, rs @ PORTE.1, rw @ PORTE.2;
unsigned disp @ PORTD;

void main(){
unsigned sayac=0;
	
init();
	LcdInit();
GIE=0;
TRISB=0XFF;
TRISD=0X00;
PORTD=0;
TRISC=0;
PORTC=0
anadongu:
if(PORTB.0==1) {

	while(PORTB.0==1)
	sayac++;
	
	MesajYaz("EEM415          ",0x80);
	bekle(1500);
	MesajYaz("application file    ",0x80);
	bekle(1500);
	
goto anadongu;
}
   	

void init()
{
	TRISD=0X00;
	TRISE=0X00;
}


void bekle(unsigned long t)	//t milisaniye gecikme saðlar
{
	unsigned n;
	for(;t>0;t--)
		for(n=140;n>0;n--)
			nop();
}

void LcdKomut(unsigned kom)
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
}