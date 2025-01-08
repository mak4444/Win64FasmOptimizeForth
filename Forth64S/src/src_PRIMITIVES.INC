;/ TEXEC_SET
;/
;/CODE TEST333
;/
;/\  add   (%rax,%rax,2),%edx
;/
;/	POP %r8

_TEST333:
	pop	r8	; 804040E8 41 58 
;/	POP %rAX
	pop	rax	; 804040EA 58 
;/
;/\	$f2 c, $f c, $10 c, 07 c,
;/
;/END-CODE
;/
;/CODE test3330
;/
;/	push   HERE (%rip) \  ff 35 77 00 00 00    # 0x83


_test3330:
;/*	push	_test3330(%rip)	; 804040EB 
	DB 0xFF,0x35,0xFA,0xFF,0xFF,0xFF
;/
;/	push   ' TEST333 (%rip) \  ff 35 77 00 00 00    # 0x83
;/*	push	_TEST333(%rip)	; 804040F1 
	DB 0xFF,0x35,0xF1,0xFF,0xFF,0xFF
;/
;/	pop    ' TEST333 (%rip) \  8f 05 77 00 00 00    # 0x7d
;/*	pop	_TEST333(%rip)	; 804040F7 
	DB 0x8F,0x5,0xEB,0xFF,0xFF,0xFF
;/	push   ' TEST333 (%rip) \  ff 35 77 00 00 00    # 0x83
;/*	push	_TEST333(%rip)	; 804040FD 
	DB 0xFF,0x35,0xE5,0xFF,0xFF,0xFF
;/	call   ' TEST333 (%rip) \  ff 15 77 00 00 00    # 0x89
;/*	call	*_TEST333(%rip)	; 80404103 
	DB 0xFF,0x15,0xDF,0xFF,0xFF,0xFF
;/	jmp    ' TEST333 (%rip) \  ff 25 77 00 00 00    # 0x8f
;/*	jmp	*_TEST333(%rip)	; 80404109 
	DB 0xFF,0x25,0xD9,0xFF,0xFF,0xFF
;/
;/	DUP,
;/*	lea	-0x08(rbp),rbp	; 8040410F 
	DB 0x48,0x8D,0x6D,0xF8
;/*	mov	rax,0x00(rbp)	; 80404113 
	DB 0x48,0x89,0x45,0x0
;/	mov    $-1,%Rax
;/*	movq	$-0x1,rax	; 80404117 
	DB 0x48,0xC7,0xC0,0xFF,0xFF,0xFF,0xFF
;/\	movabs  ' test333 ,%al
;/	NEXT
	ret		; 8040411E C3 
;/END-CODE
;/
;/CREATE test3331
;/ $0f C, 00  C, $c0 C,

	DB 0xF
	DB 0x0,0xC0
;/ $0f C, 01  C, $c0 C,
	DB 0xF,0x1,0xC0
;/
;/\ Push the address of the top element of the return stack 
;/\ onto the parameter stack.
;/CODE RP@	(  -- addr )
;/	lea    -0x8(%rbp),%rbp

_RPload:
;/*	lea	-0x08(rbp),rbp	; 80404125 
	DB 0x48,0x8D,0x6D,0xF8
;/	mov    %rax,0x0(%rbp)
;/*	mov	rax,0x00(rbp)	; 80404129 
	DB 0x48,0x89,0x45,0x0
;/	lea    0x8(%rsp),%rax
;/*	lea	0x08(rsp),rax	; 8040412D 
	DB 0x48,0x8D,0x44,0x24,0x8
;/	NEXT
	ret		; 80404132 C3 
;/END-CODE
;/
;/CODE	DROP	\ remove element of parameter stack .
;/CODL	D>S
;/	DROP,


_DgreatS:
;/*	mov	0x00(rbp),rax	; 80404133 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80404137 
	DB 0x48,0x8D,0x6D,0x8
;/CODL	NOOP
;/	NEXT
_NOOP:
	ret		; 8040413B C3 
;/END-CODE
;/
;/' NOOP TO 'CRASH
;/' NOOP TO 'NOOP
;/' DROP TO 'DROP
;/
;/\ Set the return stack pointer to n .
;/CODE RP!	( N -- )
;/	pop    %rbx


_RPsave:
	pop	rbx	; 8040413C 5B 
;/	mov    %rax,%rsp
;/*	mov	rax,rsp	; 8040413D 
	DB 0x48,0x89,0xC4
;/	mov    0x0(%rbp),%rax
;/*	mov	0x00(rbp),rax	; 80404140 
	DB 0x48,0x8B,0x45,0x0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 80404144 
	DB 0x48,0x8D,0x6D,0x8
;/	jmp	%rbx
;/*	jmp	*rbx	; 80404148 
	DB 0xFF,0xE3
;/END-CODE
;/
;/CODE 2RDROP
;/	mov	(%rsp),%rbx


_2RDROP:
;/*	mov	(rsp),rbx	; 8040414A 
	DB 0x48,0x8B,0x1C,0x24
;/	lea	0x18(%rsp),%rsp
;/*	lea	0x18(rsp),rsp	; 8040414E 
	DB 0x48,0x8D,0x64,0x24,0x18
;/	jmp	%rbx
;/*	jmp	*rbx	; 80404153 
	DB 0xFF,0xE3
;/END-CODE
;/
;/\ Pop two items from return stack onto parameter stack
;/CODE 2R>	( -- D.lo D.hi )
;/	mov    (%rsp),%rbx


_2Rgreat:
;/*	mov	(rsp),rbx	; 80404155 
	DB 0x48,0x8B,0x1C,0x24
;/	mov    %rax,-0x8(%rbp)
;/*	mov	rax,-0x08(rbp)	; 80404159 
	DB 0x48,0x89,0x45,0xF8
;/	mov    0x10(%rsp),%rcx
;/*	mov	0x10(rsp),rcx	; 8040415D 
	DB 0x48,0x8B,0x4C,0x24,0x10
;/	mov    0x8(%rsp),%rax
;/*	mov	0x08(rsp),rax	; 80404162 
	DB 0x48,0x8B,0x44,0x24,0x8
;/	mov    %rcx,-0x10(%rbp)
;/*	mov	rcx,-0x10(rbp)	; 80404167 
	DB 0x48,0x89,0x4D,0xF0
;/	lea    -0x10(%rbp),%rbp
;/*	lea	-0x10(rbp),rbp	; 8040416B 
	DB 0x48,0x8D,0x6D,0xF0
;/	lea    0x18(%rsp),%rsp
;/*	lea	0x18(rsp),rsp	; 8040416F 
	DB 0x48,0x8D,0x64,0x24,0x18
;/	jmp	%rbx
;/*	jmp	*rbx	; 80404174 
	DB 0xFF,0xE3
;/END-CODE
;/
;/
;/\ Push a copy of the top two items of the return stack onto the parameter stack.
;/CODE 2R@	( -- D.lo D.hi )
;/	mov    %rax,-0x8(%rbp)


_2Rload:
;/*	mov	rax,-0x08(rbp)	; 80404176 
	DB 0x48,0x89,0x45,0xF8
;/	mov    0x8(%rsp),%rax
;/*	mov	0x08(rsp),rax	; 8040417A 
	DB 0x48,0x8B,0x44,0x24,0x8
;/	mov    0x10(%rsp),%rbx
;/*	mov	0x10(rsp),rbx	; 8040417F 
	DB 0x48,0x8B,0x5C,0x24,0x10
;/	mov    %rbx,-0x10(%rbp)
;/*	mov	rbx,-0x10(rbp)	; 80404184 
	DB 0x48,0x89,0x5D,0xF0
;/	lea    -0x10(%rbp),%rbp
;/*	lea	-0x10(rbp),rbp	; 80404188 
	DB 0x48,0x8D,0x6D,0xF0
;/	NEXT
	ret		; 8040418C C3 
;/END-CODE
;/
;/
;/\ Pop two items from parameter stack, push onto return stack.
;/CODE 2>R	( D -- )
;/	pop    %rbx


_2greatR:
	pop	rbx	; 8040418D 5B 
;/	push   0(%rbp)
;/*	push	0x00(rbp)	; 8040418E 
	DB 0xFF,0x75,0x0
;/	push   %rax
	Push	rax	; 80404191 50 
;/	lea    0x10(%rbp),%rbp
;/*	lea	0x10(rbp),rbp	; 80404192 
	DB 0x48,0x8D,0x6D,0x10
;/	mov    -0x8(%rbp),%rax
;/*	mov	-0x08(rbp),rax	; 80404196 
	DB 0x48,0x8B,0x45,0xF8
;/	jmp	%rbx
;/*	jmp	*rbx	; 8040419A 
	DB 0xFF,0xE3
;/END-CODE
;/
;/CODE SP@	( -- N )
;/	lea    -0x8(%rbp),%rbp


_SPload:
;/*	lea	-0x08(rbp),rbp	; 8040419C 
	DB 0x48,0x8D,0x6D,0xF8
;/	mov    %rax,0x0(%rbp)
;/*	mov	rax,0x00(rbp)	; 804041A0 
	DB 0x48,0x89,0x45,0x0
;/	mov    %rbp,%rax
;/*	mov	rbp,rax	; 804041A4 
	DB 0x48,0x89,0xE8
;/	NEXT
	ret		; 804041A7 C3 
;/END-CODE
;/
;/\ Set the parameter stack pointer to specified value.
;/CODE SP!	( n -- )
;/	lea    0x8(%rax),%rbp


_SPsave:
;/*	lea	0x08(rax),rbp	; 804041A8 
	DB 0x48,0x8D,0x68,0x8
;/	mov    -0x8(%rbp),%rax
;/*	mov	-0x08(rbp),rax	; 804041AC 
	DB 0x48,0x8B,0x45,0xF8
;/	NEXT
	ret		; 804041B0 C3 
;/END-CODE
;/
;/CODE PERFORM	( ... [tx] -- ...' )
;/CODL @EXECUTE
;/	mov    (%rax),%rax


_loadEXECUTE:
;/*	mov	(rax),rax	; 804041B1 
	DB 0x48,0x8B,0x0
;/\ Execute the word whose CFA is on the stack
;/CODL EXECUTE	( ... tx -- ...' )
;/	mov    %rax,%rdx
_EXECUTE:
;/*	mov	rax,rdx	; 804041B4 
	DB 0x48,0x89,0xC2
;/	mov    0x0(%rbp),%rax
;/*	mov	0x00(rbp),rax	; 804041B7 
	DB 0x48,0x8B,0x45,0x0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 804041BB 
	DB 0x48,0x8D,0x6D,0x8
;/	jmp    %rdx
;/*	jmp	*rdx	; 804041BF 
	DB 0xFF,0xE2
;/END-CODE
;/
;/' PERFORM TO 'PERFORM
;/' EXECUTE TO 'EXECUTE
;/
;/CODE SL@
;/	mov    (%rax),%eax


_SLload:
;/*	mov	(rax),eax	; 804041C1 
	DB 0x8B,0x0
;/	cltq
	dw 9848h		; 804041C3 48 98 
;/	NEXT
	ret		; 804041C5 C3 
;/END-CODE
;/
;/CODE L@
;/	mov    (%rax),%eax


_Lload:
;/*	mov	(rax),eax	; 804041C6 
	DB 0x8B,0x0
;/	NEXT
	ret		; 804041C8 C3 
;/END-CODE
;/
;/\ ARM Forth word @   ( addr -- n )
;/\ Fetch a value from addr
;/CODE @		( A -- N )
;/	mov    (%rax),%rax


_load:
;/*	mov	(rax),rax	; 804041C9 
	DB 0x48,0x8B,0x0
;/	NEXT
	ret		; 804041CC C3 
;/END-CODE
;/
;/' @ TO 'GET
;/
;/CODE C@		( A -- c )
;/	movzbl (%rax),%eax


_Cload:
;/*	movzb	(rax),eax	; 804041CD 
	DB 0xF,0xB6,0x0
;/	NEXT
	ret		; 804041D0 C3 
;/END-CODE
;/
;/CODE W@		( A -- c )
;/	movzwl (%rax),%eax


_Wload:
;/*	movzw	(rax),eax	; 804041D1 
	DB 0xF,0xB7,0x0
;/	NEXT
	ret		; 804041D4 C3 
;/END-CODE
;/
;/\ Store the least significant 8 bits of char at the specified addr
;/CODE C!		( N,A -- )
;/	mov    0x0(%rbp),%dl


_Csave:
;/*	mov	0x00(rbp),dl	; 804041D5 
	DB 0x8A,0x55,0x0
;/	mov    %dl,(%rax)
;/*	mov	dl,(rax)	; 804041D8 
	DB 0x88,0x10
;/	mov    0x8(%rbp),%rax
;/*	mov	0x08(rbp),rax	; 804041DA 
	DB 0x48,0x8B,0x45,0x8
;/	lea    0x10(%rbp),%rbp
;/*	lea	0x10(rbp),rbp	; 804041DE 
	DB 0x48,0x8D,0x6D,0x10
;/	NEXT
	ret		; 804041E2 C3 
;/END-CODE
;/
;/CODE W!	( N,A -- )
;/	mov    0x0(%rbp),%edx


_Wsave:
;/*	mov	0x00(rbp),edx	; 804041E3 
	DB 0x8B,0x55,0x0
;/	mov    %dx,(%rax)
;/*	mov	dx,(rax)	; 804041E6 
	DB 0x66,0x89,0x10
;/	mov    0x8(%rbp),%rax
;/*	mov	0x08(rbp),rax	; 804041E9 
	DB 0x48,0x8B,0x45,0x8
;/	lea    0x10(%rbp),%rbp
;/*	lea	0x10(rbp),rbp	; 804041ED 
	DB 0x48,0x8D,0x6D,0x10
;/	NEXT
	ret		; 804041F1 C3 
;/END-CODE
;/
;/CODE L!	( N,A -- )
;/	mov    0x0(%rbp),%edx


_Lsave:
;/*	mov	0x00(rbp),edx	; 804041F2 
	DB 0x8B,0x55,0x0
;/	mov    %edx,(%rax)
;/*	mov	edx,(rax)	; 804041F5 
	DB 0x89,0x10
;/	mov    0x8(%rbp),%rax
;/*	mov	0x08(rbp),rax	; 804041F7 
	DB 0x48,0x8B,0x45,0x8
;/	lea    0x10(%rbp),%rbp
;/*	lea	0x10(rbp),rbp	; 804041FB 
	DB 0x48,0x8D,0x6D,0x10
;/	NEXT
	ret		; 804041FF C3 
;/END-CODE
;/
;/\  Store value n into the address addr
;/CODE !	( N,A -- )
;/	mov    0x0(%rbp),%rdx


_save:
;/*	mov	0x00(rbp),rdx	; 80404200 
	DB 0x48,0x8B,0x55,0x0
;/	mov    %rdx,(%rax)
;/*	mov	rdx,(rax)	; 80404204 
	DB 0x48,0x89,0x10
;/	mov    0x8(%rbp),%rax
;/*	mov	0x08(rbp),rax	; 80404207 
	DB 0x48,0x8B,0x45,0x8
;/	lea    0x10(%rbp),%rbp
;/*	lea	0x10(rbp),rbp	; 8040420B 
	DB 0x48,0x8D,0x6D,0x10
;/	NEXT
	ret		; 8040420F C3 
;/END-CODE
;/
;/CODE +!		( N,A -- )
;/	mov    0x0(%rbp),%rdx


_addsave:
;/*	mov	0x00(rbp),rdx	; 80404210 
	DB 0x48,0x8B,0x55,0x0
;/	add	%rdx, (%rax)
;/*	add	rdx,(rax)	; 80404214 
	DB 0x48,0x1,0x10
;/	mov    0x8(%rbp),%rax
;/*	mov	0x08(rbp),rax	; 80404217 
	DB 0x48,0x8B,0x45,0x8
;/	lea    0x10(%rbp),%rbp
;/*	lea	0x10(rbp),rbp	; 8040421B 
	DB 0x48,0x8D,0x6D,0x10
;/	NEXT
	ret		; 8040421F C3 
;/END-CODE
;/
;/CODE C+!		( N,A -- )
;/	mov    0x0(%rbp),%rdx


_Caddsave:
;/*	mov	0x00(rbp),rdx	; 80404220 
	DB 0x48,0x8B,0x55,0x0
;/	add	%dl, (%rax)
;/*	add	dl,(rax)	; 80404224 
	DB 0x0,0x10
;/	mov    0x8(%rbp),%rax
;/*	mov	0x08(rbp),rax	; 80404226 
	DB 0x48,0x8B,0x45,0x8
;/	lea    0x10(%rbp),%rbp
;/*	lea	0x10(rbp),rbp	; 8040422A 
	DB 0x48,0x8D,0x6D,0x10
;/	NEXT
	ret		; 8040422E C3 
;/END-CODE
;/
;/CODE L+!		( N,A -- )
;/	mov    0x0(%rbp),%rdx


_Laddsave:
;/*	mov	0x00(rbp),rdx	; 8040422F 
	DB 0x48,0x8B,0x55,0x0
;/	add	%edx, (%rax)
;/*	add	edx,(rax)	; 80404233 
	DB 0x1,0x10
;/	mov    0x8(%rbp),%rax
;/*	mov	0x08(rbp),rax	; 80404235 
	DB 0x48,0x8B,0x45,0x8
;/	lea    0x10(%rbp),%rbp
;/*	lea	0x10(rbp),rbp	; 80404239 
	DB 0x48,0x8D,0x6D,0x10
;/	NEXT
	ret		; 8040423D C3 
;/END-CODE
;/
;/CODE LOR!		( N,A -- )
;/	mov    0x0(%rbp),%rdx


_LORsave:
;/*	mov	0x00(rbp),rdx	; 8040423E 
	DB 0x48,0x8B,0x55,0x0
;/	or	%edx, (%rax)
;/*	or	edx,(rax)	; 80404242 
	DB 0x9,0x10
;/	mov    0x8(%rbp),%rax
;/*	mov	0x08(rbp),rax	; 80404244 
	DB 0x48,0x8B,0x45,0x8
;/	lea    0x10(%rbp),%rbp
;/*	lea	0x10(rbp),rbp	; 80404248 
	DB 0x48,0x8D,0x6D,0x10
;/	NEXT
	ret		; 8040424C C3 
;/END-CODE
;/
;/CODE OR!		( N,A -- )
;/	mov    0x0(%rbp),%rdx


_ORsave:
;/*	mov	0x00(rbp),rdx	; 8040424D 
	DB 0x48,0x8B,0x55,0x0
;/	or	%Rdx, (%rax)
;/*	or	rdx,(rax)	; 80404251 
	DB 0x48,0x9,0x10
;/	mov    0x8(%rbp),%rax
;/*	mov	0x08(rbp),rax	; 80404254 
	DB 0x48,0x8B,0x45,0x8
;/	lea    0x10(%rbp),%rbp
;/*	lea	0x10(rbp),rbp	; 80404258 
	DB 0x48,0x8D,0x6D,0x10
;/	NEXT
	ret		; 8040425C C3 
;/END-CODE
;/
;/CODE XOR!		( N,A -- )
;/	mov    0x0(%rbp),%rdx


_XORsave:
;/*	mov	0x00(rbp),rdx	; 8040425D 
	DB 0x48,0x8B,0x55,0x0
;/	xor	%Rdx, (%rax)
;/*	xor	rdx,(rax)	; 80404261 
	DB 0x48,0x31,0x10
;/	mov    0x8(%rbp),%rax
;/*	mov	0x08(rbp),rax	; 80404264 
	DB 0x48,0x8B,0x45,0x8
;/	lea    0x10(%rbp),%rbp
;/*	lea	0x10(rbp),rbp	; 80404268 
	DB 0x48,0x8D,0x6D,0x10
;/	NEXT
	ret		; 8040426C C3 
;/END-CODE
;/
;/CODE 1+!	( N A -- )
;/	incq   (%rax)


_1addsave:
;/*	incq	(rax)	; 8040426D 
	DB 0x48,0xFF,0x0
;/	mov    0x0(%rbp),%rax
;/*	mov	0x00(rbp),rax	; 80404270 
	DB 0x48,0x8B,0x45,0x0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 80404274 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 80404278 C3 
;/END-CODE
;/
;/\ [A] = 0
;/CODE 0!		( A -- )
;/CODL OFF		( A -- )
;/	movq   $0,(%rax)


_OFF:
;/*	movq	$0x0,(rax)	; 80404279 
	DB 0x48,0xC7,0x0,0x0,0x0,0x0,0x0
;/	DROP,
;/*	mov	0x00(rbp),rax	; 80404280 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80404284 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 80404288 C3 
;/END-CODE
;/
;/CODE ON		( A -- )
;/	movq   $-1,(%rax)


_ON:
;/*	movq	$-0x1,(rax)	; 80404289 
	DB 0x48,0xC7,0x0,0xFF,0xFF,0xFF,0xFF
;/	DROP,
;/*	mov	0x00(rbp),rax	; 80404290 
	DB 0x48,0x8B,0x45,0x0
;/*	lea	0x08(rbp),rbp	; 80404294 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 80404298 C3 
;/END-CODE
;/
;/\  Fetch a 64 bit value from addr
;/CODE 2@		( addr -- low32bits high32bits )
;/	mov 8(%rax), %rdx


_2load:
;/*	mov	0x08(rax),rdx	; 80404299 
	DB 0x48,0x8B,0x50,0x8
;/	lea -8(%rbp), %rbp
;/*	lea	-0x08(rbp),rbp	; 8040429D 
	DB 0x48,0x8D,0x6D,0xF8
;/	mov %rdx, (%rbp)
;/*	mov	rdx,0x00(rbp)	; 804042A1 
	DB 0x48,0x89,0x55,0x0
;/	mov (%rax), %rax
;/*	mov	(rax),rax	; 804042A5 
	DB 0x48,0x8B,0x0
;/
;/	NEXT
	ret		; 804042A8 C3 
;/END-CODE
;/
;/CODE 2!		( D A -- )
;/	mov (%rbp), %rdx


_2save:
;/*	mov	0x00(rbp),rdx	; 804042A9 
	DB 0x48,0x8B,0x55,0x0
;/	mov %rdx, (%rax)
;/*	mov	rdx,(rax)	; 804042AD 
	DB 0x48,0x89,0x10
;/	mov 8(%rbp), %rdx
;/*	mov	0x08(rbp),rdx	; 804042B0 
	DB 0x48,0x8B,0x55,0x8
;/     	mov %rdx, 8(%rax)
;/*	mov	rdx,0x08(rax)	; 804042B4 
	DB 0x48,0x89,0x50,0x8
;/	mov 0x10(%rbp), %rax
;/*	mov	0x10(rbp),rax	; 804042B8 
	DB 0x48,0x8B,0x45,0x10
;/	lea 0x18(%rbp),%rbp
;/*	lea	0x18(rbp),rbp	; 804042BC 
	DB 0x48,0x8D,0x6D,0x18
;/	NEXT
	ret		; 804042C0 C3 
;/END-CODE
;/
;/
;/CODE COUNT	( a -- a+1 c ) 
;/	lea    -0x8(%rbp),%rbp


_COUNT:
;/*	lea	-0x08(rbp),rbp	; 804042C1 
	DB 0x48,0x8D,0x6D,0xF8
;/	lea    0x1(%rax),%rdx
;/*	lea	0x01(rax),rdx	; 804042C5 
	DB 0x48,0x8D,0x50,0x1
;/	movzbq (%rax),%rax
;/*	movzbq	(rax),rax	; 804042C9 
	DB 0x48,0xF,0xB6,0x0
;/	mov    %rdx,0x0(%rbp)
;/*	mov	rdx,0x00(rbp)	; 804042CD 
	DB 0x48,0x89,0x55,0x0
;/	NEXT
	ret		; 804042D1 C3 
;/END-CODE
;/
;/CODE U>D
;/	lea    -0x8(%rbp),%rbp


_UgreatD:
;/*	lea	-0x08(rbp),rbp	; 804042D2 
	DB 0x48,0x8D,0x6D,0xF8
;/	mov    %rax,0x0(%rbp)
;/*	mov	rax,0x00(rbp)	; 804042D6 
	DB 0x48,0x89,0x45,0x0
;/	xor    %rax,%rax
;/*	xor	rax,rax	; 804042DA 
	DB 0x48,0x31,0xC0
;/	NEXT
	ret		; 804042DD C3 
;/END-CODE
;/
;/CODE S>D
;/	DUP,


_SgreatD:
;/*	lea	-0x08(rbp),rbp	; 804042DE 
	DB 0x48,0x8D,0x6D,0xF8
;/*	mov	rax,0x00(rbp)	; 804042E2 
	DB 0x48,0x89,0x45,0x0
;/	sar    $0x3f,%rax
;/*	sar	$0x3F,rax	; 804042E6 
	DB 0x48,0xC1,0xF8,0x3F
;/	NEXT
	ret		; 804042EA C3 
;/END-CODE
;/
;/CODE C>S ( c -- n )
;/	movsbq	%al,%rax


_CgreatS:
;/*	movsbq	al,rax	; 804042EB 
	DB 0x48,0xF,0xBE,0xC0
;/	NEXT
	ret		; 804042EF C3 
;/END-CODE
;/
;/CODE W>S ( c -- n )
;/	movswq %ax,%rax


_WgreatS:
;/*	movswq	ax,rax	; 804042F0 
	DB 0x48,0xF,0xBF,0xC0
;/	NEXT
	ret		; 804042F4 C3 
;/END-CODE
;/
;/CODE L>S ( c -- n )
;/	movslq %eax,%rax


_LgreatS:
;/*	movslq	rax,rax	; 804042F5 
	DB 0x48,0x63,0xC0
;/	NEXT
	ret		; 804042F8 C3 
;/END-CODE
;/
;/CODE MIN	( N1,N2 -- MIN )
;/	cmp    0x0(%rbp),%rax


_MIN:
;/*	cmp	0x00(rbp),rax	; 804042F9 
	DB 0x48,0x3B,0x45,0x0
;/	cmovg  0x0(%rbp),%rax
;/*	cmovNle;/*	cmov	0x00(rbp),rax	; 804042FD 
	DB 0x48,0xF,0x4F,0x45,0x0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 80404302 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 80404306 C3 
;/END-CODE
;/
;/CODE UMIN	( N1,N2 -- MIN )
;/	cmp    0x0(%rbp),%rax


_UMIN:
;/*	cmp	0x00(rbp),rax	; 80404307 
	DB 0x48,0x3B,0x45,0x0
;/	cmova  0x0(%rbp),%rax
;/*	cmovNbe;/*	cmov	0x00(rbp),rax	; 8040430B 
	DB 0x48,0xF,0x47,0x45,0x0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 80404310 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 80404314 C3 
;/END-CODE
;/
;/CODE MAX	( N1,N2 -- MAX )
;/	cmp    0x0(%rbp),%rax


_MAX:
;/*	cmp	0x00(rbp),rax	; 80404315 
	DB 0x48,0x3B,0x45,0x0
;/	cmovl  0x0(%rbp),%rax
;/*	cmovl;/*	cmov	0x00(rbp),rax	; 80404319 
	DB 0x48,0xF,0x4C,0x45,0x0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 8040431E 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 80404322 C3 
;/END-CODE
;/
;/\ ÌÀÊÑÈÌÓÌ
;/CODE UMAX	( N1,N2 -- MAX )
;/	cmp    0x0(%rbp),%rax


_UMAX:
;/*	cmp	0x00(rbp),rax	; 80404323 
	DB 0x48,0x3B,0x45,0x0
;/	cmovb  0x0(%rbp),%rax
;/*	cmovb;/*	cmov	0x00(rbp),rax	; 80404327 
	DB 0x48,0xF,0x42,0x45,0x0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 8040432C 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 80404330 C3 
;/END-CODE
;/
;/\ Return absolute value of top stack item
;/CODE ABS	( n -- +n )
;/	cqto


_ABS:
	dw 9948h		; 80404331 48 99 
;/	xor %rdx, %rax
;/*	xor	rdx,rax	; 80404333 
	DB 0x48,0x31,0xD0
;/	sub %rdx, %rax
;/*	sub	rdx,rax	; 80404336 
	DB 0x48,0x29,0xD0
;/	NEXT
	ret		; 80404339 C3 
;/ASM_END
;/
;/\  If n1 is equal to n2, return TRUE. Otherwise FALSE.
;/CODE =		( a b -- f )
;/\  If n is equal to 0, return TRUE. Otherwise FALSE.
;/	xor    0x0(%rbp),%rax


_equ:
;/*	xor	0x00(rbp),rax	; 8040433A 
	DB 0x48,0x33,0x45,0x0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 8040433E 
	DB 0x48,0x8D,0x6D,0x8
;/CODL 0=		( a -- f )
;/     	sub    $1 , %rax
_0equ:
;/*	sub	$0x01,rax	; 80404342 
	DB 0x48,0x83,0xE8,0x1
;/     	sbb	%rax,%rax
;/*	sbb	rax,rax	; 80404346 
	DB 0x48,0x19,0xC0
;/
;/	NEXT
	ret		; 80404349 C3 
;/END-CODE
;/
;/' =	TO '=
;/
;/CODE  D= ( xd1 xd2 -- flag ) \ 94 DOUBLE
;/\ flag is true if and only if xd1 is bit-for-bit the same as xd2
;/	mov    (%rbp),%rdx


_Dequ:
;/*	mov	0x00(rbp),rdx	; 8040434A 
	DB 0x48,0x8B,0x55,0x0
;/	xor    8(%rbp),%rax
;/*	xor	0x08(rbp),rax	; 8040434E 
	DB 0x48,0x33,0x45,0x8
;/	xor    0x10(%rbp),%rdx
;/*	xor	0x10(rbp),rdx	; 80404352 
	DB 0x48,0x33,0x55,0x10
;/	or     %rdx,%rax
;/*	or	rdx,rax	; 80404356 
	DB 0x48,0x9,0xD0
;/	sub    $0x1,%rax
;/*	sub	$0x01,rax	; 80404359 
	DB 0x48,0x83,0xE8,0x1
;/	sbb    %rax,%rax
;/*	sbb	rax,rax	; 8040435D 
	DB 0x48,0x19,0xC0
;/	lea    0x18(%rbp),%rbp
;/*	lea	0x18(rbp),rbp	; 80404360 
	DB 0x48,0x8D,0x6D,0x18
;/	NEXT
	ret		; 80404364 C3 
;/END-CODE
;/
;/CODE D0=		( a b -- f )
;/	or     0x0(%rbp),%rax


_D0equ:
;/*	or	0x00(rbp),rax	; 80404365 
	DB 0x48,0xB,0x45,0x0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 80404369 
	DB 0x48,0x8D,0x6D,0x8
;/	sub    $0x1,%rax
;/*	sub	$0x01,rax	; 8040436D 
	DB 0x48,0x83,0xE8,0x1
;/	sbb    %rax,%rax
;/*	sbb	rax,rax	; 80404371 
	DB 0x48,0x19,0xC0
;/	NEXT
	ret		; 80404374 C3 
;/END-CODE
;/
;/CODE >		( a b -- f )
;/	cmp	(%rbp),%rax


_great:
;/*	cmp	0x00(rbp),rax	; 80404375 
	DB 0x48,0x3B,0x45,0x0
;/	setl	%al
	setl	al	; 80404379 F 9C C0 
;/	neg	%al
;/*		neg	al	; 8040437C 
	DB 0xF6,0xD8
;/	movsb	%al,%rax
;/*	movsbq	al,rax	; 8040437E 
	DB 0x48,0xF,0xBE,0xC0
;/	lea	8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 80404382 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 80404386 C3 
;/END-CODE
;/
;/CODE <		( a b -- f )
;/	cmp	(%rbp),%rax


_less:
;/*	cmp	0x00(rbp),rax	; 80404387 
	DB 0x48,0x3B,0x45,0x0
;/	setg	%al
	setNle	al	; 8040438B F 9F C0 
;/	neg	%al
;/*		neg	al	; 8040438E 
	DB 0xF6,0xD8
;/	movsb	%al,%rax
;/*	movsbq	al,rax	; 80404390 
	DB 0x48,0xF,0xBE,0xC0
;/	lea	8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 80404394 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 80404398 C3 
;/END-CODE
;/
;/\ If n1 is not equal to n2, return TRUE.  Otherwise FALSE.
;/CODE <>		( a b -- f )
;/	xor    0x0(%rbp),%rax


_lessgreat:
;/*	xor	0x00(rbp),rax	; 80404399 
	DB 0x48,0x33,0x45,0x0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 8040439D 
	DB 0x48,0x8D,0x6D,0x8
;/\ If n is not equal to 0, return TRUE.  Otherwise FALSE.
;/CODL 0<>		( a b -- f )
;/	neg    %rax
_0lessgreat:
;/*		negq	rax	; 804043A1 
	DB 0x48,0xF7,0xD8
;/	sbb    %rax,%rax
;/*	sbb	rax,rax	; 804043A4 
	DB 0x48,0x19,0xC0
;/	NEXT
	ret		; 804043A7 C3 
;/END-CODE
;/
;/CODE 0>		( n -- f )
;/	neg    %rax


_0great:
;/*		negq	rax	; 804043A8 
	DB 0x48,0xF7,0xD8
;/\ Returns true if top is negative, ie sign bit is on.
;/CODL 0<		( n -- f )
;/	sar    $0x3f,%rax
_0less:
;/*	sar	$0x3F,rax	; 804043AB 
	DB 0x48,0xC1,0xF8,0x3F
;/	NEXT
	ret		; 804043AF C3 
;/END-CODE
;/
;/CODE U>	( n1 n2 -- f )
;/	cmp    0x0(%rbp),%rax


_Ugreat:
;/*	cmp	0x00(rbp),rax	; 804043B0 
	DB 0x48,0x3B,0x45,0x0
;/	sbb    %rax,%rax
;/*	sbb	rax,rax	; 804043B4 
	DB 0x48,0x19,0xC0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 804043B7 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 804043BB C3 
;/END-CODE
;/
;/CODE U< ( a b -- f )
;/	cmp    %rax,0x0(%rbp)


_Uless:
;/*	cmp	rax,0x00(rbp)	; 804043BC 
	DB 0x48,0x39,0x45,0x0
;/	sbb    %rax,%rax
;/*	sbb	rax,rax	; 804043C0 
	DB 0x48,0x19,0xC0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 804043C3 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 804043C7 C3 
;/END-CODE
;/
;/CODE WITHIN
;/	mov    0x8(%rbp),%rdx


_WITHIN:
;/*	mov	0x08(rbp),rdx	; 804043C8 
	DB 0x48,0x8B,0x55,0x8
;/	sub    0x0(%rbp),%rax
;/*	sub	0x00(rbp),rax	; 804043CC 
	DB 0x48,0x2B,0x45,0x0
;/	sub    0x0(%rbp),%rdx
;/*	sub	0x00(rbp),rdx	; 804043D0 
	DB 0x48,0x2B,0x55,0x0
;/	sub    %rax,%rdx
;/*	sub	rax,rdx	; 804043D4 
	DB 0x48,0x29,0xC2
;/	sbb    %rax,%rax
;/*	sbb	rax,rax	; 804043D7 
	DB 0x48,0x19,0xC0
;/	lea    0x10(%rbp),%rbp
;/*	lea	0x10(rbp),rbp	; 804043DA 
	DB 0x48,0x8D,0x6D,0x10
;/	NEXT
	ret		; 804043DE C3 
;/END-CODE
;/
;/CODE ANDC	( N1,N2 -- N )
;/	not    %rax


_ANDC:
;/*		notq	rax	; 804043DF 
	DB 0x48,0xF7,0xD0
;/\ Perform bit-wise logical AND of top two items.
;/CODL AND	( N1,N2 -- N )
;/	and    0x0(%rbp),%rax
_AND:
;/*	and	0x00(rbp),rax	; 804043E2 
	DB 0x48,0x23,0x45,0x0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 804043E6 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 804043EA C3 
;/END-CODE
;/
;/
;/\ Perform bit-wise logical OR of top two items on parameter stack.
;/CODE OR		( N1,N2 -- N )
;/	or     0x0(%rbp),%rax


_OR:
;/*	or	0x00(rbp),rax	; 804043EB 
	DB 0x48,0xB,0x45,0x0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 804043EF 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 804043F3 C3 
;/END-CODE
;/
;/\ Perform bit-wise logical XOR of top two items on parameter stack.
;/CODE XOR	( N1,N2 -- N )
;/	xor	0x0(%rbp),%rax


_XOR:
;/*	xor	0x00(rbp),rax	; 804043F4 
	DB 0x48,0x33,0x45,0x0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 804043F8 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 804043FC C3 
;/END-CODE
;/
;/
;/
;/\ Logically invert the bits of top stack item.
;/CODE INVERT	( N -- N1 )
;/CODL NOT	( N -- N1 )
;/	not    %rax


_NOT:
;/*		notq	rax	; 804043FD 
	DB 0x48,0xF7,0xD0
;/	NEXT
	ret		; 80404400 C3 
;/ASM_END
;/
;/\ Negate number on top of stack.
;/CODE NEGATE	( n - -n)
;/	neg    %rax


_NEGATE:
;/*		negq	rax	; 80404401 
	DB 0x48,0xF7,0xD8
;/	NEXT
	ret		; 80404404 C3 
;/ASM_END
;/
;/CODE DNEGATE ( d - -d)
;/	mov    0x0(%rbp),%rdx


_DNEGATE:
;/*	mov	0x00(rbp),rdx	; 80404405 
	DB 0x48,0x8B,0x55,0x0
;/	neg    %rax
;/*		negq	rax	; 80404409 
	DB 0x48,0xF7,0xD8
;/	neg    %rdx
;/*		negq	rdx	; 8040440C 
	DB 0x48,0xF7,0xDA
;/     	sbb    $0x0,%rax \ $48 C, $83 C, $d8 C, $00 C, \
;/*	sbb	$0x00,rax	; 8040440F 
	DB 0x48,0x83,0xD8,0x0
;/	mov    %rdx,0x0(%rbp)
;/*	mov	rdx,0x00(rbp)	; 80404413 
	DB 0x48,0x89,0x55,0x0
;/	NEXT
	ret		; 80404417 C3 
;/ASM_END
;/
;/CODE -		( N1,N2 -- N1-N2 )
;/	neg    %rax


_sub:
;/*		negq	rax	; 80404418 
	DB 0x48,0xF7,0xD8
;/CODL +		( N1 N2 -- N1+N2 )
;/	add    0x0(%rbp),%rax
_add:
;/*	add	0x00(rbp),rax	; 8040441B 
	DB 0x48,0x3,0x45,0x0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 8040441F 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 80404423 C3 
;/END-CODE
;/' + TO '+
;/
;/CODE D+ ( d1|ud1 d2|ud2 -- d3|ud3 ) \ 94 DOUBLE
;/	mov    0x0(%rbp),%rdx


_Dadd:
;/*	mov	0x00(rbp),rdx	; 80404424 
	DB 0x48,0x8B,0x55,0x0
;/	add    %rdx,0x10(%rbp)
;/*	add	rdx,0x10(rbp)	; 80404428 
	DB 0x48,0x1,0x55,0x10
;/	adc    0x8(%rbp),%rax
;/*	adc	0x08(rbp),rax	; 8040442C 
	DB 0x48,0x13,0x45,0x8
;/	lea    0x10(%rbp),%rbp
;/*	lea	0x10(rbp),rbp	; 80404430 
	DB 0x48,0x8D,0x6D,0x10
;/	NEXT
	ret		; 80404434 C3 
;/ASM_END
;/
;/CODE D- ( d1|ud1 d2|ud2 -- d3|ud3 ) \ 94 DOUBLE
;/	mov    (%rbp),%rdx


_Dsub:
;/*	mov	0x00(rbp),rdx	; 80404435 
	DB 0x48,0x8B,0x55,0x0
;/	sub    %rdx,0x10(%rbp)
;/*	sub	rdx,0x10(rbp)	; 80404439 
	DB 0x48,0x29,0x55,0x10
;/	mov    8(%rbp),%rdx
;/*	mov	0x08(rbp),rdx	; 8040443D 
	DB 0x48,0x8B,0x55,0x8
;/	sbb    %rax,%rdx
;/*	sbb	rax,rdx	; 80404441 
	DB 0x48,0x19,0xC2
;/	mov    %rdx,%rax
;/*	mov	rdx,rax	; 80404444 
	DB 0x48,0x89,0xD0
;/	lea	0x10(%rbp),%rbp
;/*	lea	0x10(rbp),rbp	; 80404447 
	DB 0x48,0x8D,0x6D,0x10
;/	NEXT
	ret		; 8040444B C3 
;/ASM_END
;/
;/CODE D< ( d1 d2 -- flg ) \ 94 DOUBLE
;/	mov    (%rbp),%rdx


_Dless:
;/*	mov	0x00(rbp),rdx	; 8040444C 
	DB 0x48,0x8B,0x55,0x0
;/	cmp    %rdx,0x10(%rbp)
;/*	cmp	rdx,0x10(rbp)	; 80404450 
	DB 0x48,0x39,0x55,0x10
;/	sbb    %rax,0x8(%rbp)
;/*	sbb	rax,0x08(rbp)	; 80404454 
	DB 0x48,0x19,0x45,0x8
;/	setl   %al
	setl	al	; 80404458 F 9C C0 
;/	neg    %al
;/*		neg	al	; 8040445B 
	DB 0xF6,0xD8
;/	movsbq %al,%rax
;/*	movsbq	al,rax	; 8040445D 
	DB 0x48,0xF,0xBE,0xC0
;/	lea	0x18(%rbp),%rbp
;/*	lea	0x18(rbp),rbp	; 80404461 
	DB 0x48,0x8D,0x6D,0x18
;/	NEXT
	ret		; 80404465 C3 
;/ASM_END
;/
;/CODE D2/ \ d1 -- d1/2
;/	sar    %rax


_D2rsl:
;/*	sarq	$1,rax	; 80404466 
	DB 0x48,0xD1,0xF8
;/	$48 C, $d1 C, $5d C, 0 C, \ rcrq   0x0(%rbp)
;/*	rcrq	$1,0x00(rbp)	; 80404469 
	DB 0x48,0xD1,0x5D,0x0
;/	NEXT
	ret		; 8040446D C3 
;/ASM_END
;/
;/CODE CELL+	( N -- N+8 )
;/	lea    4(%rax),%rax


_CELLadd:
;/*	lea	0x04(rax),rax	; 8040446E 
	DB 0x48,0x8D,0x40,0x4
;/CODL 4+		( N -- N+4 )
;/	inc    %rax
_4add:
;/*	incq	rax	; 80404472 
	DB 0x48,0xFF,0xC0
;/CODL 3+		( N -- N+2 )
;/	inc    %rax
_3add:
;/*	incq	rax	; 80404475 
	DB 0x48,0xFF,0xC0
;/CODL 2+		( N -- N+2 )
;/	inc    %rax
_2add:
;/*	incq	rax	; 80404478 
	DB 0x48,0xFF,0xC0
;/CODL 1+		( N -- N+1 )
;/CODL CHAR+
;/	inc    %rax
_CHARadd:
;/*	incq	rax	; 8040447B 
	DB 0x48,0xFF,0xC0
;/	NEXT
	ret		; 8040447E C3 
;/END-CODE
;/\ 4 TR> DECIMAL 1+ .
;/
;/CODE CELL-	( N -- N-8 )
;/	lea    -4(%rax),%rax


_CELLsub:
;/*	lea	-0x04(rax),rax	; 8040447F 
	DB 0x48,0x8D,0x40,0xFC
;/CODL 4-		( N -- N+4 )
;/	lea    -2(%rax),%rax
_4sub:
;/*	lea	-0x02(rax),rax	; 80404483 
	DB 0x48,0x8D,0x40,0xFE
;/CODL 2-		( N -- N-2 )
;/	dec    %rax
_2sub:
;/*	decq	rax	; 80404487 
	DB 0x48,0xFF,0xC8
;/CODL 1-		( N -- N-1 )
;/	dec    %rax
_1sub:
;/*	decq	rax	; 8040448A 
	DB 0x48,0xFF,0xC8
;/	NEXT
	ret		; 8040448D C3 
;/END-CODE
;/
;/CODE CELLS	( N -- 8*N )
;/	lea    (%rax,%rax,1),%rax


_CELLS:
;/*	lea	(rax,rax,1),rax	; 8040448E 
	DB 0x48,0x8D,0x4,0x0
;/CODL 4*	( N -- 4*N )
;/	lea    (%rax,%rax,1),%rax
_4mul:
;/*	lea	(rax,rax,1),rax	; 80404492 
	DB 0x48,0x8D,0x4,0x0
;/CODL 2*		( N -- 2*N )
;/	lea    (%rax,%rax,1),%rax
_2mul:
;/*	lea	(rax,rax,1),rax	; 80404496 
	DB 0x48,0x8D,0x4,0x0
;/	NEXT
	ret		; 8040449A C3 
;/END-CODE
;/
;/CODE 2/		( N -- N/2 )
;/	sar    %rax


_2rsl:
;/*	sarq	$1,rax	; 8040449B 
	DB 0x48,0xD1,0xF8
;/	NEXT
	ret		; 8040449E C3 
;/END-CODE
;/
;/CODE U2/        ( N -- N/U2 )
;/	shr    %rax


_U2rsl:
;/*	shrq	$1,rax	; 8040449F 
	DB 0x48,0xD1,0xE8
;/        NEXT
	ret		; 804044A2 C3 
;/END-CODE
;/
;/\ 32*32=lo(32)
;/CODE *		( a b -- a*b )
;/	imulq  0x0(%rbp)


_mul:
;/*		imulq	0x00(rbp)	; 804044A3 
	DB 0x48,0xF7,0x6D,0x0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 804044A7 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 804044AB C3 
;/END-CODE
;/
;/CODE /
;/	mov    %rax,%rcx


_rsl:
;/*	mov	rax,rcx	; 804044AC 
	DB 0x48,0x89,0xC1
;/	mov    0x0(%rbp),%rax
;/*	mov	0x00(rbp),rax	; 804044AF 
	DB 0x48,0x8B,0x45,0x0
;/	cqto
	dw 9948h		; 804044B3 48 99 
;/	idiv   %rcx
;/*		idivq	rcx	; 804044B5 
	DB 0x48,0xF7,0xF9
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 804044B8 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 804044BC C3 
;/ASM_END
;/
;/CODE MOD
;/	mov    %rax,%rcx


_MOD:
;/*	mov	rax,rcx	; 804044BD 
	DB 0x48,0x89,0xC1
;/	mov    0x0(%rbp),%rax
;/*	mov	0x00(rbp),rax	; 804044C0 
	DB 0x48,0x8B,0x45,0x0
;/	cqto
	dw 9948h		; 804044C4 48 99 
;/	idiv   %rcx
;/*		idivq	rcx	; 804044C6 
	DB 0x48,0xF7,0xF9
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 804044C9 
	DB 0x48,0x8D,0x6D,0x8
;/	mov    %rdx,%rax
;/*	mov	rdx,rax	; 804044CD 
	DB 0x48,0x89,0xD0
;/	NEXT
	ret		; 804044D0 C3 
;/ASM_END
;/
;/
;/CODE U/
;/	mov    %rax,%rcx


_Ursl:
;/*	mov	rax,rcx	; 804044D1 
	DB 0x48,0x89,0xC1
;/	mov    0x0(%rbp),%rax
;/*	mov	0x00(rbp),rax	; 804044D4 
	DB 0x48,0x8B,0x45,0x0
;/	xor    %rdx,%rdx
;/*	xor	rdx,rdx	; 804044D8 
	DB 0x48,0x31,0xD2
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 804044DB 
	DB 0x48,0x8D,0x6D,0x8
;/	div    %rcx
;/*		divq	rcx	; 804044DF 
	DB 0x48,0xF7,0xF1
;/	NEXT
	ret		; 804044E2 C3 
;/ASM_END
;/
;/CODE UM*
;/	mulq   0x0(%rbp)


_UMmul:
;/*		mulq	0x00(rbp)	; 804044E3 
	DB 0x48,0xF7,0x65,0x0
;/	mov    %rax,0x0(%rbp)
;/*	mov	rax,0x00(rbp)	; 804044E7 
	DB 0x48,0x89,0x45,0x0
;/	mov    %rdx,%rax
;/*	mov	rdx,rax	; 804044EB 
	DB 0x48,0x89,0xD0
;/	NEXT
	ret		; 804044EE C3 
;/ASM_END
;/
;/CODE M*
;/     	imulq  0x0(%rbp)


_Mmul:
;/*		imulq	0x00(rbp)	; 804044EF 
	DB 0x48,0xF7,0x6D,0x0
;/	mov    %rax,0x0(%rbp)
;/*	mov	rax,0x00(rbp)	; 804044F3 
	DB 0x48,0x89,0x45,0x0
;/	mov    %rdx,%rax
;/*	mov	rdx,rax	; 804044F7 
	DB 0x48,0x89,0xD0
;/	NEXT
	ret		; 804044FA C3 
;/ASM_END
;/
;/CODE /MOD ( n1 n2 -- rem quot )
;/	mov    %rax,%rcx


_rslMOD:
;/*	mov	rax,rcx	; 804044FB 
	DB 0x48,0x89,0xC1
;/	mov    0x0(%rbp),%rax
;/*	mov	0x00(rbp),rax	; 804044FE 
	DB 0x48,0x8B,0x45,0x0
;/	cqto
	dw 9948h		; 80404502 48 99 
;/	idiv   %rcx
;/*		idivq	rcx	; 80404504 
	DB 0x48,0xF7,0xF9
;/	mov    %rdx,0x0(%rbp)
;/*	mov	rdx,0x00(rbp)	; 80404507 
	DB 0x48,0x89,0x55,0x0
;/	NEXT
	ret		; 8040450B C3 
;/ASM_END
;/
;/CODE UM/MOD
;/	mov    %rax,%rcx


_UMrslMOD:
;/*	mov	rax,rcx	; 8040450C 
	DB 0x48,0x89,0xC1
;/	mov    0x0(%rbp),%rdx
;/*	mov	0x00(rbp),rdx	; 8040450F 
	DB 0x48,0x8B,0x55,0x0
;/	mov    0x8(%rbp),%rax
;/*	mov	0x08(rbp),rax	; 80404513 
	DB 0x48,0x8B,0x45,0x8
;/	div    %rcx
;/*		divq	rcx	; 80404517 
	DB 0x48,0xF7,0xF1
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 8040451A 
	DB 0x48,0x8D,0x6D,0x8
;/	mov    %rdx,0x0(%rbp)
;/*	mov	rdx,0x00(rbp)	; 8040451E 
	DB 0x48,0x89,0x55,0x0
;/	NEXT
	ret		; 80404522 C3 
;/ASM_END
;/
;/\ duplicate n1 if <> 0
;/CODE ?DUP	( N -- N,N )  ( 0 -- 0 )
;/     	test     %rax,%rax


_queDUP:
	test	rax,rax	; 80404523 48 85 C0 
;/	je	0f
	jz	_DUP+0x8 	; 80404526 74 8 
;/CODL DUP	( N -- N,N )  \ Duplicate the top element of the stack.
;/	DUP,
_DUP:
;/*	lea	-0x08(rbp),rbp	; 80404528 
	DB 0x48,0x8D,0x6D,0xF8
;/*	mov	rax,0x00(rbp)	; 8040452C 
	DB 0x48,0x89,0x45,0x0
;/0:	NEXT
	ret		; 80404530 C3 
;/ASM_END
;/\ END-CODE
;/' DUP TO 'DUP
;/
;/\ Duplicate double element of data stack.
;/CODE 2DUP	(  a b -- a b a b )
;/	mov    0x0(%rbp),%rdx


_2DUP:
;/*	mov	0x00(rbp),rdx	; 80404531 
	DB 0x48,0x8B,0x55,0x0
;/	mov    %rax,-0x8(%rbp)
;/*	mov	rax,-0x08(rbp)	; 80404535 
	DB 0x48,0x89,0x45,0xF8
;/	mov    %rdx,-0x10(%rbp)
;/*	mov	rdx,-0x10(rbp)	; 80404539 
	DB 0x48,0x89,0x55,0xF0
;/	lea    -0x10(%rbp),%rbp
;/*	lea	-0x10(rbp),rbp	; 8040453D 
	DB 0x48,0x8D,0x6D,0xF0
;/	NEXT
	ret		; 80404541 C3 
;/END-CODE
;/
;/\ Exchange the top two items on the stack
;/CODE SWAP	( N1,N2 -- N2,N1 )
;/	mov    0x0(%rbp),%rdx


_SWAP:
;/*	mov	0x00(rbp),rdx	; 80404542 
	DB 0x48,0x8B,0x55,0x0
;/	mov    %rax,0x0(%rbp)
;/*	mov	rax,0x00(rbp)	; 80404546 
	DB 0x48,0x89,0x45,0x0
;/	mov    %rdx,%rax
;/*	mov	rdx,rax	; 8040454A 
	DB 0x48,0x89,0xD0
;/	NEXT
	ret		; 8040454D C3 
;/END-CODE
;/
;/CODE CS-SWAP
;/	nop


_CSsubSWAP:
	nop		; 8040454E 90 
;/\ Swap double element of data stack.
;/CODL 2SWAP	( n1 n2  n3 n4 -- n3 n4  n1 n2 )
;/	mov    0x0(%rbp),%rcx
_2SWAP:
;/*	mov	0x00(rbp),rcx	; 8040454F 
	DB 0x48,0x8B,0x4D,0x0
;/	mov    0x8(%rbp),%rdx
;/*	mov	0x08(rbp),rdx	; 80404553 
	DB 0x48,0x8B,0x55,0x8
;/	mov    0x10(%rbp),%rbx
;/*	mov	0x10(rbp),rbx	; 80404557 
	DB 0x48,0x8B,0x5D,0x10
;/	mov    %rcx,0x10(%rbp)
;/*	mov	rcx,0x10(rbp)	; 8040455B 
	DB 0x48,0x89,0x4D,0x10
;/	mov    %rax,0x8(%rbp)
;/*	mov	rax,0x08(rbp)	; 8040455F 
	DB 0x48,0x89,0x45,0x8
;/	mov    %rbx,0x0(%rbp)
;/*	mov	rbx,0x00(rbp)	; 80404563 
	DB 0x48,0x89,0x5D,0x0
;/	mov    %rdx,%rax
;/*	mov	rdx,rax	; 80404567 
	DB 0x48,0x89,0xD0
;/	NEXT
	ret		; 8040456A C3 
;/END-CODE
;/
;/\ Remove double element of data stack.
;/CODE CS-DROP
;/	nop


_CSsubDROP:
	nop		; 8040456B 90 
;/CODL 2DROP  	( D -- )
;/	mov    0x8(%rbp),%rax
_2DROP:
;/*	mov	0x08(rbp),rax	; 8040456C 
	DB 0x48,0x8B,0x45,0x8
;/	lea    0x10(%rbp),%rbp
;/*	lea	0x10(rbp),rbp	; 80404570 
	DB 0x48,0x8D,0x6D,0x10
;/	NEXT
	ret		; 80404574 C3 
;/END-CODE
;/
;/CODE CS-PICK  ( xu .. x0 u -- xu .. x0 xu )
;/	lea    (%rax,%rax),%rax


_CSsubPICK:
;/*	lea	(rax,rax,1),rax	; 80404575 
	DB 0x48,0x8D,0x4,0x0
;/	mov    8(%rbp,%rax,8),%rdx
;/*	mov	0x08(rbp,rax,8),rdx	; 80404579 
	DB 0x48,0x8B,0x54,0xC5,0x8
;/	lea	-0x08(%rbp),%rbp
;/*	lea	-0x08(rbp),rbp	; 8040457E 
	DB 0x48,0x8D,0x6D,0xF8
;/	mov	%rdx,(%rbp)
;/*	mov	rdx,0x00(rbp)	; 80404582 
	DB 0x48,0x89,0x55,0x0
;/	mov    8(%rbp,%rax,8),%rax
;/*	mov	0x08(rbp,rax,8),rax	; 80404586 
	DB 0x48,0x8B,0x44,0xC5,0x8
;/	ret
	ret		; 8040458B C3 
;/END-CODE
;/
;/CODE 2NIP	( D -- )
;/	mov    (%rbp),%rdx


_2NIP:
;/*	mov	0x00(rbp),rdx	; 8040458C 
	DB 0x48,0x8B,0x55,0x0
;/	lea    0x10(%rbp),%rbp
;/*	lea	0x10(rbp),rbp	; 80404590 
	DB 0x48,0x8D,0x6D,0x10
;/	mov    %rdx,(%rbp)
;/*	mov	rdx,0x00(rbp)	; 80404594 
	DB 0x48,0x89,0x55,0x0
;/	NEXT
	ret		; 80404598 C3 
;/END-CODE
;/
;/\ Push a copy of the second stack item.
;/CODE OVER	( n1 n2 -- n1 n2 n1 )
;/	lea    -0x8(%rbp),%rbp


_OVER:
;/*	lea	-0x08(rbp),rbp	; 80404599 
	DB 0x48,0x8D,0x6D,0xF8
;/	mov    %rax,0x0(%rbp)
;/*	mov	rax,0x00(rbp)	; 8040459D 
	DB 0x48,0x89,0x45,0x0
;/	mov    0x8(%rbp),%rax
;/*	mov	0x08(rbp),rax	; 804045A1 
	DB 0x48,0x8B,0x45,0x8
;/	NEXT
	ret		; 804045A5 C3 
;/END-CODE
;/
;/' OVER	TO 'OVER
;/
;/CODE 2OVER	( n1 n2 -- n1 n2 n1 )
;/	mov 16(%rbp),%rdx


_2OVER:
;/*	mov	0x10(rbp),rdx	; 804045A6 
	DB 0x48,0x8B,0x55,0x10
;/	mov %rax,-8(%rbp)
;/*	mov	rax,-0x08(rbp)	; 804045AA 
	DB 0x48,0x89,0x45,0xF8
;/	mov %rdx,-16(%rbp)
;/*	mov	rdx,-0x10(rbp)	; 804045AE 
	DB 0x48,0x89,0x55,0xF0
;/	mov 8(%rbp),%rax
;/*	mov	0x08(rbp),rax	; 804045B2 
	DB 0x48,0x8B,0x45,0x8
;/	lea -16(%rbp),%rbp
;/*	lea	-0x10(rbp),rbp	; 804045B6 
	DB 0x48,0x8D,0x6D,0xF0
;/	NEXT
	ret		; 804045BA C3 
;/END-CODE
;/
;/
;/CODE PICK	( Nm,...,N1,K -- Nm,...,N1,Nk )
;/	mov    (%rbp,%rax,8),%rax


_PICK:
;/*	mov	0x00(rbp,rax,8),rax	; 804045BB 
	DB 0x48,0x8B,0x44,0xC5,0x0
;/	NEXT
	ret		; 804045C0 C3 
;/END-CODE
;/
;/\ CODE PLUCK	( N1 N2 N3 -- N1 N2 N3 N1 ) 
;/\ Tuck the first element under the second one.
;/CODE TUCK	( n1 n2 --- n2 n1 n2 )
;/	lea    -0x8(%rbp),%rbp


_TUCK:
;/*	lea	-0x08(rbp),rbp	; 804045C1 
	DB 0x48,0x8D,0x6D,0xF8
;/	mov    0x8(%rbp),%rdx
;/*	mov	0x08(rbp),rdx	; 804045C5 
	DB 0x48,0x8B,0x55,0x8
;/	mov    %rax,0x8(%rbp)
;/*	mov	rax,0x08(rbp)	; 804045C9 
	DB 0x48,0x89,0x45,0x8
;/	mov    %rdx,0x0(%rbp)
;/*	mov	rdx,0x00(rbp)	; 804045CD 
	DB 0x48,0x89,0x55,0x0
;/	NEXT
	ret		; 804045D1 C3 
;/END-CODE
;/
;/CODE ROLL          \ nn..n0 n -- nn-1..n0 nn
;/\ *G Rotate the order of the top N stack items by one place such
;/\ ** that the current top of stack becomes the second item and
;/\ ** the Nth item becomes TOS. See also *\fo{ROT}.
;/	test   %rax,%rax


_ROLL:
	test	rax,rax	; 804045D2 48 85 C0 
;/	je     1f
	jz	_ROLL+0x31 	; 804045D5 74 2C 
;/	mov    %rax,%rcx
;/*	mov	rax,rcx	; 804045D7 
	DB 0x48,0x89,0xC1
;/	lea    (,%rax,8),%rax
;/*	lea	0x0(,rax,8),rax	; 804045DA 
	DB 0x48,0x8D,0x4,0xC5,0x0,0x0,0x0,0x0
;/	mov    %rbp,%rdx
;/*	mov	rbp,rdx	; 804045E2 
	DB 0x48,0x89,0xEA
;/	add    %rax,%rdx
;/*	add	rax,rdx	; 804045E5 
	DB 0x48,0x1,0xC2
;/	mov    (%rdx),%rbx
;/*	mov	(rdx),rbx	; 804045E8 
	DB 0x48,0x8B,0x1A
;/2:	lea    -8(%rdx),%rdx
;/*	lea	-0x08(rdx),rdx	; 804045EB 
	DB 0x48,0x8D,0x52,0xF8
;/	mov    (%rdx),%rax
;/*	mov	(rdx),rax	; 804045EF 
	DB 0x48,0x8B,0x2
;/	mov    %rax,8(%rdx)
;/*	mov	rax,0x08(rdx)	; 804045F2 
	DB 0x48,0x89,0x42,0x8
;/	dec    %rcx
;/*	decq	rcx	; 804045F6 
	DB 0x48,0xFF,0xC9
;/	jne    2b
	jNz	_ROLL+0x19 	; 804045F9 75 F0 
;/	mov    %rbx,%rax
;/*	mov	rbx,rax	; 804045FB 
	DB 0x48,0x89,0xD8
;/	jmp    3f
;/*	jmp	_ROLL+0x35 	; 804045FE 
	DB 0xE9,0x4,0x0,0x0,0x0
;/1:	mov    (%rbp),%rax
;/*	mov	0x00(rbp),rax	; 80404603 
	DB 0x48,0x8B,0x45,0x0
;/3:	lea    8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 80404607 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 8040460B C3 
;/END-CODE
;/
;/
;/
;/\ Delete the second stack item.
;/CODE NIP	( n1 n2 -- n2 )
;/	lea    0x8(%rbp),%rbp


_NIP:
;/*	lea	0x08(rbp),rbp	; 8040460C 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 80404610 C3 
;/END-CODE
;/
;/\ Rotate top three stack values, bringing the third item to the top.
;/CODE ROT	( n1 n2 n3 -- n2 n3 n1 )
;/	mov    0x0(%rbp),%rdx


_ROT:
;/*	mov	0x00(rbp),rdx	; 80404611 
	DB 0x48,0x8B,0x55,0x0
;/	mov    %rax,0x0(%rbp)
;/*	mov	rax,0x00(rbp)	; 80404615 
	DB 0x48,0x89,0x45,0x0
;/	mov    0x8(%rbp),%rax
;/*	mov	0x08(rbp),rax	; 80404619 
	DB 0x48,0x8B,0x45,0x8
;/	mov    %rdx,0x8(%rbp)
;/*	mov	rdx,0x08(rbp)	; 8040461D 
	DB 0x48,0x89,0x55,0x8
;/	NEXT
	ret		; 80404621 C3 
;/END-CODE
;/
;/
;/\ Rotate top three stack values, bringing the top item to the third.
;/CODE -ROT	( n1 n2 n3 -- n3 n1 n2 )
;/	mov    0x8(%rbp),%rdx


_subROT:
;/*	mov	0x08(rbp),rdx	; 80404622 
	DB 0x48,0x8B,0x55,0x8
;/	mov    %rax,0x8(%rbp)
;/*	mov	rax,0x08(rbp)	; 80404626 
	DB 0x48,0x89,0x45,0x8
;/	mov    0x0(%rbp),%rax
;/*	mov	0x00(rbp),rax	; 8040462A 
	DB 0x48,0x8B,0x45,0x0
;/	mov    %rdx,0x0(%rbp)
;/*	mov	rdx,0x00(rbp)	; 8040462E 
	DB 0x48,0x89,0x55,0x0
;/	NEXT
	ret		; 80404632 C3 
;/END-CODE
;/
;/
;/CODE ARSHIFT	( a b -- a>>b ) \ arithmetic shift
;/	mov    %al,%cl


_ARSHIFT:
;/*	mov	al,cl	; 80404633 
	DB 0x88,0xC1
;/	mov    0x0(%rbp),%rax
;/*	mov	0x00(rbp),rax	; 80404635 
	DB 0x48,0x8B,0x45,0x0
;/	sar    %cl,%rax
;/*	sarq	%cl,rax	; 80404639 
	DB 0x48,0xD3,0xF8
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 8040463C 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 80404640 C3 
;/END-CODE
;/
;/CODE RSHIFT	( a b -- a>>b )
;/CODL >>
;/	mov    %al,%cl


_greatgreat:
;/*	mov	al,cl	; 80404641 
	DB 0x88,0xC1
;/	mov    0x0(%rbp),%rax
;/*	mov	0x00(rbp),rax	; 80404643 
	DB 0x48,0x8B,0x45,0x0
;/	shr    %cl,%rax	
;/*	shrq	%cl,rax	; 80404647 
	DB 0x48,0xD3,0xE8
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 8040464A 
	DB 0x48,0x8D,0x6D,0x8
;/	NEXT
	ret		; 8040464E C3 
;/END-CODE
;/
;/
;/CODE LSHIFT	( a b -- a<<b )
;/CODL <<
;/	mov    %al,%cl


_lessless:
;/*	mov	al,cl	; 8040464F 
	DB 0x88,0xC1
;/	mov    0x0(%rbp),%rax
;/*	mov	0x00(rbp),rax	; 80404651 
	DB 0x48,0x8B,0x45,0x0
;/	shl    %cl,%rax
;/*	shlq	%cl,rax	; 80404655 
	DB 0x48,0xD3,0xE0
;/	lea    0x8(%rbp),%rbp
;/*	lea	0x08(rbp),rbp	; 80404658 
	DB 0x48,0x8D,0x6D,0x8
;/
;/	NEXT
	ret		; 8040465C C3 
;/END-CODE
;/
;/
;/CODE TlsIndex!
;/     	mov    %rax,%r12


_TlsIndexsave:
;/*	mov	rax,r12	; 8040465D 
	DB 0x49,0x89,0xC4
;/	' DROP BRANCH,
;/*	jmp	_DgreatS	; 80404660 
	DB 0xE9,0xCE,0xFA,0xFF,0xFF
;/END-CODE
;/
;/CODE TlsIndex@
;/	lea    -0x8(%rbp),%rbp


_TlsIndexload:
;/*	lea	-0x08(rbp),rbp	; 80404665 
	DB 0x48,0x8D,0x6D,0xF8
;/	mov    %rax,0x0(%rbp)
;/*	mov	rax,0x00(rbp)	; 80404669 
	DB 0x48,0x89,0x45,0x0
;/	mov	%r12, %rax
;/*	mov	rsp,rax	; 8040466D 
	DB 0x4A,0x89,0xE0
;/	NEXT
	ret		; 80404670 C3 
;/END-CODE
;/
;/CODE CDR
;/     	mov    -8(%rax),%rax


_CDR:
;/*	mov	-0x08(rax),rax	; 80404671 
	DB 0x48,0x8B,0x40,0xF8
;/	NEXT
	ret		; 80404675 C3 
;/END-CODE
;/
;/CODE NAME>C
;/	lea    -0x18(%rax),%rax


_NAMEgreatC:
;/*	lea	-0x18(rax),rax	; 80404676 
	DB 0x48,0x8D,0x40,0xE8
;/	NEXT
	ret		; 8040467A C3 
;/END-CODE
;/
;/CODE NAME>
;/	mov    -0x18(%rax),%rax


_NAMEgreat:
;/*	mov	-0x18(rax),rax	; 8040467B 
	DB 0x48,0x8B,0x40,0xE8
;/	NEXT
	ret		; 8040467F C3 
;/END-CODE
;/
;/CODE NAME>F
;/	lea    -0x10(%rax),%rax


_NAMEgreatF:
;/*	lea	-0x10(rax),rax	; 80404680 
	DB 0x48,0x8D,0x40,0xF0
;/	NEXT
	ret		; 80404684 C3 
;/END-CODE
;/
;/CODE ERASE ( addr len  -- )
;/	DUP,


_ERASE:
;/*	lea	-0x08(rbp),rbp	; 80404685 
	DB 0x48,0x8D,0x6D,0xF8
;/*	mov	rax,0x00(rbp)	; 80404689 
	DB 0x48,0x89,0x45,0x0
;/	MOV	$0,%rax
;/*	movq	$0x0,rax	; 8040468D 
	DB 0x48,0xC7,0xC0,0x0,0x0,0x0,0x0
;/CODL FILL ( addr len c -- )
;/	mov    0x0(%rbp),%rcx
_FILL:
;/*	mov	0x00(rbp),rcx	; 80404694 
	DB 0x48,0x8B,0x4D,0x0
;/	jrcxz  0f
	DB	0xE3	; 80404698 E3 
;/*	add	$0x48,al	; 80404699 
	DB 0x6,0x48
;/	mov    0x8(%rbp),%rdi
;/*	mov	0x08(rbp),edi	; 8040469B 
	DB 0x8B,0x7D,0x8
;/	rep stosb \ %al,%es:(%rdi)
	repz		; 8040469E F3 
	stosb		; 8040469F AA 
;/0:	mov    0x10(%rbp),%rax
;/*	mov	0x10(rbp),rax	; 804046A0 
	DB 0x48,0x8B,0x45,0x10
;/	lea    0x18(%rbp),%rbp
;/*	lea	0x18(rbp),rbp	; 804046A4 
	DB 0x48,0x8D,0x6D,0x18
;/	NEXT
	ret		; 804046A8 C3 
;/END-CODE
;/
;/CODE CCMOVE>
;/	mov    %rax,%rcx


_CCMOVEgreat:
;/*	mov	rax,rcx	; 804046A9 
	DB 0x48,0x89,0xC1
;/	mov    0x0(%rbp),%rdi
;/*	mov	0x00(rbp),rdi	; 804046AC 
	DB 0x48,0x8B,0x7D,0x0
;/	mov    0x8(%rbp),%rsi
;/*	mov	0x08(rbp),rsi	; 804046B0 
	DB 0x48,0x8B,0x75,0x8
;/	std    
stD	; 804046B4 FD 
;/	add    %rcx,%rdi
;/*	add	rcx,rdi	; 804046B5 
	DB 0x48,0x1,0xCF
;/	add    %rcx,%rsi
;/*	add	rcx,rsi	; 804046B8 
	DB 0x48,0x1,0xCE
;/	dec    %rsi
;/*	decq	rsi	; 804046BB 
	DB 0x48,0xFF,0xCE
;/	dec    %rdi
;/*	decq	rdi	; 804046BE 
	DB 0x48,0xFF,0xCF
;/	rep movsb \ %ds:(%rsi),%es:(%rdi)
	repz		; 804046C1 F3 
	movsb		; 804046C2 A4 
;/	cld    
clD	; 804046C3 FC 
;/	lea    0x18(%rbp),%rbp
;/*	lea	0x18(rbp),rbp	; 804046C4 
	DB 0x48,0x8D,0x6D,0x18
;/	mov    -0x8(%rbp),%rax
;/*	mov	-0x08(rbp),rax	; 804046C8 
	DB 0x48,0x8B,0x45,0xF8
;/	NEXT
	ret		; 804046CC C3 
;/END-CODE
;/
;/
;/CODE CMOVE 
;/	mov    %rax,%rcx


_CMOVE:
;/*	mov	rax,rcx	; 804046CD 
	DB 0x48,0x89,0xC1
;/	mov    0x0(%rbp),%rdi
;/*	mov	0x00(rbp),rdi	; 804046D0 
	DB 0x48,0x8B,0x7D,0x0
;/	mov    0x8(%rbp),%rsi
;/*	mov	0x08(rbp),rsi	; 804046D4 
	DB 0x48,0x8B,0x75,0x8
;/ 	cld    
clD	; 804046D8 FC 
;/	rep movsb \ %ds:(%rsi),%es:(%rdi)
	repz		; 804046D9 F3 
	movsb		; 804046DA A4 
;/	lea    0x18(%rbp),%rbp
;/*	lea	0x18(rbp),rbp	; 804046DB 
	DB 0x48,0x8D,0x6D,0x18
;/ 	mov    -0x8(%rbp),%rax
;/*	mov	-0x08(rbp),rax	; 804046DF 
	DB 0x48,0x8B,0x45,0xF8
;/	NEXT
	ret		; 804046E3 C3 
;/END-CODE
;/
;/CODE DOVALUE
;/	nop


_DOVALUE:
	nop		; 804046E4 90 
;/CODL DOCONSTANT
;/	lea    -0x8(%rbp),%rbp
_DOCONSTANT:
;/*	lea	-0x08(rbp),rbp	; 804046E5 
	DB 0x48,0x8D,0x6D,0xF8
;/	mov    %rax,0x0(%rbp)
;/*	mov	rax,0x00(rbp)	; 804046E9 
	DB 0x48,0x89,0x45,0x0
;/	pop    %rax
	pop	rax	; 804046ED 58 
;/	mov    (%rax),%rax
;/*	mov	(rax),rax	; 804046EE 
	DB 0x48,0x8B,0x0
;/	NEXT
	ret		; 804046F1 C3 
;/END-CODE
;/
;/CODE DOCREATE
;/	lea    -0x8(%rbp),%rbp


_DOCREATE:
;/*	lea	-0x08(rbp),rbp	; 804046F2 
	DB 0x48,0x8D,0x6D,0xF8
;/	mov    %rax,0x0(%rbp)
;/*	mov	rax,0x00(rbp)	; 804046F6 
	DB 0x48,0x89,0x45,0x0
;/	pop    %rax
	pop	rax	; 804046FA 58 
;/	NEXT
	ret		; 804046FB C3 
;/END-CODE
;/
;/CODE DOVECT
;/	pop    %rbx


_DOVECT:
	pop	rbx	; 804046FC 5B 
;/	mov    (%rbx),%rbx
;/*	mov	(rbx),rbx	; 804046FD 
	DB 0x48,0x8B,0x1B
;/	jmp	%rbx
;/*	jmp	*rbx	; 80404700 
	DB 0xFF,0xE3
;/END-CODE 
;/
;/CREATE &NOOP 'NOOP ,

	DQ 0x53+fimg
;/
;/CODE (?DO) (  limit index -- )
;/	cmp    0x0(%rbp),%rax	\ index = limit

_cbigqueDOcend:
;/*	cmp	0x00(rbp),rax	; 8040470A 
	DB 0x48,0x3B,0x45,0x0
;/	je     0f
	jz	_cbigDOcend+0x26 	; 8040470E 74 26 
;/CODL (DO) (  limit index -- )
;/	pop    %rdx		\ rdx = return address
_cbigDOcend:
	pop	rdx	; 80404710 5A 
;/	mov    (%rdx),%rcx	\ exit address
;/*	mov	(rdx),rcx	; 80404711 
	DB 0x48,0x8B,0xA
;/	lea    0x8(%rdx),%rdx	\ step over it
;/*	lea	0x08(rdx),rdx	; 80404714 
	DB 0x48,0x8D,0x52,0x8
;/	push   %rcx		\ rcx = exit address  
	Push	rcx	; 80404718 51 
;/	push   %r15		\ r15 = old index - limit - msb
	Push	r15	; 80404719 41 57 
;/	push   %r14		\ r14 = old index     
	Push	r14	; 8040471B 41 56 
;/
;/	mov    %rax,%r15	\ rbx = index, r15 = index                                     
;/*	mov	rax,r15	; 8040471D 
	DB 0x49,0x89,0xC7
;/	sub    0x0(%rbp),%r15	\ r15 = index - limit 
;/*	sub	0x00(rbp),r15	; 80404720 
	DB 0x4C,0x2B,0x7D,0x0
;/	btc    $0x3f,%r15	\ r15 = index - limit  - msb ; BTC=complement
;/*	btc	$0x3F,r15	; 80404724 
	DB 0x49,0xF,0xBA,0xFF,0x3F
;/	mov    %rax,%r14 	\ r14 = index
;/*	mov	rax,r14	; 80404729 
	DB 0x49,0x89,0xC6
;/
;/	mov    0x8(%rbp),%rax	\ restore TOS
;/*	mov	0x08(rbp),rax	; 8040472C 
	DB 0x48,0x8B,0x45,0x8
;/	lea    0x10(%rbp),%rbp	\ step data stack                               
;/*	lea	0x10(rbp),rbp	; 80404730 
	DB 0x48,0x8D,0x6D,0x10
;/
;/	jmp	%rdx
;/*	jmp	*rdx	; 80404734 
	DB 0xFF,0xE2
;/0:	mov    0x8(%rbp),%rax	\ restore TOS
;/*	mov	0x08(rbp),rax	; 80404736 
	DB 0x48,0x8B,0x45,0x8
;/	lea    0x10(%rbp),%rbp	\ step data stack
;/*	lea	0x10(rbp),rbp	; 8040473A 
	DB 0x48,0x8D,0x6D,0x10
;/	pop    %rdx		\ rdx = return address
	pop	rdx	; 8040473E 5A 
;/	mov    (%rdx),%rdx	\ exit address
;/*	mov	(rdx),rdx	; 8040473F 
	DB 0x48,0x8B,0x12
;/	jmp	%rdx
;/*	jmp	*rdx	; 80404742 
	DB 0xFF,0xE2
;/END-CODE
;/
;/' (?DO) TO '(?DO)
;/' (DO) TO '(DO)
;/
;/CODE LEAVE
;/\ RSP+18: ESP+C:  exit address
;/\ RSP+10: ESP+8:  old index-limit-$8000.0000  (incremented by LOOP)
;/\ RSP+08: ESP+4:  old index                   (incremented by LOOP)
;/\ RSP+00: return address
;/\ R15:    new index-limit-xorbit63
;/\ R14:    new index
;/        pop     %rdx	\ return address and discard it


_LEAVE:
	pop	rdx	; 80404744 5A 
;/        pop	%r14	\ index
	pop	r14	; 80404745 41 5E 
;/        pop	%r15	\ index-limit-xorbit63
	pop	r15	; 80404747 41 5F 
;/	NEXT
	ret		; 80404749 C3 
;/END-CODE
;/
;/
;/CODE UNLOOP
;/\ RSP+18: ESP+C:  exit address
;/\ RSP+10: ESP+8:  old index-limit-$8000.0000  (incremented by LOOP)
;/\ RSP+08: ESP+4:  old index                   (incremented by LOOP)
;/\ RSP+00: return address
;/\ R15:    new index-limit-xorbit63
;/\ R14:    new index
;/        pop     %rdx	\ return address and discard it


_UNLOOP:
	pop	rdx	; 8040474A 5A 
;/        pop	%r14	\ index
	pop	r14	; 8040474B 41 5E 
;/        pop	%r15	\ index-limit-xorbit63
	pop	r15	; 8040474D 41 5F 
;/	pop	%rcx
	pop	rcx	; 8040474F 59 
;/	jmp	%rdx
;/*	jmp	*rdx	; 80404750 
	DB 0xFF,0xE2
;/END-CODE
;/
;/
