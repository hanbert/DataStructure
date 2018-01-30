/*
By HXH 2017.09.25
*/

#include <iostream>
#include <string>
#define MAX_SIZE 10000

using namespace std;

int main()
{
    string integer[MAX_SIZE];
    string temp;
    int n = 0, k = 0, counter = 0, maxIndex = 0;
    int head = 0, tail = 0;

    cin >> n >> k;
    tail = n;
    while(head < tail){
        cin >> temp;
        if(temp.substr(0,1) == "-")
            integer[head++] = temp.substr(1); //È¥³ý¡°-¡±ºÅ
        else integer[--tail] = temp;
    }

    while(counter <= k){
        maxIndex = n - counter - 1;
        if(maxIndex >= tail){
            for(int index = maxIndex - 1; index >= tail; index--){
                if(integer[index].size() > integer[maxIndex].size()) maxIndex = index;
                else if(integer[index].size() == integer[maxIndex].size() && integer[index] > integer[maxIndex]) maxIndex = index;
            }
            temp = integer[n - counter - 1];
            integer[n - counter - 1] = integer[maxIndex];
            integer[maxIndex] = temp;
            counter++;
        }
        else{
            for(int index = maxIndex - 1; index >= 0; index--){
                if(integer[index].size() < integer[maxIndex].size()) maxIndex = index;
                else if(integer[index].size() == integer[maxIndex].size() && integer[index] < integer[maxIndex]) maxIndex = index;
            }
            temp = integer[n - counter - 1];
            integer[n - counter - 1] = integer[maxIndex];
            integer[maxIndex] = temp;
            counter++;
        }
    }

    counter = 1;
    while(counter <= k){
        if(n - counter >= tail)
            cout << integer[n - counter] << " ";
        else cout << "-" << integer[n - counter] << " ";
        counter++;
    }
    cout << endl;
    return 0;
}
