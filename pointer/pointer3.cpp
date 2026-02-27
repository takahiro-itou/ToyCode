
#if 0
program=pointer3;
g++ -Wall -O0 -o bin_${program} ${program}.cpp;
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

std::shared_ptr<Base>
createInstance()
{
    std::shared_ptr<Base>   ptr = std::make_shared<Base>(1, 2);
    return  ptr;
}

void
checkFunc(std::shared_ptr<Base> &ptr)
{
    if ( !ptr ) {
        std::cout   <<  "ptr is valid\n";
    } else {
        std::cout   <<  "ptr is null\n";
    }
    std::cout   <<  ptr         <<  "\n";
    std::cout   <<  ptr.get()   <<  "\n";
    std::cout   <<  "--------------------------------\n";

    return;
}

int main(int argc, char * argv[])
{
    std::shared_ptr<Base>   pb1;
    std::shared_ptr<Base>   pb2  = createInstance();

    checkFunc(pb1);
    checkFunc(pb2);

    return ( 0 );
}

