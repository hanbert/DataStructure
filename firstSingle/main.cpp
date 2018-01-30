/*
* By HXH 2017.10.22
*/

#include <iostream>
#include <string.h>
#define MaxSize 1000
#define ASCIISize 256

using namespace std;

char firstSingle(char* str)
{
    int counter[ASCIISize];
    memset(counter, 0, sizeof(counter)); // 初始化为0, 针对每个字节，所有最后一个参数为：256*4 = 1024

    int length = strlen(str);

    for (int index = 0; index < length; index++){
        counter[(int)str[index]]++;
    }

    int index;
    for (index = 0; index < length; index++){
        if (counter[(int)str[index]] == 1) break;
    }
    if(index == length) cout << "No single char!" << endl;

    return str[index];
}


int main()
{
    char str[MaxSize] = "";
    cin >> str;

    cout << "The first single char: " << firstSingle(str) << endl;

    return 0;
}
