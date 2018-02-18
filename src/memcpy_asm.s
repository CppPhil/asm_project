.intel_syntax noprefix

.text
.globl memcpy_asm
.type memcpy_asm, @function
memcpy_asm:
    # rdi: dest
    # rsi: src
    # rdx: count

    mov rax, rdi           # load the return value into the output register

loop:
    test rdx, rdx          # if the count is zero
    je end                 # -> abort

    mov cl, BYTE PTR [rsi] # read a byte from *src into the lower 8 bits of the rcx register
    mov BYTE PTR [rdi], cl # store that byte into *dest
    inc rdi                # increment dest
    inc rsi                # increment src
    dec rdx                # decrement count
    jmp loop               # go back up

end:
    ret                    # return to the caller
