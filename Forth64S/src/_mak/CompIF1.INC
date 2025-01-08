;/
;/' 2DROP ->DEFER V_UPPER

_V_UPPER:
	call	_DOVECT	; 80414BA0 E8 57 FB FE FF 
	DQ _2DROP

;/
;/: [ELSE]
;/    1

_xcELSEyc:
;/*	mov	rax,-0x08(rbp)	; 80414BAD 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x1,eax	; 80414BB1 
	DB 0xB8,0x1,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80414BB6 
	DB 0x48,0x8D,0x6D,0xF8
;/    BEGIN
;/      PARSE-NAME 2DUP V_UPPER DUP
	call	_PARSEsubNAME	; 80414BBA E8 A7 D2 FF FF 
	call	_2DUP	; 80414BBF E8 6D F9 FE FF 
	call	_V_UPPER	; 80414BC4 E8 D7 FF FF FF 
	call	_DUP	; 80414BC9 E8 5A F9 FE FF 
;/      IF  
	test	rax,rax	; 80414BCE 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80414BD1 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414BD5 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_xcELSEyc+0x103 	; 80414BD9 
	DB 0xF,0x84,0xD1,0x0,0x0,0x0
;/         2DUP 3 UMIN  S" [IF"  \ все слова с префиксом "[IF"
	call	_2DUP	; 80414BDF E8 4D F9 FE FF 
;/*	mov	rax,-0x08(rbp)	; 80414BE4 
	DB 0x48,0x89,0x45,0xF8
;/*	mov	$0x3,eax	; 80414BE8 
	DB 0xB8,0x3,0x0,0x0,0x0
;/*	lea	-0x08(rbp),rbp	; 80414BED 
	DB 0x48,0x8D,0x6D,0xF8
	call	_UMIN	; 80414BF1 E8 11 F7 FE FF 
	call	_cbigSdticcend	; 80414BF6 E8 D8 2 FF FF 
	DB 0x3,0x5B,0x49,0x46
;/                        COMPARE 0= IF 2DROP 1+                 ELSE 
	call	_COMPARE	; 80414BFF E8 C 6 FF FF 
	call	_0equ	; 80414C04 E8 39 F7 FE FF 
	test	rax,rax	; 80414C09 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80414C0C 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414C10 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_xcELSEyc+0x7C 	; 80414C14 
	DB 0xF,0x84,0xF,0x0,0x0,0x0
	call	_2DROP	; 80414C1A E8 4D F9 FE FF 
	call	_CHARadd	; 80414C1F E8 57 F8 FE FF 
;/*	jmp	_xcELSEyc+0xFE 	; 80414C24 
	DB 0xE9,0x82,0x0,0x0,0x0
;/         2DUP S" [ELSE]" COMPARE 0= IF 2DROP 1- DUP  IF 1+ THEN ELSE 
	call	_2DUP	; 80414C29 E8 3 F9 FE FF 
	call	_cbigSdticcend	; 80414C2E E8 A0 2 FF FF 
	DB 0x6,0x5B,0x45,0x4C,0x53,0x45,0x5D
	call	_COMPARE	; 80414C3A E8 D1 5 FF FF 
	call	_0equ	; 80414C3F E8 FE F6 FE FF 
	test	rax,rax	; 80414C44 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80414C47 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414C4B 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_xcELSEyc+0xD2 	; 80414C4F 
	DB 0xF,0x84,0x2A,0x0,0x0,0x0
	call	_2DROP	; 80414C55 E8 12 F9 FE FF 
	call	_1sub	; 80414C5A E8 2B F8 FE FF 
	call	_DUP	; 80414C5F E8 C4 F8 FE FF 
	test	rax,rax	; 80414C64 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80414C67 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414C6B 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_xcELSEyc+0xCD 	; 80414C6F 
	DB 0xF,0x84,0x5,0x0,0x0,0x0
	call	_CHARadd	; 80414C75 E8 1 F8 FE FF 
;/*	jmp	_xcELSEyc+0xFE 	; 80414C7A 
	DB 0xE9,0x2C,0x0,0x0,0x0
;/              S" [THEN]" COMPARE 0= IF       1-                 THEN
	call	_cbigSdticcend	; 80414C7F E8 4F 2 FF FF 
	DB 0x6,0x5B,0x54,0x48,0x45,0x4E,0x5D
	call	_COMPARE	; 80414C8B E8 80 5 FF FF 
	call	_0equ	; 80414C90 E8 AD F6 FE FF 
	test	rax,rax	; 80414C95 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80414C98 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414C9C 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_xcELSEyc+0xFE 	; 80414CA0 
	DB 0xF,0x84,0x5,0x0,0x0,0x0
	call	_1sub	; 80414CA6 E8 DF F7 FE FF 
;/                                    THEN  THEN   
;/      ELSE 2DROP REFILL  AND \   SOURCE TYPE
;/*	jmp	_xcELSEyc+0x112 	; 80414CAB 
	DB 0xE9,0xF,0x0,0x0,0x0
	call	_2DROP	; 80414CB0 E8 B7 F8 FE FF 
	call	_REFILL	; 80414CB5 E8 A4 DE FF FF 
	call	_AND	; 80414CBA E8 23 F7 FE FF 
;/      THEN DUP 0=
	call	_DUP	; 80414CBF E8 64 F8 FE FF 
	call	_0equ	; 80414CC4 E8 79 F6 FE FF 
;/    UNTIL  DROP ;  IMMEDIATE
	test	rax,rax	; 80414CC9 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80414CCC 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414CD0 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_xcELSEyc+0xD 	; 80414CD4 
	DB 0xF,0x84,0xE0,0xFE,0xFF,0xFF
	call	_DgreatS	; 80414CDA E8 54 F4 FE FF 
	ret		; 80414CDF C3 
;/
;/: [IF] 0= IF [COMPILE] [ELSE] THEN ;  IMMEDIATE


_xcIFyc:
	call	_0equ	; 80414CE0 E8 5D F6 FE FF 
	test	rax,rax	; 80414CE5 48 85 C0 
;/*	mov	0x00(rbp),rax	; 80414CE8 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80414CEC 
	DB 0x48,0x8D,0x6D,0x8
;/*	jz	_xcIFyc+0x1B 	; 80414CF0 
	DB 0xF,0x84,0x5,0x0,0x0,0x0
	call	_xcELSEyc	; 80414CF6 E8 B2 FE FF FF 
	ret		; 80414CFB C3 
;/
;/: [THEN] ;  IMMEDIATE


_xcTHENyc:
	ret		; 80414CFC C3 
;/
