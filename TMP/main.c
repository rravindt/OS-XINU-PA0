
#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */

 
int main()
{
	kprintf("\n\nHello World, Xinu lives\n\n");		//Successful bootup of XINU
	long input = 2864434397; 						//0xaabbccdd
	kprintf("\nThe input is %x",input);
	long output=zfunction(input);
	kprintf("\nThe output is %x\n",output);		//0xbbc00d00
	printsegaddress();								//prints text,data and BSS segments.
	kprintf("\n");
	printtos();										//prints top of run-time stack before and after calling this function.
	printprocstks(25);								//prints stack base, stack size, stack limit and stack pointer of processes with priority less than parameter 'priority'
	printsyscalls();								//prints system calls invoked after tracing has begun, here it is none.
	int prA();
	int prB();
	syscallsummary_start();
	resume(create(prA, 200, 25, "ProcA", 1, 1));	//when process A and B exits, kill and getpid system calls are called
	resume(create(prB, 200, 25, "ProcB", 1, 1));
	syscallsummary_stop();
	printsyscalls();								//prints signal and sleep once, as they are called only once in function prB.
	syscallsummary_start();
	sleep(1);
	sleep(1);
	sleep(1);
	getpid();
	getpid();
	kill(48);
	syscallsummary_stop();
	printsyscalls();								//prints sleep thrice, getpid twice and kill once
	return 0;
}

prB(int a)
{
	signal(1);
	sleep(1);
}

prA(int a){
	sleep(1);
}

