
#if 0
program=sideeffect1;
g++ -Wall -O2 -o bin_${program} ${program}.cpp;
exit 0;
#endif

#include    <stdio.h>

int main(int argc, char * argv[])
{
    int i = 10;
    printf("%d %d %d\n", i, i++, i);
}
