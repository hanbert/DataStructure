/*
 * 第六周作业第2题
 * Ackerman 函数
 * 写出递归和非递归形式
 * By HXH 2017.11.07
 */


#include <iostream>
#include <stack>

using namespace std;

//递归实现形式
unsigned long long int recursiveAckerman(unsigned long long int m, unsigned long long int n)
{
    if (m == 0) return n + 1;
    else if (n == 0) return recursiveAckerman(m - 1, 1);
    else return recursiveAckerman(m - 1, recursiveAckerman(m, n - 1));
}

//非递归实现形式
class Element
{
public:
    unsigned long long int m, n;
    int r; //记录m和n都不为0时，右参数的递归回来的值

    Element(unsigned long long int m, unsigned long long int n)
    {
        this->m = m;
        this->n = n;
        this->r = -1;
    }
    void setValue(unsigned long long int m, unsigned long long int n)
    {
        this->m = m;
        this->n = n;
        this->r = -1;
    }
};

//非递归第一种形式，纯用栈来代替递归
unsigned long long int ackerman(unsigned long long int m, unsigned long long int n)
{
    stack<Element> ackmStack;
    Element elem(m, n);
    ackmStack.push(elem);
    long long temp = -1;

    while (! ackmStack.empty()){
        Element tempElement = ackmStack.top();
        if (tempElement.m == 0){
            temp = tempElement.n + 1;
            ackmStack.pop();
        }
        else if (tempElement.m > 0 && tempElement.n == 0){
            if (temp >= 0){
                ackmStack.pop();
            }
            else {
                elem.setValue(tempElement.m - 1, 1);
                ackmStack.push(elem);
            }
        }
        else {
            if (tempElement.r < 0){
                if (temp >= 0){
                    tempElement.r = temp;
                    temp = -1;
                    ackmStack.pop();
                    elem.setValue(tempElement.m - 1, tempElement.r);
                    ackmStack.push(elem);
                }
                else {
                    elem.setValue(tempElement.m, tempElement.n - 1);
                    ackmStack.push(elem);
                }
            }
            else {
                if (temp >= 0){
                    ackmStack.pop();
                }
            }
        }

    }

    return temp;
}

//非递归实现第二种形式，优化版，只需要m值进栈，n值不断更新
unsigned long long int ackerman2(unsigned long long int m, unsigned long long int n)
{
    stack<unsigned long long int> mStack;
    unsigned long long int temp = 0;

    mStack.push(m);
    while (! mStack.empty()){
        temp = mStack.top();
        mStack.pop();

        if (temp == 0){
            n = n + 1;
        }
        else if (n == 0){
            temp = temp - 1;
            n = 1;
            mStack.push(temp);
        }
        else {
            n = n - 1;
            mStack.push(temp - 1);
            mStack.push(temp);
        }
    }
    return n;
}

int main()
{
    int m = 0, n = 0;
    char action = '\0';
    bool flag  = true;

    while (flag){
        cin >> action;

        switch (action)
        {
        case 'r':
            cin >> m >> n;
            cout << recursiveAckerman(m, n) << endl;
            break;

        case 'a':
            cin >> m >> n;
            cout << ackerman(m, n) << endl;
            break;

        case 'b':
            cin >> m >> n;
            cout << ackerman2(m, n) << endl;
            break;

        default:
            flag = false;
            break;
        }
    }

    return 0;
}

