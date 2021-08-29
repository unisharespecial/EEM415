
; CC8E Version 1.3D, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  23. Jan 2011  19:33  *************

	processor  PIC18F452
	radix  DEC

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
gelen       EQU   0x00
data1       EQU   0x7F
temp        EQU   0x7F
t           EQU   0x01
x           EQU   0x03

	GOTO main

  ; FILE alici.c
			;void init();	//Baslangýc ayarlarý fonksiyonu
			;void spi_init();//SPI Ayarlarý fonksiyonu
			;uns8 spi_gonder_al(uns8);	//SPI veri gonderme fonksiyonu 
			;void bekle(unsigned long);	//Bekleme fonksiyonu
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
			;	if(gelen == 0x01) 
	DECFSZ gelen,W,0
	BRA   m003
			;		PORTD=0x01;
	MOVLW 1
	MOVWF PORTD,0
			;	if(gelen == 0x02) 
m003	MOVLW 2
	CPFSEQ gelen,0
	BRA   m004
			;		PORTD=0x02;
	MOVLW 2
	MOVWF PORTD,0
			;	if(gelen == 0x04) 
m004	MOVLW 4
	CPFSEQ gelen,0
	BRA   m005
			;		PORTD=0x03;
	MOVLW 3
	MOVWF PORTD,0
			;	if(gelen == 0x08) 
m005	MOVLW 8
	CPFSEQ gelen,0
	BRA   m006
			;		PORTD=0x04;
	MOVLW 4
	MOVWF PORTD,0
			;	if(gelen == 0x10) 
m006	MOVLW 16
	CPFSEQ gelen,0
	BRA   m007
			;		PORTD=0x05;
	MOVLW 5
	MOVWF PORTD,0
			;	if(gelen == 0x20) 
m007	MOVLW 32
	CPFSEQ gelen,0
	BRA   m008
			;		PORTD=0x06;
	MOVLW 6
	MOVWF PORTD,0
			;	if(gelen == 0x40) 
m008	MOVLW 64
	CPFSEQ gelen,0
	BRA   m009
			;		PORTD=0x07;
	MOVLW 7
	MOVWF PORTD,0
			;	if(gelen == 0x80) 
m009	MOVLW 128
	CPFSEQ gelen,0
	BRA   m010
			;		PORTD=0x08;
	MOVLW 8
	MOVWF PORTD,0
			;	bekle(100);
m010	MOVLW 100
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
	BRA   spi_init
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
m011	BTFSS 0xF9E,SSPIF,0
	BRA   m011
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
m012	MOVF  t,W,0
	IORWF t+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m015
			;		for(x=140;x>0;x--)
	MOVLW 140
	MOVWF x,0
m013	MOVF  x,1,0
	BTFSC 0xFD8,Zero_,0
	BRA   m014
			;			nop();
	NOP  
	DECF  x,1,0
	BRA   m013
m014	DECF  t,1,0
	MOVLW 0
	SUBWFB t+1,1,0
	BRA   m012
			;}
m015	RETURN

	END


; *** KEY INFO ***

; 0x00006E    8 word(s)  0 % : init
; 0x00007E   10 word(s)  0 % : spi_init
; 0x000092   14 word(s)  0 % : spi_gonder_al
; 0x0000AE   17 word(s)  0 % : bekle
; 0x000004   53 word(s)  0 % : main

; RAM usage: 4 bytes (4 local), 1532 bytes free
; Maximum call level: 1
; Total of 104 code words (0 %)
