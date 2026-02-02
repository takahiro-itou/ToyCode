
#if 0
program=jumptable2;
g++  -o bin_${program} ${program}.cpp;
exit 0;
#endif

#include    <stdio.h>

int  main(int  argc,  char * argv[])
{
    void * table[] = {
        &&label1, &&label2
    };

    goto *table[argc & 1];

label1:
    fprintf(stdout, "Label1\n");

label2:
    fprintf(stdout, "Label2\n");


    return ( 0 );
}
