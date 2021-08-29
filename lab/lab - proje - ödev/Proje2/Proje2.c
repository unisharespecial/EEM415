
#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý

char	keypad_oku();
char	TUS;
void	ayarlar();
void 	bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý


void main()
{
	ayarlar();

//-----------------------------------------------	
anadongu:
	bekle(1);	// Acquisition Time(Sample & Hold kapasitörünün þarj olmasý için gerekli zaman)
  	while(1)
 {
	PORTD=keypad_oku();
 }   
	goto anadongu;
//-----------------------------------------------	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void ayarlar()	// Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
{	
	GIE=0;			// Bütün kesmeleri kapat
	TRISC=0xF0;		// C portu giriþ yapýldý
	TRISD=0;		// D portu çýkýþ yapýldý
		
	PORTD=0;		// D portu çýkýþlarý sýfýrlandý
	PORTC=0;		// C portu çýkýþlarý sýfýrlandý

	
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////

void bekle(unsigned long t)	//t milisaniye gecikme saðlar
{
	unsigned x;
	
	for(;t>0;t--)
		for(x=140;x>0;x--)
			nop();
}

//////////////////////////////////////////////////////////////////////////////////////////////////