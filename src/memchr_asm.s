.intel_syntax noprefix

.text
.globl memchr_asm
.type memchr_asm, @function
memchr_asm:
    # rdi: ptr
    # esi: ch
    # rdx: count
    
loop:
    test rdx, rdx             # if there are 0 bytes left
    je not_found              # -> exit with failure
    
    movzx ecx, BYTE PTR [rdi] # load the current char into ecx, zero extending
    cmp ecx, esi              # if it is the char we're looking for
    je found                  # exit indicating success
    
    inc rdi                   # increment the pointer
    dec rdx                   # decrement the count
    jmp loop                  # go back up
    
found:
    mov rax, rdi              # load the current pointer into the output register
    ret                       # return
    
not_found:
    xor rax, rax              # zero out the output register
    ret                       # return

