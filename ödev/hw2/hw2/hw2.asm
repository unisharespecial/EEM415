
; CC8E Version 1.4, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************   7. Dec 2014  17:11  *************

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
t           EQU   0x00
x           EQU   0x02

	GOTO main

  ; FILE hw2.c
			;#pragma config[1] = 0xF1 // Osilat�r: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
			;#pragma config[3] = 0xFE // Watchdog Timer kapal�
			;
			;void ayarlar();
			;void bekle(unsigned long t);	// t milisaniye gecikme sa�layan fonksiyon tan�m�
			;void main()
			;{
main
			;	ayarlar();
	RCALL ayarlar
			;//-----------------------------------------------	
			;anadongu:
			; 	PORTD.0=0; 			// port D nin 0. aya�� high
m001	BCF   PORTD,0,0
			;	while(PORTB.0==1){
m002	BTFSS PORTB,0,0
	BRA   m001
			;		bekle(10);	 	// 10ms debounce s�resi bekle
	MOVLW 10
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;        PORTD.0=1;   	// port D nin 0. aya�� low
	BSF   PORTD,0,0
			;	}
	BRA   m002
			;
			;	goto anadongu;
			;//-----------------------------------------------	
			;}
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;void ayarlar()	// B�t�n ba�lang�� ayarlar�n�n tamamland��� k�s�m
			;{	
ayarlar
			;	GIE=0;			// B�t�n kesmeleri kapat
	BCF   0xFF2,GIE,0
			;	TRISB=0xFF;		// B portu giri� yap�ld�
	SETF  TRISB,0
			;	TRISD=0;		// D portu ��k�� yap�ld�		
	CLRF  TRISD,0
			;	PORTD=0;		// D portu ��k��lar� s�f�rland�	
	CLRF  PORTD,0
			;}
	RETURN
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;void bekle(unsigned long t)	//t milisaniye gecikme sa�lar
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

; 0x000018    5 word(s)  0 % : ayarlar
; 0x000022   17 word(s)  0 % : bekle
; 0x000004   10 word(s)  0 % : main

; RAM usage: 3 bytes (3 local), 1533 bytes free
; Maximum call level: 1
; Total of 34 code words (0 %)
