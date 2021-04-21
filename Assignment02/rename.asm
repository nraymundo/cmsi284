            extern      printf
            global      main

            section     .text
main:      
            cmp         rdi, 3                  ; check for 2 arguments
            jne         invalidArguments        ; jump to invalidArgs if != 2 args
            
            mov         rdi, [rsi + 8]          ; access path to new file name
            mov         rsi, [rsi + 16]         ; access path to old file name
            mov         rax, 82
            syscall
            cmp         rax, 0                  ; check to see if file paths are valid
            jne         invalidArguments        ; if file paths are invalid, jump to invalidArgs
            ret

invalidArguments:
            mov         rdi, invalidArgs        ; assign message to rdi        
            xor         rax, rax
            call        printf                  ; print statement
            ret

invalidArgs:
        db "This program requires exactly two command line arguments representing the old and new file paths.", 10, 0