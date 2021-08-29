
; CC8E Version 1.3F, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************   6. Oct 2013  22:47  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1
	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

Zero_       EQU   2
TRISD       EQU   0xF95
TRISB       EQU   0xF93
PORTD       EQU   0xF83
PORTB       EQU   0xF81
GIE         EQU   7
t           EQU   0x7F
x           EQU   0x7F

	GOTO main

  ; FILE eem415.c
			;#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;
			;void ayarlar();
			;void bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý
			;void main()
			;{
main
			;	ayarlar();
	RCALL ayarlar
			;//-----------------------------------------------	
			;anadongu:
			; 	PORTD.0=0;
m001	BCF   PORTD,0,0
			;	while(PORTB.0==1)
m002	BTFSS PORTB,0,0
	BRA   m001
			;        PORTD.0=1;    
	BSF   PORTD,0,0
	BRA   m002
			;	goto anadongu;
			;//-----------------------------------------------	
			;}
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;void ayarlar()	// Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
			;{	
ayarlar
			;	GIE=0;			// Bütün kesmeleri kapat
	BCF   0xFF2,GIE,0
			;	TRISB=0xFF;		// B portu giriþ yapýldý
	SETF  TRISB,0
			;	TRISD=0;		// D portu çýkýþ yapýldý		
	CLRF  TRISD,0
			;	PORTD=0;		// D portu çýkýþlarý sýfýrlandý	
	CLRF  PORTD,0
			;}
	RETURN
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;void bekle(unsigned long t)	//t milisaniye gecikme saðlar
			;{
bekle
			;	unsigned x;	
			;	for(;t>0;t--)
m003	MOVF  t,W,0
	IORWF t+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m006
			;		for(x=140;x>0;x--)
	MOVLW 140
	MOVWF x,0
m004	MOVF  x,1,0
	BTFSC 0xFD8,Zero_,0
	BRA   m005
			;			nop();
	NOP  
	DECF  x,1,0
	BRA   m004
m005	DECF  t,1,0
	MOVLW 0
	SUBWFB t+1,1,0
	BRA   m003
			;}
m006	RETURN

	END


; *** KEY INFO ***

; 0x000010    5 word(s)  0 % : ayarlar
; 0x00001A   17 word(s)  0 % : bekle
; 0x000004    6 word(s)  0 % : main

; RAM usage: 0 bytes (0 local), 1536 bytes free
; Maximum call level: 1
; Total of 30 code words (0 %)
