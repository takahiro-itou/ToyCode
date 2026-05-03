
#if 0
program=sideeffect3;
g++ -Wall -g -O2 -o bin_${program} ${program}.cpp;
exit 0;
#endif

#include    <stdio.h>

int main(int argc, char * argv[])
{
    int a[10] = {};
    int i = 0;

    while ( i < 10 ) {
        a[i] = i++;
    }

    for ( int i = 0; i < 10; ++ i ) {
        printf("%d,", a[i]);
    }
}
