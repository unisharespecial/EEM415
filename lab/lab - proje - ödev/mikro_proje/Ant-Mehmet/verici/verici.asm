
; CC8E Version 1.3D, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************  24. Jan 2011  11:34  *************

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
data1       EQU   0x00
temp        EQU   0x01
t           EQU   0x00
x           EQU   0x02

	GOTO main

  ; FILE verici.c
			;void init();	//Baslangýc ayarlarý fonksiyonu
			;void spi_init();//SPI Ayarlarý fonksiyonu
			;void spi_gonder(uns8);	//SPI veri gonderme fonksiyonu 
			;void bekle(unsigned long);	//Bekleme fonksiyonu
			;
			;void main()
			;{
main
			;	init();		//baslangýc ayarlarý yapýlýyor
	RCALL init
			;dongu:
			;	if(PORTB.0 == 1 ){ 
m001	BTFSS PORTB,0,0
	BRA   m002
			;		spi_gonder(0x01);
	MOVLW 1
	RCALL spi_gonder
			;		bekle(200);
	MOVLW 200
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	}
			;	if(PORTB.1 == 1 ){ 
m002	BTFSS PORTB,1,0
	BRA   m003
			;		spi_gonder(0x02);
	MOVLW 2
	RCALL spi_gonder
			;		bekle(200);
	MOVLW 200
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	}
			;
			;	if(PORTB.2 == 1 ){ 
m003	BTFSS PORTB,2,0
	BRA   m004
			;		spi_gonder(0x04);
	MOVLW 4
	RCALL spi_gonder
			;		bekle(200);
	MOVLW 200
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	}
			;	if(PORTB.3 == 1 ){ 
m004	BTFSS PORTB,3,0
	BRA   m001
			;		spi_gonder(0x08);
	MOVLW 8
	RCALL spi_gonder
			;		bekle(200);
	MOVLW 200
	MOVWF t,0
	CLRF  t+1,0
	RCALL bekle
			;	}
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
			;	//TRISC.5=1;
			;	TRISB=0xFF;	//  Buton = PORTB.0, giriþ yapýlýyor
	SETF  TRISB,0
			;	spi_init();	// SPI Ayarlarý yapýlýyor
	BRA   spi_init
			;}
			;void spi_init()
			;{
spi_init
			;	CKP = 0 ;	//Clock polarity 
	BCF   0xFC6,CKP,0
			;	CKE=1;		//Clock edge select
	BSF   0xFC7,CKE,0
			;	//SPI Master mode, Fosc\4
			;	SSPCON1.3=0;
	BCF   SSPCON1,3,0
			;	SSPCON1.2=0;
	BCF   SSPCON1,2,0
			;	SSPCON1.1=0;
	BCF   SSPCON1,1,0
			;	SSPCON1.0=0;
	BCF   SSPCON1,0,0
			;	//////////////////////
			;	SSPEN=1;	//Synchronous Serial Port Enable bit //5. bit
	BSF   0xFC6,SSPEN,0
			;	SSPOV=0;	// Receive overflow indicator bit
	BCF   0xFC6,SSPOV,0
			;	WCOL=0;		// Write collision detect bit
	BCF   0xFC6,WCOL,0
			;}
	RETURN
			;void spi_gonder(uns8 data1)
			;{
spi_gonder
	MOVWF data1,0
			;	uns8 temp;
			;	PORTD.0=0;	//CS = 0 
	BCF   PORTD,0,0
			;	SSPBUF = data1;		//Instruction register verisi
	MOVFF data1,SSPBUF
			;	while(!SSPIF);  //	Buffer kontrolü
m005	BTFSS 0xF9E,SSPIF,0
	BRA   m005
			;  	SSPIF = 0;
	BCF   0xF9E,SSPIF,0
			;	temp=SSPBUF;  //yedekleme iþlemi   
	MOVFF SSPBUF,temp
			;	PORTD.0=1;	//CS=1
	BSF   PORTD,0,0
			;}
	RETURN
			;void bekle(unsigned long t)	/*t milisaniye gecikme saðlar*/
			;{
bekle
			;	unsigned x;	
			;	for(;t>0;t--)
m006	MOVF  t,W,0
	IORWF t+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m009
			;		for(x=140;x>0;x--)
	MOVLW 140
	MOVWF x,0
m007	MOVF  x,1,0
	BTFSC 0xFD8,Zero_,0
	BRA   m008
			;			nop();
	NOP  
	DECF  x,1,0
	BRA   m007
m008	DECF  t,1,0
	MOVLW 0
	SUBWFB t+1,1,0
	BRA   m006
			;}
m009	RETURN

	END


; *** KEY INFO ***

; 0x000048    6 word(s)  0 % : init
; 0x000054   10 word(s)  0 % : spi_init
; 0x000068   11 word(s)  0 % : spi_gonder
; 0x00007E   17 word(s)  0 % : bekle
; 0x000004   34 word(s)  0 % : main

; RAM usage: 3 bytes (3 local), 1533 bytes free
; Maximum call level: 1
; Total of 80 code words (0 %)
