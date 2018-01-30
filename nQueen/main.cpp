/*
 * ���ߴ��ϻ�2��
 * N�ʺ�����
 * By HXH 2017.11.12
 */

#include <iostream>
#include <cmath>

using namespace std;

void showResult(int* queen, int num)
{
    queen[0]++;
    cout << "\n========= The " << queen[0] << "th Result =========\n" << endl;

    for (int row = 1; row <= num; row++){
        for (int col = 1; col <= num; col++){
            if (queen[row] != col) cout << "  *";
            else cout << "  @";
        }
        cout << '\n' << endl;
    }
}

bool isValid(int* queen, int row, int col)
{
    int tempRow = 1;
    //�ӵ�1�е���row-1�У����μ���Ƿ���ͻ
    while (tempRow < row){
        //���ʺ��Ƿ��뵱ǰ����ͬһ�л���ͬһб�ߣ��ڵĻ�˵����ͻ
        if (queen[tempRow] == col || abs(tempRow - row) == abs(queen[tempRow] - col)) return false;
        tempRow++;
    }
    return true;
}

void putQueen(int* queen, int num, int row)
{
    if (row > num) showResult(queen, num);
    else {
        for (int tempCol = 1; tempCol <= num; tempCol++){
            //̽�⵱ǰ�е�ÿһ���Ƿ���Է��ã�������ԣ�����̽����һ��
            if (isValid(queen, row, tempCol)){
                queen[row] = tempCol;
                putQueen(queen, num, row + 1);
            }
        }
    }
}

int main()
{
    int num;
    cout << "Please input the number of queens: ";
    cin >> num;
    int queen[num];
    //��ʼ���ʺ����飬0λ�ü�¼���ǵڼ����
    queen[0] = 0;
    for (int index = 1; index <= num; index++) queen[index] = -1;

    putQueen(queen, num, 1);


    return 0;
}
