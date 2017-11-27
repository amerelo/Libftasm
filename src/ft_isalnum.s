section		.text
	global	_ft_isalnum
	extern	_ft_isalpha
	extern	_ft_isdigit

;rdi, rsi, rdx
_ft_isalnum:
	enter 0, 0

	call _ft_isdigit
	cmp rax, 0
		je isalpha

	jmp True


isalpha:
	call _ft_isalpha
	cmp rax, 0
		je False

	jmp True


True:
	mov rax, 1
	leave
	ret

False:
	leave
	ret
