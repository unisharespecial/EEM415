
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
			;#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;
			;void ayarlar()
			;{
ayarlar
			;	TRISC.3=1; //I2C SCL Ayarý
	BSF   TRISC,3,0
			;	TRISC.4=1; //I2C SDA Ayarý
	BSF   TRISC,4,0
			;	TRISB=0x00;
	CLRF  TRISB,0
			;	PORTB=0x00;
	CLRF  PORTB,0
			;	SSPCON1.3=1; //I2C Master Modu seç
	BSF   SSPCON1,3,0
			;	SSPCON1.2=0;
	BCF   SSPCON1,2,0
			;	SSPCON1.1=0;
	BCF   SSPCON1,1,0
			;	SSPCON1.0=0;
	BCF   SSPCON1,0,0
			;	SSPADD=0x0A; //100kHZ Hýz Modu seç
	MOVLW 10
	MOVWF SSPADD,0
			;	SSPEN=1; //MSSP'yi Etkinleþtir
	BSF   0xFC6,SSPEN,0
			;}
	RETURN
			;uns8 data;
			;void main()
			;{
main
			;	ayarlar(); //Ayarlarý yap
	RCALL ayarlar
			;	while(1) //Her zaman
			;	{
			;		SEN=1; //I2C Start Biti Yolla
m001	BSF   0xFC5,SEN,0
			;		while(SEN); //Baþlatma iþlemi geçerli olana kadar bekle
m002	BTFSC 0xFC5,SEN,0
	BRA   m002
			;		SSPIF=0; //SSPIF Bayraðýný Sýfýrla
	BCF   0xF9E,SSPIF,0
			;		SSPBUF=0b.1001.1010; //Adres yolla ve yazma bitini aktifleþtir
	MOVLW 154
	MOVWF SSPBUF,0
			;		while(!SSPIF); //Adres Gönderilene Kadar Bekle	
m003	BTFSS 0xF9E,SSPIF,0
	BRA   m003
			;		SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;		SSPBUF=0b.0000.0000; //Komut biti yolla (KOmut=00000000 olurse derece okunur)
	CLRF  SSPBUF,0
			;		while(!SSPIF); //Komut biti yollanana kadar bekle
m004	BTFSS 0xF9E,SSPIF,0
	BRA   m004
			;		SSPIF=0; //SSPIF bayraðý sýfýrla
	BCF   0xF9E,SSPIF,0
			;		RSEN=1; //Tekrar baþlat
	BSF   0xFC5,RSEN,0
			;		while(RSEN); //Tekrar baþlatma aktifleþene kadar bekle
m005	BTFSC 0xFC5,RSEN,0
	BRA   m005
			;		SSPIF=0; //SSPIF bayraðýný sil
	BCF   0xF9E,SSPIF,0
			;		SSPBUF=0b.1001.1011; //Adresi gönder ve okuma bitini aktifleþtir
	MOVLW 155
	MOVWF SSPBUF,0
			;		while(!SSPIF); //Adres gönderilene kadar bekle
m006	BTFSS 0xF9E,SSPIF,0
	BRA   m006
			;		SSPIF=0; //SSPIF bayraðýný sýfýrla
	BCF   0xF9E,SSPIF,0
			;		RCEN=1; //Master alým bitini aktfileþtir (derece okumak için)
	BSF   0xFC5,RCEN,0
			;		while(RCEN); //Aktifleþene kadar bekle
m007	BTFSC 0xFC5,RCEN,0
	BRA   m007
			;		data=SSPBUF; //8'bitlik dereceyi al
	MOVFF SSPBUF,data
			;		PEN=1; //Gönderim iþlemini durdur
	BSF   0xFC5,PEN,0
			;		while(PEN); //Durana kadar bekle
m008	BTFSC 0xFC5,PEN,0
	BRA   m008
			;		SSPIF=0; //SSPIF bayraðýný sil
	BCF   0xF9E,SSPIF,0
			;		PORTB=data; //Okunan veriyi PORT'e çýk			
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
