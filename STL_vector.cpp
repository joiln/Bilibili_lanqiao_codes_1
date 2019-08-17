//
// Created by chen on 2019/8/10 19:58.
//
/*
C++中直接构造一个vector的语句为：vector-Tsvec。
 这样我们定义了一个名为vec的储存T类型数据的动态数组。
 其中T是我们数组要储存的数据类型，可以是int、float、double、
 或者其他自定义的数据类型等等。
 初始的时候vec是空的。
 比如vector<int>a定义了一个储存整数的动态数组a。

 用vec.push_back()在数组后面插入元素
 用vec.pop_back()在数组后面删除元素

 vector也可以构造成二维数组，比如一个n行m的二维数组
    vector<vector<int> > vec2(n, vector<int>(m,0))

    相当于嵌套开启空间，建一个vec2，里面有n个vector<int>(m,0)，每个vector<int>有m个0；


 */
#include <iostream>
#include <vector>
using namespace std;

struct Student              //vector还可以存放结构体类型
{
    string name;
    int age;
};
//打印锯齿矩阵
//void VectorMatrix();

void VectorMatrix();

int main() {
    //开一个动态的二维数组
//    vector<vector<int> > vec2;
//    //给每个vec2 添加 vector<int>() 元素
//    for (int j = 0; j < 10; ++j) {
//        vec2.push_back(vector<int>());
//    }
//    //给每个元素赋值
//    for (int i = 0; i < vec2.size(); ++i) {
//        vec2[i].push_back(i*i);
//    }
//    //打印
//    for (int k = 0; k < vec2.size(); ++k) {
//        for (int i = 0; i < vec2[i].size(); ++i) {
//            cout << vec2[k][i] << endl;
//        }
//    }

    //打印一个乘法口诀表
    vector<vector<int> > vec2;

    for (int i = 0; i < 9; ++i) {
        vec2.push_back(vector<int>() );
    }

    for (int j = 0; j < vec2.size(); ++j) {
        for (int k = 0; k <= j; ++k) {
            vec2[j].push_back((j+1) * (k+1));
        }
    }

    for (int l = 0; l < vec2.size(); ++l) {
        for (int i = 0; i < vec2[l].size(); ++i) {
            cout <<  i + 1 << " * " << l + 1 << " = " << vec2[l][i] << "\t";
        }
        cout << endl;
    }


//    int num;
//    vector <int> nums;
//    while (cin >> num)
//        nums.push_back(num);
//    for (int i = 0; i < nums.size(); ++i) {
//        cout << nums[i] << endl;
//    }

//    vector <Student> class_1;       //新建一个学生集合的班级
//    Student student1,student2;
//    student1.name = "Tom" ;
//    student1.age = 21;
//    student2.name = "Jack" ;
//    student2.age = 22;
//
//    class_1.push_back(student1);
//    class_1.push_back(student2);

    VectorMatrix();

    return 0;
}

/*
 锯齿矩阵是指每一行包含的元素个数不相同的矩阵，比如：
3 5 2 6 1
2 3 4
1 6 2 7
读入若干对整数（x，y），表示在第x行的末尾加上一个元素y。输出最终的锯齿数组。初始时矩阵为空。
输入格式
第一行输入两个整数
n，m（1≤n，m≤10000），其中n表示锯齿数组的行数，m表示插入的元素总数。
接下来一共m行，每行两个整数x，y（1≤x≤n，0≤y≤10000），表示在第x行的未屋插入一个示素y.
 */

//也可以用结构体来实现

void VectorMatrix() {
    vector<int> mat[10005]; //表示有10005个vector，用mat数组存了10005个vector
    int n,m,x,y;
    cin >> n >> m;
    for (int j = 0; j < m; ++j) {
        cin >> x >> y;
        mat[x].push_back(y);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < mat[i].size(); ++j) {
            if (j != mat[i].size() - 1)
                cout << mat[i][j] << " ";
            else
                cout << mat[i][j];
        }
        cout << endl;
    }
}

