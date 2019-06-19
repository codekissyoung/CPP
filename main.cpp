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

#define is_delim(x) ((x) == ' ' || (x) == '\t')

void freelist( char **list );
char *next_cmd( FILE *istream );
int execute( char *argv[] );
char *makestring( char *buf );
void excute( char *argv[] );
void parent_code( int childpid );
char *newstr( char *s, int l );

int main( int argc, char *argv[] )
{
    signal( SIGINT, SIG_IGN );
    signal( SIGQUIT, SIG_IGN );

    printf("hello world\n");

    return 0;
}

void fatal( const char *s1, const char *s2, int n ){
    fprintf( stderr, "Error: %s, %s,\n", s1, s2 );
    exit(n);
}

void *erealloc( void *p, size_t n ){

    void *rv = realloc( p, n );

    if( rv == nullptr )
        fatal("realloc() failed", "", 1 );

    return rv;
}

void *emalloc( size_t n ){
    void *rv;
    if( ( rv = malloc(n) ) == nullptr ){
        fatal("out of memery", "", 1);
    }
    return rv;
}

void freelist( char **list ){
    char **cp = list;
    while( *cp ){
        free( *cp++ );
    }
    free( list );
}

char *newstr( char *s, int l ){
    char *rv = (char *)emalloc( l + 1 );
    rv[l] = '\0';
    strncpy( rv, s, l );
    return rv;
}

// 从IO中读取一个命令，利用malloc内存存储它，碰见EOF返回nullptr
char *next_cmd( FILE *istream )
{
    char *buf = nullptr;
    int bufspace = 0;
    int pos = 0;

    int c;
    while ( ( c = getc(istream) ) != EOF )
    {
        if( pos + 1 >= bufspace )
        {
            buf = (char *) ( bufspace == 0 ? malloc(BUFSIZ) : realloc( buf, bufspace + BUFSIZ) );
            bufspace += BUFSIZ;
        }

        if( c == '\n' )
            break;

        buf[ pos++ ] = c;
    }

    if( c == EOF && pos == 0 )
        return nullptr;

    buf[pos] = '\0';

    return buf;
}

int execute( char *argv[] )
{
    int pid = fork();

    if( pid == -1 )
        perror("fork");
    else if( pid == 0 ){
        signal(SIGINT, SIG_DFL);
        signal(SIGQUIT, SIG_DFL);
        execvp( argv[0], argv );
        perror( "can not execute command" );
        return 1;
    }else{
        int child_info = 0;
        if( wait(&child_info) == -1 )
            perror("wait");

        return child_info;
    }
    return -1;
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

void parent_code( int childpid )
{
    int child_status = 0;
    unsigned int high_8, low_7, bit_7 = 0;

    int wait_rv = wait( &child_status );
    printf("done wating for %d. Wait returned: %d\n", childpid, wait_rv );

    high_8 = child_status >> 8;
    low_7  = child_status & 0x7F;
    bit_7  = child_status & 0x80;

    printf("status: exit = %d, sig = %d, core = %d\n", high_8, low_7, bit_7 );
}
