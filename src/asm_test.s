.intel_syntax noprefix

.text
.globl multiply_x64
.type multiply_x64, @function
multiply_x64:
    push rbp
    mov rbp, rsp
    
    mov eax, edi
    imul eax, esi
    
    mov rsp, rbp
    pop rbp
    ret

