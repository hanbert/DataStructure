/*
 * �ھ����ϻ� ��һ��
 * ��������ÿ���ֵ
 * By HXH 2017.11.25
 */

#include <iostream>
#include <math.h>
#include <queue>
#define null -65535 //����˽ڵ�Ϊ��
#define MAX_SIZE 1000


using namespace std;

class BinaryTree;

class Node
{
    friend class BinaryTree;
public:
    int data;
    Node* leftChild;
    Node* rightChild;

    Node()
    {
        this->leftChild = NULL;
        this->rightChild = NULL;
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
    //���캯��
    BinaryTree(int* dataArray, int num)
    {
        root = createTree(dataArray, num, 0);
    }
    //�����н�����
    Node* createTree (int* dataArray, int num, int rootIndex)
    {
        if (rootIndex >= num || dataArray[rootIndex] == null) return NULL;
        else {
            Node* tempRoot = new Node(dataArray[rootIndex]);
            tempRoot->leftChild = createTree(dataArray, num, 2*rootIndex + 1);
            tempRoot->rightChild = createTree(dataArray, num, 2*rootIndex + 2);
            return tempRoot;
        }
    }
    //�����������
    bool printTree(Node* tempRoot, int layer)
    {
        if (tempRoot == NULL) return false;
        printTree(tempRoot->rightChild, layer + 3);
        for (int index = 0; index < layer; index++){
            cout << " ";
        }
        cout << tempRoot->data << endl;
        printTree(tempRoot->leftChild,layer + 3);

        return true;
    }
    //ǰ��������
    int preOrderSum(Node* tempRoot, int* layerNodeNum, int* layerSum, int layer)
    {
        int layers = 0;
        if (tempRoot == NULL) return 0;
        layerNodeNum[layer]++;
        layerSum[layer] += tempRoot->data;
        int leftLayers = preOrderSum(tempRoot->leftChild, layerNodeNum, layerSum, layer + 1);
        int rightLayers = preOrderSum(tempRoot->rightChild, layerNodeNum, layerSum, layer + 1);
        //ȷ������
        leftLayers > rightLayers ? layers = leftLayers : layers = rightLayers;

        return layers + 1;
    }
    void layerMean()
    {
        int layers = 0;
        int layerNodeNum[MAX_SIZE] = {0};
        int layerSum[MAX_SIZE] = {0};

        layers = preOrderSum(root, layerNodeNum, layerSum, 0);
        //���ֵ
        for (int index = 0; index < layers; index++){
            cout << index << " layer: " << (double)layerSum[index] / (double)layerNodeNum[index] << endl;
        }
    }
};

int main()
{
    int dataArray[MAX_SIZE];
    int numberOfNode = 0;
    cin >> numberOfNode;
    for (int index = 0; index < MAX_SIZE; index++) dataArray[index] = null;
    for (int index = 0; index < numberOfNode; index++) cin >> dataArray[index];
    BinaryTree tree(dataArray, numberOfNode);
    tree.printTree(tree.root, 0);
    tree.layerMean();

    return 0;
}
