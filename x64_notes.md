# x64 Assembly notes

+ System V Application Binary Interface
AMD64 Architecture Processor Supplement: https://www.uclibc.org/docs/psABI-x86_64.pdf  

## Prologue and epilogue
### Prologue
The typical function prologue looks like:  
`push rbp`  
`mov rbp, rsp`  
The old frame pointer is saved onto the stack.  
Then the current stack pointer is loaded into the base pointer,  
serving as a fixed reference point of the call frame as the stack pointer is decremented as the stack grows.  

### Epilogue
The typical function epilogue looks like:  
`pop rbp`  
`ret`  
The old frame pointer is restored.  
Then the return instruction pointer is popped from the top of the stack into the rip register

## C calling convention on Linux
### volatile registers (caller saved registers)
These registers may be left in a modified state by a function implemented in x64 Assembly.  
If the values of these registers shall be preserved then the caller is responsible for saving and restoring them.  

+ rax  
+ rcx  
+ rdx  
+ rsi  
+ rdi  
+ r8  
+ r9  
+ r10  
+ r11  

### stable registers (callee saved registers)
These registers must be restored to their original values when a function implemented in x64 Assembly returns.  
The callee is responsible for saving and restoring them.  

+ rbx  
+ rsp  
+ rbp  
+ r12  
+ r13  
+ r14  
+ r15  

### special registers
+ 1st return register: rax  
+ 2nd return register: rdx  
+ frame pointer: rbp  
+ stack pointer: rsp  

### argument passing
+ 1st argument: rdi  
+ 2nd argument: rsi  
+ 3rd argument: rdx  
+ 4th argument: rcx  
+ 5th argument: r8  
+ 6th argument: r9  

Additional arguments are passed by pushing them onto the stack in reverse order.  
So the first argument on the stack is at address rbp + 16, assuming the function prologue has been run.  
The caller is responsible for removing all the arguments that were pushed onto the stack.  
