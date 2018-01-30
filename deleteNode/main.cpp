/*
 * 第十一次上机1题
 * 删除二叉搜索树中大于指定值得节点
 * By HXH 2017.12.07
 */

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* leftChild;
    Node* rightChild;

    Node(int data = -1) : data(data), leftChild(NULL), rightChild(NULL){}
};

class searchTree
{
public:
    Node* root;

    searchTree(int* preOrder, int* midOrder, int numberNode)
    {
        root = create(preOrder, midOrder, 0, 0, numberNode - 1, numberNode);
    }
    create(int* preOrder, int* midOrder, int preIndex, int midStart, int midEnd, int numberNode)
    {
        if (preIndex < numberNode){
            Node* tempRoot = new Node(preOrder[preIndex]);
            if (int index = 0; index < numberNode; index++){


            }
        }

    }


};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
