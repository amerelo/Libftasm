section		.text
	global	_ft_memset

;rdi, rsi, rdx
_ft_memset:
	enter 0, 0

	push rdi
	mov rcx, rdx
	mov rax, rsi
	rep stosb ; put rax val in rdi

	pop rdi
	mov rax, rdi
	leave
	ret
