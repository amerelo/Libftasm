section		.text
	global	_ft_strdup
	extern _ft_strlen
	extern _ft_memcpy
	extern _ft_strcpy
	extern _malloc

;rdi, rsi, rdx
_ft_strdup:
	enter 0, 0

	call _ft_strlen

	mov r12, rdi
	mov rdi, rax
	call _malloc
	cmp rax, 0
		je Error

	mov rsi, r12
	mov rdi, rax
	call _ft_strcpy

	leave
	ret

Error:
	mov rax, 0
	leave
	ret
