#include <iostream>
#include <vector>
#include <cstring>
#define MaxSize 1000
#define swap(t, x, y) (t = (x), x = (y), y = (t))

using namespace std;

vector<string> result;

void Permutation(char *str, int strStart, int strEnd)
{
    int index = 0;
    char temp = NULL;

    if(strEnd < 0) return;
    if(strStart == strEnd){
        for(index = 0; index <= strEnd; index++)
            cout << str[index];
        cout << endl;
        result.push_back(str);
    } else {
        for(index = strStart; index <= strEnd; index++){
            swap(temp, str[index], str[strStart]); //将strStart ~ strEnd 中的一个元素固定在第一位
            Permutation(str, strStart + 1, strEnd);
            swap(temp, str[index], str[strStart]); //恢复以前的状态
        }
    }
}


int main()
{
    bool flag = false;
    char str1[] = "ab";
    string str2 = "doaenobase";
    vector<string>::iterator iter;
//    int num = 0, index = 0;
//    cin >> num;
//    cin >> str;
    Permutation(str1, 0, 1);
    for(iter = result.begin(); iter != result.end(); iter++){
        cout << "vector: " << *iter << endl;
        if(str2.find(*iter)) flag = true;
    }

    if(flag) cout << "True";
    else cout << "False";

    return 0;
}
