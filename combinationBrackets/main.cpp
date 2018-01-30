/*
 * �������ϻ�ʵ���һ��
 * �������
 * ���������ŷֱ���ջ����ȳɶ��������������
 * ��������ջǰ�����뱣֤ջ�ڣ������Ŷ���������
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
        if (right && right > left){ //��֤ջ�������Ŷ���������
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
