//
// Created by chen on 2019/8/8 10:05.
//
/*
 * 10000-99999中不含4数
 */

#include <iostream>
using namespace std;

bool judge(int x)
{
    while (x)
    {
        if(x % 10 == 4)
            return true;
        x  /= 10;
    }
    return false;
}
int main()
{
    int n,m,cnt = 0;
    cin >> n >> m;
    for (int i = n; i <= m; ++i) {
        if(!judge(i))
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}


