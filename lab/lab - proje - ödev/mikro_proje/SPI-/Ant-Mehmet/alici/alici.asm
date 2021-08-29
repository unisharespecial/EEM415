
; CC8E Version 1.3D, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  24. Jan 2011  10:40  *************

	processor  PIC18F452
	radix  DEC

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
PORTD       EQU   0xF83
PORTB       EQU   0xF81
CKE         EQU   6
CKP         EQU   4
SSPEN       EQU   5
SSPOV       EQU   6
WCOL        EQU   7
SSPIF       EQU   3
e           EQU   0
rs          EQU   1
rw          EQU   2
disp        EQU   0xF83
gelen       EQU   0x00
data1       EQU   0x7F
temp        EQU   0x7F
t           EQU   0x07
x           EQU   0x09
kom         EQU   0x06
c           EQU   0x06
msj         EQU   0x01
adr         EQU   0x02
i           EQU   0x03
j           EQU   0x04
k           EQU   0x05
ci          EQU   0x06

	GOTO main

  ; FILE alici.c
			;void init();	//Baslangýc ayarlarý fonksiyonu
			;void spi_init();//SPI Ayarlarý fonksiyonu
			;uns8 spi_gonder_al(uns8);	//SPI veri gonderme fonksiyonu 
			;void bekle(unsigned long);	//Bekleme fonksiyonu
			;void LcdInit();
			;void LcdYaz(char );
			;void LcdKomut(unsigned kom);
			;void MesajYaz(const char *msj,unsigned adr);
			;
			;bit e @ PORTE.0, rs @ PORTE.1, rw @ PORTE.2;
			;unsigned disp @ PORTD;
			;
			;void main()
			;{
main
			;	uns8 gelen;
			;	init();		//baslangýc ayarlarý yapýlýyor
	RCALL init
			;dongu:
			;	SSPBUF=0x00;
m001	CLRF  SSPBUF,0
			;	while(!SSPIF);  //	Buffer kontrolü
m002	BTFSS 0xF9E,SSPIF,0
	BRA   m002
			;	gelen=SSPBUF;  
	MOVFF SSPBUF,gelen
			;  	SSPIF = 0;
	BCF   0xF9E,SSPIF,0
			;	PORTB=gelen;
	MOVFF gelen,PORTB
			;	if(gelen == 0x02) 
	MOVLW 2
	CPFSEQ gelen,0
	BRA   m003
			;		MesajYaz("bir                   ",0x80);
	CLRF  msj,0
	MOVLW 128
	RCALL MesajYaz
			;	if(gelen == 0x04) 
m003	MOVLW 4
	CPFSEQ gelen,0
	BRA   m004
			;		MesajYaz("iki                   ",0x80);
	MOVLW 23
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;	if(gelen == 0x08) 
m004	MOVLW 8
	CPFSEQ gelen,0
	BRA   m005
			;		MesajYaz("uc                    ",0x80);
	MOVLW 46
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;	if(gelen == 0x10) 
m005	MOVLW 16
	CPFSEQ gelen,0
	BRA   m006
			;		MesajYaz("dort                  ",0x80);
	MOVLW 69
	MOVWF msj,0
	MOVLW 128
	RCALL MesajYaz
			;	bekle(100);
m006	MOVLW 100
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	goto dongu;
	BRA   m001
			;}
			;void init()
			;{
init
			;	TRISA=0XFF;
	SETF  TRISA,0
			;	TRISE=0x00;
	CLRF  TRISE,0
			;	TRISD=0x00;	// PORTD.0 = CS, PORTD çýkýþ yapýlýyor.
	CLRF  TRISD,0
			;	TRISC=0x00;	//	SPI pinleri çýkýþ yapýlýyor.
	CLRF  TRISC,0
			;	TRISC.3=1;
	BSF   TRISC,3,0
			;	TRISC.5=1;
	BSF   TRISC,5,0
			;	TRISB=0x00;	//  Buton = PORTB.0, giriþ yapýlýyor
	CLRF  TRISB,0
			;	spi_init();	// SPI Ayarlarý yapýlýyor
	RCALL spi_init
			;	LcdInit();
	BRA   LcdInit
			;}
			;void spi_init()
			;{
spi_init
			;	CKP = 0 ;	//Clock polarity 
	BCF   0xFC6,CKP,0
			;	CKE=0;		//Clock edge select
	BCF   0xFC7,CKE,0
			;	//SPI Slave Mode
			;	SSPCON1.3=0;
	BCF   SSPCON1,3,0
			;	SSPCON1.2=1;
	BSF   SSPCON1,2,0
			;	SSPCON1.1=0;
	BCF   SSPCON1,1,0
			;	SSPCON1.0=1;
	BSF   SSPCON1,0,0
			;	SSPEN=1;	//Synchronous Serial Port Enable bit //5. bit
	BSF   0xFC6,SSPEN,0
			;	SSPOV=0;	// Receive overflow indicator bit
	BCF   0xFC6,SSPOV,0
			;	WCOL=0;		// Write collision detect bit
	BCF   0xFC6,WCOL,0
			;}
	RETURN
			;uns8 spi_gonder_al(uns8 data1)
			;{
spi_gonder_al
	MOVWF data1,0
			;	uns8 temp;
			;	PORTD.0=0;	//CS = 0 
	BCF   PORTD,0,0
			;	SSPBUF = data1;		//Instruction register verisi
	MOVFF data1,SSPBUF
			;	while(!SSPIF);  //	Buffer kontrolü
m007	BTFSS 0xF9E,SSPIF,0
	BRA   m007
			;	temp=SSPBUF;  
	MOVFF SSPBUF,temp
			;  	SSPIF = 0;
	BCF   0xF9E,SSPIF,0
			;	PORTD.0=1;	//CS=1
	BSF   PORTD,0,0
			;	PORTB=temp;
	MOVFF temp,PORTB
			;	return temp;
	MOVF  temp,W,0
	RETURN
			;}
			;void bekle(unsigned long t)	/*t milisaniye gecikme saðlar*/
			;{
bekle
			;	unsigned x;	
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
			;void LcdKomut(unsigned kom)
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
m012	MOVF  i,W,0
	ADDWF msj,W,0
	RCALL _const1
	XORLW 0
	BTFSC 0xFD8,Zero_,0
	BRA   m013
	INCF  i,1,0
	BRA   m012
			;	LcdKomut(adr);
m013	MOVF  adr,W,0
	RCALL LcdKomut
			;	for(j=0;j<i;j++){
	CLRF  j,0
m014	MOVF  i,W,0
	CPFSLT j,0
	BRA   m017
			;		LcdYaz(msj[j]);
	MOVF  j,W,0
	ADDWF msj,W,0
	RCALL _const1
	RCALL LcdYaz
			;		for(k=0;k<30;k++)nop();
	CLRF  k,0
m015	MOVLW 30
	CPFSLT k,0
	BRA   m016
	NOP  
	INCF  k,1,0
	BRA   m015
			;	}
m016	INCF  j,1,0
	BRA   m014
			;}
