section		.text
	global	_ft_puts
	extern 	_write
	extern 	_ft_strlen

;rdi, rsi, rdx
_ft_puts:
	enter 0, 0

	push rdi
	call _ft_strlen
	cmp rax, 0
		je Error
	pop rdi

	mov rdx, rax
	mov rsi, rdi
	mov rdi, 1
	call _write

	mov rdx, 1
	mov rsi, msg
	mov rdi, 1
	call _write

	mov rax, 1
	leave
	ret


Error:
	mov rax, -1
	leave
	ret

section     .data
	msg     db  10
