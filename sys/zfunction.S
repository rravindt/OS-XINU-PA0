	.text 
	.global zfunction
zfunction:
	pushl %ebp					#Saving EBP register content
	movl %esp,%ebp				#Moving ESP to EBP
	
	andl $0xfffff00f,8(%ebp)
	sall $8,8(%ebp)
	andl $0xffffff00,8(%ebp)
	movl 8(%ebp),%eax
	leave
	ret 
