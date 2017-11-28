section		.text
	global	_ft_strcat
	extern _ft_strcpy

;rdi, rsi, rdx
_ft_strcat:
	enter 0, 0
	push rdi
	push rsi

	mov rcx, -1
	mov rax, 0
	repnz scasb
	dec rdi

	call _ft_strcpy

	pop rsi
	pop rax
	leave
	ret
