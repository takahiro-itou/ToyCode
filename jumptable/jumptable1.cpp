
#if 0
program=jumptable1;
g++  -o bin_${program} ${program}.cpp;
exit 0;
#endif

#include    <stdio.h>

int  main(int  argc,  char * argv[])
{
    void * address;

    address = &&label2;
    goto *address;

label1:
    fprintf(stdout, "Label1\n");

label2:
    fprintf(stdout, "Label2\n");


    return ( 0 );
}
