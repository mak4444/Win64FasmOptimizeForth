;/
;/1 VALUE R/O ( -- fam ) \ 94 FILE

_RrslO:
	call	_DOVALUE	; 80414CFD E8 E2 F9 FE FF 

	DQ 0x1
;/
;/2 VALUE W/O ( -- fam ) \ 94 FILE

_WrslO:
	call	_DOVALUE	; 80414D0A E8 D5 F9 FE FF 

	DQ 0x2
;/
;/3 VALUE R/W ( -- fam ) \ 94 FILE

_RrslW:
	call	_DOVALUE	; 80414D17 E8 C8 F9 FE FF 

	DQ 0x3
;/
;/: CFNAME-SET  ( adr len -- )
;/ DUP 1+ >R  CURFILENAME CURFILENAME R@ + CFNAME_SIZE R> - CMOVE>

_CFNAMEsubSET:
	call	_DUP	; 80414D24 E8 FF F7 FE FF 
	call	_CHARadd	; 80414D29 E8 4D F7 FE FF 
	Push	rax	; 80414D2E 50 
;/*	mov	0x00(rbp),rax	; 80414D2F 
	DB 0x48,0x8B,0x45,0x0
;/*	mov	rax,0x00(rbp)	; 80414D33 
	DB 0x48,0x89,0x45,0x0
;/*	lea	_xc+0x20 (%rip),rax	; 80414D37 
	DB 0x48,0x8D,0x5,0xBE,0xDF,0xFF,0xFF
;/*	mov	rax,-0x08(rbp)	; 80414D3E 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_xc+0x20 (%rip),rax	; 80414D42 
	DB 0x48,0x8D,0x5,0xB3,0xDF,0xFF,0xFF
;/*	mov	rax,-0x10(rbp)	; 80414D49 
	DB 0x48,0x89,0x45,0xF0
;/*	mov	(rsp),rax	; 80414D4D 
	DB 0x48,0x8B,0x4,0x24
;/*	lea	-0x10(rbp),rbp	; 80414D51 
	DB 0x48,0x8D,0x6D,0xF0
	call	_add	; 80414D55 E8 C1 F6 FE FF 
;/*	mov	rax,-0x08(rbp)	; 80414D5A 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x1BC,eax	; 80414D5E 
	DB 0xB8,0xBC,0x1,0x0,0x0
;/*	mov	rax,-0x10(rbp)	; 80414D63 
	DB 0x48,0x89,0x45,0xF0
	pop	rax	; 80414D67 58 
;/*	lea	-0x10(rbp),rbp	; 80414D68 
	DB 0x48,0x8D,0x6D,0xF0
	call	_sub	; 80414D6C E8 A7 F6 FE FF 
	call	_CMOVEgreat	; 80414D71 E8 E4 F3 7E 0 
;/CURFILENAME $! ;
;/*	mov	rax,-0x08(rbp)	; 80414D76 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_xc+0x20 (%rip),rax	; 80414D7A 
	DB 0x48,0x8D,0x5,0x7B,0xDF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414D81 
	DB 0x48,0x8D,0x6D,0xF8
	call	_dolsave	; 80414D85 E8 9A 3 FF FF 
	ret		; 80414D8A C3 
;/
;/: CFNAME-FREE  ( -- )
;/ CURFILENAME COUNT + CURFILENAME


_CFNAMEsubFREE:
;/*	mov	rax,-0x08(rbp)	; 80414D8B 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_xc+0x20 (%rip),rax	; 80414D8F 
	DB 0x48,0x8D,0x5,0x66,0xDF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414D96 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COUNT	; 80414D9A E8 22 F5 FE FF 
	call	_add	; 80414D9F E8 77 F6 FE FF 
;/*	mov	rax,-0x08(rbp)	; 80414DA4 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_xc+0x20 (%rip),rax	; 80414DA8 
	DB 0x48,0x8D,0x5,0x4D,0xDF,0xFF,0xFF
;/*	mov	rax,-0x10(rbp)	; 80414DAF 
	DB 0x48,0x89,0x45,0xF0
;/ CFNAME_SIZE CURFILENAME C@ - 255 +  CMOVE ;
;/*	mov	$0x1BC,eax	; 80414DB3 
	DB 0xB8,0xBC,0x1,0x0,0x0
;/*	mov	rax,-0x18(rbp)	; 80414DB8 
	DB 0x48,0x89,0x45,0xE8
;/*	lea	_xc+0x20 (%rip),rax	; 80414DBC 
	DB 0x48,0x8D,0x5,0x39,0xDF,0xFF,0xFF
;/*	lea	-0x18(rbp),rbp	; 80414DC3 
	DB 0x48,0x8D,0x6D,0xE8
	call	_Cload	; 80414DC7 E8 1 F4 FE FF 
	call	_sub	; 80414DCC E8 47 F6 FE FF 
;/*	mov	rax,-0x08(rbp)	; 80414DD1 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xFF,eax	; 80414DD5 
	DB 0xB8,0xFF,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80414DDA 
	DB 0x48,0x8D,0x6D,0xF8
	call	_add	; 80414DDE E8 38 F6 FE FF 
	call	_CMOVE	; 80414DE3 E8 E5 F8 FE FF 
	ret		; 80414DE8 C3 
;/
;/: INCLUDE-FILE ( i*x fileid -- j*x ) \ 94 FILE
;/	>IN  @ >R


_INCLUDEsubFILE:
;/*	mov	rax,-0x08(rbp)	; 80414DE9 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80414DED 
	DB 0x48,0x8D,0x5,0x80,0xFB,0xFE,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414DF4 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80414DF8 E8 CC F3 FE FF 
	Push	rax	; 80414DFD 50 
;/*	mov	0x00(rbp),rax	; 80414DFE 
	DB 0x48,0x8B,0x45,0x0
;/*	mov	rax,0x00(rbp)	; 80414E02 
	DB 0x48,0x89,0x45,0x0
;/	CURSTR @ >R CURSTR 0!
;/*	lea	_OKdot+0x10 (%rip),rax	; 80414E06 
	DB 0x48,0x8D,0x5,0xB7,0xDB,0xFF,0xFF
	call	_load	; 80414E0D E8 B7 F3 FE FF 
	Push	rax	; 80414E12 50 
;/*	mov	0x00(rbp),rax	; 80414E13 
	DB 0x48,0x8B,0x45,0x0
;/*	mov	rax,0x00(rbp)	; 80414E17 
	DB 0x48,0x89,0x45,0x0
;/*	lea	_OKdot+0x10 (%rip),rax	; 80414E1B 
	DB 0x48,0x8D,0x5,0xA2,0xDB,0xFF,0xFF
	call	_OFF	; 80414E22 E8 52 F4 FE FF 
;/	SOURCE-ID >R  TO SOURCE-ID
;/*	mov	rax,-0x08(rbp)	; 80414E27 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_SOURCEsubID+0x5 (%rip),rax	; 80414E2B 
	DB 0x48,0x8D,0x5,0x99,0xCD,0xFF,0xFF
;/*	mov	(rax),rax	; 80414E32 
	DB 0x48,0x8B,0x0
	Push	rax	; 80414E35 50 
;/*	mov	-0x08(rbp),rax	; 80414E36 
	DB 0x48,0x8B,0x45,0xF8
;/*	mov	rax,-0x08(rbp)	; 80414E3A 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_SOURCEsubID+0x5 (%rip),rax	; 80414E3E 
	DB 0x48,0x8D,0x5,0x86,0xCD,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414E45 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 80414E49 E8 B2 F3 FE FF 
;/	TIB >R ATIB TO TIB
;/*	mov	rax,-0x08(rbp)	; 80414E4E 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_TIB+0x5 (%rip),rax	; 80414E52 
	DB 0x48,0x8D,0x5,0x7F,0xCD,0xFF,0xFF
;/*	mov	(rax),rax	; 80414E59 
	DB 0x48,0x8B,0x0
	Push	rax	; 80414E5C 50 
;/*	mov	-0x08(rbp),rax	; 80414E5D 
	DB 0x48,0x8B,0x45,0xF8
;/*	mov	rax,-0x08(rbp)	; 80414E61 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x2A (%rip),rax	; 80414E65 
	DB 0x48,0x8D,0x5,0x8,0xF9,0xFE,0xFF
;/*	mov	rax,-0x10(rbp)	; 80414E6C 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_TIB+0x5 (%rip),rax	; 80414E70 
	DB 0x48,0x8D,0x5,0x61,0xCD,0xFF,0xFF
;/*	lea	-0x10(rbp),rbp	; 80414E77 
	DB 0x48,0x8D,0x6D,0xF0
	call	_save	; 80414E7B E8 80 F3 FE FF 
;/	SOURCE
	call	_SOURCE	; 80414E80 E8 C4 CD FF FF 
;/	RP@ OVER QALIGNED - RP!
	call	_RPload	; 80414E85 E8 9B F2 FE FF 
	call	_OVER	; 80414E8A E8 A F7 FE FF 
	call	_QALIGNED	; 80414E8F E8 90 FF FE FF 
	call	_sub	; 80414E94 E8 7F F5 FE FF 
	call	_RPsave	; 80414E99 E8 9E F2 FE FF 
;/	RP@ SWAP CMOVE
	call	_RPload	; 80414E9E E8 82 F2 FE FF 
	call	_SWAP	; 80414EA3 E8 9A F6 FE FF 
	call	_CMOVE	; 80414EA8 E8 20 F8 FE FF 
;/	SOURCE 2>R 
	call	_SOURCE	; 80414EAD E8 97 CD FF FF 
	call	_2greatR	; 80414EB2 E8 D6 F2 FE FF 
;/	['] FQUIT CATCH
;/*	mov	rax,-0x08(rbp)	; 80414EB7 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_FQUIT(%rip),rax	; 80414EBB 
	DB 0x48,0x8D,0x5,0xBE,0xDD,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414EC2 
	DB 0x48,0x8D,0x6D,0xF8
	call	_CATCH	; 80414EC6 E8 CC 5 FF FF 
;/	SAVEERR	
	call	_SAVEERR	; 80414ECB E8 B2 E3 FF FF 
;/	DUP  IF cr ." in <" CURFILENAME COUNT TYPE ." >:" CURSTR @ . THEN
	call	_DUP	; 80414ED0 E8 53 F6 FE FF 
	test	rax,rax	; 80414ED5 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80414ED8 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414EDC 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_INCLUDEsubFILE+0x150 	; 80414EE0 
	DB 0xF,0x84,0x53,0x0,0x0,0x0
	call	_CR	; 80414EE6 E8 93 FE FE FF 
	call	_cbigSdticcend	; 80414EEB E8 E3 FF FE FF 
	DB 0x4,0x69,0x6E,0x20,0x3C
	call	_TYPE	; 80414EF5 E8 52 FE FE FF 
;/*	mov	rax,-0x08(rbp)	; 80414EFA 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_xc+0x20 (%rip),rax	; 80414EFE 
	DB 0x48,0x8D,0x5,0xF7,0xDD,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414F05 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COUNT	; 80414F09 E8 B3 F3 FE FF 
	call	_TYPE	; 80414F0E E8 39 FE FE FF 
	call	_cbigSdticcend	; 80414F13 E8 BB FF FE FF 
	DB 0x2,0x3E,0x3A
	call	_TYPE	; 80414F1B E8 2C FE FE FF 
;/*	mov	rax,-0x08(rbp)	; 80414F20 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_OKdot+0x10 (%rip),rax	; 80414F24 
	DB 0x48,0x8D,0x5,0x99,0xDA,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414F2B 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80414F2F E8 95 F2 FE FF 
	call	_dot	; 80414F34 E8 7E B6 FF FF 
;/	2R> SOURCE!
	call	_2Rgreat	; 80414F39 E8 17 F2 FE FF 
	call	_SOURCEsave	; 80414F3E E8 E2 CC FF FF 
;/	RP@ SOURCE CMOVE
	call	_RPload	; 80414F43 E8 DD F1 FE FF 
	call	_SOURCE	; 80414F48 E8 FC CC FF FF 
	call	_CMOVE	; 80414F4D E8 7B F7 FE FF 
;/	RP@ SOURCE NIP QALIGNED + RP!
	call	_RPload	; 80414F52 E8 CE F1 FE FF 
	call	_SOURCE	; 80414F57 E8 ED CC FF FF 
	call	_NIP	; 80414F5C E8 AB F6 FE FF 
	call	_QALIGNED	; 80414F61 E8 BE FE FE FF 
	call	_add	; 80414F66 E8 B0 F4 FE FF 
	call	_RPsave	; 80414F6B E8 CC F1 FE FF 
;/	R> TO TIB
;/*	mov	rax,-0x08(rbp)	; 80414F70 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80414F74 58 
;/*	mov	rax,-0x10(rbp)	; 80414F75 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_TIB+0x5 (%rip),rax	; 80414F79 
	DB 0x48,0x8D,0x5,0x58,0xCC,0xFF,0xFF
;/*	lea	-0x10(rbp),rbp	; 80414F80 
	DB 0x48,0x8D,0x6D,0xF0
	call	_save	; 80414F84 E8 77 F2 FE FF 
;/	R> TO SOURCE-ID
;/*	mov	rax,-0x08(rbp)	; 80414F89 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80414F8D 58 
;/*	mov	rax,-0x10(rbp)	; 80414F8E 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_SOURCEsubID+0x5 (%rip),rax	; 80414F92 
	DB 0x48,0x8D,0x5,0x32,0xCC,0xFF,0xFF
;/*	lea	-0x10(rbp),rbp	; 80414F99 
	DB 0x48,0x8D,0x6D,0xF0
	call	_save	; 80414F9D E8 5E F2 FE FF 
;/	R> CURSTR !
;/*	mov	rax,-0x08(rbp)	; 80414FA2 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80414FA6 58 
;/*	mov	rax,-0x10(rbp)	; 80414FA7 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_OKdot+0x10 (%rip),rax	; 80414FAB 
	DB 0x48,0x8D,0x5,0x12,0xDA,0xFF,0xFF
;/*	lea	-0x10(rbp),rbp	; 80414FB2 
	DB 0x48,0x8D,0x6D,0xF0
	call	_save	; 80414FB6 E8 45 F2 FE FF 
;/	R> >IN ! THROW  
;/*	mov	rax,-0x08(rbp)	; 80414FBB 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80414FBF 58 
;/*	mov	rax,-0x10(rbp)	; 80414FC0 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80414FC4 
	DB 0x48,0x8D,0x5,0xA9,0xF9,0xFE,0xFF
;/*	lea	-0x10(rbp),rbp	; 80414FCB 
	DB 0x48,0x8D,0x6D,0xF0
	call	_save	; 80414FCF E8 2C F2 FE FF 
	call	_THROW	; 80414FD4 E8 2B 5 FF FF 
;/;
	ret		; 80414FD9 C3 
;/
;/T: VIEW_{
;/?YDP><DP


_VIEW_lsk:
	call	_queYDPgreatlessDP	; 80414FDA E8 96 EF FF FF 
;/   HERE VIEW_LINK , TO VIEW_LINK  0 ,
	call	_HERE	; 80414FDF E8 E9 BF FF FF 
;/*	mov	rax,-0x08(rbp)	; 80414FE4 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_VIEW_LINK+0x5 (%rip),rax	; 80414FE8 
	DB 0x48,0x8D,0x5,0xAC,0xEF,0xFF,0xFF
;/*	mov	(rax),rax	; 80414FEF 
	DB 0x48,0x8B,0x0
;/*	lea	-0x08(rbp),rbp	; 80414FF2 
	DB 0x48,0x8D,0x6D,0xF8
	call	_com	; 80414FF6 E8 7C FC FE FF 
;/*	mov	rax,-0x08(rbp)	; 80414FFB 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_VIEW_LINK+0x5 (%rip),rax	; 80414FFF 
	DB 0x48,0x8D,0x5,0x95,0xEF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80415006 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 8041500A E8 F1 F1 FE FF 
;/*	mov	rax,-0x08(rbp)	; 8041500F 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80415013 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80415018 
	DB 0x48,0x8D,0x6D,0xF8
	call	_com	; 8041501C E8 56 FC FE FF 
;/?YDP><DP
	call	_queYDPgreatlessDP	; 80415021 E8 4F EF FF FF 
;/;
	ret		; 80415026 C3 
;/
;/T: }VIEW
;/?YDP><DP


_rskVIEW:
	call	_queYDPgreatlessDP	; 80415027 E8 49 EF FF FF 
;/   HERE  VIEW_LINK , TO VIEW_LINK -1 ,
	call	_HERE	; 8041502C E8 9C BF FF FF 
;/*	mov	rax,-0x08(rbp)	; 80415031 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_VIEW_LINK+0x5 (%rip),rax	; 80415035 
	DB 0x48,0x8D,0x5,0x5F,0xEF,0xFF,0xFF
;/*	mov	(rax),rax	; 8041503C 
	DB 0x48,0x8B,0x0
;/*	lea	-0x08(rbp),rbp	; 8041503F 
	DB 0x48,0x8D,0x6D,0xF8
	call	_com	; 80415043 E8 2F FC FE FF 
;/*	mov	rax,-0x08(rbp)	; 80415048 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_VIEW_LINK+0x5 (%rip),rax	; 8041504C 
	DB 0x48,0x8D,0x5,0x48,0xEF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80415053 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 80415057 E8 A4 F1 FE FF 
;/*	mov	rax,-0x08(rbp)	; 8041505C 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0x1,rax	; 80415060 
	DB 0x48,0xC7,0xC0,0xFF,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80415067 
	DB 0x48,0x8D,0x6D,0xF8
	call	_com	; 8041506B E8 7 FC FE FF 
;/   CURFILENAME COUNT S",
;/*	mov	rax,-0x08(rbp)	; 80415070 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_xc+0x20 (%rip),rax	; 80415074 
	DB 0x48,0x8D,0x5,0x81,0xDC,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041507B 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COUNT	; 8041507F E8 3D F2 FE FF 
	call	_Sdticcom	; 80415084 E8 37 E5 FF FF 
;/?YDP><DP
	call	_queYDPgreatlessDP	; 80415089 E8 E7 EE FF FF 
;/;
	ret		; 8041508E C3 
;/
;/T: INCLUDED  ( c-addr u ---- )
;/\ Open the file with name c-addr u and interpret all lines contained in it.
;/	CR RP@ 6 >> $F AND SPACES ." TO   <" 2DUP TYPE ." >"


_INCLUDED:
	call	_CR	; 8041508F E8 EA FC FE FF 
	call	_RPload	; 80415094 E8 8C F0 FE FF 
;/*	mov	rax,-0x08(rbp)	; 80415099 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x6,eax	; 8041509D 
	DB 0xB8,0x6,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804150A2 
	DB 0x48,0x8D,0x6D,0xF8
	call	_greatgreat	; 804150A6 E8 96 F5 FE FF 
;/*	mov	rax,-0x08(rbp)	; 804150AB 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xF,eax	; 804150AF 
	DB 0xB8,0xF,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804150B4 
	DB 0x48,0x8D,0x6D,0xF8
	call	_AND	; 804150B8 E8 25 F3 FE FF 
	call	_SPACES	; 804150BD E8 7D B4 FF FF 
	call	_cbigSdticcend	; 804150C2 E8 C FE FE FF 
	DB 0x6,0x54,0x4F,0x20,0x20,0x20,0x3C
	call	_TYPE	; 804150CE E8 79 FC FE FF 
	call	_2DUP	; 804150D3 E8 59 F4 FE FF 
	call	_TYPE	; 804150D8 E8 6F FC FE FF 
	call	_cbigSdticcend	; 804150DD E8 F1 FD FE FF 
	DB 0x1,0x3E
	call	_TYPE	; 804150E4 E8 63 FC FE FF 
;/	2DUP	R/O  OPEN-FILE THROW >R
	call	_2DUP	; 804150E9 E8 43 F4 FE FF 
;/*	mov	rax,-0x08(rbp)	; 804150EE 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_RrslO+0x5 (%rip),rax	; 804150F2 
	DB 0x48,0x8D,0x5,0x9,0xFC,0xFF,0xFF
;/*	mov	(rax),rax	; 804150F9 
	DB 0x48,0x8B,0x0
;/*	lea	-0x08(rbp),rbp	; 804150FC 
	DB 0x48,0x8D,0x6D,0xF8
	call	_OPENsubFILE	; 80415100 E8 E2 D4 FF FF 
	call	_THROW	; 80415105 E8 FA 3 FF FF 
	Push	rax	; 8041510A 50 
;/*	mov	0x00(rbp),rax	; 8041510B 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8041510F 
	DB 0x48,0x8D,0x6D,0x8
;/	CFNAME-SET
	call	_CFNAMEsubSET	; 80415113 E8 C FC FF FF 
;/        VIEW_{
	call	_VIEW_lsk	; 80415118 E8 BD FE FF FF 
;/	R@
;/*	mov	rax,-0x08(rbp)	; 8041511D 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	(rsp),rax	; 80415121 
	DB 0x48,0x8B,0x4,0x24
;/*	mov	rax,-0x10(rbp)	; 80415125 
	DB 0x48,0x89,0x45,0xF0
;/	 ['] INCLUDE-FILE
;/*	lea	_INCLUDEsubFILE(%rip),rax	; 80415129 
	DB 0x48,0x8D,0x5,0xB9,0xFC,0xFF,0xFF
;/*	lea	-0x10(rbp),rbp	; 80415130 
	DB 0x48,0x8D,0x6D,0xF0
;/	CATCH
	call	_CATCH	; 80415134 E8 5E 3 FF FF 
;/	}VIEW
	call	_rskVIEW	; 80415139 E8 E9 FE FF FF 
;/	CFNAME-FREE
	call	_CFNAMEsubFREE	; 8041513E E8 48 FC FF FF 
;/	R> CLOSE-FILE DROP
;/*	mov	rax,-0x08(rbp)	; 80415143 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80415147 58 
;/*	lea	-0x08(rbp),rbp	; 80415148 
	DB 0x48,0x8D,0x6D,0xF8
	call	_CLOSEsubFILE	; 8041514C E8 3 F0 7E 0 
	call	_DgreatS	; 80415151 E8 DD EF FE FF 
;/	THROW
	call	_THROW	; 80415156 E8 A9 3 FF FF 
;/;
	ret		; 8041515B C3 
;/
;/: FLOAD  PARSE-NAME INCLUDED ;


_FLOAD:
	call	_PARSEsubNAME	; 8041515C E8 5 CD FF FF 
	call	_INCLUDED	; 80415161 E8 29 FF FF FF 
	ret		; 80415166 C3 
;/
;/: REQUIRED ( waddr wu laddr lu -- )
;/  2SWAP SFIND


_REQUIRED:
	call	_2SWAP	; 80415167 E8 E3 F3 FE FF 
	call	_SFIND	; 8041516C E8 EF CE FF FF 
;/  IF DROP 2DROP EXIT
	test	rax,rax	; 80415171 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80415174 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80415178 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_REQUIRED+0x2B 	; 8041517C 
	DB 0xF,0x84,0x10,0x0,0x0,0x0
	call	_DgreatS	; 80415182 E8 AC EF FE FF 
	call	_2DROP	; 80415187 E8 E0 F3 FE FF 
	ret		; 8041518C C3 
;/  ELSE 2DROP INCLUDED EXIT THEN
;/*	jmp	_REQUIRED+0x36 	; 8041518D 
	DB 0xE9,0xB,0x0,0x0,0x0
	call	_2DROP	; 80415192 E8 D5 F3 FE FF 
	call	_INCLUDED	; 80415197 E8 F3 FE FF FF 
	ret		; 8041519C C3 
;/;
	ret		; 8041519D C3 
;/
;/: REQUIRE ( "word" "libpath" -- )
;/  PARSE-NAME PARSE-NAME 2DUP + 0 SWAP C!


_REQUIRE:
	call	_PARSEsubNAME	; 8041519E E8 C3 CC FF FF 
	call	_PARSEsubNAME	; 804151A3 E8 BE CC FF FF 
	call	_2DUP	; 804151A8 E8 84 F3 FE FF 
	call	_add	; 804151AD E8 69 F2 FE FF 
;/*	mov	rax,-0x08(rbp)	; 804151B2 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 804151B6 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804151BB 
	DB 0x48,0x8D,0x6D,0xF8
	call	_SWAP	; 804151BF E8 7E F3 FE FF 
	call	_Csave	; 804151C4 E8 C F0 FE FF 
;/  REQUIRED
	call	_REQUIRED	; 804151C9 E8 99 FF FF FF 
;/;
	ret		; 804151CE C3 
;/
;/
