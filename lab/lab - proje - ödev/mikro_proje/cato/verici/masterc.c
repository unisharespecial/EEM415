#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý

void ayarlar();
void I2Cayar();
void bekle(unsigned long t);
char keypad_oku();   // t milisaniye gecikme saðlayan fonksiyon tanýmý
char TUS;

char keypad_oku()	// tarama keypad'ýn okunduðu kýsým
{	
	PORTC.0=1;
	if(PORTC.4==1)
	{bekle(50);TUS=0X01;}
	if(PORTC.5==1)
	{bekle(50);TUS=0X02;}
	if(PORTC.6==1)
	{bekle(50);TUS=0X03;}
	if(PORTC.7==1)
	{bekle(50);TUS=0X0A;}
  	PORTC.0=0;
  
	PORTC.1=1;
	if(PORTC.4==1)
	{bekle(50);TUS=0X04;}
	if(PORTC.5==1)
	{bekle(50);TUS=0X05;}
	if(PORTC.6==1)
	{bekle(50);TUS=0X06;}
	if(PORTC.7==1)
	{bekle(50);TUS=0X0B;}
	PORTC.1=0;

	PORTC.2=1;
	if(PORTC.4==1)
	{bekle(50);TUS=0X07;}
	if(PORTC.5==1)
	{bekle(50);TUS=0X08;}
	if(PORTC.6==1)
	{bekle(50);TUS=0X09;}
	if(PORTC.7==1)
	{bekle(50);TUS=0X0C;}
	PORTC.2=0;

	PORTC.3=1;
	if(PORTC.4==1)
	{bekle(50);TUS=0X0E;}
	if(PORTC.5==1)
	{bekle(50);TUS=0X00;}
	if(PORTC.6==1)
	{bekle(50);TUS=0X0F;}
	if(PORTC.7==1)
	{bekle(50);TUS=0X0D;}
	PORTC.3=0;
	
	return TUS;	
	
}

void main()
{  
   
   
   ayarlar();
}


  
//////////////////////////////////////////////////////////////////////////////////////////////////
void ayarlar()   // Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
{   
   GIE=0;  // Bütün kesmeleri kapat
   I2Cayar(); 
   TRISC.3=1; //IC SCL Portunu Ayarla
   TRISC.4=1; //I2C SDA Porunu Ayarla
   SSPADD=0x02;  //Cihazýn Adresini Belirle
   SSPCON1=0x36; //I2C Slave Modunu Aç
   SSPSTAT=0x00;
   SEN=1;  //Clock esnetmeyi etkinleþtirir
   SSPIF=0; //SSPIF Bayraðýný Temizle
   SSPIE=1; //Senkron iletiþim kesmesini etkinleþtirir
   INTCON=0xC0; //Genel kesmeleri ve çevre kesmelerini etkinleþtirir
   TRISD=0xF0; //D Portu giriþ yapýldý
   TRISC=0;    //C portu çýkýþ yapýldý
   PORTD=0x00;  //D portu çýkýþlarý sýfýrlandý
   PORTC=0x00;  //C portu çýkýþlarý sýfýrlandý   
   return;
   
}
//////////////////////////////////////////////////////////////////////////////////

void I2Cayar()   // Seri Portu veri göndermeye hazýr hale getirir
{
   //SPBRG=25;   // Baud Rate=9.6k
   BRGH=1;      // Yüksek Hýz
   SYNC=1;      // senkron mod
   SMP=0;
   CKE=0;
   BF=0;
   //WCOL=0;
   //SSPOV=0;
   SSPEN=1;  // MSSP'yi etkinleþtir
   CKP=1;
SSPADD=0x0A; //100kHZ hýz modunu seç
SSPCON1.3=1;  //I2C master modu aç
SSPCON1.2=0;
SSPCON1.1=0;
SSPCON1.0=0;
ADCON0.0=0; // A/D modülü kapat.
ADCON1.3=0;
ADCON1.2=1;
ADCON1.1=1;

}

//////////////////////////////////////////////////////////////////////////////////////////////////

void bekle(unsigned long t)   //t milisaniye gecikme saðlar
{
   unsigned x;
   
   for(;t>0;t--)
      for(x=140;x>0;x--)
         nop();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

