section		.text
	global	_ft_toupper

;rdi, rsi, rdx
_ft_toupper:
	enter 0, 0

	cmp rdi, 'a'
		jl false
	cmp rdi, 'z'
		jg false

	sub rdi, 32
	mov rax, rdi

	leave
	ret

false:
	mov rax, rdi
	leave
	ret
