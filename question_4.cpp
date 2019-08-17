//
// Created by chen on 2019/8/5.
//
/*
 * 输出一个矩阵的倒序，
 */

#include <iostream>
#include <cstdio>
using namespace std;

int num[205][205];

int main()
{
    int r,l;
    cin >> r >> l;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < l; ++j) {
            cin >> num[i][j];
        }
    }
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < r; ++j) {
            if(j != r-1 )
            cout << num[r-1-j][i] << " ";
            else
                cout << num[r-1-j][i];
        }
        cout << endl;
    }
    return 0;
}