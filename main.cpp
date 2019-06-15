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
#include <wait.h>

using namespace std;

char *makestring( char *buf );
void excute( char *arglist[] );
void parent_code( int childpid );

#define MAXARGS 20
#define ARGLEN 100

int main( int argc, char *argv[] )
{
    char *arglist[MAXARGS + 1] = {};
    int numargs = 0;
    char argbuff[ARGLEN];
    while ( numargs < MAXARGS ){
        printf("Arg[%d] ", numargs);
        fgets(argbuff, ARGLEN, stdin);
        if(  *argbuff != '\n' ){
            arglist[numargs++] = makestring( argbuff );
        }else{
            if( numargs > 0 ){
                arglist[numargs] = nullptr;
                excute( arglist );
                numargs = 0;
            }
        }
    }
    return 0;
}

char *makestring( char *buf ){
    char *cp;
    buf[strlen(buf) - 1] = '\0';
    cp = (char *)malloc( strlen(buf) + 1 );
    if( cp == nullptr ){
        fprintf(stderr, "no memory");
        exit(1);
    }
    strcpy( cp, buf );
    return cp;
}

void excute( char *arglist[] ){
    int pid = fork();
    if( pid == -1 ){
        perror("fork failed!");
        exit(1);
    }else if( pid == 0 ){
        sleep(5);
        execvp( arglist[0], arglist );
        perror("execvp failed");
        exit(1);
    }else{
        signal( SIGINT, SIG_IGN ); // 让父进程 忽略 Ctrl + C 信号
        parent_code( pid );
    }
}

void parent_code( int childpid ){
    int child_status = 0;
    int high_8, low_7, bit_7 = 0;

    int wait_rv = wait( &child_status );
    printf("done wating for %d. Wait returned: %d\n", childpid, wait_rv );

    high_8 = child_status >> 8;
    low_7  = child_status & 0x7F;
    bit_7  = child_status & 0x80;

    printf("status: exit = %d, sig = %d, core = %d\n", high_8, low_7, bit_7 );
}
