//
// Created by chen on 2019/8/5.
//

/*
 * 随机数和去重
蒜头君想在学校中请一些同学一起做一项问卷调查，为了确保实验的客观性，他先用计算机生成了n（1≤n≤100）个1到1000之间的随机整数，对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。
请你协助蒜头君完成“去重”与“排序”的工作。
输入格式
共两行，第一行为一个正整数n。
第二行有n个用空格隔开的正整数，为所产生的随机数。
 */
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;
int num[1005],ans[1005];
int main()
{
    int n,m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin  >> num[i];
    }
    sort(num,num + n);
    m = 0;
    for (int j = 0; j < n; ++j) {
        if(j != 0 && num[j] != num[j-1] )
        ans[m++] = num[j-1];
    }
    ans[m++]  = num[n-1];
    cout << m <<endl;
    for (int k = 0; k < m; ++k) {
        if(k != m-1)
            cout << ans[k] << " ";
        else
            cout << ans[k];
    }
    return 0;
}
