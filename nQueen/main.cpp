/*
 * 第七次上机2题
 * N皇后问题
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
    //从第1行到第row-1行，依次检测是否会冲突
    while (tempRow < row){
        //检测皇后是否与当前行在同一列或者同一斜线，在的话说明冲突
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
            //探测当前行的每一列是否可以放置，如果可以，继续探测下一行
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
    //初始化皇后数组，0位置记录这是第几组解
    queen[0] = 0;
    for (int index = 1; index <= num; index++) queen[index] = -1;

    putQueen(queen, num, 1);


    return 0;
}
