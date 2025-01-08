;/	
;/\- DOCREATE	: DOCREATE	R> ;
;/\- DOCONSTANT	: DOCONSTANT	R> @ ;
;/\- DOVALUE	: DOTVALUE	R> @ ;
;/\- DOVECT 	: DOVECT	R> PERFORM ;
;/\- DOFIELD	: DOFIELD	R> L@ + ;

_DOFIELD:
;/*	mov	rax,-0x08(rbp)	; 80404BC4 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80404BC8 58 
;/*	lea	-0x08(rbp),rbp	; 80404BC9 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Lload	; 80404BCD E8 F4 F5 FF FF 
	call	_add	; 80404BD2 E8 44 F8 FF FF 
	ret		; 80404BD7 C3 
;/
;/' DOCREATE TO 'DOCREATE
;/' DOCONSTANT TO 'DOCONSTANT
;/' DOVALUE TO 'DOVALUE
;/' DOVECT TO 'DOVECT
;/' DOFIELD TO 'DOFIELD
;/
;/VARIABLE SP0

	DQ 0x0
;/VARIABLE &INPUT
	DQ 0x0
;/VARIABLE &INPUT?
	DQ 0x0
;/
;/VARIABLE &OUTPUT
	DQ 0x0
;/
;/0 VALUE  H-STDIN    \ хэндл файла - стандартного ввода

_HsubSTDIN:
	call	_DOVALUE	; 80404BF8 E8 E7 FA FF FF 

	DQ 0x0
;/1 VALUE  H-STDOUT   \ хэндл файла - стандартного вывода

_HsubSTDOUT:
	call	_DOVALUE	; 80404C05 E8 DA FA FF FF 

	DQ 0x1
;/1 VALUE  H-STDERR   \ хэндл файла - стандартного вывода ошибок

_HsubSTDERR:
	call	_DOVALUE	; 80404C12 E8 CD FA FF FF 

	DQ 0x1
;/
;/CREATE &START_INIT ' NOOP ,
	DQ 0x53+fimg
;/\ CREATE DP ' DPBuff ,
;/VARIABLE DP
	DQ 0x0
	DB 0x0
;/
;/VARIABLE EMITVAR
	DQ 0x0
;/
;/T: THERE DP @ ;

_THERE:
;/*	mov	rax,-0x08(rbp)	; 80404C38 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_HsubSTDERR+0x16 (%rip),rax	; 80404C3C 
	DB 0x48,0x8D,0x5,0xE5,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80404C43 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80404C47 E8 7D F5 FF FF 
	ret		; 80404C4C C3 
;/
;/T: ALLOT DP +! ;


_ALLOT:
;/*	mov	rax,-0x08(rbp)	; 80404C4D 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_HsubSTDERR+0x16 (%rip),rax	; 80404C51 
	DB 0x48,0x8D,0x5,0xD0,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80404C58 
	DB 0x48,0x8D,0x6D,0xF8
	call	_addsave	; 80404C5C E8 AF F5 FF FF 
	ret		; 80404C61 C3 
;/
;/T: DP! DP ! ;


_DPsave:
;/*	mov	rax,-0x08(rbp)	; 80404C62 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_HsubSTDERR+0x16 (%rip),rax	; 80404C66 
	DB 0x48,0x8D,0x5,0xBB,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80404C6D 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 80404C71 E8 8A F5 FF FF 
	ret		; 80404C76 C3 
;/
;/T: ,   THERE ! 8 ALLOT ;


_com:
	call	_THERE	; 80404C77 E8 BC FF FF FF 
	call	_save	; 80404C7C E8 7F F5 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80404C81 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x8,eax	; 80404C85 
	DB 0xB8,0x8,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80404C8A 
	DB 0x48,0x8D,0x6D,0xF8
	call	_ALLOT	; 80404C8E E8 BA FF FF FF 
	ret		; 80404C93 C3 
;/
;/T: L, THERE L! 4 ALLOT ;


_Lcom:
	call	_THERE	; 80404C94 E8 9F FF FF FF 
	call	_Lsave	; 80404C99 E8 54 F5 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80404C9E 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x4,eax	; 80404CA2 
	DB 0xB8,0x4,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80404CA7 
	DB 0x48,0x8D,0x6D,0xF8
	call	_ALLOT	; 80404CAB E8 9D FF FF FF 
	ret		; 80404CB0 C3 
;/
;/T: W, THERE W! 2 ALLOT ;


_Wcom:
	call	_THERE	; 80404CB1 E8 82 FF FF FF 
	call	_Wsave	; 80404CB6 E8 28 F5 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80404CBB 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x2,eax	; 80404CBF 
	DB 0xB8,0x2,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80404CC4 
	DB 0x48,0x8D,0x6D,0xF8
	call	_ALLOT	; 80404CC8 E8 80 FF FF FF 
	ret		; 80404CCD C3 
;/
;/T: C, THERE C! 1 ALLOT ;


_Ccom:
	call	_THERE	; 80404CCE E8 65 FF FF FF 
	call	_Csave	; 80404CD3 E8 FD F4 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80404CD8 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x1,eax	; 80404CDC 
	DB 0xB8,0x1,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80404CE1 
	DB 0x48,0x8D,0x6D,0xF8
	call	_ALLOT	; 80404CE5 E8 63 FF FF FF 
	ret		; 80404CEA C3 
;/
;/' EMIT_M ->DEFER EMIT


_EMIT:
	call	_DOVECT	; 80404CEB E8 C FA FF FF 
	DQ _EMIT_M

;/
;/: TYPE_M ( c-addr1 u --- )
;/\ Output the string starting at c-addr and length u to the terminal.
;/\ CC_LINES
;/  0 ?DO COUNT EMIT LOOP DROP

_TYPE_M:
;/*	mov	rax,-0x08(rbp)	; 80404CF8 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80404CFC 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80404D01 
	DB 0x48,0x8D,0x6D,0xF8
	call	_cbigqueDOcend	; 80404D05 E8 0 FA FF FF 
	DQ _TYPE_M+0x31 
	call	_COUNT	; 80404D12 E8 AA F5 FF FF 
	call	_EMIT	; 80404D17 E8 CF FF FF FF 
;/*	inc	r14	; 80404D1C 
	DB 0x49,0xFF,0xC6
;/*	inc	r15	; 80404D1F 
	DB 0x49,0xFF,0xC7
	jNo	_TYPE_M+0x1A 	; 80404D22 71 EE 
	pop	r14	; 80404D24 41 5E 
	pop	r15	; 80404D26 41 5F 
	pop	rcx	; 80404D28 59 
	call	_DgreatS	; 80404D29 E8 5 F4 FF FF 
;/;
	ret		; 80404D2E C3 
;/
;/: TYPE1 ( c-addr u -- ) \ 94
;/  H-STDOUT \ DUP 0= IF DROP 2DROP BREAK


_TYPE1:
;/*	mov	rax,-0x08(rbp)	; 80404D2F 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_HsubSTDOUT+0x5 (%rip),rax	; 80404D33 
	DB 0x48,0x8D,0x5,0xD0,0xFE,0xFF,0xFF
;/*	mov	(rax),rax	; 80404D3A 
	DB 0x48,0x8B,0x0
;/*	lea	-0x08(rbp),rbp	; 80404D3D 
	DB 0x48,0x8D,0x6D,0xF8
;/  WRITE-FILE DROP \ THROW  !!!!!
	call	_WRITEsubFILE	; 80404D41 E8 D8 F3 7F 0 
	call	_DgreatS	; 80404D46 E8 E8 F3 FF FF 
;/;
	ret		; 80404D4B C3 
;/
;/' TYPE1 ->DEFER TYPE


_TYPE:
	call	_DOVECT	; 80404D4C E8 AB F9 FF FF 
	DQ _TYPE1

;/
;/: CR1 	$d EMIT	$a EMIT ;

_CR1:
;/*	mov	rax,-0x08(rbp)	; 80404D59 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xD,eax	; 80404D5D 
	DB 0xB8,0xD,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80404D62 
	DB 0x48,0x8D,0x6D,0xF8
	call	_EMIT	; 80404D66 E8 80 FF FF FF 
;/*	mov	rax,-0x08(rbp)	; 80404D6B 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xA,eax	; 80404D6F 
	DB 0xB8,0xA,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80404D74 
	DB 0x48,0x8D,0x6D,0xF8
	call	_EMIT	; 80404D78 E8 6E FF FF FF 
	ret		; 80404D7D C3 
;/' CR1 ->defer CR


_CR:
	call	_DOVECT	; 80404D7E E8 79 F9 FF FF 
	DQ _CR1

;/
;/VARIABLE TEXTINPUEX
	DQ 0x0
	DB 0x0
;/VARIABLE IVANTID
	DQ 0x0
;/
;/0 VALUE BOOTSERV

_BOOTSERV:
	call	_DOVALUE	; 80404D9C E8 43 F9 FF FF 

	DQ 0x0
;/0 VALUE VOLUME

_VOLUME:
	call	_DOVALUE	; 80404DA9 E8 36 F9 FF FF 

	DQ 0x0
;/
;/: KEY?EX ( -- flg )
;/ ;

_KEYqueEX:
	ret		; 80404DB6 C3 
;/
;/: SHIFT@  ;


_SHIFTload:
	ret		; 80404DB7 C3 
;/: CTL@  ;


_CTLload:
	ret		; 80404DB8 C3 
;/: ALT@  ;


_ALTload:
	ret		; 80404DB9 C3 
;/
;/' KEY?EX ->DEFER KEY?


_KEYque:
	call	_DOVECT	; 80404DBA E8 3D F9 FF FF 
	DQ _KEYqueEX

;/
;/' OS_KEY ->DEFER KEY

_KEY:
	call	_DOVECT	; 80404DC7 E8 30 F9 FF FF 
	DQ _OS_KEY

;/
;/: TAB	9  EMIT ;

_TAB:
;/*	mov	rax,-0x08(rbp)	; 80404DD4 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x9,eax	; 80404DD8 
	DB 0xB8,0x9,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80404DDD 
	DB 0x48,0x8D,0x6D,0xF8
	call	_EMIT	; 80404DE1 E8 5 FF FF FF 
	ret		; 80404DE6 C3 
;/
;/T: HALIGNED  1+  1 ANDC ;


_HALIGNED:
	call	_CHARadd	; 80404DE7 E8 8F F6 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80404DEC 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x1,eax	; 80404DF0 
	DB 0xB8,0x1,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80404DF5 
	DB 0x48,0x8D,0x6D,0xF8
	call	_ANDC	; 80404DF9 E8 E1 F5 FF FF 
	ret		; 80404DFE C3 
;/T: IALIGNED  3 + 3 ANDC ;


_IALIGNED:
;/*	mov	rax,-0x08(rbp)	; 80404DFF 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x3,eax	; 80404E03 
	DB 0xB8,0x3,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80404E08 
	DB 0x48,0x8D,0x6D,0xF8
	call	_add	; 80404E0C E8 A F6 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80404E11 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x3,eax	; 80404E15 
	DB 0xB8,0x3,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80404E1A 
	DB 0x48,0x8D,0x6D,0xF8
	call	_ANDC	; 80404E1E E8 BC F5 FF FF 
	ret		; 80404E23 C3 
;/T: QALIGNED  7 + 7 ANDC ;


_QALIGNED:
;/*	mov	rax,-0x08(rbp)	; 80404E24 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x7,eax	; 80404E28 
	DB 0xB8,0x7,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80404E2D 
	DB 0x48,0x8D,0x6D,0xF8
	call	_add	; 80404E31 E8 E5 F5 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80404E36 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x7,eax	; 80404E3A 
	DB 0xB8,0x7,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80404E3F 
	DB 0x48,0x8D,0x6D,0xF8
	call	_ANDC	; 80404E43 E8 97 F5 FF FF 
	ret		; 80404E48 C3 
;/
;/CREATE ALIGN-BYTES 8 ,

	DQ 0x8
;/
;/T: ALIGNED ( addr -- a-addr ) \ 94
;/\ a-addr - первый выровненный адрес, больший или равный addr.
;/  ALIGN-BYTES @ DUP 0= IF 1+ DUP ALIGN-BYTES ! THEN

_ALIGNED:
;/*	mov	rax,-0x08(rbp)	; 80404E51 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_QALIGNED+0x25 (%rip),rax	; 80404E55 
	DB 0x48,0x8D,0x5,0xED,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80404E5C 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80404E60 E8 64 F3 FF FF 
	call	_DUP	; 80404E65 E8 BE F6 FF FF 
	call	_0equ	; 80404E6A E8 D3 F4 FF FF 
	test	rax,rax	; 80404E6F 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80404E72 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80404E76 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_ALIGNED+0x4D 	; 80404E7A 
	DB 0xF,0x84,0x1E,0x0,0x0,0x0
	call	_CHARadd	; 80404E80 E8 F6 F5 FF FF 
	call	_DUP	; 80404E85 E8 9E F6 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80404E8A 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_QALIGNED+0x25 (%rip),rax	; 80404E8E 
	DB 0x48,0x8D,0x5,0xB4,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80404E95 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 80404E99 E8 62 F3 FF FF 
;/  2DUP
	call	_2DUP	; 80404E9E E8 8E F6 FF FF 
;/  MOD DUP IF - + ELSE 2DROP THEN ;
	call	_MOD	; 80404EA3 E8 15 F6 FF FF 
	call	_DUP	; 80404EA8 E8 7B F6 FF FF 
	test	rax,rax	; 80404EAD 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80404EB0 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80404EB4 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_ALIGNED+0x7C 	; 80404EB8 
	DB 0xF,0x84,0xF,0x0,0x0,0x0
	call	_sub	; 80404EBE E8 55 F5 FF FF 
	call	_add	; 80404EC3 E8 53 F5 FF FF 
;/*	jmp	_ALIGNED+0x81 	; 80404EC8 
	DB 0xE9,0x5,0x0,0x0,0x0
	call	_2DROP	; 80404ECD E8 9A F6 FF FF 
	ret		; 80404ED2 C3 
;/
;/: (S")  ( --- c-addr u )
;/\ Runtime part of S"
;/\ It returns address and length of an in-line counted string.
;/  R>  COUNT 2DUP + >R ;


_cbigSdticcend:
;/*	mov	rax,-0x08(rbp)	; 80404ED3 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80404ED7 58 
;/*	lea	-0x08(rbp),rbp	; 80404ED8 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COUNT	; 80404EDC E8 E0 F3 FF FF 
	call	_2DUP	; 80404EE1 E8 4B F6 FF FF 
	call	_add	; 80404EE6 E8 30 F5 FF FF 
	Push	rax	; 80404EEB 50 
;/*	mov	0x00(rbp),rax	; 80404EEC 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80404EF0 
	DB 0x48,0x8D,0x6D,0x8
	ret		; 80404EF4 C3 
;/
;/\+ '(S") ' (S") TO '(S")
;/
;/: (Z")  ( --- c-addr u )
;/\ Runtime part of S"
;/\ It returns address and length of an in-line counted string.
;/  R>  COUNT OVER + 1+ >R ;


_cbigZdticcend:
;/*	mov	rax,-0x08(rbp)	; 80404EF5 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80404EF9 58 
;/*	lea	-0x08(rbp),rbp	; 80404EFA 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COUNT	; 80404EFE E8 BE F3 FF FF 
	call	_OVER	; 80404F03 E8 91 F6 FF FF 
	call	_add	; 80404F08 E8 E F5 FF FF 
	call	_CHARadd	; 80404F0D E8 69 F5 FF FF 
	Push	rax	; 80404F12 50 
;/*	mov	0x00(rbp),rax	; 80404F13 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80404F17 
	DB 0x48,0x8D,0x6D,0x8
	ret		; 80404F1B C3 
;/
;/: (C")  ( --- c-addr )
;/   R> DUP COUNT +  >R ;


_cbigCdticcend:
;/*	mov	rax,-0x08(rbp)	; 80404F1C 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80404F20 58 
;/*	lea	-0x08(rbp),rbp	; 80404F21 
	DB 0x48,0x8D,0x6D,0xF8
	call	_DUP	; 80404F25 E8 FE F5 FF FF 
	call	_COUNT	; 80404F2A E8 92 F3 FF FF 
	call	_add	; 80404F2F E8 E7 F4 FF FF 
	Push	rax	; 80404F34 50 
;/*	mov	0x00(rbp),rax	; 80404F35 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80404F39 
	DB 0x48,0x8D,0x6D,0x8
	ret		; 80404F3D C3 
;/
;/\+ '(C") ' (C") TO '(C")
;/
;/: DEPTH ( -- n ) \ 94
;/  SP@ SP0 @ - NEGATE  3 ARSHIFT ;


_DEPTH:
	call	_SPload	; 80404F3E E8 59 F2 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80404F43 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_DOFIELD+0x14 (%rip),rax	; 80404F47 
	DB 0x48,0x8D,0x5,0x8A,0xFC,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80404F4E 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80404F52 E8 72 F2 FF FF 
	call	_sub	; 80404F57 E8 BC F4 FF FF 
	call	_NEGATE	; 80404F5C E8 A0 F4 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80404F61 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x3,eax	; 80404F65 
	DB 0xB8,0x3,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80404F6A 
	DB 0x48,0x8D,0x6D,0xF8
	call	_ARSHIFT	; 80404F6E E8 C0 F6 FF FF 
	ret		; 80404F73 C3 
;/
;/\ T: ERASE 0 FILL ;
;/
;/: WCOUNT DUP W@ SWAP 2+ SWAP ;


_WCOUNT:
	call	_DUP	; 80404F74 E8 AF F5 FF FF 
	call	_Wload	; 80404F79 E8 53 F2 FF FF 
	call	_SWAP	; 80404F7E E8 BF F5 FF FF 
	call	_2add	; 80404F83 E8 F0 F4 FF FF 
	call	_SWAP	; 80404F88 E8 B5 F5 FF FF 
	ret		; 80404F8D C3 
;/
;/: SPACE BL EMIT ;


_SPACE:
;/*	mov	rax,-0x08(rbp)	; 80404F8E 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x20,eax	; 80404F92 
	DB 0xB8,0x20,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80404F97 
	DB 0x48,0x8D,0x6D,0xF8
	call	_EMIT	; 80404F9B E8 4B FD FF FF 
	ret		; 80404FA0 C3 
;/
;/: 0MAX 0 MAX ;


_0MAX:
;/*	mov	rax,-0x08(rbp)	; 80404FA1 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80404FA5 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80404FAA 
	DB 0x48,0x8D,0x6D,0xF8
	call	_MAX	; 80404FAE E8 62 F3 FF FF 
	ret		; 80404FB3 C3 
;/
;/: 3DUP DUP 2OVER ROT ;


_3DUP:
	call	_DUP	; 80404FB4 E8 6F F5 FF FF 
	call	_2OVER	; 80404FB9 E8 E8 F5 FF FF 
	call	_ROT	; 80404FBE E8 4E F6 FF FF 
	ret		; 80404FC3 C3 
;/
;/: BOUNDS OVER + SWAP ;


_BOUNDS:
	call	_OVER	; 80404FC4 E8 D0 F5 FF FF 
	call	_add	; 80404FC9 E8 4D F4 FF FF 
	call	_SWAP	; 80404FCE E8 6F F5 FF FF 
	ret		; 80404FD3 C3 
;/
;/: U<= U> 0= ;


_Ulessequ:
	call	_Ugreat	; 80404FD4 E8 D7 F3 FF FF 
	call	_0equ	; 80404FD9 E8 64 F3 FF FF 
	ret		; 80404FDE C3 
;/
;/: CS-ROLL  2* 1+ DUP>R ROLL R> ROLL ;


_CSsubROLL:
	call	_2mul	; 80404FDF E8 B2 F4 FF FF 
	call	_CHARadd	; 80404FE4 E8 92 F4 FF FF 
	Push	rax	; 80404FE9 50 
	call	_ROLL	; 80404FEA E8 E3 F5 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80404FEF 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80404FF3 58 
;/*	lea	-0x08(rbp),rbp	; 80404FF4 
	DB 0x48,0x8D,0x6D,0xF8
	call	_ROLL	; 80404FF8 E8 D5 F5 FF FF 
	ret		; 80404FFD C3 
;/
;/: D2*      ( D -- D*2 )        2DUP D+     ;


_D2mul:
	call	_2DUP	; 80404FFE E8 2E F5 FF FF 
	call	_Dadd	; 80405003 E8 1C F4 FF FF 
	ret		; 80405008 C3 
;/: DABS     ( d -- ud )         DUP 0< IF DNEGATE THEN  ;


_DABS:
	call	_DUP	; 80405009 E8 1A F5 FF FF 
	call	_0less	; 8040500E E8 98 F3 FF FF 
	test	rax,rax	; 80405013 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80405016 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8040501A 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_DABS+0x20 	; 8040501E 
	DB 0xF,0x84,0x5,0x0,0x0,0x0
	call	_DNEGATE	; 80405024 E8 DC F3 FF FF 
	ret		; 80405029 C3 
;/
;/: U/MOD 0 SWAP UM/MOD ;


_UrslMOD:
;/*	mov	rax,-0x08(rbp)	; 8040502A 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 8040502E 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80405033 
	DB 0x48,0x8D,0x6D,0xF8
	call	_SWAP	; 80405037 E8 6 F5 FF FF 
	call	_UMrslMOD	; 8040503C E8 CB F4 FF FF 
	ret		; 80405041 C3 
;/
;/\ : U/ ( n1 n2 -- n1*n2 ) U/MOD  NIP ;
;/
;/\ : UMOD ( n1 n2 -- n1%n2 )  U/MOD DROP ;
;/
;/: MOVE ( addr1 addr2 u -- ) \ 94	
;/  >R 2DUP SWAP R@ + U<


_MOVE:
	Push	rax	; 80405042 50 
;/*	mov	0x00(rbp),rax	; 80405043 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80405047 
	DB 0x48,0x8D,0x6D,0x8
	call	_2DUP	; 8040504B E8 E1 F4 FF FF 
	call	_SWAP	; 80405050 E8 ED F4 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80405055 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	(rsp),rax	; 80405059 
	DB 0x48,0x8B,0x4,0x24
;/*	lea	-0x08(rbp),rbp	; 8040505D 
	DB 0x48,0x8D,0x6D,0xF8
	call	_add	; 80405061 E8 B5 F3 FF FF 
	call	_Uless	; 80405066 E8 51 F3 FF FF 
;/  IF 2DUP U<
	test	rax,rax	; 8040506B 48 85 C0 
;/*	mov	0x00(rbp),rax	; 8040506E 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80405072 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_MOVE+0x7B 	; 80405076 
	DB 0xF,0x84,0x41,0x0,0x0,0x0
	call	_2DUP	; 8040507C E8 B0 F4 FF FF 
	call	_Uless	; 80405081 E8 36 F3 FF FF 
;/     IF R> CMOVE> ELSE R> CMOVE THEN
	test	rax,rax	; 80405086 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80405089 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8040508D 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_MOVE+0x68 	; 80405091 
	DB 0xF,0x84,0x13,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 80405097 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 8040509B 58 
;/*	lea	-0x08(rbp),rbp	; 8040509C 
	DB 0x48,0x8D,0x6D,0xF8
	call	_CMOVEgreat	; 804050A0 E8 B5 F0 7F 0 
;/*	jmp	_MOVE+0x76 	; 804050A5 
	DB 0xE9,0xE,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 804050AA 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 804050AE 58 
;/*	lea	-0x08(rbp),rbp	; 804050AF 
	DB 0x48,0x8D,0x6D,0xF8
	call	_CMOVE	; 804050B3 E8 15 F6 FF FF 
;/  ELSE R> CMOVE THEN ;
;/*	jmp	_MOVE+0x89 	; 804050B8 
	DB 0xE9,0xE,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 804050BD 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 804050C1 58 
;/*	lea	-0x08(rbp),rbp	; 804050C2 
	DB 0x48,0x8D,0x6D,0xF8
	call	_CMOVE	; 804050C6 E8 2 F6 FF FF 
	ret		; 804050CB C3 
;/
;/255 CONSTANT MAXCOUNTED   \ maximum length of contents of a counted string
;/
;/
;/: "CLIP"        ( a1 n1 -- a1 n1' )   \ clip a string to between 0 and MAXCOUNTED
;/                MAXCOUNTED MIN 0 MAX ;


_dticCLIPdtic:
;/*	mov	rax,-0x08(rbp)	; 804050CC 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xFF,eax	; 804050D0 
	DB 0xB8,0xFF,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804050D5 
	DB 0x48,0x8D,0x6D,0xF8
	call	_MIN	; 804050D9 E8 1B F2 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804050DE 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 804050E2 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804050E7 
	DB 0x48,0x8D,0x6D,0xF8
	call	_MAX	; 804050EB E8 25 F2 FF FF 
	ret		; 804050F0 C3 
;/
;/: PLACE         ( addr len dest -- )
;/                SWAP "CLIP" SWAP


_PLACE:
	call	_SWAP	; 804050F1 E8 4C F4 FF FF 
	call	_dticCLIPdtic	; 804050F6 E8 D1 FF FF FF 
	call	_SWAP	; 804050FB E8 42 F4 FF FF 
;/                2DUP 2>R
	call	_2DUP	; 80405100 E8 2C F4 FF FF 
	call	_2greatR	; 80405105 E8 83 F0 FF FF 
;/                CHAR+ SWAP MOVE
	call	_CHARadd	; 8040510A E8 6C F3 FF FF 
	call	_SWAP	; 8040510F E8 2E F4 FF FF 
	call	_MOVE	; 80405114 E8 29 FF FF FF 
;/                2R> C! ;
	call	_2Rgreat	; 80405119 E8 37 F0 FF FF 
	call	_Csave	; 8040511E E8 B2 F0 FF FF 
	ret		; 80405123 C3 
;/
;/: $!   PLACE ;


_dolsave:
	call	_PLACE	; 80405124 E8 C8 FF FF FF 
	ret		; 80405129 C3 
;/
;/: +PLACE        ( addr len dest -- ) \ append string addr,len to counted
;/                                     \ string dest
;/                >R "CLIP" MAXCOUNTED  R@ C@ -  MIN R>


_addPLACE:
	Push	rax	; 8040512A 50 
;/*	mov	0x00(rbp),rax	; 8040512B 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8040512F 
	DB 0x48,0x8D,0x6D,0x8
	call	_dticCLIPdtic	; 80405133 E8 94 FF FF FF 
;/*	mov	rax,-0x08(rbp)	; 80405138 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xFF,eax	; 8040513C 
	DB 0xB8,0xFF,0x0,0x0,0x0
;/*	mov	rax,-0x10(rbp)	; 80405141 
	DB 0x48,0x89,0x45,0xF0
;/*	mov	(rsp),rax	; 80405145 
	DB 0x48,0x8B,0x4,0x24
;/*	lea	-0x10(rbp),rbp	; 80405149 
	DB 0x48,0x8D,0x6D,0xF0
	call	_Cload	; 8040514D E8 7B F0 FF FF 
	call	_sub	; 80405152 E8 C1 F2 FF FF 
	call	_MIN	; 80405157 E8 9D F1 FF FF 
;/*	mov	rax,-0x08(rbp)	; 8040515C 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80405160 58 
;/*	lea	-0x08(rbp),rbp	; 80405161 
	DB 0x48,0x8D,0x6D,0xF8
;/                                        \ clip total to MAXCOUNTED string
;/                2DUP 2>R
	call	_2DUP	; 80405165 E8 C7 F3 FF FF 
	call	_2greatR	; 8040516A E8 1E F0 FF FF 
;/
;/                COUNT + SWAP MOVE
	call	_COUNT	; 8040516F E8 4D F1 FF FF 
	call	_add	; 80405174 E8 A2 F2 FF FF 
	call	_SWAP	; 80405179 E8 C4 F3 FF FF 
	call	_MOVE	; 8040517E E8 BF FE FF FF 
;/                2R> +! ;
	call	_2Rgreat	; 80405183 E8 CD EF FF FF 
	call	_addsave	; 80405188 E8 83 F0 FF FF 
	ret		; 8040518D C3 
;/
;/: $+!  +PLACE ;


_doladdsave:
	call	_addPLACE	; 8040518E E8 97 FF FF FF 
	ret		; 80405193 C3 
;/
;/: C+PLACE       ( c1 a1 -- )    \ append char c1 to the counted string at a1
;/                DUP 1+! COUNT + 1- C! ;


_CaddPLACE:
	call	_DUP	; 80405194 E8 8F F3 FF FF 
	call	_1addsave	; 80405199 E8 CF F0 FF FF 
	call	_COUNT	; 8040519E E8 1E F1 FF FF 
	call	_add	; 804051A3 E8 73 F2 FF FF 
	call	_1sub	; 804051A8 E8 DD F2 FF FF 
	call	_Csave	; 804051AD E8 23 F0 FF FF 
	ret		; 804051B2 C3 
;/
;/: $C+! C+PLACE  ;


_dolCaddsave:
	call	_CaddPLACE	; 804051B3 E8 DC FF FF FF 
	ret		; 804051B8 C3 
;/
;/: +NULL         ( a1 -- )       \ append a NULL just beyond the counted chars
;/                COUNT + 0 SWAP C! ;


_addNULL:
	call	_COUNT	; 804051B9 E8 3 F1 FF FF 
	call	_add	; 804051BE E8 58 F2 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804051C3 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 804051C7 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804051CC 
	DB 0x48,0x8D,0x6D,0xF8
	call	_SWAP	; 804051D0 E8 6D F3 FF FF 
	call	_Csave	; 804051D5 E8 FB EF FF FF 
	ret		; 804051DA C3 
;/
;/
;/: zplace        \ caddr len zaddr --
;/\ *G Copy the string caddr/len to zaddr as a 0 terminated string.
;/  2dup + >r				\ save location of zero


_zplace:
	call	_2DUP	; 804051DB E8 51 F3 FF FF 
	call	_add	; 804051E0 E8 36 F2 FF FF 
	Push	rax	; 804051E5 50 
;/*	mov	0x00(rbp),rax	; 804051E6 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804051EA 
	DB 0x48,0x8D,0x6D,0x8
;/  swap move				\ copy string
	call	_SWAP	; 804051EE E8 4F F3 FF FF 
	call	_MOVE	; 804051F3 E8 4A FE FF FF 
;/  0 r> c!				\ terminate afterwards in case of overlap
;/*	mov	rax,-0x08(rbp)	; 804051F8 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 804051FC 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	mov	rax,-0x10(rbp)	; 80405201 
	DB 0x48,0x89,0x45,0xF0
	pop	rax	; 80405205 58 
;/*	lea	-0x10(rbp),rbp	; 80405206 
	DB 0x48,0x8D,0x6D,0xF0
	call	_Csave	; 8040520A E8 C6 EF FF FF 
;/;
	ret		; 8040520F C3 
;/
;/: COMPARE ( addr1 u1 addr2 u2 --- diff )
;/\ Compare two strings. diff is negative if addr1 u1 is smaller, 0 if it
;/\ is equal and positive if it is greater than addr2 u2.
;/
;/  ROT 2DUP - >R        


_COMPARE:
	call	_ROT	; 80405210 E8 FC F3 FF FF 
	call	_2DUP	; 80405215 E8 17 F3 FF FF 
	call	_sub	; 8040521A E8 F9 F1 FF FF 
	Push	rax	; 8040521F 50 
;/*	mov	0x00(rbp),rax	; 80405220 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80405224 
	DB 0x48,0x8D,0x6D,0x8
;/  MIN DUP IF
	call	_MIN	; 80405228 E8 CC F0 FF FF 
	call	_DUP	; 8040522D E8 F6 F2 FF FF 
	test	rax,rax	; 80405232 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80405235 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80405239 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_COMPARE+0xD4 	; 8040523D 
	DB 0xF,0x84,0xA1,0x0,0x0,0x0
;/   >R
	Push	rax	; 80405243 50 
;/*	mov	0x00(rbp),rax	; 80405244 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80405248 
	DB 0x48,0x8D,0x6D,0x8
;/   BEGIN
;/    OVER C@ OVER C@ - IF
	call	_OVER	; 8040524C E8 48 F3 FF FF 
	call	_Cload	; 80405251 E8 77 EF FF FF 
	call	_OVER	; 80405256 E8 3E F3 FF FF 
	call	_Cload	; 8040525B E8 6D EF FF FF 
	call	_sub	; 80405260 E8 B3 F1 FF FF 
	test	rax,rax	; 80405265 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80405268 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8040526C 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_COMPARE+0x85 	; 80405270 
	DB 0xF,0x84,0x1F,0x0,0x0,0x0
;/     SWAP C@ SWAP C@ -
	call	_SWAP	; 80405276 E8 C7 F2 FF FF 
	call	_Cload	; 8040527B E8 4D EF FF FF 
	call	_SWAP	; 80405280 E8 BD F2 FF FF 
	call	_Cload	; 80405285 E8 43 EF FF FF 
	call	_sub	; 8040528A E8 89 F1 FF FF 
;/		 2RDROP	EXIT
	call	_2RDROP	; 8040528F E8 B6 EE FF FF 
	ret		; 80405294 C3 
;/    THEN 
;/    1+ SWAP 1+ SWAP
	call	_CHARadd	; 80405295 E8 E1 F1 FF FF 
	call	_SWAP	; 8040529A E8 A3 F2 FF FF 
	call	_CHARadd	; 8040529F E8 D7 F1 FF FF 
	call	_SWAP	; 804052A4 E8 99 F2 FF FF 
;/    R> 1- DUP >R 0=
;/*	mov	rax,-0x08(rbp)	; 804052A9 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 804052AD 58 
;/*	lea	-0x08(rbp),rbp	; 804052AE 
	DB 0x48,0x8D,0x6D,0xF8
	call	_1sub	; 804052B2 E8 D3 F1 FF FF 
	call	_DUP	; 804052B7 E8 6C F2 FF FF 
	Push	rax	; 804052BC 50 
;/*	mov	0x00(rbp),rax	; 804052BD 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804052C1 
	DB 0x48,0x8D,0x6D,0x8
	call	_0equ	; 804052C5 E8 78 F0 FF FF 
;/   UNTIL R>
	test	rax,rax	; 804052CA 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804052CD 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804052D1 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_COMPARE+0x3C 	; 804052D5 
	DB 0xF,0x84,0x71,0xFF,0xFF,0xFF
;/*	mov	rax,-0x08(rbp)	; 804052DB 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 804052DF 58 
;/*	lea	-0x08(rbp),rbp	; 804052E0 
	DB 0x48,0x8D,0x6D,0xF8
;/  THEN DROP
	call	_DgreatS	; 804052E4 E8 4A EE FF FF 
;/  2DROP R> NEGATE
	call	_2DROP	; 804052E9 E8 7E F2 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804052EE 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 804052F2 58 
;/*	lea	-0x08(rbp),rbp	; 804052F3 
	DB 0x48,0x8D,0x6D,0xF8
	call	_NEGATE	; 804052F7 E8 5 F1 FF FF 
;/;
	ret		; 804052FC C3 
;/
;/: SCAN ( c-addr1 u1 c --- c-addr2 u2 )
;/\ Find the first occurrence of character c in the string c-addr1 u1
;/\ c-addr2 u2 is the remaining part of the string starting with that char.
;/\ It is a zero-length string if c was not found.
;/  BEGIN
;/   OVER


_SCAN:
	call	_OVER	; 804052FD E8 97 F2 FF FF 
;/  WHILE
	test	rax,rax	; 80405302 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80405305 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80405309 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_SCAN+0x7B 	; 8040530D 
	DB 0xF,0x84,0x65,0x0,0x0,0x0
;/   ROT DUP C@ >R OVER R> =
	call	_ROT	; 80405313 E8 F9 F2 FF FF 
	call	_DUP	; 80405318 E8 B F2 FF FF 
	call	_Cload	; 8040531D E8 AB EE FF FF 
	Push	rax	; 80405322 50 
;/*	mov	0x00(rbp),rax	; 80405323 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80405327 
	DB 0x48,0x8D,0x6D,0x8
	call	_OVER	; 8040532B E8 69 F2 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80405330 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80405334 58 
;/*	lea	-0x08(rbp),rbp	; 80405335 
	DB 0x48,0x8D,0x6D,0xF8
	call	_equ	; 80405339 E8 FC EF FF FF 
;/   IF -ROT DROP
	test	rax,rax	; 8040533E 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80405341 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80405345 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_SCAN+0x5D 	; 80405349 
	DB 0xF,0x84,0xB,0x0,0x0,0x0
	call	_subROT	; 8040534F E8 CE F2 FF FF 
	call	_DgreatS	; 80405354 E8 DA ED FF FF 
;/   BREAK
	ret		; 80405359 C3 
;/   1+ -ROT SWAP 1- SWAP
	call	_CHARadd	; 8040535A E8 1C F1 FF FF 
	call	_subROT	; 8040535F E8 BE F2 FF FF 
	call	_SWAP	; 80405364 E8 D9 F1 FF FF 
	call	_1sub	; 80405369 E8 1C F1 FF FF 
	call	_SWAP	; 8040536E E8 CF F1 FF FF 
;/  REPEAT DROP
;/*	jmp	_SCAN	; 80405373 
	DB 0xE9,0x85,0xFF,0xFF,0xFF
	call	_DgreatS	; 80405378 E8 B6 ED FF FF 
;/;
	ret		; 8040537D C3 
;/
;/: SEARCH ( c-addr1 u1 c-addr2 u2 -- c-addr3 u3 flag ) \ 94 STRING
;/    2>R 2DUP


_SEARCH:
	call	_2greatR	; 8040537E E8 A EE FF FF 
	call	_2DUP	; 80405383 E8 A9 F1 FF FF 
;/    BEGIN
;/      DUP 1+ R@ >
	call	_DUP	; 80405388 E8 9B F1 FF FF 
	call	_CHARadd	; 8040538D E8 E9 F0 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80405392 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	(rsp),rax	; 80405396 
	DB 0x48,0x8B,0x4,0x24
;/*	lea	-0x08(rbp),rbp	; 8040539A 
	DB 0x48,0x8D,0x6D,0xF8
	call	_great	; 8040539E E8 D2 EF FF FF 
;/    WHILE
	test	rax,rax	; 804053A3 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804053A6 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804053AA 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_SEARCH+0x98 	; 804053AE 
	DB 0xF,0x84,0x62,0x0,0x0,0x0
;/      OVER 2R@ TUCK COMPARE 0=
	call	_OVER	; 804053B4 E8 E0 F1 FF FF 
	call	_2Rload	; 804053B9 E8 B8 ED FF FF 
	call	_TUCK	; 804053BE E8 FE F1 FF FF 
	call	_COMPARE	; 804053C3 E8 48 FE FF FF 
	call	_0equ	; 804053C8 E8 75 EF FF FF 
;/      IF 2RDROP 2SWAP 2DROP TRUE EXIT THEN
	test	rax,rax	; 804053CD 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804053D0 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804053D4 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_SEARCH+0x7F 	; 804053D8 
	DB 0xF,0x84,0x1F,0x0,0x0,0x0
	call	_2RDROP	; 804053DE E8 67 ED FF FF 
	call	_2SWAP	; 804053E3 E8 67 F1 FF FF 
	call	_2DROP	; 804053E8 E8 7F F1 FF FF 
;/*	mov	rax,-0x08(rbp)	; 804053ED 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0x1,rax	; 804053F1 
	DB 0x48,0xC7,0xC0,0xFF,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804053F8 
	DB 0x48,0x8D,0x6D,0xF8
	ret		; 804053FC C3 
;/      1- SWAP 1+ SWAP
	call	_1sub	; 804053FD E8 88 F0 FF FF 
	call	_SWAP	; 80405402 E8 3B F1 FF FF 
	call	_CHARadd	; 80405407 E8 6F F0 FF FF 
	call	_SWAP	; 8040540C E8 31 F1 FF FF 
;/    REPEAT 2RDROP 2DROP 0
;/*	jmp	_SEARCH+0xA 	; 80405411 
	DB 0xE9,0x72,0xFF,0xFF,0xFF
	call	_2RDROP	; 80405416 E8 2F ED FF FF 
	call	_2DROP	; 8040541B E8 4C F1 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80405420 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80405424 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80405429 
	DB 0x48,0x8D,0x6D,0xF8
;/;
	ret		; 8040542D C3 
;/
;/: REL@ ( ADDR -- ADDR' )
;/         DUP SL@ + ;


_RELload:
	call	_DUP	; 8040542E E8 F5 F0 FF FF 
	call	_SLload	; 80405433 E8 89 ED FF FF 
	call	_add	; 80405438 E8 DE EF FF FF 
	ret		; 8040543D C3 
;/
;/: <'>
;/R>  1+ DUP 4 + >R  REL@ 4 + ;


_lessticgreat:
;/*	mov	rax,-0x08(rbp)	; 8040543E 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80405442 58 
;/*	lea	-0x08(rbp),rbp	; 80405443 
	DB 0x48,0x8D,0x6D,0xF8
	call	_CHARadd	; 80405447 E8 2F F0 FF FF 
	call	_DUP	; 8040544C E8 D7 F0 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80405451 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x4,eax	; 80405455 
	DB 0xB8,0x4,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8040545A 
	DB 0x48,0x8D,0x6D,0xF8
	call	_add	; 8040545E E8 B8 EF FF FF 
	Push	rax	; 80405463 50 
;/*	mov	0x00(rbp),rax	; 80405464 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80405468 
	DB 0x48,0x8D,0x6D,0x8
	call	_RELload	; 8040546C E8 BD FF FF FF 
;/*	mov	rax,-0x08(rbp)	; 80405471 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x4,eax	; 80405475 
	DB 0xB8,0x4,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8040547A 
	DB 0x48,0x8D,0x6D,0xF8
	call	_add	; 8040547E E8 98 EF FF FF 
	ret		; 80405483 C3 
;/
;/T: >BODY 5 + ;


_greatBODY:
;/*	mov	rax,-0x08(rbp)	; 80405484 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x5,eax	; 80405488 
	DB 0xB8,0x5,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8040548D 
	DB 0x48,0x8D,0x6D,0xF8
	call	_add	; 80405491 E8 85 EF FF FF 
	ret		; 80405496 C3 
;/
;/$20 CONSTANT BL
;/8 CONSTANT CELL
;/0 CONSTANT FALSE
;/-1 CONSTANT TRUE
;/
;/
;/: CATCH ( i*x xt -- j*x 0 | i*x n ) \ 94 EXCEPTION
;/\ Положить на стек исключений кадр перехвата исключительных ситуаций
;/\ и выполнить токен xt (как по EXECUTE) таким образом, чтобы управление
;/\ могло быть передано в точку сразу после CATCH, если во время выполнения
;/\ xt выполняется THROW.
;/\ Если выполнение xt заканчивается нормально (т.е. кадр исключений,
;/\ положенный на стек словом CATCH не был взят выполнением THROW),
;/\ взять кадр исключений и вернуть ноль на вершину стека данных,
;/\ остальные элементы стека возвращаются xt EXECUTE. Иначе остаток
;/\ семантики выполнения дается THROW.
;/\  <SET-EXC-HANDLER>
;/
;/  SP@ >R  HANDLER @  >R


_CATCH:
	call	_SPload	; 80405497 E8 0 ED FF FF 
	Push	rax	; 8040549C 50 
;/*	mov	0x00(rbp),rax	; 8040549D 
	DB 0x48,0x8B,0x45,0x0
;/*	mov	rax,0x00(rbp)	; 804054A1 
	DB 0x48,0x89,0x45,0x0
;/*	lea	_UNLOOP+0x1A (%rip),rax	; 804054A5 
	DB 0x48,0x8D,0x5,0xB8,0xF2,0xFF,0xFF
	call	_load	; 804054AC E8 18 ED FF FF 
	Push	rax	; 804054B1 50 
;/*	mov	0x00(rbp),rax	; 804054B2 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804054B6 
	DB 0x48,0x8D,0x6D,0x8
;/  RP@ HANDLER !
	call	_RPload	; 804054BA E8 66 EC FF FF 
;/*	mov	rax,-0x08(rbp)	; 804054BF 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x1A (%rip),rax	; 804054C3 
	DB 0x48,0x8D,0x5,0x9A,0xF2,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804054CA 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 804054CE E8 2D ED FF FF 
;/  EXECUTE
	call	_EXECUTE	; 804054D3 E8 DC EC FF FF 
;/  R> HANDLER !
;/*	mov	rax,-0x08(rbp)	; 804054D8 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 804054DC 58 
;/*	mov	rax,-0x10(rbp)	; 804054DD 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_UNLOOP+0x1A (%rip),rax	; 804054E1 
	DB 0x48,0x8D,0x5,0x7C,0xF2,0xFF,0xFF
;/*	lea	-0x10(rbp),rbp	; 804054E8 
	DB 0x48,0x8D,0x6D,0xF0
	call	_save	; 804054EC E8 F ED FF FF 
;/  RDROP
;/*	lea	0x08(rsp),rsp	; 804054F1 
	DB 0x48,0x8D,0x64,0x24,0x8
;/  0
;/*	mov	rax,-0x08(rbp)	; 804054F6 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 804054FA 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804054FF 
	DB 0x48,0x8D,0x6D,0xF8
;/;
	ret		; 80405503 C3 
;/
;/' CATCH TO 'CATCH
;/
;/: THROW
;/\ Если любые биты n ненулевые, взять верхний кадр исключений со стека
;/\ исключений, включая все на стеке возвратов над этим кадром. Затем
;/\ восстановить спецификации входного потока, который использовался перед
;/\ соответствующим CATCH, и установить глубины всех стеков, определенных
;/\ в этом Стандарте, в то состояние, которое было сохранено в кадре
;/\ исключений (i - это то же число, что и i во входных аргументах
;/\ соответствующего CATCH), положить n на вершину стека данных и передать
;/\ управление в точку сразу после CATCH, которое положило этот кадр
;/\ исключений.
;/\ Если вершина стека не ноль, и на стеке исключений есть кадр 
;/\ исключений, то поведение следующее:
;/\   Если n=-1, выполнить функцию ABORT (версию ABORT из слов CORE), 
;/\   не выводя сообщений.
;/\   Если n=-2, выполнить функцию ABORT" (версию ABORT" из слов CORE), 
;/\   выводя символы ccc, ассоциированные с ABORT", генерирующим THROW.
;/\   Иначе система может вывести на дисплей зависящее от реализации 
;/\   сообщение об условии, соответствующем THROW с кодом n. Затем 
;/\   система выполнит функцию ABORT (версию ABORT из CORE).
;/  ?DUP


_THROW:
	call	_queDUP	; 80405504 E8 1A F0 FF FF 
;/  IF
	test	rax,rax	; 80405509 48 85 C0 
;/*	mov	0x00(rbp),rax	; 8040550C 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80405510 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_THROW+0x8D 	; 80405514 
	DB 0xF,0x84,0x77,0x0,0x0,0x0
;/   ( SAVEERR )  HANDLER @ \ A@ 
;/*	mov	rax,-0x08(rbp)	; 8040551A 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_UNLOOP+0x1A (%rip),rax	; 8040551E 
	DB 0x48,0x8D,0x5,0x3F,0xF2,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80405525 
	DB 0x48,0x8D,0x6D,0xF8
	call	_load	; 80405529 E8 9B EC FF FF 
;/     ?DUP
	call	_queDUP	; 8040552E E8 F0 EF FF FF 
;/     IF
	test	rax,rax	; 80405533 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80405536 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8040553A 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_THROW+0x8D 	; 8040553E 
	DB 0xF,0x84,0x4D,0x0,0x0,0x0
;/      RP!
	call	_RPsave	; 80405544 E8 F3 EB FF FF 
;/        R> HANDLER !
;/*	mov	rax,-0x08(rbp)	; 80405549 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 8040554D 58 
;/*	mov	rax,-0x10(rbp)	; 8040554E 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_UNLOOP+0x1A (%rip),rax	; 80405552 
	DB 0x48,0x8D,0x5,0xB,0xF2,0xFF,0xFF
;/*	lea	-0x10(rbp),rbp	; 80405559 
	DB 0x48,0x8D,0x6D,0xF0
	call	_save	; 8040555D E8 9E EC FF FF 
;/        R> SWAP >R
;/*	mov	rax,-0x08(rbp)	; 80405562 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80405566 58 
;/*	lea	-0x08(rbp),rbp	; 80405567 
	DB 0x48,0x8D,0x6D,0xF8
	call	_SWAP	; 8040556B E8 D2 EF FF FF 
	Push	rax	; 80405570 50 
;/*	mov	0x00(rbp),rax	; 80405571 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80405575 
	DB 0x48,0x8D,0x6D,0x8
;/        SP! DROP R>
	call	_SPsave	; 80405579 E8 2A EC FF FF 
	call	_DgreatS	; 8040557E E8 B0 EB FF FF 
;/*	mov	rax,-0x08(rbp)	; 80405583 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80405587 58 
;/*	lea	-0x08(rbp),rbp	; 80405588 
	DB 0x48,0x8D,0x6D,0xF8
;/     ELSE
;/*	jmp	_THROW+0x8D 	; 8040558C 
	DB 0xE9,0x0,0x0,0x0,0x0
;/\ FATAL-HANDLER
;/ THEN
;/  THEN
;/;
	ret		; 80405591 C3 
;/
;/' THROW TO 'THROW 
;/
;/T: ABORT -1 THROW ;


_ABORT:
;/*	mov	rax,-0x08(rbp)	; 80405592 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0x1,rax	; 80405596 
	DB 0x48,0xC7,0xC0,0xFF,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 8040559D 
	DB 0x48,0x8D,0x6D,0xF8
	call	_THROW	; 804055A1 E8 5E FF FF FF 
	ret		; 804055A6 C3 
;/
;/: ?THROW        \ k*x flag throw-code -- k*x|i*x n
;/\ *G Perform a *\fo{THROW} of value *\i{throw-code} if flag is non-zero.
;/  SWAP IF THROW THEN DROP


_queTHROW:
	call	_SWAP	; 804055A7 E8 96 EF FF FF 
	test	rax,rax	; 804055AC 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804055AF 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804055B3 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_queTHROW+0x1B 	; 804055B7 
	DB 0xF,0x84,0x5,0x0,0x0,0x0
	call	_THROW	; 804055BD E8 42 FF FF FF 
	call	_DgreatS	; 804055C2 E8 6C EB FF FF 
;/;
	ret		; 804055C7 C3 
;/
;/: SHORT? ( n -- -129 < n < 128 )
;/  0x80 + 0x100 U< ;


_SHORTque:
;/*	mov	rax,-0x08(rbp)	; 804055C8 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x80,eax	; 804055CC 
	DB 0xB8,0x80,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804055D1 
	DB 0x48,0x8D,0x6D,0xF8
	call	_add	; 804055D5 E8 41 EE FF FF 
;/*	mov	rax,-0x08(rbp)	; 804055DA 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x100,eax	; 804055DE 
	DB 0xB8,0x0,0x1,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804055E3 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Uless	; 804055E7 E8 D0 ED FF FF 
	ret		; 804055EC C3 
;/
;/: LONG? ( n -- -2147483648<n<2147483647 )
;/	$80000000 + $100000000 U< ;


_LONGque:
;/*	mov	rax,-0x08(rbp)	; 804055ED 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x80000000,eax	; 804055F1 
	DB 0xB8,0x0,0x0,0x0,0x80
;/*	lea	-0x08(rbp),rbp	; 804055F6 
	DB 0x48,0x8D,0x6D,0xF8
	call	_add	; 804055FA E8 1C EE FF FF 
;/*	mov	rax,-0x08(rbp)	; 804055FF 
	DB 0x48,0x89,0x45,0xF8
;/*	movabs	$0x100000000,%rax	; 80405603 
	DB 0x48,0xB8,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8040560D 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Uless	; 80405611 E8 A6 ED FF FF 
	ret		; 80405616 C3 
;/
;/: HH.
;/  DUP 0xF ANDC


_HHdot:
	call	_DUP	; 80405617 E8 C EF FF FF 
;/*	mov	rax,-0x08(rbp)	; 8040561C 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xF,eax	; 80405620 
	DB 0xB8,0xF,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80405625 
	DB 0x48,0x8D,0x6D,0xF8
	call	_ANDC	; 80405629 E8 B1 ED FF FF 
;/  IF DUP 0xF AND >R
	test	rax,rax	; 8040562E 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80405631 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80405635 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_HHdot+0x60 	; 80405639 
	DB 0xF,0x84,0x38,0x0,0x0,0x0
	call	_DUP	; 8040563F E8 E4 EE FF FF 
;/*	mov	rax,-0x08(rbp)	; 80405644 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xF,eax	; 80405648 
	DB 0xB8,0xF,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 8040564D 
	DB 0x48,0x8D,0x6D,0xF8
	call	_AND	; 80405651 E8 8C ED FF FF 
	Push	rax	; 80405656 50 
;/*	mov	0x00(rbp),rax	; 80405657 
	DB 0x48,0x8B,0x45,0x0
;/*	mov	rax,0x00(rbp)	; 8040565B 
	DB 0x48,0x89,0x45,0x0
;/	4 RSHIFT
;/*	mov	$0x4,eax	; 8040565F 
	DB 0xB8,0x4,0x0,0x0,0x0
	call	_greatgreat	; 80405664 E8 D8 EF FF FF 
;/	T_RECURSE R>
	call	_HHdot	; 80405669 E8 A9 FF FF FF 
;/*	mov	rax,-0x08(rbp)	; 8040566E 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 80405672 58 
;/*	lea	-0x08(rbp),rbp	; 80405673 
	DB 0x48,0x8D,0x6D,0xF8
;/  THEN
;/    DUP 10 < 0= IF 7 + THEN 48 + EMIT
	call	_DUP	; 80405677 E8 AC EE FF FF 
;/*	mov	rax,-0x08(rbp)	; 8040567C 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0xA,eax	; 80405680 
	DB 0xB8,0xA,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80405685 
	DB 0x48,0x8D,0x6D,0xF8
	call	_less	; 80405689 E8 F9 EC FF FF 
	call	_0equ	; 8040568E E8 AF EC FF FF 
	test	rax,rax	; 80405693 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80405696 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8040569A 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_HHdot+0x9F 	; 8040569E 
	DB 0xF,0x84,0x12,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 804056A4 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x7,eax	; 804056A8 
	DB 0xB8,0x7,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804056AD 
	DB 0x48,0x8D,0x6D,0xF8
	call	_add	; 804056B1 E8 65 ED FF FF 
;/*	mov	rax,-0x08(rbp)	; 804056B6 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x30,eax	; 804056BA 
	DB 0xB8,0x30,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804056BF 
	DB 0x48,0x8D,0x6D,0xF8
	call	_add	; 804056C3 E8 53 ED FF FF 
	call	_EMIT	; 804056C8 E8 1E F6 FF FF 
;/;
	ret		; 804056CD C3 
;/
;/
;/: BYE 0 HALT ;


_BYE:
;/*	mov	rax,-0x08(rbp)	; 804056CE 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 804056D2 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 804056D7 
	DB 0x48,0x8D,0x6D,0xF8
	call	_HALT	; 804056DB E8 86 EA 7F 0 
	ret		; 804056E0 C3 
;/
;/
;/: ASCII-Z     ( addr len buff -- buff-z )        \ make an ascii string
;/   DUP >R $! R> COUNT OVER + 0 SWAP C! ;


_ASCIIsubZ:
	call	_DUP	; 804056E1 E8 42 EE FF FF 
	Push	rax	; 804056E6 50 
;/*	mov	0x00(rbp),rax	; 804056E7 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804056EB 
	DB 0x48,0x8D,0x6D,0x8
	call	_dolsave	; 804056EF E8 30 FA FF FF 
;/*	mov	rax,-0x08(rbp)	; 804056F4 
	DB 0x48,0x89,0x45,0xF8
	pop	rax	; 804056F8 58 
;/*	lea	-0x08(rbp),rbp	; 804056F9 
	DB 0x48,0x8D,0x6D,0xF8
	call	_COUNT	; 804056FD E8 BF EB FF FF 
	call	_OVER	; 80405702 E8 92 EE FF FF 
	call	_add	; 80405707 E8 F ED FF FF 
;/*	mov	rax,-0x08(rbp)	; 8040570C 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x0,eax	; 80405710 
	DB 0xB8,0x0,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80405715 
	DB 0x48,0x8D,0x6D,0xF8
	call	_SWAP	; 80405719 E8 24 EE FF FF 
	call	_Csave	; 8040571E E8 B2 EA FF FF 
	ret		; 80405723 C3 
;/
;/: ZCOUNT        \ zaddr -- zaddr len
;/\ *G A version of *\fo{COUNT} for zero terminated strings, returning
;/\ ** the address of the first character and the length.
;/  dup


_ZCOUNT:
	call	_DUP	; 80405724 E8 FF ED FF FF 
;/  begin
;/    dup c@ ( 0<> )
	call	_DUP	; 80405729 E8 FA ED FF FF 
	call	_Cload	; 8040572E E8 9A EA FF FF 
;/   while
	test	rax,rax	; 80405733 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80405736 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 8040573A 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_ZCOUNT+0x2A 	; 8040573E 
	DB 0xF,0x84,0xA,0x0,0x0,0x0
;/     1+
	call	_CHARadd	; 80405744 E8 32 ED FF FF 
;/  repeat
;/*	jmp	_ZCOUNT+0x5 	; 80405749 
	DB 0xE9,0xDB,0xFF,0xFF,0xFF
;/  over -
	call	_OVER	; 8040574E E8 46 EE FF FF 
	call	_sub	; 80405753 E8 C0 EC FF FF 
;/;
	ret		; 80405758 C3 
;/
;/: ASCIIZ> ZCOUNT ;


_ASCIIZgreat:
	call	_ZCOUNT	; 80405759 E8 C6 FF FF FF 
	ret		; 8040575E C3 
;/
;/$400 VALUE /SysPad


_rslSysPad:
	call	_DOVALUE	; 8040575F E8 80 EF FF FF 

	DQ 0x400
;/
;/0 VALUE SysPadBuff

_SysPadBuff:
	call	_DOVALUE	; 8040576C E8 73 EF FF FF 

	DQ 0x0
;/0 VALUE SysPAD

_SysPAD:
	call	_DOVALUE	; 80405779 E8 66 EF FF FF 

	DQ 0x0
;/0 VALUE SysPadEdge

_SysPadEdge:
	call	_DOVALUE	; 80405786 E8 59 EF FF FF 

	DQ 0x0
;/
;/: NEWSYSPADGET	\ u -- addr
;/  dup /SysPad u>

_NEWSYSPADGET:
	call	_DUP	; 80405793 E8 90 ED FF FF 
;/*	mov	rax,-0x08(rbp)	; 80405798 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_rslSysPad+0x5 (%rip),rax	; 8040579C 
	DB 0x48,0x8D,0x5,0xC1,0xFF,0xFF,0xFF
;/*	mov	(rax),rax	; 804057A3 
	DB 0x48,0x8B,0x0
;/*	lea	-0x08(rbp),rbp	; 804057A6 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Ugreat	; 804057AA E8 1 EC FF FF 
;/  IF  -419 throw  THEN
	test	rax,rax	; 804057AF 48 85 C0 
;/*	mov	0x00(rbp),rax	; 804057B2 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 804057B6 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_NEWSYSPADGET+0x41 	; 804057BA 
	DB 0xF,0x84,0x14,0x0,0x0,0x0
;/*	mov	rax,-0x08(rbp)	; 804057C0 
	DB 0x48,0x89,0x45,0xF8
;/*	movq	$-0x1A3,rax	; 804057C4 
	DB 0x48,0xC7,0xC0,0x5D,0xFE,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 804057CB 
	DB 0x48,0x8D,0x6D,0xF8
	call	_THROW	; 804057CF E8 30 FD FF FF 
;/
;/  SysPad  SysPadEdge UMIN OVER - 
;/*	mov	rax,-0x08(rbp)	; 804057D4 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_SysPAD+0x5 (%rip),rax	; 804057D8 
	DB 0x48,0x8D,0x5,0x9F,0xFF,0xFF,0xFF
;/*	mov	(rax),rax	; 804057DF 
	DB 0x48,0x8B,0x0
;/*	mov	rax,-0x10(rbp)	; 804057E2 
	DB 0x48,0x89,0x45,0xF0
;/*	lea	_SysPadEdge+0x5 (%rip),rax	; 804057E6 
	DB 0x48,0x8D,0x5,0x9E,0xFF,0xFF,0xFF
;/*	mov	(rax),rax	; 804057ED 
	DB 0x48,0x8B,0x0
;/*	lea	-0x10(rbp),rbp	; 804057F0 
	DB 0x48,0x8D,0x6D,0xF0
	call	_UMIN	; 804057F4 E8 E EB FF FF 
	call	_OVER	; 804057F9 E8 9B ED FF FF 
	call	_sub	; 804057FE E8 15 EC FF FF 
;/  DUP SysPADBuff U<
	call	_DUP	; 80405803 E8 20 ED FF FF 
;/*	mov	rax,-0x08(rbp)	; 80405808 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_SysPadBuff+0x5 (%rip),rax	; 8040580C 
	DB 0x48,0x8D,0x5,0x5E,0xFF,0xFF,0xFF
;/*	mov	(rax),rax	; 80405813 
	DB 0x48,0x8B,0x0
;/*	lea	-0x08(rbp),rbp	; 80405816 
	DB 0x48,0x8D,0x6D,0xF8
	call	_Uless	; 8040581A E8 9D EB FF FF 
;/  IF DROP SysPadEdge OVER - THEN
	test	rax,rax	; 8040581F 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80405822 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80405826 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_NEWSYSPADGET+0xBE 	; 8040582A 
	DB 0xF,0x84,0x21,0x0,0x0,0x0
	call	_DgreatS	; 80405830 E8 FE E8 FF FF 
;/*	mov	rax,-0x08(rbp)	; 80405835 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_SysPadEdge+0x5 (%rip),rax	; 80405839 
	DB 0x48,0x8D,0x5,0x4B,0xFF,0xFF,0xFF
;/*	mov	(rax),rax	; 80405840 
	DB 0x48,0x8B,0x0
;/*	lea	-0x08(rbp),rbp	; 80405843 
	DB 0x48,0x8D,0x6D,0xF8
	call	_OVER	; 80405847 E8 4D ED FF FF 
	call	_sub	; 8040584C E8 C7 EB FF FF 
;/  NIP DUP TO SysPad
	call	_NIP	; 80405851 E8 B6 ED FF FF 
	call	_DUP	; 80405856 E8 CD EC FF FF 
;/*	mov	rax,-0x08(rbp)	; 8040585B 
	DB 0x48,0x89,0x45,0xF8
;/*	lea	_SysPAD+0x5 (%rip),rax	; 8040585F 
	DB 0x48,0x8D,0x5,0x18,0xFF,0xFF,0xFF
;/*	lea	-0x08(rbp),rbp	; 80405866 
	DB 0x48,0x8D,0x6D,0xF8
	call	_save	; 8040586A E8 91 E9 FF FF 
;/
;/;
	ret		; 8040586F C3 
;/
