
#if 0
program=regparm1;
g++ -Wall -O0 -g -o bin_${program} ${program}.cpp;
exit 0;
#endif

#define     TEST_REGPARM_1   __attribute__((regparm(1)))
#define     TEST_REGPARM_2   __attribute__((regparm(2)))
#define     TEST_REGPARM_3   __attribute__((regparm(3)))

class  Hoge
{
public:

    Hoge()
        : x_(10)
    { }

    int test1_0(int a);

    TEST_REGPARM_1
    int test1_1(int a);

    TEST_REGPARM_2
    int test1_2(int a);

    TEST_REGPARM_3
    int test1_3(int a);

    int test2_0(int a, int b);

    TEST_REGPARM_1
    int test2_1(int a, int b);

    TEST_REGPARM_2
    int test2_2(int a, int b);

    TEST_REGPARM_3
    int test2_3(int a, int b);

public:
    int     x_;
};

int Hoge::test1_0(int a)
{
    return ( x_ + a );
}

int Hoge::test1_1(int a)
{
    return ( x_ + a );
}

int Hoge::test1_2(int a)
{
    return ( x_ + a );
}

int Hoge::test1_3(int a)
{
    return ( x_ + a );
}

int Hoge::test2_0(int a, int b)
{
    return ( x_ + a + b );
}

int Hoge::test2_1(int a, int b)
{
    return ( x_ + a + b );
}

int Hoge::test2_2(int a, int b)
{
    return ( x_ + a + b );
}

int Hoge::test2_3(int a, int b)
{
    return ( x_ + a + b );
}

int main(int argc, char * argv[])
{
    Hoge    hoge;

    hoge.test1_0(10);
    hoge.test1_1(11);
    hoge.test1_2(12);
    hoge.test1_3(13);

    hoge.test2_0(20, 30);
    hoge.test2_1(20, 30);
    hoge.test2_2(22, 32);
    hoge.test2_3(22, 32);
}
