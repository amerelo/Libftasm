section		.text
	global	_ft_strnew
	extern _malloc
	extern _ft_bzero

;rdi, rsi, rdx
_ft_strnew:
	enter 0, 0

	inc     rdi
	call _malloc
	cmp rax, 0
		je Error

	mov     rsi,  rdi
	mov     rdi,  rax
	call    _ft_bzero

	leave
	ret

Error:
	mov rax, 0
	leave
	ret
