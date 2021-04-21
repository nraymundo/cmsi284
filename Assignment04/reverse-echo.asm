	global	main
	extern	puts
	extern	strlen
	extern	reverse_range_in_place  	; Look ma, no .h

	section	.text
main:
	push	r12							; push r12 register
	push	r13							; push r13 register

	mov		r12, rsi					; assign rdi to r12 register
	mov		r13, rdi					; assign rdi to r13 register

loop:
	mov		rdi, [r12]					; assign index of r12 to rdi
	call	strlen						; find string length

	mov		rdi, [r12]					; first parameter of function is [r12]
	mov		rsi, 0						; second parameter is 0				
	mov		rdx, rax					; third parameter is rax (strlen)
	call	reverse_range_in_place		; call function

	mov		rdi, [r12]					; reassign new reversed word to rdi
	call	puts						; print word

	add		r12, 8						; add 8 to r12 to increment index
	dec		r13							; decrement r13 to count numOfWords left
	jnz		loop						; if r13 > 0, redo loop

done:
	pop		r12							; pop r12 register
	pop		r13							; pop r13 register

    ret									; return
