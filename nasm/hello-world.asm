; define variables
section .data
  hello: db 'Hello world', 10
  size: equ $-hello

; define code
section .text
    global _start

; this is a label
_start:
  
  mov rax, 1 ; write
  mov rdi, 1 ; file descriptor: output
  mov rsi, hello ; const char * buffer
  mov rdx, size ; size_t count
  syscall ; do operation
  
  mov rax, 60 ; exit
  xor rdi, rdi ; error code 0
  syscall
