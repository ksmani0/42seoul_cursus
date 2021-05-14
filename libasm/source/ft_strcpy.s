section .text
	global _ft_strcpy ; char *ft_strcpy(char *dest, const char *src)

_ft_strcpy:
	xor rcx, rcx ; Initialize rcx value to 0 using logical operator xor
	jmp copy

copy:
	mov al, BYTE [rsi + rcx] ; If it is not 0, the value of rsi is moved to al. al means the lower 8 bits
	mov BYTE [rdi + rcx], al ; The string address to which rsi contents will be copied is put in rdi. Pass the value of al to rdi
	cmp BYTE [rsi + rcx], 0 ; The string address containing the content to be copied is contained in rsi. Move index until rsi value is 0 
	je end
	inc rcx
	jmp copy

end:
	mov rax, rdi ; The address value of rdi is assigned to the return value
	ret