        extern  printf
        global  gcd                     ; uint64_t gcd(uint64_t x, uint64_t y)

        section .text
gcd:
        xor     rax, rax
        push    r12                     ; push r12 register

        cmp     rsi, 0                  ; compare y to 0
        jne     notEqual                ; if not =, jump to notEqual

equal:
        mov     rax, rdi                ; assign x to return register
        pop     r12                     ; pop r12
        ret                             ; return

notEqual:
        mov     r12, rdi                ; use r12 to hold value for x

        mov     rdi, rsi                ; move y into register for x
        mov     rdx, 0                  ; clear rdx register
        mov     rax, r12                ; move original x value to the dividend
        mov     rcx, rdi                ; move original y value to the divisor
        div     rcx                     ; divide

        pop     r12                     ; clear r12 register

        mov     rsi, rdx                ; assign remainder to register for x
        call    gcd                     ; loop back to gcd
        ret                             ; return