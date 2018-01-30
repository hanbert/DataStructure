/*
 * 第五周作业第一题
 * 判断出栈序列是否合法
 * By HXH 2017.10.30
 */

#include <iostream>
#define MaxSize 1000

using namespace std;

int main()
{
    int input[MaxSize], output[MaxSize], temp[MaxSize];
    int top = -1, num = 0;

    cin >> num;
    for (int index = 0; index < num; index++) cin >> input[index];
    for (int index = 0; index < num; index++) cin >> output[index];

    int indexInput = 0, indexOutput = 0;
    while (indexInput < num && indexOutput < num){
        if (input[indexInput] == output[indexOutput]){
            indexInput++;
            indexOutput++;
            while (top != -1 && temp[top] == output[indexOutput]){
                top--;
                indexOutput++;
            }
        }
        else{
            top++;
            temp[top] = input[indexInput];
            indexInput++;
        }
    }
    if (top == -1) cout << "Right" << endl;
    else cout << "Wrong" << endl;

    return 0;
}
