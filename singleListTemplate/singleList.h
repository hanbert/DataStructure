#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>

using namespace std;

//链表声明
template <typename Type> class List;

//链表节点类
template <typename Type> class ListNode
{
    //声明友元类
    friend class List<Type>;

private:
    Type data; //数据域
    ListNode<Type> *link; //后继指针

public:
    //不含参数构造函数
    ListNode(){link = NULL;}

    //含参数构造函数
    ListNode(const Type &item){
        data = item;
        link = NULL;
    }
};

//链表类
template <typename Type> class List
{

private:
    ListNode<Type> *head, *tail;

public:
    //不含参数构造函数
    List(){tail = head = NULL;}

    //含参数构造函数
    List(const Type &value){
        tail = head = new ListNode<Type>(value);
    }

    //析构函数
    ~List(){
        ListNode<Type> *temp = NULL;

        temp = head;
        while(temp != NULL){
            head = temp->link;
            delete temp;
            temp = head;
        }
        tail = NULL;
    }

    //增加函数
    bool add(const Type &value){
        ListNode<Type> *temp = NULL;

        temp = new ListNode<Type>(value);
        if (! temp) return false;

        if (head == NULL){
            tail = head = temp;
        }
        else {
            tail->link = temp;
            tail = temp;
        }

        return true;
    }

    //删除函数
    bool remove(const Type &value){
        ListNode<Type> *tempNode = NULL, *preNode = NULL;

        preNode = tempNode = head;
        while (tempNode != NULL && tempNode->data != value){
            preNode = tempNode;
            tempNode = tempNode->link;
        }

        //当temp指向NULL的时候，未找到该值，发怒会false
        if (! tempNode) return false;

        if (tempNode == head) {
            head = head->link;
            delete tempNode;
            tempNode = NULL;
            return true;
        }
        if (tempNode == tail) tail = preNode;
        preNode->link = tempNode->link;
        delete tempNode;
        tempNode = NULL;

        return true;
    }

    //查找函数
    bool find(const Type &value){
        ListNode<Type> *tempNode = NULL;

        tempNode = head;
        while (tempNode != NULL && tempNode->data != value) tempNode = tempNode->link;

        if (! tempNode) return false;

        return true;
    }

    void printList(){
        ListNode<Type> *tempNode = NULL;

        tempNode = head;
        while (tempNode != NULL){
            cout << tempNode->data << " ";
            tempNode = tempNode->link;
        }
        cout << endl;
    }
};


#endif // SINGLELIST_H
