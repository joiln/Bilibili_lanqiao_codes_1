//
// Created by chen on 2019/8/4.
//
/*
 * 相信小伙伴们都学过斐波那契数列，它是这样的一个数列：1，1，2，3，5，8，13，21…。
用f，表示斐波那契数列的第n项，则有：
fi=f2=1，fn=fn-1+fn-2（n>2）。
输入一个n，求出fn对1000000007（10+7）取模结果。
输入格式
输入一个整数n（1≤n≤100000）。
输出格式
输入
fn mod 1000000007 的值。
样例输入3
 */

//这题就是考取模的知识，大数处理的办法
//10的九次方int和long long 都不能处理
// 所以只能边运算边取模

#include <iostream>
#include <cstdio>
using namespace std;

const int mod = 1e-9;
int num[100005];
int main()
{
    int n;
    num[1] = 1;
    num[2] = 1;
    cin >> n;
    for (int i = 3; i <= n; ++i) {
        num[i] = (num[i-1] + num[i-2])%(mod+7);
    }
    cout << num[n] << endl;
    return 0;
}