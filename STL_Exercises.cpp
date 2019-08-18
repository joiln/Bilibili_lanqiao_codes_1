//
// Created by chen on 2019/8/17 18:09.
//
/*
常用STL练习
 这一部分习题用来练习和熟练vector、map、set的使用。
【程序设计】堆积木
【程序设计】计算集合的并
【程序设计】蒜头君学英语
【程序设计】蒜头君面试
【程序设计】水果店
1.堆积木

蒜头君有n块积木，编号分别为1到n。一开始，蒜头把第i块积木放在位置i。
 蒜头君进行m次操作，每次操作，蒜头把位置 b上的积木整体移动到位置a上面。
 比如1位置的积木是1，2位置的积木是2，那么把位置2的积木移动到位置1后，
 位置1上的积木从下到上依次为1，2。

输入格式
第一行输入2个整数
n，m（1≤n≤10000，0≤m≤10000）。
接下来m行，每行输入2个整数
a，b（1≤a，b≤n），如果a，b相等则本次不需要移动。

输出格式
 输出n行，第i行输出位置i从下到上的积木编号，如果该行没有积木输出一行空行。
样例输入1
2 2
1 2
1 2
样例输出1
1 2
样例输入2
4 4
3 1
4 3
2 4
样例输出2
2 4 3 1

2.计算集合的并
 给你两个集合，计算其并集，即{A}+{B}。注：{4}+{B}中不允许出现重复元素，但是
{A}与{B}之间可能存在相同元素。

输入格式
输入数据分为三行，第一行有两个数字n，m（0<n，m≤10000），
 分别表示集合A和集合B的元素个数。后两行分别表示集合A和集合B。
 每个元素为不超出int范围的整数，每个元素之间用一个空格隔开。

输出格式
输出一行数据，表示合并后的集合，要求从小到大输出，每个元素之间用一个空格隔开。

样例输入1
 1 2
 1
 2 3
样例输出1
 1 2 3
样例输入2
 1 2
 1
 1 2
样例输出2
 1 2

3. 记单词
 首先输入一个n（1≤n≤100000）表示事件数，接下来n行，每行表示一个事件。
 每个事件输入为一个整数d和一个单词word（单词长度不大于20），用空格隔开。
 如果d=0，表示蒜头君记住了word这个单词，如果d=1.表示这是一个测试，
 测试蒜头君是否认识单词word（花椰妹永远不会告诉蒜头君这个单词的意思）。
 事件的输入是按照时间先后顺序输入的。
输出格式
对于花椰妹的每次测试，如果蒜头君认识这个单词，输出一行Yes，否则输出一行No。

 样例输入 1
 5
 0 we
 0 are
 1 family
 0 family
 1 family
样例输出 1

4.
 给定n个整数，求里面出现次数最多的数，如果有多个重复出现的数，求出值最大的一个。
 当时可算是给蒜头君难住了。现在蒜头君来考考你。
输入格式
第一行输入一个整数n（1≤n≤100000），接下来一行输入n个int范围内的整数。
输出格式
输出出现次数最多的数和出现的次数，中间用一个空格隔开，如果有多个重复出现的数，
输出值最大的那个。
 样例输入
 5
 1 1 2 3 4

5.水果店
 蒜头君经营着一个不大的水果店。他认为生存之道就是经营最受顾客欢迎的水果。
 现在他想要一份水果销售情况的明细表，这样就可以很容易掌握所有水果的销售情况了。
 森头君告诉你每一笔销售记录的水果名称，产地和销售的数量，请你帮他生成明细表。

输入格式
第一行是一个整数N（0<N≤1000），表示工有N次成功的交易。其后有N行数据，
每行表示一次交易，由水果名称（小写字母组成，长度不超过100），
水果产地（小写字母组成，长度不超过100）和交易的水果数目（正整数，不超过1000）组成。

输出格式
请你输出一份排版格式正确（请分析样本输出）的水果销售情况明细表。
这份明细表包括所有水果的产地、名称和销售数目的信息。水果先按产地分类，
产地按字母顺序排列；同一产地的水果按照名称排序，名称按字母顺序排序。

 样例输入
5
apple shandong 3
pineapple guangdong 1
sugarcane guangdong 1
pineapple guangdong 3
pineapple guangdong 1
样例输出
guangdong
1----pineapple（5）
1----sugarcane（1）
shandong
1---apple（3）
 */
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void Question_1()
{
    vector<int> v[10005]; //vector<int> 数组
    int a,b,n,m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        v[i].push_back(i);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if (a == b)
        {
            continue;
        }

    }
}
void Question_2()
{
    set<int> s;
    int n,m,num,cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n + m; ++i) {
        cin >> num;
        s.insert(num);
    }
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        if(cnt != s.size()-1){
            cout << *it << " ";
            cnt++;
        }else
            cout << *it <<endl;
    }
}
void Question_3()
{
    set<string> set;
    string s;
    int n,op;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> op >> s;
        for (int j = 0; j < s.size(); ++j) {
            if(s[j] >= 'A' && s[j] <= 'Z')
                s[j] = 'a' + (s[j] - 'A');
        }
        if(op == 0)
        {
            set.insert(s);
        }else
        {
            if(set.count(s))
                cout << "YES"<< endl;
            else
                cout << "NO"<< endl;
        }

    }
}
void Question_4()
{
    int n,num,ans1,ans2 = 0;
    cin >>n;
    map<int,int > m;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        m[num]++;
    }
    for (map<int,int>::iterator it = m.begin(); it != m.end(); it ++)
    {
        if((it->second) > ans2)  //找到其中次数最多的
        {
            ans2 = it -> second;
            ans1 = it -> first;
        }
    }
    cout << ans1 << " " << ans2;
}
void Question_5()
{
    int n,num;
    string name,place;
    map<string,map<string,int> > m; //map回自己初始化掉里面的数据，int类型为零
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> name >> place >> num;
        m[place][name] += num;
    }
    for(map<string,map<string,int> >::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it -> first <<endl;
        for(map<string,int>::iterator it2 = it-> second.begin(); it2 !=it ->second.end(); it2++ )
        {
            cout << " " << "|----" << it2 -> first << "(" <<it2 -> second << ")" <<endl;
        }
    }
}

int main() {
    //Question_2();
    //Question_3();
    //Question_4();
    Question_5();
    return 0;
}


