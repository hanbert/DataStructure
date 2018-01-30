/*
By HXH 2017.09.19
*/

#include <iostream>
#include <cstring>
#define MAX_SIZE 10000

using namespace std;

bool CheckRepetition(char element, char *temp, int &length);

int main(){

    char str[MAX_SIZE];
    int start = 0, strLength = 0, length = 0, maxLength = 0;

    cin >> str;
    strLength = strlen(str);
    char temp[strLength + 1];

    while(start < strLength){
        for(int index = start; index < strLength; index++)
            if(CheckRepetition(str[index], temp, length)) break;
        if(length > maxLength) maxLength = length;
        length = 0;
        start++;
    }

    cout << "最大无重复子串长度为：" << maxLength << endl;

    return 0;
}

bool CheckRepetition(char element, char *temp, int &length){

    int flag = 1;
    int num = length;

    for(int index = 0; index < num; index++)
        if(temp[index] == element){
            flag = 0;
            return true;
        }
    if(flag){
        temp[num] = element;
        num++;
        length = num;
    }

    return false;
}
