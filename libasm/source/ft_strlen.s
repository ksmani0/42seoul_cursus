section .text
	global _ft_strlen ; Define the symbol as global so that the linker can access it

_ft_strlen:
	mov rax, 0 ; Since the return value is a string index, rax is used as the index. First initialize to 0
	jmp count ; jump to count label

count:
	cmp BYTE [rdi + rax], 0 ; Subtract the values of two arguments when comparing
	je end ; If the result of the above comparison operation is the same, move to the end label, otherwise ignore it.
	inc rax ; Add 1 to the rax value, which is the string index
	jmp count

end:
	ret ; Exit function and return rax value