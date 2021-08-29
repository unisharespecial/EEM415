
; CC8E Version 1.3F, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  20. Oct 2013   0:13  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1

INTCON      EQU   0xFF2
Zero_       EQU   2
ADRESH      EQU   0xFC4
ADCON0      EQU   0xFC2
ADCON1      EQU   0xFC1
TRISE       EQU   0xF96
TRISD       EQU   0xF95
TRISC       EQU   0xF94
TRISB       EQU   0xF93
TRISA       EQU   0xF92
PORTD       EQU   0xF83
PORTC       EQU   0xF82
GIE         EQU   7
GO          EQU   2
y           EQU   0x00
t           EQU   0x01
x           EQU   0x03

	GOTO main

  ; FILE odev.c
			;#pragma config[1] = 0xF1 // Osilatör: XT#pragma config[1] = 0xF1 // Osilatör: XT
			;void ayarlar();
			;void bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý
			;void deger();	
			;
			;
			;void deger() //kesme gelince yapilacak komutlar, kesmede calisacak fonksiyon main fonksiyonunun ustunde yazilir...	
			;{
deger
			; 	GO=1;	// adc cevrimi baslar
	BSF   0xFC2,GO,0
			;	while(GO);	//cevirme bitene kadar calisir, cevirme bitince go=0 olur
m001	BTFSC 0xFC2,GO,0
	BRA   m001
			;	PORTC=ADRESH;	//adc'den okunan deger PORTC ye aktarilirak sonuc gozlemlenir.
	MOVFF ADRESH,PORTC
			;	
			;}	
	RETURN
			;
			;
			;void main()
			;{
main
			;	
			;	ayarlar();
	RCALL ayarlar
			;
			;//-----------------------------------------------	
			;anadongu:
			;
			;	bekle(1);	// Acquisition Time(Sample & Hold kapasitörünün þarj olmasý için gerekli zaman)
m002	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	INTCON=0x90; // 
	MOVLW 144
	MOVWF INTCON,0
			;	
			;    unsigned y=0;
	CLRF  y,0
			;    while(y==0)            
m003	MOVF  y,1,0
	BTFSS 0xFD8,Zero_,0
	BRA   m002
			;	   nop();
	NOP  
	BRA   m003
			;
			;
			;
			;goto anadongu;
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
m004	MOVF  t,W,0
	IORWF t+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m007
			;		for(x=140;x>0;x--)
	MOVLW 140
	MOVWF x,0
m005	MOVF  x,1,0
	BTFSC 0xFD8,Zero_,0
	BRA   m006
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
			;
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;
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
			;	
			;	PORTC=0x00;		
	CLRF  PORTC,0
			;	PORTD=0x00;
	CLRF  PORTD,0
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

; 0x00004C   12 word(s)  0 % : ayarlar
; 0x00002A   17 word(s)  0 % : bekle
; 0x000004    6 word(s)  0 % : deger
; 0x000010   13 word(s)  0 % : main

; RAM usage: 4 bytes (4 local), 1532 bytes free
; Maximum call level: 1
; Total of 50 code words (0 %)
