
#pragma config[1] = 0xF1 // Osilat�r: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
#pragma config[3] = 0xFE // Watchdog Timer kapal�

char	keypad_oku();
char	TUS;
void	ayarlar();
void 	bekle(unsigned long t);	// t milisaniye gecikme sa�layan fonksiyon tan�m�


void main()
{
	ayarlar();

//-----------------------------------------------	
anadongu:
	bekle(1);	// Acquisition Time(Sample & Hold kapasit�r�n�n �arj olmas� i�in gerekli zaman)
  	while(1)
 {
	PORTD=keypad_oku();
 }   
	goto anadongu;
//-----------------------------------------------	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void ayarlar()	// B�t�n ba�lang�� ayarlar�n�n tamamland��� k�s�m
{	
	GIE=0;			// B�t�n kesmeleri kapat
	TRISC=0xF0;		// C portu giri� yap�ld�
	TRISD=0;		// D portu ��k�� yap�ld�
		
	PORTD=0;		// D portu ��k��lar� s�f�rland�
	PORTC=0;		// C portu ��k��lar� s�f�rland�

	
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////

void bekle(unsigned long t)	//t milisaniye gecikme sa�lar
{
	unsigned x;
	
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}

//////////////////////////////////////////////////////////////////////////////////////////////////