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

void countdown( int a ){
    static int num = 10;
    printf( "%d .. ", num-- );
    fflush( stdout );
    if( num < 0 ){
        printf("DONE!\n");
        exit(0);
    }
}

int set_ticker( int n_msecs ){

    long n_sec = n_msecs / 1000;
    long n_usecs = ( n_msecs % 1000 ) * 100L;

    itimerval new_timeset;

    // time to next timer expiration
    new_timeset.it_value.tv_sec = n_sec;
    new_timeset.it_value.tv_usec = n_usecs;

    // 间隔调用时间
    new_timeset.it_interval.tv_sec = n_sec;
    new_timeset.it_interval.tv_usec = n_usecs;

    return setitimer( ITIMER_REAL, &new_timeset, NULL );
}

void quithandler( int s){
    printf("Received signal %d .. waiting\n", s );
    sleep(2);
    printf("Leaving quithandler\n");
}

#define INPUTLEN 100

void inthandler( int s ){
    printf("Received signal %d .. waiting\n", s );
    sleep(2);
    printf("Leaving inthandler\n");
}

int main( int argc, char *argv[] )
{
    struct sigaction newhandler = {};
    sigset_t blocked;
    char x[INPUTLEN];

    newhandler.sa_handler = inthandler;
    newhandler.sa_flags = SA_RESTART;
    sigemptyset( &blocked );
    sigaddset( &blocked, SIGQUIT );
    newhandler.sa_mask = blocked;

    if( sigaction( SIGINT, &newhandler, NULL ) ==  -1 )
    {
        perror("sigaction");
    }else{
        while(true){
            fgets( x, INPUTLEN, stdin );
            printf("input: %s", x );
        }
    }

    return 0;

    /*
    initscr(); // 初始化 curses 库
    clear();

    int x_dir = +1;
    int y_dir = +1;

    int x = 0;
    int y = 0;


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
    */
}