m017	RETURN
_const1
	MOVWF ci,0
	MOVF  ci,W,0
	ADDLW 84
	MOVWF TBLPTR,0
	MOVLW 1
	CLRF  TBLPTR+1,0
	ADDWFC TBLPTR+1,1,0
	CLRF  TBLPTR+2,0
	TBLRD *
	MOVF  TABLAT,W,0
	RETURN
	DW    0x6962
	DW    0x2072
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x6900
	DW    0x696B
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x20
	DW    0x6375
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x6400
	DW    0x726F
	DW    0x2074
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x2020
	DW    0x20

	END


; *** KEY INFO ***

; 0x000056    9 word(s)  0 % : init
; 0x000068   10 word(s)  0 % : spi_init
; 0x00007C   14 word(s)  0 % : spi_gonder_al
; 0x000098   17 word(s)  0 % : bekle
; 0x0000EC   11 word(s)  0 % : LcdInit
; 0x0000D0   14 word(s)  0 % : LcdYaz
; 0x0000BA   11 word(s)  0 % : LcdKomut
; 0x000102   30 word(s)  0 % : MesajYaz
; 0x000004   41 word(s)  0 % : main
; 0x00013E   57 word(s)  0 % : _const1

; RAM usage: 10 bytes (10 local), 1526 bytes free
; Maximum call level: 3
; Total of 216 code words (1 %)
