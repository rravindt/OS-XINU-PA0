/* gettime.c - gettime */

#include <conf.h>
#include <kernel.h>
#include <date.h>
#include <proc.h>
#include <lab0.h>
extern int getutim(unsigned long *);

/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */
SYSCALL	gettime(long *timvar)
{
    /* long	now; */

	/* FIXME -- no getutim */
	if(trace_flag)
	{
		struct pentry *proc = &proctab[currpid];
		proc -> systemCallTab [proc -> systemCallCount] = 2;
		proc -> systemCallCount ++;
	}
    return OK;
}
