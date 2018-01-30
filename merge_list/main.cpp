/*
By HXH 2017.10.08
*/

#include <iostream>
#include "LinkList.h"

using namespace std;

//合并两个非递减有序单链表成为一个非递增有序单链表
int MergeList(){

    List<int> listA, listB;
    LinkNode<int> *ptrA, *ptrB, *tempPtr;
    int numA = 0, numB = 0;

    //初始化两个链表
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

    //输出合并后的链表
    ptrA = listA.head;
    cout << "The Merged List: " << endl;
    while(ptrA != NULL){
        cout << ptrA->data << " ";
        ptrA = ptrA->link;
    }
    cout << endl;

    return 0;
}

//检查单链表中是否存在环，调用List的类的方法
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

    //检查是否存在环并找出入口
    testList.CheckLoop();

    return 0;
}

//主函数
int main()
{
    int flag = 0;

    cout << "What do you want to do: \n" << "       1. Merge two list \n" << "       2. Check loop in list \n" << "Please enter 1 or 2: ";
    cin >> flag;

    if(flag == 1) MergeList();
    else CheckList();

    return 0;
}

