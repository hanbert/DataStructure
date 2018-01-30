/*
 * �ھ����ϻ� �ڶ���
 * �������������������й��������
 * ʹ�ú��������֤�������Ƿ���ȷ
 * By HXH 2017.11.26
 */

#include <iostream>
#define MAX_SIZE 1000

using namespace std;

class Node
{
public:
    int data;
    Node* leftChild;
    Node* rightChild;

    Node()
    {
        leftChild = rightChild = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
};

class BinaryTree
{
public:
    Node* root;

    BinaryTree()
    {
        root = NULL;
    }
    BinaryTree(int* preOrder, int* midOrder, int numberNode)
    {
        int preIndex = 0;
        this->root = constructBinaryTree(preOrder, midOrder, preIndex, 0, numberNode - 1);
    }
    //���������
    Node* constructBinaryTree(int* preOrder, int* midOrder, int& preIndex, int midStart, int midEnd)
    {
        if (midEnd < midStart) return NULL; //�������������û����Ԫ�ط���
        Node* tempNode = new Node(preOrder[preIndex]);
        //Ѱ�����������������������
        int rootIndex = midStart;
        while (rootIndex <= midEnd && midOrder[rootIndex] != preOrder[preIndex]) rootIndex++;
        //�ݹ鹹����������
        preIndex++; //��ȡ��һ��ǰ������ֵ
        if (rootIndex <= midEnd){
            tempNode->leftChild = constructBinaryTree(preOrder, midOrder, preIndex, midStart, rootIndex - 1);
            tempNode->rightChild = constructBinaryTree(preOrder, midOrder, preIndex, rootIndex + 1, midEnd);
        }
        return tempNode;
    }
    //�������
    void showTree(Node* tempRoot, int layer)
    {
        if (tempRoot == NULL) return;
        showTree(tempRoot->rightChild, layer + 3);
        for (int index = 0; index < layer; index++) cout << " ";
        cout << tempRoot->data << endl;
        showTree(tempRoot->leftChild, layer + 3);
    }

    //�������
    void postOrderTraverse(Node* tempRoot)
    {
        if (tempRoot == NULL) return;
        postOrderTraverse(tempRoot->leftChild);
        postOrderTraverse(tempRoot->rightChild);
        cout << tempRoot->data << " ";
    }
};

int main()
{
    int preOrder[MAX_SIZE] = {0}, midOrder[MAX_SIZE] = {0};
    int numberNode = 0;
    cin >> numberNode;
    for (int index = 0; index < numberNode; index++) cin >> preOrder[index];
    for (int index = 0; index < numberNode; index++) cin >> midOrder[index];

    BinaryTree binTree(preOrder, midOrder, numberNode);
    cout << endl;
    binTree.showTree(binTree.root, 0);
    cout << endl;
    binTree.postOrderTraverse(binTree.root);
    cout << endl;

    return 0;
}
