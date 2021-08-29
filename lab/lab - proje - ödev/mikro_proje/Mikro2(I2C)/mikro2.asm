
; CC8E Version 1.2A, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  22. Jan 2010  13:37  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1
	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

SSPBUF      EQU   0xFC9
SSPADD      EQU   0xFC8
SSPCON1     EQU   0xFC6
TRISC       EQU   0xF94
TRISB       EQU   0xF93
PORTB       EQU   0xF81
SSPEN       EQU   5
SEN         EQU   0
RSEN        EQU   1
PEN         EQU   2
RCEN        EQU   3
SSPIF       EQU   3
data        EQU   0x00

	GOTO main

  ; FILE mikro2.c
			;#include "INT18XXX.H"
			;
			;
			;#pragma config[1] = 0xF1 // Osilat�r: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT a��k, BOR kapal�
			;#pragma config[3] = 0xFE // Watchdog Timer kapal�
			;
			;void ayarlar()
			;{
ayarlar
			;	TRISC.3=1; //I2C SCL Ayar�
	BSF   TRISC,3,0
			;	TRISC.4=1; //I2C SDA Ayar�
	BSF   TRISC,4,0
			;	TRISB=0x00;
	CLRF  TRISB,0
			;	PORTB=0x00;
	CLRF  PORTB,0
			;	SSPCON1.3=1; //I2C Master Modu se�
	BSF   SSPCON1,3,0
			;	SSPCON1.2=0;
	BCF   SSPCON1,2,0
			;	SSPCON1.1=0;
	BCF   SSPCON1,1,0
			;	SSPCON1.0=0;
	BCF   SSPCON1,0,0
			;	SSPADD=0x0A; //100kHZ H�z Modu se�
	MOVLW 10
	MOVWF SSPADD,0
			;	SSPEN=1; //MSSP'yi Etkinle�tir
	BSF   0xFC6,SSPEN,0
			;}
	RETURN
			;uns8 data;
			;void main()
			;{
main
			;	ayarlar(); //Ayarlar� yap
	RCALL ayarlar
			;	while(1) //Her zaman
			;	{
			;		SEN=1; //I2C Start Biti Yolla
m001	BSF   0xFC5,SEN,0
			;		while(SEN); //Ba�latma i�lemi ge�erli olana kadar bekle
m002	BTFSC 0xFC5,SEN,0
	BRA   m002
			;		SSPIF=0; //SSPIF Bayra��n� S�f�rla
	BCF   0xF9E,SSPIF,0
			;		SSPBUF=0b.1001.1010; //Adres yolla ve yazma bitini aktifle�tir
	MOVLW 154
	MOVWF SSPBUF,0
			;		while(!SSPIF); //Adres G�nderilene Kadar Bekle	
m003	BTFSS 0xF9E,SSPIF,0
	BRA   m003
			;		SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;		SSPBUF=0b.0000.0000; //Komut biti yolla (KOmut=00000000 olurse derece okunur)
	CLRF  SSPBUF,0
			;		while(!SSPIF); //Komut biti yollanana kadar bekle
m004	BTFSS 0xF9E,SSPIF,0
	BRA   m004
			;		SSPIF=0; //SSPIF bayra�� s�f�rla
	BCF   0xF9E,SSPIF,0
			;		RSEN=1; //Tekrar ba�lat
	BSF   0xFC5,RSEN,0
			;		while(RSEN); //Tekrar ba�latma aktifle�ene kadar bekle
m005	BTFSC 0xFC5,RSEN,0
	BRA   m005
			;		SSPIF=0; //SSPIF bayra��n� sil
	BCF   0xF9E,SSPIF,0
			;		SSPBUF=0b.1001.1011; //Adresi g�nder ve okuma bitini aktifle�tir
	MOVLW 155
	MOVWF SSPBUF,0
			;		while(!SSPIF); //Adres g�nderilene kadar bekle
m006	BTFSS 0xF9E,SSPIF,0
	BRA   m006
			;		SSPIF=0; //SSPIF bayra��n� s�f�rla
	BCF   0xF9E,SSPIF,0
			;		RCEN=1; //Master al�m bitini aktfile�tir (derece okumak i�in)
	BSF   0xFC5,RCEN,0
			;		while(RCEN); //Aktifle�ene kadar bekle
m007	BTFSC 0xFC5,RCEN,0
	BRA   m007
			;		data=SSPBUF; //8'bitlik dereceyi al
	MOVFF SSPBUF,data
			;		PEN=1; //G�nderim i�lemini durdur
	BSF   0xFC5,PEN,0
			;		while(PEN); //Durana kadar bekle
m008	BTFSC 0xFC5,PEN,0
	BRA   m008
			;		SSPIF=0; //SSPIF bayra��n� sil
	BCF   0xF9E,SSPIF,0
			;		PORTB=data; //Okunan veriyi PORT'e ��k			
	MOVFF data,PORTB
			;	}
	BRA   m001

	END


; *** KEY INFO ***

; 0x000004   12 word(s)  0 % : ayarlar
; 0x00001C   35 word(s)  0 % : main

; RAM usage: 1 bytes (0 local), 1535 bytes free
; Maximum call level: 1
; Total of 49 code words (0 %)
