
; CC8E Version 1.3B, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  11. Jan 2010  23:05  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1
	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

BSR         EQU   0xFE0
STATUS      EQU   0xFD8
Zero_       EQU   2
TRISD       EQU   0xF95
TRISC       EQU   0xF94
PORTD       EQU   0xF83
PORTC       EQU   0xF82
INT0IF      EQU   1
INT0IE      EQU   4
GIE         EQU   7
INTEDG0     EQU   6
x           EQU   0x03
svrSTATUS   EQU   0x00
svrBSR      EQU   0x01
svrWREG     EQU   0x02

	GOTO main

  ; FILE FarukCC8.c
			;#include "INT18XXX.H"
			;#pragma origin 0x8
	ORG 0x0008
			;#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;int8 x;
			;interrupt int_server(void)  // KESME SUNUCU FONKSÝYONU
			;{   
int_server
			;   int_save_registers   //W, STATUS, ve BSR yazmaçlarýnýn kesme gelmeden önceki deðerlerini kaydeder
	MOVFF STATUS,svrSTATUS
	MOVFF BSR,svrBSR
	MOVWF svrWREG,0
			;      INT0IF = 0;         // INT0 kesme bayraðýný sýfýrla(yeni kesmeler gelebilir)
	BCF   0xFF2,INT0IF,0
			;        if(x==-1)
	INCFSZ x,W,0
	BRA   m001
			;			x=7;
	MOVLW 7
	MOVWF x,0
			;		if(x==8)
m001	MOVLW 8
	CPFSEQ x,0
	BRA   m002
			;			x=0;
	CLRF  x,0
			;		if(x==0)
m002	MOVF  x,1,0
	BTFSS 0xFD8,Zero_,0
	BRA   m003
			;		    PORTC=1;
	MOVLW 1
	MOVWF PORTC,0
			;		if(x==1)
m003	DECFSZ x,W,0
	BRA   m004
			;			PORTC=2;
	MOVLW 2
	MOVWF PORTC,0
			;		if(x==2)
m004	MOVLW 2
	CPFSEQ x,0
	BRA   m005
			;			PORTC=4;
	MOVLW 4
	MOVWF PORTC,0
			;		if(x==3)
m005	MOVLW 3
	CPFSEQ x,0
	BRA   m006
			;			PORTC=8;
	MOVLW 8
	MOVWF PORTC,0
			;		if(x==4)
m006	MOVLW 4
	CPFSEQ x,0
	BRA   m007
			;			PORTC=16;
	MOVLW 16
	MOVWF PORTC,0
			;		if(x==5)
m007	MOVLW 5
	CPFSEQ x,0
	BRA   m008
			;			PORTC=32;
	MOVLW 32
	MOVWF PORTC,0
			;		if(x==6)
m008	MOVLW 6
	CPFSEQ x,0
	BRA   m009
			;			PORTC=64;
	MOVLW 64
	MOVWF PORTC,0
			;		if(x==7)
m009	MOVLW 7
	CPFSEQ x,0
	BRA   m010
			;			PORTC=128;
	MOVLW 128
	MOVWF PORTC,0
			;	if(PORTD==1)
m010	DCFSNZ PORTD,W,0
			;	x++;	
	INCF  x,1,0
			;	if(PORTD==2)
	MOVLW 2
	CPFSEQ PORTD,0
	BRA   m011
			;	x--;
	DECF  x,1,0
			;	
			;    int_restore_registers //CC8E Macro to restore W, STATUS, and BSR registers
m011	MOVF  svrWREG,W,0
	MOVFF svrBSR,BSR
	MOVFF svrSTATUS,STATUS
			;   
			;}
	RETFIE
			;void main()
			;{
main
			; x=0;
	CLRF  x,0
			; TRISC=0;
	CLRF  TRISC,0
			; PORTC=0;
	CLRF  PORTC,0
			; TRISD=1;
	MOVLW 1
	MOVWF TRISD,0
			; PORTD=0;
	CLRF  PORTD,0
			; 
			; INT0IE=1;         // INT0 kesmesi açýk
	BSF   0xFF2,INT0IE,0
			; INTEDG0=1;        // INT0 kesmesi yükselen kenarda aktif olacak
	BSF   0xFF1,INTEDG0,0
			; GIE=1;            // Bütün kesmeler kullanýlabilir
	BSF   0xFF2,GIE,0
			; sonsuz:
			;goto sonsuz;
m012	BRA   m012

	END


; *** KEY INFO ***

; 0x000008   65 word(s)  0 % : int_server
; 0x00008A   10 word(s)  0 % : main

; RAM usage: 4 bytes (3 local), 1532 bytes free
; Maximum call level: 0 (+1 for interrupt)
; Total of 77 code words (0 %)
