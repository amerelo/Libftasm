section		.text
	global	_ft_bzero

;rdi, rsi, rdx
_ft_bzero:
	enter 0, 0

	mov rcx, rsi
	mov rax, 0
	rep stosb ; put rax val in rdi

	leave
	ret
