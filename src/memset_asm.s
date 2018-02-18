.intel_syntax noprefix

.text
.globl memset_asm
.type memset_asm, @function
memset_asm:
    # rdi: dest
    # esi: ch 
    # rdx: count

    mov rax, rdi            # load the return value into the output register

loop:
    test rdx, rdx           # test if the count is zero
    je end                  # if it is -> abort

    mov BYTE PTR [rdi], sil # store the lower 8 bits of ch into *dest 
    inc rdi                 # increment dest
    dec rdx                 # decrement count
    jmp loop                # go back up

end:
    ret
