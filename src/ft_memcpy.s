section		.text
	global	_ft_memcpy

;rdi, rsi, rdx
_ft_memcpy:
	enter 0, 0

	push rdi
	push rsi
	mov rcx, rdx
	rep movsb ; mov rsi to rdi

	pop rsi
	pop rax
	leave
	ret
