section		.text
	global	_ft_isalpha

;rdi, rsi, rdx
_ft_isalpha:
	enter 0, 0

	cmp rdi, 'A'
		jl is_false
	cmp rdi, 'z'
		jg is_false

	jmp is_between


is_false:
	mov rax, 0
	leave
	ret

is_between:
	cmp rdi, 91
		jl is_true

	cmp rdi, 96
	jg is_true
	jmp is_false


is_true:
	mov rax, 1
	leave
	ret
