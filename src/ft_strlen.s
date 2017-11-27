section		.text
	global	_ft_strlen

;rdi, rsi, rdx
_ft_strlen:
	enter 0, 0

	push rdi

	mov rcx, -1
	mov rax, 0
	repnz scasb
	mov rax, rcx
	not rax ; Flip the bits
	dec rax

	pop rdi
	leave
	ret
