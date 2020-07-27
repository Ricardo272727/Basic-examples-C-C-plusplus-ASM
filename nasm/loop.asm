

section .data
  message db 'NASM course', 10
  size equ $-message
section .text
  global _start

_start:
 
  mov rcx, 0 ; counter
  mov rsi, message ; load the string
  mov rdx, size ; load the size of string

  iterate:
    call print_string ; print the loaded string
    inc rcx
    cmp rcx, 10
    jne iterate
  end_iterate:

  mov rax, 60 ; exit
  xor rdi, rdi ; return 0
  syscall

; rsi has the string, rdx has the size
print_string:
  push rcx
  mov rax, 1 ; write
  mov rdi, 1 ; fd = 1
  syscall 
  pop rcx
  ret


