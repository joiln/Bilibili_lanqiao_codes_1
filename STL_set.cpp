//
// Created by chen on 2019/8/12 16:00.
//
/*
C++当中的set:
 set在C++就是集合
 要加入set的头文件

 构造一个集合
现在我们来构造一个集合。

C++中直接构造一个set的语句为：set<T>s。这样我们定义了一个名为s的、
 储存T类型数据的集合，其中T是集合要储存的数据类型。
 初始的时候s是空集合。比如set<int>aa，set<string>bbb等等。

 插入元素
C++中用insert（）函数向集合中插入一个新的元素。注意如果集合中已经存在了某个元素，
 再次插入不会产生任何效果，集合中是不会出现重复元素的。

 删除元素
C++中通过erase（）函数删除集合中的一个元素，如果集合中不存在这个元素，不进行任何操作。

 判断元素是否存在
C++中如果你想知道某个元素是否在集合中出现，你可以直接用count（）函数。如果集合中存在我们要查找的元素，返回1，否则会返回0。

 遍历元素
C++通过迭代器可以访问集合中的每个元素，迭代器就好像一根手指指向set中的某个元素。通过操作这个手指，我们可以改变它指向的元素。
 通过*（解引用运算符，不是乘号的意思）操作可以获取迭代器指向的元素。通过+操作让迭代器指向下一个元素，同理--操作让迭代器指向上一个元素。
迭代器的写法比较固定，set-T>：：iteratorit就定义了一个指向set<Ts这种集合的迭代器it，T是任意的数据类型。其中：：iterator是固定的写法。
begin 函数返回容器中起始元素的迭代器，end函数返回容器的尾后迭代器。
如果你不了解迭代器，你只需要先记住用法。

注意，在C++中遍历set是从小到大遍历的，也就是说set会帮我们排序的。

在set中插入、删除、查找某个元素的时间复杂度都是O（logn），并且内部元素是有序的，C++ set函数总结

函数           功能                 时间复杂度
insert      插入一个元素               O（logn）
erase       删除一个元素               O（logn）
count       统计集合中某个元素的个数     O（logn）
size        获取元素个数               O（1）

通过上面列举的函数，可以满足我们平时大多数的需求。
 关于set的更多函数，可以去参考文档，或者在网络上搜索资料查看。对于比赛来说，上面的函数已经足够了。

 set和结构体
 set经常会配合结构体来使用，用set来储存结构体和vector 有些区别。正如我们前面所说的那样，set是需要经过排序的。
 系统自带的数据类型有默认的比较大小的规则，而我们自定义的结构体，系统是不可能知道这个结构体比较大小的方式的。
 所以我们需要用一种方式来告诉系统怎么比较这个结构体的大小。其中一种方法叫做运算符重载，我们需要重新定义小于符号。

 重载运算符
 下面定义了一个重载小于符号的结构体

struct Node{
int x,y;
 bool operator<(const Node & rhs) const {
 if(x == rhs.x){
    return y<rhs.y;
} else{
    return x<rhs.x;
};

operator< 表示我们要重载运算符 <，可以看成是一个函数名。rhs是“right hand side”的简称，
 有右操作数的意思，这里我们定义为一个const引用。
 因为该运算符重载定义在结构体内部，左操作数就当前调用operator<的对象。
特别要注意，不要漏掉最后的const。const函数表示不能对其数据成员进行修改操作，
 并且const对象不能调用非 const成员函数，只允许调用const成员函数。
上面重载规定了排序方式为，优先按照x从小到大排序，如果x相同，那么再按照y从小到大排序。
 经过了<运算符重载的结构体，我们就可以比较两个Node对象的大小了，因此可以直接储存在set中了。

 */

#include <iostream>
#include <set>
using namespace std;

struct Node{
    int x;
    int y;
    //重载运算符 <
    bool operator <(const Node &rhs) const
    {
        if(x == rhs.x)                      //先比较x与x后面的数是否相等，如果相等
            return y < rhs.y;               //则就按y来从小到大排
        else
            return x < rhs.x;               //否则就按照x从小到大排
    }
};

void FindPeople();

int main() {
    //插入元素,集合中不能有重复的元素，当插入相同元素，结果不发生变化
    set<string> country;              //{ }
    country. insert("China");      //{"China"}
    country. insert("America");    //{"China","America"}
    country. insert("France");     //{"China","America","France"}
    country. insert("China");      //{"China","America","France"}
    cout << "删除前：";
    for (set<string>::iterator it = country.begin() ;it != country.end(); ++it)
    {
        cout  << *it << " ";
    }
    cout << "\n" << "删除后：";
    country.erase("America");      //{"China","France"}
    for (set<string>::iterator it = country.begin() ;it != country.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    if (country.count("China"))
        cout << "Find it!" <<endl;

    //用set来储存二维坐标系上面点的集合
    int n;
    Node node;
    set<Node> v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> node.x >> node.y;
        v.insert(node);
    }
    for (set<Node>::iterator it = v.begin(); it != v.end();it++)
    {
        cout << it -> x << " " << it -> y << endl;
    }
    FindPeople();

    return 0;
}
/*
 最近某地连续发生了多起盗窃案件，根据监控和路人提供的线索得知，这是一个犯罪团伙。
 并且还知道这个犯罪团伙中每个人的身高、体重、年龄。
 警察想知道这个犯罪团伙中的每个人是不是本市的（如果本市有这个特征的人就视为是本市的）。
 但本市人口太多，又不能一个一个排查。警察又急需这条信息来缩小范围，所以警察特来找到聪明的你来帮忙解决这个棘手的问题。

 输入格式
第一行将会输入两个数字n（1≤n≤2*105）和m（1≤m≤104）。n代表本市的人口数目，m代表犯罪团伙的数量。
后面n行每行有3个数字代表本市每个人的身高、体重、年龄。然后会有m行每行有3个数字代表犯罪团伙每个人的身高、体重、年龄。
 输出格式
输出 m行，每行输出一
个“yes”或“no”，"yes”“代表这个罪犯是本市的，“no”代表这个罪犯不是本市的。
样例输入
3 2
166 50 30
178 60 23
132 40 15
167 50 30
178 60 23
样例输出
no
yes
 */
void FindPeople() {
    struct people{
        int h;
        int w;
        int age;
        //自定义构造函数，来代替people.h 等的输入，直接调用people(h,w,age)传入h,w,age
        people(int _h,int _w, int _age)
        {
            h = _h;
            w = _w;
            age = _age;
        }
        //重载 "<"
        bool operator <(const people &rhs) const
        {
            if (h != rhs.h)
                return h < rhs.h;
            if (w != rhs.w)
                return w < rhs.w;
            return age < rhs.age;
        }
    };
    int n,m,h,w,age;
    cin >> n >> m;
    set<people> s;
    for (int i = 0; i < n; ++i) {
        cin >> h >> w >> age;
        s.insert(people(h,w,age));
    }
    for (int j = 0; j < m; ++j) {
        cin >> h >> w >> age;
        if(s.count(people(h,w,age)))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}




