section .text
	global _ft_read ; ssize_t read(int fd, void *buf, size_t nbyte)
	extern ___error

_ft_read:
	mov rax, 0x2000003 ; systemcall command to call read() in MAC OS
	syscall ; fd is automatically assigned to rdi, buf to rsi, and nbyte to rdx
	jc error
	ret

error:
	push rax
	call ___error
	pop rdx
	mov [rax], rdx
	mov rax, -1
	ret