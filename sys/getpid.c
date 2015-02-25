/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
SYSCALL getpid()
{
	if(trace_flag){
		struct pentry *proc = &proctab[currpid];
		proc->systemCallTab[proc->systemCallCount]=1;
		proc->systemCallCount++;		

	}
	return(currpid);
}
