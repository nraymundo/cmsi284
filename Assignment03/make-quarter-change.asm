        global main
        extern atoi
        extern printf
        extern puts

        section .text
main:
        push    rdi                                     ; Save registers
        push    rdx  
        push    rsi  

        cmp     rdi, 2                                  ; Check for 2 arguments
        jne     invalidArguments                        ; Jump to invalidArgs if != 2 args

        mov     rdi, [rsi + 8]                          ; Assign cents amount to rdi
        call    atoi                                    ; Turn it into an integer
        cmp     eax, 0                                  ; Check to see if argument was a integer or not
        jne     makeChange                              ; Jump to nonInt if not an integer

nonInt:
        mov     rdi, nonIntMessage                      ; Assign message to rdi
        pop     rsi                                     ; Pop rsi to get original value
        movsxd  rsi, eax                                ; Assign 0 to first %d
        movsxd  rdx, eax                                ; Assign 0 to second %d
        xor     rax, rax
        call    printf                                  ; Print statement
        jne     done                                    ; Jump to done

makeChange:
        mov     ecx, 25                                 ; Assign divisor to 25
        div     ecx                                     ; Divide
        mov     rdi, message                            
        pop     rsi
        mov     rdx, [rsi + 8]                          ; Assign number of cents to second %s
        movsxd  rsi, eax                                ; Assign quotient to first %d
        xor     rax, rax
        call    printf                                  ; Print statement
        jne     done                                    ; Jump to done

invalidArguments:
        mov     rdi, invalidArgs
        call    printf                                  ; Print statement
        pop     rsi                                     ; Clear rsi. Do it here bc done doesn't clear rsi.

done:
        pop     rdx                                     ; Clear registers
        pop     rdi

        ret                                             ; Return

invalidArgs:
        db "This program requires exactly one integer command line argument.", 10, 0

nonIntMessage:
        db "%d quarters make partial change for %d cents.", 10, 0

message: 
        db "%d quarters make partial change for %s cents.", 10, 0


