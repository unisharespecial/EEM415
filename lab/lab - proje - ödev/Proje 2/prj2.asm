
; CC8E Version 1.3D, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  19. Nov 2010  21:35  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1
	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

Zero_       EQU   2
TRISD       EQU   0xF95
TRISC       EQU   0xF94
TRISB       EQU   0xF93
PORTD       EQU   0xF83
PORTB       EQU   0xF81
GIE         EQU   7
t           EQU   0x04
x           EQU   0x06

	GOTO main

  ; FILE prj2.c
			;
			;#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;
			;
			; void bekle(unsigned long t)	//t milisaniye gecikme saðlar
			;{
bekle
			;	unsigned x;
			;	
			;	for(;t>0;t--)
m001	MOVF  t,W,0
	IORWF t+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m004
			;		for(x=140;x>0;x--)
	MOVLW 140
	MOVWF x,0
m002	MOVF  x,1,0
	BTFSC 0xFD8,Zero_,0
	BRA   m003
			;			nop();
	NOP  
	DECF  x,1,0
	BRA   m002
m003	DECF  t,1,0
	MOVLW 0
	SUBWFB t+1,1,0
	BRA   m001
			;}
m004	RETURN
			;void ayarlar()   // Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
			;{   
ayarlar
			;   GIE=0;         // Bütün kesmeleri kapat
	BCF   0xFF2,GIE,0
			;   TRISB=0xFF;    // B portu giriþ yapýldý(Butonlar)
	SETF  TRISB,0
			;   TRISC=0;
	CLRF  TRISC,0
			;   TRISD=0;       // D portu çýkýþ yapýldý(DC-Motor)      
	CLRF  TRISD,0
			;   PORTD=0xFF;       
	SETF  PORTD,0
			;}
	RETURN
			;
			;void basla()
			;{
basla
			;
			;	while(PORTB.1) // stop butonuna basýlmadýðý sürece program devam edecek
m005	BTFSS PORTB,1,0
	BRA   m007
			;	{
			;		PORTD=0xFF;
	SETF  PORTD,0
			;		if(PORTB.2==0)   	//  saga donme butonuna basýldý mý?
	BTFSC PORTB,2,0
	BRA   m006
			;		{PORTD = 0x01;bekle(10);}
	MOVLW 1
	MOVWF PORTD,0
	MOVLW 10
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;
			;		if(PORTB.3==0)    	// sola dönme butonuna basýldý mý?
m006	BTFSC PORTB,3,0
	BRA   m005
			;		{PORTD = 0x02;bekle(10);}
	MOVLW 2
	MOVWF PORTD,0
	MOVLW 10
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;				
			;	}
	BRA   m005
			;}
m007	RETURN
			;
			;
			;void main()
			;{
main
			;anadongu:		
			;    bekle(1);	
m008	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;    ayarlar();
	RCALL ayarlar
			;    unsigned STOP,START,RIGHT,LEFT;
			;    
			;    if(PORTB.0==0) // start butonuna basýldý mý?
	BTFSC PORTB,0,0
	BRA   m008
			;      {basla(); }
	RCALL basla
			;goto anadongu;
	BRA   m008

	END


; *** KEY INFO ***

; 0x000004   17 word(s)  0 % : bekle
; 0x000026    6 word(s)  0 % : ayarlar
; 0x000032   21 word(s)  0 % : basla
; 0x00005C    9 word(s)  0 % : main

; RAM usage: 7 bytes (7 local), 1529 bytes free
; Maximum call level: 2
; Total of 55 code words (0 %)
