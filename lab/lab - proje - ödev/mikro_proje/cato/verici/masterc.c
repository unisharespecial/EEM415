#pragma config[1] = 0xF1 // Osilat�r: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
#pragma config[3] = 0xFE // Watchdog Timer kapal�

void ayarlar();
void I2Cayar();
void bekle(unsigned long t);
char keypad_oku();   // t milisaniye gecikme sa�layan fonksiyon tan�m�
char TUS;

char keypad_oku()	// tarama keypad'�n okundu�u k�s�m
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
void ayarlar()   // B�t�n ba�lang�� ayarlar�n�n tamamland��� k�s�m
{   
   GIE=0;  // B�t�n kesmeleri kapat
   I2Cayar(); 
   TRISC.3=1; //IC SCL Portunu Ayarla
   TRISC.4=1; //I2C SDA Porunu Ayarla
   SSPADD=0x02;  //Cihaz�n Adresini Belirle
   SSPCON1=0x36; //I2C Slave Modunu A�
   SSPSTAT=0x00;
   SEN=1;  //Clock esnetmeyi etkinle�tirir
   SSPIF=0; //SSPIF Bayra��n� Temizle
   SSPIE=1; //Senkron ileti�im kesmesini etkinle�tirir
   INTCON=0xC0; //Genel kesmeleri ve �evre kesmelerini etkinle�tirir
   TRISD=0xF0; //D Portu giri� yap�ld�
   TRISC=0;    //C portu ��k�� yap�ld�
   PORTD=0x00;  //D portu ��k��lar� s�f�rland�
   PORTC=0x00;  //C portu ��k��lar� s�f�rland�   
   return;
   
}
//////////////////////////////////////////////////////////////////////////////////

void I2Cayar()   // Seri Portu veri g�ndermeye haz�r hale getirir
{
   //SPBRG=25;   // Baud Rate=9.6k
   BRGH=1;      // Y�ksek H�z
   SYNC=1;      // senkron mod
   SMP=0;
   CKE=0;
   BF=0;
   //WCOL=0;
   //SSPOV=0;
   SSPEN=1;  // MSSP'yi etkinle�tir
   CKP=1;
SSPADD=0x0A; //100kHZ h�z modunu se�
SSPCON1.3=1;  //I2C master modu a�
SSPCON1.2=0;
SSPCON1.1=0;
SSPCON1.0=0;
ADCON0.0=0; // A/D mod�l� kapat.
ADCON1.3=0;
ADCON1.2=1;
ADCON1.1=1;

}

//////////////////////////////////////////////////////////////////////////////////////////////////

void bekle(unsigned long t)   //t milisaniye gecikme sa�lar
{
   unsigned x;
   
   for(;t>0;t--)
      for(x=140;x>0;x--)
         nop();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

