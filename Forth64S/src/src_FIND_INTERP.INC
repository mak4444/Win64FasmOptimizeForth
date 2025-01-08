;/
;/: DO-VOC R> 1 ANDC

_DOsubVOC:
;/*	mov	rax,-0x08(rbp)	; 80411B55 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80411B59 58 
;/*	mov	rax,-0x10(rbp)	; 80411B5A 
	DB 0x48,0x89,0x45,0xF0
;/*	mov	$0x1,eax	; 80411B5E 
	DB 0xB8,0x1,0x0,0x0,0x0
;/*	lea	-0x10(rbp),rbp	; 80411B63 
	DB 0x48,0x8D,0x6D,0xF0
	call	_ANDC	; 80411B67 E8 73 28 FF FF 
;/ CONTEXT ! ;
	call	_CONTEXT	; 80411B6C E8 89 25 7F 0 
	call	_save	; 80411B71 E8 8A 26 FF FF 
	ret		; 80411B76 C3 
;/
;/: ?PAIRS        \ x1 x1 --
;/  XOR -22 ?THROW ;


_quePAIRS:
	call	_XOR	; 80411B77 E8 78 28 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80411B7C 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0x16,rax	; 80411B80 
	DB 0x48,0xC7,0xC0,0xEA,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411B87 
	DB 0x48,0x8D,0x6D,0xF8
	call	_queTHROW	; 80411B8B E8 17 3A FF FF 
	ret		; 80411B90 C3 
;/
;/T: DEFINITIONS  ( --- )
;/\ Set the definitions wordlist to the last wordlist in the search order.
;/  CONTEXT @ CURRENT ! ;


_DEFINITIONS:
	call	_CONTEXT	; 80411B91 E8 64 25 7F 0 
	call	_load	; 80411B96 E8 2E 26 FF FF 
	call	_CURRENT	; 80411B9B E8 60 25 7F 0 
	call	_save	; 80411BA0 E8 5B 26 FF FF 
	ret		; 80411BA5 C3 
;/
;/T: ALIGN HERE ALIGNED DP! ;


_ALIGN:
	call	_HERE	; 80411BA6 E8 22 F4 FF FF 
	call	_ALIGNED	; 80411BAB E8 A1 32 FF FF 
	call	_DPsave	; 80411BB0 E8 AD 30 FF FF 
	ret		; 80411BB5 C3 
;/T: HALIGN HERE HALIGNED DP! ;


_HALIGN:
	call	_HERE	; 80411BB6 E8 12 F4 FF FF 
	call	_HALIGNED	; 80411BBB E8 27 32 FF FF 
	call	_DPsave	; 80411BC0 E8 9D 30 FF FF 
	ret		; 80411BC5 C3 
;/
;/0 VALUE SOURCE-ID


_SOURCEsubID:
	call	_DOVALUE	; 80411BC6 E8 19 2B FF FF 

	DQ 0x0
;/
;/ATIB VALUE TIB

_TIB:
	call	_DOVALUE	; 80411BD3 E8 C 2B FF FF 

	DQ 0x68C+fimg
;/
;/: #TIB #ATIB TIB ATIB = CELL AND + ;

_hashTIB:
;/*	mov	rax,-0x08(rbp)	; 80411BE0 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x25A (%rip),rax	; 80411BE4 
	DB 0x48,0x8D,0x5,0xB9,0x2D,0xFF,0xFF
;/*	mov	rax,-0x10(rbp)	; 80411BEB 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_TIB+0x5 (%rip),rax	; 80411BEF 
	DB 0x48,0x8D,0x5,0xE2,0xFF,0xFF,0xFF
;/*	mov	(rax),rax	; 80411BF6 
	DB 0x48,0x8B,0x0
;/*	mov	rax,-0x18(rbp)	; 80411BF9 
	DB 0x48,0x89,0x45,0xE8
;/*	lea	_UNLOOP+0x2A (%rip),rax	; 80411BFD 
	DB 0x48,0x8D,0x5,0x70,0x2B,0xFF,0xFF
;/*	lea	-0x18(rbp),rbp	; 80411C04 
	DB 0x48,0x8D,0x6D,0xE8
	call	_equ	; 80411C08 E8 2D 27 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80411C0D 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x8,eax	; 80411C11 
	DB 0xB8,0x8,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80411C16 
	DB 0x48,0x8D,0x6D,0xF8
	call	_AND	; 80411C1A E8 C3 27 FF FF 
	call	_add	; 80411C1F E8 F7 27 FF FF 
	ret		; 80411C24 C3 
;/
;/: SOURCE! ( c-addr u -- ) 
;/ SWAP TO TIB  #TIB ! ;


_SOURCEsave:
	call	_SWAP	; 80411C25 E8 18 29 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80411C2A 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_TIB+0x5 (%rip),rax	; 80411C2E 
	DB 0x48,0x8D,0x5,0xA3,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411C35 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 80411C39 E8 C2 25 FF FF 
	call	_hashTIB	; 80411C3E E8 9D FF FF FF 
	call	_save	; 80411C43 E8 B8 25 FF FF 
	ret		; 80411C48 C3 
;/
;/: SOURCE TIB #TIB @ ;


_SOURCE:
;/*	mov	rax,-0x08(rbp)	; 80411C49 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_TIB+0x5 (%rip),rax	; 80411C4D 
	DB 0x48,0x8D,0x5,0x84,0xFF,0xFF,0xFF
;/*	mov	(rax),rax	; 80411C54 
	DB 0x48,0x8B,0x0
;/*	lea	-0x08(rbp),rbp	; 80411C57 
	DB 0x48,0x8D,0x6D,0xF8
	call	_hashTIB	; 80411C5B E8 80 FF FF FF 
	call	_load	; 80411C60 E8 64 25 FF FF 
	ret		; 80411C65 C3 
;/
;/
;/: EndOfChunk ( -- flag )
;/ >IN @ SOURCE NIP < 0=        \ >IN 


_EndOfChunk:
;/*	mov	rax,-0x08(rbp)	; 80411C66 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80411C6A 
	DB 0x48,0x8D,0x5,0x3,0x2D,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411C71 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80411C75 E8 4F 25 FF FF 
	call	_SOURCE	; 80411C7A E8 CA FF FF FF 
	call	_NIP	; 80411C7F E8 88 29 FF FF 
	call	_less	; 80411C84 E8 FE 26 FF FF 
	call	_0equ	; 80411C89 E8 B4 26 FF FF 
;/;
	ret		; 80411C8E C3 
;/\ T\EOF
;/
;/: IsDelimiter ( char -- flag )
;/ BL 1+ < ;


_IsDelimiter:
;/*	mov	rax,-0x08(rbp)	; 80411C8F 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x20,eax	; 80411C93 
	DB 0xB8,0x20,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80411C98 
	DB 0x48,0x8D,0x6D,0xF8
	call	_CHARadd	; 80411C9C E8 DA 27 FF FF 
	call	_less	; 80411CA1 E8 E1 26 FF FF 
	ret		; 80411CA6 C3 
;/
;/: CharAddr ( -- c-addr )
;/  SOURCE DROP >IN @ +


_CharAddr:
	call	_SOURCE	; 80411CA7 E8 9D FF FF FF 
	call	_DgreatS	; 80411CAC E8 82 24 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80411CB1 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80411CB5 
	DB 0x48,0x8D,0x5,0xB8,0x2C,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411CBC 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80411CC0 E8 4 25 FF FF 
	call	_add	; 80411CC5 E8 51 27 FF FF 
;/;
	ret		; 80411CCA C3 
;/
;/: PeekChar ( -- char )
;/  CharAddr C@


_PeekChar:
	call	_CharAddr	; 80411CCB E8 D7 FF FF FF 
	call	_Cload	; 80411CD0 E8 F8 24 FF FF 
;/;
	ret		; 80411CD5 C3 
;/
;/: GetChar ( -- char flag )
;/ EndOfChunk


_GetChar:
	call	_EndOfChunk	; 80411CD6 E8 8B FF FF FF 
;/ IF 0 FALSE
	test	rax,rax	; 80411CDB 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80411CDE 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80411CE2 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_GetChar+0x31 	; 80411CE6 
	DB 0xF,0x84,0x1B,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 80411CEC 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80411CF0 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	mov	rax,-0x10(rbp)	; 80411CF5 
	DB 0x48,0x89,0x45,0xF0
;/*	mov	$0x0,eax	; 80411CF9 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x10(rbp),rbp	; 80411CFE 
	DB 0x48,0x8D,0x6D,0xF0
;/	ELSE PeekChar TRUE THEN ;
;/*	jmp	_GetChar+0x45 	; 80411D02 
	DB 0xE9,0x14,0x0,0x0,0x0
	call	_PeekChar	; 80411D07 E8 BF FF FF FF 
;/*	mov	rax,-0x08(rbp)	; 80411D0C 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0x1,rax	; 80411D10 
	DB 0x48,0xC7,0xC0,0xFF,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411D17 
	DB 0x48,0x8D,0x6D,0xF8
	ret		; 80411D1B C3 
;/
;/: OnDelimiter ( -- flag )
;/	GetChar SWAP IsDelimiter AND ;


_OnDelimiter:
	call	_GetChar	; 80411D1C E8 B5 FF FF FF 
	call	_SWAP	; 80411D21 E8 1C 28 FF FF 
	call	_IsDelimiter	; 80411D26 E8 64 FF FF FF 
	call	_AND	; 80411D2B E8 B2 26 FF FF 
	ret		; 80411D30 C3 
;/
;/: SkipDelimiters ( -- ) \ 
;/	BEGIN	OnDelimiter


_SkipDelimiters:
	call	_OnDelimiter	; 80411D31 E8 E6 FF FF FF 
;/	WHILE	>IN 1+!
	test	rax,rax	; 80411D36 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80411D39 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80411D3D 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_SkipDelimiters+0x2F 	; 80411D41 
	DB 0xF,0x84,0x19,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 80411D47 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80411D4B 
	DB 0x48,0x8D,0x5,0x22,0x2C,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411D52 
	DB 0x48,0x8D,0x6D,0xF8
	call	_1addsave	; 80411D56 E8 12 25 FF FF 
;/	REPEAT >IN @   >IN_WORD ! ;
;/*	jmp	_SkipDelimiters	; 80411D5B 
	DB 0xE9,0xD1,0xFF,0xFF,0xFF
;/*	mov	rax,-0x08(rbp)	; 80411D60 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80411D64 
	DB 0x48,0x8D,0x5,0x9,0x2C,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411D6B 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80411D6F E8 55 24 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80411D74 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x232 (%rip),rax	; 80411D78 
	DB 0x48,0x8D,0x5,0xFD,0x2B,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411D7F 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 80411D83 E8 78 24 FF FF 
	ret		; 80411D88 C3 
;/
;/: OnNotDelimiter ( -- flag )
;/  GetChar SWAP IsDelimiter 0= AND ;


_OnNotDelimiter:
	call	_GetChar	; 80411D89 E8 48 FF FF FF 
	call	_SWAP	; 80411D8E E8 AF 27 FF FF 
	call	_IsDelimiter	; 80411D93 E8 F7 FE FF FF 
	call	_0equ	; 80411D98 E8 A5 25 FF FF 
	call	_AND	; 80411D9D E8 40 26 FF FF 
	ret		; 80411DA2 C3 
;/
;/: SkipWord ( -- ) \ 
;/ BEGIN	OnNotDelimiter


_SkipWord:
	call	_OnNotDelimiter	; 80411DA3 E8 E1 FF FF FF 
;/ WHILE	>IN 1+!
	test	rax,rax	; 80411DA8 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80411DAB 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80411DAF 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_SkipWord+0x2F 	; 80411DB3 
	DB 0xF,0x84,0x19,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 80411DB9 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80411DBD 
	DB 0x48,0x8D,0x5,0xB0,0x2B,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411DC4 
	DB 0x48,0x8D,0x6D,0xF8
	call	_1addsave	; 80411DC8 E8 A0 24 FF FF 
;/ REPEAT ;
;/*	jmp	_SkipWord	; 80411DCD 
	DB 0xE9,0xD1,0xFF,0xFF,0xFF
	ret		; 80411DD2 C3 
;/
;/
;/: ParseWord ( -- c-addr u )
;/ CharAddr >IN @  SkipWord


_ParseWord:
	call	_CharAddr	; 80411DD3 E8 CF FE FF FF 
;/*	mov	rax,-0x08(rbp)	; 80411DD8 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80411DDC 
	DB 0x48,0x8D,0x5,0x91,0x2B,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411DE3 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80411DE7 E8 DD 23 FF FF 
	call	_SkipWord	; 80411DEC E8 B2 FF FF FF 
;/ >IN @ - NEGATE ;
;/*	mov	rax,-0x08(rbp)	; 80411DF1 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80411DF5 
	DB 0x48,0x8D,0x5,0x78,0x2B,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411DFC 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80411E00 E8 C4 23 FF FF 
	call	_sub	; 80411E05 E8 E 26 FF FF 
	call	_NEGATE	; 80411E0A E8 F2 25 FF FF 
	ret		; 80411E0F C3 
;/
;/: PSKIP ( char "ccc<char>" -- )
;/\ 
;/  BEGIN
;/    DUP GetChar >R = R> AND


_PSKIP:
	call	_DUP	; 80411E10 E8 13 27 FF FF 
	call	_GetChar	; 80411E15 E8 BC FE FF FF 
	Push	rax	; 80411E1A 50 
;/*	mov	0x00(rbp),rax	; 80411E1B 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80411E1F 
	DB 0x48,0x8D,0x6D,0x8
	call	_equ	; 80411E23 E8 12 25 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80411E28 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80411E2C 58 
;/*	lea	-0x08(rbp),rbp	; 80411E2D 
	DB 0x48,0x8D,0x6D,0xF8
	call	_AND	; 80411E31 E8 AC 25 FF FF 
;/  WHILE
	test	rax,rax	; 80411E36 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80411E39 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80411E3D 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_PSKIP+0x50 	; 80411E41 
	DB 0xF,0x84,0x19,0x0,0x0,0x0
;/    >IN 1+!
;/*	mov	rax,-0x08(rbp)	; 80411E47 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80411E4B 
	DB 0x48,0x8D,0x5,0x22,0x2B,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411E52 
	DB 0x48,0x8D,0x6D,0xF8
	call	_1addsave	; 80411E56 E8 12 24 FF FF 
;/  REPEAT DROP
;/*	jmp	_PSKIP	; 80411E5B 
	DB 0xE9,0xB0,0xFF,0xFF,0xFF
	call	_DgreatS	; 80411E60 E8 CE 22 FF FF 
;/;
	ret		; 80411E65 C3 
;/
;/: PARSE-NAME ( -- c-addr u )
;/  SkipDelimiters


_PARSEsubNAME:
	call	_SkipDelimiters	; 80411E66 E8 C6 FE FF FF 
;/  ParseWord
	call	_ParseWord	; 80411E6B E8 63 FF FF FF 
;/  >IN @ 1+ #TIB @ MIN >IN !   \ 
;/*	mov	rax,-0x08(rbp)	; 80411E70 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80411E74 
	DB 0x48,0x8D,0x5,0xF9,0x2A,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411E7B 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80411E7F E8 45 23 FF FF 
	call	_CHARadd	; 80411E84 E8 F2 25 FF FF 
	call	_hashTIB	; 80411E89 E8 52 FD FF FF 
	call	_load	; 80411E8E E8 36 23 FF FF 
	call	_MIN	; 80411E93 E8 61 24 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80411E98 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80411E9C 
	DB 0x48,0x8D,0x5,0xD1,0x2A,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411EA3 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 80411EA7 E8 54 23 FF FF 
;/;
	ret		; 80411EAC C3 
;/
;/: SkipUpTo ( char -- ) \ 
;/  BEGIN
;/    DUP GetChar >R <> R> AND


_SkipUpTo:
	call	_DUP	; 80411EAD E8 76 26 FF FF 
	call	_GetChar	; 80411EB2 E8 1F FE FF FF 
	Push	rax	; 80411EB7 50 
;/*	mov	0x00(rbp),rax	; 80411EB8 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80411EBC 
	DB 0x48,0x8D,0x6D,0x8
	call	_lessgreat	; 80411EC0 E8 D4 24 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80411EC5 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80411EC9 58 
;/*	lea	-0x08(rbp),rbp	; 80411ECA 
	DB 0x48,0x8D,0x6D,0xF8
	call	_AND	; 80411ECE E8 F 25 FF FF 
;/  WHILE
	test	rax,rax	; 80411ED3 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80411ED6 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80411EDA 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_SkipUpTo+0x50 	; 80411EDE 
	DB 0xF,0x84,0x19,0x0,0x0,0x0
;/    >IN 1+!
;/*	mov	rax,-0x08(rbp)	; 80411EE4 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80411EE8 
	DB 0x48,0x8D,0x5,0x85,0x2A,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411EEF 
	DB 0x48,0x8D,0x6D,0xF8
	call	_1addsave	; 80411EF3 E8 75 23 FF FF 
;/  REPEAT DROP
;/*	jmp	_SkipUpTo	; 80411EF8 
	DB 0xE9,0xB0,0xFF,0xFF,0xFF
	call	_DgreatS	; 80411EFD E8 31 22 FF FF 
;/;
	ret		; 80411F02 C3 
;/
;/: PARSE ( char "ccc<char>" -- c-addr u ) \ 94 CORE EXT
;/  CharAddr >IN @


_PARSE:
	call	_CharAddr	; 80411F03 E8 9F FD FF FF 
;/*	mov	rax,-0x08(rbp)	; 80411F08 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80411F0C 
	DB 0x48,0x8D,0x5,0x61,0x2A,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411F13 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80411F17 E8 AD 22 FF FF 
;/  ROT SkipUpTo
	call	_ROT	; 80411F1C E8 F0 26 FF FF 
	call	_SkipUpTo	; 80411F21 E8 87 FF FF FF 
;/  >IN @ - NEGATE
;/*	mov	rax,-0x08(rbp)	; 80411F26 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80411F2A 
	DB 0x48,0x8D,0x5,0x43,0x2A,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411F31 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80411F35 E8 8F 22 FF FF 
	call	_sub	; 80411F3A E8 D9 24 FF FF 
	call	_NEGATE	; 80411F3F E8 BD 24 FF FF 
;/  >IN 1+!
;/*	mov	rax,-0x08(rbp)	; 80411F44 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80411F48 
	DB 0x48,0x8D,0x5,0x25,0x2A,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80411F4F 
	DB 0x48,0x8D,0x6D,0xF8
	call	_1addsave	; 80411F53 E8 15 23 FF FF 
;/;
	ret		; 80411F58 C3 
;/
;/
;/: SEARCH-NFA1 ( c-addr u wid --- 0 | nfa )
;/	@


_SEARCHsubNFA1:
	call	_load	; 80411F59 E8 6B 22 FF FF 
;/	BEGIN   DUP
	call	_DUP	; 80411F5E E8 C5 25 FF FF 
;/	WHILE
	test	rax,rax	; 80411F63 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80411F66 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80411F6A 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_SEARCHsubNFA1+0x77 	; 80411F6E 
	DB 0xF,0x84,0x5C,0x0,0x0,0x0
;/	>R 2DUP	R@ COUNT COMPARE 0= 
	Push	rax	; 80411F74 50 
;/*	mov	0x00(rbp),rax	; 80411F75 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80411F79 
	DB 0x48,0x8D,0x6D,0x8
	call	_2DUP	; 80411F7D E8 AF 25 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80411F82 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	(rsp),rax	; 80411F86 
	DB 0x48,0x8B,0x4,0x24
;/*	lea	-0x08(rbp),rbp	; 80411F8A 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COUNT	; 80411F8E E8 2E 23 FF FF 
	call	_COMPARE	; 80411F93 E8 78 32 FF FF 
	call	_0equ	; 80411F98 E8 A5 23 FF FF 
;/		IF 2DROP R>
	test	rax,rax	; 80411F9D 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80411FA0 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80411FA4 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_SEARCHsubNFA1+0x64 	; 80411FA8 
	DB 0xF,0x84,0xF,0x0,0x0,0x0
	call	_2DROP	; 80411FAE E8 B9 25 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80411FB3 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80411FB7 58 
;/*	lea	-0x08(rbp),rbp	; 80411FB8 
	DB 0x48,0x8D,0x6D,0xF8
;/		BREAK
	ret		; 80411FBC C3 
;/ 	R> CDR
;/*	mov	rax,-0x08(rbp)	; 80411FBD 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80411FC1 58 
;/*	lea	-0x08(rbp),rbp	; 80411FC2 
	DB 0x48,0x8D,0x6D,0xF8
	call	_CDR	; 80411FC6 E8 A6 26 FF FF 
;/	REPEAT
;/*	jmp	_SEARCHsubNFA1+0x5 	; 80411FCB 
	DB 0xE9,0x8E,0xFF,0xFF,0xFF
;/	2DROP DROP 0 \ Not found.
	call	_2DROP	; 80411FD0 E8 97 25 FF FF 
	call	_DgreatS	; 80411FD5 E8 59 21 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80411FDA 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80411FDE 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80411FE3 
	DB 0x48,0x8D,0x6D,0xF8
;/;
	ret		; 80411FE7 C3 
;/
;/' SEARCH-NFA1 ->DEFER SEARCH-NFA


_SEARCHsubNFA:
	call	_DOVECT	; 80411FE8 E8 F 27 FF FF 
	DQ _SEARCHsubNFA1

;/
;/: SEARCH-WORDLIST1 ( c-addr u wid --- 0 | xt 1 xt -1)
;/\ Search the wordlist with address wid for the name c-addr u.
;/\ Return 0 if not found, the execution token xt and -1 for non-immediate
;/\ words and xt and 1 for immediate words.
;/        SEARCH-NFA DUP

_SEARCHsubWORDLIST1:
	call	_SEARCHsubNFA	; 80411FF5 E8 EE FF FF FF 
	call	_DUP	; 80411FFA E8 29 25 FF FF 
;/	IF	DUP NAME> SWAP
	test	rax,rax	; 80411FFF 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80412002 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80412006 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_SEARCHsubWORDLIST1+0x5D 	; 8041200A 
	DB 0xF,0x84,0x42,0x0,0x0,0x0
	call	_DUP	; 80412010 E8 13 25 FF FF 
	call	_NAMEgreat	; 80412015 E8 61 26 FF FF 
	call	_SWAP	; 8041201A E8 23 25 FF FF 
;/		NAME>F L@ 1 AND 1- 1 OR
	call	_NAMEgreatF	; 8041201F E8 5C 26 FF FF 
	call	_Lload	; 80412024 E8 9D 21 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412029 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x1,eax	; 8041202D 
	DB 0xB8,0x1,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80412032 
	DB 0x48,0x8D,0x6D,0xF8
	call	_AND	; 80412036 E8 A7 23 FF FF 
	call	_1sub	; 8041203B E8 4A 24 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412040 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x1,eax	; 80412044 
	DB 0xB8,0x1,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80412049 
	DB 0x48,0x8D,0x6D,0xF8
	call	_OR	; 8041204D E8 99 23 FF FF 
;/	THEN
;/
;/;
	ret		; 80412052 C3 
;/
;/' SEARCH-WORDLIST1 ->DEFER SEARCH-WORDLIST


_SEARCHsubWORDLIST:
	call	_DOVECT	; 80412053 E8 A4 26 FF FF 
	DQ _SEARCHsubWORDLIST1

;/
;/: SFIND ( addr len --- addr len 0| xt 1|xt -1 )
;/\ Search all word lists in the search order for the name in the
;/\ counted string at c-addr. If not found return the name address and 0.
;/\ If found return the execution token xt and -1 if the word is non-immediate
;/\ and 1 if the word is immediate.
;/\ ." SFIND=<"
;/  CONTEXT

_SFIND:
	call	_CONTEXT	; 80412060 E8 95 20 7F 0 
;/  BEGIN	DUP @ \ DUP H.
	call	_DUP	; 80412065 E8 BE 24 FF FF 
	call	_load	; 8041206A E8 5A 21 FF FF 
;/  WHILE	>R
	test	rax,rax	; 8041206F 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80412072 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80412076 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_SFIND+0x78 	; 8041207A 
	DB 0xF,0x84,0x58,0x0,0x0,0x0
	Push	rax	; 80412080 50 
;/*	mov	0x00(rbp),rax	; 80412081 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80412085 
	DB 0x48,0x8D,0x6D,0x8
;/	2DUP  R@  @  SEARCH-WORDLIST ?DUP
	call	_2DUP	; 80412089 E8 A3 24 FF FF 
;/*	mov	rax,-0x08(rbp)	; 8041208E 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	(rsp),rax	; 80412092 
	DB 0x48,0x8B,0x4,0x24
;/*	lea	-0x08(rbp),rbp	; 80412096 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 8041209A E8 2A 21 FF FF 
	call	_SEARCHsubWORDLIST	; 8041209F E8 AF FF FF FF 
	call	_queDUP	; 804120A4 E8 7A 24 FF FF 
;/	IF    RDROP 2NIP EXIT \ Exit if found.
	test	rax,rax	; 804120A9 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804120AC 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804120B0 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_SFIND+0x65 	; 804120B4 
	DB 0xF,0x84,0xB,0x0,0x0,0x0
;/*	lea	0x08(rsp),rsp	; 804120BA 
	DB 0x48,0x8D,0x64,0x24,0x8
	call	_2NIP	; 804120BF E8 C8 24 FF FF 
	ret		; 804120C4 C3 
;/	THEN
;/	R> CELL+
;/*	mov	rax,-0x08(rbp)	; 804120C5 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 804120C9 58 
;/*	lea	-0x08(rbp),rbp	; 804120CA 
	DB 0x48,0x8D,0x6D,0xF8
	call	_CELLadd	; 804120CE E8 9B 23 FF FF 
;/  REPEAT @
;/*	jmp	_SFIND+0x5 	; 804120D3 
	DB 0xE9,0x8D,0xFF,0xFF,0xFF
	call	_load	; 804120D8 E8 EC 20 FF FF 
;/;
	ret		; 804120DD C3 
;/
;/: ?STACK ( -> ) \ 
;/ SP@ SP0 @ SWAP U< IF SP0 @ SP! -4 THROW THEN


_queSTACK:
	call	_SPload	; 804120DE E8 B9 20 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804120E3 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_DOFIELD+0x14 (%rip),rax	; 804120E7 
	DB 0x48,0x8D,0x5,0xEA,0x2A,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804120EE 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 804120F2 E8 D2 20 FF FF 
	call	_SWAP	; 804120F7 E8 46 24 FF FF 
	call	_Uless	; 804120FC E8 BB 22 FF FF 
	test	rax,rax	; 80412101 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80412104 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80412108 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_queSTACK+0x61 	; 8041210C 
	DB 0xF,0x84,0x2D,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 80412112 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_DOFIELD+0x14 (%rip),rax	; 80412116 
	DB 0x48,0x8D,0x5,0xBB,0x2A,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041211D 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80412121 E8 A3 20 FF FF 
	call	_SPsave	; 80412126 E8 7D 20 FF FF 
;/*	mov	rax,-0x08(rbp)	; 8041212B 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0x4,rax	; 8041212F 
	DB 0x48,0xC7,0xC0,0xFC,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80412136 
	DB 0x48,0x8D,0x6D,0xF8
	call	_THROW	; 8041213A E8 C5 33 FF FF 
;/\  SP@ HERE - 0xE00 U< IF ." STACK: MAM" ABORT THEN
;/;
	ret		; 8041213F C3 
;/
;/' NOOP ->DEFER MEM_TST


_MEM_TST:
	call	_DOVECT	; 80412140 E8 B7 25 FF FF 
	DQ _NOOP

;/
;/: INTERPRET_ ( -> ) \ 
;/  SAVEERR? ON

_INTERPRET_:
;/*	mov	rax,-0x08(rbp)	; 8041214D 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x24A (%rip),rax	; 80412151 
	DB 0x48,0x8D,0x5,0x3C,0x28,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80412158 
	DB 0x48,0x8D,0x6D,0xF8
	call	_ON	; 8041215C E8 28 21 FF FF 
;/  BEGIN	PARSE-NAME \  ." <" 2DUP  TYPE ." >"
	call	_PARSEsubNAME	; 80412161 E8 0 FD FF FF 
;/  DUP
	call	_DUP	; 80412166 E8 BD 23 FF FF 
;/  WHILE
	test	rax,rax	; 8041216B 48 85 C0 
;/*	mov	0x00(rbp),rax	; 8041216E 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80412172 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_INTERPRET_+0x92 	; 80412176 
	DB 0xF,0x84,0x63,0x0,0x0,0x0
;/
;/ SFIND ?DUP
	call	_SFIND	; 8041217C E8 DF FE FF FF 
	call	_queDUP	; 80412181 E8 9D 23 FF FF 
;/	IF     STATE @ =
	test	rax,rax	; 80412186 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80412189 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8041218D 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_INTERPRET_+0x88 	; 80412191 
	DB 0xF,0x84,0x3E,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 80412197 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x12 (%rip),rax	; 8041219B 
	DB 0x48,0x8D,0x5,0xBA,0x25,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804121A2 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 804121A6 E8 1E 20 FF FF 
	call	_equ	; 804121AB E8 8A 21 FF FF 
;/		IF COMPILE,
	test	rax,rax	; 804121B0 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804121B3 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804121B7 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_INTERPRET_+0x7E 	; 804121BB 
	DB 0xF,0x84,0xA,0x0,0x0,0x0
	call	_COMPILEcom	; 804121C1 E8 E4 F1 FF FF 
;/		ELSE EXECUTE \ LLL @ IF ." {L}" 0 LLL ! THEN
;/*	jmp	_INTERPRET_+0x83 	; 804121C6 
	DB 0xE9,0x5,0x0,0x0,0x0
	call	_EXECUTE	; 804121CB E8 E4 1F FF FF 
;/		THEN
;/	ELSE 	?SLITERAL
;/*	jmp	_INTERPRET_+0x8D 	; 804121D0 
	DB 0xE9,0x5,0x0,0x0,0x0
	call	_queSLITERAL	; 804121D5 E8 F0 F8 FF FF 
;/        THEN
;/
;/\    ?STACK  MEM_TST \  CACHBREAK
;/  REPEAT 2DROP
;/*	jmp	_INTERPRET_+0x14 	; 804121DA 
	DB 0xE9,0x82,0xFF,0xFF,0xFF
	call	_2DROP	; 804121DF E8 88 23 FF FF 
;/;
	ret		; 804121E4 C3 
;/
;/
;/\ - &INTERPRET_ VARIABLE  &INTERPRET_
;/
;/\ CREATE IIII ' INTERPRET_ ,
;/\ CREATE &INTERPRET ' INTERPRET_ ,
;/\ : INTERPRET &INTERPRET PERFORM ;
;/' INTERPRET_ ->DEFER INTERPRET


_INTERPRET:
	call	_DOVECT	; 804121E5 E8 12 25 FF FF 
	DQ _INTERPRET_

;/
;/: .ID ( NFA -- )   COUNT TYPE ;

_dotID:
	call	_COUNT	; 804121F2 E8 CA 20 FF FF 
	call	_TYPE	; 804121F7 E8 50 2B FF FF 
	ret		; 804121FC C3 
;/
;/
;/VARIABLE _fp1

	DQ 0x0
	DB 0x0,0x0,0x0
;/VARIABLE _fp2
	DQ 0x0
;/VARIABLE _addr 4 ALLOT
	DQ 0x0
	DB 0x0,0x0,0x0,0x0
;/VARIABLE _dos
	DQ 0x0
;/CREATE LT  $0A0A0A0A ,
	DQ 0xA0A0A0A
;/
;/
;/: READ-LINE ( c-addr u1 fileid -- u2 flag ior ) \ 94 FILE
;/  OVER 0= IF DROP NIP TRUE 0 BREAK

_READsubLINE:
	call	_OVER	; 8041222C E8 68 23 FF FF 
	call	_0equ	; 80412231 E8 C 21 FF FF 
	test	rax,rax	; 80412236 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80412239 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8041223D 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_READsubLINE+0x3E 	; 80412241 
	DB 0xF,0x84,0x23,0x0,0x0,0x0
	call	_DgreatS	; 80412247 E8 E7 1E FF FF 
	call	_NIP	; 8041224C E8 BB 23 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412251 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0x1,rax	; 80412255 
	DB 0x48,0xC7,0xC0,0xFF,0xFF,0xFF,0xFF
;/*	mov	rax,-0x10(rbp)	; 8041225C 
	DB 0x48,0x89,0x45,0xF0
;/*	mov	$0x0,eax	; 80412260 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x10(rbp),rbp	; 80412265 
	DB 0x48,0x8D,0x6D,0xF0
	ret		; 80412269 C3 
;/  _dos 0!
;/*	mov	rax,-0x08(rbp)	; 8041226A 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_dotID+0x2A (%rip),rax	; 8041226E 
	DB 0x48,0x8D,0x5,0xA7,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80412275 
	DB 0x48,0x8D,0x6D,0xF8
	call	_OFF	; 80412279 E8 FB 1F FF FF 
;/  DUP >R
	call	_DUP	; 8041227E E8 A5 22 FF FF 
	Push	rax	; 80412283 50 
;/*	mov	0x00(rbp),rax	; 80412284 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80412288 
	DB 0x48,0x8D,0x6D,0x8
;/  FILE-POSITION IF 2DROP 0 0 THEN _fp1 ! _fp2 !
	call	_FILEsubPOSITION	; 8041228C E8 99 1E 7F 0 
	test	rax,rax	; 80412291 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80412294 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80412298 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_READsubLINE+0x91 	; 8041229C 
	DB 0xF,0x84,0x1B,0x0,0x0,0x0
	call	_2DROP	; 804122A2 E8 C5 22 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804122A7 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 804122AB 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	mov	rax,-0x10(rbp)	; 804122B0 
	DB 0x48,0x89,0x45,0xF0
;/*	mov	$0x0,eax	; 804122B4 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x10(rbp),rbp	; 804122B9 
	DB 0x48,0x8D,0x6D,0xF0
;/*	mov	rax,-0x08(rbp)	; 804122BD 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_dotID+0xE (%rip),rax	; 804122C1 
	DB 0x48,0x8D,0x5,0x38,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804122C8 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 804122CC E8 2F 1F FF FF 
;/*	mov	rax,-0x08(rbp)	; 804122D1 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_dotID+0x16 (%rip),rax	; 804122D5 
	DB 0x48,0x8D,0x5,0x2C,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804122DC 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 804122E0 E8 1B 1F FF FF 
;/\  1+ \ LTL @ +
;/  OVER _addr !
	call	_OVER	; 804122E5 E8 AF 22 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804122EA 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_dotID+0x1E (%rip),rax	; 804122EE 
	DB 0x48,0x8D,0x5,0x1B,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804122F5 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 804122F9 E8 2 1F FF FF 
;/  R@ READ-FILE   ?DUP  IF NIP RDROP 0 0 ROT EXIT THEN
;/*	mov	rax,-0x08(rbp)	; 804122FE 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	(rsp),rax	; 80412302 
	DB 0x48,0x8B,0x4,0x24
;/*	lea	-0x08(rbp),rbp	; 80412306 
	DB 0x48,0x8D,0x6D,0xF8
	call	_READsubFILE	; 8041230A E8 15 1E 7F 0 
	call	_queDUP	; 8041230F E8 F 22 FF FF 
	test	rax,rax	; 80412314 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80412317 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8041231B 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_READsubLINE+0x11F 	; 8041231F 
	DB 0xF,0x84,0x26,0x0,0x0,0x0
	call	_NIP	; 80412325 E8 E2 22 FF FF 
;/*	lea	0x08(rsp),rsp	; 8041232A 
	DB 0x48,0x8D,0x64,0x24,0x8
;/*	mov	rax,-0x08(rbp)	; 8041232F 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80412333 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	mov	rax,-0x10(rbp)	; 80412338 
	DB 0x48,0x89,0x45,0xF0
;/*	mov	$0x0,eax	; 8041233C 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x10(rbp),rbp	; 80412341 
	DB 0x48,0x8D,0x6D,0xF0
	call	_ROT	; 80412345 E8 C7 22 FF FF 
	ret		; 8041234A C3 
;/  DUP >R 0= IF RDROP RDROP 0 0 0 EXIT THEN \ были в конце файла
	call	_DUP	; 8041234B E8 D8 21 FF FF 
	Push	rax	; 80412350 50 
;/*	mov	0x00(rbp),rax	; 80412351 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80412355 
	DB 0x48,0x8D,0x6D,0x8
	call	_0equ	; 80412359 E8 E4 1F FF FF 
	test	rax,rax	; 8041235E 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80412361 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80412365 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_READsubLINE+0x16D 	; 80412369 
	DB 0xF,0x84,0x2A,0x0,0x0,0x0
;/*	lea	0x08(rsp),rsp	; 8041236F 
	DB 0x48,0x8D,0x64,0x24,0x8
;/*	lea	0x08(rsp),rsp	; 80412374 
	DB 0x48,0x8D,0x64,0x24,0x8
;/*	mov	rax,-0x08(rbp)	; 80412379 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 8041237D 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	mov	rax,-0x10(rbp)	; 80412382 
	DB 0x48,0x89,0x45,0xF0
;/*	mov	$0x0,eax	; 80412386 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	mov	rax,-0x18(rbp)	; 8041238B 
	DB 0x48,0x89,0x45,0xE8
;/*	mov	$0x0,eax	; 8041238F 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x18(rbp),rbp	; 80412394 
	DB 0x48,0x8D,0x6D,0xE8
	ret		; 80412398 C3 
;/  _addr @ R@
;/*	mov	rax,-0x08(rbp)	; 80412399 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_dotID+0x1E (%rip),rax	; 8041239D 
	DB 0x48,0x8D,0x5,0x6C,0xFE,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804123A4 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 804123A8 E8 1C 1E FF FF 
;/*	mov	rax,-0x08(rbp)	; 804123AD 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	(rsp),rax	; 804123B1 
	DB 0x48,0x8B,0x4,0x24
;/*	mov	rax,-0x10(rbp)	; 804123B5 
	DB 0x48,0x89,0x45,0xF0
;/
;/ LT 1 SEARCH
;/*	lea	_dotID+0x32 (%rip),rax	; 804123B9 
	DB 0x48,0x8D,0x5,0x64,0xFE,0xFF,0xFF
;/*	mov	rax,-0x18(rbp)	; 804123C0 
	DB 0x48,0x89,0x45,0xE8
;/*	mov	$0x1,eax	; 804123C4 
	DB 0xB8,0x1,0x0,0x0,0x0
;/*	lea	-0x18(rbp),rbp	; 804123C9 
	DB 0x48,0x8D,0x6D,0xE8
	call	_SEARCH	; 804123CD E8 AC 2F FF FF 
;/  IF   \ найден разделитель строк
	test	rax,rax	; 804123D2 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804123D5 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804123D9 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_READsubLINE+0x263 	; 804123DD 
	DB 0xF,0x84,0xAC,0x0,0x0,0x0
;/     OVER 1- C@ 13 = _dos !
	call	_OVER	; 804123E3 E8 B1 21 FF FF 
	call	_1sub	; 804123E8 E8 9D 20 FF FF 
	call	_Cload	; 804123ED E8 DB 1D FF FF 
;/*	mov	rax,-0x08(rbp)	; 804123F2 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xD,eax	; 804123F6 
	DB 0xB8,0xD,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804123FB 
	DB 0x48,0x8D,0x6D,0xF8
	call	_equ	; 804123FF E8 36 1F FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412404 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_dotID+0x2A (%rip),rax	; 80412408 
	DB 0x48,0x8D,0x5,0xD,0xFE,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041240F 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 80412413 E8 E8 1D FF FF 
;/     DROP _addr @ -     DUP   
	call	_DgreatS	; 80412418 E8 16 1D FF FF 
;/*	mov	rax,-0x08(rbp)	; 8041241D 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_dotID+0x1E (%rip),rax	; 80412421 
	DB 0x48,0x8D,0x5,0xE8,0xFD,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80412428 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 8041242C E8 98 1D FF FF 
	call	_sub	; 80412431 E8 E2 1F FF FF 
	call	_DUP	; 80412436 E8 ED 20 FF FF 
;/     1+ U>D _fp2 @ _fp1 @ D+
	call	_CHARadd	; 8041243B E8 3B 20 FF FF 
	call	_UgreatD	; 80412440 E8 8D 1E FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412445 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_dotID+0x16 (%rip),rax	; 80412449 
	DB 0x48,0x8D,0x5,0xB8,0xFD,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80412450 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80412454 E8 70 1D FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412459 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_dotID+0xE (%rip),rax	; 8041245D 
	DB 0x48,0x8D,0x5,0x9C,0xFD,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80412464 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80412468 E8 5C 1D FF FF 
	call	_Dadd	; 8041246D E8 B2 1F FF FF 
;/      RDROP R> REPOSITION-FILE DROP
;/*	lea	0x08(rsp),rsp	; 80412472 
	DB 0x48,0x8D,0x64,0x24,0x8
;/*	mov	rax,-0x08(rbp)	; 80412477 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 8041247B 58 
;/*	lea	-0x08(rbp),rbp	; 8041247C 
	DB 0x48,0x8D,0x6D,0xF8
	call	_REPOSITIONsubFILE	; 80412480 E8 AB 1C 7F 0 
	call	_DgreatS	; 80412485 E8 A9 1C FF FF 
;/  ELSE \ не найден разделитель строк
;/*	jmp	_READsubLINE+0x276 	; 8041248A 
	DB 0xE9,0x13,0x0,0x0,0x0
;/     2DROP
	call	_2DROP	; 8041248F E8 D8 20 FF FF 
;/     R>  RDROP  \ если строка прочитана не полностью - будет разрезана
;/*	mov	rax,-0x08(rbp)	; 80412494 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80412498 58 
;/*	lea	0x08(rsp),rsp	; 80412499 
	DB 0x48,0x8D,0x64,0x24,0x8
;/*	lea	-0x08(rbp),rbp	; 8041249E 
	DB 0x48,0x8D,0x6D,0xF8
;/  THEN
;/  _dos @ + 0 MAX
;/*	mov	rax,-0x08(rbp)	; 804124A2 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_dotID+0x2A (%rip),rax	; 804124A6 
	DB 0x48,0x8D,0x5,0x6F,0xFD,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804124AD 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 804124B1 E8 13 1D FF FF 
	call	_add	; 804124B6 E8 60 1F FF FF 
;/*	mov	rax,-0x08(rbp)	; 804124BB 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 804124BF 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804124C4 
	DB 0x48,0x8D,0x6D,0xF8
	call	_MAX	; 804124C8 E8 48 1E FF FF 
;/  TRUE 0
;/*	mov	rax,-0x08(rbp)	; 804124CD 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0x1,rax	; 804124D1 
	DB 0x48,0xC7,0xC0,0xFF,0xFF,0xFF,0xFF
;/*	mov	rax,-0x10(rbp)	; 804124D8 
	DB 0x48,0x89,0x45,0xF0
;/*	mov	$0x0,eax	; 804124DC 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x10(rbp),rbp	; 804124E1 
	DB 0x48,0x8D,0x6D,0xF0
;/;
	ret		; 804124E5 C3 
;/
;/CREATE FILE-BUFF $101 ALLOT

	DQ 0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
	DB 0x0
;/
;/: OPEN-FILE ( c-addr u fam -- fileid ior )
;/\ Открыть файл с именем, заданным строкой c-addr u, с методом доступа fam.
;/\ Смысл значения fam определен реализацией.
;/\ Если файл успешно открыт, ior ноль, fileid его идентификатор, и файл
;/\ позиционирован на начало.
;/\ Иначе ior - определенный реализацией код результата ввода/вывода,
;/\ и fileid неопределен.
;/  >R FILE-BUFF ASCII-Z  R>

_OPENsubFILE:
	Push	rax	; 804125E7 50 
;/*	mov	0x00(rbp),rax	; 804125E8 
	DB 0x48,0x8B,0x45,0x0
;/*	mov	rax,0x00(rbp)	; 804125EC 
	DB 0x48,0x89,0x45,0x0
;/*	lea	_READsubLINE+0x2BA (%rip),rax	; 804125F0 
	DB 0x48,0x8D,0x5,0xEF,0xFE,0xFF,0xFF
	call	_ASCIIsubZ	; 804125F7 E8 E5 30 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804125FC 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80412600 58 
;/*	lea	-0x08(rbp),rbp	; 80412601 
	DB 0x48,0x8D,0x6D,0xF8
;/  ZOPEN-FILE
	call	_ZOPENsubFILE	; 80412605 E8 32 1B 7F 0 
;/;
	ret		; 8041260A C3 
;/
;/: OPEN-FILE-SHARED ( c-addr u fam -- fileid ior )
;/  >R FILE-BUFF ASCII-Z  R>


_OPENsubFILEsubSHARED:
	Push	rax	; 8041260B 50 
;/*	mov	0x00(rbp),rax	; 8041260C 
	DB 0x48,0x8B,0x45,0x0
;/*	mov	rax,0x00(rbp)	; 80412610 
	DB 0x48,0x89,0x45,0x0
;/*	lea	_READsubLINE+0x2BA (%rip),rax	; 80412614 
	DB 0x48,0x8D,0x5,0xCB,0xFE,0xFF,0xFF
	call	_ASCIIsubZ	; 8041261B E8 C1 30 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412620 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80412624 58 
;/*	lea	-0x08(rbp),rbp	; 80412625 
	DB 0x48,0x8D,0x6D,0xF8
;/  ZOPEN-FILE-SHARED
	call	_ZOPENsubFILEsubSHARED	; 80412629 E8 14 1B 7F 0 
;/;
	ret		; 8041262E C3 
;/
;/: CREATE-FILE ( c-addr u fam -- fileid ior )
;/  >R FILE-BUFF ASCII-Z  R>


_CREATEsubFILE:
	Push	rax	; 8041262F 50 
;/*	mov	0x00(rbp),rax	; 80412630 
	DB 0x48,0x8B,0x45,0x0
;/*	mov	rax,0x00(rbp)	; 80412634 
	DB 0x48,0x89,0x45,0x0
;/*	lea	_READsubLINE+0x2BA (%rip),rax	; 80412638 
	DB 0x48,0x8D,0x5,0xA7,0xFE,0xFF,0xFF
	call	_ASCIIsubZ	; 8041263F E8 9D 30 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412644 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80412648 58 
;/*	lea	-0x08(rbp),rbp	; 80412649 
	DB 0x48,0x8D,0x6D,0xF8
;/  ZCREATE-FILE
	call	_ZCREATEsubFILE	; 8041264D E8 F6 1A 7F 0 
;/;
	ret		; 80412652 C3 
;/
;/: CREATE-FILE-SHARED ( c-addr u fam -- fileid ior )
;/  >R FILE-BUFF ASCII-Z  R>


_CREATEsubFILEsubSHARED:
	Push	rax	; 80412653 50 
;/*	mov	0x00(rbp),rax	; 80412654 
	DB 0x48,0x8B,0x45,0x0
;/*	mov	rax,0x00(rbp)	; 80412658 
	DB 0x48,0x89,0x45,0x0
;/*	lea	_READsubLINE+0x2BA (%rip),rax	; 8041265C 
	DB 0x48,0x8D,0x5,0x83,0xFE,0xFF,0xFF
	call	_ASCIIsubZ	; 80412663 E8 79 30 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412668 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 8041266C 58 
;/*	lea	-0x08(rbp),rbp	; 8041266D 
	DB 0x48,0x8D,0x6D,0xF8
;/  ZCREATE-FILE-SHARED
	call	_ZCREATEsubFILEsubSHARED	; 80412671 E8 D8 1A 7F 0 
;/;
	ret		; 80412676 C3 
;/
;/VARIABLE ID_SHIFT

	DQ 0x0
	DB 0x0
;/: ID_SHIFT@ ID_SHIFT @ ;

_ID_SHIFTload:
;/*	mov	rax,-0x08(rbp)	; 80412680 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_CREATEsubFILEsubSHARED+0x25 (%rip),rax	; 80412684 
	DB 0x48,0x8D,0x5,0xED,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041268B 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 8041268F E8 35 1B FF FF 
	ret		; 80412694 C3 
;/
;/\ : JKEY#  #JKEY >CPF WPF> ;
;/\ : GKEY#  JKEY#  DUP $200 AND ID_SHIFT ! $1FF AND ;
;/\ : GKEY?#  #GKEY? >CPF PF> ;
;/
;/0 VALUE UTT?


_UTTque:
	call	_DOVALUE	; 80412695 E8 4A 20 FF FF 

	DQ 0x0
;/
;/: CR_C	$D EMIT $A EMIT ;

_CR_C:
;/*	mov	rax,-0x08(rbp)	; 804126A2 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xD,eax	; 804126A6 
	DB 0xB8,0xD,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804126AB 
	DB 0x48,0x8D,0x6D,0xF8
	call	_EMIT	; 804126AF E8 37 26 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804126B4 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xA,eax	; 804126B8 
	DB 0xB8,0xA,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804126BD 
	DB 0x48,0x8D,0x6D,0xF8
	call	_EMIT	; 804126C1 E8 25 26 FF FF 
	ret		; 804126C6 C3 
;/
;/: ACCEPT0 ( C-ADDR +N -- +N' ) \ GET LINE FROM TERM'L
;/   OVER + 1- OVER      \ SA EA A


_ACCEPT0:
	call	_OVER	; 804126C7 E8 CD 1E FF FF 
	call	_add	; 804126CC E8 4A 1D FF FF 
	call	_1sub	; 804126D1 E8 B4 1D FF FF 
	call	_OVER	; 804126D6 E8 BE 1E FF FF 
;/   BEGIN
;/ KEY       \ SA EA A C
	call	_KEY	; 804126DB E8 E7 26 FF FF 
;/   DUP $D <>
	call	_DUP	; 804126E0 E8 43 1E FF FF 
;/*	mov	rax,-0x08(rbp)	; 804126E5 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xD,eax	; 804126E9 
	DB 0xB8,0xD,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804126EE 
	DB 0x48,0x8D,0x6D,0xF8
	call	_lessgreat	; 804126F2 E8 A2 1C FF FF 
;/  OVER $A <> AND
	call	_OVER	; 804126F7 E8 9D 1E FF FF 
;/*	mov	rax,-0x08(rbp)	; 804126FC 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xA,eax	; 80412700 
	DB 0xB8,0xA,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80412705 
	DB 0x48,0x8D,0x6D,0xF8
	call	_lessgreat	; 80412709 E8 8B 1C FF FF 
	call	_AND	; 8041270E E8 CF 1C FF FF 
;/  WHILE
	test	rax,rax	; 80412713 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80412716 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8041271A 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_ACCEPT0+0x232 	; 8041271E 
	DB 0xF,0x84,0xD5,0x1,0x0,0x0
;/       DUP 27 = IF  DROP DUP C@ EMIT  ELSE
	call	_DUP	; 80412724 E8 FF 1D FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412729 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x1B,eax	; 8041272D 
	DB 0xB8,0x1B,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80412732 
	DB 0x48,0x8D,0x6D,0xF8
	call	_equ	; 80412736 E8 FF 1B FF FF 
	test	rax,rax	; 8041273B 48 85 C0 
;/*	mov	0x00(rbp),rax	; 8041273E 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80412742 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_ACCEPT0+0x9E 	; 80412746 
	DB 0xF,0x84,0x19,0x0,0x0,0x0
	call	_DgreatS	; 8041274C E8 E2 19 FF FF 
	call	_DUP	; 80412751 E8 D2 1D FF FF 
	call	_Cload	; 80412756 E8 72 1A FF FF 
	call	_EMIT	; 8041275B E8 8B 25 FF FF 
;/*	jmp	_ACCEPT0+0x21E 	; 80412760 
	DB 0xE9,0x80,0x1,0x0,0x0
;/       DUP EMIT
	call	_DUP	; 80412765 E8 BE 1D FF FF 
	call	_EMIT	; 8041276A E8 7C 25 FF FF 
;/       DUP   8  = IF BL EMIT EMIT
	call	_DUP	; 8041276F E8 B4 1D FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412774 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x8,eax	; 80412778 
	DB 0xB8,0x8,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8041277D 
	DB 0x48,0x8D,0x6D,0xF8
	call	_equ	; 80412781 E8 B4 1B FF FF 
	test	rax,rax	; 80412786 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80412789 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8041278D 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_ACCEPT0+0x112 	; 80412791 
	DB 0xF,0x84,0x42,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 80412797 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x20,eax	; 8041279B 
	DB 0xB8,0x20,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804127A0 
	DB 0x48,0x8D,0x6D,0xF8
	call	_EMIT	; 804127A4 E8 42 25 FF FF 
	call	_EMIT	; 804127A9 E8 3D 25 FF FF 
;/                     2- >R OVER 1- R> UMAX ELSE
	call	_2sub	; 804127AE E8 D4 1C FF FF 
	Push	rax	; 804127B3 50 
;/*	mov	0x00(rbp),rax	; 804127B4 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804127B8 
	DB 0x48,0x8D,0x6D,0x8
	call	_OVER	; 804127BC E8 D8 1D FF FF 
	call	_1sub	; 804127C1 E8 C4 1C FF FF 
;/*	mov	rax,-0x08(rbp)	; 804127C6 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 804127CA 58 
;/*	lea	-0x08(rbp),rbp	; 804127CB 
	DB 0x48,0x8D,0x6D,0xF8
	call	_UMAX	; 804127CF E8 4F 1B FF FF 
;/*	jmp	_ACCEPT0+0x21E 	; 804127D4 
	DB 0xE9,0xC,0x1,0x0,0x0
;/       DUP   $7F  = IF BL EMIT EMIT
	call	_DUP	; 804127D9 E8 4A 1D FF FF 
;/*	mov	rax,-0x08(rbp)	; 804127DE 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x7F,eax	; 804127E2 
	DB 0xB8,0x7F,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804127E7 
	DB 0x48,0x8D,0x6D,0xF8
	call	_equ	; 804127EB E8 4A 1B FF FF 
	test	rax,rax	; 804127F0 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804127F3 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804127F7 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_ACCEPT0+0x17C 	; 804127FB 
	DB 0xF,0x84,0x42,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 80412801 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x20,eax	; 80412805 
	DB 0xB8,0x20,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8041280A 
	DB 0x48,0x8D,0x6D,0xF8
	call	_EMIT	; 8041280E E8 D8 24 FF FF 
	call	_EMIT	; 80412813 E8 D3 24 FF FF 
;/                     2- >R OVER 1- R> UMAX ELSE
	call	_2sub	; 80412818 E8 6A 1C FF FF 
	Push	rax	; 8041281D 50 
;/*	mov	0x00(rbp),rax	; 8041281E 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80412822 
	DB 0x48,0x8D,0x6D,0x8
	call	_OVER	; 80412826 E8 6E 1D FF FF 
	call	_1sub	; 8041282B E8 5A 1C FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412830 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80412834 58 
;/*	lea	-0x08(rbp),rbp	; 80412835 
	DB 0x48,0x8D,0x6D,0xF8
	call	_UMAX	; 80412839 E8 E5 1A FF FF 
;/*	jmp	_ACCEPT0+0x21E 	; 8041283E 
	DB 0xE9,0xA2,0x0,0x0,0x0
;/
;/       DUP 9  = IF  DROP DUP 8 SPACE
	call	_DUP	; 80412843 E8 E0 1C FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412848 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x9,eax	; 8041284C 
	DB 0xB8,0x9,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80412851 
	DB 0x48,0x8D,0x6D,0xF8
	call	_equ	; 80412855 E8 E0 1A FF FF 
	test	rax,rax	; 8041285A 48 85 C0 
;/*	mov	0x00(rbp),rax	; 8041285D 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80412861 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_ACCEPT0+0x214 	; 80412865 
	DB 0xF,0x84,0x70,0x0,0x0,0x0
	call	_DgreatS	; 8041286B E8 C3 18 FF FF 
	call	_DUP	; 80412870 E8 B3 1C FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412875 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x8,eax	; 80412879 
	DB 0xB8,0x8,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8041287E 
	DB 0x48,0x8D,0x6D,0xF8
	call	_SPACE	; 80412882 E8 7 27 FF FF 
;/                    >R OVER R>    \ SA EA SA A
	Push	rax	; 80412887 50 
;/*	mov	0x00(rbp),rax	; 80412888 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8041288C 
	DB 0x48,0x8D,0x6D,0x8
	call	_OVER	; 80412890 E8 4 1D FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412895 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80412899 58 
;/*	lea	-0x08(rbp),rbp	; 8041289A 
	DB 0x48,0x8D,0x6D,0xF8
;/                    TUCK  -   \ SA EA SA A-SA
	call	_TUCK	; 8041289E E8 1E 1D FF FF 
	call	_sub	; 804128A3 E8 70 1B FF FF 
;/                    8 / 1+ 8 * +  ELSE
;/*	mov	rax,-0x08(rbp)	; 804128A8 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x8,eax	; 804128AC 
	DB 0xB8,0x8,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804128B1 
	DB 0x48,0x8D,0x6D,0xF8
	call	_rsl	; 804128B5 E8 F2 1B FF FF 
	call	_CHARadd	; 804128BA E8 BC 1B FF FF 
;/*	mov	rax,-0x08(rbp)	; 804128BF 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x8,eax	; 804128C3 
	DB 0xB8,0x8,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804128C8 
	DB 0x48,0x8D,0x6D,0xF8
	call	_mul	; 804128CC E8 D2 1B FF FF 
	call	_add	; 804128D1 E8 45 1B FF FF 
;/*	jmp	_ACCEPT0+0x21E 	; 804128D6 
	DB 0xE9,0xA,0x0,0x0,0x0
;/	OVER  C! THEN THEN THEN   THEN
	call	_OVER	; 804128DB E8 B9 1C FF FF 
	call	_Csave	; 804128E0 E8 F0 18 FF FF 
;/	1+ OVER UMIN  \ SA EA A
	call	_CHARadd	; 804128E5 E8 91 1B FF FF 
	call	_OVER	; 804128EA E8 AA 1C FF FF 
	call	_UMIN	; 804128EF E8 13 1A FF FF 
;/   REPEAT                          \ SA EA A C
;/*	jmp	_ACCEPT0+0x14 	; 804128F4 
	DB 0xE9,0xE2,0xFD,0xFF,0xFF
;/
;/   DROP NIP SWAP -
	call	_DgreatS	; 804128F9 E8 35 18 FF FF 
	call	_NIP	; 804128FE E8 9 1D FF FF 
	call	_SWAP	; 80412903 E8 3A 1C FF FF 
	call	_sub	; 80412908 E8 B 1B FF FF 
;/
;/ CR ;
	call	_CR	; 8041290D E8 6C 24 FF FF 
	ret		; 80412912 C3 
;/
;/: ACCEPT1 ( c-addr +n1 -- +n2 ) \ 94
;/\ Ввести строку максимальной длины до +n1 символов.
;/\ Исключительная ситуация возникает, если +n1 0 или больше 32767.
;/\ Отображать символы по мере ввода.
;/\ Ввод прерывается, когда получен символ "конец строки".
;/\ Ничего не добавляется в строку.
;/\ +n2 - длина строки, записанной по адресу c-addr.
;/  H-STDIN READ-FILE DROP


_ACCEPT1:
;/*	mov	rax,-0x08(rbp)	; 80412913 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_HsubSTDIN+0x5 (%rip),rax	; 80412917 
	DB 0x48,0x8D,0x5,0xDF,0x22,0xFF,0xFF
;/*	mov	(rax),rax	; 8041291E 
	DB 0x48,0x8B,0x0
;/*	lea	-0x08(rbp),rbp	; 80412921 
	DB 0x48,0x8D,0x6D,0xF8
	call	_READsubFILE	; 80412925 E8 FA 17 7F 0 
	call	_DgreatS	; 8041292A E8 4 18 FF FF 
;/;
	ret		; 8041292F C3 
;/
;/' ACCEPT1 ->DEFER ACCEPT


_ACCEPT:
	call	_DOVECT	; 80412930 E8 C7 1D FF FF 
	DQ _ACCEPT1

;/
;/: QUERY	( -- )
;/	TIB 180 ACCEPT #TIB !

_QUERY:
;/*	mov	rax,-0x08(rbp)	; 8041293D 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_TIB+0x5 (%rip),rax	; 80412941 
	DB 0x48,0x8D,0x5,0x90,0xF2,0xFF,0xFF
;/*	mov	(rax),rax	; 80412948 
	DB 0x48,0x8B,0x0
;/*	mov	rax,-0x10(rbp)	; 8041294B 
	DB 0x48,0x89,0x45,0xF0
;/*	mov	$0xB4,eax	; 8041294F 
	DB 0xB8,0xB4,0x0,0x0,0x0
;/*	lea	-0x10(rbp),rbp	; 80412954 
	DB 0x48,0x8D,0x6D,0xF0
	call	_ACCEPT	; 80412958 E8 D3 FF FF FF 
	call	_hashTIB	; 8041295D E8 7E F2 FF FF 
	call	_save	; 80412962 E8 99 18 FF FF 
;/	0 >IN !  0 SOURCE + C! ;
;/*	mov	rax,-0x08(rbp)	; 80412967 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 8041296B 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	mov	rax,-0x10(rbp)	; 80412970 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80412974 
	DB 0x48,0x8D,0x5,0xF9,0x1F,0xFF,0xFF
;/*	lea	-0x10(rbp),rbp	; 8041297B 
	DB 0x48,0x8D,0x6D,0xF0
	call	_save	; 8041297F E8 7C 18 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412984 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80412988 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8041298D 
	DB 0x48,0x8D,0x6D,0xF8
	call	_SOURCE	; 80412991 E8 B3 F2 FF FF 
	call	_add	; 80412996 E8 80 1A FF FF 
	call	_Csave	; 8041299B E8 35 18 FF FF 
	ret		; 804129A0 C3 
;/
;/
;/: OK..  ." OK" CR ;


_OKdotdot:
	call	_cbigSdticcend	; 804129A1 E8 2D 25 FF FF 
	DB 0x2,0x4F,0x4B
	call	_TYPE	; 804129A9 E8 9E 23 FF FF 
	call	_CR	; 804129AE E8 CB 23 FF FF 
	ret		; 804129B3 C3 
;/' OK.. ->DEFER OK.


_OKdot:
	call	_DOVECT	; 804129B4 E8 43 1D FF FF 
	DQ _OKdotdot

;/
;/VARIABLE CURSTR
	DQ 0x0
	DB 0x0,0x0,0x0
;/
;/' NOOP ->DEFER <PRE>

_lessPREgreat:
	call	_DOVECT	; 804129CC E8 2B 1D FF FF 
	DQ _NOOP

;/
;/: FREFILL ( h -- flag )
;/  TIB TC/L ROT READ-LINE THROW

_FREFILL:
;/*	mov	rax,-0x08(rbp)	; 804129D9 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_TIB+0x5 (%rip),rax	; 804129DD 
	DB 0x48,0x8D,0x5,0xF4,0xF1,0xFF,0xFF
;/*	mov	(rax),rax	; 804129E4 
	DB 0x48,0x8B,0x0
;/*	mov	rax,-0x10(rbp)	; 804129E7 
	DB 0x48,0x89,0x45,0xF0
;/*	mov	$0x100,eax	; 804129EB 
	DB 0xB8,0x0,0x1,0x0,0x0
;/*	lea	-0x10(rbp),rbp	; 804129F0 
	DB 0x48,0x8D,0x6D,0xF0
	call	_ROT	; 804129F4 E8 18 1C FF FF 
	call	_READsubLINE	; 804129F9 E8 2E F8 FF FF 
	call	_THROW	; 804129FE E8 1 2B FF FF 
;/  SWAP
	call	_SWAP	; 80412A03 E8 3A 1B FF FF 
;/  #TIB !  0 >IN ! CURSTR 1+!
	call	_hashTIB	; 80412A08 E8 D3 F1 FF FF 
	call	_save	; 80412A0D E8 EE 17 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412A12 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80412A16 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	mov	rax,-0x10(rbp)	; 80412A1B 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80412A1F 
	DB 0x48,0x8D,0x5,0x4E,0x1F,0xFF,0xFF
;/*	lea	-0x10(rbp),rbp	; 80412A26 
	DB 0x48,0x8D,0x6D,0xF0
	call	_save	; 80412A2A E8 D1 17 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412A2F 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_OKdot+0x10 (%rip),rax	; 80412A33 
	DB 0x48,0x8D,0x5,0x8A,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80412A3A 
	DB 0x48,0x8D,0x6D,0xF8
	call	_1addsave	; 80412A3E E8 2A 18 FF FF 
;/  0 SOURCE + C!
;/*	mov	rax,-0x08(rbp)	; 80412A43 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80412A47 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80412A4C 
	DB 0x48,0x8D,0x6D,0xF8
	call	_SOURCE	; 80412A50 E8 F4 F1 FF FF 
	call	_add	; 80412A55 E8 C1 19 FF FF 
	call	_Csave	; 80412A5A E8 76 17 FF FF 
;/ DUP IF <PRE> THEN
	call	_DUP	; 80412A5F E8 C4 1A FF FF 
	test	rax,rax	; 80412A64 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80412A67 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80412A6B 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_FREFILL+0xA1 	; 80412A6F 
	DB 0xF,0x84,0x5,0x0,0x0,0x0
	call	_lessPREgreat	; 80412A75 E8 52 FF FF FF 
;/;
	ret		; 80412A7A C3 
;/
;/: TTIB TIB ;


_TTIB:
;/*	mov	rax,-0x08(rbp)	; 80412A7B 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_TIB+0x5 (%rip),rax	; 80412A7F 
	DB 0x48,0x8D,0x5,0x52,0xF1,0xFF,0xFF
;/*	mov	(rax),rax	; 80412A86 
	DB 0x48,0x8B,0x0
;/*	lea	-0x08(rbp),rbp	; 80412A89 
	DB 0x48,0x8D,0x6D,0xF8
	ret		; 80412A8D C3 
;/
;/: _FREFILL ( h -- flag )
;/ CR ." FREF="


__FREFILL:
	call	_CR	; 80412A8E E8 EB 22 FF FF 
	call	_cbigSdticcend	; 80412A93 E8 3B 24 FF FF 
	DB 0x5,0x46,0x52,0x45,0x46,0x3D
	call	_TYPE	; 80412A9E E8 A9 22 FF FF 
;/  TIB TC/L 2DUP H. H. CR
;/*	mov	rax,-0x08(rbp)	; 80412AA3 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_TIB+0x5 (%rip),rax	; 80412AA7 
	DB 0x48,0x8D,0x5,0x2A,0xF1,0xFF,0xFF
;/*	mov	(rax),rax	; 80412AAE 
	DB 0x48,0x8B,0x0
;/*	mov	rax,-0x10(rbp)	; 80412AB1 
	DB 0x48,0x89,0x45,0xF0
;/*	mov	$0x100,eax	; 80412AB5 
	DB 0xB8,0x0,0x1,0x0,0x0
;/*	lea	-0x10(rbp),rbp	; 80412ABA 
	DB 0x48,0x8D,0x6D,0xF0
	call	_2DUP	; 80412ABE E8 6E 1A FF FF 
	call	_Hdot	; 80412AC3 E8 43 DD FF FF 
	call	_Hdot	; 80412AC8 E8 3E DD FF FF 
	call	_CR	; 80412ACD E8 AC 22 FF FF 
;/ ROT
	call	_ROT	; 80412AD2 E8 3A 1B FF FF 
;/  ABORT
	call	_ABORT	; 80412AD7 E8 B6 2A FF FF 
;/ READ-LINE THROW
	call	_READsubLINE	; 80412ADC E8 4B F7 FF FF 
	call	_THROW	; 80412AE1 E8 1E 2A FF FF 
;/  SWAP
	call	_SWAP	; 80412AE6 E8 57 1A FF FF 
;/  #TIB !  0 >IN ! CURSTR 1+!
	call	_hashTIB	; 80412AEB E8 F0 F0 FF FF 
	call	_save	; 80412AF0 E8 B 17 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412AF5 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80412AF9 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	mov	rax,-0x10(rbp)	; 80412AFE 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80412B02 
	DB 0x48,0x8D,0x5,0x6B,0x1E,0xFF,0xFF
;/*	lea	-0x10(rbp),rbp	; 80412B09 
	DB 0x48,0x8D,0x6D,0xF0
	call	_save	; 80412B0D E8 EE 16 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412B12 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_OKdot+0x10 (%rip),rax	; 80412B16 
	DB 0x48,0x8D,0x5,0xA7,0xFE,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80412B1D 
	DB 0x48,0x8D,0x6D,0xF8
	call	_1addsave	; 80412B21 E8 47 17 FF FF 
;/  0 SOURCE + C!
;/*	mov	rax,-0x08(rbp)	; 80412B26 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80412B2A 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80412B2F 
	DB 0x48,0x8D,0x6D,0xF8
	call	_SOURCE	; 80412B33 E8 11 F1 FF FF 
	call	_add	; 80412B38 E8 DE 18 FF FF 
	call	_Csave	; 80412B3D E8 93 16 FF FF 
;/ DUP IF <PRE> THEN
	call	_DUP	; 80412B42 E8 E1 19 FF FF 
	test	rax,rax	; 80412B47 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80412B4A 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80412B4E 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	__FREFILL+0xCF 	; 80412B52 
	DB 0xF,0x84,0x5,0x0,0x0,0x0
	call	_lessPREgreat	; 80412B58 E8 6F FE FF FF 
;/;
	ret		; 80412B5D C3 
;/
;/T: REFILL ( -- flag ) \ 94 FILE EXT
;/  SOURCE-ID  0 > IF ( included text )


_REFILL:
;/*	mov	rax,-0x08(rbp)	; 80412B5E 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_SOURCEsubID+0x5 (%rip),rax	; 80412B62 
	DB 0x48,0x8D,0x5,0x62,0xF0,0xFF,0xFF
;/*	mov	(rax),rax	; 80412B69 
	DB 0x48,0x8B,0x0
;/*	mov	rax,-0x10(rbp)	; 80412B6C 
	DB 0x48,0x89,0x45,0xF0
;/*	mov	$0x0,eax	; 80412B70 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x10(rbp),rbp	; 80412B75 
	DB 0x48,0x8D,0x6D,0xF0
	call	_great	; 80412B79 E8 F7 17 FF FF 
	test	rax,rax	; 80412B7E 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80412B81 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80412B85 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_REFILL+0x49 	; 80412B89 
	DB 0xF,0x84,0x18,0x0,0x0,0x0
;/  SOURCE-ID
;/*	mov	rax,-0x08(rbp)	; 80412B8F 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_SOURCEsubID+0x5 (%rip),rax	; 80412B93 
	DB 0x48,0x8D,0x5,0x31,0xF0,0xFF,0xFF
;/*	mov	(rax),rax	; 80412B9A 
	DB 0x48,0x8B,0x0
;/*	lea	-0x08(rbp),rbp	; 80412B9D 
	DB 0x48,0x8D,0x6D,0xF8
;/ FREFILL
	call	_FREFILL	; 80412BA1 E8 33 FE FF FF 
;/  EXIT  THEN
	ret		; 80412BA6 C3 
;/  QUERY TRUE
	call	_QUERY	; 80412BA7 E8 91 FD FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412BAC 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0x1,rax	; 80412BB0 
	DB 0x48,0xC7,0xC0,0xFF,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80412BB7 
	DB 0x48,0x8D,0x6D,0xF8
;/;
	ret		; 80412BBB C3 
;/
;/: EVALUATE ( i*x c-addr u -- j*x ) \ 94
;/  SOURCE-ID >R SOURCE 2>R >IN @ >R


_EVALUATE:
;/*	mov	rax,-0x08(rbp)	; 80412BBC 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_SOURCEsubID+0x5 (%rip),rax	; 80412BC0 
	DB 0x48,0x8D,0x5,0x4,0xF0,0xFF,0xFF
;/*	mov	(rax),rax	; 80412BC7 
	DB 0x48,0x8B,0x0
	Push	rax	; 80412BCA 50 
;/*	mov	-0x08(rbp),rax	; 80412BCB 
	DB 0x48,0x8B,0x45,0xF8
	call	_SOURCE	; 80412BCF E8 75 F0 FF FF 
	call	_2greatR	; 80412BD4 E8 B4 15 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412BD9 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80412BDD 
	DB 0x48,0x8D,0x5,0x90,0x1D,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80412BE4 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80412BE8 E8 DC 15 FF FF 
	Push	rax	; 80412BED 50 
;/*	mov	0x00(rbp),rax	; 80412BEE 
	DB 0x48,0x8B,0x45,0x0
;/*	mov	rax,0x00(rbp)	; 80412BF2 
	DB 0x48,0x89,0x45,0x0
;/  -1 TO SOURCE-ID
;/*	movq	$-0x1,rax	; 80412BF6 
	DB 0x48,0xC7,0xC0,0xFF,0xFF,0xFF,0xFF
;/*	mov	rax,-0x08(rbp)	; 80412BFD 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_SOURCEsubID+0x5 (%rip),rax	; 80412C01 
	DB 0x48,0x8D,0x5,0xC3,0xEF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80412C08 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 80412C0C E8 EF 15 FF FF 
;/  SOURCE! >IN 0!
	call	_SOURCEsave	; 80412C11 E8 F F0 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412C16 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80412C1A 
	DB 0x48,0x8D,0x5,0x53,0x1D,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80412C21 
	DB 0x48,0x8D,0x6D,0xF8
	call	_OFF	; 80412C25 E8 4F 16 FF FF 
;/    ['] INTERPRET CATCH
;/*	mov	rax,-0x08(rbp)	; 80412C2A 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_INTERPRET(%rip),rax	; 80412C2E 
	DB 0x48,0x8D,0x5,0xB0,0xF5,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80412C35 
	DB 0x48,0x8D,0x6D,0xF8
	call	_CATCH	; 80412C39 E8 59 28 FF FF 
;/  R> >IN ! 2R> SOURCE! R> TO SOURCE-ID
;/*	mov	rax,-0x08(rbp)	; 80412C3E 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80412C42 58 
;/*	mov	rax,-0x10(rbp)	; 80412C43 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 80412C47 
	DB 0x48,0x8D,0x5,0x26,0x1D,0xFF,0xFF
;/*	lea	-0x10(rbp),rbp	; 80412C4E 
	DB 0x48,0x8D,0x6D,0xF0
	call	_save	; 80412C52 E8 A9 15 FF FF 
	call	_2Rgreat	; 80412C57 E8 F9 14 FF FF 
	call	_SOURCEsave	; 80412C5C E8 C4 EF FF FF 
;/*	mov	rax,-0x08(rbp)	; 80412C61 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80412C65 58 
;/*	mov	rax,-0x10(rbp)	; 80412C66 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_SOURCEsubID+0x5 (%rip),rax	; 80412C6A 
	DB 0x48,0x8D,0x5,0x5A,0xEF,0xFF,0xFF
;/*	lea	-0x10(rbp),rbp	; 80412C71 
	DB 0x48,0x8D,0x6D,0xF0
	call	_save	; 80412C75 E8 86 15 FF FF 
;/  THROW
	call	_THROW	; 80412C7A E8 85 28 FF FF 
;/;
	ret		; 80412C7F C3 
;/
;/: FQUIT
;/ BEGIN  REFILL


_FQUIT:
	call	_REFILL	; 80412C80 E8 D9 FE FF FF 
;/ WHILE  INTERPRET
	test	rax,rax	; 80412C85 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80412C88 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80412C8C 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_FQUIT+0x20 	; 80412C90 
	DB 0xF,0x84,0xA,0x0,0x0,0x0
	call	_INTERPRET	; 80412C96 E8 4A F5 FF FF 
;/ REPEAT ;
;/*	jmp	_FQUIT	; 80412C9B 
	DB 0xE9,0xE0,0xFF,0xFF,0xFF
	ret		; 80412CA0 C3 
;/
;/: QUIT
;/ BEGIN  REFILL


_QUIT:
	call	_REFILL	; 80412CA1 E8 B8 FE FF FF 
;/ WHILE  INTERPRET OK.
	test	rax,rax	; 80412CA6 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80412CA9 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80412CAD 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_QUIT+0x25 	; 80412CB1 
	DB 0xF,0x84,0xF,0x0,0x0,0x0
	call	_INTERPRET	; 80412CB7 E8 29 F5 FF FF 
	call	_OKdot	; 80412CBC E8 F3 FC FF FF 
;/ REPEAT ;
;/*	jmp	_QUIT	; 80412CC1 
	DB 0xE9,0xDB,0xFF,0xFF,0xFF
	ret		; 80412CC6 C3 
;/
;/T: ] STATE ON ;


_yc:
;/*	mov	rax,-0x08(rbp)	; 80412CC7 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x12 (%rip),rax	; 80412CCB 
	DB 0x48,0x8D,0x5,0x8A,0x1A,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80412CD2 
	DB 0x48,0x8D,0x6D,0xF8
	call	_ON	; 80412CD6 E8 AE 15 FF FF 
	ret		; 80412CDB C3 
;/T: [ STATE OFF ; IMMEDIATE


_xc:
;/*	mov	rax,-0x08(rbp)	; 80412CDC 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x12 (%rip),rax	; 80412CE0 
	DB 0x48,0x8D,0x5,0x75,0x1A,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80412CE7 
	DB 0x48,0x8D,0x6D,0xF8
	call	_OFF	; 80412CEB E8 89 15 FF FF 
	ret		; 80412CF0 C3 
;/
;/ VARIABLE BYE_FLG

	DQ 0x0
	DB 0x0,0x0,0x0
;/
;/\ DP><DDP
;/
;/444 CONSTANT  CFNAME_SIZE
;/ CREATE CURFILENAME 0 , CFNAME_SIZE 255 + ALLOT
	DQ 0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
	DB 0x0,0x0,0x0
;/ CREATE ERRFILENAME 0 , CFNAME_SIZE 255 + ALLOT
	DQ 0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
	DB 0x0
	DB 0x0,0x0
;/
;/\ DP><DDP
;/
;/: SAVEERR
;/	DUP SAVEERR? @ AND

_SAVEERR:
	call	_DUP	; 80413282 E8 A1 12 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413287 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x24A (%rip),rax	; 8041328B 
	DB 0x48,0x8D,0x5,0x2,0x17,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413292 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80413296 E8 2E F FF FF 
	call	_AND	; 8041329B E8 42 11 FF FF 
;/	IF	SOURCE ERRTIB $! >IN_WORD @ ER>IN !
	test	rax,rax	; 804132A0 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804132A3 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804132A7 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_SAVEERR+0xF6 	; 804132AB 
	DB 0xF,0x84,0xC7,0x0,0x0,0x0
	call	_SOURCE	; 804132B1 E8 93 E9 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804132B6 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x12A (%rip),rax	; 804132BA 
	DB 0x48,0x8D,0x5,0xB3,0x15,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804132C1 
	DB 0x48,0x8D,0x6D,0xF8
	call	_dolsave	; 804132C5 E8 5A 1E FF FF 
;/*	mov	rax,-0x08(rbp)	; 804132CA 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x232 (%rip),rax	; 804132CE 
	DB 0x48,0x8D,0x5,0xA7,0x16,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804132D5 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 804132D9 E8 EB E FF FF 
;/*	mov	rax,-0x08(rbp)	; 804132DE 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x23A (%rip),rax	; 804132E2 
	DB 0x48,0x8D,0x5,0x9B,0x16,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804132E9 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 804132ED E8 E F FF FF 
;/		SOURCE-ID ERR&S-ID ! CURSTR @ ERR-LINE ! SAVEERR? OFF
;/*	mov	rax,-0x08(rbp)	; 804132F2 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_SOURCEsubID+0x5 (%rip),rax	; 804132F6 
	DB 0x48,0x8D,0x5,0xCE,0xE8,0xFF,0xFF
;/*	mov	(rax),rax	; 804132FD 
	DB 0x48,0x8B,0x0
;/*	mov	rax,-0x10(rbp)	; 80413300 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_UNLOOP+0x242 (%rip),rax	; 80413304 
	DB 0x48,0x8D,0x5,0x81,0x16,0xFF,0xFF
;/*	lea	-0x10(rbp),rbp	; 8041330B 
	DB 0x48,0x8D,0x6D,0xF0
	call	_save	; 8041330F E8 EC E FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413314 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_OKdot+0x10 (%rip),rax	; 80413318 
	DB 0x48,0x8D,0x5,0xA5,0xF6,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041331F 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80413323 E8 A1 E FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413328 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x252 (%rip),rax	; 8041332C 
	DB 0x48,0x8D,0x5,0x69,0x16,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413333 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 80413337 E8 C4 E FF FF 
;/*	mov	rax,-0x08(rbp)	; 8041333C 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x24A (%rip),rax	; 80413340 
	DB 0x48,0x8D,0x5,0x4D,0x16,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413347 
	DB 0x48,0x8D,0x6D,0xF8
	call	_OFF	; 8041334B E8 29 F FF FF 
;/		CURFILENAME COUNT ERRFILENAME $!
;/*	mov	rax,-0x08(rbp)	; 80413350 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_xc+0x20 (%rip),rax	; 80413354 
	DB 0x48,0x8D,0x5,0xA1,0xF9,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041335B 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COUNT	; 8041335F E8 5D F FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413364 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_xc+0x2E3 (%rip),rax	; 80413368 
	DB 0x48,0x8D,0x5,0x50,0xFC,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041336F 
	DB 0x48,0x8D,0x6D,0xF8
	call	_dolsave	; 80413373 E8 AC 1D FF FF 
;/	THEN
;/;
	ret		; 80413378 C3 
;/
;/VARIABLE CCOUT&OUTPUT

	DQ 0x0
	DB 0x0,0x0,0x0
;/VARIABLE CCOUTV_EMIT
	DQ 0x0
;/VARIABLE CCOUTV_TYPE
	DQ 0x0
;/
;/0 VALUE CCOUT_#

_CCOUT_hash:
	call	_DOVALUE	; 80413394 E8 4B 13 FF FF 

	DQ 0x0
;/
;/: ERROR_DO1
;/
;/	DUP 0= IF DROP BREAK

_ERROR_DO1:
	call	_DUP	; 804133A1 E8 82 11 FF FF 
	call	_0equ	; 804133A6 E8 97 F FF FF 
	test	rax,rax	; 804133AB 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804133AE 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804133B2 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_ERROR_DO1+0x21 	; 804133B6 
	DB 0xF,0x84,0x6,0x0,0x0,0x0
	call	_DgreatS	; 804133BC E8 72 D FF FF 
	ret		; 804133C1 C3 
;/	SAVEERR
	call	_SAVEERR	; 804133C2 E8 BB FE FF FF 
;/	CR ERRTIB COUNT TYPE CR
	call	_CR	; 804133C7 E8 B2 19 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804133CC 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x12A (%rip),rax	; 804133D0 
	DB 0x48,0x8D,0x5,0x9D,0x14,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804133D7 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COUNT	; 804133DB E8 E1 E FF FF 
	call	_TYPE	; 804133E0 E8 67 19 FF FF 
	call	_CR	; 804133E5 E8 94 19 FF FF 
;/\ ER>IN @ BEGIN SPACE 1- DUP 0 MAX 0= UNTIL
;/	ERRTIB 1+ ER>IN @ $3F AND 0
;/*	mov	rax,-0x08(rbp)	; 804133EA 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x12A (%rip),rax	; 804133EE 
	DB 0x48,0x8D,0x5,0x7F,0x14,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804133F5 
	DB 0x48,0x8D,0x6D,0xF8
	call	_CHARadd	; 804133F9 E8 7D 10 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804133FE 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x23A (%rip),rax	; 80413402 
	DB 0x48,0x8D,0x5,0x7B,0x15,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413409 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 8041340D E8 B7 D FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413412 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x3F,eax	; 80413416 
	DB 0xB8,0x3F,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8041341B 
	DB 0x48,0x8D,0x6D,0xF8
	call	_AND	; 8041341F E8 BE F FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413424 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80413428 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8041342D 
	DB 0x48,0x8D,0x6D,0xF8
;/   ?DO COUNT 9 = IF 9 EMIT ELSE SPACE THEN  LOOP DROP
	call	_cbigqueDOcend	; 80413431 E8 D4 12 FF FF 
	DQ _ERROR_DO1+0xEE 
	call	_COUNT	; 8041343E E8 7E E FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413443 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x9,eax	; 80413447 
	DB 0xB8,0x9,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8041344C 
	DB 0x48,0x8D,0x6D,0xF8
	call	_equ	; 80413450 E8 E5 E FF FF 
	test	rax,rax	; 80413455 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80413458 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8041345C 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_ERROR_DO1+0xDC 	; 80413460 
	DB 0xF,0x84,0x17,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 80413466 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x9,eax	; 8041346A 
	DB 0xB8,0x9,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8041346F 
	DB 0x48,0x8D,0x6D,0xF8
	call	_EMIT	; 80413473 E8 73 18 FF FF 
;/*	jmp	_ERROR_DO1+0xE1 	; 80413478 
	DB 0xE9,0x5,0x0,0x0,0x0
	call	_SPACE	; 8041347D E8 C 1B FF FF 
;/*	inc	r14	; 80413482 
	DB 0x49,0xFF,0xC6
;/*	inc	r15	; 80413485 
	DB 0x49,0xFF,0xC7
	jNo	_ERROR_DO1+0x9D 	; 80413488 71 B4 
	pop	r14	; 8041348A 41 5E 
	pop	r15	; 8041348C 41 5F 
	pop	rcx	; 8041348E 59 
	call	_DgreatS	; 8041348F E8 9F C FF FF 
;/ ." ^" \ DROP
	call	_cbigSdticcend	; 80413494 E8 3A 1A FF FF 
	DB 0x1,0x5E
	call	_TYPE	; 8041349B E8 AC 18 FF FF 
;/	CR ." ERR=" . 
	call	_CR	; 804134A0 E8 D9 18 FF FF 
	call	_cbigSdticcend	; 804134A5 E8 29 1A FF FF 
	DB 0x4,0x45,0x52,0x52,0x3D
	call	_TYPE	; 804134AF E8 98 18 FF FF 
	call	_dot	; 804134B4 E8 FE D0 FF FF 
;/	CR  SP0 @ SP!   STATE 0!
	call	_CR	; 804134B9 E8 C0 18 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804134BE 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_DOFIELD+0x14 (%rip),rax	; 804134C2 
	DB 0x48,0x8D,0x5,0xF,0x17,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804134C9 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 804134CD E8 F7 C FF FF 
	call	_SPsave	; 804134D2 E8 D1 C FF FF 
;/*	mov	rax,-0x08(rbp)	; 804134D7 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x12 (%rip),rax	; 804134DB 
	DB 0x48,0x8D,0x5,0x7A,0x12,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804134E2 
	DB 0x48,0x8D,0x6D,0xF8
	call	_OFF	; 804134E6 E8 8E D FF FF 
;/;
	ret		; 804134EB C3 
;/
;/' ERROR_DO1 ->DEFER ERROR_DO


_ERROR_DO:
	call	_DOVECT	; 804134EC E8 B 12 FF FF 
	DQ _ERROR_DO1

;/
;/: MAIN_CYCLE
;/ BEGIN	[COMPILE] [

_MAIN_CYCLE:
	call	_xc	; 804134F9 E8 DE F7 FF FF 
;/	&?MINUS 0!
;/*	mov	rax,-0x08(rbp)	; 804134FE 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_rslSTRING+0x2A (%rip),rax	; 80413502 
	DB 0x48,0x8D,0x5,0x87,0xD8,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413509 
	DB 0x48,0x8D,0x6D,0xF8
	call	_OFF	; 8041350D E8 67 D FF FF 
;/	['] QUIT CATCH
;/*	mov	rax,-0x08(rbp)	; 80413512 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_QUIT(%rip),rax	; 80413516 
	DB 0x48,0x8D,0x5,0x84,0xF7,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041351D 
	DB 0x48,0x8D,0x6D,0xF8
	call	_CATCH	; 80413521 E8 71 1F FF FF 
;/	ERROR_DO
	call	_ERROR_DO	; 80413526 E8 C1 FF FF FF 
;/ AGAIN
;/*	jmp	_MAIN_CYCLE	; 8041352B 
	DB 0xE9,0xC9,0xFF,0xFF,0xFF
;/;
	ret		; 80413530 C3 
;/
;/T: ' PARSE-NAME SFIND 0= IF -13 THROW THEN  ; \ ???????


_tic:
	call	_PARSEsubNAME	; 80413531 E8 30 E9 FF FF 
	call	_SFIND	; 80413536 E8 25 EB FF FF 
	call	_0equ	; 8041353B E8 2 E FF FF 
	test	rax,rax	; 80413540 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80413543 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80413547 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_tic+0x34 	; 8041354B 
	DB 0xF,0x84,0x14,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 80413551 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0xD,rax	; 80413555 
	DB 0x48,0xC7,0xC0,0xF3,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041355C 
	DB 0x48,0x8D,0x6D,0xF8
	call	_THROW	; 80413560 E8 9F 1F FF FF 
	ret		; 80413565 C3 
;/
;/T: ['] '  LIT, ; IMMEDIATE


_xcticyc:
	call	_tic	; 80413566 E8 C6 FF FF FF 
	call	_LITcom	; 8041356B E8 CB DC FF FF 
	ret		; 80413570 C3 
;/
;/: CHAR ( "<spaces>name" -- char ) \ 94
;/ PARSE-NAME DROP C@ ;


_CHAR:
	call	_PARSEsubNAME	; 80413571 E8 F0 E8 FF FF 
	call	_DgreatS	; 80413576 E8 B8 B FF FF 
	call	_Cload	; 8041357B E8 4D C FF FF 
	ret		; 80413580 C3 
;/
;/: >S, ( addr u -- addr addr1 u )
;/  DP @ SWAP DUP ALLOT ;


_greatScom:
;/*	mov	rax,-0x08(rbp)	; 80413581 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_HsubSTDERR+0x16 (%rip),rax	; 80413585 
	DB 0x48,0x8D,0x5,0x9C,0x16,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041358C 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80413590 E8 34 C FF FF 
	call	_SWAP	; 80413595 E8 A8 F FF FF 
	call	_DUP	; 8041359A E8 89 F FF FF 
	call	_ALLOT	; 8041359F E8 A9 16 FF FF 
	ret		; 804135A4 C3 
;/
;/T: S, ( addr u -- )
;/  >S, CMOVE ;


_Scom:
	call	_greatScom	; 804135A5 E8 D7 FF FF FF 
	call	_CMOVE	; 804135AA E8 1E 11 FF FF 
	ret		; 804135AF C3 
;/
;/: >S", ( addr u -- addr addr1 u ) 
;/ DUP C, >S,   ;


_greatSdticcom:
	call	_DUP	; 804135B0 E8 73 F FF FF 
	call	_Ccom	; 804135B5 E8 14 17 FF FF 
	call	_greatScom	; 804135BA E8 C2 FF FF FF 
	ret		; 804135BF C3 
;/
;/T: S", ( addr u -- ) 
;/  >S", CMOVE ;


_Sdticcom:
	call	_greatSdticcom	; 804135C0 E8 EB FF FF FF 
	call	_CMOVE	; 804135C5 E8 3 11 FF FF 
	ret		; 804135CA C3 
;/
;/
;/
;/T: SLIT, ( adr len -- [ adr len ] )
;/	['] (S") _COMPILE, S",


_SLITcom:
;/*	mov	rax,-0x08(rbp)	; 804135CB 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_cbigSdticcend(%rip),rax	; 804135CF 
	DB 0x48,0x8D,0x5,0xFD,0x18,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804135D6 
	DB 0x48,0x8D,0x6D,0xF8
	call	__COMPILEcom	; 804135DA E8 97 DD FF FF 
	call	_Sdticcom	; 804135DF E8 DC FF FF FF 
;/;
	ret		; 804135E4 C3 
;/
;/T: ZSLIT, ( adr len -- [ adr len ] )
;/	['] (Z") _COMPILE, S", 0 C,


_ZSLITcom:
;/*	mov	rax,-0x08(rbp)	; 804135E5 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_cbigZdticcend(%rip),rax	; 804135E9 
	DB 0x48,0x8D,0x5,0x5,0x19,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804135F0 
	DB 0x48,0x8D,0x6D,0xF8
	call	__COMPILEcom	; 804135F4 E8 7D DD FF FF 
	call	_Sdticcom	; 804135F9 E8 C2 FF FF FF 
;/*	mov	rax,-0x08(rbp)	; 804135FE 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80413602 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413607 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 8041360B E8 BE 16 FF FF 
;/;
	ret		; 80413610 C3 
;/
;/: >SYSPAD	\ caddr len -- caddr' len
;/\ *G Copy a string to *\fo{SYSPAD} and return the new string.
;/  DUP >R NEWSYSPADGET TUCK R@ MOVE R>  ;


_greatSYSPAD:
	call	_DUP	; 80413611 E8 12 F FF FF 
	Push	rax	; 80413616 50 
;/*	mov	0x00(rbp),rax	; 80413617 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8041361B 
	DB 0x48,0x8D,0x6D,0x8
	call	_NEWSYSPADGET	; 8041361F E8 6F 21 FF FF 
	call	_TUCK	; 80413624 E8 98 F FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413629 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	(rsp),rax	; 8041362D 
	DB 0x48,0x8B,0x4,0x24
;/*	lea	-0x08(rbp),rbp	; 80413631 
	DB 0x48,0x8D,0x6D,0xF8
	call	_MOVE	; 80413635 E8 8 1A FF FF 
;/*	mov	rax,-0x08(rbp)	; 8041363A 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 8041363E 58 
;/*	lea	-0x08(rbp),rbp	; 8041363F 
	DB 0x48,0x8D,0x6D,0xF8
	ret		; 80413643 C3 
;/
;/: >SYSPADZ	\ caddr len -- zaddr
;/\ *G Copy a string to *\fo{SYSPAD} and return the new zero
;/\ ** terminated string.
;/  dup 1+ NEWSYSPADGET dup >r zplace r>  ;


_greatSYSPADZ:
	call	_DUP	; 80413644 E8 DF E FF FF 
	call	_CHARadd	; 80413649 E8 2D E FF FF 
	call	_NEWSYSPADGET	; 8041364E E8 40 21 FF FF 
	call	_DUP	; 80413653 E8 D0 E FF FF 
	Push	rax	; 80413658 50 
;/*	mov	0x00(rbp),rax	; 80413659 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8041365D 
	DB 0x48,0x8D,0x6D,0x8
	call	_zplace	; 80413661 E8 75 1B FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413666 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 8041366A 58 
;/*	lea	-0x08(rbp),rbp	; 8041366B 
	DB 0x48,0x8D,0x6D,0xF8
	ret		; 8041366F C3 
;/
;/T: S"	[CHAR] " PARSE


_Sdtic:
;/*	mov	rax,-0x08(rbp)	; 80413670 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x22,eax	; 80413674 
	DB 0xB8,0x22,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413679 
	DB 0x48,0x8D,0x6D,0xF8
	call	_PARSE	; 8041367D E8 81 E8 FF FF 
;/	STATE @ IF SLIT, ELSE >SYSPAD THEN ; IMMEDIATE
;/*	mov	rax,-0x08(rbp)	; 80413682 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x12 (%rip),rax	; 80413686 
	DB 0x48,0x8D,0x5,0xCF,0x10,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041368D 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80413691 E8 33 B FF FF 
	test	rax,rax	; 80413696 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80413699 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8041369D 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_Sdtic+0x41 	; 804136A1 
	DB 0xF,0x84,0xA,0x0,0x0,0x0
	call	_SLITcom	; 804136A7 E8 1F FF FF FF 
;/*	jmp	_Sdtic+0x46 	; 804136AC 
	DB 0xE9,0x5,0x0,0x0,0x0
	call	_greatSYSPAD	; 804136B1 E8 5B FF FF FF 
	ret		; 804136B6 C3 
;/
;/T: Z"	[CHAR] " PARSE


_Zdtic:
;/*	mov	rax,-0x08(rbp)	; 804136B7 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x22,eax	; 804136BB 
	DB 0xB8,0x22,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804136C0 
	DB 0x48,0x8D,0x6D,0xF8
	call	_PARSE	; 804136C4 E8 3A E8 FF FF 
;/	STATE @ IF ZSLIT, ELSE >SYSPADZ THEN ; IMMEDIATE
;/*	mov	rax,-0x08(rbp)	; 804136C9 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x12 (%rip),rax	; 804136CD 
	DB 0x48,0x8D,0x5,0x88,0x10,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804136D4 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 804136D8 E8 EC A FF FF 
	test	rax,rax	; 804136DD 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804136E0 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804136E4 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_Zdtic+0x41 	; 804136E8 
	DB 0xF,0x84,0xA,0x0,0x0,0x0
	call	_ZSLITcom	; 804136EE E8 F2 FE FF FF 
;/*	jmp	_Zdtic+0x46 	; 804136F3 
	DB 0xE9,0x5,0x0,0x0,0x0
	call	_greatSYSPADZ	; 804136F8 E8 47 FF FF FF 
	ret		; 804136FD C3 
;/
;/: (ABORT'') ROT


_cbigABORTticticcend:
	call	_ROT	; 804136FE E8 E F FF FF 
;/ IF TYPE -2 THROW THEN
	test	rax,rax	; 80413703 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80413706 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8041370A 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_cbigABORTticticcend+0x2F 	; 8041370E 
	DB 0xF,0x84,0x19,0x0,0x0,0x0
	call	_TYPE	; 80413714 E8 33 16 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413719 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0x2,rax	; 8041371D 
	DB 0x48,0xC7,0xC0,0xFE,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413724 
	DB 0x48,0x8D,0x6D,0xF8
	call	_THROW	; 80413728 E8 D7 1D FF FF 
;/ 2DROP
	call	_2DROP	; 8041372D E8 3A E FF FF 
;/;
	ret		; 80413732 C3 
;/
;/T: ABORT"        \ Comp: "ccc<quote>" -- ; Run: i*x x1 -- | i*x ; R: j*x -- | j*x  9.6.2.0680
;/\ *G If x1 is true at run-time, display the following string and
;/\ ** perform *\fo{ABORT}, otherwise do nothing. This is handled by
;/\ ** performing *\fo{-2 THROW} after setting the variable
;/\ ** *\fo{'ABORTTEXT}.
;/	[COMPILE] S" ['] (ABORT'') COMPILE, ; IMMEDIATE


_ABORTdtic:
	call	_Sdtic	; 80413733 E8 38 FF FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413738 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_cbigABORTticticcend(%rip),rax	; 8041373C 
	DB 0x48,0x8D,0x5,0xBB,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413743 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COMPILEcom	; 80413747 E8 5E DC FF FF 
	ret		; 8041374C C3 
;/
;/: CRASH         ( -- ) 
;/ TRUE	ABORT" <- is an Uninitialized execution vector." 


_CRASH:
;/*	mov	rax,-0x08(rbp)	; 8041374D 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0x1,rax	; 80413751 
	DB 0x48,0xC7,0xC0,0xFF,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413758 
	DB 0x48,0x8D,0x6D,0xF8
	call	_cbigSdticcend	; 8041375C E8 72 17 FF FF 
	DB 0x28,0x3C,0x2D,0x20,0x69,0x73,0x20,0x61,0x6E,0x20,0x55,0x6E,0x69,0x6E,0x69,0x74,0x69,0x61,0x6C,0x69,0x7A,0x65,0x64,0x20,0x65,0x78,0x65,0x63,0x75,0x74,0x69,0x6F,0x6E,0x20,0x76,0x65,0x63,0x74,0x6F,0x72,0x2E
	call	_cbigABORTticticcend	; 8041378A E8 6F FF FF FF 
;/ ;
	ret		; 8041378F C3 
;/
;/' CRASH TO 'CRASH
;/
;/: ?COMP ( -> )
;/  STATE @ 0= IF -14 THROW THEN


_queCOMP:
;/*	mov	rax,-0x08(rbp)	; 80413790 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x12 (%rip),rax	; 80413794 
	DB 0x48,0x8D,0x5,0xC1,0xF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041379B 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 8041379F E8 25 A FF FF 
	call	_0equ	; 804137A4 E8 99 B FF FF 
	test	rax,rax	; 804137A9 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804137AC 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804137B0 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_queCOMP+0x3E 	; 804137B4 
	DB 0xF,0x84,0x14,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 804137BA 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0xE,rax	; 804137BE 
	DB 0x48,0xC7,0xC0,0xF2,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804137C5 
	DB 0x48,0x8D,0x6D,0xF8
	call	_THROW	; 804137C9 E8 36 1D FF FF 
;/;
	ret		; 804137CE C3 
;/
;/: WORD ( char "<chars>ccc<char>" -- c-addr ) \ 94
;/\  DUP PSKIP PARSE 255 MIN
;/\  DUP PAD C! PAD 1+ SWAP CMOVE
;/\  0 PAD COUNT + C!
;/  PARSE PAD $!  PAD ;


_WORD:
	call	_PARSE	; 804137CF E8 2F E7 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804137D4 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x372 (%rip),rax	; 804137D8 
	DB 0x48,0x8D,0x5,0xDD,0x12,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804137DF 
	DB 0x48,0x8D,0x6D,0xF8
	call	_dolsave	; 804137E3 E8 3C 19 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804137E8 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x372 (%rip),rax	; 804137EC 
	DB 0x48,0x8D,0x5,0xC9,0x12,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804137F3 
	DB 0x48,0x8D,0x6D,0xF8
	ret		; 804137F7 C3 
;/
;/: CLIT,
;/	['] (C") COMPILE, COUNT S",


_CLITcom:
;/*	mov	rax,-0x08(rbp)	; 804137F8 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_cbigCdticcend(%rip),rax	; 804137FC 
	DB 0x48,0x8D,0x5,0x19,0x17,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413803 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COMPILEcom	; 80413807 E8 9E DB FF FF 
	call	_COUNT	; 8041380C E8 B0 A FF FF 
	call	_Sdticcom	; 80413811 E8 AA FD FF FF 
;/\	HERE 1 AND IF 0xFF C, THEN
;/\	HERE 3 AND IF 0xFFFF W, THEN
;/;
	ret		; 80413816 C3 
;/
;/T: CLITERAL ( addr -- ) 
;/  STATE @ IF CLIT, THEN ; IMMEDIATE


_CLITERAL:
;/*	mov	rax,-0x08(rbp)	; 80413817 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x12 (%rip),rax	; 8041381B 
	DB 0x48,0x8D,0x5,0x3A,0xF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413822 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80413826 E8 9E 9 FF FF 
	test	rax,rax	; 8041382B 48 85 C0 
;/*	mov	0x00(rbp),rax	; 8041382E 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80413832 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_CLITERAL+0x2A 	; 80413836 
	DB 0xF,0x84,0x5,0x0,0x0,0x0
	call	_CLITcom	; 8041383C E8 B7 FF FF FF 
	ret		; 80413841 C3 
;/
;/T: C"
;/  [CHAR] " WORD [COMPILE] CLITERAL


_Cdtic:
;/*	mov	rax,-0x08(rbp)	; 80413842 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x22,eax	; 80413846 
	DB 0xB8,0x22,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8041384B 
	DB 0x48,0x8D,0x6D,0xF8
	call	_WORD	; 8041384F E8 7B FF FF FF 
	call	_CLITERAL	; 80413854 E8 BE FF FF FF 
;/; IMMEDIATE
	ret		; 80413859 C3 
;/
;/T: EXIT, $C3 C, ;


_EXITcom:
;/*	mov	rax,-0x08(rbp)	; 8041385A 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xC3,eax	; 8041385E 
	DB 0xB8,0xC3,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413863 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 80413867 E8 62 14 FF FF 
	ret		; 8041386C C3 
;/
;/THS> .(  0)  MCR .( Wortbirne 'EXIT',_EXITcom,0,) 1 TO TLASTFLG
;/
;/: BRANCH, ( A -- ) \ ZZZZ IF  THEN
;/   0xE9 C,


_BRANCHcom:
;/*	mov	rax,-0x08(rbp)	; 8041386D 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xE9,eax	; 80413871 
	DB 0xB8,0xE9,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413876 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 8041387A E8 4F 14 FF FF 
;/  DUP IF THERE 4 + - THEN L,  \  DP @ TO LAST-HERE
	call	_DUP	; 8041387F E8 A4 C FF FF 
	test	rax,rax	; 80413884 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80413887 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8041388B 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_BRANCHcom+0x44 	; 8041388F 
	DB 0xF,0x84,0x1C,0x0,0x0,0x0
	call	_THERE	; 80413895 E8 9E 13 FF FF 
;/*	mov	rax,-0x08(rbp)	; 8041389A 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x4,eax	; 8041389E 
	DB 0xB8,0x4,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804138A3 
	DB 0x48,0x8D,0x6D,0xF8
	call	_add	; 804138A7 E8 6F B FF FF 
	call	_sub	; 804138AC E8 67 B FF FF 
	call	_Lcom	; 804138B1 E8 DE 13 FF FF 
;/;
	ret		; 804138B6 C3 
;/
;/T: ?BRANCH, ( A -- )
;/ 0x84 TO J_COD


_queBRANCHcom:
;/*	mov	rax,-0x08(rbp)	; 804138B7 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x84,eax	; 804138BB 
	DB 0xB8,0x84,0x0,0x0,0x0
;/*	mov	rax,-0x10(rbp)	; 804138C0 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_J_COD+0x5 (%rip),rax	; 804138C4 
	DB 0x48,0x8D,0x5,0xAA,0x1F,0xFF,0xFF
;/*	lea	-0x10(rbp),rbp	; 804138CB 
	DB 0x48,0x8D,0x6D,0xF0
	call	_save	; 804138CF E8 2C 9 FF FF 
;/   OPT_INIT SetOP $48 C, $C085 W,  OPT \ test   %rax,%rax
	call	_OPT_INIT	; 804138D4 E8 EA C9 FF FF 
	call	_SetOP	; 804138D9 E8 EB 21 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804138DE 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x48,eax	; 804138E2 
	DB 0xB8,0x48,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804138E7 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 804138EB E8 DE 13 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804138F0 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xC085,eax	; 804138F4 
	DB 0xB8,0x85,0xC0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804138F9 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Wcom	; 804138FD E8 AF 13 FF FF 
	call	_OPT	; 80413902 E8 CB C5 FF FF 
;/   OPT_CLOSE	['] DROP INLINE,
	call	_OPT_CLOSE	; 80413907 E8 C2 C9 FF FF 
;/*	mov	rax,-0x08(rbp)	; 8041390C 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_DgreatS(%rip),rax	; 80413910 
	DB 0x48,0x8D,0x5,0x1C,0x8,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413917 
	DB 0x48,0x8D,0x6D,0xF8
	call	_INLINEcom	; 8041391B E8 D8 C9 FF FF 
;/     0x0F C,  J_COD C, 
;/*	mov	rax,-0x08(rbp)	; 80413920 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xF,eax	; 80413924 
	DB 0xB8,0xF,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413929 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 8041392D E8 9C 13 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413932 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_J_COD+0x5 (%rip),rax	; 80413936 
	DB 0x48,0x8D,0x5,0x38,0x1F,0xFF,0xFF
;/*	mov	(rax),rax	; 8041393D 
	DB 0x48,0x8B,0x0
;/*	lea	-0x08(rbp),rbp	; 80413940 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 80413944 E8 85 13 FF FF 
;/  DUP IF THERE 4 + - THEN L, \ DP @ TO LAST-HERE
	call	_DUP	; 80413949 E8 DA B FF FF 
	test	rax,rax	; 8041394E 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80413951 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80413955 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_queBRANCHcom+0xC4 	; 80413959 
	DB 0xF,0x84,0x1C,0x0,0x0,0x0
	call	_THERE	; 8041395F E8 D4 12 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413964 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x4,eax	; 80413968 
	DB 0xB8,0x4,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8041396D 
	DB 0x48,0x8D,0x6D,0xF8
	call	_add	; 80413971 E8 A5 A FF FF 
	call	_sub	; 80413976 E8 9D A FF FF 
	call	_Lcom	; 8041397B E8 14 13 FF FF 
;/ 0 TO J_COD
;/*	mov	rax,-0x08(rbp)	; 80413980 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80413984 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	mov	rax,-0x10(rbp)	; 80413989 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_J_COD+0x5 (%rip),rax	; 8041398D 
	DB 0x48,0x8D,0x5,0xE1,0x1E,0xFF,0xFF
;/*	lea	-0x10(rbp),rbp	; 80413994 
	DB 0x48,0x8D,0x6D,0xF0
	call	_save	; 80413998 E8 63 8 FF FF 
;/;
	ret		; 8041399D C3 
;/
;/: >ORESOLVE1 ( A, N -- )
;/    HERE


_greatORESOLVE1:
	call	_HERE	; 8041399E E8 2A D6 FF FF 
;/    OVER -
	call	_OVER	; 804139A3 E8 F1 B FF FF 
	call	_sub	; 804139A8 E8 6B A FF FF 
;/    SWAP 4 - L!
	call	_SWAP	; 804139AD E8 90 B FF FF 
;/*	mov	rax,-0x08(rbp)	; 804139B2 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x4,eax	; 804139B6 
	DB 0xB8,0x4,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804139BB 
	DB 0x48,0x8D,0x6D,0xF8
	call	_sub	; 804139BF E8 54 A FF FF 
	call	_Lsave	; 804139C4 E8 29 8 FF FF 
;/;
	ret		; 804139C9 C3 
;/
;/: >ORESOLVE ( A, N -- )
;/ DUP	IF_FLAG =	IF   DROP >ORESOLVE1 BREAK


_greatORESOLVE:
	call	_DUP	; 804139CA E8 59 B FF FF 
;/*	mov	rax,-0x08(rbp)	; 804139CF 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x1,eax	; 804139D3 
	DB 0xB8,0x1,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804139D8 
	DB 0x48,0x8D,0x6D,0xF8
	call	_equ	; 804139DC E8 59 9 FF FF 
	test	rax,rax	; 804139E1 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804139E4 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804139E8 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_greatORESOLVE+0x33 	; 804139EC 
	DB 0xF,0x84,0xB,0x0,0x0,0x0
	call	_DgreatS	; 804139F2 E8 3C 7 FF FF 
	call	_greatORESOLVE1	; 804139F7 E8 A2 FF FF FF 
	ret		; 804139FC C3 
;/	HEAD_FLAG <>	IF -2007 THROW THEN \ ABORT" Conditionals not paired"
;/*	mov	rax,-0x08(rbp)	; 804139FD 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xD,eax	; 80413A01 
	DB 0xB8,0xD,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413A06 
	DB 0x48,0x8D,0x6D,0xF8
	call	_lessgreat	; 80413A0A E8 8A 9 FF FF 
	test	rax,rax	; 80413A0F 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80413A12 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80413A16 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_greatORESOLVE+0x6A 	; 80413A1A 
	DB 0xF,0x84,0x14,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 80413A20 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0x7D7,rax	; 80413A24 
	DB 0x48,0xC7,0xC0,0x29,0xF8,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413A2B 
	DB 0x48,0x8D,0x6D,0xF8
	call	_THROW	; 80413A2F E8 D0 1A FF FF 
;/		>ORESOLVE1
	call	_greatORESOLVE1	; 80413A34 E8 65 FF FF FF 
;/;
	ret		; 80413A39 C3 
;/
;/T: ." [COMPILE] S" ['] TYPE COMPILE, ; IMMEDIATE


_dotdtic:
	call	_Sdtic	; 80413A3A E8 31 FC FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413A3F 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_TYPE(%rip),rax	; 80413A43 
	DB 0x48,0x8D,0x5,0x2,0x13,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413A4A 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COMPILEcom	; 80413A4E E8 57 D9 FF FF 
	ret		; 80413A53 C3 
;/
;/: ALIGN-NOP ( n -- )
;/\ выровнять HERE на n и заполнить NOP
;/  HERE DUP ROT 2DUP


_ALIGNsubNOP:
	call	_HERE	; 80413A54 E8 74 D5 FF FF 
	call	_DUP	; 80413A59 E8 CA A FF FF 
	call	_ROT	; 80413A5E E8 AE B FF FF 
	call	_2DUP	; 80413A63 E8 C9 A FF FF 
;/  MOD DUP IF - + ELSE 2DROP THEN
	call	_MOD	; 80413A68 E8 50 A FF FF 
	call	_DUP	; 80413A6D E8 B6 A FF FF 
	test	rax,rax	; 80413A72 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80413A75 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80413A79 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_ALIGNsubNOP+0x3E 	; 80413A7D 
	DB 0xF,0x84,0xF,0x0,0x0,0x0
	call	_sub	; 80413A83 E8 90 9 FF FF 
	call	_add	; 80413A88 E8 8E 9 FF FF 
;/*	jmp	_ALIGNsubNOP+0x43 	; 80413A8D 
	DB 0xE9,0x5,0x0,0x0,0x0
	call	_2DROP	; 80413A92 E8 D5 A FF FF 
;/  OVER - DUP ALLOT 0x90 FILL
	call	_OVER	; 80413A97 E8 FD A FF FF 
	call	_sub	; 80413A9C E8 77 9 FF FF 
	call	_DUP	; 80413AA1 E8 82 A FF FF 
	call	_ALLOT	; 80413AA6 E8 A2 11 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413AAB 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x90,eax	; 80413AAF 
	DB 0xB8,0x90,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413AB4 
	DB 0x48,0x8D,0x6D,0xF8
	call	_FILL	; 80413AB8 E8 D7 B FF FF 
;/;
	ret		; 80413ABD C3 
;/
;/T: BEGIN ?COMP HERE BEGIN_FLAG ; IMMEDIATE


_BEGIN:
	call	_queCOMP	; 80413ABE E8 CD FC FF FF 
	call	_HERE	; 80413AC3 E8 5 D5 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413AC8 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x7,eax	; 80413ACC 
	DB 0xB8,0x7,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413AD1 
	DB 0x48,0x8D,0x6D,0xF8
	ret		; 80413AD5 C3 
;/T: UNTIL ?COMP BEGIN_FLAG <> IF -22 THROW THEN  ?BRANCH, ; IMMEDIATE


_UNTIL:
	call	_queCOMP	; 80413AD6 E8 B5 FC FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413ADB 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x7,eax	; 80413ADF 
	DB 0xB8,0x7,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413AE4 
	DB 0x48,0x8D,0x6D,0xF8
	call	_lessgreat	; 80413AE8 E8 AC 8 FF FF 
	test	rax,rax	; 80413AED 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80413AF0 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80413AF4 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_UNTIL+0x3C 	; 80413AF8 
	DB 0xF,0x84,0x14,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 80413AFE 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0x16,rax	; 80413B02 
	DB 0x48,0xC7,0xC0,0xEA,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413B09 
	DB 0x48,0x8D,0x6D,0xF8
	call	_THROW	; 80413B0D E8 F2 19 FF FF 
	call	_queBRANCHcom	; 80413B12 E8 A0 FD FF FF 
	ret		; 80413B17 C3 
;/T: AGAIN ?COMP BEGIN_FLAG <> IF -22 THROW THEN   BRANCH, ; IMMEDIATE


_AGAIN:
	call	_queCOMP	; 80413B18 E8 73 FC FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413B1D 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x7,eax	; 80413B21 
	DB 0xB8,0x7,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413B26 
	DB 0x48,0x8D,0x6D,0xF8
	call	_lessgreat	; 80413B2A E8 6A 8 FF FF 
	test	rax,rax	; 80413B2F 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80413B32 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80413B36 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_AGAIN+0x3C 	; 80413B3A 
	DB 0xF,0x84,0x14,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 80413B40 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0x16,rax	; 80413B44 
	DB 0x48,0xC7,0xC0,0xEA,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413B4B 
	DB 0x48,0x8D,0x6D,0xF8
	call	_THROW	; 80413B4F E8 B0 19 FF FF 
	call	_BRANCHcom	; 80413B54 E8 14 FD FF FF 
	ret		; 80413B59 C3 
;/T: AHEAD ?COMP	THERE BRANCH,	THERE HEAD_FLAG ; IMMEDIATE


_AHEAD:
	call	_queCOMP	; 80413B5A E8 31 FC FF FF 
	call	_THERE	; 80413B5F E8 D4 10 FF FF 
	call	_BRANCHcom	; 80413B64 E8 4 FD FF FF 
	call	_THERE	; 80413B69 E8 CA 10 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413B6E 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xD,eax	; 80413B72 
	DB 0xB8,0xD,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413B77 
	DB 0x48,0x8D,0x6D,0xF8
	ret		; 80413B7B C3 
;/T: IF	?COMP	THERE ?BRANCH,	THERE  IF_FLAG ; IMMEDIATE


_IF:
	call	_queCOMP	; 80413B7C E8 F FC FF FF 
	call	_THERE	; 80413B81 E8 B2 10 FF FF 
	call	_queBRANCHcom	; 80413B86 E8 2C FD FF FF 
	call	_THERE	; 80413B8B E8 A8 10 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413B90 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x1,eax	; 80413B94 
	DB 0xB8,0x1,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413B99 
	DB 0x48,0x8D,0x6D,0xF8
	ret		; 80413B9D C3 
;/T: THEN ( A, N -- )
;/	?COMP   >ORESOLVE ; IMMEDIATE


_THEN:
	call	_queCOMP	; 80413B9E E8 ED FB FF FF 
	call	_greatORESOLVE	; 80413BA3 E8 22 FE FF FF 
	ret		; 80413BA8 C3 
;/T: ELSE   ( BO BI ADDR ? -- 0 0 ADDR1 ?1 )
;/  [COMPILE] AHEAD CS-SWAP [COMPILE] THEN ; IMMEDIATE


_ELSE:
	call	_AHEAD	; 80413BA9 E8 AC FF FF FF 
	call	_CSsubSWAP	; 80413BAE E8 9B 9 FF FF 
	call	_THEN	; 80413BB3 E8 E6 FF FF FF 
	ret		; 80413BB8 C3 
;/
;/T: WHILE  [COMPILE] IF  CS-SWAP ; IMMEDIATE


_WHILE:
	call	_IF	; 80413BB9 E8 BE FF FF FF 
	call	_CSsubSWAP	; 80413BBE E8 8B 9 FF FF 
	ret		; 80413BC3 C3 
;/T: REPEAT [COMPILE] AGAIN [COMPILE] THEN ; IMMEDIATE


_REPEAT:
	call	_AGAIN	; 80413BC4 E8 4F FF FF FF 
	call	_THEN	; 80413BC9 E8 D0 FF FF FF 
	ret		; 80413BCE C3 
;/
;/ 
;/T: DO            \ Run: n1|u1 n2|u2 -- ; R: -- loop-sys           6.1.1240
;/\ *G Begin a *\fo{DO ... LOOP} construct. Takes the end-value and
;/\ ** start-value from the stack.
;/  ['] (DO) _COMPILE, HERE 0 , HERE 3


_DO:
;/*	mov	rax,-0x08(rbp)	; 80413BCF 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_cbigDOcend(%rip),rax	; 80413BD3 
	DB 0x48,0x8D,0x5,0x36,0xB,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413BDA 
	DB 0x48,0x8D,0x6D,0xF8
	call	__COMPILEcom	; 80413BDE E8 93 D7 FF FF 
	call	_HERE	; 80413BE3 E8 E5 D3 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413BE8 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80413BEC 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413BF1 
	DB 0x48,0x8D,0x6D,0xF8
	call	_com	; 80413BF5 E8 7D 10 FF FF 
	call	_HERE	; 80413BFA E8 CE D3 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413BFF 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x3,eax	; 80413C03 
	DB 0xB8,0x3,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413C08 
	DB 0x48,0x8D,0x6D,0xF8
;/; IMMEDIATE
	ret		; 80413C0C C3 
;/
;/T: ?DO           \ Run: n1|u1 n2|u2 -- ; R: -- | loop-sys ; 6.2.0620
;/\ *G Compile a *\fo{DO} which will only begin loop execution if
;/\ ** the loop parameters do not specify an interation count of 0.
;/  ['] (?DO) _COMPILE, HERE 0 , HERE 3


_queDO:
;/*	mov	rax,-0x08(rbp)	; 80413C0D 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_cbigqueDOcend(%rip),rax	; 80413C11 
	DB 0x48,0x8D,0x5,0xF2,0xA,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413C18 
	DB 0x48,0x8D,0x6D,0xF8
	call	__COMPILEcom	; 80413C1C E8 55 D7 FF FF 
	call	_HERE	; 80413C21 E8 A7 D3 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413C26 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80413C2A 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413C2F 
	DB 0x48,0x8D,0x6D,0xF8
	call	_com	; 80413C33 E8 3F 10 FF FF 
	call	_HERE	; 80413C38 E8 90 D3 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413C3D 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x3,eax	; 80413C41 
	DB 0xB8,0x3,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413C46 
	DB 0x48,0x8D,0x6D,0xF8
;/; IMMEDIATE
	ret		; 80413C4A C3 
;/
;/
;/T: LOOP          \ Run: -- ; R: loop-sys1 -- | loop-sys2         6.1.1800
;/\ *G The closing statement of a *\fo{DO ... LOOP} construct.
;/\ ** Increments the index and terminates when the index crosses
;/\ ** the limit.
;/  3 ?PAIRS


_LOOP:
;/*	mov	rax,-0x08(rbp)	; 80413C4B 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x3,eax	; 80413C4F 
	DB 0xB8,0x3,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413C54 
	DB 0x48,0x8D,0x6D,0xF8
	call	_quePAIRS	; 80413C58 E8 1A DF FF FF 
;/ $49 C, $C6FF W, \ inc r14
;/*	mov	rax,-0x08(rbp)	; 80413C5D 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x49,eax	; 80413C61 
	DB 0xB8,0x49,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413C66 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 80413C6A E8 5F 10 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413C6F 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xC6FF,eax	; 80413C73 
	DB 0xB8,0xFF,0xC6,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413C78 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Wcom	; 80413C7C E8 30 10 FF FF 
;/ $49 C, $C7FF W, \ inc r15
;/*	mov	rax,-0x08(rbp)	; 80413C81 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x49,eax	; 80413C85 
	DB 0xB8,0x49,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413C8A 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 80413C8E E8 3B 10 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413C93 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xC7FF,eax	; 80413C97 
	DB 0xB8,0xFF,0xC7,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413C9C 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Wcom	; 80413CA0 E8 C 10 FF FF 
;/  HERE 2+ -  DUP SHORT? \  SetOP SetJP
	call	_HERE	; 80413CA5 E8 23 D3 FF FF 
	call	_2add	; 80413CAA E8 C9 7 FF FF 
	call	_sub	; 80413CAF E8 64 7 FF FF 
	call	_DUP	; 80413CB4 E8 6F 8 FF FF 
	call	_SHORTque	; 80413CB9 E8 A 19 FF FF 
;/  IF
	test	rax,rax	; 80413CBE 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80413CC1 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80413CC5 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_LOOP+0xA0 	; 80413CC9 
	DB 0xF,0x84,0x1C,0x0,0x0,0x0
;/    0x71 C, C, \ jno short 
;/*	mov	rax,-0x08(rbp)	; 80413CCF 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x71,eax	; 80413CD3 
	DB 0xB8,0x71,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413CD8 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 80413CDC E8 ED F FF FF 
	call	_Ccom	; 80413CE1 E8 E8 F FF FF 
;/  ELSE
;/*	jmp	_LOOP+0xDB 	; 80413CE6 
	DB 0xE9,0x3B,0x0,0x0,0x0
;/    4 - 0xF C, 0x81 C, L, \ jno near
;/*	mov	rax,-0x08(rbp)	; 80413CEB 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x4,eax	; 80413CEF 
	DB 0xB8,0x4,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413CF4 
	DB 0x48,0x8D,0x6D,0xF8
	call	_sub	; 80413CF8 E8 1B 7 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413CFD 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xF,eax	; 80413D01 
	DB 0xB8,0xF,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413D06 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 80413D0A E8 BF F FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413D0F 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x81,eax	; 80413D13 
	DB 0xB8,0x81,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413D18 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 80413D1C E8 AD F FF FF 
	call	_Lcom	; 80413D21 E8 6E F FF FF 
;/  THEN  \ SetOP
;/  $5E41 W, \ pop r14
;/*	mov	rax,-0x08(rbp)	; 80413D26 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x5E41,eax	; 80413D2A 
	DB 0xB8,0x41,0x5E,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413D2F 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Wcom	; 80413D33 E8 79 F FF FF 
;/  $5F41 W, \ pop r15
;/*	mov	rax,-0x08(rbp)	; 80413D38 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x5F41,eax	; 80413D3C 
	DB 0xB8,0x41,0x5F,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413D41 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Wcom	; 80413D45 E8 67 F FF FF 
;/  $59 C, \ pop rcx
;/*	mov	rax,-0x08(rbp)	; 80413D4A 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x59,eax	; 80413D4E 
	DB 0xB8,0x59,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413D53 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 80413D57 E8 72 F FF FF 
;/  HERE SWAP !
	call	_HERE	; 80413D5C E8 6C D2 FF FF 
	call	_SWAP	; 80413D61 E8 DC 7 FF FF 
	call	_save	; 80413D66 E8 95 4 FF FF 
;/ ; IMMEDIATE
	ret		; 80413D6B C3 
;/
;/T: +LOOP         \ Run: n -- ; R: loop-sys1 -- | loop-sys2       6.1.0140
;/\ *G As *\fo{LOOP} except that you specify the increment on the
;/\ ** stack. The action of *\fo{n +LOOP} is peculiar when n is
;/\ ** negative:
;/\ *C   -1 0 ?DO  i .  -1 +LOOP
;/\ *P prints *\fo{0 -1}, whereas:
;/\ *C   0 0 ?DO  i .  -1 +LOOP
;/\ *P prints nothing. This a result of the mathematical trick used
;/\ ** to detect the terminating condition. To prevent confusion
;/\ ** avoid using *\fo{n +LOOP} with negative *\i{n}.
;/  3 ?PAIRS


_addLOOP:
;/*	mov	rax,-0x08(rbp)	; 80413D6C 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x3,eax	; 80413D70 
	DB 0xB8,0x3,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413D75 
	DB 0x48,0x8D,0x6D,0xF8
	call	_quePAIRS	; 80413D79 E8 F9 DD FF FF 
;/	$49 C, $c601 W,	\   	add    %rax,%r14
;/*	mov	rax,-0x08(rbp)	; 80413D7E 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x49,eax	; 80413D82 
	DB 0xB8,0x49,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413D87 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 80413D8B E8 3E F FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413D90 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xC601,eax	; 80413D94 
	DB 0xB8,0x1,0xC6,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413D99 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Wcom	; 80413D9D E8 F F FF FF 
;/	$49 C, $c701 W,	\	add    %rax,%r15
;/*	mov	rax,-0x08(rbp)	; 80413DA2 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x49,eax	; 80413DA6 
	DB 0xB8,0x49,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413DAB 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 80413DAF E8 1A F FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413DB4 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xC701,eax	; 80413DB8 
	DB 0xB8,0x1,0xC7,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413DBD 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Wcom	; 80413DC1 E8 EB E FF FF 
;/	['] DROP INLINE,
;/*	mov	rax,-0x08(rbp)	; 80413DC6 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_DgreatS(%rip),rax	; 80413DCA 
	DB 0x48,0x8D,0x5,0x62,0x3,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413DD1 
	DB 0x48,0x8D,0x6D,0xF8
	call	_INLINEcom	; 80413DD5 E8 1E C5 FF FF 
;/  HERE 2+ -  DUP SHORT? \  SetOP SetJP
	call	_HERE	; 80413DDA E8 EE D1 FF FF 
	call	_2add	; 80413DDF E8 94 6 FF FF 
	call	_sub	; 80413DE4 E8 2F 6 FF FF 
	call	_DUP	; 80413DE9 E8 3A 7 FF FF 
	call	_SHORTque	; 80413DEE E8 D5 17 FF FF 
;/  IF
	test	rax,rax	; 80413DF3 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80413DF6 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80413DFA 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_addLOOP+0xB4 	; 80413DFE 
	DB 0xF,0x84,0x1C,0x0,0x0,0x0
;/    0x71 C, C, \ jno short 
;/*	mov	rax,-0x08(rbp)	; 80413E04 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x71,eax	; 80413E08 
	DB 0xB8,0x71,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413E0D 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 80413E11 E8 B8 E FF FF 
	call	_Ccom	; 80413E16 E8 B3 E FF FF 
;/  ELSE
;/*	jmp	_addLOOP+0xEF 	; 80413E1B 
	DB 0xE9,0x3B,0x0,0x0,0x0
;/    4 - 0xF C, 0x81 C, L, \ jno near
;/*	mov	rax,-0x08(rbp)	; 80413E20 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x4,eax	; 80413E24 
	DB 0xB8,0x4,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413E29 
	DB 0x48,0x8D,0x6D,0xF8
	call	_sub	; 80413E2D E8 E6 5 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413E32 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xF,eax	; 80413E36 
	DB 0xB8,0xF,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413E3B 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 80413E3F E8 8A E FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413E44 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x81,eax	; 80413E48 
	DB 0xB8,0x81,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413E4D 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 80413E51 E8 78 E FF FF 
	call	_Lcom	; 80413E56 E8 39 E FF FF 
;/  THEN  \ SetOP
;/  $5E41 W, \ pop r14
;/*	mov	rax,-0x08(rbp)	; 80413E5B 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x5E41,eax	; 80413E5F 
	DB 0xB8,0x41,0x5E,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413E64 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Wcom	; 80413E68 E8 44 E FF FF 
;/  $5F41 W, \ pop r15
;/*	mov	rax,-0x08(rbp)	; 80413E6D 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x5F41,eax	; 80413E71 
	DB 0xB8,0x41,0x5F,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413E76 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Wcom	; 80413E7A E8 32 E FF FF 
;/  $59 C, \ pop rcx
;/*	mov	rax,-0x08(rbp)	; 80413E7F 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x59,eax	; 80413E83 
	DB 0xB8,0x59,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413E88 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 80413E8C E8 3D E FF FF 
;/  HERE SWAP !
	call	_HERE	; 80413E91 E8 37 D1 FF FF 
	call	_SWAP	; 80413E96 E8 A7 6 FF FF 
	call	_save	; 80413E9B E8 60 3 FF FF 
;/ ; IMMEDIATE
	ret		; 80413EA0 C3 
;/
;/T: I
;/  ['] DUP INLINE,


_I:
;/*	mov	rax,-0x08(rbp)	; 80413EA1 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_DUP(%rip),rax	; 80413EA5 
	DB 0x48,0x8D,0x5,0x7C,0x6,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413EAC 
	DB 0x48,0x8D,0x6D,0xF8
	call	_INLINEcom	; 80413EB0 E8 43 C4 FF FF 
;/ OPT_INIT
	call	_OPT_INIT	; 80413EB5 E8 9 C4 FF FF 
;/ SetOP $4c C, $f089 W,  OPT	\	mov %r14,%rax
	call	_SetOP	; 80413EBA E8 A 1C FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413EBF 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x4C,eax	; 80413EC3 
	DB 0xB8,0x4C,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413EC8 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ccom	; 80413ECC E8 FD D FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413ED1 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xF089,eax	; 80413ED5 
	DB 0xB8,0x89,0xF0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413EDA 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Wcom	; 80413EDE E8 CE D FF FF 
	call	_OPT	; 80413EE3 E8 EA BF FF FF 
;/ OPT_CLOSE
	call	_OPT_CLOSE	; 80413EE8 E8 E1 C3 FF FF 
;/ ; IMMEDIATE
	ret		; 80413EED C3 
;/
;/: GET-CURRENT ( -- wid ) \ 94 SEARCH
;/  CURRENT @ ;


_GETsubCURRENT:
	call	_CURRENT	; 80413EEE E8 D 2 7F 0 
	call	_load	; 80413EF3 E8 D1 2 FF FF 
	ret		; 80413EF8 C3 
;/
;/: SET-CURRENT ( wid -- ) \ 94 SEARCH
;/  CURRENT ! ;


_SETsubCURRENT:
	call	_CURRENT	; 80413EF9 E8 2 2 7F 0 
	call	_save	; 80413EFE E8 FD 2 FF FF 
	ret		; 80413F03 C3 
;/
;/
;/0 VALUE YDP_FL


_YDP_FL:
	call	_DOVALUE	; 80413F04 E8 DB 7 FF FF 

	DQ 0x0
;/\ : YDP_FL  &YDP_FL @ ;
;/VARIABLE YDP
	DQ 0x0
	DB 0x0,0x0,0x0
;/VARIABLE YDP0
	DQ 0x0
;/
;/: YDP><DP
;/  YDP @ DP @

_YDPgreatlessDP:
;/*	mov	rax,-0x08(rbp)	; 80413F24 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_YDP_FL+0x10 (%rip),rax	; 80413F28 
	DB 0x48,0x8D,0x5,0xE5,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413F2F 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80413F33 E8 91 2 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413F38 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_HsubSTDERR+0x16 (%rip),rax	; 80413F3C 
	DB 0x48,0x8D,0x5,0xE5,0xC,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413F43 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80413F47 E8 7D 2 FF FF 
;/  YDP ! DP ! ;
;/*	mov	rax,-0x08(rbp)	; 80413F4C 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_YDP_FL+0x10 (%rip),rax	; 80413F50 
	DB 0x48,0x8D,0x5,0xBD,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413F57 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 80413F5B E8 A0 2 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413F60 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_HsubSTDERR+0x16 (%rip),rax	; 80413F64 
	DB 0x48,0x8D,0x5,0xBD,0xC,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413F6B 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 80413F6F E8 8C 2 FF FF 
	ret		; 80413F74 C3 
;/
;/: ?YDP><DP
;/ YDP_FL \ IS-TEMP-WL 0= AND


_queYDPgreatlessDP:
;/*	mov	rax,-0x08(rbp)	; 80413F75 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_YDP_FL+0x5 (%rip),rax	; 80413F79 
	DB 0x48,0x8D,0x5,0x89,0xFF,0xFF,0xFF
;/*	mov	(rax),rax	; 80413F80 
	DB 0x48,0x8B,0x0
	test	rax,rax	; 80413F83 48 85 C0 
;/*	mov	-0x08(rbp),rax	; 80413F86 
	DB 0x48,0x8B,0x45,0xF8
;/ IF YDP><DP
;/*	jz	_queYDPgreatlessDP+0x20 	; 80413F8A 
	DB 0xF,0x84,0x5,0x0,0x0,0x0
	call	_YDPgreatlessDP	; 80413F90 E8 8F FF FF FF 
;/ THEN ;
	ret		; 80413F95 C3 
;/
;/0 VALUE VIEW_LINK


_VIEW_LINK:
	call	_DOVALUE	; 80413F96 E8 49 7 FF FF 

	DQ 0x0
;/
;/VARIABLE LAST-CFA
	DQ 0x0
	DB 0x0
;/CREATE WARNING 1 ,
	DQ 0x1
;/CREATE NEEDUNIQUE  0 ,
	DQ 0x0
;/
;/: SBUILD ( addr u -- )
;/  ?YDP><DP

_SBUILD:
	call	_queYDPgreatlessDP	; 80413FBC E8 B4 FF FF FF 
;/	HERE 0 , DUP LAST-CFA !
	call	_HERE	; 80413FC1 E8 7 D0 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413FC6 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80413FCA 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413FCF 
	DB 0x48,0x8D,0x6D,0xF8
	call	_com	; 80413FD3 E8 9F C FF FF 
	call	_DUP	; 80413FD8 E8 4B 5 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80413FDD 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_VIEW_LINK+0xE (%rip),rax	; 80413FE1 
	DB 0x48,0x8D,0x5,0xBC,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80413FE8 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 80413FEC E8 F 2 FF FF 
;/	0 L,   ( flags )
;/*	mov	rax,-0x08(rbp)	; 80413FF1 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80413FF5 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80413FFA 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Lcom	; 80413FFE E8 91 C FF FF 
;/	CURSTR @ L,
;/*	mov	rax,-0x08(rbp)	; 80414003 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_OKdot+0x10 (%rip),rax	; 80414007 
	DB 0x48,0x8D,0x5,0xB6,0xE9,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041400E 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80414012 E8 B2 1 FF FF 
	call	_Lcom	; 80414017 E8 78 C FF FF 
;/	-ROT WARNING @ NEEDUNIQUE @ OR
	call	_subROT	; 8041401C E8 1 6 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80414021 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_VIEW_LINK+0x16 (%rip),rax	; 80414025 
	DB 0x48,0x8D,0x5,0x80,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041402C 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80414030 E8 94 1 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80414035 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_VIEW_LINK+0x1E (%rip),rax	; 80414039 
	DB 0x48,0x8D,0x5,0x74,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414040 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80414044 E8 80 1 FF FF 
	call	_OR	; 80414049 E8 9D 3 FF FF 
;/	IF 2DUP GET-CURRENT SEARCH-WORDLIST
	test	rax,rax	; 8041404E 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80414051 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414055 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_SBUILD+0x127 	; 80414059 
	DB 0xF,0x84,0x84,0x0,0x0,0x0
	call	_2DUP	; 8041405F E8 CD 4 FF FF 
	call	_GETsubCURRENT	; 80414064 E8 85 FE FF FF 
	call	_SEARCHsubWORDLIST	; 80414069 E8 E5 DF FF FF 
;/	   DUP NEEDUNIQUE @ AND
	call	_DUP	; 8041406E E8 B5 4 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80414073 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_VIEW_LINK+0x1E (%rip),rax	; 80414077 
	DB 0x48,0x8D,0x5,0x36,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041407E 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80414082 E8 42 1 FF FF 
	call	_AND	; 80414087 E8 56 3 FF FF 
;/	   ABORT"  unique is need"
	call	_cbigSdticcend	; 8041408C E8 42 E FF FF 
	DB 0xF,0x20,0x75,0x6E,0x69,0x71,0x75,0x65,0x20,0x69,0x73,0x20,0x6E,0x65,0x65,0x64
	call	_cbigABORTticticcend	; 804140A1 E8 58 F6 FF FF 
;/	   IF ( NOUNIQUE ) DROP 2DUP TYPE ."  isn't unique" CR THEN
	test	rax,rax	; 804140A6 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804140A9 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804140AD 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_SBUILD+0x127 	; 804140B1 
	DB 0xF,0x84,0x2C,0x0,0x0,0x0
	call	_DgreatS	; 804140B7 E8 77 0 FF FF 
	call	_2DUP	; 804140BC E8 70 4 FF FF 
	call	_TYPE	; 804140C1 E8 86 C FF FF 
	call	_cbigSdticcend	; 804140C6 E8 8 E FF FF 
	DB 0xD,0x20,0x69,0x73,0x6E,0x27,0x74,0x20,0x75,0x6E,0x69,0x71,0x75,0x65
	call	_TYPE	; 804140D9 E8 6E C FF FF 
	call	_CR	; 804140DE E8 9B C FF FF 
;/	THEN
;/	 CURRENT @ @ ,
	call	_CURRENT	; 804140E3 E8 18 0 7F 0 
	call	_load	; 804140E8 E8 DC 0 FF FF 
	call	_load	; 804140ED E8 D7 0 FF FF 
	call	_com	; 804140F2 E8 80 B FF FF 
;/	HERE LAST !
	call	_HERE	; 804140F7 E8 D1 CE FF FF 
;/*	mov	rax,-0x08(rbp)	; 804140FC 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22 (%rip),rax	; 80414100 
	DB 0x48,0x8D,0x5,0x65,0x6,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414107 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 8041410B E8 F0 0 FF FF 
;/	S", 
	call	_Sdticcom	; 80414110 E8 AB F4 FF FF 
;/	ALIGN
	call	_ALIGN	; 80414115 E8 8C DA FF FF 
;/	?YDP><DP
	call	_queYDPgreatlessDP	; 8041411A E8 56 FE FF FF 
;/    HERE SWAP ! ( ......... cfa )
	call	_HERE	; 8041411F E8 A9 CE FF FF 
	call	_SWAP	; 80414124 E8 19 4 FF FF 
	call	_save	; 80414129 E8 D2 0 FF FF 
;/;
	ret		; 8041412E C3 
;/
;/: SMUDGE LAST @ CURRENT @ ! ;


_SMUDGE:
;/*	mov	rax,-0x08(rbp)	; 8041412F 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22 (%rip),rax	; 80414133 
	DB 0x48,0x8D,0x5,0x32,0x6,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041413A 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 8041413E E8 86 0 FF FF 
	call	_CURRENT	; 80414143 E8 B8 FF 7E 0 
	call	_load	; 80414148 E8 7C 0 FF FF 
	call	_save	; 8041414D E8 AE 0 FF FF 
	ret		; 80414152 C3 
;/
;/T: SHEADER  SBUILD SMUDGE ;


_SHEADER:
	call	_SBUILD	; 80414153 E8 64 FE FF FF 
	call	_SMUDGE	; 80414158 E8 D2 FF FF FF 
	ret		; 8041415D C3 
;/
;/T: HEADER  PARSE-NAME SHEADER ;


_HEADER:
	call	_PARSEsubNAME	; 8041415E E8 3 DD FF FF 
	call	_SHEADER	; 80414163 E8 EB FF FF FF 
	ret		; 80414168 C3 
;/
;/T: BUILD  PARSE-NAME SBUILD ;


_BUILD:
	call	_PARSEsubNAME	; 80414169 E8 F8 DC FF FF 
	call	_SBUILD	; 8041416E E8 49 FE FF FF 
	ret		; 80414173 C3 
;/
;/CREATE &DOCONSTANT	' DOCONSTANT ,

	DQ 0x5FD+fimg
;/CREATE &DOVALUE		' DOVALUE ,
	DQ 0x5FC+fimg
;/CREATE &DOCREATE	' DOCREATE ,
	DQ 0x60A+fimg
;/CREATE &DOVECT		' DOVECT ,
	DQ 0x614+fimg
;/
;/T: CONSTANT  ( n -- )	HEADER &DOCONSTANT @ COMPILE, , ;

_CONSTANT:
	call	_HEADER	; 80414194 E8 C5 FF FF FF 
;/*	mov	rax,-0x08(rbp)	; 80414199 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_BUILD+0xB (%rip),rax	; 8041419D 
	DB 0x48,0x8D,0x5,0xD0,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804141A4 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 804141A8 E8 1C 0 FF FF 
	call	_COMPILEcom	; 804141AD E8 F8 D1 FF FF 
	call	_com	; 804141B2 E8 C0 A FF FF 
	ret		; 804141B7 C3 
;/
;/T: VALUE ( n -- )	HEADER &DOVALUE	@ COMPILE, , ;


_VALUE:
	call	_HEADER	; 804141B8 E8 A1 FF FF FF 
;/*	mov	rax,-0x08(rbp)	; 804141BD 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_BUILD+0x13 (%rip),rax	; 804141C1 
	DB 0x48,0x8D,0x5,0xB4,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804141C8 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 804141CC E8 F8 FF FE FF 
	call	_COMPILEcom	; 804141D1 E8 D4 D1 FF FF 
	call	_com	; 804141D6 E8 9C A FF FF 
	ret		; 804141DB C3 
;/
;/: CREATED  SHEADER


_CREATED:
	call	_SHEADER	; 804141DC E8 72 FF FF FF 
;/  THERE 3 - ALIGNED 3 + DP! THERE LAST @ NAME>C !
	call	_THERE	; 804141E1 E8 52 A FF FF 
;/*	mov	rax,-0x08(rbp)	; 804141E6 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x3,eax	; 804141EA 
	DB 0xB8,0x3,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804141EF 
	DB 0x48,0x8D,0x6D,0xF8
	call	_sub	; 804141F3 E8 20 2 FF FF 
	call	_ALIGNED	; 804141F8 E8 54 C FF FF 
;/*	mov	rax,-0x08(rbp)	; 804141FD 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x3,eax	; 80414201 
	DB 0xB8,0x3,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80414206 
	DB 0x48,0x8D,0x6D,0xF8
	call	_add	; 8041420A E8 C 2 FF FF 
	call	_DPsave	; 8041420F E8 4E A FF FF 
	call	_THERE	; 80414214 E8 1F A FF FF 
;/*	mov	rax,-0x08(rbp)	; 80414219 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22 (%rip),rax	; 8041421D 
	DB 0x48,0x8D,0x5,0x48,0x5,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414224 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80414228 E8 9C FF FE FF 
	call	_NAMEgreatC	; 8041422D E8 44 4 FF FF 
	call	_save	; 80414232 E8 C9 FF FE FF 
;/ &DOCREATE @ COMPILE, ;
;/*	mov	rax,-0x08(rbp)	; 80414237 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_BUILD+0x1B (%rip),rax	; 8041423B 
	DB 0x48,0x8D,0x5,0x42,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414242 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80414246 E8 7E FF FE FF 
	call	_COMPILEcom	; 8041424B E8 5A D1 FF FF 
	ret		; 80414250 C3 
;/
;/T: CREATE	PARSE-NAME CREATED ;


_CREATE:
	call	_PARSEsubNAME	; 80414251 E8 10 DC FF FF 
	call	_CREATED	; 80414256 E8 81 FF FF FF 
	ret		; 8041425B C3 
;/
;/T: VARIABLE	CREATE 0 , ;


_VARIABLE:
	call	_CREATE	; 8041425C E8 F0 FF FF FF 
;/*	mov	rax,-0x08(rbp)	; 80414261 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80414265 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8041426A 
	DB 0x48,0x8D,0x6D,0xF8
	call	_com	; 8041426E E8 4 A FF FF 
	ret		; 80414273 C3 
;/
;/T: ->DEFER ( cfa -- )	HEADER 	&DOVECT @ COMPILE, , ;


_subgreatDEFER:
	call	_HEADER	; 80414274 E8 E5 FE FF FF 
;/*	mov	rax,-0x08(rbp)	; 80414279 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_BUILD+0x23 (%rip),rax	; 8041427D 
	DB 0x48,0x8D,0x5,0x8,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414284 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80414288 E8 3C FF FE FF 
	call	_COMPILEcom	; 8041428D E8 18 D1 FF FF 
	call	_com	; 80414292 E8 E0 9 FF FF 
	ret		; 80414297 C3 
;/
;/T: DEFER	( -- )  ['] CRASH  ->DEFER ;


_DEFER:
;/*	mov	rax,-0x08(rbp)	; 80414298 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_CRASH(%rip),rax	; 8041429C 
	DB 0x48,0x8D,0x5,0xAA,0xF4,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804142A3 
	DB 0x48,0x8D,0x6D,0xF8
	call	_subgreatDEFER	; 804142A7 E8 C8 FF FF FF 
	ret		; 804142AC C3 
;/
;/T: #DEFINE  BUILD SMUDGE &DOCONSTANT @ COMPILE, INTERPRET , ; 


_hashDEFINE:
	call	_BUILD	; 804142AD E8 B7 FE FF FF 
	call	_SMUDGE	; 804142B2 E8 78 FE FF FF 
;/*	mov	rax,-0x08(rbp)	; 804142B7 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_BUILD+0xB (%rip),rax	; 804142BB 
	DB 0x48,0x8D,0x5,0xB2,0xFE,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804142C2 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 804142C6 E8 FE FE FE FF 
	call	_COMPILEcom	; 804142CB E8 DA D0 FF FF 
	call	_INTERPRET	; 804142D0 E8 10 DF FF FF 
	call	_com	; 804142D5 E8 9D 9 FF FF 
	ret		; 804142DA C3 
;/
;/: DEFER@ ( xt1 i?? i?? xt2 )
;/\ xt2 is the execution token xt1 is set to execute. An ambiguous condition exists if xt1 is not
;/\ the execution token of a word defined by DEFER, or if xt1 has not been set to execute an
;/  >BODY @ ;


_DEFERload:
	call	_greatBODY	; 804142DB E8 A4 11 FF FF 
	call	_load	; 804142E0 E8 E4 FE FE FF 
	ret		; 804142E5 C3 
;/: DEFER! ( xt2 xt1 i?? i?? )
;/\ Set the word xt1 to execute xt2. An ambiguous condition exists if xt1 is not for a word
;/\ defined by DEFER.
;/  >BODY ! ;


_DEFERsave:
	call	_greatBODY	; 804142E6 E8 99 11 FF FF 
	call	_save	; 804142EB E8 10 FF FE FF 
	ret		; 804142F0 C3 
;/
;/T: TO '


_TO:
	call	_tic	; 804142F1 E8 3B F2 FF FF 
;/ STATE @
;/*	mov	rax,-0x08(rbp)	; 804142F6 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x12 (%rip),rax	; 804142FA 
	DB 0x48,0x8D,0x5,0x5B,0x4,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414301 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80414305 E8 BF FE FE FF 
;/ IF
	test	rax,rax	; 8041430A 48 85 C0 
;/*	mov	0x00(rbp),rax	; 8041430D 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414311 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_TO+0x49 	; 80414315 
	DB 0xF,0x84,0x1F,0x0,0x0,0x0
;/  >BODY  ADDR, ['] !
	call	_greatBODY	; 8041431B E8 64 11 FF FF 
	call	_ADDRcom	; 80414320 E8 23 CF FF FF 
;/*	mov	rax,-0x08(rbp)	; 80414325 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_save(%rip),rax	; 80414329 
	DB 0x48,0x8D,0x5,0xD0,0xFE,0xFE,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414330 
	DB 0x48,0x8D,0x6D,0xF8
;/   COMPILE,
	call	_COMPILEcom	; 80414334 E8 71 D0 FF FF 
;/ BREAK
	ret		; 80414339 C3 
;/ DEFER!  ; IMMEDIATE
	call	_DEFERsave	; 8041433A E8 A7 FF FF FF 
	ret		; 8041433F C3 
;/
;/: (DOES>)
;/ R>	HERE >R


_cbigDOESgreatcend:
;/*	mov	rax,-0x08(rbp)	; 80414340 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80414344 58 
;/*	lea	-0x08(rbp),rbp	; 80414345 
	DB 0x48,0x8D,0x6D,0xF8
	call	_HERE	; 80414349 E8 7F CC FF FF 
	Push	rax	; 8041434E 50 
;/*	mov	0x00(rbp),rax	; 8041434F 
	DB 0x48,0x8B,0x45,0x0
;/*	mov	rax,0x00(rbp)	; 80414353 
	DB 0x48,0x89,0x45,0x0
;/	LAST @ NAME>  DP !
;/*	lea	_UNLOOP+0x22 (%rip),rax	; 80414357 
	DB 0x48,0x8D,0x5,0xE,0x4,0xFF,0xFF
	call	_load	; 8041435E E8 66 FE FE FF 
	call	_NAMEgreat	; 80414363 E8 13 3 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80414368 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_HsubSTDERR+0x16 (%rip),rax	; 8041436C 
	DB 0x48,0x8D,0x5,0xB5,0x8,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414373 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 80414377 E8 84 FE FE FF 
;/	COMPILE,
	call	_COMPILEcom	; 8041437C E8 29 D0 FF FF 
;/ R> DP !
;/*	mov	rax,-0x08(rbp)	; 80414381 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80414385 58 
;/*	mov	rax,-0x10(rbp)	; 80414386 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_HsubSTDERR+0x16 (%rip),rax	; 8041438A 
	DB 0x48,0x8D,0x5,0x97,0x8,0xFF,0xFF
;/*	lea	-0x10(rbp),rbp	; 80414391 
	DB 0x48,0x8D,0x6D,0xF0
	call	_save	; 80414395 E8 66 FE FE FF 
;/;
	ret		; 8041439A C3 
;/
;/T: DOES>
;/ ['] (DOES>)	COMPILE,


_DOESgreat:
;/*	mov	rax,-0x08(rbp)	; 8041439B 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_cbigDOESgreatcend(%rip),rax	; 8041439F 
	DB 0x48,0x8D,0x5,0x9A,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804143A6 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COMPILEcom	; 804143AA E8 FB CF FF FF 
;/ [COMPILE] R>
	call	_Rgreat	; 804143AF E8 A9 CC FF FF 
;/; IMMEDIATE
	ret		; 804143B4 C3 
;/
;/T: \ SOURCE NIP >IN ! ; IMMEDIATE


_sl:
	call	_SOURCE	; 804143B5 E8 8F D8 FF FF 
	call	_NIP	; 804143BA E8 4D 2 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804143BF 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22A (%rip),rax	; 804143C3 
	DB 0x48,0x8D,0x5,0xAA,0x5,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804143CA 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 804143CE E8 2D FE FE FF 
	ret		; 804143D3 C3 
;/
;/T: (  ( "ccc<paren>" -- ) \ 94 FILE
;/\ Расширить семантику CORE (, включив:
;/\ Когда разбирается текстовый файл, если конец разбираемой области достигнут
;/\ раньше, чем найдена правая скобка, снова заполнить входной буфер следующей
;/\ строкой из файла, установить >IN в ноль и продолжать разбор, повторяя
;/\ этот процесс до тех пор, пока не будет найдена правая скобка или не
;/\ будет достигнут конец файла.
;/  BEGIN
;/    [CHAR] ) DUP PARSE + C@ = 0=


_cbig:
;/*	mov	rax,-0x08(rbp)	; 804143D4 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x29,eax	; 804143D8 
	DB 0xB8,0x29,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804143DD 
	DB 0x48,0x8D,0x6D,0xF8
	call	_DUP	; 804143E1 E8 42 1 FF FF 
	call	_PARSE	; 804143E6 E8 18 DB FF FF 
	call	_add	; 804143EB E8 2B 0 FF FF 
	call	_Cload	; 804143F0 E8 D8 FD FE FF 
	call	_equ	; 804143F5 E8 40 FF FE FF 
	call	_0equ	; 804143FA E8 43 FF FE FF 
;/  WHILE
	test	rax,rax	; 804143FF 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80414402 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414406 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_cbig+0x5D 	; 8041440A 
	DB 0xF,0x84,0x21,0x0,0x0,0x0
;/    REFILL 0= IF EXIT THEN
	call	_REFILL	; 80414410 E8 49 E7 FF FF 
	call	_0equ	; 80414415 E8 28 FF FE FF 
	test	rax,rax	; 8041441A 48 85 C0 
;/*	mov	0x00(rbp),rax	; 8041441D 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414421 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_cbig+0x58 	; 80414425 
	DB 0xF,0x84,0x1,0x0,0x0,0x0
	ret		; 8041442B C3 
;/  REPEAT
;/*	jmp	_cbig	; 8041442C 
	DB 0xE9,0xA3,0xFF,0xFF,0xFF
;/; IMMEDIATE
	ret		; 80414431 C3 
;/
;/T: .( [CHAR] ) PARSE TYPE ; IMMEDIATE


_dotcbig:
;/*	mov	rax,-0x08(rbp)	; 80414432 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x29,eax	; 80414436 
	DB 0xB8,0x29,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8041443B 
	DB 0x48,0x8D,0x6D,0xF8
	call	_PARSE	; 8041443F E8 BF DA FF FF 
	call	_TYPE	; 80414444 E8 3 9 FF FF 
	ret		; 80414449 C3 
;/
;/T: [CHAR] ?COMP CHAR LIT, ; IMMEDIATE


_xcCHARyc:
	call	_queCOMP	; 8041444A E8 41 F3 FF FF 
	call	_CHAR	; 8041444F E8 1D F1 FF FF 
	call	_LITcom	; 80414454 E8 E2 CD FF FF 
	ret		; 80414459 C3 
;/
;/: [DEFINED] ( -- f ) \ "name"
;/  PARSE-NAME SFIND  IF DROP TRUE ELSE 2DROP FALSE THEN


_xcDEFINEDyc:
	call	_PARSEsubNAME	; 8041445A E8 7 DA FF FF 
	call	_SFIND	; 8041445F E8 FC DB FF FF 
	test	rax,rax	; 80414464 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80414467 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8041446B 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_xcDEFINEDyc+0x34 	; 8041446F 
	DB 0xF,0x84,0x19,0x0,0x0,0x0
	call	_DgreatS	; 80414475 E8 B9 FC FE FF 
;/*	mov	rax,-0x08(rbp)	; 8041447A 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0x1,rax	; 8041447E 
	DB 0x48,0xC7,0xC0,0xFF,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414485 
	DB 0x48,0x8D,0x6D,0xF8
;/*	jmp	_xcDEFINEDyc+0x46 	; 80414489 
	DB 0xE9,0x12,0x0,0x0,0x0
	call	_2DROP	; 8041448E E8 D9 0 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80414493 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80414497 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8041449C 
	DB 0x48,0x8D,0x6D,0xF8
;/; IMMEDIATE
	ret		; 804144A0 C3 
;/
;/: [UNDEFINED]  ( -- f )   [COMPILE] [DEFINED] 0= ; IMMEDIATE


_xcUNDEFINEDyc:
	call	_xcDEFINEDyc	; 804144A1 E8 B4 FF FF FF 
	call	_0equ	; 804144A6 E8 97 FE FE FF 
	ret		; 804144AB C3 
;/
;/T: \+ [COMPILE] [UNDEFINED]	IF [COMPILE] \ THEN ; IMMEDIATE


_sladd:
	call	_xcUNDEFINEDyc	; 804144AC E8 F0 FF FF FF 
	test	rax,rax	; 804144B1 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804144B4 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804144B8 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_sladd+0x1B 	; 804144BC 
	DB 0xF,0x84,0x5,0x0,0x0,0x0
	call	_sl	; 804144C2 E8 EE FE FF FF 
	ret		; 804144C7 C3 
;/T: \- [COMPILE] [DEFINED]	IF [COMPILE] \ THEN ; IMMEDIATE


_slsub:
	call	_xcDEFINEDyc	; 804144C8 E8 8D FF FF FF 
	test	rax,rax	; 804144CD 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804144D0 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804144D4 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_slsub+0x1B 	; 804144D8 
	DB 0xF,0x84,0x5,0x0,0x0,0x0
	call	_sl	; 804144DE E8 D2 FE FF FF 
	ret		; 804144E3 C3 
;/
;/T: \EOF  ( -- )
;/\ Заканчивает трансляцию текущего потока
;/  BEGIN REFILL 0= UNTIL  [COMPILE] \


_slEOF:
	call	_REFILL	; 804144E4 E8 75 E6 FF FF 
	call	_0equ	; 804144E9 E8 54 FE FE FF 
	test	rax,rax	; 804144EE 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804144F1 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804144F5 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_slEOF	; 804144F9 
	DB 0xF,0x84,0xE5,0xFF,0xFF,0xFF
	call	_sl	; 804144FF E8 B1 FE FF FF 
;/;
	ret		; 80414504 C3 
;/
;/: FIND ( c-addr -- c-addr 0 | xt 1 | xt -1 ) \ 94 SEARCH
;/  DUP >R COUNT SFIND


_FIND:
	call	_DUP	; 80414505 E8 1E 0 FF FF 
	Push	rax	; 8041450A 50 
;/*	mov	0x00(rbp),rax	; 8041450B 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8041450F 
	DB 0x48,0x8D,0x6D,0x8
	call	_COUNT	; 80414513 E8 A9 FD FE FF 
	call	_SFIND	; 80414518 E8 43 DB FF FF 
;/  DUP 0= IF NIP NIP R> SWAP ELSE RDROP THEN
	call	_DUP	; 8041451D E8 6 0 FF FF 
	call	_0equ	; 80414522 E8 1B FE FE FF 
	test	rax,rax	; 80414527 48 85 C0 
;/*	mov	0x00(rbp),rax	; 8041452A 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8041452E 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_FIND+0x50 	; 80414532 
	DB 0xF,0x84,0x1D,0x0,0x0,0x0
	call	_NIP	; 80414538 E8 CF 0 FF FF 
	call	_NIP	; 8041453D E8 CA 0 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80414542 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80414546 58 
;/*	lea	-0x08(rbp),rbp	; 80414547 
	DB 0x48,0x8D,0x6D,0xF8
	call	_SWAP	; 8041454B E8 F2 FF FE FF 
;/*	jmp	_FIND+0x55 	; 80414550 
	DB 0xE9,0x5,0x0,0x0,0x0
;/*	lea	0x08(rsp),rsp	; 80414555 
	DB 0x48,0x8D,0x64,0x24,0x8
;/;
	ret		; 8041455A C3 
;/
;/: GET-ORDER ( -- widn ... wid1 n ) \ 94 SEARCH
;/  SP@ >R 0 >R


_GETsubORDER:
	call	_SPload	; 8041455B E8 3C FC FE FF 
	Push	rax	; 80414560 50 
;/*	mov	0x00(rbp),rax	; 80414561 
	DB 0x48,0x8B,0x45,0x0
;/*	mov	rax,0x00(rbp)	; 80414565 
	DB 0x48,0x89,0x45,0x0
;/*	mov	$0x0,eax	; 80414569 
	DB 0xB8,0x0,0x0,0x0,0x0
	Push	rax	; 8041456E 50 
;/*	mov	0x00(rbp),rax	; 8041456F 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414573 
	DB 0x48,0x8D,0x6D,0x8
;/  CONTEXT
	call	_CONTEXT	; 80414577 E8 7E FB 7E 0 
;/  BEGIN DUP @ ?DUP
	call	_DUP	; 8041457C E8 A7 FF FE FF 
	call	_load	; 80414581 E8 43 FC FE FF 
	call	_queDUP	; 80414586 E8 98 FF FE FF 
;/  WHILE >R CELL+
	test	rax,rax	; 8041458B 48 85 C0 
;/*	mov	0x00(rbp),rax	; 8041458E 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414592 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_GETsubORDER+0x54 	; 80414596 
	DB 0xF,0x84,0x13,0x0,0x0,0x0
	Push	rax	; 8041459C 50 
;/*	mov	0x00(rbp),rax	; 8041459D 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804145A1 
	DB 0x48,0x8D,0x6D,0x8
	call	_CELLadd	; 804145A5 E8 C4 FE FE FF 
;/  REPEAT  DROP
;/*	jmp	_GETsubORDER+0x21 	; 804145AA 
	DB 0xE9,0xCD,0xFF,0xFF,0xFF
	call	_DgreatS	; 804145AF E8 7F FB FE FF 
;/  BEGIN R> DUP 0=
;/*	mov	rax,-0x08(rbp)	; 804145B4 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 804145B8 58 
;/*	lea	-0x08(rbp),rbp	; 804145B9 
	DB 0x48,0x8D,0x6D,0xF8
	call	_DUP	; 804145BD E8 66 FF FE FF 
	call	_0equ	; 804145C2 E8 7B FD FE FF 
;/  UNTIL DROP
	test	rax,rax	; 804145C7 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804145CA 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804145CE 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_GETsubORDER+0x59 	; 804145D2 
	DB 0xF,0x84,0xDC,0xFF,0xFF,0xFF
	call	_DgreatS	; 804145D8 E8 56 FB FE FF 
;/  R> SP@ - 8 / 1-
;/*	mov	rax,-0x08(rbp)	; 804145DD 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 804145E1 58 
;/*	lea	-0x08(rbp),rbp	; 804145E2 
	DB 0x48,0x8D,0x6D,0xF8
	call	_SPload	; 804145E6 E8 B1 FB FE FF 
	call	_sub	; 804145EB E8 28 FE FE FF 
;/*	mov	rax,-0x08(rbp)	; 804145F0 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x8,eax	; 804145F4 
	DB 0xB8,0x8,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804145F9 
	DB 0x48,0x8D,0x6D,0xF8
	call	_rsl	; 804145FD E8 AA FE FE FF 
	call	_1sub	; 80414602 E8 83 FE FE FF 
;/;
	ret		; 80414607 C3 
;/
;/: BLANK BL FILL ;


_BLANK:
;/*	mov	rax,-0x08(rbp)	; 80414608 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x20,eax	; 8041460C 
	DB 0xB8,0x20,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80414611 
	DB 0x48,0x8D,0x6D,0xF8
	call	_FILL	; 80414615 E8 7A 0 FF FF 
	ret		; 8041461A C3 
;/
;/: ID. ( NFA[E] -> )  COUNT TYPE ;


_IDdot:
	call	_COUNT	; 8041461B E8 A1 FC FE FF 
	call	_TYPE	; 80414620 E8 27 7 FF FF 
	ret		; 80414625 C3 
;/
;/T: LATEST ( -> NFA )    CURRENT @ @ ;


_LATEST:
	call	_CURRENT	; 80414626 E8 D5 FA 7E 0 
	call	_load	; 8041462B E8 99 FB FE FF 
	call	_load	; 80414630 E8 94 FB FE FF 
	ret		; 80414635 C3 
;/
;/\ : [COMPILE] ' COMPILE, ; IMMEDIATE
;/
;/T: [COMPILE] ' COMPILE, ; IMMEDIATE


_xcCOMPILEyc:
	call	_tic	; 80414636 E8 F6 EE FF FF 
	call	_COMPILEcom	; 8041463B E8 6A CD FF FF 
	ret		; 80414640 C3 
;/
;/T: POSTPONE
;/\  ?COMP
;/  PARSE-NAME SFIND DUP


_POSTPONE:
	call	_PARSEsubNAME	; 80414641 E8 20 D8 FF FF 
	call	_SFIND	; 80414646 E8 15 DA FF FF 
	call	_DUP	; 8041464B E8 D8 FE FE FF 
;/ 0=	IF -13 THROW THEN
	call	_0equ	; 80414650 E8 ED FC FE FF 
	test	rax,rax	; 80414655 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80414658 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8041465C 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_POSTPONE+0x39 	; 80414660 
	DB 0xF,0x84,0x14,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 80414666 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0xD,rax	; 8041466A 
	DB 0x48,0xC7,0xC0,0xF3,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414671 
	DB 0x48,0x8D,0x6D,0xF8
	call	_THROW	; 80414675 E8 8A E FF FF 
;/ 1 = 	IF	COMPILE,
;/*	mov	rax,-0x08(rbp)	; 8041467A 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x1,eax	; 8041467E 
	DB 0xB8,0x1,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80414683 
	DB 0x48,0x8D,0x6D,0xF8
	call	_equ	; 80414687 E8 AE FC FE FF 
	test	rax,rax	; 8041468C 48 85 C0 
;/*	mov	0x00(rbp),rax	; 8041468F 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414693 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_POSTPONE+0x66 	; 80414697 
	DB 0xF,0x84,0xA,0x0,0x0,0x0
	call	_COMPILEcom	; 8041469D E8 8 CD FF FF 
;/	ELSE	LIT, ['] COMPILE, COMPILE,
;/*	jmp	_POSTPONE+0x7F 	; 804146A2 
	DB 0xE9,0x19,0x0,0x0,0x0
	call	_LITcom	; 804146A7 E8 8F CB FF FF 
;/*	mov	rax,-0x08(rbp)	; 804146AC 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_COMPILEcom(%rip),rax	; 804146B0 
	DB 0x48,0x8D,0x5,0xF3,0xCC,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804146B7 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COMPILEcom	; 804146BB E8 EA CC FF FF 
;/	THEN
;/; IMMEDIATE
	ret		; 804146C0 C3 
;/
;/T: BREAK  EXIT, [COMPILE] THEN ; IMMEDIATE


_BREAK:
	call	_EXITcom	; 804146C1 E8 94 F1 FF FF 
	call	_THEN	; 804146C6 E8 D3 F4 FF FF 
	ret		; 804146CB C3 
;/
;/: UPPER ( A L -- )
;/         OVER + SWAP


_UPPER:
	call	_OVER	; 804146CC E8 C8 FE FE FF 
	call	_add	; 804146D1 E8 45 FD FE FF 
	call	_SWAP	; 804146D6 E8 67 FE FE FF 
;/         ?DO I C@ DUP [CHAR] Z U>
	call	_cbigqueDOcend	; 804146DB E8 2A 0 FF FF 
	DQ _UPPER+0x83 
;/*	mov	rax,-0x08(rbp)	; 804146E8 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	r14,rax	; 804146EC 
	DB 0x4C,0x89,0xF0
;/*	lea	-0x08(rbp),rbp	; 804146EF 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Cload	; 804146F3 E8 D5 FA FE FF 
	call	_DUP	; 804146F8 E8 2B FE FE FF 
;/*	mov	rax,-0x08(rbp)	; 804146FD 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x5A,eax	; 80414701 
	DB 0xB8,0x5A,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80414706 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ugreat	; 8041470A E8 A1 FC FE FF 
;/            IF  0xDF AND
	test	rax,rax	; 8041470F 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80414712 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414716 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_UPPER+0x66 	; 8041471A 
	DB 0xF,0x84,0x12,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 80414720 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xDF,eax	; 80414724 
	DB 0xB8,0xDF,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80414729 
	DB 0x48,0x8D,0x6D,0xF8
	call	_AND	; 8041472D E8 B0 FC FE FF 
;/            THEN  I C!
;/*	mov	rax,-0x08(rbp)	; 80414732 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	r14,rax	; 80414736 
	DB 0x4C,0x89,0xF0
;/*	lea	-0x08(rbp),rbp	; 80414739 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Csave	; 8041473D E8 93 FA FE FF 
;/         LOOP ;
;/*	inc	r14	; 80414742 
	DB 0x49,0xFF,0xC6
;/*	inc	r15	; 80414745 
	DB 0x49,0xFF,0xC7
	jNo	_UPPER+0x1C 	; 80414748 71 9E 
	pop	r14	; 8041474A 41 5E 
	pop	r15	; 8041474C 41 5F 
	pop	rcx	; 8041474E 59 
	ret		; 8041474F C3 
;/
;/T: 1RP@  ['] RP@   COMPILE,


_1RPload:
;/*	mov	rax,-0x08(rbp)	; 80414750 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_RPload(%rip),rax	; 80414754 
	DB 0x48,0x8D,0x5,0xCA,0xF9,0xFE,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041475B 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COMPILEcom	; 8041475F E8 46 CC FF FF 
;/         ['] CELL+ COMPILE,  ; IMMEDIATE
;/*	mov	rax,-0x08(rbp)	; 80414764 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_CELLadd(%rip),rax	; 80414768 
	DB 0x48,0x8D,0x5,0xFF,0xFC,0xFE,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041476F 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COMPILEcom	; 80414773 E8 32 CC FF FF 
	ret		; 80414778 C3 
;/
;/T: 2RP@  [COMPILE] 1RP@


_2RPload:
	call	_1RPload	; 80414779 E8 D2 FF FF FF 
;/         ['] CELL+ COMPILE,  ; IMMEDIATE
;/*	mov	rax,-0x08(rbp)	; 8041477E 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_CELLadd(%rip),rax	; 80414782 
	DB 0x48,0x8D,0x5,0xE5,0xFC,0xFE,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414789 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COMPILEcom	; 8041478D E8 18 CC FF FF 
	ret		; 80414792 C3 
;/
;/T: 3RP@  [COMPILE] 2RP@


_3RPload:
	call	_2RPload	; 80414793 E8 E1 FF FF FF 
;/         ['] CELL+ COMPILE,  ; IMMEDIATE
;/*	mov	rax,-0x08(rbp)	; 80414798 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_CELLadd(%rip),rax	; 8041479C 
	DB 0x48,0x8D,0x5,0xCB,0xFC,0xFE,0xFF
;/*	lea	-0x08(rbp),rbp	; 804147A3 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COMPILEcom	; 804147A7 E8 FE CB FF FF 
	ret		; 804147AC C3 
;/
;/T: 4RP@  [COMPILE] 3RP@


_4RPload:
	call	_3RPload	; 804147AD E8 E1 FF FF FF 
;/         ['] CELL+ COMPILE,  ; IMMEDIATE
;/*	mov	rax,-0x08(rbp)	; 804147B2 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_CELLadd(%rip),rax	; 804147B6 
	DB 0x48,0x8D,0x5,0xB1,0xFC,0xFE,0xFF
;/*	lea	-0x08(rbp),rbp	; 804147BD 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COMPILEcom	; 804147C1 E8 E4 CB FF FF 
	ret		; 804147C6 C3 
;/
;/T: VOC-NAME. ( wid -- )
;/  DUP CELL+ CELL+ @ DUP


_VOCsubNAMEdot:
	call	_DUP	; 804147C7 E8 5C FD FE FF 
	call	_CELLadd	; 804147CC E8 9D FC FE FF 
	call	_CELLadd	; 804147D1 E8 98 FC FE FF 
	call	_load	; 804147D6 E8 EE F9 FE FF 
	call	_DUP	; 804147DB E8 48 FD FE FF 
;/ IF ID. DROP BREAK
	test	rax,rax	; 804147E0 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804147E3 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804147E7 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_VOCsubNAMEdot+0x35 	; 804147EB 
	DB 0xF,0x84,0xB,0x0,0x0,0x0
	call	_IDdot	; 804147F1 E8 25 FE FF FF 
	call	_DgreatS	; 804147F6 E8 38 F9 FE FF 
	ret		; 804147FB C3 
;/   DROP ." <NONAME>:" U. 
	call	_DgreatS	; 804147FC E8 32 F9 FE FF 
	call	_cbigSdticcend	; 80414801 E8 CD 6 FF FF 
	DB 0x9,0x3C,0x4E,0x4F,0x4E,0x41,0x4D,0x45,0x3E,0x3A
	call	_TYPE	; 80414810 E8 37 5 FF FF 
	call	_Udot	; 80414815 E8 A8 BD FF FF 
;/;
	ret		; 8041481A C3 
;/
;/: VOCS
;/        VOC-LIST


_VOCS:
	call	_VOCsubLIST	; 8041481B E8 CE F8 7E 0 
;/        BEGIN @ DUP WHILE
	call	_load	; 80414820 E8 A4 F9 FE FF 
	call	_DUP	; 80414825 E8 FE FC FE FF 
	test	rax,rax	; 8041482A 48 85 C0 
;/*	mov	0x00(rbp),rax	; 8041482D 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414831 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_VOCS+0x39 	; 80414835 
	DB 0xF,0x84,0x19,0x0,0x0,0x0
;/               DUP CELL-  VOC-NAME. SPACE
	call	_DUP	; 8041483B E8 E8 FC FE FF 
	call	_CELLsub	; 80414840 E8 3A FC FE FF 
	call	_VOCsubNAMEdot	; 80414845 E8 7D FF FF FF 
	call	_SPACE	; 8041484A E8 3F 7 FF FF 
;/        REPEAT
;/*	jmp	_VOCS+0x5 	; 8041484F 
	DB 0xE9,0xCC,0xFF,0xFF,0xFF
;/        DROP
	call	_DgreatS	; 80414854 E8 DA F8 FE FF 
;/;
	ret		; 80414859 C3 
;/
;/VARIABLE RP0

	DQ 0x0
	DB 0x0,0x0
;/
;/: WORDLIST ( --- wid)
;/  HERE	0 , 

_WORDLIST:
	call	_HERE	; 80414864 E8 64 C7 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80414869 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 8041486D 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80414872 
	DB 0x48,0x8D,0x6D,0xF8
	call	_com	; 80414876 E8 FC 3 FF FF 
;/  HERE  VOC-LIST @ , VOC-LIST !
	call	_HERE	; 8041487B E8 4D C7 FF FF 
	call	_VOCsubLIST	; 80414880 E8 69 F8 7E 0 
	call	_load	; 80414885 E8 3F F9 FE FF 
	call	_com	; 8041488A E8 E8 3 FF FF 
	call	_VOCsubLIST	; 8041488F E8 5A F8 7E 0 
	call	_save	; 80414894 E8 67 F9 FE FF 
;/	0 ,
;/*	mov	rax,-0x08(rbp)	; 80414899 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 8041489D 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804148A2 
	DB 0x48,0x8D,0x6D,0xF8
	call	_com	; 804148A6 E8 CC 3 FF FF 
;/\ Make a new wordlist and give its address.
;/;
	ret		; 804148AB C3 
;/
;/
;/T: VOCABULARY ( "<spaces>name" -- )
;/  WORDLIST


_VOCABULARY:
	call	_WORDLIST	; 804148AC E8 B3 FF FF FF 
;/  CREATE DUP ,
	call	_CREATE	; 804148B1 E8 9B F9 FF FF 
	call	_DUP	; 804148B6 E8 6D FC FE FF 
	call	_com	; 804148BB E8 B7 3 FF FF 
;/   CELL+ \ link
	call	_CELLadd	; 804148C0 E8 A9 FB FE FF 
;/   CELL+ LAST @ SWAP ! \ 
	call	_CELLadd	; 804148C5 E8 A4 FB FE FF 
;/*	mov	rax,-0x08(rbp)	; 804148CA 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22 (%rip),rax	; 804148CE 
	DB 0x48,0x8D,0x5,0x97,0xFE,0xFE,0xFF
;/*	lea	-0x08(rbp),rbp	; 804148D5 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 804148D9 E8 EB F8 FE FF 
	call	_SWAP	; 804148DE E8 5F FC FE FF 
	call	_save	; 804148E3 E8 18 F9 FE FF 
;/  DOES> @ CONTEXT ! ;
	call	_cbigDOESgreatcend	; 804148E8 E8 53 FA FF FF 
;/*	mov	rax,-0x08(rbp)	; 804148ED 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 804148F1 58 
;/*	lea	-0x08(rbp),rbp	; 804148F2 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 804148F6 E8 CE F8 FE FF 
	call	_CONTEXT	; 804148FB E8 FA F7 7E 0 
	call	_save	; 80414900 E8 FB F8 FE FF 
	ret		; 80414905 C3 
;/
;/: VARY ( "<spaces>name" -- )
;/  CREATE 77 ,


_VARY:
	call	_CREATE	; 80414906 E8 46 F9 FF FF 
;/*	mov	rax,-0x08(rbp)	; 8041490B 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x4D,eax	; 8041490F 
	DB 0xB8,0x4D,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80414914 
	DB 0x48,0x8D,0x6D,0xF8
	call	_com	; 80414918 E8 5A 3 FF FF 
;/  DOES> @  ;
	call	_cbigDOESgreatcend	; 8041491D E8 1E FA FF FF 
;/*	mov	rax,-0x08(rbp)	; 80414922 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80414926 58 
;/*	lea	-0x08(rbp),rbp	; 80414927 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 8041492B E8 99 F8 FE FF 
	ret		; 80414930 C3 
;/
;/
;/T: ALSO ( --- )
;/\ Duplicate the last wordlist in the search order.
;/ CONTEXT CONTEXT  CELL+ CONTEXT_SIZE CELL-  CMOVE> ;


_ALSO:
	call	_CONTEXT	; 80414931 E8 C4 F7 7E 0 
	call	_CONTEXT	; 80414936 E8 BF F7 7E 0 
	call	_CELLadd	; 8041493B E8 2E FB FE FF 
	call	_CONTEXT_SIZE	; 80414940 E8 AF F7 7E 0 
	call	_CELLsub	; 80414945 E8 35 FB FE FF 
	call	_CMOVEgreat	; 8041494A E8 B F8 7E 0 
	ret		; 8041494F C3 
;/
;/T: FORTH FORTH-WORDLIST CONTEXT ! ;


_FORTH:
	call	_FORTHsubWORDLIST	; 80414950 E8 93 F7 7E 0 
	call	_CONTEXT	; 80414955 E8 A0 F7 7E 0 
	call	_save	; 8041495A E8 A1 F8 FE FF 
	ret		; 8041495F C3 
;/
;/T: ONLY ( --- )
;/ FORTH CONTEXT CELL+ 0! ;


_ONLY:
	call	_FORTH	; 80414960 E8 EB FF FF FF 
	call	_CONTEXT	; 80414965 E8 90 F7 7E 0 
	call	_CELLadd	; 8041496A E8 FF FA FE FF 
	call	_OFF	; 8041496F E8 5 F9 FE FF 
	ret		; 80414974 C3 
;/
;/T: PREVIOUS ( --- )
;/\ Remove the last wordlist from search order.
;/ CONTEXT CELL+ CONTEXT CONTEXT_SIZE CMOVE  ;


_PREVIOUS:
	call	_CONTEXT	; 80414975 E8 80 F7 7E 0 
	call	_CELLadd	; 8041497A E8 EF FA FE FF 
	call	_CONTEXT	; 8041497F E8 76 F7 7E 0 
	call	_CONTEXT_SIZE	; 80414984 E8 6B F7 7E 0 
	call	_CMOVE	; 80414989 E8 3F FD FE FF 
	ret		; 8041498E C3 
;/
;/: SET-ORDER
;/  DUP -1 = IF DROP ONLY BREAK


_SETsubORDER:
	call	_DUP	; 8041498F E8 94 FB FE FF 
;/*	mov	rax,-0x08(rbp)	; 80414994 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0x1,rax	; 80414998 
	DB 0x48,0xC7,0xC0,0xFF,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8041499F 
	DB 0x48,0x8D,0x6D,0xF8
	call	_equ	; 804149A3 E8 92 F9 FE FF 
	test	rax,rax	; 804149A8 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804149AB 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804149AF 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_SETsubORDER+0x35 	; 804149B3 
	DB 0xF,0x84,0xB,0x0,0x0,0x0
	call	_DgreatS	; 804149B9 E8 75 F7 FE FF 
	call	_ONLY	; 804149BE E8 9D FF FF FF 
	ret		; 804149C3 C3 
;/  DUP 0= IF CONTEXT ! BREAK
	call	_DUP	; 804149C4 E8 5F FB FE FF 
	call	_0equ	; 804149C9 E8 74 F9 FE FF 
	test	rax,rax	; 804149CE 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804149D1 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804149D5 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_SETsubORDER+0x5B 	; 804149D9 
	DB 0xF,0x84,0xB,0x0,0x0,0x0
	call	_CONTEXT	; 804149DF E8 16 F7 7E 0 
	call	_save	; 804149E4 E8 17 F8 FE FF 
	ret		; 804149E9 C3 
;/  0
;/*	mov	rax,-0x08(rbp)	; 804149EA 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 804149EE 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804149F3 
	DB 0x48,0x8D,0x6D,0xF8
;/  DO CONTEXT I CELLS +
	call	_cbigDOcend	; 804149F7 E8 14 FD FE FF 
	DQ _SETsubORDER+0xB0 
	call	_CONTEXT	; 80414A04 E8 F1 F6 7E 0 
;/*	mov	rax,-0x08(rbp)	; 80414A09 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	r14,rax	; 80414A0D 
	DB 0x4C,0x89,0xF0
;/*	lea	-0x08(rbp),rbp	; 80414A10 
	DB 0x48,0x8D,0x6D,0xF8
	call	_CELLS	; 80414A14 E8 75 FA FE FF 
	call	_add	; 80414A19 E8 FD F9 FE FF 
;/     DUP CELL+ 0!  !
	call	_DUP	; 80414A1E E8 5 FB FE FF 
	call	_CELLadd	; 80414A23 E8 46 FA FE FF 
	call	_OFF	; 80414A28 E8 4C F8 FE FF 
	call	_save	; 80414A2D E8 CE F7 FE FF 
;/  LOOP
;/*	inc	r14	; 80414A32 
	DB 0x49,0xFF,0xC6
;/*	inc	r15	; 80414A35 
	DB 0x49,0xFF,0xC7
	jNo	_SETsubORDER+0x75 	; 80414A38 71 CA 
	pop	r14	; 80414A3A 41 5E 
	pop	r15	; 80414A3C 41 5F 
	pop	rcx	; 80414A3E 59 
;/;
	ret		; 80414A3F C3 
;/
;/T: ORDER ( -- ) \ 94 SEARCH EXT
;/  GET-ORDER ." Context: "


_ORDER:
	call	_GETsubORDER	; 80414A40 E8 16 FB FF FF 
	call	_cbigSdticcend	; 80414A45 E8 89 4 FF FF 
	DB 0x9,0x43,0x6F,0x6E,0x74,0x65,0x78,0x74,0x3A,0x20
	call	_TYPE	; 80414A54 E8 F3 2 FF FF 
;/  0 ?DO ( DUP .) VOC-NAME. SPACE LOOP CR
;/*	mov	rax,-0x08(rbp)	; 80414A59 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80414A5D 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80414A62 
	DB 0x48,0x8D,0x6D,0xF8
	call	_cbigqueDOcend	; 80414A66 E8 9F FC FE FF 
	DQ _ORDER+0x4A 
	call	_VOCsubNAMEdot	; 80414A73 E8 4F FD FF FF 
	call	_SPACE	; 80414A78 E8 11 5 FF FF 
;/*	inc	r14	; 80414A7D 
	DB 0x49,0xFF,0xC6
;/*	inc	r15	; 80414A80 
	DB 0x49,0xFF,0xC7
	jNo	_ORDER+0x33 	; 80414A83 71 EE 
	pop	r14	; 80414A85 41 5E 
	pop	r15	; 80414A87 41 5F 
	pop	rcx	; 80414A89 59 
	call	_CR	; 80414A8A E8 EF 2 FF FF 
;/  ." Current: " GET-CURRENT VOC-NAME. CR
	call	_cbigSdticcend	; 80414A8F E8 3F 4 FF FF 
	DB 0x9,0x43,0x75,0x72,0x72,0x65,0x6E,0x74,0x3A,0x20
	call	_TYPE	; 80414A9E E8 A9 2 FF FF 
	call	_GETsubCURRENT	; 80414AA3 E8 46 F4 FF FF 
	call	_VOCsubNAMEdot	; 80414AA8 E8 1A FD FF FF 
	call	_CR	; 80414AAD E8 CC 2 FF FF 
;/;
	ret		; 80414AB2 C3 
;/
;/T: HEX HEX ;


_HEX:
;/*	mov	rax,-0x08(rbp)	; 80414AB3 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x10,eax	; 80414AB7 
	DB 0xB8,0x10,0x0,0x0,0x0
;/*	mov	rax,-0x10(rbp)	; 80414ABC 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_UNLOOP+0x472 (%rip),rax	; 80414AC0 
	DB 0x48,0x8D,0x5,0xF5,0x0,0xFF,0xFF
;/*	lea	-0x10(rbp),rbp	; 80414AC7 
	DB 0x48,0x8D,0x6D,0xF0
	call	_save	; 80414ACB E8 30 F7 FE FF 
	ret		; 80414AD0 C3 
;/
;/: ALIAS  ( cfa -- ) 
;/ PARSE-NAME SHEADER


_ALIAS:
	call	_PARSEsubNAME	; 80414AD1 E8 90 D3 FF FF 
	call	_SHEADER	; 80414AD6 E8 78 F6 FF FF 
;/ LAST @  NAME>C !
;/*	mov	rax,-0x08(rbp)	; 80414ADB 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x22 (%rip),rax	; 80414ADF 
	DB 0x48,0x8D,0x5,0x86,0xFC,0xFE,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414AE6 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80414AEA E8 DA F6 FE FF 
	call	_NAMEgreatC	; 80414AEF E8 82 FB FE FF 
	call	_save	; 80414AF4 E8 7 F7 FE FF 
;/;
	ret		; 80414AF9 C3 
;/
;/T: : PARSE-NAME  SBUILD  ] ;


_dcoma:
	call	_PARSEsubNAME	; 80414AFA E8 67 D3 FF FF 
	call	_SBUILD	; 80414AFF E8 B8 F4 FF FF 
	call	_yc	; 80414B04 E8 BE E1 FF FF 
	ret		; 80414B09 C3 
;/
;/T: ; ?COMP  EXIT,


_end:
	call	_queCOMP	; 80414B0A E8 81 EC FF FF 
	call	_EXITcom	; 80414B0F E8 46 ED FF FF 
;/ SMUDGE
	call	_SMUDGE	; 80414B14 E8 16 F6 FF FF 
;/ [COMPILE] [ ; IMMEDIATE
	call	_xc	; 80414B19 E8 BE E1 FF FF 
	ret		; 80414B1E C3 
;/
;/1 [IF]
;/T: FIELD  ( offset size "new-name< >" -- offset+size )
;/      : OVER


_FIELD:
	call	_dcoma	; 80414B1F E8 D6 FF FF FF 
	call	_OVER	; 80414B24 E8 70 FA FE FF 
;/        DUP IF   DUP  LIT,  ['] + COMPILE,
	call	_DUP	; 80414B29 E8 FA F9 FE FF 
	test	rax,rax	; 80414B2E 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80414B31 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414B35 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_FIELD+0x3E 	; 80414B39 
	DB 0xF,0x84,0x1E,0x0,0x0,0x0
	call	_DUP	; 80414B3F E8 E4 F9 FE FF 
	call	_LITcom	; 80414B44 E8 F2 C6 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80414B49 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_add(%rip),rax	; 80414B4D 
	DB 0x48,0x8D,0x5,0xC7,0xF8,0xFE,0xFF
;/*	lea	-0x08(rbp),rbp	; 80414B54 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COMPILEcom	; 80414B58 E8 4D C8 FF FF 
;/            THEN DROP
	call	_DgreatS	; 80414B5D E8 D1 F5 FE FF 
;/       [COMPILE] ;
	call	_end	; 80414B62 E8 A3 FF FF FF 
;/       + ;  
	call	_add	; 80414B67 E8 AF F8 FE FF 
	ret		; 80414B6C C3 
;/[ELSE]
;/T: FIELD
;/  CREATE OVER , + 
;/  DOES> @ +
;/;
;/[THEN]
;/
;/1 CONSTANT &IMMEDIATE
;/
;/T: IMMEDIATE
;/  &IMMEDIATE LAST @ NAME>F LOR!


_IMMEDIATE:
;/*	mov	rax,-0x08(rbp)	; 80414B6D 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x1,eax	; 80414B71 
	DB 0xB8,0x1,0x0,0x0,0x0
;/*	mov	rax,-0x10(rbp)	; 80414B76 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_UNLOOP+0x22 (%rip),rax	; 80414B7A 
	DB 0x48,0x8D,0x5,0xEB,0xFB,0xFE,0xFF
;/*	lea	-0x10(rbp),rbp	; 80414B81 
	DB 0x48,0x8D,0x6D,0xF0
	call	_load	; 80414B85 E8 3F F6 FE FF 
	call	_NAMEgreatF	; 80414B8A E8 F1 FA FE FF 
	call	_LORsave	; 80414B8F E8 AA F6 FE FF 
;/;
	ret		; 80414B94 C3 
;/
;/VARIABLE EMITVAR

	DQ 0x0
	DB 0x0,0x0,0x0
