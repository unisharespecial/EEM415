
; CC8E Version 1.3D, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  23. Dec 2010  15:33  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1
	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

Zero_       EQU   2
ADRESH      EQU   0xFC4
ADCON0      EQU   0xFC2
ADCON1      EQU   0xFC1
SPBRG       EQU   0xFAF
TXREG       EQU   0xFAD
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
BRGH        EQU   2
SYNC        EQU   4
TXEN        EQU   5
TX9         EQU   6
SPEN        EQU   7
TXIF        EQU   4
TXIE        EQU   4
sayi        EQU   0x00
sayi1       EQU   0x01
deger       EQU   0x02
t           EQU   0x02
x           EQU   0x04

	GOTO main

  ; FILE adcdeneme.c
			;
			;#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;
			;void ayarlar();
			;void seriTXayar();
			;void serigonder(unsigned deger);
			;void bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý
			;
			;void main()
			;{	
main
			;	unsigned sayi='0';
	MOVLW 48
	MOVWF sayi,0
			;	unsigned sayi1='0';
	MOVLW 48
	MOVWF sayi1,0
			;	ayarlar();
	RCALL ayarlar
			;
			;//-----------------------------------------------	
			;anadongu:
			;
			;	bekle(1000);
m001	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;	GO=1;
	BSF   0xFC2,GO,0
			;	while(GO);
m002	BTFSC 0xFC2,GO,0
	BRA   m002
			;	sayi=ADRESH; //okunan analog degerin digital karsiligi, sayi degiskenine atýlýyor
	MOVFF ADRESH,sayi
			;	serigonder(sayi);
	MOVF  sayi,W,0
	RCALL serigonder
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
			;	ADCON0=0b.0100.0001;;
	MOVLW 65
	MOVWF ADCON0,0
			;	ADCON1=0b.0000.0000;;
	CLRF  ADCON1,0
			;	seriTXayar();
	BRA   seriTXayar
			;		
			;}
			;//////////////////////////////////////////////////////////////////////////////////
			;
			;
			;void serigonder(unsigned deger)	 // Seri porttan veri gönderir
			;{	
serigonder
	MOVWF deger,0
			;	while(!TXIF);
m003	BTFSS 0xF9E,TXIF,0
	BRA   m003
			;	nop(); nop(); nop(); nop();
	NOP  
	NOP  
	NOP  
	NOP  
			;	TXREG=deger;
	MOVFF deger,TXREG
			;}
	RETURN
			;
			;//////////////////////////////////////////////////////////////////////////////////
			;
			;
			;void seriTXayar()	// Seri Portu veri göndermeye hazýr hale getirir
			;{
seriTXayar
			;	TRISC.6=0;
	BCF   TRISC,6,0
			;	TRISC.7=1;
	BSF   TRISC,7,0
			;	SPBRG=25;	// Baud Rate=9.6k
	MOVLW 25
	MOVWF SPBRG,0
			;	BRGH=1;		// Yüksek Hýz
	BSF   0xFAC,BRGH,0
			;	SYNC=0;		// Asenkron mod
	BCF   0xFAC,SYNC,0
			;	SPEN=1;		// Seri port etkin
	BSF   0xFAB,SPEN,0
			;	TXIE=0;
	BCF   0xF9D,TXIE,0
			;	TX9=0;		// 8 bit Veri Gönderme
	BCF   0xFAC,TX9,0
			;	TXEN=1;	// Gönderme etkin	
	BSF   0xFAC,TXEN,0
			;}
	RETURN
			;
			;
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;
			;void bekle(unsigned long t)	//t milisaniye gecikme saðlar
			;{
bekle
			;	unsigned x;
			;	
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

	END


; *** KEY INFO ***

; 0x000028   15 word(s)  0 % : ayarlar
; 0x00005A   11 word(s)  0 % : seriTXayar
; 0x000046   10 word(s)  0 % : serigonder
; 0x000070   17 word(s)  0 % : bekle
; 0x000004   18 word(s)  0 % : main

; RAM usage: 5 bytes (5 local), 1531 bytes free
; Maximum call level: 1
; Total of 73 code words (0 %)
