section		.text
	global	_ft_isprint

;rdi, rsi, rdx
_ft_isprint:
	enter 0, 0

	cmp rdi, '~'
		jl False
	cmp rdi, ' '
		jg False

	mov rax, 1
	leave
	ret

False:
	mov rax, 0
	leave
	ret
