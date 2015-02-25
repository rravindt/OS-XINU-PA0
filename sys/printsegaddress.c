#include <stdio.h>
extern long etext, edata, end;

void printsegaddress()
{
	kprintf("\nTask 2: printsegaddress\n");
	kprintf("Address indicating end of text segment 0x%08x\n", &etext);
	kprintf("Address indicating end of data segment 0x%08x\n", &edata);
	kprintf("Address indicating end of BSS segment  0x%08x\n", &end);
	kprintf("Hexadecimal contents preceding end of text segment 0x%08x\n", *(&etext -1));
	kprintf("Hexadecimal contents after end of text segment 0x%08x\n", *(&etext +1));
	kprintf("Hexadecimal contents preceding end of data segment 0x%08x\n", *(&edata -1));
	kprintf("Hexadecimal contents after end of data segment 0x%08x\n", *(&edata +1));
	kprintf("Hexadecimal contents preceding end of BSS segment 0x%08x\n", *(&end -1));
	kprintf("Hexadecimal contents after end of BSS segment 0x%08x\n", *(&end +1));
}

