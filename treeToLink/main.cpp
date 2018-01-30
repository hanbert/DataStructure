/*
 * 第十次上机第二题
 * 将二叉树转换成单链表
 * By HXH 2017.12.02
 */


#include <iostream>
#include <stack>
#define null -1 //假设树中的节点值都大于0

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

    //递归实现树到链表的转换
    Node* toLink(Node* tempRoot)
    {
        if (tempRoot == NULL) return NULL;

        //转换左右子树
        Node* leftLink = toLink(tempRoot->leftChild);
        Node* rightLink = toLink(tempRoot->rightChild);

        //将转换好的左右子链，拼接起来
        if(leftLink){
            Node* currentNode = leftLink;
            //左子树已经转换为一个非空的链表，右子树拼接到该链表末尾
            while (currentNode->rightChild) currentNode = currentNode->rightChild;
            currentNode->rightChild = rightLink;
            //将转换好的左链连接到当前root的右孩子指针上，并将左孩子指针置为空
            tempRoot->rightChild = leftLink;
            tempRoot->leftChild = NULL;
        }

        return tempRoot;
    }

    /*
     *非递归实现，二叉树转换为单链表
     *根据先序遍历的结果可知最终的链表肯定是：根-左链-右链
     *并且右链的头结点必然在左子树的最右节点后面
     *同样，在左子树和右子树的情况也是一致的
     *依据以上原理，不断调整右子树的挂载位置
     *保证其时刻挂载到它的前序遍历的前驱节点的右指针上即可
     *先假设目前只有根节点，其左孩子，以及右孩子需要调整，进行重新挂载，便调整好了root节点
     *然后变换root节点为当前调整好的节点的下一个节点，重复上述过程
     *最后，自上而下以此调整好每个节点，即得链表
     */
    void toLink()
    {
        if (! root) return ;

        Node* tempRoot = root;
        while (tempRoot){
            if (tempRoot->leftChild){
                Node* preNode = tempRoot->leftChild;
                //寻找前驱节点
                while (preNode->rightChild) preNode = preNode->rightChild;
                preNode->rightChild = tempRoot->rightChild;
                tempRoot->rightChild = tempRoot->leftChild;
                tempRoot->leftChild = NULL;
            }
            //经过以上调整，tempRoot变成了一个只有右子树的节点，那么其在链表中的位置便确定了
            tempRoot = tempRoot->rightChild;
        }
    }

    //输出转换后的链表
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
