/*
By HXH 2017.10.08
*/

#include <iostream>
#include "LinkList.h"

using namespace std;


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
    head = new LinkNode<Type>(NULL);
    p = head;
    for(int i = 1; i < n; i++){
        cin >> p->data;
        q = new LinkNode<Type>(NULL);
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
    //待完善
}


















