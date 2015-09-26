
#if 0
program=template3;
g++  -std=c++11  -Wall -g  -O2 -o bin_${program} ${program}.cpp;
exit 0;
#endif

#include    <stdlib.h>
#include    <iostream>

template  < typename  VALTYPE,  class >
class  SafetyType
{
public:

    constexpr
    SafetyType(
            const  VALTYPE  v)
        : m_value(v)
    { }

    //  ここではサンプルなので、マイナス演算子だけ示す。    //
    //  実際には、他の演算子も同様に定義する必要がある。    //
    SafetyType
    operator - (const  SafetyType  &rhs)  const
    {
        return ( SafetyType(this->m_value - rhs.m_value) );
    }

    //  画面表示用。    //
    std::ostream  &
    writeToStream(std::ostream  &os)  const
    {
        return ( os << (this->m_value) );
    }

    friend  std::ostream  &
    operator << (std::ostream  &os,  const  SafetyType  &rhs)
    {
        return ( rhs.writeToStream(os) );
    }

private:
    VALTYPE     m_value;
};


//
//    使うときはこれでもいいけど。
//

#if 0
struct      tag_SyainNo;
typedef     SafetyType<int,  tag_SyainNo>   SyainNo;

struct      tag_Year;
typedef     SafetyType<int,  tag_Year>      Year;
#endif

//
//    こんなマクロを用意してもよい。
//

#define     DECLARE_SAFETY_TYPE(btype, dtype)   \
struct      tag_ ## dtype;                      \
typedef     SafetyType<btype, tag_ ## dtype>    dtype

DECLARE_SAFETY_TYPE(int, SyainNo);      /**<  社員番号型。  **/
DECLARE_SAFETY_TYPE(int, Year);         /**<  西暦年型。    **/

//  安全でない構造体。  //
struct  UnsafeStrcut
{
    int     syainNo;        //  社員番号。  //
    int     enterYear;      //  入社年。    //
};

//  少し安全な構造体。  //
struct  SafeStruct
{
    SyainNo syainNo;        //  社員番号。  //
    Year    enterYear;      //  入社年。    //
};


//  指定した社員が入社何年目かを計算する。  //
int  unsafeFunction(const  UnsafeStrcut  &data,  const  int  yCur)
{
    //  プログラムミス：入社年と社員番号を間違えた。    //
    //  でも、どっちも int  だからエラーではない。      //
    //  当然実行時にバグが発生するが探すのが大変。      //
    return ( yCur - data.syainNo );
}

Year  safeFunction(const  SafeStruct  &data,  const  Year  yCur)
{
    //  プログラムミス：入社年と社員番号を間違えた。    //
    //  今度は厳密に型チェックが入ってエラーになる。    //
    //  実行時にバグが出るまえにコンパイルで気づける。  //

////    return ( yCur - data.syainNo );     //  これはエラー。  //
    return ( yCur - data.enterYear );    //  これは大丈夫。  //
}

int  main(int  argc,  char * argv[])
{
    //  安全でない。    //
    UnsafeStrcut    datUnsafe   = { 12345, 2010 };

    SafeStruct      datSafe     = { 12345, 2010 };

    std::cout   << "UNSAFE: " << unsafeFunction(datUnsafe, 2015)
                << std::endl;

    std::cout   << "SAFE: " << safeFunction(datSafe, 2015)
                << std::endl;

    return ( 0 );
};

