/*
By HXH 2017.10.08
*/

#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>

using namespace std;

template <typename Type> class List;

template <typename Type> class LinkNode{
    friend class List<Type>;

public:
    Type data; //数据域
    LinkNode<Type> *link; //后继指针

public:
    LinkNode(); //不带形参的构造函数
    LinkNode(const Type &item); //带形参的构造函数
    LinkNode<Type> *NextNode(); //给出当前节点的后继节点地址
    void InsertAfter(LinkNode<Type> *p); //当前节点插入
    LinkNode<Type> *GetNode(const Type &item, LinkNode<Type> *next); //建立一个新节点
    LinkNode<Type> *RemoveAfter(); //删除当前节点的下一个节点
};

template <class Type> class List{

public:
    LinkNode<Type> *head, *tail;
    List();
    List(const Type &value); //构造函数
    ~List(); //析构函数
    LinkNode<Type> *Create_List(int n); //建立一个单链表
    void MakeEmpty(); //将链表置为空
    int Length() const; //计算链表的长度
    LinkNode<Type> *Find(Type value); //在链表中搜索含有数据value的节点
    int Insert(Type value, int i); // 将新元素插在链表的第i个位置
    Type Delete(int i); //将链表中的第i个元素删除
    Type Get(int i); //取出链表中的第i个元素
    int CheckLoop();
};


//ListNode 类函数实现
template <typename Type> LinkNode<Type> :: LinkNode(){
    link = NULL;
}

template <typename Type> LinkNode<Type> :: LinkNode(const Type &item){
    data = item;
    link = NULL;
}

template <typename Type> LinkNode<Type>* LinkNode<Type> :: NextNode(){
    return link;
}

template <typename Type> void LinkNode<Type> :: InsertAfter(LinkNode<Type> *p){
    //待完善
}

template <typename Type> LinkNode<Type>* LinkNode<Type> :: GetNode(const Type &item, LinkNode<Type> *next){
    //待完善
}

template <typename Type> LinkNode<Type>* LinkNode<Type> :: RemoveAfter(){
    //待完善
}


//List类函数实现
template <typename Type> List<Type> :: List(){
}

template <typename Type> List<Type> :: List(const Type &value){
    tail = head = new LinkNode<Type>(value);
}

template <typename Type> List<Type> :: ~List(){
    //待完善
}

template <typename Type> LinkNode<Type>* List<Type> :: Create_List(int n){
    LinkNode<Type> *p, *q;

    if(n == 0) return NULL;
    head = new LinkNode<Type>();
    p = head;
    for(int i = 1; i < n; i++){
        cin >> p->data;
        q = new LinkNode<Type>();
        p->link = q;
        p = q;
    }
    cin >> p->data;
    p->link = NULL;
    tail = p;

    return head;
}

template <typename Type> void List<Type> :: MakeEmpty(){
    //待完善
}

template <typename Type> int List<Type> :: Length() const {
    //待完善
    return 0;
}

template <typename Type> LinkNode<Type>* List<Type> :: Find(Type value){
    //待完善
}

template <typename Type> int List<Type> :: Insert(Type value, int i){
    //将新元素value插入到i节点之前，其中i是节点的编号，从0开始计数
    LinkNode<Type> *p, *q;
    int j = 0;

    p = head;
    q = new LinkNode<Type>(value, NULL); //建立新的数据域为value的节点，由q指示

    while(p != NULL && j < i - 1){ //寻找第i-1个节点的位置
        p = p->link;
        j++;
    }

    if(p == NULL && head != NULL){
        //非空链表，但是较短，不存在i-1个节点
        cout << "Invalid position for Insertion! " << endl;
        return 0;
    }

    if(head == NULL || i == 0){
        //将新节点插入到空表或者非空表的第一个节点之前
        q->link = head;
        if(head == NULL) tail = q;
        head = q;
    }
    else{
        //将新节点插入到链表中间或者表尾
        q->link = p->link;
        if(p->link == NULL) tail = q;
        p->link = q;
    }
    return 1;
}

template <typename Type> Type List<Type> :: Delete(int i){
    //删除链表中的第i个节点并将其返回，其中i是节点的编号，从0开始
    LinkNode<Type> *p, *q;
    int j = 0;
    p = head;
    Type result;

    while(p != NULL && j < i - 1){
        p = p->link;
        j++;
    }

    if(p == NULL && head != NULL){
        //非空且链短，找不到第i-1个节点
        cout << "Invalid position for Deletion!" << endl;
        return 0;
    }

    if(i == 0){ //删除表首节点
        q = head;
        p = head = head->link;
    }
    else{
        q = p->link;
        p->link = q->link;
    }

    if(q == tail) tail = p;

    result = q->data;
    delete q;

    return result;
}

template <typename Type> Type List<Type> :: Get(int i){
    //待完善
}

template <typename Type> int List<Type> :: CheckLoop(){

    LinkNode<Type> *ptr1, *ptr2;

    ptr1 = ptr2 = head;
    while(ptr2 != NULL && ptr2->link != NULL){
        ptr1 = ptr1->link;
        ptr2 =  ptr2->link->link;
        if(ptr1 == ptr2) break;
    }
    if(ptr2 == NULL){
        cout << "The list have no loop!" << endl;
    }
    if(ptr1 == ptr2){
        ptr1 = head;
        while(ptr1 != ptr2){
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        cout << "The list have loop!" << endl;
        cout << "The loop entrance: " << ptr1 << " " << ptr1->data << endl;
    }

    return 0;
}


#endif // LINKLIST_H
