	.file	"switch.c"
	.section	.rodata
.LC0:
	.string	"Excellent!\n"
.LC1:
	.string	"Well done\n"
.LC2:
	.string	"You passed\n"
.LC3:
	.string	"Better try again\n"
.LC4:
	.string	"Invalid grade\n"
.LC5:
	.string	"Your grade is  %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$90, -4(%rbp)
	movl	-4(%rbp), %eax
	cmpl	$80, %eax
	je	.L3
	cmpl	$80, %eax
	jg	.L4
	cmpl	$40, %eax
	je	.L5
	cmpl	$60, %eax
	je	.L6
	jmp	.L2
.L4:
	cmpl	$90, %eax
	je	.L7
	cmpl	$100, %eax
	jne	.L2
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	jmp	.L9
.L7:
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	jmp	.L9
.L3:
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	jmp	.L9
.L6:
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	jmp	.L9
.L5:
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	jmp	.L9
.L2:
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
.L9:
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-28)"
	.section	.note.GNU-stack,"",@progbits
