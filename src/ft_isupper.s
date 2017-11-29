section	.text
global	_ft_isupper

_ft_isupper:
	push	rbp
	cmp		rdi, 'Z'
		jg	notup
	cmp		rdi , 'A'
		jl	notup

	up:
		mov	rax, 1
		pop	rbp
	ret

	notup:
		mov	rax, 0
		pop	rbp
	ret
