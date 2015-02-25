#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

static unsigned long *esp;
void printprocstks(int priority)
{
	struct pentry *process;
	int i;
	kprintf("\n\nTask 4: printprocstks");
	kprintf("\nProcess_Id\tProcess_Name\tProcess_Prio\tStack_Base\tStack_Size\tStack_Limit\tStack_Pointer\n");
	for(i = 0; i < NPROC; i++)
	{
		process = &proctab[i];
		if(process -> pstate != PRFREE)
		{
			if(process -> pprio <= priority)
			{
				kprintf("%d\t\t",i);
				kprintf("%s\t\t",process->pname);
				kprintf("%d\t\t",process->pprio);
				kprintf("0x%08x\t\t",process->pbase);
				kprintf("%d\t\t",process->pstklen);
				kprintf("0x%08x\t\t",process->plimit);
				if(process->pstate == PRCURR)
				{
					asm("movl %esp, esp");
				}
				else esp = (unsigned long *)process->pesp;
				kprintf("0x%08x\n",esp);
			}
		}
	}
}
