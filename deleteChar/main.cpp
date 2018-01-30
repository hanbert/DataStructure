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

    // ��ȡ���鳤��
    while (str[length]) length++;

    // �����в���Ҫɾ�����ַ����Ƶ�temp������
    for (int index = 0; index < length; index++){
        if (str[index] == ch){
            counter++;
            continue;
        }
        temp[index - counter] = str[index];
    }
    // ��ɾ��ch�ַ�������鸴�Ƶ�ԭ�洢�ռ�
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
