
; CC8E Version 1.3D, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  23. Dec 2010  14:32  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1
	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

TBLPTR      EQU   0xFF6
TABLAT      EQU   0xFF5
Zero_       EQU   2
ADRESH      EQU   0xFC4
ADCON0      EQU   0xFC2
ADCON1      EQU   0xFC1
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
ci          EQU   0x01

	GOTO main

  ; FILE uyg.c
			;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			;//Look up Table Tabanlý Sensor Doðrusallaþtýrýlmasý
			;#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;void ayarlar();
			;void bekle(unsigned long t); // t milisaniye gecikme saðlayan fonksiyon tanýmý
			;void main()
			;{
main
			;unsigned static const int lookuptable[11] = {1,2,3,4,5,6,7,8,9,10,11};
			;unsigned int deger;
			;//y= 2 * X + 1 sensor dogrulastirma islemi
			;ayarlar();
	RCALL ayarlar
			;PORTC=0;
	CLRF  PORTC,0
			;anadongu:
			;bekle(1);
m001	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;GO=1;
	BSF   0xFC2,GO,0
			;while(GO);
m002	BTFSC 0xFC2,GO,0
	BRA   m002
			;deger=ADRESH; //okunan analog degerin digital karsiligi, deger degiskenine atýlýyor
	MOVFF ADRESH,deger
			;//PORTC=deger;
			;if(deger == 0) //0V dogrulastirmasi
	MOVF  deger,1,0
	BTFSS 0xFD8,Zero_,0
	BRA   m003
			;PORTC=lookuptable[0];
	MOVLW 0
	RCALL _const1
	MOVWF PORTC,0
			;else if(deger == 25) //0.5V dogrulastirmasi
	BRA   m001
m003	MOVLW 25
	CPFSEQ deger,0
	BRA   m004
			;PORTC=lookuptable[1];
	MOVLW 1
	RCALL _const1
	MOVWF PORTC,0
			;else if(deger == 51)//1V dogrulastirmasi
	BRA   m001
m004	MOVLW 51
	CPFSEQ deger,0
	BRA   m005
			;PORTC=lookuptable[2];
	MOVLW 2
	RCALL _const1
	MOVWF PORTC,0
			;else if(deger == 76)//1.5V dogrulastirmasi
	BRA   m001
m005	MOVLW 76
	CPFSEQ deger,0
	BRA   m006
			;PORTC=lookuptable[3];
	MOVLW 3
	RCALL _const1
	MOVWF PORTC,0
			;else if(deger == 102)//2V dogrulastirmasi
	BRA   m001
m006	MOVLW 102
	CPFSEQ deger,0
	BRA   m007
			;PORTC=lookuptable[4];
	MOVLW 4
	RCALL _const1
	MOVWF PORTC,0
			;else if(deger == 127)//2.5V dogrulastirmasi
	BRA   m001
m007	MOVLW 127
	CPFSEQ deger,0
	BRA   m008
			;PORTC=lookuptable[5];
	MOVLW 5
	RCALL _const1
	MOVWF PORTC,0
			;else if(deger == 153)//3V dogrulastirmasi
	BRA   m001
m008	MOVLW 153
	CPFSEQ deger,0
	BRA   m009
			;PORTC=lookuptable[6];
	MOVLW 6
	RCALL _const1
	MOVWF PORTC,0
			;else if(deger == 179)//3.5V dogrulastirmasi
	BRA   m001
m009	MOVLW 179
	CPFSEQ deger,0
	BRA   m010
			;PORTC=lookuptable[7];
	MOVLW 7
	RCALL _const1
	MOVWF PORTC,0
			;else if(deger == 204)//4V dogrulastirmasi
	BRA   m001
m010	MOVLW 204
	CPFSEQ deger,0
	BRA   m011
			;PORTC=lookuptable[8];
	MOVLW 8
	RCALL _const1
	MOVWF PORTC,0
			;else if(deger == 230)//4.5V dogrulastirmasi
	BRA   m001
m011	MOVLW 230
	CPFSEQ deger,0
	BRA   m012
			;PORTC=lookuptable[9];
	MOVLW 9
	RCALL _const1
	MOVWF PORTC,0
			;else if(deger == 255)//5V dogrulastirmasi
	BRA   m001
m012	INCFSZ deger,W,0
	BRA   m001
			;PORTC=lookuptable[10];
	MOVLW 10
	RCALL _const1
	MOVWF PORTC,0
			;goto anadongu;
	BRA   m001
			;}
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;void bekle(unsigned long t) //t milisaniye gecikme saðlar
			;{
bekle
			;unsigned x;
			;for(;t>0;t--)
m013	MOVF  t,W,0
	IORWF t+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m016
			;for(x=140;x>0;x--)
	MOVLW 140
	MOVWF x,0
m014	MOVF  x,1,0
	BTFSC 0xFD8,Zero_,0
	BRA   m015
			;nop();
	NOP  
	DECF  x,1,0
	BRA   m014
m015	DECF  t,1,0
	MOVLW 0
	SUBWFB t+1,1,0
	BRA   m013
			;}
m016	RETURN
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;void ayarlar() // Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
			;{
ayarlar
			;GIE=0; // Bütün kesmeleri kapat
	BCF   0xFF2,GIE,0
			;TRISA=0xFF;
	SETF  TRISA,0
			;TRISB=0xFF;
	SETF  TRISB,0
			;TRISC=0x00;
	CLRF  TRISC,0
			;TRISD=0x00;
	CLRF  TRISD,0
			;TRISE=0xFF;
	SETF  TRISE,0
			;PORTC=0x00;
	CLRF  PORTC,0
			;PORTD=0x00;
	CLRF  PORTD,0
			;ADCON0=0b.0100.0001;;
	MOVLW 65
	MOVWF ADCON0,0
			;ADCON1=0b.0000.0000;;
	CLRF  ADCON1,0
			;}
	RETURN
_const1
	MOVWF ci,0
	MOVF  ci,W,0
	ADDLW 2
	MOVWF TBLPTR,0
	MOVLW 1
	CLRF  TBLPTR+1,0
	ADDWFC TBLPTR+1,1,0
	CLRF  TBLPTR+2,0
	TBLRD *
	MOVF  TABLAT,W,0
	RETURN
	DW    0x201
	DW    0x403
	DW    0x605
	DW    0x807
	DW    0xA09
	DW    0xB

	END


; *** KEY INFO ***

; 0x0000D4   12 word(s)  0 % : ayarlar
; 0x0000B2   17 word(s)  0 % : bekle
; 0x000004   87 word(s)  0 % : main
; 0x0000EC   17 word(s)  0 % : _const1

; RAM usage: 4 bytes (4 local), 1532 bytes free
; Maximum call level: 1
; Total of 135 code words (0 %)
