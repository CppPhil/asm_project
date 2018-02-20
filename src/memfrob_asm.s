.intel_syntax noprefix

.text
.globl memfrob_asm
.type memfrob_asm, @function
memfrob_asm:
    # rdi: s
    # rsi: n

    mov rax, rdi           # copy pointer to the memory into the output register

loop:
    test rsi, rsi          # check if n is zero
    je end                 # if it is -> abort
    xor BYTE PTR [rdi], 42 # ^= the current byte with 42
    inc rdi                # increment the pointer
    dec rsi                # decrement n
    jmp loop               # go back up
    
end:
    ret                    # return back to the caller
