/*
* By HXH 2017.10.22
*/

#include <iostream>
#define MaxSize 1000

using namespace std;

void minDistance(char str1[], int length1, char str2[], int length2)
{
    // �����������飬��̬�ַ���ռ�
    int** distance = new int*[length1 + 1];
    for (int index = 0; index <= length1; index++){
        distance[index] = new int[length2 + 1];
    }

    // �ȼ�������һ���ַ���Ϊ�յ�ʱ���Ӧ����С�޸ľ���
    for (int index = 0; index <= length1; index++){
        distance[index][0] = index;
    }
    for (int index = 0; index <= length2; index++){
        distance[0][index] = index;
    }

    // ���������ַ�������Ϊ��ʱ�ľ���
    int dist1 = 0, dist2 = 0, dist3 = 0, temp = 0;
    for (int index1 = 1; index1 <= length1; index1++){
        for (int index2 = 1; index2 <= length2; index2++){
            // �����Ϸ���ɵ�ǰ״̬���޸ĵľ���
            dist1 = distance[index1 - 1][index2 - 1] + (str1[index1] == str2[index2] ? 0 : 1);
            // �����Ϸ��޸ĵ���ǰ״̬���޸ľ���
            dist2 = distance[index1 - 1][index2] + 1;
            // ������޸ĵ���ǰ״̬���޸ľ���
            dist3 = distance[index1][index2 - 1] + 1;
            // ѡ�����ֱ任��ʽ�ľ����е���С����
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
