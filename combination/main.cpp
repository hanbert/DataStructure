/*
 * 第六周作业
 * 第一题
 * 递归算法 1~m中任取k个数的所有组合
 * By HXH 2017.11.07
 */

#include <iostream>
#define MaxSize 1000

using namespace std;

int resultNum;
int result[MaxSize];

void combination(int startNum, int selectNum, int current, int endNum)
{
    if (selectNum == 0){
        for (int index = 0; index < current; index++){
            cout << result[index] << " ";
        }
        resultNum++;
        cout << endl;

        return;
    }

    if (selectNum > endNum - startNum + 1) return;

    for (int index = startNum; index <= endNum; index++){
        result[current] = index;
        combination(index + 1, selectNum - 1, current + 1, endNum);
    }

}

int main()
{
    int m, k;
    int flag = 1;

    while (flag){
        cin >> m >> k;
        switch (m >= k){

        case 1:
            resultNum  = 0;
            cout << "========== From 1 - " << m << " Select " << k << " Numbers ==========" << endl;
            combination(1, k, 0, m);
            cout << "=================== Total: " << resultNum << " ====================" << endl;
            break;

        case 0:
            cout << "ERROR: k > m, expect k <= m " << endl;
            break;
        }
    }

    return 0;
}
