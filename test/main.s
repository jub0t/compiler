section .data
  Message: db "Started!", 0x0A

section .text
  global _start

_start:
  mov rcx, 0
  mov rdi, Message
  call get_length
  
  .loop:
    mov rsi, Message
    call print

  .done:
    mov rdi, 0
    mov rax, 60
    syscall

open_file:
  mov rsi, 1
  mov rdx, 1
  mov rax, 2 ; open file
  syscall
  ret

print:
  mov rdi, 1
  mov rdx, rax
  mov rax, 1
  syscall
  ret

get_length:
  .loop:
    mov al, byte [rdi]
    cmp al, 0
    jz .done
    
    inc rdi
    inc rcx
    jmp .loop
  .done:
    mov rax, rcx
    ret
