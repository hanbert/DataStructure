/*
 * ��ʮ���ϻ�
 * �����������С�������ڵ�
 * By HXH 2017.12.02
 */

#include <iostream>
#define null -1

using namespace std;

class Node
{
public:
    int data;
    Node* leftChild;
    Node* rightChild;

    //���캯��
    Node(int value = null) : data(value), leftChild(NULL), rightChild(NULL) {}
};

class BinTree
{
public:
    Node* root;

    //���캯��
    BinTree(int* nodeArray, int numberNode)
    {
        root = create(nodeArray, numberNode, 0);
    }

    //�����鴴�����������ݹ�
    Node* create(int* nodeArray, int numberNode, int layer)
    {
        if (layer >= numberNode || nodeArray[layer] == null) return NULL;

        Node* tempRoot  = new Node(nodeArray[layer]);
        tempRoot->leftChild = create(nodeArray, numberNode, 2*layer + 1);
        tempRoot->rightChild = create(nodeArray, numberNode, 2*layer + 2);

        return tempRoot;
    }
    //��ʾ������
    void show(Node* tempRoot, int layer)
    {
        if (tempRoot == NULL) return;

        show(tempRoot->rightChild, layer + 3);
        for (int index = 0; index < layer; index++) cout << " ";
        cout << tempRoot->data << endl;
        show(tempRoot->leftChild, layer + 3);
    }
    //Ѱ����С�������ڵ�
    Node* minCommonParent(Node* tempRoot, int node1, int node2)
    {
        //�ݹ����
        if (tempRoot == NULL || tempRoot->data == node1 || tempRoot->data == node2) return tempRoot;

        Node* leftSubTree = minCommonParent(tempRoot->leftChild, node1, node2);
        Node* rightSubTree = minCommonParent(tempRoot->rightChild, node1, node2);

        //��ǰ�ڵ��������������Ϊ�գ���˵�������������ڵ��ڵ�ǰ�ڵ������������
        //��ǰ�ڵ㼴Ϊ����С�������ڵ�
        if (leftSubTree && rightSubTree) return tempRoot;
        //��������Ϊ��ʱ��˵�������ڵ㶼���������������У��ڵĻ����������������ڷ���NULL
        if (leftSubTree == NULL) return rightSubTree;
        //�����������յ�ʱ�����������Ϊ�գ�����������
        if (rightSubTree == NULL)  return leftSubTree;

        return NULL;
    }
};

int main()
{

    int number = 0;
    cin >> number;
    int inputArray[number];
    for (int index = 0; index < number; index++) cin >> inputArray[index];
    BinTree binTree(inputArray, number);
    cout << endl;
    binTree.show(binTree.root, 0);
    cout << endl;
    int node1 = -1, node2 = -1;
    cin >> node1 >> node2;
    Node* commonParent = binTree.minCommonParent(binTree.root, node1, node2);
    cout <<  commonParent->data << endl;

    return 0;
}
