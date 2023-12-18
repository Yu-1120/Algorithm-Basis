	.file	"demo.c"
	.text
	.section	.rodata
.LC0:
	.string	"Even"
.LC1:
	.string	"Jacy"
.LC3:
	.string	"CuiHua"
	.align 8
.LC4:
	.string	"\345\275\223\345\211\215\350\276\223\345\207\272\344\270\272\346\270\205\346\264\201\345\267\245\357\274\232\n \345\220\215\345\255\227\357\274\232%s\t\344\272\272\347\214\277\347\261\273\345\236\213:%c\t\346\270\205\346\264\201\350\203\275\345\212\233\357\274\232%c\n"
	.align 8
.LC5:
	.string	"\345\275\223\345\211\215\350\276\223\345\207\272\344\270\272\345\255\246\347\224\237\357\274\232\n \345\220\215\345\255\227\357\274\232%s\t\344\272\272\347\214\277\347\261\273\345\236\213:%c\t\345\255\246\344\271\240\350\203\275\345\212\233\357\274\232%f\n"
	.align 8
.LC6:
	.string	"\345\275\223\345\211\215\350\276\223\345\207\272\344\270\272\346\211\223\351\245\255\351\230\277\345\247\250\357\274\232\n \345\220\215\345\255\227\357\274\232%s\t\344\272\272\347\214\277\347\261\273\345\236\213:%c\t\346\212\226\350\202\211\350\203\275\345\212\233\357\274\232%d\n"
.LC7:
	.string	"demo.c"
.LC8:
	.string	"%s,%s,%d\n"
.LC9:
	.string	"Hello.c"
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
	subq	$160, %rsp
	movl	%edi, -148(%rbp)
	movq	%rsi, -160(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-128(%rbp), %rax
	movl	$32, %edx
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	call	strncpy@PLT
	movb	$81, -96(%rbp)
	movb	$65, -92(%rbp)
	leaq	-128(%rbp), %rax
	addq	$40, %rax
	movl	$32, %edx
	leaq	.LC1(%rip), %rsi
	movq	%rax, %rdi
	call	strncpy@PLT
	movb	$83, -56(%rbp)
	movss	.LC2(%rip), %xmm0
	movss	%xmm0, -52(%rbp)
	leaq	-128(%rbp), %rax
	addq	$80, %rax
	movl	$32, %edx
	leaq	.LC3(%rip), %rsi
	movq	%rax, %rdi
	call	strncpy@PLT
	movb	$70, -16(%rbp)
	movl	$13, -12(%rbp)
	movq	$0, -136(%rbp)
	jmp	.L2
.L7:
	movq	-136(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	leaq	-128(%rbp), %rax
	addq	%rdx, %rax
	movzbl	32(%rax), %eax
	movsbl	%al, %eax
	cmpl	$81, %eax
	je	.L4
	cmpl	$83, %eax
	je	.L5
	cmpl	$70, %eax
	je	.L6
	jmp	.L3
.L4:
	movq	-136(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	leaq	-128(%rbp), %rax
	addq	%rdx, %rax
	movzbl	36(%rax), %eax
	movsbl	%al, %ecx
	movq	-136(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	leaq	-128(%rbp), %rax
	addq	%rdx, %rax
	movzbl	32(%rax), %eax
	movsbl	%al, %esi
	movq	-136(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	leaq	-128(%rbp), %rax
	addq	%rdx, %rax
	movl	%esi, %edx
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L3
.L5:
	movq	-136(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	leaq	-128(%rbp), %rax
	addq	%rdx, %rax
	movss	36(%rax), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movq	-136(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	leaq	-128(%rbp), %rax
	addq	%rdx, %rax
	movzbl	32(%rax), %eax
	movsbl	%al, %ecx
	movq	-136(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	leaq	-128(%rbp), %rax
	addq	%rdx, %rax
	movl	%ecx, %edx
	movq	%rax, %rsi
	leaq	.LC5(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	jmp	.L3
.L6:
	movq	-136(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	leaq	-128(%rbp), %rax
	addq	%rdx, %rax
	movl	36(%rax), %ecx
	movq	-136(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	leaq	-128(%rbp), %rax
	addq	%rdx, %rax
	movzbl	32(%rax), %eax
	movsbl	%al, %esi
	movq	-136(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	leaq	-128(%rbp), %rax
	addq	%rdx, %rax
	movl	%esi, %edx
	movq	%rax, %rsi
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
.L3:
	addq	$1, -136(%rbp)
.L2:
	cmpq	$2, -136(%rbp)
	jbe	.L7
	movl	$61, %ecx
	leaq	__FUNCTION__.2449(%rip), %rdx
	leaq	.LC7(%rip), %rsi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$998, %ecx
	leaq	__FUNCTION__.2449(%rip), %rdx
	leaq	.LC9(%rip), %rsi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdi
	xorq	%fs:40, %rdi
	je	.L9
	call	__stack_chk_fail@PLT
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.type	__FUNCTION__.2449, @object
	.size	__FUNCTION__.2449, 5
__FUNCTION__.2449:
	.string	"main"
	.align 4
.LC2:
	.long	1096663695
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
