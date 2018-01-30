/*
 * 第十次上机
 * 求二叉树的最小公共父节点
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

    //构造函数
    Node(int value = null) : data(value), leftChild(NULL), rightChild(NULL) {}
};

class BinTree
{
public:
    Node* root;

    //构造函数
    BinTree(int* nodeArray, int numberNode)
    {
        root = create(nodeArray, numberNode, 0);
    }

    //由数组创建二叉树，递归
    Node* create(int* nodeArray, int numberNode, int layer)
    {
        if (layer >= numberNode || nodeArray[layer] == null) return NULL;

        Node* tempRoot  = new Node(nodeArray[layer]);
        tempRoot->leftChild = create(nodeArray, numberNode, 2*layer + 1);
        tempRoot->rightChild = create(nodeArray, numberNode, 2*layer + 2);

        return tempRoot;
    }
    //显示二叉树
    void show(Node* tempRoot, int layer)
    {
        if (tempRoot == NULL) return;

        show(tempRoot->rightChild, layer + 3);
        for (int index = 0; index < layer; index++) cout << " ";
        cout << tempRoot->data << endl;
        show(tempRoot->leftChild, layer + 3);
    }
    //寻找最小公共父节点
    Node* minCommonParent(Node* tempRoot, int node1, int node2)
    {
        //递归出口
        if (tempRoot == NULL || tempRoot->data == node1 || tempRoot->data == node2) return tempRoot;

        Node* leftSubTree = minCommonParent(tempRoot->leftChild, node1, node2);
        Node* rightSubTree = minCommonParent(tempRoot->rightChild, node1, node2);

        //当前节点的左右子树都不为空，则说明搜索的两个节点在当前节点的左右子树中
        //当前节点即为其最小公共父节点
        if (leftSubTree && rightSubTree) return tempRoot;
        //当左子树为空时，说明两个节点都可能在其右子树中，在的话返回右子树，不在返回NULL
        if (leftSubTree == NULL) return rightSubTree;
        //当左子树不空的时候，如果右子树为空，返回左子树
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
