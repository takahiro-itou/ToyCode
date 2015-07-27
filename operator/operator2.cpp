
#if 0
program=operator2;
g++ -Wall -O2 -o bin_${program} ${program}.cpp;
exit 0;
#endif

#include    <iostream>

int  main(int  argc,  char * argv[])
{
    int  a, b;

    a  =  1,000,000 + 123;
    b  =  (1,000,010 + 5);

    std::cout   <<   "a = " << a
                << "\nb = " << b
                << std::endl;
    return ( 0 );
};

