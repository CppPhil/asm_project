.intel_syntax noprefix

.text
.globl memcmp_asm
.type memcmp_asm, @function
memcmp_asm:
    # rdi: lhs
    # rsi: rhs
    # rdx: count

    xor eax, eax           # zero out the output register

loop:
    test rdx, rdx          # if the count is zero
    je end                 # then -> abort

    mov cl, BYTE PTR [rdi] # load the current byte from lhs
    cmp cl, BYTE PTR [rsi] # compare the current byte from lhs to the one from rhs
    jb less                # if *lhs < *rhs -> abort with negative value
    ja greater             # if *lhs > *rhs -> abort with positive value

    inc rdi                # increment lhs
    inc rsi                # increment rhs
    dec rdx                # decrement count            
    jmp loop               # go back up

less:
    not eax                # toggle the bits, so that all bits are set, representing -1
    jmp end                # return

greater:
    mov eax, 1             # set the return value to 1

end:
    ret                    # return
