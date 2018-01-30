#ifndef LINKEDPRQUEUE_H
#define LINKEDPRQUEUE_H

#include <iostream>

using namespace std;

//声明链表队列
template <typename Type> class LinkedPrQueue;

//定义链表节点类
template <typename Type> class LinkNode{

    friend class LinkedPrQueue<Type>;

private:
    Type data; //数据域
    LinkNode<Type> *link; //后继节点

public:
    //不含参构造函数
    LinkNode(){link = NULL;}
    //含参构造函数
    LinkNode(const Type &item){
        data = item;
        link = NULL;
    }
};

//定义链表队列类
template <typename Type> class LinkedPrQueue{

private:
    LinkNode<Type> *head, *tail; //头指针和尾指针

public:
    //无参数构造函数
    LinkedPrQueue(){head = tail = NULL;}
    //入队操作
    void inQueue(const Type &item)
    {
        LinkNode<Type> *tempNode = NULL, *preNode = NULL, *newNode = NULL;
        //新建一个节点
        newNode = new LinkNode<Type>(item);

        //找寻插入点
        tempNode = head;
        while (head != NULL && tempNode != NULL){
            if (tempNode->data < newNode->data) break;
            preNode = tempNode;
            tempNode = tempNode->link;
        }

        //当队列为空的时候
        if (head == NULL){
            tail = head = newNode;
        }
        else if (tempNode == head){ //当前队列不空时
            head = newNode;
            newNode->link = tempNode;

        }
        else if (tempNode != NULL){
            preNode->link = newNode;
            newNode->link = tempNode;
        }
        else {
            tail->link = newNode;
            tail = newNode;
        }

        //输出当前队列
        tempNode = head;
        while (tempNode){
            cout << tempNode->data << " ";
            tempNode = tempNode->link;
        }
        cout << endl;
    }
    //出队操作
    void outQueue()
    {
        LinkNode<Type> *tempNode = NULL;

        tempNode = head;
        while (tempNode->link != tail) tempNode = tempNode->link;
        tail = tempNode;
        tempNode = tempNode->link;
        tail->link = NULL;
        delete tempNode;
        tempNode = NULL;

        tempNode = head;
        while (tempNode){
            cout << tempNode->data << " ";
            tempNode = tempNode->link;
        }
        cout << endl;
    }
};

#endif // LINKEDPRQUEUE_H
