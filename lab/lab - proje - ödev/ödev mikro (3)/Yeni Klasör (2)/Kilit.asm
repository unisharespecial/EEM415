
; CC8E Version 1.3F, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************   7. Dec 2013  10:25  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

INTCON      EQU   0xFF2
Zero_       EQU   2
TMR0H       EQU   0xFD7
T0CON       EQU   0xFD5
TRISD       EQU   0xF95
TRISB       EQU   0xF93
TRISA       EQU   0xF92
PORTD       EQU   0xF83
INT0IF      EQU   1
GIE         EQU   7
TMR0ON      EQU   7
t           EQU   0x00
x           EQU   0x02

	GOTO main

  ; FILE Kilit.c
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;
			;void ayarlar();
			;void bekle(unsigned long t);
			;void kesme() //kesme gelince yapilacak komutlar, kesmede calisacak fonksiyon main fonksiyonunun ustunde yazilir...	
			;{
kesme
			;    INTCON=0x90; // kesmeler acilir RBO/INT0 girisi interrupt enable edilir.
	MOVLW 144
	MOVWF INTCON,0
			;    T0CON=0b.0000.0101;//Timer baslatilir.
	MOVLW 5
	MOVWF T0CON,0
			;   	TMR0ON = 1;	// Timer0'ý saymaya baþlat
	BSF   0xFD5,TMR0ON,0
			;    PORTD.1 = 0;	//	yeþil ledi söndür
	BCF   PORTD,1,0
			;	PORTD.0 = 1;	//	mavi ledi yak
	BSF   PORTD,0,0
			;     nop();
	NOP  
			;	 T0CON=0b.0000.0000;//Timer durdurulur.
	CLRF  T0CON,0
			;     TMR0ON=0;
	BCF   0xFD5,TMR0ON,0
			;     PORTD.1=1;
	BSF   PORTD,1,0
			;     PORTD.0=0;	 
	BCF   PORTD,0,0
			;	 TMR0H=0b.0000;
	CLRF  TMR0H,0
			;	 nop();
	NOP  
			;
			;    INT0IF=0;  // yeni kesmeler gelmesi icin butona bagli olan INT0 portundaki interrupt flagi kapatilir.
	BCF   0xFF2,INT0IF,0
			;	GIE=1;	//kesmeler acilir, yeni kesme gelmesine musade edilir	
	BSF   0xFF2,GIE,0
			;
			;}		
	RETURN
			;
			;void main()
			;{
main
			; 
			;	ayarlar();
	RCALL ayarlar
			;
			;	anadongu: 
			;   
			;
			;	 
			;     	
			; 		bekle(1000);
m001	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;
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
			;  	GIE=0;			// Bütün kesmeleri kapat
	BCF   0xFF2,GIE,0
			;	TRISA=0xFF;		// PORTA giriþ
	SETF  TRISA,0
			;	TRISB=0xFF;		// PORTB giriþ	
	SETF  TRISB,0
			;	TRISD=0x00;		// PORTD çýkýþ
	CLRF  TRISD,0
			;
			; 	PORTD=0x00;
	CLRF  PORTD,0
			;
			;/*	ADCON0=0b.0100.0001;	//	ADC ayarlarý
			;	ADCON1=0b.0000.0000;*/
			;	
			;	T0CON = 0b.1101.1000;	// Timer0 ayarlarý
	MOVLW 216
	MOVWF T0CON,0
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

	END


; *** KEY INFO ***

; 0x000034    8 word(s)  0 % : ayarlar
; 0x000044   17 word(s)  0 % : bekle
; 0x000004   17 word(s)  0 % : kesme
; 0x000026    7 word(s)  0 % : main

; RAM usage: 3 bytes (3 local), 1533 bytes free
; Maximum call level: 1
; Total of 51 code words (0 %)
