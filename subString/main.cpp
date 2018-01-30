/*
 * 第五周上机第二题
 * 最长回文子串
 * By HXH 2017.10.30
 */

#include <iostream>
#include <string>
#define MaxSize 30

using namespace std;

//动态规划
int palindromeSubstring2(string &str)
{
    int length = str.size(), maxLength = 0;
    bool isPalindrome[MaxSize][MaxSize] = {false}; //标记从i到j的子串是否为回文子串，1表示是，0表示不是

    //初始化标记数组,考虑子串长度为奇数和为偶数两种情况，两种情况的i+1和j-1子串是不同的，分别对应为1和2进行初始化
    for (int index = 0; index < length; index++){
        //单个字符肯定满足条件
        isPalindrome[index][index] = true;
        //先找出长度为2的满足回文的子串
        if (index < length - 1 && str[index] == str[index + 1])
        {
            isPalindrome[index][index + 1] = true;
            maxLength = 2;
        }
    }
    //从子串长度为3开始查找满足回文的子串，子串长度依次递增
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


