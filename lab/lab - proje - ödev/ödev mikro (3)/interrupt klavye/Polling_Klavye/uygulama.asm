
; CC8E Version 1.3F, Copyright (c) B Knudsen Data
; C compiler for the PIC18 microcontrollers
; ************   2. Dec 2013  21:53  *************

	processor  PIC18F452
	radix  DEC

	__config 0x300001, 0xF1
	__config 0x300002, 0xF8
	__config 0x300003, 0xFE

INTCON      EQU   0xFF2
INTCON2     EQU   0xFF1
INTCON3     EQU   0xFF0
Zero_       EQU   2
TRISE       EQU   0xF96
TRISD       EQU   0xF95
TRISC       EQU   0xF94
TRISB       EQU   0xF93
TRISA       EQU   0xF92
PORTD       EQU   0xF83
PORTC       EQU   0xF82
PORTB       EQU   0xF81
INT0IF      EQU   1
GIE         EQU   7
t           EQU   0x00
x           EQU   0x02

	GOTO main

  ; FILE uygulama.c
			;//interrupt Tabanlý Klavyeden Basýlan Butonu Algýlama
			;
			;// Mikrodenetleyici Timer ve Clock Ayarlamalarý
			;#pragma config[1] = 0xF1 // Osilatör: XT
			;#pragma config[2] = 0xFE & 0xF9 // PWRT açýk, BOR kapalý
			;#pragma config[3] = 0xFE // Watchdog Timer kapalý
			;
			;void ayarlar(); // Port ayarlamalarýnýn yapýldýðý fonksiyonlarýn tanýmý
			;void bekle(unsigned long t);	// t milisaniye gecikme saðlayan fonksiyon tanýmý
			;void anadongu();
			;void kesme() //kesme gelince yapilacak komutlar, kesmede calisacak fonksiyon main fonksiyonunun ustunde yazilir...	
			;{
kesme
			;	INTCON=0x90; // kesmeler acilir RBO/INT0 girisi interrupt enable edilir.
	MOVLW 144
	MOVWF INTCON,0
			;anadongu();
	RCALL anadongu
			;bekle(300);
	MOVLW 44
	MOVWF t,0
	MOVLW 1
	MOVWF t+1,0
	RCALL bekle
			;	INT0IF=0;  // yeni kesmeler gelmesi icin butona bagli olan INT0 portundaki interrupt flagi kapatilir.
	BCF   0xFF2,INT0IF,0
			;	GIE=1;	//kesmeler acilir, yeni kesme gelmesine musade edilir
	BSF   0xFF2,GIE,0
			;
			;}	
	RETURN
			;
			;
			;void main()
			;{	
main
			;	ayarlar(); // Port Ayarlamalarý Programýn ilk adýmýnda yapýlýyor.
	RCALL ayarlar
			;/*if(PORTB.4==1|| PORTB.5==1||	PORTB.6==1)
			;anadongu();
			;bekle(300);*/
			;
			;//-----------------------------------------------	
			;/*anadongu:
			;	PORTB.0=1; // Port B' nin 0. biti high yapýlýyor
			;	PORTB.1=0; // Port B' nin 1. biti low yapýlýyor
			;	PORTB.2=0; // Port B' nin 2. biti low yapýlýyor
			;	if(PORTB.0==1){ // Port B' nin 0. biti high olduðu sürece, input bitlerine tek tek bakýlacak
			;	if(PORTB.5 == 1){ // Port B' nin 5. biti high olmuþsa göstergede 1 göster.
			;		PORTD=0x06;
			;		bekle(300);
			;		PORTD=0;
			;	}
			;	if(PORTB.4 == 1){ // Port B' nin 4. biti high olmuþsa göstergede 2 göster.
			;		PORTD=0x5B;
			;		bekle(300);
			;		PORTD=0;
			;	}
			;	if(PORTB.3 == 1){ // Port B' nin 3. biti high olmuþsa göstergede 3 göster.
			;		PORTD=0x4F;
			;		bekle(300);
			;		PORTD=0;
			;	}
			;	if(PORTB.6 == 1){// Port B' nin 6. biti high olmuþsa göstergede 0 göster.
			;		PORTD=0x03F;
			;		bekle(300);
			;		PORTD=0;
			;	}
			;	}
			;	PORTB.1=1; // Port B' nin 1. biti high, 0 ve 2. bitleri low yapýlýr.
			;	PORTB.0=0;
			;	PORTB.2=0;
			;	if(PORTB.1==1){ // Port B' nin 1. biti high olduðu sürece, input bitlerine tek tek bakýlacak
			;	if(PORTB.5 == 1){ // Port B' nin 5. biti high olmuþsa göstergede 4 göster.
			;		PORTD=0x66;
			;		bekle(300);
			;		PORTD=0;
			;	}
			;	if(PORTB.4 == 1){ // Port B' nin 4. biti high olmuþsa göstergede 5 göster.
			;		PORTD=0x6D;
			;		bekle(300);
			;		PORTD=0;
			;	}
			;	if(PORTB.3 == 1){ // Port B' nin 3. biti high olmuþsa göstergede 6 göster.
			;		PORTD=0x7D;
			;		bekle(300);
			;		PORTD=0;
			;	}
			;	}
			;	PORTB.2=1; // Port B' nin 2. biti high, 0 ve 1. bitleri low yapýlýr.
			;	PORTB.0=0;
			;	PORTB.1=0;
			;	if(PORTB.2==1){ // Port B' nin 2. biti high olduðu sürece, input bitlerine tek tek bakýlacak
			;	if(PORTB.5 == 1){ // Port B' nin 5. biti high olmuþsa göstergede 7 göster.
			;		PORTD=0x07;
			;		bekle(300);
			;		PORTD=0;
			;	}
			;	if(PORTB.4 == 1){ // Port B' nin 4. biti high olmuþsa göstergede 8 göster.
			;		PORTD=0x7F;
			;		bekle(300);
			;		PORTD=0;
			;	}
			;	if(PORTB.3 == 1){ // Port B' nin 3. biti high olmuþsa göstergede 9 göster.
			;		PORTD=0x6F;
			;		bekle(300);
			;		PORTD=0;
			;	}
			;}
			;*/
			;kesme(); // Döngü baþýna dönüþ
	RCALL kesme
			;//-----------------------------------------------	
			;}
	SLEEP
	RESET
			;
			;//////////////////////////////////////////////////////////////////////////////////////////////////
			;
			;void ayarlar()	// Bütün baþlangýç ayarlarýnýn tamamlandýðý kýsým
			;{	
ayarlar
			;	GIE=0;			// Bütün kesmeleri kapat
	BCF   0xFF2,GIE,0
			;	TRISA=0xFF;		// Port A input
	SETF  TRISA,0
			;	TRISB=0xF8;		// Port B' nin 0-3 arasý bitleri output, 4-7 arasý bitleri input 
	MOVLW 248
	MOVWF TRISB,0
			;	TRISC=0;		// Port C output	
	CLRF  TRISC,0
			;	TRISD=0;		// Port D output
	CLRF  TRISD,0
			;	TRISE=0;		// Port E output
	CLRF  TRISE,0
			;
			;	// Program ilk çalýþtýrýldýðýnda çýkýþlarda deðer görülmemesi için ilk çýkýþ deðerleri 0 alýnýr.	
			;	PORTC=0;		
	CLRF  PORTC,0
			;	PORTD=0;
	CLRF  PORTD,0
			;	PORTB=0;
	CLRF  PORTB,0
			; INTCON=0X88;
	MOVLW 136
	MOVWF INTCON,0
			; INTCON2=0XF1;
	MOVLW 241
	MOVWF INTCON2,0
			; INTCON3=0X8B;
	MOVLW 139
	MOVWF INTCON3,0
			;		
			;}
	RETURN
			;void anadongu()
			;{
anadongu
			;INTCON=0x90;
	MOVLW 144
	MOVWF INTCON,0
			;    PORTB.0=1; // Port B' nin 0. biti high yapýlýyor
	BSF   PORTB,0,0
			;	PORTB.1=0; // Port B' nin 1. biti low yapýlýyor
	BCF   PORTB,1,0
			;	PORTB.2=0; // Port B' nin 2. biti low yapýlýyor
	BCF   PORTB,2,0
			;	if(PORTB.0==1){ // Port B' nin 0. biti high olduðu sürece, input bitlerine tek tek bakýlacak
	BTFSS PORTB,0,0
	BRA   m004
			;	if(PORTB.5 == 1){ // Port B' nin 5. biti high olmuþsa göstergede 1 göster.
	BTFSS PORTB,5,0
	BRA   m001
			;		PORTD=0x06;
	MOVLW 6
	MOVWF PORTD,0
			;		bekle(300);
	MOVLW 44
	MOVWF t,0
	MOVLW 1
	MOVWF t+1,0
	RCALL bekle
			;		PORTD=0;
	CLRF  PORTD,0
			;	}
			;	if(PORTB.4 == 1){ // Port B' nin 4. biti high olmuþsa göstergede 2 göster.
m001	BTFSS PORTB,4,0
	BRA   m002
			;		PORTD=0x5B;
	MOVLW 91
	MOVWF PORTD,0
			;		bekle(300);
	MOVLW 44
	MOVWF t,0
	MOVLW 1
	MOVWF t+1,0
	RCALL bekle
			;		PORTD=0;
	CLRF  PORTD,0
			;	}
			;	if(PORTB.3 == 1){ // Port B' nin 3. biti high olmuþsa göstergede 3 göster.
m002	BTFSS PORTB,3,0
	BRA   m003
			;		PORTD=0x4F;
	MOVLW 79
	MOVWF PORTD,0
			;		bekle(300);
	MOVLW 44
	MOVWF t,0
	MOVLW 1
	MOVWF t+1,0
	RCALL bekle
			;		PORTD=0;
	CLRF  PORTD,0
			;	}
			;	if(PORTB.6 == 1){// Port B' nin 6. biti high olmuþsa göstergede 0 göster.
m003	BTFSS PORTB,6,0
	BRA   m004
			;		PORTD=0x03F;
	MOVLW 63
	MOVWF PORTD,0
			;		bekle(300);
	MOVLW 44
	MOVWF t,0
	MOVLW 1
	MOVWF t+1,0
	RCALL bekle
			;		PORTD=0;
	CLRF  PORTD,0
			;	}
			;	}
			;	PORTB.1=1; // Port B' nin 1. biti high, 0 ve 2. bitleri low yapýlýr.
m004	BSF   PORTB,1,0
			;	PORTB.0=0;
	BCF   PORTB,0,0
			;	PORTB.2=0;
	BCF   PORTB,2,0
			;	if(PORTB.1==1){ // Port B' nin 1. biti high olduðu sürece, input bitlerine tek tek bakýlacak
	BTFSS PORTB,1,0
	BRA   m007
			;	if(PORTB.5 == 1){ // Port B' nin 5. biti high olmuþsa göstergede 4 göster.
	BTFSS PORTB,5,0
	BRA   m005
			;		PORTD=0x66;
	MOVLW 102
	MOVWF PORTD,0
			;		bekle(300);
	MOVLW 44
	MOVWF t,0
	MOVLW 1
	MOVWF t+1,0
	RCALL bekle
			;		PORTD=0;
	CLRF  PORTD,0
			;	}
			;	if(PORTB.4 == 1){ // Port B' nin 4. biti high olmuþsa göstergede 5 göster.
m005	BTFSS PORTB,4,0
	BRA   m006
			;		PORTD=0x6D;
	MOVLW 109
	MOVWF PORTD,0
			;		bekle(300);
	MOVLW 44
	MOVWF t,0
	MOVLW 1
	MOVWF t+1,0
	RCALL bekle
			;		PORTD=0;
	CLRF  PORTD,0
			;	}
			;	if(PORTB.3 == 1){ // Port B' nin 3. biti high olmuþsa göstergede 6 göster.
m006	BTFSS PORTB,3,0
	BRA   m007
			;		PORTD=0x7D;
	MOVLW 125
	MOVWF PORTD,0
			;		bekle(300);
	MOVLW 44
	MOVWF t,0
	MOVLW 1
	MOVWF t+1,0
	RCALL bekle
			;		PORTD=0;
	CLRF  PORTD,0
			;	}
			;	}
			;	PORTB.2=1; // Port B' nin 2. biti high, 0 ve 1. bitleri low yapýlýr.
m007	BSF   PORTB,2,0
			;	PORTB.0=0;
	BCF   PORTB,0,0
			;	PORTB.1=0;
	BCF   PORTB,1,0
			;	if(PORTB.2==1){ // Port B' nin 2. biti high olduðu sürece, input bitlerine tek tek bakýlacak
	BTFSS PORTB,2,0
	BRA   m010
			;	if(PORTB.5 == 1){ // Port B' nin 5. biti high olmuþsa göstergede 7 göster.
	BTFSS PORTB,5,0
	BRA   m008
			;		PORTD=0x07;
	MOVLW 7
	MOVWF PORTD,0
			;		bekle(300);
	MOVLW 44
	MOVWF t,0
	MOVLW 1
	MOVWF t+1,0
	RCALL bekle
			;		PORTD=0;
	CLRF  PORTD,0
			;	}
			;	if(PORTB.4 == 1){ // Port B' nin 4. biti high olmuþsa göstergede 8 göster.
m008	BTFSS PORTB,4,0
	BRA   m009
			;		PORTD=0x7F;
	MOVLW 127
	MOVWF PORTD,0
			;		bekle(300);
	MOVLW 44
	MOVWF t,0
	MOVLW 1
	MOVWF t+1,0
	RCALL bekle
			;		PORTD=0;
	CLRF  PORTD,0
			;	}
			;	if(PORTB.3 == 1){ // Port B' nin 3. biti high olmuþsa göstergede 9 göster.
m009	BTFSS PORTB,3,0
	BRA   m010
			;		PORTD=0x6F;
	MOVLW 111
	MOVWF PORTD,0
			;		bekle(300);
	MOVLW 44
	MOVWF t,0
	MOVLW 1
	MOVWF t+1,0
	RCALL bekle
			;		PORTD=0;
	CLRF  PORTD,0
			;	}
			;}
			;}
m010	RETURN
			;
			;void bekle(unsigned long t)	//t milisaniye gecikme saðlar
			;{
bekle
			;	unsigned x;
			;	
			;	for(;t>0;t--)
m011	MOVF  t,W,0
	IORWF t+1,W,0
	BTFSC 0xFD8,Zero_,0
	BRA   m014
			;		for(x=140;x>0;x--)
	MOVLW 140
	MOVWF x,0
m012	MOVF  x,1,0
	BTFSC 0xFD8,Zero_,0
	BRA   m013
			;			nop();
	NOP  
	DECF  x,1,0
	BRA   m012
m013	DECF  t,1,0
	MOVLW 0
	SUBWFB t+1,1,0
	BRA   m011
			;}
m014	RETURN

	END


; *** KEY INFO ***

; 0x000022   17 word(s)  0 % : ayarlar
; 0x000130   17 word(s)  0 % : bekle
; 0x000044  118 word(s)  0 % : anadongu
; 0x000004   11 word(s)  0 % : kesme
; 0x00001A    4 word(s)  0 % : main

; RAM usage: 3 bytes (3 local), 1533 bytes free
; Maximum call level: 3
; Total of 169 code words (1 %)
