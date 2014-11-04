
#if 0
program=template1;
g++ -Wall -O2 -o bin_${program} ${program}.cpp;
exit 0;
#endif

#include    <iostream>

template  < class  T,  int (T::* PTR) >
class  Accessor
{
public:
    static  int  getValue(const  T  &obj)
    {
        return ( obj .* PTR );
    }

};

struct  Tester
{
    int     a;
    int     b;
};

int  main(int  argc,  char * argv[])
{
    Accessor<Tester,  &Tester::a>   acc1;
    Accessor<Tester,  &Tester::b>   acc2;
    Tester  obj1 = { 10, 20 };
    Tester  obj2 = { 30, 40 };

    std::cout   <<   "obj1.a = " << acc1.getValue(obj1)
                << "\nobj1.b = " << acc2.getValue(obj1)
                << "\nobj2.a = " << acc1.getValue(obj2)
                << "\nobj2.b = " << acc2.getValue(obj2)
                << "\n";
    return ( 0 );
};

