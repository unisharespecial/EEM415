
; CC8E Version 1.3D, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  19. Nov 2010  16:22  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1
	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

Zero_       EQU   2
TRISE       EQU   0xF96
TRISD       EQU   0xF95
TRISC       EQU   0xF94
TRISB       EQU   0xF93
PORTE       EQU   0xF84
PORTD       EQU   0xF83
PORTC       EQU   0xF82
PORTB       EQU   0xF81
GIE         EQU   7
TUS         EQU   0x03
TUS1        EQU   0x04
TUS2        EQU   0x05
t           EQU   0x00
x           EQU   0x02

	GOTO main

  ; FILE prj2.c
			;
			;#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;
			;char	tus_oku();
			;char	TUS;
			;char	TUS1;
			;char	TUS2;
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
m001	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;  	while(PORTB.0==1)
m002	BTFSS PORTB,0,0
	BRA   m005
			; {
			;	PORTD=0x00;
	CLRF  PORTD,0
			;	if (PORTB.1==1)
	BTFSS PORTB,1,0
	BRA   m003
			;	{PORTD=0xF1;bekle(1);}
	MOVLW 241
	MOVWF PORTD,0
	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	if (PORTB.2==1)
m003	BTFSS PORTB,2,0
	BRA   m004
			;	{PORTD=0xF2;bekle(1);}
	MOVLW 242
	MOVWF PORTD,0
	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	PORTE=tus_oku();
m004	RCALL tus_oku
	MOVWF PORTE,0
			; }   
	BRA   m002
			;	PORTD=0x00;
m005	CLRF  PORTD,0
			;	goto anadongu;
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
			;	TRISC=0xFF;		// C portu giriþ yapýldý
	SETF  TRISC,0
			;	TRISD=0;		// D portu çýkýþ yapýldý
	CLRF  TRISD,0
			;	TRISB=0xFF;		// B portu çýkýþ yapýldý
	SETF  TRISB,0
			;	TRISE=0;		// E portu çýkýþ yapýldý
	CLRF  TRISE,0
			;	
			;	PORTB=0;		// B portu çýkýþlarý sýfýrlandý
	CLRF  PORTB,0
			;	PORTE=0;		// E portu çýkýþlarý sýfýrlandý	
	CLRF  PORTE,0
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
			;////////////////////////////////////////////////////////////////////////////////////////////
			;char tus_oku()	// tarama keypad'ýn okunduðu kýsým
			;{
tus_oku
			;
			;	TUS1=PORTC;
	MOVFF PORTC,TUS1
			;	bekle(5);
	MOVLW 5
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	TUS2=PORTC;
	MOVFF PORTC,TUS2
			;	bekle(5);
	MOVLW 5
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	if(TUS1<TUS2)
	MOVF  TUS2,W,0
	CPFSLT TUS1,0
	BRA   m006
			;	{TUS=0x01;bekle(2);}
	MOVLW 1
	MOVWF TUS,0
	MOVLW 2
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	if(TUS1>TUS2)
m006	MOVF  TUS1,W,0
	CPFSLT TUS2,0
	BRA   m007
			;	{TUS=0x02;bekle(2);}	
	MOVLW 2
	MOVWF TUS,0
	MOVLW 2
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;
			;	return TUS;	
m007	MOVF  TUS,W,0
	RETURN
			;}
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;
			;void bekle(unsigned long t)	//t milisaniye gecikme saðlar
			;{
bekle
			;	unsigned x;
			;	
			;	for(;t>0;t--)
m008	MOVF  t,W,0
	IORWF t+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m011
			;		for(x=140;x>0;x--)
	MOVLW 140
	MOVWF x,0
m009	MOVF  x,1,0
	BTFSC 0xFD8,Zero_,0
	BRA   m010
			;			nop();
	NOP  
	DECF  x,1,0
	BRA   m009
m010	DECF  t,1,0
	MOVLW 0
	SUBWFB t+1,1,0
	BRA   m008
			;}
m011	RETURN

	END


; *** KEY INFO ***

; 0x000052   32 word(s)  0 % : tus_oku
; 0x00003E   10 word(s)  0 % : ayarlar
; 0x000092   17 word(s)  0 % : bekle
; 0x000004   29 word(s)  0 % : main

; RAM usage: 6 bytes (3 local), 1530 bytes free
; Maximum call level: 2
; Total of 90 code words (0 %)
