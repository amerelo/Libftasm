section		.text
	global	_ft_strnew
	extern _malloc

;rdi, rsi, rdx
_ft_strnew:
	enter 0, 0

	inc     rdi
	call _malloc
	cmp rax, 0
		je Error

	inc		rdi
	mov 	r12, 0
	mov		rcx, 0
	jmp 	Zero

For:
	mov [rax + rcx], r12
	inc rcx

Zero:
	cmp rcx, rdi
		je For
	leave
	ret

Error:
	mov rax, 0
	leave
	ret
