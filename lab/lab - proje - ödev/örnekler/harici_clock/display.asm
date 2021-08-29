
; CC8E Version 1.3F, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************   1. Dec 2013  18:30  *************

	processor  PIC18F452
	radix  DEC

Zero_       EQU   2
TMR0L       EQU   0xFD6
T0CON       EQU   0xFD5
TRISC       EQU   0xF94
TRISA       EQU   0xF92
PORTC       EQU   0xF82
GIE         EQU   7
t           EQU   0x00
x           EQU   0x02
s           EQU   0x00

	GOTO main

  ; FILE display.c
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
			;T0CON=0b.1110.1000;
m001	MOVLW 232
	MOVWF T0CON,0
			;PORTC=TMR0L;
	MOVFF TMR0L,PORTC
			;//T0CON=0b.0000.0000;
			;bekle(5);
	MOVLW 5
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;sifirla(TMR0L);
	MOVFF TMR0L,s
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
			;		TMR0L=0b.0000;
m006	CLRF  TMR0L,0
			;}
	RETURN
			;
			;void ayarlar()
			;{	
ayarlar
			;	GIE=0;	
	BCF   0xFF2,GIE,0
			;	TRISA=0xFF;
	SETF  TRISA,0
			;	TRISC=0x00;		
	CLRF  TRISC,0
			;}
	RETURN

	END


; *** KEY INFO ***

; 0x000050    4 word(s)  0 % : ayarlar
; 0x000020   17 word(s)  0 % : bekle
; 0x000042    7 word(s)  0 % : sifirla
; 0x000004   14 word(s)  0 % : main

; RAM usage: 3 bytes (3 local), 1533 bytes free
; Maximum call level: 1
; Total of 44 code words (0 %)
