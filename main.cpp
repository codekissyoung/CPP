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

#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <iomanip>

using namespace std;

#define QUESTION "Do you want another transaction"

int get_response( const char *question, int try_num = 3 );
int get_enable_char( const char *str ); // 获得指定的字符之一
void set_crmode();                      // 无缓冲，一次输入一个字符，就发送到程序
void set_noecho_mode();                 // 无回显
void set_nodelay_mode();                // 非阻塞
void ctrl_c_handler( int );             // 处理 Ctrl + C 信号
void init_terminal();                   // 初始化 终端程序
void restore_terminal();                // 恢复终端程序

// 原始属性
termios original_mode = {};
int original_flags = 0;

int main( int argc, char *argv[] )
{
    init_terminal();

    signal( SIGINT, ctrl_c_handler );
    signal( SIGQUIT, SIG_IGN );

    set_crmode();
    set_noecho_mode();
    set_nodelay_mode();

    int response = get_response( QUESTION );

    restore_terminal();

    return response;
}

void init_terminal(){
    tcgetattr( STDIN_FILENO, &original_mode );
    original_flags = fcntl( STDIN_FILENO, F_GETFL );
}

void restore_terminal(){
    tcsetattr( STDIN_FILENO, TCSANOW, &original_mode );
    fcntl( STDIN_FILENO, F_SETFL, original_flags );
}

void ctrl_c_handler( int sig_num ){
    cout << "\n" << sig_num << " signal called " << endl;
    restore_terminal();
    exit( EXIT_FAILURE );
}

int get_response( const char *question, int try_num ){
    cout << question << "?(Y/N)";
    fflush( stdout );

    char input;
    while ( true ){
        sleep( 2 );
        switch( input = tolower( get_enable_char( "YyNn" ) ) )
        {
            case 'y':
                return 0;

            case 'n':
                return 2;

            case EOF:
                if( --try_num > 0 ){
                    cout << "\n try num left " << try_num << " : ";
                    break;
                }else{
                    cout << endl;
                    return 1;
                }
        }
    }
}

int get_enable_char( const char *str ){
    int c;
    // 跳过无用的 输入字符
    while ( ( c = getchar() ) != EOF && strchr( str, c ) == nullptr )
    {
        continue;
    }
    return c;
}

void set_crmode()
{
    termios ttystate;

    tcgetattr( STDIN_FILENO, &ttystate );

    ttystate.c_lflag &= ~ICANON; // no buffering
    ttystate.c_cc[VMIN] = 1;     // get 1 char at a time

    tcsetattr( STDIN_FILENO, TCSANOW, &ttystate );
}

void set_noecho_mode(){
    termios ttystate;

    tcgetattr( STDIN_FILENO, &ttystate );

    ttystate.c_lflag &= ~ECHO; // no echo

    tcsetattr( STDIN_FILENO, TCSANOW, &ttystate );
}

// 非阻塞输入，就是 getchar() 如果没读到数据，就直接返回了，不会等待用户输入了
void set_nodelay_mode(){
    int termflags;
    termflags = fcntl( STDIN_FILENO, F_GETFL );
    termflags |= O_NDELAY;
    fcntl( STDIN_FILENO, F_SETFL, termflags );
}
