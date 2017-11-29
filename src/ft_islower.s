section	.text
global	_ft_islower

_ft_islower:
	push	rbp
	cmp		rdi, 'z'
		jg	notlow
	cmp		rdi , 'a'
		jl	notlow

	low:
		mov	rax, 1
		pop	rbp
	ret

	notlow:
		mov	rax, 0
		pop	rbp
	ret
