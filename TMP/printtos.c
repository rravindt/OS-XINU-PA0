#include<stdio.h>

unsigned long	*esp;
unsigned long	*ebp;

void printtos()
{
	asm("movl %esp,esp");
	asm("movl %ebp,ebp");
	int count=0;

	kprintf("\nTask 3: printtos");
	kprintf("\nAddress of Top of Run-time stack Before getting into printtos ebp : 0x%08x",(ebp+2));
	kprintf("\nAddress of Top of Run-time stack After getting into printtos ebp : 0x%08x",(ebp));
		
	//In case there are any local variables, then ebp points to that last local variable added location and esp cannot go beyond that
	while(count<6 && ebp>esp)
	{
		kprintf("\nContent in stack at [0x%08x] is 0x%08x",(esp+count),*(esp+count));
		count++;
	}
}

