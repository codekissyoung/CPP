#include <iostream>
#include <string>
#include "common.h"

template <> void Swap<job>( job& i, job& j)
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

