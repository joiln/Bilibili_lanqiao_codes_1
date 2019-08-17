//
// Created by chen on 2019/8/5.
//进制转换
/*
输入一个十进制数N，将它转换成R进制数输出。
 在10≤R≤16的情况下，用‘A’表示10.
 用'B’表示11，用'C’表示12，用‘D’表示13，
 用E’表示14，用‘F·表示15。输入格式
输入包含两个整数N（N≤10000）和R（2≤R≤16）。
注意，N有可能是负整数。
输出格式
输出一行，表示转换后的数。

 */
#include <iostream>
#include <cstdio>
#include <algorithm>

char num[105];

int main()
{
    int m,N,R,now;
    std::cin >> N >> R;
    if(N < 0){
        std::cout << "-";
        N = -N;
    }
    m = 0;
    while (N)           //转换进制，先求余在，在除，最后倒序输出
    {
        now = N % R;
        if(now <= 9)
        {
            num[m++] = '0' + now; //'0'表示把数字转换成char类型的数字
        }else
        {
            num[m++] = 'A' + now - 10;  //把now转换成大写字母
        }
        N /= R;
    }
    if(m == 0)
    {
        std::cout << 0;
    }
    for (int i = m ; i > 0; i--) {     //进制转换以后要倒序输出，才是转换后的结果。
        std::cout << num[i] << std::endl;
    }
    return 0;
}
