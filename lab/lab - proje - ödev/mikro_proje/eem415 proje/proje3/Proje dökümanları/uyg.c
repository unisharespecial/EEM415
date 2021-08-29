///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Look up Table Tabanlý Sensor Doðrusallaþtýrýlmasý
#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý
void ayarlar();
void bekle(unsigned long t); // t milisaniye gecikme saðlayan fonksiyon tanýmý
void main()
{
unsigned static const int lookuptable[11] = {1,2,3,4,5,6,7,8,9,10,11};
unsigned int deger;
//y= 2 * X + 1 sensor dogrulastirma islemi
ayarlar();
PORTC=0;
anadongu:
bekle(1);
GO=1;
while(GO);
deger=ADRESH; //okunan analog degerin digital karsiligi, deger degiskenine atýlýyor
//PORTC=deger;
if(deger == 0) //0V dogrulastirmasi
PORTC=lookuptable[0];
else if(deger == 25) //0.5V dogrulastirmasi
PORTC=lookuptable[1];
else if(deger == 51)//1V dogrulastirmasi
PORTC=lookuptable[2];
else if(deger == 76)//1.5V dogrulastirmasi
PORTC=lookuptable[3];
else if(deger == 102)//2V dogrulastirmasi
PORTC=lookuptable[4];
else if(deger == 127)//2.5V dogrulastirmasi
PORTC=lookuptable[5];
else if(deger == 153)//3V dogrulastirmasi
PORTC=lookuptable[6];
else if(deger == 179)//3.5V dogrulastirmasi
PORTC=lookuptable[7];
else if(deger == 204)//4V dogrulastirmasi
PORTC=lookuptable[8];
else if(deger == 230)//4.5V dogrulastirmasi
PORTC=lookuptable[9];
else if(deger == 255)//5V dogrulastirmasi
PORTC=lookuptable[10];
goto anadongu;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void bekle(unsigned long t) //t milisaniye gecikme saðlar
{
unsigned x;
for(;t>0;t--)
for(x=140;x>0;x--)
nop();
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void ayarlar() // Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
{
GIE=0; // Bütün kesmeleri kapat
TRISA=0xFF;
TRISB=0xFF;
TRISC=0x00;
TRISD=0x00;
TRISE=0xFF;
PORTC=0x00;
PORTD=0x00;
ADCON0=0b.0100.0001;;
ADCON1=0b.0000.0000;;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////