//
// Created by chen on 2019/7/30.
//

#include <iostream>
#include <algorithm>

using namespace std;
//从大到小排
bool cmp(int x,int y)
{
    return x > y;
}
int num[10];

int main()
{
    int n;
    for (int i = 0; i < 10; ++i) {
        cin >> num[i];
    }
    sort(num,num+10,cmp);
    for (int j = 0; j < 10; ++j) {
        cout << num[j] << " ";
    }
    cout << endl;
    return 0;
}



