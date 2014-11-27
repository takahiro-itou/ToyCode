
#if 0
program=operator1;
g++ -Wall -O2 -o bin_${program} ${program}.cpp;
exit 0;
#endif

#include    <iostream>

int  main(int  argc,  char * argv[])
{
    int  a  = 10;
    int  b  = 2;
    int  c  = 3;

    a *= b += c;
    std::cout   <<   "a = " << a
                << "\nb = " << b
                << "\nc = " << c
                << std::endl;

    double  x, y;

    x  = 1,5 + 2;
    y  = (1,5 + 2);
    std::cout   <<   "x = " << x
                << "\ny = " << y
                << std::endl;
    return ( 0 );
};

