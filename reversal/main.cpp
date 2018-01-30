/*
By HXH 2017.09.30
*/
#include <iostream>
#define MAX_SZIE 10000

using namespace std;

class List;

class LinkNode{
    friend class List;
private:
    int data;
    LinkNode *link;

public:
    int getData(){
        return data;
    }
    LinkNode* getLink(){
        return link;
    }
};

class List{
private:
    LinkNode *first, *current;

public:
    List(int *arry, int num);

    LinkNode* getCurrent(){
        return current;
    }

    LinkNode* getFirst(){
        return first;
    }

    LinkNode* reversal(LinkNode *currNode, int k);
};

//主函数
int main()
{
    int num = 0, k = 0, arry[MAX_SZIE] = {0};
    bool flag = true;

    cin >> num >> k;
    for(int index = 0; index < num; index++) cin >> arry[index];

    List linkList(arry, num);
    LinkNode *current = NULL, *tempNode = NULL;

    current = linkList.getFirst();
    tempNode = current;
    for(int index = 1; index < k; index++)
        if(tempNode->getLink() == NULL) flag = false;
    while(flag){
        current = linkList.reversal(current, k);
        tempNode = current;
        for(int index = 1; index <= k; index++){
            if(tempNode->getLink() == NULL){
                flag = false;
                break;
            };
            tempNode = tempNode->getLink();
        }

    }

    current = linkList.getFirst();
    cout << "Link list after exchange: " << endl;
    cout << current->getData() << " ";
    while(current->getLink() != NULL){
        cout << current->getLink()->getData() << " ";
        current = current->getLink();
    }
    cout << endl;

    return 0;
}


//类函数实现
List::List(int *arry, int num){ //链表初始化

    first = new LinkNode();
    first->data = arry[0];
    first->link = NULL;
    current = first;

    for(int index = 1; index < num; index++){
        current->link = new LinkNode();
        current->link->data = arry[index];
        current->link->link = NULL;
        current = current->link;
    }
    current = first;

    cout << "Link list before exchange: " << endl;
    cout << current << ": " << current->data << " | ";
    while(current->link != NULL) {
        cout << current->link << ": " << current->link->data << " | ";
        current = current->link;
    }
    cout << endl;
}

LinkNode* List::reversal(LinkNode *currNode, int k){ //反转每k个节点
    LinkNode *head = NULL, *tail = NULL, *preNode = NULL, *postNode = NULL, *tempNode = NULL;

    tempNode = currNode;
    for(int index = 1; index < k; index++) tempNode = tempNode->link;

    if(currNode == first){
        head = currNode;
        tail = tempNode;
        first = tempNode;
        preNode = currNode;
        currNode = currNode->link;
        postNode = currNode->link;
        head->link = tail->link;
        while(currNode != head->link){
            currNode->link = preNode;
            preNode = currNode;
            currNode = postNode;
            if(postNode != NULL) postNode = postNode->link;
        }
    }
    else{
        head = currNode->link;
        tail = tempNode->link;
        preNode = currNode;
        currNode = currNode->link;
        postNode = currNode->link;
        head->link = tail->link;
        preNode->link = tail;
        preNode = currNode;
        currNode = postNode;
        postNode = postNode->link;
        while(currNode != head->link){
            currNode->link = preNode;
            preNode = currNode;
            currNode = postNode;
            if(postNode != NULL) postNode = postNode->link;
        }
    }

    tempNode = first;

    cout << "Link list after exchange: " << endl;
    cout << tempNode << " " << tempNode->data << " | ";
    while(tempNode->link != NULL) {
        cout << tempNode->link << ": " << tempNode->link->data << " | ";
        tempNode = tempNode->link;
    }
    cout << endl;

    return head;
}
