
; CC8E Version 1.3B, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  30. Dec 2010   8:11  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1
	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

TRISD       EQU   0xF95
TRISB       EQU   0xF93
PORTD       EQU   0xF83
PORTB       EQU   0xF81
GIE         EQU   7
t           EQU   0x00
x           EQU   0x02

	GOTO main

  ; FILE DTMF.c
			;#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;
			;void ayarlar();
			;void bekle(unsigned long t);   // t milisaniye gecikme saðlayan fonksiyon tanýmý
			;
			;
			;void main()
			;{
main
			;   ayarlar();
	RCALL ayarlar
			;
			;//-----------------------------------------------   
			;anadongu:
			;
			;    bekle(1);   // Acquisition Time(Sample & Hold kapasitörünün þarj olmasý için gerekli zaman)
	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;    
			;     
			;    while(1)
			;    {
			;    
			;    
			;    PORTB.0=1;
m001	BSF   PORTB,0,0
			;    if(PORTB.4==1)
	BTFSS PORTB,4,0
	BRA   m002
			;    {
			;      bekle(2);
	MOVLW 2
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;      PORTD=0x01;}
	MOVLW 1
	MOVWF PORTD,0
			;    if(PORTB.5==1)
m002	BTFSS PORTB,5,0
	BRA   m003
			;    {
			;      bekle(2);
	MOVLW 2
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;      PORTD=0x02;}
	MOVLW 2
	MOVWF PORTD,0
			;    if(PORTB.6==1)
m003	BTFSS PORTB,6,0
	BRA   m004
			;    {
			;      bekle(2);
	MOVLW 2
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;      PORTD=0x03;}
	MOVLW 3
	MOVWF PORTD,0
			;    PORTB.0=0;
m004	BCF   PORTB,0,0
			;    
			;    PORTB.1=1;
	BSF   PORTB,1,0
			;    if(PORTB.4==1)
	BTFSS PORTB,4,0
	BRA   m005
			;    {
			;      bekle(2);
	MOVLW 2
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;      PORTD=0x04;}
	MOVLW 4
	MOVWF PORTD,0
			;    if(PORTB.5==1)
m005	BTFSS PORTB,5,0
	BRA   m006
			;    {
			;      bekle(2);
	MOVLW 2
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;      PORTD=0x05;}
	MOVLW 5
	MOVWF PORTD,0
			;    if(PORTB.6==1)
m006	BTFSS PORTB,6,0
	BRA   m007
			;    {
			;      bekle(2);
	MOVLW 2
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;      PORTD=0x06;}
	MOVLW 6
	MOVWF PORTD,0
			;    PORTB.1=0; 
m007	BCF   PORTB,1,0
			;     
			;    PORTB.2=1;
	BSF   PORTB,2,0
			;    if(PORTB.4==1)
	BTFSS PORTB,4,0
	BRA   m008
			;    {
			;      bekle(2);
	MOVLW 2
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;      PORTD=0x07;}
	MOVLW 7
	MOVWF PORTD,0
			;    if(PORTB.5==1)
m008	BTFSS PORTB,5,0
	BRA   m009
			;    {
			;      bekle(2);
	MOVLW 2
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;      PORTD=0x08;}
	MOVLW 8
	MOVWF PORTD,0
			;    if(PORTB.6==1)
m009	BTFSS PORTB,6,0
	BRA   m010
			;    {
			;      bekle(2);
	MOVLW 2
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;      PORTD=0x09;}
	MOVLW 9
	MOVWF PORTD,0
			;    PORTB.2=0;  
m010	BCF   PORTB,2,0
			;     
			;    PORTB.3=1;
	BSF   PORTB,3,0
			;    if(PORTB.4==1)
	BTFSS PORTB,4,0
	BRA   m011
			;    {
			;      bekle(2);
	MOVLW 2
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;      PORTD=0x0B;}
	MOVLW 11
	MOVWF PORTD,0
			;    if(PORTB.5==1)
m011	BTFSS PORTB,5,0
	BRA   m012
			;    {
			;      bekle(2);
	MOVLW 2
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;      PORTD=0x0A;}
	MOVLW 10
	MOVWF PORTD,0
			;    if(PORTB.6==1)
m012	BTFSS PORTB,6,0
	BRA   m013
			;    {
			;      bekle(2);
	MOVLW 2
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;      PORTD=0x0C;}
	MOVLW 12
	MOVWF PORTD,0
			;    PORTB.3=0;   
m013	BCF   PORTB,3,0
			;     
			;} 
	BRA   m001
			;    
			;   goto anadongu;
			;//-----------------------------------------------   
			;}
			;
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;
			;void ayarlar()   // Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
			;{   
ayarlar
			;   GIE=0;         // Bütün kesmeleri kapat
	BCF   0xFF2,GIE,0
			;   TRISB=0xF0;      // B portu giriþ yapýldý
	MOVLW 240
	MOVWF TRISB,0
			;   TRISD=0;      // D portu çýkýþ yapýldý
	CLRF  TRISD,0
			;     
			;   PORTD=0;      // D portu çýkýþlarý sýfýrlandý
	CLRF  PORTD,0
			;
			;   
			;   
			;}
	RETURN
			;
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;
			;void bekle(unsigned long t)   //t milisaniye gecikme saðlar
			;{
bekle
			;   unsigned x;
			;   
			;   for(;t>0;t--)
m014	MOVF  t,W,0
	IORWF t+1,W,0
	BZ    m017
			;      for(x=140;x>0;x--)
	MOVLW 140
	MOVWF x,0
m015	MOVF  x,1,0
	BZ    m016
			;         nop();
	NOP  
	DECF  x,1,0
	BRA   m015
m016	DECF  t,1,0
	MOVLW 0
	SUBWFB t+1,1,0
	BRA   m014
			;}
m017	RETURN

	END


; *** KEY INFO ***

; 0x0000E0    6 word(s)  0 % : ayarlar
; 0x0000EC   15 word(s)  0 % : bekle
; 0x000004  110 word(s)  0 % : main

; RAM usage: 3 bytes (3 local), 1533 bytes free
; Maximum call level: 1
; Total of 133 code words (0 %)
