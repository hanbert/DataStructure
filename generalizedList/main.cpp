/*
 * ��������ҵ3��
 * �ж������������ȵĵݹ��㷨
 * By HXH 2017.11.08
 */

#include <iostream>
#define HEAD 0 //��ʾͷ���
#define DATA 1 //��ʾ���ݽڵ�
#define LIST 2 //��ʾ�ӱ�ڵ�

using namespace std;

template<typename Type> class GenList;
template<typename Type> class GenListNode{
    friend class GenList<Type>;
private:
    int tag; //ȡֵΪ 0/1, �ֱ��ʾ�����ݣ������ӱ�
    GenListNode *link;
    union{
        Type value; //tag = DATA��������ݵ�ֵ
        GenListNode *dlink; //tag = LIST�������ָ���ӱ��ָ��
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
    GenListNode<Type> *head, *tail; //�����ͷָ��

    GenList(){tail = head = NULL;};
    ~GenList(){};
    void createList(int num);
    bool Equal(GenListNode<Type> *s, GenListNode<Type> *t);
};

template<typename Type> void GenList<Type>::createList(int num)
{
    int counter = 0;
    //����ͷ���
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


template<typename Type> bool GenList<Type>::Equal(GenListNode<Type> *s, GenListNode<Type> *t) //s��tΪ2��������ͷ���
{
    bool flag = false;

    if (s->link == NULL && t->link == NULL) return 1;
    if (s->link != NULL && t->link != NULL && s->link->tag == t->link->tag){
        if (s->link->tag == DATA){
            if (s->link->data.value == t->link->data.value) flag = true; //�Ƚ����ݽڵ��Ƿ���ͬ
            else flag = false;
        }
        else flag = Equal(s->link->data.dlink, t->link->data.dlink); //�ݹ飬�ж����ӱ��Ƿ����

        if (flag) return Equal(s->link, t->link); //�ݹ飬��ǰ�ڵ����ݽڵ���ӱ�ڵ㶼���ʱ���Ƚ���һ���ڵ�
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











