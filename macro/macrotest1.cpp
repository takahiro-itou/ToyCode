
#if 0
program=macrotest1;
g++  -o bin_${program} ${program}.cpp;
exit 0;
#endif

#define     FILENAME    "stdio.h"
#include    FILENAME

int  main(int  argc,  char * argv[])
{
    fprintf(stdout, "Hello World\n");
    return ( 0 );
}
