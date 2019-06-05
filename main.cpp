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

ino_t get_inode( const char * );
void printpathto( ino_t );
void inum_to_name( ino_t , char *, int );

int main( int argc, char *argv[] )
{
    printpathto( get_inode(".") );
    cout << endl;
}

void printpathto( ino_t this_inode ){

    ino_t my_inode;
    char its_name[BUFSIZ];

    if( get_inode("..") != this_inode ){
        chdir( ".." );
        inum_to_name( this_inode, its_name, BUFSIZ );
        my_inode = get_inode( "." );
        printpathto( my_inode );
        cout << "/" << its_name;
    }
}

ino_t get_inode( const char *fname ){
    struct stat info;
    stat( fname, &info );
    return info.st_ino;
}

void inum_to_name( ino_t inode_to_find, char *namebuf, int buflen ){
    DIR *dir_ptr;
    struct dirent *direntp;
    dir_ptr = opendir( "." );

    while ( ( direntp = readdir( dir_ptr ) ) != NULL ){
        if( direntp->d_ino == inode_to_find ){
            strncpy( namebuf, direntp->d_name, buflen );
            namebuf[buflen - 1] = '\0';
            closedir( dir_ptr );
            return ;
        }
    }
    return;
}