//
// Created by chen on 2019/8/12 20:30.
//
/*
映射表
映射是指两个集合之间的元素的相互对应关系。通俗地说，就是一个元素对应另外一个元素。比如有一个姓名的集合
 {“Tom，"Jone"，“Mary"}，班级集合{1，2}。姓名与班级之间可以有如下的映射关系：
class（"Tom"）=1，class（"Jone"）=2，class（"Mary"）=1

我们称其中的姓名集合为关键字集合（key），班级集合为值集合（value）。
在C++中我们常用的映射是map。

 插入一对映射
在C++中通过insert（）函数向集合中插入一个新的映射，参数是一个pair。
pair是一个标准库类型，定义在头文件utility中。可以看成是有两个成员变量first和second的结构体，并且重载了<运算符（先比较first大小，
 如果一样再比较second）。当我们创建一个pair时，必须提供两个类型。
我们可以像这样定义一个保存string和int的pair

 pair<string，int>p；

 make-pair（v1，v2）函数返回由v1和v2初始化的pair，类型可以从v1和v2的类型推断出来。
 我们向映射中加入新映射对的时候就是通过插入pair来实现的。如果插入的key之前已经存在了，
 将不会用插入的新的value替代原来的value，也就是这次插入是无效的。

 访问映射
在C++中访问映射和数组一样，直接用口就能访问。比如dict[“Tom"]就可以获取“Tom”的班级了。
 而这里有一个比较神奇的地方，如果没有对“Tom”做过映射的话，此时你访问dict["Tom]，
 系统将会自动为“Tom”生成一个映射，其value为对应类型的默认值（比如int的默认值是0，string的默认值是空字符串）。
并且我们可以之后再给映射赋予新的值，比如dict["Tom"]=3，这样为我们提供了另一种方便的插入手段。
 实际上，我们常常通过下标访问的方式来插入映射，而不是通过用insert插入一个pair来实现。
当然有些时候，我们不希望系统自动为我们生成映射，这时候我们需要检测“Tom”是否已经有映射了，
 如果已经有映射再继续访问。这时就需要用count（）函数进行判断，在下一页中我们会详细介绍。
  添加元素
 map<string,int> m;
 m["tom"] = 1;
 m["jane"] = 2;

 判断关键字是否存在
在C++中，如果你想知道某个关键字是否被映射过，你可以直接用count）函数。如果关键字存在，返回1，否则会返回0。

 遍历映射
map的迭代器的定义和set差不多，map<T1，T2>：iterator it就定义了一个迭代器，其中T1、T2分别是key和value的类型。
C++通过迭代器可以访问集合中的每个元素。这里迭代器指向的元素是一个pair，有first和second两个成员变量，分别代表一个映射的key和value。
我们用->运算符来获取值，it->first和（*it）.first的效果是一样的，就是获取迭代器it指向的pair里first成员的值。

 注意，在C++中遍历map是按照关键字（key）从小到大遍历的，这一点和set有些共性。

 二维 map的实现
 前面我们学习了二维的vector，实际上就是一个vector套一个vector。map当然也有二维的用法。
而二维的map不仅仅能map套map，还能map 套set。实际上map套set更容易理解。所以我们先学习map套set，然后再学习map套map。

 */

#include <iostream>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;

void MapCombanSet();
void MapCombanMap();
void MapAndMatrix();
void FindBook();

int main() {
//    map<string, int > m;
//    int n;
//    string name;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        cin >> name;
//        m[name] = i;
//    }
//    for ( map<string ,int >::iterator it = m.begin(); it != m.end(); it++)
//    {
//        cout << it -> first << " " << it -> second << endl;
//    }
//
//    MapCombanSet();
//    MapCombanMap();
//    MapAndMatrix();
    FindBook();
    return 0;
}

