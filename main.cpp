#include "LinkList.h"

int main(int argc,char* argv[])
{
    CLinkList list;
    list.insertList(0,10);
    list.print();
    list.insertList(1,35);
    list.insertList(2,56);
    list.print();

    return 0;
}