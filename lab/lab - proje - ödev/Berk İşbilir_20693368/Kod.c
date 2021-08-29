#pragma config[1] = 0xF1 // Osilat�r: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
#pragma config[3] = 0xFE // Watchdog Timer kapal�
#pragma origin 0x8    //A�a��daki kesme fonksiyonunun hangi program sat�r�ndan ba�layaca�� ayarland�
       					//(0x8 adresi y�ksek �ncelikli kesme ba�lang�� adresidir)

#pragma interruptSaveCheck n
#pragma sharedAllocation

void ayarlar();
void bekle(unsigned long t);	// t milisaniye gecikme sa�layan fonksiyon tan�m�
void oku_yaz();
void LcdInit();
void LcdYaz(char);
void LcdKomut(unsigned kom);
void MesajYaz(const char *msj,unsigned adr);

bit e @ PORTE.0, rs @ PORTE.1, rw @ PORTE.2;
unsigned disp @ PORTD;


interrupt int_server(void)  // KESME SUNUCU FONKS�YONU
{   
	if(INT0IF)				//Gelen kesme, INT0 kesmesi mi?
	{
		oku_yaz();
		INT0IF = 0;
	}
}


void main()
{
	ayarlar(); // �lgili Port ve INT tan�mlamalar�n�n yap�lmd��� fonksiyon
	LcdInit(); // LCD' nin kullan�m� i�in gerekli ayarlamalar.
	
	MesajYaz("Islem Basliyor",0x80); //0x80 Cursor�n baslang�c konumunu belirliyor
	bekle(500);
//-----------------------------------------------	
anadongu:
	
	
 	bekle(1);	// Acquisition Time(Sample & Hold kapasit�r�n�n �arj olmas� i�in gerekli zaman)
 	MesajYaz("Basilan Tus : ",0x80);
	goto anadongu;
//-----------------------------------------------	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void ayarlar()	// B�t�n ba�lang�� ayarlar�n�n tamamland��� k�s�m
{	

	INT0IE = 1;		// INT0 kesmesi a��k
	INTEDG0 = 0;	// INT0 kesmesi d��en kenarda aktif olacak
	GIE = 1;		// B�t�n kesmeler kullan�labilir
	TRISC = 0x00;	// PORTC ��k�� yap�ld�( LED )
	TRISB = 0xFF;	// PORTB giri� yap�ld� ( Matrix Klavye )
	TRISD = 0X00;	// PORTD ��k�� yap�ld� ( LCD )
	TRISE = 0X00;	// PORTE ��k�� yap�ld� ( LCD )
	
	PORTC = 0;		// PORTC ��k��lar� s�f�rland�
	PORTD = 0;	
	
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

void oku_yaz()
{
	unsigned x;
	int index;
	int b[4];
	static const v[8] = {0x01,0x02,0x03,0x00,0x04,0x05,0x06,0x00}; //Girilen de�er 6'dan k���kse kullan�lan bu diziyi kullan
	static const n[8] = {0x07,0x08,0x09,0x00,0x0F,0x00,0x0F,0x00}; //Girilen de�er 6'dan b�y�kse kullan�lan bu diziyi kullan
	
	//Matrix klavyeden girilen de�eri bulmak i�in, b dizisini kullan
	b[0] = PORTB.4;
	b[1] = PORTB.5;
	b[2] = PORTB.6;
	b[3] = PORTB.7;

	//Girilen say�n�n decimal kar��l���
	index = b[0] + (b[1]*2);
	index += (b[2]*4); 
	index += (b[3]*8);
	
	if( index>6 ) //Girilen say�n�n 6 dan b�y�k olmas�
	{
		
		PORTC = n[index-8];
		if ( index == 12 || index == 14 ) //Bas�lan tu�un "*" veya "#" olmas�
		{
			if ( index == 12 )
				MesajYaz("*",0x8E);
			else
				MesajYaz("#",0x8E);
		}
		else //Bas�lan tu�un 7,8,9,0 olmas� durumu
		{
			switch (index)
			{
				case 8:
					MesajYaz("7",0x8E);
					break;
				case 9:
					MesajYaz("8",0x8E);
					break;
				case 10:
					MesajYaz("9",0x8E);
					break;
				case 13:
					MesajYaz("0",0x8E);
					break;
			}
		}
	}
	else //Girilen say�n�n 6 veya 6'dan k���k olmas�
	{
		PORTC = v[index];
		switch(index) //Bas�lan tu�un 1,2,3,4,5,6 olmas� durumu
		{
			case 0:
					MesajYaz("1",0x8E);
					break;
			case 1:
					MesajYaz("2",0x8E);
					break;
			case 2:
					MesajYaz("3",0x8E);
					break;
			case 4:
					MesajYaz("4",0x8E);
					break;
			case 5:
					MesajYaz("5",0x8E);
					break;
			case 6:
					MesajYaz("6",0x8E);
					break;
		}
	}	
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void LcdKomut(unsigned kom) // Gelen mesaj�n i�lem komutuna g�re, ilgili komutu ger�ekle�tiren fonksiyon 
{							// MesajYaz("....",0x80); sat�r�ndaki 0x80' i i�leme koyan fonksiyon
	bekle(20);
	disp=kom;
	rs=0;
	e=0;
	e=1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void LcdYaz(char c) // Gelen karakteri ekrana basan fonksiyon
{
	bekle(50);
	disp=c;
	rs=1;
	e=0;
	e=1;
	bekle(1);	
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void LcdInit() // LCD ekran�n kullan�m �zelliklerini belirleyen fonksiyon
{
	rw=0;			// LCD' ye yazd�rma
	e=1;			// LCD aktif edildi
	rs=1;			// Yazma� se�imi
	LcdKomut(0x38);	
	LcdKomut(0x01);	//Clear display
	LcdKomut(0x0C); //Dont display cursor,Blink off
	LcdKomut(0x06); //Increment ddram adres, do not shift disp.
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void MesajYaz(const char *msj,unsigned adr)
{
	unsigned i,j,k;
	i=0;
	while(msj[i]!=0) //Gelen mesaj�n boyutunun bulunmas�
		i++;
	
	LcdKomut(adr);
	for(j=0;j<i;j++) //LcdYaz fonksiyonu i�ine, mesaj�n karakterleri tek tek yollan�yor.
	{
		LcdYaz(msj[j]);
		for(k=0;k<30;k++) //30 cycle boyunca bekleme yarat
			nop();
	}
}