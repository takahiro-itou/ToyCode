
#if 0
program=sideeffect2;
g++ -Wall -g -O0 -o bin_${program} ${program}.cpp;
exit 0;
#endif

#include    <stdio.h>

int main(int argc, char * argv[])
{
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int i = 0;

    while ( i < 10 ) {
        a[i++] = a[i];
    }

    for ( int i = 0; i < 10; ++ i ) {
        printf("%d,", a[i]);
    }
}
