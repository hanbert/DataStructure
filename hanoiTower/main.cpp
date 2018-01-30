/*
 * �������ϻ�ʵ��
 * ��ŵ���ķǵݹ���ʽ
 * By HXH 2017.11.02
 */

#include <iostream>
#include <stack>

using namespace std;


//״̬�࣬���浱ǰ����״̬
class Stat{

public:
    int num; //��ǰ״̬���ƶ�������Ŀ
    char a, b, c; //��ǰ���ӵ�״̬

    //�����ι��캯��
    Stat(){
        num = 0;
        a = b = c = '\0';
    }
    //���ι��캯��
    Stat(int num, char a, char b, char c){
        num = num;
        a = a;
        b = b;
        c = c;
    }
    //�����Ա��ֵ
    void setValue(int num, char a, char b, char c)
    {
        this->num = num;
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

void hanoi(int num, char a, char b, char c)
{
    stack<Stat> statStack;
    Stat temp;
    temp.setValue(num, a, b, c);

    statStack.push(temp);
    while (!statStack.empty()){
        temp = statStack.top();
        statStack.pop();
        num = temp.num;
        a = temp.a;
        b = temp.b;
        c = temp.c;
        if (num == 1){
            cout << a << " -> " << c << endl;
        }
        else{
            temp.setValue(num - 1, b, a, c);
            statStack.push(temp);
            temp.setValue(1, a, b, c);
            statStack.push(temp);
            temp.setValue(num - 1, a, c, b);
            statStack.push(temp);
        }
    }
}

int main()
{
    int num = 0;
    cin >> num;

    hanoi(num, 'A', 'B', 'C');

    return 0;
}
