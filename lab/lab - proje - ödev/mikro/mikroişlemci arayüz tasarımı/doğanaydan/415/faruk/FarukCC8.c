#include "INT18XXX.H"
#pragma origin 0x8
#pragma config[1] = 0xF1 // Osilatör: XT
#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
#pragma config[3] = 0xFE // Watchdog Timer kapalý
int8 x;
interrupt int_server(void)  // KESME SUNUCU FONKSÝYONU
{   
   int_save_registers   //W, STATUS, ve BSR yazmaçlarýnýn kesme gelmeden önceki deðerlerini kaydeder
      INT0IF = 0;         // INT0 kesme bayraðýný sýfýrla(yeni kesmeler gelebilir)
        if(x==-1)
			x=7;
		if(x==8)
			x=0;
		if(x==0)
		    PORTC=1;
		if(x==1)
			PORTC=2;
		if(x==2)
			PORTC=4;
		if(x==3)
			PORTC=8;
		if(x==4)
			PORTC=16;
		if(x==5)
			PORTC=32;
		if(x==6)
			PORTC=64;
		if(x==7)
			PORTC=128;
	if(PORTD==1)
	x++;	
	if(PORTD==2)
	x--;
	
    int_restore_registers //CC8E Macro to restore W, STATUS, and BSR registers
   
}
void main()
{
 x=0;
 TRISC=0;
 PORTC=0;
 TRISD=1;
 PORTD=0;
 
 INT0IE=1;         // INT0 kesmesi açýk
 INTEDG0=1;        // INT0 kesmesi yükselen kenarda aktif olacak
 GIE=1;            // Bütün kesmeler kullanýlabilir
 sonsuz:
goto sonsuz;
}

