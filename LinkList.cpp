#include "LinkList.h"
#include <stdio.h>


    void CLinkList::print()
    {
        LinkList p = mHead;
        for(int i = 0;i != mLength;i++)
        {
            p = p->next;
            printf("%d ",p->data);
            if(!(i+1)%10)
            {
                printf("\n");
            }
        }

        printf("\n");
    }

    /*Initialize a Link List*/
    CLinkList::CLinkList()
    {
        mLength = 0;
        mHead = new ListNode;
        mHead->next = nullptr;
    }

    /*test whether a list is empty
    ** return value
    ** true : if the link list is empty
    ** false: if the link list is not empty
    */
    bool CLinkList::listEmpty()
    {
        return !(mLength);
    }

    /*
    ** get the data at the index
    ** input value : 
    ** index    :the index of the value
    ** return value:
    ** ListNode*    : the node at the position
    */
    ListNode* CLinkList::get(int index)
    {
        ListNode* p = mHead;
        if((index < 0) || (index >= mLength))
        {
            return nullptr;
        }
        for(int i = 0;i != index;i++)
        {
            p = p->next;
        }
        return p;
    }

    /*
    ** get the node which contains the value e
    ** param    :
    ** DataType e   : desired data
    ** return   :
    ** ListNode*    :the node contains the data e
    */
    ListNode* CLinkList::locateElem(DataType e)
    {
        ListNode* p = mHead;
        for(int i = 0;i != mLength;i++)
        {
            p = p->next;
            if(p->data == e)
            {
                return p;
            }
        }
        return nullptr;
    }

    int CLinkList::locatePos(DataType e)
    {
        LinkList p = nullptr;
        for(int i = 0;i != mLength;i++)
        {
            p = p->next;
            if(p->data == e)
            {
                return i;
            }
        }
        return -1;
    }

    bool CLinkList::insertList(int index,DataType e)
    {
        ListNode* p = mHead;
        if((index < 0) || (index > mLength))
        {
            return false;
        }
        for(int i = 0;i != index;i++)
        {
            p = p->next;
        }
        LinkList newItem = new ListNode;
        newItem->data = e;

        printf("p->data = %d,p->next = %d\n",p->data,p->next);

        newItem->next = p->next;
        p->next = newItem;
        mLength ++;
        return true;
    }

    bool CLinkList::deleteList(int index,DataType * e)
    {
        LinkList p = mHead;
        if((index < 0) || (index > mLength))
        {
            return false;
        }
        for(int i = 0;i != index;i++)
        {
            p = p->next;
        }
        LinkList tempp = p->next;
        p->next = p->next->next;
        
        delete tempp;

        return true;
    }

    int CLinkList::listLength()
    {
        return mLength;
    }

    CLinkList::~CLinkList()
    {
        LinkList p = mHead->next;
        LinkList tempp = nullptr;
        for(int i = 0;i != mLength;i++)
        {
            tempp = p;
            p = tempp->next;
            delete tempp;
        }
        delete mHead; 
    }