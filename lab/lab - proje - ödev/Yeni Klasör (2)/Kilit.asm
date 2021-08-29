
; CC8E Version 1.3B, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  14. Jan 2011  12:05  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

TMR0L       EQU   0xFD6
T0CON       EQU   0xFD5
ADRESH      EQU   0xFC4
ADCON0      EQU   0xFC2
ADCON1      EQU   0xFC1
TRISD       EQU   0xF95
TRISB       EQU   0xF93
TRISA       EQU   0xF92
PORTD       EQU   0xF83
PORTB       EQU   0xF81
GIE         EQU   7
TMR0ON      EQU   7
GO          EQU   2
deger       EQU   0x00
t           EQU   0x01
x           EQU   0x03

	GOTO main

  ; FILE Kilit.c
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;
			;void ayarlar();
			;void bekle(unsigned long t);	
			;
			;void main()
			;{
main
			;    unsigned int deger;
			;	ayarlar();
	RCALL ayarlar
			;
			;	anadongu:
			;	
			;	PORTD.0 = 1;	//	mavi ledi yak
m001	BSF   PORTD,0,0
			;	
			;	if(PORTB.0==0)	//	BUTTON_1'e basýldýysa
	BTFSC PORTB,0,0
	BRA   m001
			;	{
			;		PORTD.0 = 0;	//	mavi ledi söndür
	BCF   PORTD,0,0
			;		PORTD.1 = 1;	//	yeþil ledi yak
	BSF   PORTD,1,0
			;				
			;		GO=1;	//	ADC çevrimini baþlat
	BSF   0xFC2,GO,0
			;		while(GO);
m002	BTFSC 0xFC2,GO,0
	BRA   m002
			;		deger=ADRESH; //okunan analog deðerin digital karþýlýðýný deger deðiþkenine at
	MOVFF ADRESH,deger
			;
			;    	TMR0ON = 1;	// Timer0'ý saymaya baþlat
	BSF   0xFD5,TMR0ON,0
			;		
			;
			;		while(TMR0L < deger);	//	Timer0 "deger" deðiþkenindeki deðere ulaþana kadar say
m003	MOVF  deger,W,0
	CPFSLT TMR0L,0
	BRA   m004
	BRA   m003
			;		bekle(3000);
m004	MOVLW 184
	MOVWF t,0
	MOVLW 11
	MOVWF t+1,0
	RCALL bekle
			;				
			;		PORTD.1 = 0;	//	yeþil ledi söndür
	BCF   PORTD,1,0
			;		PORTD.0 = 1;	//	mavi ledi yak
	BSF   PORTD,0,0
			;				
			; 		
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
			;	ADCON0=0b.0100.0001;	//	ADC ayarlarý
	MOVLW 65
	MOVWF ADCON0,0
			;	ADCON1=0b.0000.0000;
	CLRF  ADCON1,0
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
m005	MOVF  t,W,0
	IORWF t+1,W,0
	BZ    m008
			;		for(x=140;x>0;x--)
	MOVLW 140
	MOVWF x,0
m006	MOVF  x,1,0
	BZ    m007
			;			nop();
	NOP  
	DECF  x,1,0
	BRA   m006
m007	DECF  t,1,0
	MOVLW 0
	SUBWFB t+1,1,0
	BRA   m005
			;}
m008	RETURN

	END


; *** KEY INFO ***

; 0x000034   11 word(s)  0 % : ayarlar
; 0x00004A   15 word(s)  0 % : bekle
; 0x000004   24 word(s)  0 % : main

; RAM usage: 4 bytes (4 local), 1532 bytes free
; Maximum call level: 1
; Total of 52 code words (0 %)
