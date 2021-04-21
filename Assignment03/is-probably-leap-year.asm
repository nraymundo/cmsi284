        global main
        extern atoi
        extern printf
        extern puts

        section .text
main:
        push    rdi                                     ; Save registers
        push    rsi  

        cmp     rdi, 2                                  ; Check for 2 arguments
        jne     invalidArguments                        ; Jump to invalidArgs if != 2 args

        mov     rdi, [rsi + 8]                          ; Assign year to rdi
        call    atoi                                    ; Turn it into an integer
        cmp     eax, 00                                 ; Check to see if argument was a integer or not
        je     nonInt                                   ; Jump to nonInt if not an integer

        mov     ecx, 4                                  ; Assign divisor of 4 to ecx
        div     ecx                                     ; Divide

        pop     rsi                                     
        mov     rsi, [rsi + 8]
        xor     rax, rax

        cmp     edx, 00                                 ; Check for remainder
        jne     isNotLeapYear                           ; If there is a remainder, jump to isNotLeapYear

isLeapYear:
        mov     rdi, leapYear                           ; Assign message to rdi
        call    printf                                  ; Print statement
        jmp     done                                    ; Jump to done

isNotLeapYear:
        mov     rdi, notLeapYear
        call    printf                                  
        jmp     done                                    

nonInt:
        mov     rdi, nonIntMessage
        pop     rsi
        movsxd  rsi, eax
        xor     rax, rax
        call    printf
        jmp     done

invalidArguments:
        mov     rdi, invalidArgs
        pop     rsi                                     ; Clear rsi. Do it here bc done doesn't clear rsi.
        call    printf

done:
        pop     rdi                                     ; Clear register
        ret

invalidArgs:
        db "This program requires exactly one command line argument specifying a year.", 10, 0

leapYear:
        db "%s is probably a leap year.", 10, 0

notLeapYear: 
        db "%s is probably not a leap year", 10, 0

nonIntMessage:
        db "%d is probably a leap year.", 10, 0