//
// Created by chen on 2019/8/5.
//

//求最大子矩阵
/*
给定一个n×m的矩阵A，求A中的一个非空子矩阵，
使这个子矩阵中的元素和最大。其中，A的子矩阵指在A中行和列均连续的一部分。
输入格式
输入的第一行包含两个整数n，m（1≤n，m≤50），分别表示矩阵A的行数和列数。
接下来n行，每行m个整数，表示矩阵A.，（-1000≤Ai，≤1000）。
输出格式
输出一行，包含一个整数，表示A中最大子矩阵的元素和。
 */

//求一个和最大的，我们可以用枚举来解决

#include <iostream>
#include <cstdio>
using namespace std;

int a[55][55];

int main()
{
    int n,m,ans;                        //一共有n行，m列，ans用记录和的结果；
    cin >> n >> m;
    ans = -1005;                        //由于最后的结果可能
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <m; ++j) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++)                                          //以下四个for循环实在暴力遍历找出所有的子矩阵
    {
        for (int j = i;j < n; j++)
        {
            for (int k = 0; k < m; ++k)
            {
                for (int l = k; l < m; ++l)
                {
                    //把子矩阵中所有元素加起来，
                    int temp = 0;   //暂时储存运算结果，来和ans比较，避免零矩阵的情况
                    for (int p = i; p <= j; p++)                        //i代表的是子矩阵行的起点，j代表的是子矩阵行的终点
                    {
                        for(int q = k; q <= l; q++)                     //k代表的是子矩阵列的起点，j代表的是子矩阵列的终点
                        {
                          temp += a[p][q];
                        }
                    }
                    //如果temp比ans的值大，就把结果赋给ans，
                    if(temp > ans)
                        ans = temp;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;

}

