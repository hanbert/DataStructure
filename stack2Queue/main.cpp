/*
 * ���ߴ��ϻ�1��
 * ������ջ��ɶ���
 * By HXH 2017.11.12
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

template<typename Type> class Queue
{
private:
    stack<Type> inStack, outStack;

public:
    Queue(){}
    ~Queue(){}

    //���
    bool add(Type elem);
    //����
    bool poll();
    //�п�
    bool peek();
    //���
    void printQueue();
};

template<typename Type> bool Queue<Type>::add(Type elem)
{
    inStack.push(elem);

    return true;
}

template<typename Type> bool Queue<Type>::poll()
{
    if (outStack.empty()){
        while (! inStack.empty()){
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
    outStack.pop();

    return true;
}

template<typename Type> bool Queue<Type>::peek()
{
    if (inStack.empty() && outStack.empty()) return true;

    return false;
}

template<typename Type> void Queue<Type>::printQueue()
{
    stack<Type> tempStack;

    if (! outStack.empty()){
        while (! outStack.empty()){
            cout << outStack.top() << " ";
            tempStack.push(outStack.top());
            outStack.pop();
        }
    }
    if (! inStack.empty()){
        while (! inStack.empty()){
            outStack.push(inStack.top());
            inStack.pop();
        }
        while (! outStack.empty()){
            cout << outStack.top() << " ";
            inStack.push(outStack.top());
            outStack.pop();
        }
    }
    if (! tempStack.empty())
        while (! tempStack.empty()){
            outStack.push(tempStack.top());
            tempStack.pop();
        }
    cout << endl;
}

int main()
{
    Queue<int> stackQueue;
    string action = "";
    int value = 0;
    bool flag = true;

    while (flag){
        cin >> action;

        if (action == "add"){
            cin >> value;
            if (stackQueue.add(value)) cout << "True" << endl;
            else cout << "False" << endl;
        }
        else if (action == "poll"){
            if (stackQueue.poll()) cout << "True" << endl;
            else cout << "False" << endl;
        }
        else if (action == "print")
            stackQueue.printQueue();
        else if (action == "peek"){
            if (stackQueue.peek()) cout << "True" << endl;
            else cout << "False" << endl;
        }
        else flag = false;
    }

    return 0;
}
