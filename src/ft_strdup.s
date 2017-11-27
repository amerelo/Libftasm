section		.text
	global	_ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_memcpy

;rdi, rsi, rdx
_ft_strdup:
	enter 0, 0

	call _ft_strlen
	cmp rax, 0
		je Error

	mov r12, rdi
	mov rdi, rax
	call _malloc
	cmp rax, 0
		je Error

	mov rdx, rdi
	mov rsi, r12
	mov rdi, rax
	call _ft_memcpy

	leave
	ret

Error:
	mov rax, 0
	leave
	ret
