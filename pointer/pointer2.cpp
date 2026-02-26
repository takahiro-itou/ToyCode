
#if 0
program=pointer2;
g++ -Wall -O2 -o bin_${program} ${program}.cpp;
exit 0;
#endif

#include    <iostream>
#include    <memory>

class  Base
{
public:

    Base(int x, int y)
    {
        std::cout   <<  "Construct\n";
    }

    virtual  ~Base()
    {
        std::cout   <<  "Destruct\n";
    }

    virtual  void func()
    {
        std::cout   <<  "Base::func\n";
    }
};

class  Derived : public Base
{
public:

    Derived(int x, int y)
        : Base(x + 1, y + 2)
    {
        std::cout   <<  "Derived Construct.\n";
    }

    virtual  ~Derived()
    {
        std::cout   <<  "Derived Destruct.\n";
    }

    virtual  void func()  override
    {
        std::cout   <<  "Derived::func\n";
    }
};

std::shared_ptr<Derived>
createDerived()
{
    std::shared_ptr<Derived>    ptr = std::make_shared<Derived>(1, 2);
    return  ptr;
}

std::shared_ptr<Base>
testfunc()
{
    std::shared_ptr<Derived>    p1  = createDerived();
    std::cout   <<  "p1 "   <<  p1.use_count()  <<  ":";
    p1->func();

    return  std::move(p1);
}

int main(int argc, char * argv[])
{
    std::shared_ptr<Base>   pb  = testfunc();
    std::cout   <<  "pb = "  <<  pb.use_count()  <<  ":";
    pb->func();

    std::shared_ptr<Base>   pb2 = std::make_shared<Derived>(3, 4);
    pb2->func();

    return ( 0 );
}

