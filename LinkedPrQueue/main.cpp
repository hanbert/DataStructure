/*
 * 第五周作业
 * 链表实现优先级队列
 * By HXH 2017.10.30
 */

#include <iostream>
#include "LinkedPrQueue.h"

using namespace std;

int main()
{
    LinkedPrQueue<int> prQueue;
    int temp = 0;
    char action;
    bool flag = true;

    while (flag){
        cin >> action;

        switch (action)
        {
        case 'i':
            cin >> temp;
            prQueue.inQueue(temp);
            break;

        case 'o':
            prQueue.outQueue();
            break;

        default:
            flag = false;
            break;
        }
    }

    return 0;
}
