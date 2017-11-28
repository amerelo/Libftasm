%define bufsize 4096

section		.text
	global	_ft_cat
	extern _read
	extern _write

;rdi, rsi, rdx
_ft_cat:
	enter 0, 0
	lea rsi, [rel buf]

Start:
	mov rdx, bufsize ; size
	call _read ; (fd, buf, size)
	cmp rax, 0 ; if read 0 end
		jle End

	mov r15, rdi ; save fd

	mov rdi, 1 ; fd
	mov rdx, rax ; size
	call _write ; (fd, str, size)

	mov rdi, r15 ; fd
	jmp Start

End:
	leave
	ret

section		.bss
	buf: resb 4096
