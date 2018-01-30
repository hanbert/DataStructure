/*
By HXH 2017.10.08
*/

#include <iostream>
#include "LinkList.h"

using namespace std;

//�ϲ������ǵݼ����������Ϊһ���ǵ�����������
int MergeList(){

    List<int> listA, listB;
    LinkNode<int> *ptrA, *ptrB, *tempPtr;
    int numA = 0, numB = 0;

    //��ʼ����������
    cout << "Initial the A list: " << endl;
    cin >> numA;
    listA.Create_List(numA);
    cout << "Initial the B list: " << endl;
    cin >> numB;
    listB.Create_List(numB);

//    ptrA = listA.head;
//    cout << "The ListA: " << endl;
//    cout << ptrA << " ";
//    while(ptrA != NULL){
//        cout << ptrA->data << " | " << ptrA->link << " ";
//        ptrA = ptrA->link;
//    }
//    cout << endl;
//
//    ptrB = listB.head;
//    cout << "The ListB: " << endl;
//    cout << ptrB << " ";
//    while(ptrB != NULL){
//        cout << ptrB->data << " | " << ptrB->link << " ";
//        ptrB = ptrB->link;
//    }
//    cout << endl;

    ptrA = listA.head;
    ptrB = listB.head;
    listA.head = NULL;

    while(ptrA != NULL && ptrB != NULL){
        if(ptrA->data <=  ptrB->data){
            tempPtr = ptrA;
            ptrA = ptrA->link;
            tempPtr->link = listA.head;
            listA.head = tempPtr;
            if(listA.head->link == NULL) listA.tail = listA.head;
        }
        else{
            tempPtr = ptrB;
            ptrB = ptrB->link;
            tempPtr->link = listA.head;
            listA.head = tempPtr;
            if(listA.head->link == NULL) listA.tail = listA.head;
        }
    }
    if(ptrA == NULL){
        while(ptrB != NULL){
            tempPtr = ptrB;
            ptrB = ptrB->link;
            tempPtr->link = listA.head;
            listA.head = tempPtr;
        }
    }
    else{
        while(ptrA != NULL){
            tempPtr = ptrA;
            ptrA = ptrA->link;
            tempPtr->link = listA.head;
            listA.head = tempPtr;
        }
    }

    //����ϲ��������
    ptrA = listA.head;
    cout << "The Merged List: " << endl;
    while(ptrA != NULL){
        cout << ptrA->data << " ";
        ptrA = ptrA->link;
    }
    cout << endl;

    return 0;
}

//��鵥�������Ƿ���ڻ�������List����ķ���
int CheckList(){
    List<int> testList;
    int num = 0, counter = 0, position = 0;
    LinkNode<int> *ptr;

    cout << "Initial the list: " << endl;
    cin >> num;
    testList.Create_List(num);

    ptr = testList.head;
    cout << "The List: " << endl;
    cout << ptr << " ";
    while(ptr != NULL){
        counter++;
        cout << ptr->data << " | " << ptr->link << " ";
        ptr = ptr->link;
    }
    cout << "\nThe list have " << counter << " nodes!" << endl;

    cout << "Add a loop in list for test! " << endl;
    cout << "The loop entrance(1~" << counter << "): " << endl;
    cin >> position;

    ptr = testList.head;
    for(int index = 1; index < position; index++) ptr = ptr->link;
    testList.tail->link = ptr;

    //����Ƿ���ڻ����ҳ����
    testList.CheckLoop();

    return 0;
}

//������
int main()
{
    int flag = 0;

    cout << "What do you want to do: \n" << "       1. Merge two list \n" << "       2. Check loop in list \n" << "Please enter 1 or 2: ";
    cin >> flag;

    if(flag == 1) MergeList();
    else CheckList();

    return 0;
}

