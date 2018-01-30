/*
By HXH 2017.09.28
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

    LinkNode* exchangeNeighbor(LinkNode *currNode);
};

int main()
{
    int num = 0, arry[MAX_SZIE] = {0};
    cin >> num;
    for(int index = 0; index < num; index++) cin >> arry[index];
    List linkList(arry, num);
    LinkNode *current = NULL;

    current = linkList.getFirst();
    while(current->getLink() != NULL && current->getLink()->getLink() != NULL){
        current = linkList.exchangeNeighbor(current);
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

List::List(int *arry, int num){

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
    cout << current->data << " ";
    while(current->link != NULL) {
        cout << current->link->data << " ";
        current = current->link;
    }
    cout << endl;
}

LinkNode* List::exchangeNeighbor(LinkNode *currNode){
    LinkNode *preNode, *postNode;

    if(currNode == first){
        first = currNode->link;
        currNode->link = first->link;
        first->link = currNode;
    }
    else{
        preNode = currNode;
        currNode = currNode->link;
        postNode = currNode->link;
        preNode->link = postNode;
        currNode->link = postNode->link;
        postNode->link = currNode;
    }

    return currNode;
}
