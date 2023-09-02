section .data
kH8V: db "Greetings!"


section .text
global _start
_start:
mov rdi, 1
mov rsi, kH8V
mov rdx, 10
mov rax, 1
syscall
mov rdi, 0
mov rax, 60
syscall