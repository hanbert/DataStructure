/*
 * 第六周上机实验第一题
 * 组合括号
 * 将左右括号分别入栈，类比成二叉树的中序遍历
 * 右括号入栈前，必须保证栈内，左括号多于右括号
 * By HXH 2017.11.02
 */


#include <iostream>

using namespace std;

void validBrackets(int left, int right, char *brackets, int top)
{
    if (left == 0 && right == 0){
        for (int index = 0; index < top; index++) cout << brackets[index] << " ";
        cout << endl;
    }
    else {
        if (left){
            brackets[top] = '(';
            validBrackets(left - 1, right, brackets, top + 1);
        }
        if (right && right > left){ //保证栈内左括号多于右括号
            brackets[top] = ')';
            validBrackets(left, right - 1, brackets, top + 1);
        }
    }
}

int main()
{
    int num = 0;
    cin >> num;
    char brackets[2 * num] = {'\0'};

    validBrackets(num, num, brackets, 0);

    return 0;
}
