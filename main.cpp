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

#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <iomanip>

using namespace std;

void do_ls( const char *dirname );
void show_file_info( const char *filename );
char* mode_to_letters( int mode );

int main( int argc, char *argv[] )
{
    if( argc == 1 )
        do_ls( "." );
    else
        while ( --argc ){
            do_ls( *++argv );
        }

    return EXIT_SUCCESS;
}

void do_ls( const char * dirname ) {
    DIR *dir_ptr;
    struct dirent *dir_data;

    dir_ptr = opendir( dirname );

    while ( (dir_data = readdir(dir_ptr)) != nullptr ){
        show_file_info( dir_data->d_name );
    }

    closedir(dir_ptr);
}

void show_file_info( const char *filename ){
    struct stat info;
    stat( filename, &info );

    cout << mode_to_letters( info.st_mode ); // 权限

    cout << " " << info.st_nlink << " ";     // lnode 数
    cout << " " << getgrgid(info.st_gid) -> gr_name << " ";  // 用户组名
    cout << " " << getpwuid(info.st_uid) -> pw_name << " ";  // 用户名

    // 小数显示 文件大小
    cout << " " << setiosflags( ios::fixed ) << setprecision( 1 );
    if( info.st_size >= 1024 * 1024 * 1024 ){
        cout << info.st_size / (1024.0 * 1024.0 * 1024.0)  << "G\t";
    }else if( info.st_size < 1024 * 1024 * 1024 && info.st_size >= 1024 * 1024 ) {
        cout << info.st_size / (1024.0 * 1024.0)  << "M\t";
    }else if(info.st_size < 1024 * 1024 ){
        cout << info.st_size / 1024.0 << "K\t";
    }

    char time_str[30];
    strftime( time_str, 30, "%Y-%m-%d %H:%M:%S", localtime( &info.st_mtime ) );

    cout << " " << time_str << " ";

    cout << " " << filename << endl;
}

char* mode_to_letters( int mode ){
    char *str = new char[11];
    strcpy( str, "----------" );
    str[10] = '\0';

    if( S_ISDIR(mode) ) str[0] = 'd';
    if( S_ISCHR(mode) ) str[0] = 'c';
    if( S_ISBLK(mode) ) str[0] = 'b';

    if( mode & S_IRUSR ) str[1] = 'r';
    if( mode & S_IWUSR ) str[2] = 'w';
    if( mode & S_IXUSR ) str[3] = 'x';

    if( mode & S_IRGRP ) str[4] = 'r';
    if( mode & S_IWGRP ) str[5] = 'w';
    if( mode & S_IXGRP ) str[6] = 'x';

    if( mode & S_IROTH ) str[7] = 'r';
    if( mode & S_IWOTH ) str[8] = 'w';
    if( mode & S_IXOTH ) str[9] = 'x';


    return str;
}

