//
// Created by chen on 2019/8/2.
//
/*
 * 某小学举办了一场校内的信息学竞赛选拔赛。现在同学们的成绩都出来了，负责信息学竞赛的老师需要确定最终选拔赛的获奖名单。
为了鼓励大家，老师希望获奖人数不少于参赛总人数的一半。因此，老师需要确定一个获奖分数线，
 所有得分在分数线及以上的同学可以获奖。在满足上面条件的情况下，老师希望获奖分数线越高越好。
请同学们通过程序设计的方法来解决以上问题，确定获奖分数线和总获奖人数。
    输入格式
第一行为一个整数n表示参赛总人数。
第二行为n个整数，分别表示n（1≤n≤100000）个参赛同学的分数，所有分数都是在0~100之间的整数（含0和100），每两个数之间用一个空格隔开。
输出格式
输出为一行，包括两个整数，分别表示分数线和获奖人数（中间用一个空格隔开）。
样例输入
7
76 71 42 4 27 27 20
样例输出
27 5
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int score[10005];


int main()
{
    int n,cnt;
    cin >> n;
//    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        cin >> score[i];
//        scanf("%d",&score[i]);
    }
    sort(score,score+n,greater<int>());
    cout << score[(n - 1) / 2 ] << " ";
    cnt = 0;
    for (int j = 0; j < n; ++j) {
        if(score[j] >= score[(n - 1) / 2 ])
            cnt++;
        else
            break;
    }
    cout << cnt;
    return 0;
}
