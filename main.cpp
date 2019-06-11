#include "common.h"
#include "func.h"
#include "Stock.h"
#include "Student_info.h"
#include "My_vector.h"
#include "My_stack.h"
#include "My_Queue.h"
#include "My_array.h"
#include "My_pair.h"
#include "StringBad.h"
#include "vec.h"
#include "Sales_item.h"
#include "Str.h"
#include "Screen.h"
#include "Window_mgr.h"
#include "Brass_model.h"
#include "LinkList.h"
#include "Tree.h"

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
#include <valarray>

#include <cmath>
#include <time.h>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <climits>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <termios.h>
#include <signal.h>
#include <curses.h>   // 一个用于控制终端屏幕的库

#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <iomanip>

using namespace std;

#define MESSAGE "O"
#define BLANK   " "

void move_msg( int n );
int set_ticker( int n_msecs );

int row;   // 当前行
int col;   // 当前列
int x_dir; // x轴方向
int y_dir; // y轴方向

int main( int argc, char *argv[] )
{
    initscr();
    crmode();
    noecho();
    clear();

    int delay  = 200;

    row = 0, col = 0, x_dir = +1, y_dir = +1;

    move( row, col );
    addstr( MESSAGE );

    signal( SIGALRM, move_msg );

    set_ticker( delay );

    while ( true )
    {
        int ndelay = 0;

        int c = getch();

        if( c == 'q' )
            break;

        switch ( c )
        {
            case ' ':
                x_dir = -x_dir;
                break;
            case 'f':
                if( delay > 2 )
                    ndelay = delay / 2;
                break;
            case 's':
                ndelay = delay * 2;
        }

        if( ndelay > 0 )
            set_ticker( delay = ndelay );
    }

    endwin();
    return 0;
}

void move_msg( int n ){
    signal( SIGALRM, move_msg ); // reset, just in case

    move( row, col );
    addstr( BLANK );

    col += x_dir;
    row += y_dir;

    move( row, col );
    addstr( MESSAGE );

    move( LINES - 1, 0 );
    refresh();

    if( x_dir == -1 && col <= 0 )
        x_dir = 1;
    else if( x_dir == 1 && col + strlen(MESSAGE) >= (unsigned int)COLS )
        x_dir = -1;

    if( y_dir == -1 && row <= 0 )
        y_dir = 1;
    else if( y_dir == 1 && row >= LINES - 1 )
        y_dir = -1;
}

int set_ticker( int n_msecs ){
    long n_sec   = n_msecs / 1000;
    long n_usecs = ( n_msecs % 1000 ) * 100;

    itimerval new_timeset;

    // time to next timer expiration
    new_timeset.it_value.tv_sec = n_sec;
    new_timeset.it_value.tv_usec = n_usecs;

    // 间隔调用时间
    new_timeset.it_interval.tv_sec = n_sec;
    new_timeset.it_interval.tv_usec = n_usecs;

    return setitimer( ITIMER_REAL, &new_timeset, NULL );
}