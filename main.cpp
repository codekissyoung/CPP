#include "common.h"
#include "func.h"
#include "Stock.h"
#include "Student_info.h"
#include "My_vector.h"
#include "My_stack.h"
#include "My_Queue.h"
#include "StringBad.h"
#include "vec.h"
#include "Sales_item.h"
#include "Str.h"
#include "Screen.h"
#include "Window_mgr.h"
#include "Brass_model.h"

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <initializer_list>
#include <stack>
#include <queue>
#include <memory>

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <climits>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;


class TableTennisPlayer{
private:
    string firstname;   //
    string lastname;    //
    bool hasTable;      // 是否有球桌?
public:
    TableTennisPlayer(const string &fn, const string &ln, bool ht = false ):firstname{fn},lastname{ln},hasTable{ht} { }
    void name() const{
        cout << lastname << "," << firstname;
    };
    bool HasTable() const { return hasTable; }
    void ResetTable(bool v ) {hasTable = v;};
};

class RatePlayer : public TableTennisPlayer{
private:
    unsigned int rating; // 参与比赛次数
public:
    explicit RatePlayer(unsigned int r  = 0, const string &fn = "none", const string &ln = "none", bool ht = false ) :
        TableTennisPlayer(fn, ln, ht), rating{r} { }

    RatePlayer(unsigned int r, const TableTennisPlayer &tp ) :
        TableTennisPlayer(tp), rating{r} { }

    unsigned int Rating() const { return rating; }

    void ResetRating(unsigned int r ){ rating = r; }
};

void show( const TableTennisPlayer &tp )
{
    tp.name();
    if( tp.HasTable() )
        cout << "has table" << endl;
    else
        cout << "no table" << endl;
}

int main( int argc, char *argv[] )
{
    Brass cao ("codekissyoung", 38123, 4000.0 );
    BrassPlus zhan ("zhangjian", 38124, 5000.0, 10000.0, 0.04 );

    BrassBase* accout_list[2];

    accout_list[0] = &cao;
    accout_list[1] = &zhan;

    for( auto x : accout_list ){
        x -> ViewAcct();
        cout << endl;
    }

    return EXIT_SUCCESS;
}
