;  ASM code generated by mikroVirtualMachine for PIC - V. 8.0.0.0
;  Date/Time: 07.01.2010 22:14:58
;  Info: http://www.mikroe.com


; ADDRESS	OPCODE	ASM
; ----------------------------------------------
$0000	$EF9D	F000			GOTO	_main
$003C	$	_fonk:
;faruk2.c,4 :: 			void fonk()
;faruk2.c,5 :: 			{if(portd==1)
$003C	$5083	    			MOVF	PORTD, 0, 0
$003E	$0A01	    			XORLW	1
$0040	$E120	    			BNZ	L_fonk_0
;faruk2.c,6 :: 			{ portc=dizi[x];
$0042	$0E01	    			MOVLW	1
$0044	$6E04	    			MOVWF	STACK_4, 0
$0046	$C025	F000			MOVFF	_x, STACK_0
$004A	$C026	F001			MOVFF	_x+1, STACK_0+1
$004E	$5004	    			MOVF	STACK_4, 0, 0
$0050	$	L_fonk_8:
$0050	$E005	    			BZ	L_fonk_9
$0052	$3600	    			RLCF	STACK_0, 1, 0
$0054	$9000	    			BCF	STACK_0, 0, 0
$0056	$3601	    			RLCF	STACK_0+1, 1, 0
$0058	$0FFF	    			ADDLW	255
$005A	$D7FA	    			BRA	L_fonk_8
$005C	$	L_fonk_9:
$005C	$0E15	    			MOVLW	_dizi
$005E	$2400	    			ADDWF	STACK_0, 0, 0
$0060	$6EE9	    			MOVWF	FSR0L, 0
$0062	$0E00	    			MOVLW	@_dizi
$0064	$2001	    			ADDWFC	STACK_0+1, 0, 0
$0066	$6EEA	    			MOVWF	FSR0L+1, 0
$0068	$CFEE	FF82			MOVFF	POSTINC0, PORTC
;faruk2.c,7 :: 			x++;
$006C	$4A25	    			INFSNZ	_x, 1, 0
$006E	$2A26	    			INCF	_x+1, 1, 0
;faruk2.c,8 :: 			if(x==8)
$0070	$0E00	    			MOVLW	0
$0072	$1826	    			XORWF	_x+1, 0, 0
$0074	$E102	    			BNZ	L_fonk_10
$0076	$0E08	    			MOVLW	8
$0078	$1825	    			XORWF	_x, 0, 0
$007A	$	L_fonk_10:
$007A	$E102	    			BNZ	L_fonk_1
;faruk2.c,9 :: 			x=0; }
$007C	$6A25	    			CLRF	_x, 0
$007E	$6A26	    			CLRF	_x+1, 0
$0080	$	L_fonk_1:
$0080	$D026	    			BRA	L_fonk_2
$0082	$	L_fonk_0:
;faruk2.c,10 :: 			else if(portd==2)
$0082	$5083	    			MOVF	PORTD, 0, 0
$0084	$0A02	    			XORLW	2
$0086	$E123	    			BNZ	L_fonk_3
;faruk2.c,11 :: 			{ portc=dizi[x];
$0088	$0E01	    			MOVLW	1
$008A	$6E04	    			MOVWF	STACK_4, 0
$008C	$C025	F000			MOVFF	_x, STACK_0
$0090	$C026	F001			MOVFF	_x+1, STACK_0+1
$0094	$5004	    			MOVF	STACK_4, 0, 0
$0096	$	L_fonk_11:
$0096	$E005	    			BZ	L_fonk_12
$0098	$3600	    			RLCF	STACK_0, 1, 0
$009A	$9000	    			BCF	STACK_0, 0, 0
$009C	$3601	    			RLCF	STACK_0+1, 1, 0
$009E	$0FFF	    			ADDLW	255
$00A0	$D7FA	    			BRA	L_fonk_11
$00A2	$	L_fonk_12:
$00A2	$0E15	    			MOVLW	_dizi
$00A4	$2400	    			ADDWF	STACK_0, 0, 0
$00A6	$6EE9	    			MOVWF	FSR0L, 0
$00A8	$0E00	    			MOVLW	@_dizi
$00AA	$2001	    			ADDWFC	STACK_0+1, 0, 0
$00AC	$6EEA	    			MOVWF	FSR0L+1, 0
$00AE	$CFEE	FF82			MOVFF	POSTINC0, PORTC
;faruk2.c,12 :: 			x--;
$00B2	$0E01	    			MOVLW	1
$00B4	$5E25	    			SUBWF	_x, 1, 0
$00B6	$0E00	    			MOVLW	0
$00B8	$5A26	    			SUBWFB	_x+1, 1, 0
;faruk2.c,13 :: 			if(x==-1)
$00BA	$0EFF	    			MOVLW	255
$00BC	$1826	    			XORWF	_x+1, 0, 0
$00BE	$E102	    			BNZ	L_fonk_13
$00C0	$0EFF	    			MOVLW	255
$00C2	$1825	    			XORWF	_x, 0, 0
$00C4	$	L_fonk_13:
$00C4	$E104	    			BNZ	L_fonk_4
;faruk2.c,14 :: 			x=7; }
$00C6	$0E07	    			MOVLW	7
$00C8	$6E25	    			MOVWF	_x, 0
$00CA	$0E00	    			MOVLW	0
$00CC	$6E26	    			MOVWF	_x+1, 0
$00CE	$	L_fonk_4:
$00CE	$	L_fonk_3:
$00CE	$	L_fonk_2:
;faruk2.c,15 :: 			}
$00CE	$0012	    			RETURN
$0008	$	_interrupt:
$0008	$C000	F02B			MOVFF	STACK_0, STSAVED_0
$000C	$CFE9	F027			MOVFF	FSR0L, ?saveFSR0
$0010	$CFEA	F028			MOVFF	FSR0H, ?saveFSR0+1
$0014	$CFE1	F029			MOVFF	FSR1L, ?saveFSR1
$0018	$CFE2	F02A			MOVFF	FSR1H, ?saveFSR1+1
;faruk2.c,17 :: 			void interrupt()
;faruk2.c,18 :: 			{ if(INTCON.INT0IF)
$001C	$A2F2	    			BTFSS	INTCON, 1, 0
$001E	$D003	    			BRA	L_interrupt_5
;faruk2.c,19 :: 			{ fonk();
$0020	$EC1E	F000			CALL	_fonk
;faruk2.c,20 :: 			INTCON.INT0IF=0;
$0024	$92F2	    			BCF	INTCON, 1, 0
;faruk2.c,21 :: 			}
$0026	$	L_interrupt_5:
;faruk2.c,23 :: 			}
$0026	$	L_Interrupt_end:
$0026	$C027	FFE9			MOVFF	?saveFSR0, FSR0L
$002A	$C028	FFEA			MOVFF	?saveFSR0+1, FSR0H
$002E	$C029	FFE1			MOVFF	?saveFSR1, FSR1L
$0032	$C02A	FFE2			MOVFF	?saveFSR1+1, FSR1H
$0036	$C02B	F000			MOVFF	STSAVED_0, STACK_0
$003A	$0011	    			RETFIE
$00D0	$	_init:
;faruk2.c,25 :: 			void init()
;faruk2.c,26 :: 			{TRISC=0;
$00D0	$6A94	    			CLRF	TRISC, 0
;faruk2.c,27 :: 			PORTC=0;
$00D2	$6A82	    			CLRF	PORTC, 0
;faruk2.c,28 :: 			TRISD=1;
$00D4	$0E01	    			MOVLW	1
$00D6	$6E95	    			MOVWF	TRISD, 0
;faruk2.c,29 :: 			PORTD=0;
$00D8	$6A83	    			CLRF	PORTD, 0
;faruk2.c,30 :: 			INTCON=0X88;
$00DA	$0E88	    			MOVLW	136
$00DC	$6EF2	    			MOVWF	INTCON, 0
;faruk2.c,31 :: 			INTCON2=0XF1;
$00DE	$0EF1	    			MOVLW	241
$00E0	$6EF1	    			MOVWF	INTCON2, 0
;faruk2.c,32 :: 			INTCON3=0X8B;
$00E2	$0E8B	    			MOVLW	139
$00E4	$6EF0	    			MOVWF	INTCON3, 0
;faruk2.c,33 :: 			INTCON.INT0IF=0;
$00E6	$92F2	    			BCF	INTCON, 1, 0
;faruk2.c,34 :: 			INTCON.RBIF=0;
$00E8	$90F2	    			BCF	INTCON, 0, 0
;faruk2.c,35 :: 			INTCON3.INT2IF=0;
$00EA	$92F0	    			BCF	INTCON3, 1, 0
;faruk2.c,36 :: 			INTCON3.INT1IF=0;
$00EC	$90F0	    			BCF	INTCON3, 0, 0
;faruk2.c,37 :: 			}
$00EE	$0012	    			RETURN
$00F0	$	GlobalInifaruk2:
$00F0	$0E01	    			MOVLW	1
$00F2	$6E15	    			MOVWF	_dizi+0, 0
$00F4	$0E00	    			MOVLW	0
$00F6	$6E16	    			MOVWF	_dizi+1, 0
$00F8	$0E02	    			MOVLW	2
$00FA	$6E17	    			MOVWF	_dizi+2, 0
$00FC	$0E00	    			MOVLW	0
$00FE	$6E18	    			MOVWF	_dizi+3, 0
$0100	$0E04	    			MOVLW	4
$0102	$6E19	    			MOVWF	_dizi+4, 0
$0104	$0E00	    			MOVLW	0
$0106	$6E1A	    			MOVWF	_dizi+5, 0
$0108	$0E08	    			MOVLW	8
$010A	$6E1B	    			MOVWF	_dizi+6, 0
$010C	$0E00	    			MOVLW	0
$010E	$6E1C	    			MOVWF	_dizi+7, 0
$0110	$0E10	    			MOVLW	16
$0112	$6E1D	    			MOVWF	_dizi+8, 0
$0114	$0E00	    			MOVLW	0
$0116	$6E1E	    			MOVWF	_dizi+9, 0
$0118	$0E20	    			MOVLW	32
$011A	$6E1F	    			MOVWF	_dizi+10, 0
$011C	$0E00	    			MOVLW	0
$011E	$6E20	    			MOVWF	_dizi+11, 0
$0120	$0E40	    			MOVLW	64
$0122	$6E21	    			MOVWF	_dizi+12, 0
$0124	$0E00	    			MOVLW	0
$0126	$6E22	    			MOVWF	_dizi+13, 0
$0128	$0E80	    			MOVLW	128
$012A	$6E23	    			MOVWF	_dizi+14, 0
$012C	$0E00	    			MOVLW	0
$012E	$6E24	    			MOVWF	_dizi+15, 0
$0130	$0E00	    			MOVLW	0
$0132	$6E25	    			MOVWF	_x+0, 0
$0134	$0E00	    			MOVLW	0
$0136	$6E26	    			MOVWF	_x+1, 0
;faruk2.c,2 :: 			int x=0;
$0138	$0012	    			RETURN
$013A	$	_main:
;faruk2.c,39 :: 			void main()
;faruk2.c,40 :: 			{init();
$013A	$EC78	F000			CALL	GlobalInifaruk2
$013E	$EC68	F000			CALL	_init
;faruk2.c,41 :: 			do{
$0142	$	L_main_6:
;faruk2.c,42 :: 			}while(1);
$0142	$D7FF	    			BRA	L_main_6
;faruk2.c,43 :: 			}
$0144	$D7FF	    			BRA	$
