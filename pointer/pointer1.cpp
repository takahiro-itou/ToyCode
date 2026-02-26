
#if 0
program=pointer1;
g++ -Wall -O2 -o bin_${program} ${program}.cpp;
exit 0;
#endif

#include    <iostream>
#include    <memory>

class  Test
{
public:

    Test(int x, int y)
    {
        std::cout   <<  "Construct\n";
    }

    virtual  ~Test()
    {
        std::cout   <<  "Destruct\n";
    }
};


int main(int argc, char * argv[])
{
    std::shared_ptr<Test>   ptr = std::make_shared<Test>(1, 2);

    {
        std::weak_ptr<Test>     wptr(ptr);
        std::cout   <<  "REF = "  <<  ptr.use_count()   <<  std::endl;
    }
    std::cout   <<  "REF = "  <<  ptr.use_count()   <<  std::endl;

    return ( 0 );
}

