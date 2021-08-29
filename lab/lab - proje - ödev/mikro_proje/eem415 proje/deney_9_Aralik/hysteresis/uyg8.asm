
; CC8E Version 1.3B, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************   8. Dec 2010  14:37  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1
	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

Carry       EQU   0
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
PORTB       EQU   0xF81
GIE         EQU   7
GO          EQU   2
CHS0        EQU   3
fan         EQU   0
sicaklik    EQU   0x00
hys         EQU   0x01
altsinir    EQU   0x02
ustsinir    EQU   0x03
t           EQU   0x04
x           EQU   0x06

	GOTO main

  ; FILE uyg8.c
			;
			;#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;
			;void ayarlar();
			;void bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý
			;
			;bit fan @ PORTD.0;
			;
			;void main()
			;{
main
			;	unsigned sicaklik=0, hys=0, altsinir=0, ustsinir=0;
	CLRF  sicaklik,0
	CLRF  hys,0
	CLRF  altsinir,0
	CLRF  ustsinir,0
			;	
			;	ayarlar();
	RCALL ayarlar
			;
			;//-----------------------------------------------	
			;anadongu:
			;
			;	CHS0=0;
m001	BCF   0xFC2,CHS0,0
			;	bekle(1);	// Acquisition Time(Sample & Hold kapasitörünün þarj olmasý için gerekli zaman)
	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	GO=1;		// Çevrimi baþlat
	BSF   0xFC2,GO,0
			;	while(GO);	// Çevrim bitti mi?
m002	BTFSC 0xFC2,GO,0
	BRA   m002
			;	sicaklik=ADRESH;
	MOVFF ADRESH,sicaklik
			;	
			;	CHS0=1;
	BSF   0xFC2,CHS0,0
			;	bekle(1);
	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	GO=1;		
	BSF   0xFC2,GO,0
			;	while(GO);	
m003	BTFSC 0xFC2,GO,0
	BRA   m003
			;	hys=ADRESH/2;
	BCF   0xFD8,Carry,0
	RRCF  ADRESH,W,0
	MOVWF hys,0
			;	
			;	ustsinir=128+hys;
	MOVLW 128
	ADDWF hys,W,0
	MOVWF ustsinir,0
			;	altsinir=128-hys;
	MOVF  hys,W,0
	SUBLW 128
	MOVWF altsinir,0
			;	
			;	if(fan==0)
	BTFSC 0xF83,fan,0
	BRA   m004
			;	{
			;		if(sicaklik>ustsinir)
	MOVF  sicaklik,W,0
	CPFSLT ustsinir,0
	BRA   m001
			;			fan=1;
	BSF   0xF83,fan,0
			;	}
			;	else
	BRA   m001
			;	{
			;		if(sicaklik<altsinir)
m004	MOVF  altsinir,W,0
	CPFSLT sicaklik,0
	BRA   m001
			;			fan=0;
	BCF   0xF83,fan,0
			;	}
			;
			;goto anadongu;
	BRA   m001
			;//-----------------------------------------------	
			;}
			;
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;
			;void ayarlar()	// Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
			;{	
ayarlar
			;	GIE=0;			// Bütün kesmeleri kapat
	BCF   0xFF2,GIE,0
			;	TRISA=0xFF;
	SETF  TRISA,0
			;	TRISB=0;
	CLRF  TRISB,0
			;	TRISC=0;	
	CLRF  TRISC,0
			;	TRISD=0;
	CLRF  TRISD,0
			;	TRISE.0=1;
	BSF   TRISE,0,0
			;	TRISE.1=1;
	BSF   TRISE,1,0
			;	TRISE.2=1;
	BSF   TRISE,2,0
			;	
			;	PORTC=0;		
	CLRF  PORTC,0
			;	PORTD=0;
	CLRF  PORTD,0
			;	PORTB=0;
	CLRF  PORTB,0
			;	
			;	ADCON0=0b.0100.0001;
	MOVLW 65
	MOVWF ADCON0,0
			;	ADCON1=0b.0000.0000;
	CLRF  ADCON1,0
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

; 0x00005C   15 word(s)  0 % : ayarlar
; 0x00007A   15 word(s)  0 % : bekle
; 0x000004   44 word(s)  0 % : main

; RAM usage: 7 bytes (7 local), 1529 bytes free
; Maximum call level: 1
; Total of 76 code words (0 %)
