
; CC8E Version 1.3B, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  14. Jan 2011  11:54  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1
	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

TRISD       EQU   0xF95
PORTD       EQU   0xF83
PORTB       EQU   0xF81
t           EQU   0x00
x           EQU   0x02

	GOTO main

  ; FILE Kilit.c
			;#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;
			;void ayarlar();
			;void bekle(unsigned long t);	
			;void oku_yaz();
			;
			;
			;void main()
			;{
main
			;	ayarlar();
	RCALL ayarlar
			;
			;	bekle(1);
	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	anadongu:
			;	
			; 	if(PORTB.0==1)	// set-3 butonuna basýldýysa
m001	BTFSS PORTB,0,0
	BRA   m002
			;	{
			;		PORTD.0 = 0;	// yeþil ledi söndür
	BCF   PORTD,0,0
			;		PORTD.1 = 1;	// kýrmýzý ledi yak
	BSF   PORTD,1,0
			;		bekle(50);
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	}
			;
			;	if(PORTB.1==1)	//	reset-3 butonuna basýldýysa
m002	BTFSS PORTB,1,0
	BRA   m001
			;	{
			;		PORTD.1 = 0;	//	kýrmýzý ledi söndür
	BCF   PORTD,1,0
			;		PORTD.0 = 1;	//	yeþil ledi yak
	BSF   PORTD,0,0
			;		bekle(50);
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	}
			;	goto anadongu;
	BRA   m001
			;//-----------------------------------------------
			;
			;}
			;
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;
			;void ayarlar()	
			;{	
ayarlar
			;
			;	TRISD=0x00;	//	PORTD çýkýþ		
	CLRF  TRISD,0
			;	PORTD=0;
	CLRF  PORTD,0
			;	PORTD.0 = 1;	//	yeþil ledi yak
	BSF   PORTD,0,0
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
m003	MOVF  t,W,0
	IORWF t+1,W,0
	BZ    m006
			;		for(x=140;x>0;x--)
	MOVLW 140
	MOVWF x,0
m004	MOVF  x,1,0
	BZ    m005
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

; 0x000030    4 word(s)  0 % : ayarlar
; 0x000038   15 word(s)  0 % : bekle
; 0x000004   22 word(s)  0 % : main

; RAM usage: 3 bytes (3 local), 1533 bytes free
; Maximum call level: 1
; Total of 43 code words (0 %)
