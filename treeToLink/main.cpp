/*
 * ��ʮ���ϻ��ڶ���
 * ��������ת���ɵ�����
 * By HXH 2017.12.02
 */


#include <iostream>
#include <stack>
#define null -1 //�������еĽڵ�ֵ������0

using namespace std;

class Node
{
public:
    int data;
    Node* leftChild;
    Node* rightChild;

    Node(int value = null) : data(value), leftChild(NULL), rightChild(NULL) {}
};

class BinTree
{
public:
    Node* root;

    BinTree(int* nodeArray, int nodeNumber)
    {
        root = create(nodeArray, nodeNumber, 0);
    }

private:
    Node* create(int* nodeArray, int nodeNumber, int layer)
    {
        if (layer >= nodeNumber || nodeArray[layer] == null) return NULL;

        Node* tempRoot = new Node(nodeArray[layer]);
        tempRoot->leftChild = create(nodeArray, nodeNumber, 2*layer + 1);
        tempRoot->rightChild = create(nodeArray, nodeNumber, 2*layer + 2);

        return tempRoot;
    }

public:
    void show(Node* tempRoot, int layer)
    {
        if (tempRoot == NULL) return ;

        show(tempRoot->rightChild, layer + 3);
        for (int index = 0; index < layer; index++) cout << " ";
        cout << tempRoot->data << endl;
        show(tempRoot->leftChild, layer + 3);
    }

    //�ݹ�ʵ�����������ת��
    Node* toLink(Node* tempRoot)
    {
        if (tempRoot == NULL) return NULL;

        //ת����������
        Node* leftLink = toLink(tempRoot->leftChild);
        Node* rightLink = toLink(tempRoot->rightChild);

        //��ת���õ�����������ƴ������
        if(leftLink){
            Node* currentNode = leftLink;
            //�������Ѿ�ת��Ϊһ���ǿյ�����������ƴ�ӵ�������ĩβ
            while (currentNode->rightChild) currentNode = currentNode->rightChild;
            currentNode->rightChild = rightLink;
            //��ת���õ��������ӵ���ǰroot���Һ���ָ���ϣ���������ָ����Ϊ��
            tempRoot->rightChild = leftLink;
            tempRoot->leftChild = NULL;
        }

        return tempRoot;
    }

    /*
     *�ǵݹ�ʵ�֣�������ת��Ϊ������
     *������������Ľ����֪���յ�����϶��ǣ���-����-����
     *����������ͷ����Ȼ�������������ҽڵ����
     *ͬ�������������������������Ҳ��һ�µ�
     *��������ԭ�����ϵ����������Ĺ���λ��
     *��֤��ʱ�̹��ص�����ǰ�������ǰ���ڵ����ָ���ϼ���
     *�ȼ���Ŀǰֻ�и��ڵ㣬�����ӣ��Լ��Һ�����Ҫ�������������¹��أ����������root�ڵ�
     *Ȼ��任root�ڵ�Ϊ��ǰ�����õĽڵ����һ���ڵ㣬�ظ���������
     *������϶����Դ˵�����ÿ���ڵ㣬��������
     */
    void toLink()
    {
        if (! root) return ;

        Node* tempRoot = root;
        while (tempRoot){
            if (tempRoot->leftChild){
                Node* preNode = tempRoot->leftChild;
                //Ѱ��ǰ���ڵ�
                while (preNode->rightChild) preNode = preNode->rightChild;
                preNode->rightChild = tempRoot->rightChild;
                tempRoot->rightChild = tempRoot->leftChild;
                tempRoot->leftChild = NULL;
            }
            //�������ϵ�����tempRoot�����һ��ֻ���������Ľڵ㣬��ô���������е�λ�ñ�ȷ����
            tempRoot = tempRoot->rightChild;
        }
    }

    //���ת���������
    void printLink()
    {
        Node* tempNode = root;
        while (tempNode){
            cout <<  tempNode->data << " ";
            tempNode = tempNode->rightChild;
        }
        cout << endl;
    }
};

int main()
{

    int number = 0;
    cin >> number;
    int inputArray[number];
    for (int index = 0; index < number; index++) cin >> inputArray[index];
    BinTree tree(inputArray, number);
    tree.show(tree.root, 0);
    //tree.toLink(tree.root);
    tree.toLink();
    tree.printLink();

    return 0;
}
