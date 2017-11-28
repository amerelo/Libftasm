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

	mov rax, 1
	leave
	ret

isalpha:
	call _ft_isalpha
	cmp rax, 0
		je False

	mov rax, 1
	leave
	ret


False:
	mov rax, 0
	leave
	ret
