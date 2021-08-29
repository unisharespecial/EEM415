#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý

void ayarlar();
void LcdInit();
void LcdYaz(char);
void LcdKomut(unsigned kom);
void MesajYaz(const char*msj,unsigned adr);
bit e@PORTE.0, rs@PORTE.1, rw@PORTE.2;
unsigned disp@PORTD;
void bekle(unsigned long t);   // t milisaniye gecikme saðlayan fonksiyon tanýmý


void main()
{  
   
   uns8 gelen;
   ayarlar();
 

//-----------------------------------------------   
while(1){

 SSPBUF=0x00;
while(!SSPIF);
gelen=SSPBUF;
SSPIF=0;
PORTB=gelen; 
bekle(1000);
if(gelen== 0x1)
{  LcdInit();
  MesajYaz(" 1 butonu " ,0x80); 
}
if(gelen== 0x2)
{  LcdInit();
  MesajYaz(" 2 butonu " ,0x80); 
}
if(gelen== 0x3)
{  LcdInit();
  MesajYaz(" 3 butonu " ,0x80); 
}

if(gelen== 0x4)
{  LcdInit();
  MesajYaz(" 4 butonu " ,0x80); 
}
if(gelen== 0x5)
{  LcdInit();
  MesajYaz(" 5 butonu " ,0x80); 
}
if(gelen== 0x6)
{  LcdInit();
  MesajYaz(" 6 butonu " ,0x80); 
}
if(gelen== 0x0)
{  LcdInit();
  MesajYaz(" 0 butonu " ,0x80); 
}




if(gelen== 0xB)
{  LcdInit();
  MesajYaz(" B butonu " ,0x80); 
}
if(gelen==0x7)
{ LcdInit();
   MesajYaz(" 7 butonu " ,0x80); 
}
if(gelen==0x8)
{ LcdInit();
   MesajYaz(" 8 butonu " ,0x80); 
}
if(gelen==0x9)
{ LcdInit();
   MesajYaz(" 9 butonu " ,0x80); 
}
if(gelen==0xA)
{ LcdInit();
   MesajYaz(" A butonu " ,0x80); 
}
if(gelen==0xC)
{ LcdInit();
   MesajYaz(" C butonu " ,0x80);
}
if(gelen==0xD)
{ LcdInit();
   MesajYaz(" D butonu " ,0x80);
}
if(gelen==0xE)
{ LcdInit();
   MesajYaz(" E butonu " ,0x80); 
}
if(gelen==0xF)
{ LcdInit();
   MesajYaz(" F butonu " ,0x80); 
} 
 
}

//-----------------------------------------------   
}

//////////////////////////////////////////////////////////////////////////////////////////////////
void ayarlar()   // Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
{   
   GIE=0;         // Bütün kesmeleri kapat
   TRISD=0x00;
   TRISA=0xFF;
   TRISE=0x00; 
   TRISC=0x18; 
   TRISB=0x00;
   PORTB=0x00;  
   //SPBRG=25;   // Baud Rate=9.6k
   BRGH=1;      // Yüksek Hýz
  SYNC=1;      // senkron mod
  SMP=0;
  CKE=0;
  BF=0;
  WCOL=0;
  SSPOV=0;
  SSPEN=0;
  SSPEN=1;
  CKP=1;
  SSPCON1.3=0;
  SSPCON1.2=1;
  SSPCON1.1=0;
  SSPCON1.0=1;
  
} 
 void LcdKomut(unsigned kom)
{
	//while(IsLcdBusy());
	bekle(20);
	disp=kom;
	rs=0;
	e=0;
	e=1;
}
void LcdYaz(char c)
{
	//while(IsLcdBusy());
	bekle(20);
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



   

//////////////////////////////////////////////////////////////////////////////////

 
     



//////////////////////////////////////////////////////////////////////////////////////////////////

void bekle(unsigned long t)   //t milisaniye gecikme saðlar
{
   unsigned x;
   
   for(;t>0;t--)
      for(x=140;x>0;x--)
         nop();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

