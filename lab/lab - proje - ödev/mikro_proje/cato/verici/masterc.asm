
; CC8E Version 1.3D, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  24. Jan 2011  10:36  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1
	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

INTCON      EQU   0xFF2
Zero_       EQU   2
SSPADD      EQU   0xFC8
SSPSTAT     EQU   0xFC7
SSPCON1     EQU   0xFC6
ADCON0      EQU   0xFC2
ADCON1      EQU   0xFC1
TRISD       EQU   0xF95
TRISC       EQU   0xF94
PORTD       EQU   0xF83
PORTC       EQU   0xF82
GIE         EQU   7
BF          EQU   0
CKE         EQU   6
SMP         EQU   7
CKP         EQU   4
SSPEN       EQU   5
SEN         EQU   0
BRGH        EQU   2
SYNC        EQU   4
SSPIF       EQU   3
SSPIE       EQU   3
TUS         EQU   0x00
t           EQU   0x7F
x           EQU   0x7F

	GOTO main

  ; FILE masterc.c
			;#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;
			;void ayarlar();
			;void I2Cayar();
			;void bekle(unsigned long t);
			;char keypad_oku();   // t milisaniye gecikme saðlayan fonksiyon tanýmý
			;char TUS;
			;
			;char keypad_oku()	// tarama keypad'ýn okunduðu kýsým
			;{	
keypad_oku
			;	PORTC.0=1;
	BSF   PORTC,0,0
			;	if(PORTC.4==1)
	BTFSS PORTC,4,0
	BRA   m001
			;	{bekle(50);TUS=0X01;}
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
	MOVLW 1
	MOVWF TUS,0
			;	if(PORTC.5==1)
m001	BTFSS PORTC,5,0
	BRA   m002
			;	{bekle(50);TUS=0X02;}
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
	MOVLW 2
	MOVWF TUS,0
			;	if(PORTC.6==1)
m002	BTFSS PORTC,6,0
	BRA   m003
			;	{bekle(50);TUS=0X03;}
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
	MOVLW 3
	MOVWF TUS,0
			;	if(PORTC.7==1)
m003	BTFSS PORTC,7,0
	BRA   m004
			;	{bekle(50);TUS=0X0A;}
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
	MOVLW 10
	MOVWF TUS,0
			;  	PORTC.0=0;
m004	BCF   PORTC,0,0
			;  
			;	PORTC.1=1;
	BSF   PORTC,1,0
			;	if(PORTC.4==1)
	BTFSS PORTC,4,0
	BRA   m005
			;	{bekle(50);TUS=0X04;}
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
	MOVLW 4
	MOVWF TUS,0
			;	if(PORTC.5==1)
m005	BTFSS PORTC,5,0
	BRA   m006
			;	{bekle(50);TUS=0X05;}
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
	MOVLW 5
	MOVWF TUS,0
			;	if(PORTC.6==1)
m006	BTFSS PORTC,6,0
	BRA   m007
			;	{bekle(50);TUS=0X06;}
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
	MOVLW 6
	MOVWF TUS,0
			;	if(PORTC.7==1)
m007	BTFSS PORTC,7,0
	BRA   m008
			;	{bekle(50);TUS=0X0B;}
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
	MOVLW 11
	MOVWF TUS,0
			;	PORTC.1=0;
m008	BCF   PORTC,1,0
			;
			;	PORTC.2=1;
	BSF   PORTC,2,0
			;	if(PORTC.4==1)
	BTFSS PORTC,4,0
	BRA   m009
			;	{bekle(50);TUS=0X07;}
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
	MOVLW 7
	MOVWF TUS,0
			;	if(PORTC.5==1)
m009	BTFSS PORTC,5,0
	BRA   m010
			;	{bekle(50);TUS=0X08;}
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
	MOVLW 8
	MOVWF TUS,0
			;	if(PORTC.6==1)
m010	BTFSS PORTC,6,0
	BRA   m011
			;	{bekle(50);TUS=0X09;}
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
	MOVLW 9
	MOVWF TUS,0
			;	if(PORTC.7==1)
m011	BTFSS PORTC,7,0
	BRA   m012
			;	{bekle(50);TUS=0X0C;}
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
	MOVLW 12
	MOVWF TUS,0
			;	PORTC.2=0;
m012	BCF   PORTC,2,0
			;
			;	PORTC.3=1;
	BSF   PORTC,3,0
			;	if(PORTC.4==1)
	BTFSS PORTC,4,0
	BRA   m013
			;	{bekle(50);TUS=0X0E;}
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
	MOVLW 14
	MOVWF TUS,0
			;	if(PORTC.5==1)
m013	BTFSS PORTC,5,0
	BRA   m014
			;	{bekle(50);TUS=0X00;}
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
	CLRF  TUS,0
			;	if(PORTC.6==1)
m014	BTFSS PORTC,6,0
	BRA   m015
			;	{bekle(50);TUS=0X0F;}
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
	MOVLW 15
	MOVWF TUS,0
			;	if(PORTC.7==1)
m015	BTFSS PORTC,7,0
	BRA   m016
			;	{bekle(50);TUS=0X0D;}
	MOVLW 50
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
	MOVLW 13
	MOVWF TUS,0
			;	PORTC.3=0;
m016	BCF   PORTC,3,0
			;	
			;	return TUS;	
	MOVF  TUS,W,0
	RETURN
			;	
			;}
			;
			;void main()
			;{  
main
			;   
			;   
			;   ayarlar();
	RCALL ayarlar
			;}
	SLEEP
	RESET
			;
			;
			;  
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;void ayarlar()   // Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
			;{   
ayarlar
			;   GIE=0;  // Bütün kesmeleri kapat
	BCF   0xFF2,GIE,0
			;   I2Cayar(); 
	RCALL I2Cayar
			;   TRISC.3=1; //IC SCL Portunu Ayarla
	BSF   TRISC,3,0
			;   TRISC.4=1; //I2C SDA Porunu Ayarla
	BSF   TRISC,4,0
			;   SSPADD=0x02;  //Cihazýn Adresini Belirle
	MOVLW 2
	MOVWF SSPADD,0
			;   SSPCON1=0x36; //I2C Slave Modunu Aç
	MOVLW 54
	MOVWF SSPCON1,0
			;   SSPSTAT=0x00;
	CLRF  SSPSTAT,0
			;   SEN=1;  //Clock esnetmeyi etkinleþtirir
	BSF   0xFC5,SEN,0
			;   SSPIF=0; //SSPIF Bayraðýný Temizle
	BCF   0xF9E,SSPIF,0
			;   SSPIE=1; //Senkron iletiþim kesmesini etkinleþtirir
	BSF   0xF9D,SSPIE,0
			;   INTCON=0xC0; //Genel kesmeleri ve çevre kesmelerini etkinleþtirir
	MOVLW 192
	MOVWF INTCON,0
			;   TRISD=0xF0; //D Portu giriþ yapýldý
	MOVLW 240
	MOVWF TRISD,0
			;   TRISC=0;    //C portu çýkýþ yapýldý
	CLRF  TRISC,0
			;   PORTD=0x00;  //D portu çýkýþlarý sýfýrlandý
	CLRF  PORTD,0
			;   PORTC=0x00;  //C portu çýkýþlarý sýfýrlandý   
	CLRF  PORTC,0
			;   return;
	RETURN
			;   
			;}
			;//////////////////////////////////////////////////////////////////////////////////
			;
			;void I2Cayar()   // Seri Portu veri göndermeye hazýr hale getirir
			;{
I2Cayar
			;   //SPBRG=25;   // Baud Rate=9.6k
			;   BRGH=1;      // Yüksek Hýz
	BSF   0xFAC,BRGH,0
			;   SYNC=1;      // senkron mod
	BSF   0xFAC,SYNC,0
			;   SMP=0;
	BCF   0xFC7,SMP,0
			;   CKE=0;
	BCF   0xFC7,CKE,0
			;   BF=0;
	BCF   0xFC7,BF,0
			;   //WCOL=0;
			;   //SSPOV=0;
			;   SSPEN=1;  // MSSP'yi etkinleþtir
	BSF   0xFC6,SSPEN,0
			;   CKP=1;
	BSF   0xFC6,CKP,0
			;SSPADD=0x0A; //100kHZ hýz modunu seç
	MOVLW 10
	MOVWF SSPADD,0
			;SSPCON1.3=1;  //I2C master modu aç
	BSF   SSPCON1,3,0
			;SSPCON1.2=0;
	BCF   SSPCON1,2,0
			;SSPCON1.1=0;
	BCF   SSPCON1,1,0
			;SSPCON1.0=0;
	BCF   SSPCON1,0,0
			;ADCON0.0=0; // A/D modülü kapat.
	BCF   ADCON0,0,0
			;ADCON1.3=0;
	BCF   ADCON1,3,0
			;ADCON1.2=1;
	BSF   ADCON1,2,0
			;ADCON1.1=1;
	BSF   ADCON1,1,0
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
m017	MOVF  t,W,0
	IORWF t+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m020
			;      for(x=140;x>0;x--)
	MOVLW 140
	MOVWF x,0
m018	MOVF  x,1,0
	BTFSC 0xFD8,Zero_,0
	BRA   m019
			;         nop();
	NOP  
	DECF  x,1,0
	BRA   m018
m019	DECF  t,1,0
	MOVLW 0
	SUBWFB t+1,1,0
	BRA   m017
			;}
m020	RETURN

	END


; *** KEY INFO ***

; 0x00011C   20 word(s)  0 % : ayarlar
; 0x000144   18 word(s)  0 % : I2Cayar
; 0x000168   17 word(s)  0 % : bekle
; 0x000004  137 word(s)  0 % : keypad_oku
; 0x000116    3 word(s)  0 % : main

; RAM usage: 1 bytes (0 local), 1535 bytes free
; Maximum call level: 2
; Total of 197 code words (1 %)
