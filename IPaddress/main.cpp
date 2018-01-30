/*
* By HXH 2017.10.22
*/

#include <iostream>
#include <vector>
#define MaxSize 1000

using namespace std;

// ����ȫ�ֱ���������Ϸ���IPv4��ַ
vector<string> result;
int numValidIP;

// �жϷָ������Ƭ���Ƿ�Ϸ�
bool isVaild(char str[], int num, int layer)
{

    // �����ǰ������ַ���λ��������[1,3]֮�䣬˵���˶ε�ַ���Ϸ�
    if (num < 1 || num > 3) return false;

    // �����IP��ַ�ĵ�һ�Σ������ԡ�0����ͷ
    if (layer == 1 && str[0] == '0') return false;

     // �����IP��ַ��λ������1�������ԡ�0����ͷ
    if (num > 1 && str[0] == '0') return false;

    // �ж�ÿһλ�����Ƿ�Ϸ�
    if (str[0] >= '0' && str[0] <= '2'){
        for (int index = 1; index < num; index++)
            if (str[index] < '0' || str[index] > '5') return false;
        return true;
    }

    return false;
}

// �ݹ��ѯ�Ϸ���IPv4��ַ��
int IPSegment(char str[], int length, int start, int tail, int layer)
{
    char temp[4] = "";
    int num = 0;
    num = tail - start;

    //��ǰnum���ַ��������ж����Ƿ�Ϸ�
    if (tail <= length)
        for (int index = start; index < tail; index++) temp[index - start] = str[index];
    else return 0;

    if (! isVaild(temp, num, layer)) return 0;
    temp[num] = '\0';
    result.push_back(temp);

    // ��Ե�4��IP��ַ�ε��ж�����������ҵ��˺Ϸ���ַ��������û���ҵ��Ϸ���ַ�������ϲ�
    if (layer == 4 && tail == length){
        for (vector<string>::iterator iter = result.begin(); iter < result.end(); iter++)
            cout << *iter << ".";
        cout << "\b" << " " << endl;
        numValidIP++;
        result.pop_back();
        return 1;
    }
    else if (layer == 4 && tail < length){
        result.pop_back();
        return 0;
    }

    IPSegment(str, length, tail, tail + 1, layer + 1);
    IPSegment(str, length, tail, tail + 2, layer + 1);
    IPSegment(str, length, tail, tail + 3, layer + 1);

    result.pop_back();

    return 2;
}

int main()
{
    char str[MaxSize] = "";
    int layer = 1;
    int length = 0;

    cin >> str;

    // �ж��ַ����Ƿ����12���������12�޷���ɺϷ���IPv4��ַ
    while (str[length]) length++;
    if (length > 12){
        cout << "No valid IPv4 adress!" << endl;
        return 0;
    }

    IPSegment(str, length, 0, 1, layer);
    IPSegment(str, length, 0, 2, layer);
    IPSegment(str, length, 0, 3, layer);

    if (numValidIP) cout << "Find " << numValidIP << " IPv4 adresses!" << endl;
    else cout << "No valid IPv4 adress!" << endl;

    return 0;
}
















