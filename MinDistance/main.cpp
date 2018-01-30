/*
* By HXH 2017.10.22
*/

#include <iostream>
#define MaxSize 1000

using namespace std;

void minDistance(char str1[], int length1, char str2[], int length2)
{
    // 创建距离数组，动态分分配空间
    int** distance = new int*[length1 + 1];
    for (int index = 0; index <= length1; index++){
        distance[index] = new int[length2 + 1];
    }

    // 先计算其中一个字符串为空的时候对应的最小修改距离
    for (int index = 0; index <= length1; index++){
        distance[index][0] = index;
    }
    for (int index = 0; index <= length2; index++){
        distance[0][index] = index;
    }

    // 计算两个字符串都不为空时的距离
    int dist1 = 0, dist2 = 0, dist3 = 0, temp = 0;
    for (int index1 = 1; index1 <= length1; index1++){
        for (int index2 = 1; index2 <= length2; index2++){
            // 从左上方变成当前状态的修改的距离
            dist1 = distance[index1 - 1][index2 - 1] + (str1[index1] == str2[index2] ? 0 : 1);
            // 从正上方修改到当前状态的修改距离
            dist2 = distance[index1 - 1][index2] + 1;
            // 从左边修改到当前状态的修改距离
            dist3 = distance[index1][index2 - 1] + 1;
            // 选出三种变换方式的距离中的最小距离
            temp = dist1 < dist2 ? dist1 : dist2;
            distance[index1][index2] = temp < dist3 ? temp : dist3;
        }
    }

    cout << "The minmum distance: " << distance[length1][length2] << endl;
}

int main()
{
    char word1[MaxSize] = "", word2[MaxSize] = "";
    int length1 = 0, length2 = 0;

    cin >> word1;
    cin >> word2;
    while (word1[length1]) length1++;
    while (word2[length2]) length2++;

    minDistance(word1, length1, word2, length2);

    return 0;
}
