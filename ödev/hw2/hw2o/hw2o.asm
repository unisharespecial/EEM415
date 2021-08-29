
; CC8E Version 1.4, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************   8. Dec 2014  19:19  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1

INTCON      EQU   0xFF2
Carry       EQU   0
Zero_       EQU   2
TRISE       EQU   0xF96
TRISD       EQU   0xF95
TRISC       EQU   0xF94
TRISB       EQU   0xF93
TRISA       EQU   0xF92
PORTD       EQU   0xF83
PORTC       EQU   0xF82
GIE         EQU   7
t           EQU   0x00
x           EQU   0x02

	GOTO main

  ; FILE hw2o.c
			;#pragma config[1] = 0xF1 // Osilatör: XT#pragma config[1] = 0xF1 // Osilatör: XT
			;void ayarlar();
			;void bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý
			;void main()
			;{
main
			;	ayarlar();
	RCALL ayarlar
			;anadongu:
			;  bekle(1);	// Acquisition Time(Sample & Hold kapasitörünün þarj olmasý için gerekli zaman)
	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;  INTCON=0x90; 
	MOVLW 144
	MOVWF INTCON,0
			;
			;PWM_dongu:
			;	PORTC.0=1;
m001	BSF   PORTC,0,0
			;   	bekle(2); 
	MOVLW 2
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;    	PORTC.0=0;
	BCF   PORTC,0,0
			;    	bekle(2);
	MOVLW 2
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;goto PWM_dongu;
	BRA   m001
			;
			;goto anadongu;
			;//-----------------------------------------------	
			;}
			;void bekle(unsigned long t)	//t milisaniye gecikme saðlar
			;{
bekle
			;	unsigned x;
			;	t=t/2;
	BCF   0xFD8,Carry,0
	RRCF  t+1,1,0
	RRCF  t,1,0
			;	for(;t>0;t--)
m002	MOVF  t,W,0
	IORWF t+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m005
			;		for(x=35;x>0;x--)
	MOVLW 35
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
			;void ayarlar()	// Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
			;{	
ayarlar
			;	GIE=1;			// Bütün kesmeleri ac
	BSF   0xFF2,GIE,0
			;	TRISA=0xFF;
	SETF  TRISA,0
			;	TRISB=0xFF;
	SETF  TRISB,0
			;	TRISC=0x00;	
	CLRF  TRISC,0
			;	TRISD=0x00;		
	CLRF  TRISD,0
			;	TRISE=0xFF;
	SETF  TRISE,0
			;	PORTC=0x00;		
	CLRF  PORTC,0
			;	PORTD=0x00;
	CLRF  PORTD,0
			;	//ADCON0=0b.0100.0001;// Anlog kanal 0 aktif, A/D conversion is not in progress
			;	//ADCON1=0b.0000.0000;
			;}
	RETURN

	END


; *** KEY INFO ***

; 0x000050    9 word(s)  0 % : ayarlar
; 0x000028   20 word(s)  0 % : bekle
; 0x000004   18 word(s)  0 % : main

; RAM usage: 3 bytes (3 local), 1533 bytes free
; Maximum call level: 1
; Total of 49 code words (0 %)
