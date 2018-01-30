	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_update_count
	.p2align	4, 0x90
_update_count:                          ## @update_count
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$2, -8(%rbp)
	jle	LBB0_3
## BB#1:
	cmpl	$7, -8(%rbp)
	jge	LBB0_3
## BB#2:
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB0_6
LBB0_3:
	cmpl	$10, -8(%rbp)
	jne	LBB0_5
## BB#4:
	movl	-4(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -4(%rbp)
LBB0_5:
	jmp	LBB0_6
LBB0_6:
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_count_cards
	.p2align	4, 0x90
_count_cards:                           ## @count_cards
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi5:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	leaq	L_.str(%rip), %rdi
	callq	_puts
	movq	-8(%rbp), %rsi
	leaq	L_.str.1(%rip), %rdi
	xorl	%ecx, %ecx
	movb	%cl, %dl
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movb	%dl, %al
	callq	_scanf
	movl	$0, -16(%rbp)
	movq	-8(%rbp), %rsi
	movsbl	(%rsi), %ecx
	addl	$-65, %ecx
	movl	%ecx, %esi
	subl	$23, %ecx
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	movq	%rsi, -32(%rbp)         ## 8-byte Spill
	movl	%ecx, -36(%rbp)         ## 4-byte Spill
	ja	LBB1_5
## BB#12:                               ##   in Loop: Header=BB1_1 Depth=1
	leaq	LJTI1_0(%rip), %rax
	movq	-32(%rbp), %rcx         ## 8-byte Reload
	movslq	(%rax,%rcx,4), %rdx
	addq	%rax, %rdx
	jmpq	*%rdx
LBB1_2:                                 ##   in Loop: Header=BB1_1 Depth=1
	movl	$10, -16(%rbp)
	jmp	LBB1_9
LBB1_3:                                 ##   in Loop: Header=BB1_1 Depth=1
	movl	$11, -16(%rbp)
	jmp	LBB1_9
LBB1_4:                                 ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_10
LBB1_5:                                 ##   in Loop: Header=BB1_1 Depth=1
	movq	-8(%rbp), %rdi
	callq	_atoi
	movl	%eax, -16(%rbp)
	cmpl	$1, -16(%rbp)
	jl	LBB1_7
## BB#6:                                ##   in Loop: Header=BB1_1 Depth=1
	cmpl	$10, -16(%rbp)
	jle	LBB1_8
LBB1_7:                                 ##   in Loop: Header=BB1_1 Depth=1
	leaq	L_.str.2(%rip), %rdi
	callq	_puts
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	jmp	LBB1_10
LBB1_8:                                 ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_9
LBB1_9:                                 ##   in Loop: Header=BB1_1 Depth=1
	movl	-12(%rbp), %edi
	movl	-16(%rbp), %esi
	callq	_update_count
	leaq	L_.str.3(%rip), %rdi
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -44(%rbp)         ## 4-byte Spill
LBB1_10:                                ##   in Loop: Header=BB1_1 Depth=1
	movq	-8(%rbp), %rax
	movsbl	(%rax), %ecx
	cmpl	$88, %ecx
	jne	LBB1_1
## BB#11:
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
	.p2align	2, 0x90
	.data_region jt32
L1_0_set_3 = LBB1_3-LJTI1_0
L1_0_set_5 = LBB1_5-LJTI1_0
L1_0_set_2 = LBB1_2-LJTI1_0
L1_0_set_4 = LBB1_4-LJTI1_0
LJTI1_0:
	.long	L1_0_set_3
	.long	L1_0_set_5
	.long	L1_0_set_5
	.long	L1_0_set_5
	.long	L1_0_set_5
	.long	L1_0_set_5
	.long	L1_0_set_5
	.long	L1_0_set_5
	.long	L1_0_set_5
	.long	L1_0_set_2
	.long	L1_0_set_2
	.long	L1_0_set_5
	.long	L1_0_set_5
	.long	L1_0_set_5
	.long	L1_0_set_5
	.long	L1_0_set_5
	.long	L1_0_set_2
	.long	L1_0_set_5
	.long	L1_0_set_5
	.long	L1_0_set_5
	.long	L1_0_set_5
	.long	L1_0_set_5
	.long	L1_0_set_5
	.long	L1_0_set_4
	.end_data_region

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi6:
	.cfi_def_cfa_offset 16
Lcfi7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi8:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	leaq	-7(%rbp), %rdi
	movl	$0, -4(%rbp)
	movl	$0, -12(%rbp)
	movl	-12(%rbp), %esi
	callq	_count_cards
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Enter the card_name: "

L_.str.1:                               ## @.str.1
	.asciz	"%2s"

L_.str.2:                               ## @.str.2
	.asciz	"I don't understand that value!"

L_.str.3:                               ## @.str.3
	.asciz	"Current count: %i\n"


.subsections_via_symbols
