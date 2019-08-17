/*东东所在的班级有N名同学，期未考试进行了数学、语文、英语、地理四门功课的测试。
班主任要将这N名学生中总分前三名定为本学期的“学习小标兵”。现在给出这N名学生的姓名和各科成绩，
请你编程找到总分前三名，并依次输出他们的姓名。所给数据不会有总分相同的情况。
输入格式
输入包含N+1行，第一行仅有一个正整数N（
3≤N≤40），表示东东班里学生的总数，接下来的N行，每行描述一个学生的考试信息，
 依次为姓名、数学成绩、语文成绩、英语成绩与地理成绩，两两之间用一个空格分隔。
 注意：姓名（不会同名）都用小写字母表示（不超过10个字母），
 成绩全都是不超过200的非负整数。
 */
/*
 * 控制答案末尾的空格有两种方式
 * 知道个数和不知道个数
1.知道个数(判断结尾)
    if (i != 6)
    {
        cout << num << " ";  //不是开头就打数值加印空格
    }else{
        cout << cum << endl; //是开头的话就打印第一个数值
    }
2.不知道个数(判断开头)
 if(i != 1)
 {
    cout << " " << num;     //不是开头就打印空格加数值
 }else{
    cout << num;            //是开头的话就打印第一个数值
 }

 */




#include <iostream>
//#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;


struct Student{
    char name[15];
    int socre[4];

};
//自定义sort排序标准，传入一个Student结构体的一个对象，
//表示当第一个参数大于的二个时，就把第一个排在第二个的前面。
//在排序标准中一般不用“等于”条件，否则容易出错。
bool cmp(Student x ,Student y)
{
    int sumx = 0;
    int sumy = 0;
    for (int i = 0; i < 4; ++i) {
        sumx += x.socre[i];
        sumy += y.socre[i];
    }
    return sumx > sumy;
}

Student stu[100];

int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
    scanf("%s",&stu[i].name);
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &stu[i].socre[j]);
        }
    }
    sort(stu,stu+(4+1),cmp);    //尾地址要往后面走一位,因为地址0-4，一共有5个，所有尾地址填 5。
    for (int i = 0; i < 4; ++i) {
        cout << stu[i].name << " ";
        for (int j = 0; j < 4; ++j) {
            cout << stu[i].socre[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}