/*
 map 套用set为了帮助理解，我们举用一个生活中实际例子。
 全校有很多班级，每个班级每个人都会有中文名。现在我们需要用一种方式来记录全校的同学的名字。
 如果直接用一个set记录，对于重名的同学，那么就没办法分辨了。
我们可以把全校的班级进行编号，对每一个班级建立一个set，也就是每个班级都映射成一个set，
 这样就能分辨不同班级的同名同学了。对于同班的同学来说，一般很少有重名的。
 */
void MapCombanSet()
{
    set<string> name;
    map<int,set<string> > m;
    int n;
    string nme;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nme;
        name.insert(nme);
    }

}
/*
 map 套用map上面的结构没有办法解决同班同名的情况。实际上，如果同班同名，
 单单通过名字本身是无法分辨的，需要通过其他特征来分辨。所以为了简单起见，
 我们只需要记录每个班级同名的人的个数。

 这一节我们来是实际操作二维的map。首先把班级编号映射成一个名字到人数的映射。
在main函数开头写下
map<int，map<string，int>>info；

接下来，我么读入n个同学的信息，每个信息包含一个班级编号和名字。然后更新info，把相应班级中的相应名字数量加1。
 在main 函数里接着写下1int n；
cin>>n；
 for（inti=0；i<n；i++）{
int class_id；
string name；
cin>>class_id>>name；
info【class_id】【name】++；
}

然后我们遍历整个map，首先我们遍历第一维，也就是外层。
在main函数里接着写下
for（map<int，map<string，int> >：：iterator it1=info.begin（）；it1！=
info.end（）；it1++）{

 然后遍历第二维，，这时候我们需要先分析一下第一维的it1迭代器。实际上，it1->first是一个int，表示班级编号。
 而it1->second是一个map<string，int>容器，表示某个班级里每个名字个数的map，现在我们正要准备遍历这个map。
因此it1->second.begin（）是内层迭代器的起始位置，it1->second.end（）是这个map的尾后迭代器。
在for 循环里面写下 :
for（map<string，int>：：iterator it2 = it1 -> second.begin()；it2 != it1 -> second.end()；it2++）{

}

 这一节已经完成了，点击运行，然后输入如下的数据查看效果。
6
1 zgh
2 yuhaoran
2 yuhaoran
1 barty
100 xxXX
50 xxxx

 */
void MapCombanMap()
{
    map<int ,map<string,int> > m;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int class_id;
        string name;
        cin >> class_id >> name;
        m[class_id][name]++;
    }
    for (map<int ,map<string,int> >::iterator it = m.begin(); it != m.end(); it++){
        for (map<string,int >:: iterator it1 = it -> second.begin(); it1 != it-> second.end(); it1++)
        {
            if(it1 -> second == 1)
            {
                cout << "There is " << it1 -> second << " people name " << it1 ->first << " in class " << it ->first <<endl;
            }else
                cout << "There are " << it1 -> second << " people name " << it1 ->first << " in class " << it ->first <<endl;
        }
    }
}
/*
蒜头君有个学霸同学，家中藏书真可谓汗牛充栋。小明想考一考学霸，给学霸出了一道难题。
 小明问这么多书籍，到底有多少本不一样的书，每样书的名字是什么？（因为有的书名是一样的，
 所以我们把它们视为同样的书）学霸就是学霸，张口就说出了答案。不知道你是否也是学霸？一起来挑战下？
输入格式
第一行是书籍总量n（1≤n≤106）。
然后有n行书名（书名是一个英文字符串，字符串的长度小于100，中间没有空格）。
输出格式
第一行是不同书籍的数量，然后按照书名的字典序输出书名和数量。
输出格式
第一行是不同书籍的数量，然后按照书名的字典序输出书名和数量。
样例输入
4
English
Math
Chinese
Chinese
样例输出
3
Chinese 2
English 1
Math 1
 */
void FindBook()
{
    int n;
    string name;
    map<string,int> mp;
    cin >> n;
    //scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        cin >> name;
        mp[name]++;
    }
    cout << mp.size() << endl;
    for (map<string,int >::iterator it = mp.begin(); it != mp.end(); it++)
    {
        cout << it -> first << " " << it -> second << endl;
    }
}