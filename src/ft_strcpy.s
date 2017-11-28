section		.text
	global	_ft_strcpy
	extern _ft_strlen
	extern _ft_memcpy

;rdi, rsi, rdx
_ft_strcpy:
	enter 0, 0
	push rdi
	push rsi

	mov r12, rdi
	mov rdi, rsi
	call _ft_strlen

	mov rsi, rdi
	mov rdi, r12
	mov rdx, rax
	inc rdx
	call _ft_memcpy

	pop rsi
	pop rdi

	leave
	ret
