.intel_syntax noprefix

.text
.globl strlen_asm
.type strlen_asm, @function
strlen_asm:
    # rdi: str

    xor rax, rax            # zero out the output register

loop:
    cmp BYTE PTR [rdi], 0   # check if the current char is '\0'
    je end                  # if it is -> abort
    inc rdi                 # increment the pointer
    inc rax                 # increment the count
    jmp loop                # go back up

end:
    ret                     # return back to the caller
