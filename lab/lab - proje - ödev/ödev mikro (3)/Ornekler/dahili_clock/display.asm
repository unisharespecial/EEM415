
; CC8E Version 1.3F, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************   1. Dec 2013  18:17  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

Zero_       EQU   2
TMR1H       EQU   0xFCF
T1CON       EQU   0xFCD
TRISC       EQU   0xF94
PORTC       EQU   0xF82
GIE         EQU   7
t           EQU   0x00
x           EQU   0x02
s           EQU   0x00

	GOTO main

  ; FILE display.c
			;//#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;
			;void ayarlar();
			;void bekle(unsigned long t);
			;void sifirla(unsigned long s);
			;
			;
			;void main()
			;{
main
			;	ayarlar();
	RCALL ayarlar
			;
			;anadongu:
			;
			;
			;T1CON=0b.0000.0101;
m001	MOVLW 5
	MOVWF T1CON,0
			;PORTC=TMR1H;
	MOVFF TMR1H,PORTC
			;T1CON=0b.0000.0000;
	CLRF  T1CON,0
			;bekle(5);
	MOVLW 5
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;sifirla(TMR1H);
	MOVFF TMR1H,s
	CLRF  s+1,0
	RCALL sifirla
			;
			;
			;
			;goto anadongu;
	BRA   m001
			;}
			;
			;void bekle(unsigned long t)
			;{
bekle
			;	unsigned x;
			;	
			;	for(;t>0;t--)
m002	MOVF  t,W,0
	IORWF t+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m005
			;		for(x=140;x>0;x--)
	MOVLW 140
	MOVWF x,0
m003	MOVF  x,1,0
	BTFSC 0xFD8,Zero_,0
	BRA   m004
			;			nop();
	NOP  
	DECF  x,1,0
	BRA   m003
m004	DECF  t,1,0
	MOVLW 0
	SUBWFB t+1,1,0
	BRA   m002
			;}
m005	RETURN
			;
			;void sifirla(unsigned long s)
			;{
sifirla
			;	if(s>9)
	MOVF  s+1,W,0
	BTFSS 0xFD8,Zero_,0
	BRA   m006
	MOVLW 10
	CPFSLT s,0
			;		TMR1H=0b.0000;
m006	CLRF  TMR1H,0
			;}
	RETURN
			;
			;void ayarlar()
			;{	
ayarlar
			;	GIE=0;	
	BCF   0xFF2,GIE,0
			;	TRISC=0x00;		
	CLRF  TRISC,0
			;}
	RETURN

	END


; *** KEY INFO ***

; 0x000052    3 word(s)  0 % : ayarlar
; 0x000022   17 word(s)  0 % : bekle
; 0x000044    7 word(s)  0 % : sifirla
; 0x000004   15 word(s)  0 % : main

; RAM usage: 3 bytes (3 local), 1533 bytes free
; Maximum call level: 1
; Total of 44 code words (0 %)
