
; CC8E Version 1.3B, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************   9. Dec 2010   3:58  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1
	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

TRISD       EQU   0xF95
TRISB       EQU   0xF93
PORTD       EQU   0xF83
PORTB       EQU   0xF81
INT0IF      EQU   1
INT0IE      EQU   4
GIE         EQU   7
INTEDG0     EQU   6
t           EQU   0x00
x           EQU   0x02

	GOTO main

  ; FILE uyg8.c
			;#include "INT18XXX.H"
			;#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;#pragma origin 0x8    //Aþaðýdaki kesme fonksiyonunun hangi program satýrýndan baþlayacaðý ayarlandý
	ORG 0x0008
			;       					//(0x8 adresi yüksek öncelikli kesme baþlangýç adresidir)
			;
			;
			;void ayarlar();
			;void bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý
			;
			;interrupt int_server(void)  // KESME SUNUCU FONKSÝYONU
			;{
int_server
			;	if(INT0IF)	//Gelen kesme, INT0 kesmesi mi?
	BTFSS 0xFF2,INT0IF,0
	BRA   m002
			;	{
			;      PORTD.0=1;
	BSF   PORTD,0,0
			;	  while(PORTB.0==1);	
m001	BTFSC PORTB,0,0
	BRA   m001
			;      INT0IF = 0;			// INT0 kesme bayraðýný sýfýrla
	BCF   0xFF2,INT0IF,0
			;
			;	}
			;
			;}
m002	RETFIE
			;
			;void main()
			;{
main
			;	ayarlar();
	RCALL ayarlar
			;
			;//-----------------------------------------------	
			;anadongu:
			;
			; 	bekle(1);	// Acquisition Time(Sample & Hold kapasitörünün þarj olmasý için gerekli zaman)
m003	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;  	PORTD.0=0;
	BCF   PORTD,0,0
			;	goto anadongu;
	BRA   m003
			;//-----------------------------------------------	
			;}
			;
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;
			;void ayarlar()	// Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
			;{	
ayarlar
			;
			;	INT0IE=1;		// INT0 kesmesi açýk
	BSF   0xFF2,INT0IE,0
			;	INTEDG0=1;		// INT0 kesmesi yükselen kenarda aktif olacak
	BSF   0xFF1,INTEDG0,0
			;	GIE=1;			// Bütün kesmeler kullanýlabilir
	BSF   0xFF2,GIE,0
			;	TRISB=0xFF;		// PORTB giriþ yapýldý(Buton)
	SETF  TRISB,0
			;	TRISD=0x00;		// PORTD çýkýþ yapýldý(LED)
	CLRF  TRISD,0
			;	PORTD=0;		// PORTD çýkýþlarý sýfýrlandý
	CLRF  PORTD,0
			;	
			;}
	RETURN
			;
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;
			;void bekle(unsigned long t)	//t milisaniye gecikme saðlar
			;{
bekle
			;	unsigned x;
			;	
			;	for(;t>0;t--)
m004	MOVF  t,W,0
	IORWF t+1,W,0
	BZ    m007
			;		for(x=140;x>0;x--)
	MOVLW 140
	MOVWF x,0
m005	MOVF  x,1,0
	BZ    m006
			;			nop();
	NOP  
	DECF  x,1,0
	BRA   m005
m006	DECF  t,1,0
	MOVLW 0
	SUBWFB t+1,1,0
	BRA   m004
			;}
m007	RETURN

	END


; *** KEY INFO ***

; 0x000024    7 word(s)  0 % : ayarlar
; 0x000032   15 word(s)  0 % : bekle
; 0x000008    7 word(s)  0 % : int_server
; 0x000016    7 word(s)  0 % : main

; RAM usage: 3 bytes (3 local), 1533 bytes free
; Maximum call level: 1 (+1 for interrupt)
; Total of 38 code words (0 %)
