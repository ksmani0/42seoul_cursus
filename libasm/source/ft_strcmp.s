section .text
	global _ft_strcmp ; int ft_strcmp(const char *s1, const char *s2)

_ft_strcmp:
	xor rcx, rcx ; rdi = s1, rsi = s2
	jmp compare

compare:
	mov al, BYTE [rdi + rcx] ; Assign the current character value of rdi string to al
	mov dl, BYTE [rsi + rcx] ; dl means the lower 8 bits of rdx
	cmp al, 0 ; If any one of the two strings encounters a null character,
	je rdi_null
	cmp dl, 0 ; it moves to the label to check the order of the characters.
	je rsi_null
	cmp al, dl
	jne end ; If the values of al and dl are different, move to end
	inc rcx
	jmp compare

rdi_null:
	cmp dl, 0 ; Since the character of rdi is null, the order of the two strings is determined
	je null_equal ; according to the character value of rsi.
	jmp end ; The character value of rsi can be 0 or 1 or more. 1 or more means rdi is first in alphabetical order.

rsi_null:
	cmp al, 0 ; check the character of rdi is null
	je null_equal
	jmp end

null_equal:
	mov rax, 0
	ret

end:
	movzx rax, al ; move with zero-extended
	movzx rbx, dl
	sub rax, rbx ; Returns the current character values of rdi and rsi minus
	ret