section		.text
	global	_ft_strdup
	extern _ft_strlen
	extern _ft_memcpy
	extern _ft_strcpy
	extern _malloc

;rdi, rsi, rdx
_ft_strdup:
	push rdi
	call _ft_strlen

	inc rax
	mov rdi, rax

	call _malloc
	cmp rax, 0
		je Error

	pop rsi
	mov rdi, rax
	call _ft_strcpy
	ret

Error:
	mov rax, 0
	ret
