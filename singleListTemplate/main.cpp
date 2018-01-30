#include <iostream>
#include <string>
#include "singleList.h"

using namespace std;

int main()
{
    List<int> singleList;
    char action;
    bool flag = true;
    int temp = 0;

    while(flag){
        cin >> action;

        switch (action)
        {
        case 'a':
            cin >> temp;
            if (singleList.add(temp)) cout << "true" << endl;
            else cout << "false" << endl;
            break;

        case 'r':
            cin >> temp;
            if (singleList.remove(temp)) cout << "true" << endl;
            else cout << "false" << endl;
            break;

        case 'f':
            cin >> temp;
            if (singleList.find(temp)) cout << "true" << endl;
            else cout << "false" << endl;
            break;

        case 'p':
            singleList.printList();
            break;

        default:
            flag = false;
            break;
        }

    }

    return 0;
}
