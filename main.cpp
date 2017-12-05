#include <iostream>
#include <string>
#include <vector>
#include <array>

/* 使用到的 c 标准库 */
#include <cmath>
#include <cstring>

#include "sales_data.h"

using namespace std; // 作用于当前整个文件

struct job
{
    char name[40];
    double salary;
    int floor;
};

// 正常函数原型
void Swap( job& i, job& j )
{
    double salary_temp;
    int floor_temp;
    salary_temp = i.salary;
    floor_temp  = i.floor;
    i.salary    = j.salary;
    i.floor     = j.floor;
    j.salary    = salary_temp;
    j.floor     = floor_temp;
}

// 模板化原型
template <typename T>
void Swap( T& i, T& j)
{

}

// 显式具体化原型
template <> void Swap<job>( job& i, job& j)
{

}

int main()
{
    job Teacher = { "codekissyoung", 10000.00, 4 };
    job Worker  = { "caokaiyan", 4000.00, 3 };
    Swap( Teacher, Worker );
    cout << Worker.name << " : " << Worker.salary << " , " << Worker.floor << endl;
    return 0;

}

