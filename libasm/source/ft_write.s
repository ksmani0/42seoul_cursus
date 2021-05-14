section .text
	global _ft_write ; ssize_t write(int fd, const void *buf, size_t nbyte)
	extern ___error ; syscall error should be handled with ___error function

_ft_write:
	mov rax, 0x2000004 ; systemcall command to call write() in MAC OS
	syscall ; fd is automatically assigned to rdi, buf to rsi, and nbyte to rdx
	jc error ; When an error occurs, the carry flag is set to 1
	ret ; If no error occurs, rax is returned. rax contains the number of bytes printed

error:
	push rax ; When an error occurs, rax contains an error value. Back up this value to the stack once
	call ___error ; When calling the ___error function, the error address value is stored in rax
	pop rdx ; The error value that was backed up on the stack is transferred to rdx
	mov [rax], rdx ; Square brackets are used to put the error value contained in rdx into rax without changing the address
	mov rax, -1 ; When an error occurs, -1 should be returned, so -1 is substituted for rax
	ret