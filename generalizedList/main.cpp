/*
 * 第六周作业3题
 * 判断两个广义表相等的递归算法
 * By HXH 2017.11.08
 */

#include <iostream>
#define HEAD 0 //表示头结点
#define DATA 1 //表示数据节点
#define LIST 2 //表示子表节点

using namespace std;

template<typename Type> class GenList;
template<typename Type> class GenListNode{
    friend class GenList<Type>;
private:
    int tag; //取值为 0/1, 分别表示是数据，还是子表
    GenListNode *link;
    union{
        Type value; //tag = DATA，存放数据的值
        GenListNode *dlink; //tag = LIST，存放着指向子表的指针
    }data;

public:
    GenListNode()
    {
        this->tag = HEAD;
        this->data.value = 0;
        this->link = NULL;
    }
    GenListNode(Type value)
    {
        this->tag = DATA;
        this->data.value = value;
        this->link = NULL;
    }
    GenListNode(GenListNode *ptr)
    {
        this->tag = LIST;
        this->data.dlink = ptr;
        this->link = NULL;
    }
    void setNode(Type value)
    {
        this->tag = DATA;
        this->data.value = value;
        this->link = NULL;
    }
    void setNode(GenListNode *ptr)
    {
        this->tag = LIST;
        this->data.dlink = ptr;
        this->link = NULL;
    }
};

template<typename Type> class GenList{
public:
    GenListNode<Type> *head, *tail; //广义表头指针

    GenList(){tail = head = NULL;};
    ~GenList(){};
    void createList(int num);
    bool Equal(GenListNode<Type> *s, GenListNode<Type> *t);
};

template<typename Type> void GenList<Type>::createList(int num)
{
    int counter = 0;
    //生成头结点
    if (head == NULL) tail = head = new GenListNode<Type>();

    Type temp;
    GenListNode<Type>* newNode;
    while (counter < num){
        cin >> temp;
        newNode = new GenListNode<int>(temp);
        tail->link = newNode;
        tail = newNode;
        counter++;
    }
}


template<typename Type> bool GenList<Type>::Equal(GenListNode<Type> *s, GenListNode<Type> *t) //s和t为2个广义表的头结点
{
    bool flag = false;

    if (s->link == NULL && t->link == NULL) return 1;
    if (s->link != NULL && t->link != NULL && s->link->tag == t->link->tag){
        if (s->link->tag == DATA){
            if (s->link->data.value == t->link->data.value) flag = true; //比较数据节点是否相同
            else flag = false;
        }
        else flag = Equal(s->link->data.dlink, t->link->data.dlink); //递归，判断其子表是否相等

        if (flag) return Equal(s->link, t->link); //递归，当前节点数据节点和子表节点都相等时，比较下一个节点
    }

    return false;
}

int main()
{
    GenList<int> genListA, genListB;
    int a = 0, b = 0;
    cin >> a;
    genListA.createList(a);
    cin >> b;
    genListB.createList(b);

    bool flag = false;
    flag = genListA.Equal(genListA.head, genListB.head);
    if (flag) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}











