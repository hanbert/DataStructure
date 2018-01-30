/*
 * �������ϻ��ڶ���
 * ������Ӵ�
 * By HXH 2017.10.30
 */

#include <iostream>
#include <string>
#define MaxSize 30

using namespace std;

//��̬�滮
int palindromeSubstring2(string &str)
{
    int length = str.size(), maxLength = 0;
    bool isPalindrome[MaxSize][MaxSize] = {false}; //��Ǵ�i��j���Ӵ��Ƿ�Ϊ�����Ӵ���1��ʾ�ǣ�0��ʾ����

    //��ʼ���������,�����Ӵ�����Ϊ������Ϊż��������������������i+1��j-1�Ӵ��ǲ�ͬ�ģ��ֱ��ӦΪ1��2���г�ʼ��
    for (int index = 0; index < length; index++){
        //�����ַ��϶���������
        isPalindrome[index][index] = true;
        //���ҳ�����Ϊ2��������ĵ��Ӵ�
        if (index < length - 1 && str[index] == str[index + 1])
        {
            isPalindrome[index][index + 1] = true;
            maxLength = 2;
        }
    }
    //���Ӵ�����Ϊ3��ʼ����������ĵ��Ӵ����Ӵ��������ε���
    for (int subStringLength = 3; subStringLength <= length; subStringLength++){
        for (int subBegin = 0; subBegin <= length - subStringLength; subBegin++){
            int subTail = subBegin + subStringLength - 1;
            if (isPalindrome[subBegin + 1][subTail - 1] && str[subBegin] == str[subTail]){
                isPalindrome[subBegin][subTail] = true;
                maxLength = subStringLength;
            }
        }
    }

    return maxLength;

}

int main()
{
    string str;
    int num = 0;
    cin >> num;
    while (num){
        cin >> str;
        cout << palindromeSubstring(str) << endl;
        num--;
    }

    return 0;
}


