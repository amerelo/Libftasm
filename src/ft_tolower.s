section		.text
	global	_ft_tolower

;rdi, rsi, rdx
_ft_tolower:
	enter 0, 0

	cmp rdi, 'A'
		jl false
	cmp rdi, 'Z'
		jg false

	add rdi, 32
	mov rax, rdi

	leave
	ret

false:
	mov rax, rdi
	leave
	ret
