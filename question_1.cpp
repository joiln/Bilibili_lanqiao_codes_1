//
// Created by chen on 2019/8/2.
//

/*
 * 我们有N个正浮点数，均小于10000.0。现在需要将这些浮点数按照离它最近的整数的差从小到大排序，浮点数与距离最近的整数的差越小，这个浮点数的排位越靠前；如果差相等，按照浮点数的值从小到大排序。
判断浮点数相等应该使用如下语句：
1   if（fabs（a-b）<EPSILON）{
2   //执行当两个浮点数a和b相等时的操作3}
其中EPSILON为常量，大小为10-6。
输入格式
输入有2行
·第一行为一个整数N，0<N<101；
·第二行为用空格隔开的N个正浮点数，均小于10000.0。
输出格式
输出有1行，为按照题目要求排序后的N个正浮

 */
/*
 * 我们常用EPSILON来调整误差，它是一个常值大小为e的-6次方
 *
 * 但两个数的差值小于EPSILON时，就认为这两个数是相等或者是同一个数。
 *
 * 小数
 小数可分为两种格式类型，一种是定点表示“ios::fixed”（不带指数域），
 另一种是科学计数法表示“ios::scientific”（带指数域）。
 与<iomanip>的setprecision配合使用，
 可以表示指定小数点后面的保留位数（四舍五入）

 需要注意的是，有时会因为机器的精度问题导致四舍五入的结果不正确。这种问题一般需要手动修正，代码如下
 cout << fixed << setprecision(1) << 2.05 + 1e-8 << endl;
 */

#include <cstdio>
#include <iostream>
#include <iomanip>  //cout来进行小数点后位数，要导入iomanip，使用其中的setprecision
#include <algorithm>
#include <cmath>
using namespace std;
const double EPSILON = 1e-6;
double num[105];

bool cmp(double a, double b)
{
    double da = fabs((a-round(a)));
    double db = fabs((b-round(b)));
    if(fabs(da-db) < EPSILON)
    {
        return a < b;
    } else
    {
        return da < db;
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    for (int i = 0; i < N; ++i) {
        scanf("%lf",&num[i]);

    }
    sort(num,num + N,cmp);
    for (int j = 0; j < N; ++j) {
        if(j != N - 1)
        {
            //printf("%.6lf ",num[j]);
            cout.setf(ios::fixed);          //fixed表示不带指数域，若要用指数域则使用scientific
            cout << setprecision(6) << num[j] << " ";
        }
        else
            //printf("%.6lf",num[j]);
            cout << setprecision(6) << num[j];
    }
    return 0;
}