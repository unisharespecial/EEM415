
; CC8E Version 1.3D, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  24. Jan 2011  10:46  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1
	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

TBLPTR      EQU   0xFF6
TABLAT      EQU   0xFF5
Zero_       EQU   2
SSPBUF      EQU   0xFC9
SSPCON1     EQU   0xFC6
TRISE       EQU   0xF96
TRISD       EQU   0xF95
TRISC       EQU   0xF94
TRISB       EQU   0xF93
TRISA       EQU   0xF92
PORTB       EQU   0xF81
GIE         EQU   7
BF          EQU   0
CKE         EQU   6
SMP         EQU   7
CKP         EQU   4
SSPEN       EQU   5
SSPOV       EQU   6
WCOL        EQU   7
BRGH        EQU   2
SYNC        EQU   4
SSPIF       EQU   3
e           EQU   0
rs          EQU   1
rw          EQU   2
disp        EQU   0xF83
gelen       EQU   0x00
kom         EQU   0x06
c           EQU   0x06
msj         EQU   0x01
adr         EQU   0x02
i           EQU   0x03
j           EQU   0x04
k           EQU   0x05
t           EQU   0x07
x           EQU   0x09
ci          EQU   0x06

	GOTO main

  ; FILE slavec.c
			;#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;
			;void ayarlar();
			;void LcdInit();
			;void LcdYaz(char);
			;void LcdKomut(unsigned kom);
			;void MesajYaz(const char*msj,unsigned adr);
			;bit e@PORTE.0, rs@PORTE.1, rw@PORTE.2;
			;unsigned disp@PORTD;
			;void bekle(unsigned long t);   // t milisaniye gecikme saðlayan fonksiyon tanýmý
			;
			;
			;void main()
			;{  
main
			;   
			;   uns8 gelen;
			;   ayarlar();
	RCALL ayarlar
			; 
			;
			;//-----------------------------------------------   
			;while(1){
			;
			; SSPBUF=0x00;
m001	CLRF  SSPBUF,0
			;while(!SSPIF);
m002	BTFSS 0xF9E,SSPIF,0
	BRA   m002
			;gelen=SSPBUF;
	MOVFF SSPBUF,gelen
			;SSPIF=0;
	BCF   0xF9E,SSPIF,0
			;PORTB=gelen; 
	MOVFF gelen,PORTB
			;bekle(1000);
	MOVLW 232
	MOVWF t,0
	MOVLW 3
	MOVWF t+1,0
	RCALL bekle
			;if(gelen== 0x1)
	DECFSZ gelen,W,0
	BRA   m003
			;{  LcdInit();
	RCALL LcdInit
			;  MesajYaz(" 1 butonu " ,0x80); 
	CLRF  msj,0
	MOVLW 128
	RCALL MesajYaz
			;}
			;if(gelen== 0x2)
m003	MOVLW 2
	CPFSEQ gelen,0
	BRA   m004
			;{  LcdInit();
	RCALL LcdInit
			;  MesajYaz(" 2 butonu " ,0x80); 
	MOVLW 11
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;}
			;if(gelen== 0x3)
m004	MOVLW 3
	CPFSEQ gelen,0
	BRA   m005
			;{  LcdInit();
	RCALL LcdInit
			;  MesajYaz(" 3 butonu " ,0x80); 
	MOVLW 22
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;}
			;
			;if(gelen== 0x4)
m005	MOVLW 4
	CPFSEQ gelen,0
	BRA   m006
			;{  LcdInit();
	RCALL LcdInit
			;  MesajYaz(" 4 butonu " ,0x80); 
	MOVLW 33
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;}
			;if(gelen== 0x5)
m006	MOVLW 5
	CPFSEQ gelen,0
	BRA   m007
			;{  LcdInit();
	RCALL LcdInit
			;  MesajYaz(" 5 butonu " ,0x80); 
	MOVLW 44
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;}
			;if(gelen== 0x6)
m007	MOVLW 6
	CPFSEQ gelen,0
	BRA   m008
			;{  LcdInit();
	RCALL LcdInit
			;  MesajYaz(" 6 butonu " ,0x80); 
	MOVLW 55
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;}
			;if(gelen== 0x0)
m008	MOVF  gelen,1,0
	BTFSS 0xFD8,Zero_,0
	BRA   m009
			;{  LcdInit();
	RCALL LcdInit
			;  MesajYaz(" 0 butonu " ,0x80); 
	MOVLW 66
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;}
			;
			;
			;
			;
			;if(gelen== 0xB)
m009	MOVLW 11
	CPFSEQ gelen,0
	BRA   m010
			;{  LcdInit();
	RCALL LcdInit
			;  MesajYaz(" B butonu " ,0x80); 
	MOVLW 77
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;}
			;if(gelen==0x7)
m010	MOVLW 7
	CPFSEQ gelen,0
	BRA   m011
			;{ LcdInit();
	RCALL LcdInit
			;   MesajYaz(" 7 butonu " ,0x80); 
	MOVLW 88
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;}
			;if(gelen==0x8)
m011	MOVLW 8
	CPFSEQ gelen,0
	BRA   m012
			;{ LcdInit();
	RCALL LcdInit
			;   MesajYaz(" 8 butonu " ,0x80); 
	MOVLW 99
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;}
			;if(gelen==0x9)
m012	MOVLW 9
	CPFSEQ gelen,0
	BRA   m013
			;{ LcdInit();
	RCALL LcdInit
			;   MesajYaz(" 9 butonu " ,0x80); 
	MOVLW 110
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;}
			;if(gelen==0xA)
m013	MOVLW 10
	CPFSEQ gelen,0
	BRA   m014
			;{ LcdInit();
	RCALL LcdInit
			;   MesajYaz(" A butonu " ,0x80); 
	MOVLW 121
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;}
			;if(gelen==0xC)
m014	MOVLW 12
	CPFSEQ gelen,0
	BRA   m015
			;{ LcdInit();
	RCALL LcdInit
			;   MesajYaz(" C butonu " ,0x80);
	MOVLW 132
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;}
			;if(gelen==0xD)
m015	MOVLW 13
	CPFSEQ gelen,0
	BRA   m016
			;{ LcdInit();
	RCALL LcdInit
			;   MesajYaz(" D butonu " ,0x80);
	MOVLW 143
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;}
			;if(gelen==0xE)
m016	MOVLW 14
	CPFSEQ gelen,0
	BRA   m017
			;{ LcdInit();
	RCALL LcdInit
			;   MesajYaz(" E butonu " ,0x80); 
	MOVLW 154
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;}
			;if(gelen==0xF)
m017	MOVLW 15
	CPFSEQ gelen,0
	BRA   m001
			;{ LcdInit();
	RCALL LcdInit
			;   MesajYaz(" F butonu " ,0x80); 
	MOVLW 165
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;} 
			; 
			;}
	BRA   m001
			;
			;//-----------------------------------------------   
			;}
			;
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;void ayarlar()   // Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
			;{   
ayarlar
			;   GIE=0;         // Bütün kesmeleri kapat
	BCF   0xFF2,GIE,0
			;   TRISD=0x00;
	CLRF  TRISD,0
			;   TRISA=0xFF;
	SETF  TRISA,0
			;   TRISE=0x00; 
	CLRF  TRISE,0
			;   TRISC=0x18; 
	MOVLW 24
	MOVWF TRISC,0
			;   TRISB=0x00;
	CLRF  TRISB,0
			;   PORTB=0x00;  
	CLRF  PORTB,0
			;   //SPBRG=25;   // Baud Rate=9.6k
			;   BRGH=1;      // Yüksek Hýz
	BSF   0xFAC,BRGH,0
			;  SYNC=1;      // senkron mod
	BSF   0xFAC,SYNC,0
			;  SMP=0;
	BCF   0xFC7,SMP,0
			;  CKE=0;
	BCF   0xFC7,CKE,0
			;  BF=0;
	BCF   0xFC7,BF,0
			;  WCOL=0;
	BCF   0xFC6,WCOL,0
			;  SSPOV=0;
	BCF   0xFC6,SSPOV,0
			;  SSPEN=0;
	BCF   0xFC6,SSPEN,0
			;  SSPEN=1;
	BSF   0xFC6,SSPEN,0
			;  CKP=1;
	BSF   0xFC6,CKP,0
			;  SSPCON1.3=0;
	BCF   SSPCON1,3,0
			;  SSPCON1.2=1;
	BSF   SSPCON1,2,0
			;  SSPCON1.1=0;
	BCF   SSPCON1,1,0
			;  SSPCON1.0=1;
	BSF   SSPCON1,0,0
			;  
			;} 
	RETURN
			; void LcdKomut(unsigned kom)
			;{
LcdKomut
	MOVWF kom,0
			;	//while(IsLcdBusy());
			;	bekle(20);
	MOVLW 20
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	disp=kom;
	MOVFF kom,disp
			;	rs=0;
	BCF   0xF84,rs,0
			;	e=0;
	BCF   0xF84,e,0
			;	e=1;
	BSF   0xF84,e,0
			;}
	RETURN
			;void LcdYaz(char c)
			;{
LcdYaz
	MOVWF c,0
			;	//while(IsLcdBusy());
			;	bekle(20);
	MOVLW 20
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	disp=c;
	MOVFF c,disp
			;	rs=1;
	BSF   0xF84,rs,0
			;	e=0;
	BCF   0xF84,e,0
			;	e=1;
	BSF   0xF84,e,0
			;	bekle(1);	
	MOVLW 1
	MOVWF t,0
	CLRF  t+1,0
	BRA   bekle
			;}
			;void LcdInit()
			;{
LcdInit
			;	rw=0;
	BCF   0xF84,rw,0
			;	e=1;
	BSF   0xF84,e,0
			;	rs=1;
	BSF   0xF84,rs,0
			;	LcdKomut(0x38);
	MOVLW 56
	RCALL LcdKomut
			;	LcdKomut(0x01);	//Clear display
	MOVLW 1
	RCALL LcdKomut
			;	LcdKomut(0x0D); //Display,Cursor,Blink on
	MOVLW 13
	RCALL LcdKomut
			;	LcdKomut(0x06); //Increment ddram adres, do not shift disp.
	MOVLW 6
	BRA   LcdKomut
			;}
			;void MesajYaz(const char *msj,unsigned adr)
			;{
MesajYaz
	MOVWF adr,0
			;	unsigned i,j,k;
			;	i=0;
	CLRF  i,0
			;	while(msj[i]!=0)	i++;
m018	MOVF  i,W,0
	ADDWF msj,W,0
	RCALL _const1
	XORLW 0
	BTFSC 0xFD8,Zero_,0
	BRA   m019
	INCF  i,1,0
	BRA   m018
			;	LcdKomut(adr);
m019	MOVF  adr,W,0
	RCALL LcdKomut
			;	for(j=0;j<i;j++){
	CLRF  j,0
m020	MOVF  i,W,0
	CPFSLT j,0
	BRA   m023
			;		LcdYaz(msj[j]);
	MOVF  j,W,0
	ADDWF msj,W,0
	RCALL _const1
	RCALL LcdYaz
			;		for(k=0;k<30;k++)nop();
	CLRF  k,0
m021	MOVLW 30
	CPFSLT k,0
	BRA   m022
	NOP  
	INCF  k,1,0
	BRA   m021
			;	}
m022	INCF  j,1,0
	BRA   m020
			;}
