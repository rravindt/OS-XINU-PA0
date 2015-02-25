#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

void syscallsummary_start()
{
	struct pentry *proc;
	int i;
	for(i = 0; i < NPROC; i++)
	{
		proc = &proctab[i];
		proc -> systemCallCount = 0;
	}
	trace_flag = TRUE;
}

void syscallsummary_stop()
{
	trace_flag = FALSE;
}


void printsyscalls()
{	
	struct pentry *proc;
	int i,j;
	int count[6]={0,0,0,0,0,0};
	for(i = 0; i < NPROC; i++)
	{
		proc = &proctab[i];
		if(proc -> systemCallCount != 0)
		{
			kprintf("\nSystem Calls In process %s :\n", proc->pname);
			for(j = 0; j < proc -> systemCallCount; j++)
			{
				switch(proc -> systemCallTab[j])	
				{
					case 1: count[0]++;
							break;
					case 2: count[1]++;
							break;
					case 3: count[2]++;
							break;
					case 4: count[3]++;
							break;
					case 5: count[4]++;
							break;
					case 6: count[5]++;
							break;
				}
			}
			for (j=0; j < 6 ; j++){
				if(count[j] == 0){
					continue;
				}
				switch(j){
					case 0: kprintf("%d times getpid was called \n", count[0]); break;
					case 1: kprintf("%d times gettime was called \n", count[1]); break;
					case 2: kprintf("%d times kill was called \n", count[2]); break;
					case 3: kprintf("%d times signal was called \n", count[3]); break;
					case 4: kprintf("%d times sleep was called \n", count[4]); break;
					case 5: kprintf("%d times wait was called \n", count[5]); break;
				}
				count[j]=0;
			}
		}
		//Check for next process.
	}
}
