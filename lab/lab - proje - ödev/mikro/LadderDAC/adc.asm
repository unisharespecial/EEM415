
; CC8E Version 1.3F, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  28. Oct 2013  16:22  *************

	processor  PIC18F242
	radix  DEC

	__config 0x300001, 0xF1

Zero_       EQU   2
ADRESH      EQU   0xFC4
ADCON0      EQU   0xFC2
ADCON1      EQU   0xFC1
TRISC       EQU   0xF94
TRISA       EQU   0xF92
PORTC       EQU   0xF82
GIE         EQU   7
GO          EQU   2
t           EQU   0x00
x           EQU   0x02

	GOTO main

  ; FILE adc.c
			;#pragma config[1] = 0xF1 // Osilatör: XT#pragma config[1] = 0xF1 // Osilatör: XT
			;void ayarlar();
			;void bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý
			;
			;void main()
			;{
main
			;	
			;	ayarlar();
	RCALL ayarlar
			;
			;//-----------------------------------------------
			;
			;anadongu:
			;	GO=1;	// adc cevrimi baslar
m001	BSF   0xFC2,GO,0
			;	bekle(1);	// Acquisition Time(Sample & Hold kapasitörünün þarj olmasý için gerekli zaman)
	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	//INTCON=0x90; // 
			;	while(GO);	//cevirme bitene kadar calisir, cevirme bitince go=0 olur
m002	BTFSC 0xFC2,GO,0
	BRA   m002
			;	PORTC=ADRESH;	//adc'den okunan deger PORTC ye aktarilirak sonuc gozlemlenir.          
	MOVFF ADRESH,PORTC
			;goto anadongu;
	BRA   m001
			;
			;//-----------------------------------------------	
			;}
			;
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;
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
			;
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;
			;void ayarlar()	// Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
			;{	
ayarlar
			;	GIE=0;			// Bütün kesmeleri kapat
	BCF   0xFF2,GIE,0
			;	TRISA=0xFF;		// A portu giriþ yapýldý
	SETF  TRISA,0
			;	TRISC=0x00;		// C portu çýkýþ yapýldý
	CLRF  TRISC,0
			;	
			;	ADCON0=0b.0100.0001;// Anlog kanal 0 aktif, A/D conversion is not in progress
	MOVLW 65
	MOVWF ADCON0,0
			;	ADCON1=0b.0000.0000;
	CLRF  ADCON1,0
			;}
	RETURN

	END


; *** KEY INFO ***

; 0x00003C    7 word(s)  0 % : ayarlar
; 0x00001A   17 word(s)  0 % : bekle
; 0x000004   11 word(s)  0 % : main

; RAM usage: 3 bytes (3 local), 765 bytes free
; Maximum call level: 1
; Total of 37 code words (0 %)
