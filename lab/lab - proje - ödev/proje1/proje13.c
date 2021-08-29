#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý

char	tus

#define	sut1	pin_d0		   //portd0 ifedesi "sut1" kelimesi ile eþleniyor
#define	sut2	pin_d1		   //portd1 ifedesi "sut2" kelimesi ile eþleniyor
#define	sut3	pin_d2		   //portd2 ifedesi "sut3" kelimesi ile eþleniyor
#define	sut4	pin_d3		   //portd3 ifedesi "sut4" kelimesi ile eþleniyor

#define	sat1	pin_d4		   //portd4 ifedesi "sat1" kelimesi ile eþleniyor
#define	sat2	pin_d5		   //portd5 ifedesi "sat2" kelimesi ile eþleniyor
#define	sat3	pin_d6		   //portd6 ifedesi "sat3" kelimesi ile eþleniyor
#define	sat4	pin_d7		   //portd7 ifedesi "sat4" kelimesi ile eþleniyor
void	main;
//=================Ana program=====================================

void main();
{
	GIE=0;			// Bütün kesmeleri kapat
	TRISB=0x00;		// B portu giriþ yapýldý
	TRISD=0xFF;		// D portu çýkýþ yapýldý
		
	PORTD=0;		// D portu çýkýþlarý sýfýrlandý
}
//-----------------------------------------------	
anadongu:

	output_b(0x00);

	while(1)			//sonsuz döngü
	{
	keypad_oku();
	portb=tus
	}
	goto anadongu;
//===============================================


//=================keypad tarama=============================================

char	keypad_oku()		//fonksiyon ismi
{
	output_d(0x00);			//portd sýfýrlandý
	
	output_high(sat1);		//1. satýr 1 yapýlýyor sutunlarý okuma baþlýyor
	if	(input(sut1))		//1. sutün okunuyor
		{delay_ms(20); tus=1}
	if	(input(sut2))		//2. sutün okunuyor
		{delay_ms(20); tus=2}
	if	(input(sut3))		//3. sutün okunuyor
		{delay_ms(20); tus=3}
	if	(input(sut4))		//4. sutün okunuyor
		{delay_ms(20); tus=0xA}
	output_low(sat1);		//1. satýr sýfýra çekiliyor

	output_high(sat2);		//2. satýr 1 yapýlýyor sutunlarý okuma baþlýyor
	if	(input(sut1))		//1. sutün okunuyor
		{delay_ms(20); tus=4}
	if	(input(sut2))		//2. sutün okunuyor
		{delay_ms(20); tus=5}
	if	(input(sut3))		//3. sutün okunuyor
		{delay_ms(20); tus=6}
	if	(input(sut4))		//4. sutün okunuyor
		{delay_ms(20); tus=0xB}
	output_low(sat2);		//2. satýr sýfýra çekiliyor

	output_high(sat3);		//3. satýr 1 yapýlýyor sutunlarý okuma baþlýyor
	if	(input(sut1))		//1. sutün okunuyor
		{delay_ms(20); tus=7}
	if	(input(sut2))		//2. sutün okunuyor
		{delay_ms(20); tus=8}
	if	(input(sut3))		//3. sutün okunuyor
		{delay_ms(20); tus=9}
	if	(input(sut4))		//4. sutün okunuyor
		{delay_ms(20); tus=0xC}
	output_low(sat3);		//3. satýr sýfýra çekiliyor

	output_high(sat4);		//4. satýr 1 yapýlýyor sutunlarý okuma baþlýyor
	if	(input(sut1))		//1. sutün okunuyor
		{delay_ms(20); tus=0xE}
	if	(input(sut2))		//2. sutün okunuyor
		{delay_ms(20); tus=0}
	if	(input(sut3))		//3. sutün okunuyor
		{delay_ms(20); tus=0xF}
	if	(input(sut4))		//4. sutün okunuyor
		{delay_ms(20); tus=0xD}
	output_low(sat4);		//4. satýr sýfýra çekiliyor

	return tus;				//tus deðeri ile geri döner
}



//////////////////////////////////////////////////////////////////////////////////////////////////

