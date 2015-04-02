
int  sub2a(int x);
int  sub2b(int x);

#include    <iostream>

int  sub1a(int x)
{
    std::cout  << "SUB 1A"  << std::endl;
    return ( sub2a(x) + 1 );
}

int  sub1b(int x)
{
    std::cout  << "SUB 1B"  << std::endl;
    return ( sub2b(x) + 2 );
}
