section		.text
	global	_ft_isdigit

;rdi, rsi, rdx
_ft_isdigit:
	enter 0, 0

	cmp rdi, '0'
		jl False
	cmp rdi, '9'
		jg False

	mov rax, 1
	leave
	ret

False:
	mov rax, 0
	leave
	ret
