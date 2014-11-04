
#if 0
program=template2;
g++ -Wall -g  -O2 -o bin_${program} ${program}.cpp;
exit 0;
#endif

#include    <stdlib.h>
#include    <iostream>

template  < class  T,  T * (T::* PTR) >
class  LinkListWrapper
{
public:
    struct  Iterator
    {
        Iterator() : m_ptrNode(NULL) { }
        Iterator(T * p) : m_ptrNode(p) { }
        Iterator & operator ++ () {
            this->m_ptrNode = ((this->m_ptrNode) ->* PTR);
            return ( *this );
        }
        T & operator * () const { return ( *(this->m_ptrNode) ); }
        T * operator ->() const { return ( this->m_ptrNode ); }

        bool  operator != (const  Iterator  &rhs)  const {
            return ( (this->m_ptrNode) != (rhs.m_ptrNode) );
        }

        T * m_ptrNode;
    };

    LinkListWrapper() : m_ptrHead(NULL) { }
    LinkListWrapper(T * p) : m_ptrHead(p) { }
    Iterator    begin() const { return ( Iterator(this->m_ptrHead) ); }
    Iterator    end  () const { return ( Iterator(NULL) ); }

private:
    T * m_ptrHead;
};

struct  ListNode
{
    ListNode *  pNext1;
    ListNode *  pNext2;
    int         nValue;
};

ListNode  *
makeSampleData()
{
    ListNode *  ptr = (ListNode *)(malloc(sizeof(ListNode) * 5));
    for ( int i = 0; i < 5; ++ i ) {
        ptr[i].nValue   = i + 1;
        ptr[i].pNext1   = &ptr[i + 1];
    }
    ptr[4].pNext1   = (NULL);

    ptr[0].pNext2   = ptr + 2;
    ptr[2].pNext2   = ptr + 4;
    ptr[4].pNext2   = ptr + 1;
    ptr[1].pNext2   = ptr + 3;
    ptr[3].pNext2   = (NULL);

    return ( ptr );
}

template  <class  LLW>
void  showLinkList(
        const  LLW  &obj)
{
    typedef     typename  LLW::Iterator     ITR;
    const  ITR  itrEnd  = obj.end();
    for ( ITR itr = obj.begin(); itr != itrEnd; ++ itr ) {
        std::cout   << (itr->nValue) << ", ";
    }
    std::cout   << "\n";
}

int  main(int  argc,  char * argv[])
{
    ListNode *  ptr = makeSampleData();

    LinkListWrapper<ListNode,  &ListNode::pNext1>   obj1(ptr);
    LinkListWrapper<ListNode,  &ListNode::pNext2>   obj2(ptr);

    showLinkList(obj1);
    showLinkList(obj2);

    return ( 0 );
};

