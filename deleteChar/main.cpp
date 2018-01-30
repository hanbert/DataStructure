/*
* By HXH 2017.10.22
*/

#include <iostream>
#define MaxSize 1000

using namespace std;

void Del(char *str, char ch)
{
    char temp[MaxSize] = "";
    int length = 0, counter = 0;

    // 获取数组长度
    while (str[length]) length++;

    // 将所有不需要删除的字符复制到temp数组中
    for (int index = 0; index < length; index++){
        if (str[index] == ch){
            counter++;
            continue;
        }
        temp[index - counter] = str[index];
    }
    // 将删除ch字符后的数组复制到原存储空间
    for(int index = 0; index < length - counter; index++){
        str[index] = temp[index];
    }
    str[length - counter] = '\0';
}


int main()
{
    char str[MaxSize] = "";
    char ch;
    int index = 0;

    cin >> str;
    cin >> ch;

    Del(str, ch);

    while (str[index]){
        cout << str[index];
        index++;
    }

    return 0;
}
