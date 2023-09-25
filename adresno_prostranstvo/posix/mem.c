#include <sys/mman.h>
#include <stdio.h>

int main()
{
       char *mem = mmap(0, 1<<20, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
       perror("mmap");
       mprotect(mem + (1<<16), 1<<16, PROT_WRITE);
       perror("mprotect");
       //mem[(1<<16) + (1<<15)] = 'B';
       mem[0] = 'B';
}
