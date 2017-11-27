section		.text
	global	_ft_isascii

;rdi, rsi, rdx
_ft_isascii:
	enter 0, 0

	cmp rdi, 0
		jl False
	cmp rdi, 127
		jg False

	mov rax, 1
	leave
	ret

False:
	mov rax, 0
	leave
	ret
