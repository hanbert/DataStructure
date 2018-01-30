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
    Type data; //������
    LinkNode<Type> *link; //���ָ��

public:
    LinkNode(); //�����βεĹ��캯��
    LinkNode(const Type &item); //���βεĹ��캯��
    LinkNode<Type> *NextNode(); //������ǰ�ڵ�ĺ�̽ڵ��ַ
    void InsertAfter(LinkNode<Type> *p); //��ǰ�ڵ����
    LinkNode<Type> *GetNode(const Type &item, LinkNode<Type> *next); //����һ���½ڵ�
    LinkNode<Type> *RemoveAfter(); //ɾ����ǰ�ڵ����һ���ڵ�
};

template <class Type> class List{

public:
    LinkNode<Type> *head, *tail;
    List();
    List(const Type &value); //���캯��
    ~List(); //��������
    LinkNode<Type> *Create_List(int n); //����һ��������
    void MakeEmpty(); //��������Ϊ��
    int Length() const; //��������ĳ���
    LinkNode<Type> *Find(Type value); //��������������������value�Ľڵ�
    int Insert(Type value, int i); // ����Ԫ�ز�������ĵ�i��λ��
    Type Delete(int i); //�������еĵ�i��Ԫ��ɾ��
    Type Get(int i); //ȡ�������еĵ�i��Ԫ��
    int CheckLoop();
};


//ListNode �ຯ��ʵ��
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
    //������
}

template <typename Type> LinkNode<Type>* LinkNode<Type> :: GetNode(const Type &item, LinkNode<Type> *next){
    //������
}

template <typename Type> LinkNode<Type>* LinkNode<Type> :: RemoveAfter(){
    //������
}


//List�ຯ��ʵ��
template <typename Type> List<Type> :: List(){
}

template <typename Type> List<Type> :: List(const Type &value){
    tail = head = new LinkNode<Type>(value);
}

template <typename Type> List<Type> :: ~List(){
    //������
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
    //������
}

template <typename Type> int List<Type> :: Length() const {
    //������
    return 0;
}

template <typename Type> LinkNode<Type>* List<Type> :: Find(Type value){
    //������
}

template <typename Type> int List<Type> :: Insert(Type value, int i){
    //����Ԫ��value���뵽i�ڵ�֮ǰ������i�ǽڵ�ı�ţ���0��ʼ����
    LinkNode<Type> *p, *q;
    int j = 0;

    p = head;
    q = new LinkNode<Type>(value, NULL); //�����µ�������Ϊvalue�Ľڵ㣬��qָʾ

    while(p != NULL && j < i - 1){ //Ѱ�ҵ�i-1���ڵ��λ��
        p = p->link;
        j++;
    }

    if(p == NULL && head != NULL){
        //�ǿ��������ǽ϶̣�������i-1���ڵ�
        cout << "Invalid position for Insertion! " << endl;
        return 0;
    }

    if(head == NULL || i == 0){
        //���½ڵ���뵽�ձ���߷ǿձ�ĵ�һ���ڵ�֮ǰ
        q->link = head;
        if(head == NULL) tail = q;
        head = q;
    }
    else{
        //���½ڵ���뵽�����м���߱�β
        q->link = p->link;
        if(p->link == NULL) tail = q;
        p->link = q;
    }
    return 1;
}

template <typename Type> Type List<Type> :: Delete(int i){
    //ɾ�������еĵ�i���ڵ㲢���䷵�أ�����i�ǽڵ�ı�ţ���0��ʼ
    LinkNode<Type> *p, *q;
    int j = 0;
    p = head;
    Type result;

    while(p != NULL && j < i - 1){
        p = p->link;
        j++;
    }

    if(p == NULL && head != NULL){
        //�ǿ������̣��Ҳ�����i-1���ڵ�
        cout << "Invalid position for Deletion!" << endl;
        return 0;
    }

    if(i == 0){ //ɾ�����׽ڵ�
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
    //������
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