m023	RETURN
			;
			;
			;
			;   
			;
			;//////////////////////////////////////////////////////////////////////////////////
			;
			; 
			;     
			;
			;
			;
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;
			;void bekle(unsigned long t)   //t milisaniye gecikme saðlar
			;{
bekle
			;   unsigned x;
			;   
			;   for(;t>0;t--)
m024	MOVF  t,W,0
	IORWF t+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m027
			;      for(x=140;x>0;x--)
	MOVLW 140
	MOVWF x,0
m025	MOVF  x,1,0
	BTFSC 0xFD8,Zero_,0
	BRA   m026
			;         nop();
	NOP  
	DECF  x,1,0
	BRA   m025
m026	DECF  t,1,0
	MOVLW 0
	SUBWFB t+1,1,0
	BRA   m024
			;}
m027	RETURN
_const1
	MOVWF ci,0
	MOVF  ci,W,0
	ADDLW 8
	MOVWF TBLPTR,0
	MOVLW 2
	CLRF  TBLPTR+1,0
	ADDWFC TBLPTR+1,1,0
	CLRF  TBLPTR+2,0
	TBLRD *
	MOVF  TABLAT,W,0
	RETURN
	DW    0x3120
	DW    0x6220
	DW    0x7475
	DW    0x6E6F
	DW    0x2075
	DW    0x2000
	DW    0x2032
	DW    0x7562
	DW    0x6F74
	DW    0x756E
	DW    0x20
	DW    0x3320
	DW    0x6220
	DW    0x7475
	DW    0x6E6F
	DW    0x2075
	DW    0x2000
	DW    0x2034
	DW    0x7562
	DW    0x6F74
	DW    0x756E
	DW    0x20
	DW    0x3520
	DW    0x6220
	DW    0x7475
	DW    0x6E6F
	DW    0x2075
	DW    0x2000
	DW    0x2036
	DW    0x7562
	DW    0x6F74
	DW    0x756E
	DW    0x20
	DW    0x3020
	DW    0x6220
	DW    0x7475
	DW    0x6E6F
	DW    0x2075
	DW    0x2000
	DW    0x2042
	DW    0x7562
	DW    0x6F74
	DW    0x756E
	DW    0x20
	DW    0x3720
	DW    0x6220
	DW    0x7475
	DW    0x6E6F
	DW    0x2075
	DW    0x2000
	DW    0x2038
	DW    0x7562
	DW    0x6F74
	DW    0x756E
	DW    0x20
	DW    0x3920
	DW    0x6220
	DW    0x7475
	DW    0x6E6F
	DW    0x2075
	DW    0x2000
	DW    0x2041
	DW    0x7562
	DW    0x6F74
	DW    0x756E
	DW    0x20
	DW    0x4320
	DW    0x6220
	DW    0x7475
	DW    0x6E6F
	DW    0x2075
	DW    0x2000
	DW    0x2044
	DW    0x7562
	DW    0x6F74
	DW    0x756E
	DW    0x20
	DW    0x4520
	DW    0x6220
	DW    0x7475
	DW    0x6E6F
	DW    0x2075
	DW    0x2000
	DW    0x2046
	DW    0x7562
	DW    0x6F74
	DW    0x756E
	DW    0x20

	END


; *** KEY INFO ***

; 0x00011E   23 word(s)  0 % : ayarlar
; 0x00017E   11 word(s)  0 % : LcdInit
; 0x000162   14 word(s)  0 % : LcdYaz
; 0x00014C   11 word(s)  0 % : LcdKomut
; 0x000194   30 word(s)  0 % : MesajYaz
; 0x0001D0   17 word(s)  0 % : bekle
; 0x000004  141 word(s)  0 % : main
; 0x0001F2   99 word(s)  0 % : _const1

; RAM usage: 10 bytes (10 local), 1526 bytes free
; Maximum call level: 3
; Total of 348 code words (2 %)
