
; CC8E Version 1.3D, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************   3. Nov 2010  10:28  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1
	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

Zero_       EQU   2
TRISD       EQU   0xF95
TRISC       EQU   0xF94
PORTD       EQU   0xF83
PORTC       EQU   0xF82
GIE         EQU   7
TUS         EQU   0x03
t           EQU   0x00
x           EQU   0x02

	GOTO main

  ; FILE proje15.c
			;
			;#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;
			;char	keypad_oku();
			;char	TUS;
			;void	ayarlar();
			;void 	bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý
			;
			;
			;void main()
			;{
main
			;	ayarlar();
	RCALL ayarlar
			;
			;//-----------------------------------------------	
			;anadongu:
			;	bekle(1);	// Acquisition Time(Sample & Hold kapasitörünün þarj olmasý için gerekli zaman)
	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;  	while(1)
			; {
			;	PORTD=keypad_oku();
m001	RCALL keypad_oku
	MOVWF PORTD,0
			; }   
	BRA   m001
			;	goto anadongu;
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
			;	TRISC=0xF0;		// C portu giriþ yapýldý
	MOVLW 240
	MOVWF TRISC,0
			;	TRISD=0;		// D portu çýkýþ yapýldý
	CLRF  TRISD,0
			;		
			;	PORTD=0;		// D portu çýkýþlarý sýfýrlandý
	CLRF  PORTD,0
			;	PORTC=0;		// C portu çýkýþlarý sýfýrlandý
	CLRF  PORTC,0
			;
			;	
			;	
			;}
	RETURN
			;
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;
			;char keypad_oku()	// tarama keypad'ýn okunduðu kýsým
			;{	
keypad_oku
			;	PORTC.0=1;
	BSF   PORTC,0,0
			;	if(PORTC.4==1)
	BTFSS PORTC,4,0
	BRA   m002
			;	{bekle(999);TUS=0X01;}
	MOVLW 231
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
	MOVLW 1
	MOVWF TUS,0
			;	if(PORTC.5==1)
m002	BTFSS PORTC,5,0
	BRA   m003
			;	{bekle(999);TUS=0X02;}
	MOVLW 231
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
	MOVLW 2
	MOVWF TUS,0
			;	if(PORTC.6==1)
m003	BTFSS PORTC,6,0
	BRA   m004
			;	{bekle(999);TUS=0X03;}
	MOVLW 231
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
	MOVLW 3
	MOVWF TUS,0
			;	if(PORTC.7==1)
m004	BTFSS PORTC,7,0
	BRA   m005
			;	{bekle(999);TUS=0X0A;}
	MOVLW 231
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
	MOVLW 10
	MOVWF TUS,0
			;
			;	PORTC.1=1;
m005	BSF   PORTC,1,0
			;	if(PORTC.4==1)
	BTFSS PORTC,4,0
	BRA   m006
			;	{bekle(999);TUS=0X04;}
	MOVLW 231
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
	MOVLW 4
	MOVWF TUS,0
			;	if(PORTC.5==1)
m006	BTFSS PORTC,5,0
	BRA   m007
			;	{bekle(999);TUS=0X05;}
	MOVLW 231
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
	MOVLW 5
	MOVWF TUS,0
			;	if(PORTC.6==1)
m007	BTFSS PORTC,6,0
	BRA   m008
			;	{bekle(999);TUS=0X06;}
	MOVLW 231
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
	MOVLW 6
	MOVWF TUS,0
			;	if(PORTC.7==1)
m008	BTFSS PORTC,7,0
	BRA   m009
			;	{bekle(999);TUS=0X0B;}
	MOVLW 231
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
	MOVLW 11
	MOVWF TUS,0
			;
			;	PORTC.2=1;
m009	BSF   PORTC,2,0
			;	if(PORTC.4==1)
	BTFSS PORTC,4,0
	BRA   m010
			;	{bekle(999);TUS=0X07;}
	MOVLW 231
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
	MOVLW 7
	MOVWF TUS,0
			;	if(PORTC.5==1)
m010	BTFSS PORTC,5,0
	BRA   m011
			;	{bekle(999);TUS=0X08;}
	MOVLW 231
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
	MOVLW 8
	MOVWF TUS,0
			;	if(PORTC.6==1)
m011	BTFSS PORTC,6,0
	BRA   m012
			;	{bekle(999);TUS=0X09;}
	MOVLW 231
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
	MOVLW 9
	MOVWF TUS,0
			;	if(PORTC.7==1)
m012	BTFSS PORTC,7,0
	BRA   m013
			;	{bekle(999);TUS=0X0C;}
	MOVLW 231
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
	MOVLW 12
	MOVWF TUS,0
			;
			;	PORTC.3=1;
m013	BSF   PORTC,3,0
			;	if(PORTC.4==1)
	BTFSS PORTC,4,0
	BRA   m014
			;	{bekle(999);TUS=0X0E;}
	MOVLW 231
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
	MOVLW 14
	MOVWF TUS,0
			;	if(PORTC.5==1)
m014	BTFSS PORTC,5,0
	BRA   m015
			;	{bekle(999);TUS=0X00;}
	MOVLW 231
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
	CLRF  TUS,0
			;	if(PORTC.6==1)
m015	BTFSS PORTC,6,0
	BRA   m016
			;	{bekle(999);TUS=0X0F;}
	MOVLW 231
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
	MOVLW 15
	MOVWF TUS,0
			;	if(PORTC.7==1)
m016	BTFSS PORTC,7,0
	BRA   m017
			;	{bekle(999);TUS=0X0D;}
	MOVLW 231
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
	MOVLW 13
	MOVWF TUS,0
			;	
			;	return TUS;	
m017	MOVF  TUS,W,0
	RETURN
			;	
			;}
			;
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;
			;void bekle(unsigned long t)	//t milisaniye gecikme saðlar
			;{
bekle
			;	unsigned x;
			;	
			;	for(;t>0;t--)
m018	MOVF  t,W,0
	IORWF t+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m021
			;		for(x=540;x>0;x--)
	MOVLW 28
	MOVWF x,0
m019	MOVF  x,1,0
	BTFSC 0xFD8,Zero_,0
	BRA   m020
			;			nop();
	NOP  
	DECF  x,1,0
	BRA   m019
m020	DECF  t,1,0
	MOVLW 0
	SUBWFB t+1,1,0
	BRA   m018
			;}
m021	RETURN

	END


; *** KEY INFO ***

; 0x000022  149 word(s)  0 % : keypad_oku
; 0x000014    7 word(s)  0 % : ayarlar
; 0x00014C   17 word(s)  0 % : bekle
; 0x000004    8 word(s)  0 % : main

; RAM usage: 4 bytes (3 local), 1532 bytes free
; Maximum call level: 2
; Total of 183 code words (1 %)
