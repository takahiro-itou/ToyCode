
#if 0
program=sideeffect4;
g++ -Wall -O2 -o bin_${program} ${program}.cpp;
exit 0;
#endif

#include    <stdio.h>

int main(int argc, char * argv[])
{
    int i = 10;

    if ( i == 0, i++, i == 11 ) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    i = i = 20;
    printf("%d\n", i);
}
