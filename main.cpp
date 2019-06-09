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

#define LEFTEDGE 10
#define RIGHTEDGE 30
#define ROW 10

int main( int argc, char *argv[] )
{
    initscr(); // 初始化 curses 库
    clear();

    int x_dir = +1;
    int y_dir = +1;

    int x = 0;
    int y = 0;

    return 0;
    while ( true )
    {
        move( x, y );
        standout();
        addstr( " " );
        standend();

        move( LINES - 1 , 0 );

        refresh();
        move( x, y );
        addstr( " " );

        if ( x + x_dir == LINES - 1 )
            x_dir = -1;
        if ( x + x_dir == -1 )
            x_dir = +1;

        if ( y + y_dir == COLS - 1 )
            y_dir = -1;
        if ( y + y_dir == -1 )
            y_dir = +1;

        x += x_dir;
        y += y_dir;

        usleep( 1000 * 200 );
    }

    endwin();
}
