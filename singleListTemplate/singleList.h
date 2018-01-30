#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>

using namespace std;

//��������
template <typename Type> class List;

//����ڵ���
template <typename Type> class ListNode
{
    //������Ԫ��
    friend class List<Type>;

private:
    Type data; //������
    ListNode<Type> *link; //���ָ��

public:
    //�����������캯��
    ListNode(){link = NULL;}

    //���������캯��
    ListNode(const Type &item){
        data = item;
        link = NULL;
    }
};

//������
template <typename Type> class List
{

private:
    ListNode<Type> *head, *tail;

public:
    //�����������캯��
    List(){tail = head = NULL;}

    //���������캯��
    List(const Type &value){
        tail = head = new ListNode<Type>(value);
    }

    //��������
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

    //���Ӻ���
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

    //ɾ������
    bool remove(const Type &value){
        ListNode<Type> *tempNode = NULL, *preNode = NULL;

        preNode = tempNode = head;
        while (tempNode != NULL && tempNode->data != value){
            preNode = tempNode;
            tempNode = tempNode->link;
        }

        //��tempָ��NULL��ʱ��δ�ҵ���ֵ����ŭ��false
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

    //���Һ���
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
