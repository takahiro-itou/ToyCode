
#if 0
echo    '#define MSG "デバッグモード"' > ConfigDebug
echo    '#define MSG "リリースモード"' > ConfigRelease

program=macrotest2;
g++  -o bin_${program} ${program}.cpp  -DCOMPILE_MODE=Debug;
#g++  -o bin_${program} ${program}.cpp  -DCOMPILE_MODE=Release;
exit 0;
#endif

#define     TEST_TO_STR(s)          #s
#define     TEST_FILENAME(h)        TEST_TO_STR(h)
#define     TEST_CAT(x, y)          x ## y
#define     TEST_HEADER_NAME(p)     TEST_FILENAME(TEST_CAT(Config, p))

#include    TEST_HEADER_NAME(COMPILE_MODE)

#include    <iostream>

int  main(int  argc,  char * argv[])
{
    std::cout   << MSG << std::endl;
    return ( 0 );
}

