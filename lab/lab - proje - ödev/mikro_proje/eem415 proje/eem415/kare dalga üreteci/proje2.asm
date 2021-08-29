
; CC8E Version 1.3D, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  13. Nov 2010  10:54  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1
	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

Zero_       EQU   2
PR2         EQU   0xFCB
T2CON       EQU   0xFCA
ADRESH      EQU   0xFC4
ADCON0      EQU   0xFC2
ADCON1      EQU   0xFC1
CCPR1L      EQU   0xFBE
CCP1CON     EQU   0xFBD
CCPR2L      EQU   0xFBB
CCP2CON     EQU   0xFBA
TRISE       EQU   0xF96
TRISD       EQU   0xF95
TRISC       EQU   0xF94
TRISB       EQU   0xF93
TRISA       EQU   0xF92
PORTD       EQU   0xF83
PORTC       EQU   0xF82
GIE         EQU   7
GO          EQU   2
deger       EQU   0x00
t           EQU   0x01
x           EQU   0x03

	GOTO main

  ; FILE proje2.c
			;//BERSU MEHMETLÝOGLU
			;//YESIM GUNHAN
			;//ONUR DENIZ KURT
			;//M.ERGIN HABERAL
			;//PROJE2
			;#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;
			;void ayarlar();
			;void bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý
			;void PWMayar();
			;
			;void main()
			;{
main
			;    unsigned int deger;
			; 
			;    PWMayar();
	RCALL PWMayar
			;	ayarlar();
	RCALL ayarlar
			;    PORTC=0;
	CLRF  PORTC,0
			;anadongu:
			;    
			;	bekle(1);	
m001	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	GO=1;
	BSF   0xFC2,GO,0
			;	while(GO);
m002	BTFSC 0xFC2,GO,0
	BRA   m002
			;	deger=ADRESH; //okunan analog degerin digital karsiligi, deger degiskenine atýlýyor
	MOVFF ADRESH,deger
			;    CCPR1L=deger;
	MOVFF deger,CCPR1L
			;   // CCPR2L=deger;
			;   //PORTC=deger;
			;    
			;
			;goto anadongu;
	BRA   m001
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
			;	ADCON0=0b.0100.0001;;
	MOVLW 65
	MOVWF ADCON0,0
			;	ADCON1=0b.0000.0000;;
	CLRF  ADCON1,0
			;}
	RETURN
			;void PWMayar()
			;{
PWMayar
			;	PR2=0XFF;		//Periyod yazmacý(Timer2 peryodu=255)
	SETF  PR2,0
			;	
			;	CCP1CON=0;		//PWM MODE OFF
	CLRF  CCP1CON,0
			;	CCPR1L=0;		
	CLRF  CCPR1L,0
			;	CCP1CON.4=0;	
	BCF   CCP1CON,4,0
			;	CCP1CON.5=0;
	BCF   CCP1CON,5,0
			;	
			;	CCP2CON=0;		//PWM MODE OFF
	CLRF  CCP2CON,0
			;	CCPR2L=0;		
	CLRF  CCPR2L,0
			;	CCP2CON.4=0;	
	BCF   CCP2CON,4,0
			;	CCP2CON.5=0;
	BCF   CCP2CON,5,0
			;	
			;	TRISC.2=0;
	BCF   TRISC,2,0
			;	TRISC.1=0;
	BCF   TRISC,1,0
			;			
			;	T2CON = 0b.0000.0100; // TMR2 ON, PRESCALE 1:1, POSTSCALE 1:1
	MOVLW 4
	MOVWF T2CON,0
			;
			;	CCP1CON=0b.0000.1100; //CCP1 ON
	MOVLW 12
	MOVWF CCP1CON,0
	RETURN

	END


; *** KEY INFO ***

; 0x000044   12 word(s)  0 % : ayarlar
; 0x000022   17 word(s)  0 % : bekle
; 0x00005C   16 word(s)  0 % : PWMayar
; 0x000004   15 word(s)  0 % : main

; RAM usage: 4 bytes (4 local), 1532 bytes free
; Maximum call level: 1
; Total of 62 code words (0 %)
