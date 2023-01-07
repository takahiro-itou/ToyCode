
#if 0
program=template4;
g++  -std=c++11  -Wall -g  -O2 -o bin_${program} ${program}.cpp;
exit 0;
#endif

#include    <vector>
#include    <stdlib.h>
#include    <iostream>

template  <typename T>
inline  T func(const T val)
{
    return ( val );
}

template <typename T>
inline  T func(const std::vector<T> & v)
{
    return ( v[0] );
}

template <typename T>
inline  T func(T * val)
{
    return ( * val );
}

int main(int argc, char * argv[])
{
    int x1  = 10;
    int *p  = &x1;
    std::vector<int>    v;
    v.push_back(20);

    std::cout   <<  "x1 = " <<  func(x1)
                <<  "\n*p = "   <<  func(p)
                <<  "\nv  = "   <<  func(v)
                <<  std::endl;
    return ( 0 );
}
