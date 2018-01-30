#ifndef LINKEDPRQUEUE_H
#define LINKEDPRQUEUE_H

#include <iostream>

using namespace std;

//�����������
template <typename Type> class LinkedPrQueue;

//��������ڵ���
template <typename Type> class LinkNode{

    friend class LinkedPrQueue<Type>;

private:
    Type data; //������
    LinkNode<Type> *link; //��̽ڵ�

public:
    //�����ι��캯��
    LinkNode(){link = NULL;}
    //���ι��캯��
    LinkNode(const Type &item){
        data = item;
        link = NULL;
    }
};

//�������������
template <typename Type> class LinkedPrQueue{

private:
    LinkNode<Type> *head, *tail; //ͷָ���βָ��

public:
    //�޲������캯��
    LinkedPrQueue(){head = tail = NULL;}
    //��Ӳ���
    void inQueue(const Type &item)
    {
        LinkNode<Type> *tempNode = NULL, *preNode = NULL, *newNode = NULL;
        //�½�һ���ڵ�
        newNode = new LinkNode<Type>(item);

        //��Ѱ�����
        tempNode = head;
        while (head != NULL && tempNode != NULL){
            if (tempNode->data < newNode->data) break;
            preNode = tempNode;
            tempNode = tempNode->link;
        }

        //������Ϊ�յ�ʱ��
        if (head == NULL){
            tail = head = newNode;
        }
        else if (tempNode == head){ //��ǰ���в���ʱ
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

        //�����ǰ����
        tempNode = head;
        while (tempNode){
            cout << tempNode->data << " ";
            tempNode = tempNode->link;
        }
        cout << endl;
    }
    //���Ӳ���
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
