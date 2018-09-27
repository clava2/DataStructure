#ifndef _LINK_LIST_H
#define _LINK_LIST_H

typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node* next;
}ListNode, * LinkList;

class CLinkList
{
private:

    // header
    LinkList mHead;

    // the length of the list
    int mLength;

public:


    /*
    ** print the information in the list
    ** params   :
    ** void
    ** return   :
    ** void
    */
    void print(void);

    /*Initialize a Link List*/
    CLinkList();

    /*test whether a list is empty
    ** return value
    ** true : if the link list is empty
    ** false: if the link list is not empty
    */
    bool listEmpty();

    /*
    ** get the data at the index
    ** input value : 
    ** index    :the index of the value
    ** return value:
    ** ListNode*    : the node at the position, nullptr if the index if illeagle.
    */
    ListNode* get(int index);

    /*
    ** get the node which contains the value e
    ** param    :
    ** DataType e   : desired data
    ** return   :
    ** ListNode*    :the node contains the data e, nullptr if the value e is illeagle
    */
    ListNode* locateElem(DataType e);

    /*
    ** get the position of the node which contains the data e
    ** params   :
    ** DataType e   :desired data
    ** return   :
    ** int          : the index of the node, -1 if the data was not found.
    */
    int locatePos(DataType e);

    /*
    ** insert a Data
    ** params   :
    ** int index    : desired position for inserting
    ** DataType e   : the value which will be inserted
    ** return   :
    ** bool         : true if successful, false otherwise
    */
    bool insertList(int index,DataType e);

    /*
    ** delete a element in the list
    ** param    :
    ** int index    : the position of the data which will be deleted
    ** DataType* e  : if the node is deleted successful, 
                        the deleted value will be placed here.
                        otherwise, the value of e will not be modified
    ** return   :
    ** bool         : true if successful, false otherwise
    */
    bool deleteList(int index,DataType * e);

    /*
    ** get the length of the Link List
    ** param:
    ** void
    ** return   :
    ** int          : the length of the Link List
    */
    int listLength();

    /*
    ** destroy the Link List
    */
    ~CLinkList();
};


#endif