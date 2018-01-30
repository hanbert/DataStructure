/*
* By HXH 2017.10.22
*/

#include <iostream>
#include <vector>
#define MaxSize 1000

using namespace std;

// 设置全局变量，保存合法的IPv4地址
vector<string> result;
int numValidIP;

// 判断分割出来的片段是否合法
bool isVaild(char str[], int num, int layer)
{

    // 如果当前传入的字符串位数不是在[1,3]之间，说明此段地址不合法
    if (num < 1 || num > 3) return false;

    // 如果是IP地址的第一段，不能以“0”开头
    if (layer == 1 && str[0] == '0') return false;

     // 如果是IP地址段位数大于1，不能以“0”开头
    if (num > 1 && str[0] == '0') return false;

    // 判断每一位数字是否合法
    if (str[0] >= '0' && str[0] <= '2'){
        for (int index = 1; index < num; index++)
            if (str[index] < '0' || str[index] > '5') return false;
        return true;
    }

    return false;
}

// 递归查询合法的IPv4地址段
int IPSegment(char str[], int length, int start, int tail, int layer)
{
    char temp[4] = "";
    int num = 0;
    num = tail - start;

    //将前num个字符读出，判断其是否合法
    if (tail <= length)
        for (int index = start; index < tail; index++) temp[index - start] = str[index];
    else return 0;

    if (! isVaild(temp, num, layer)) return 0;
    temp[num] = '\0';
    result.push_back(temp);

    // 针对第4个IP地址段的判断条件，如果找到了合法地址输出，如果没有找到合法地址，返回上层
    if (layer == 4 && tail == length){
        for (vector<string>::iterator iter = result.begin(); iter < result.end(); iter++)
            cout << *iter << ".";
        cout << "\b" << " " << endl;
        numValidIP++;
        result.pop_back();
        return 1;
    }
    else if (layer == 4 && tail < length){
        result.pop_back();
        return 0;
    }

    IPSegment(str, length, tail, tail + 1, layer + 1);
    IPSegment(str, length, tail, tail + 2, layer + 1);
    IPSegment(str, length, tail, tail + 3, layer + 1);

    result.pop_back();

    return 2;
}

int main()
{
    char str[MaxSize] = "";
    int layer = 1;
    int length = 0;

    cin >> str;

    // 判断字符串是否大于12，如果大于12无法组成合法的IPv4地址
    while (str[length]) length++;
    if (length > 12){
        cout << "No valid IPv4 adress!" << endl;
        return 0;
    }

    IPSegment(str, length, 0, 1, layer);
    IPSegment(str, length, 0, 2, layer);
    IPSegment(str, length, 0, 3, layer);

    if (numValidIP) cout << "Find " << numValidIP << " IPv4 adresses!" << endl;
    else cout << "No valid IPv4 adress!" << endl;

    return 0;
}
















