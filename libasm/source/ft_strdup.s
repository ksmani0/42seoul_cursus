section .text
	global _ft_strdup ; char *strdup(const char *src)
	extern _ft_strlen
	extern _malloc
	extern _ft_strcpy

_ft_strdup:
	call _ft_strlen ; rax = length of string
	inc rax ; add 1 for null character
	push rdi ; rdi = src address containing the content to be copied
	mov rdi, rax ; Passing the number of bytes to be allocated dynamically
	call _malloc
	cmp rax, 0 ; If the return value is 0, dynamic allocation has failed
	jz error ; If the operation result is 0, the zero flag is set to 1
	pop rsi ; 할당에 성공하면 스택에 저장돼있는 s1 주소를 rsi 대입
	mov rdi, rax ; Assign the assigned address to rdi
	call _ft_strcpy ; rdi is parameter 1, rsi is parameter 2
	ret ; Returns rax with all contents copied

error:
	ret ; Returns rax containing null points