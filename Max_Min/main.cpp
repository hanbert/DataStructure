/*
By HXH 2017.09.25
*/

#include <iostream>
#define MAX_SIZE 10000

using namespace std;

int main()
{
    int seqList[MAX_SIZE] = {0};
    int maxIndex = 0, minIndex = 0, num = 0;

    cout << "Please enter integer end of n!" << endl;
    while(cin >> seqList[num]) num++;

    for(int index = 0; index < num; index++){
        if(seqList[index] > seqList[maxIndex]) maxIndex = index;
        else if(seqList[index] < seqList[minIndex]) minIndex = index;
    }
    cout << "The Max Integer: " << seqList[maxIndex] << endl;
    cout << "The Min Integer: " << seqList[minIndex] << endl;

    return 0;
}
