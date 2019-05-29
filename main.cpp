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
#include <ctime>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <climits>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

void show_info( utmp *u ){
    cout << u->ut_name << "\t";
    cout << u-> ut_line << "\t";
    cout << u-> ut_host << "\t";
    cout << u-> ut_session << "\t";

    cout << endl;
}

int main( int argc, char *argv[] )
{
    utmp current_record;

    int utmpfd;
    int reclen = sizeof(current_record);

    if( ( utmpfd = open( UTMP_FILE, O_RDONLY ) ) == -1 ){
        perror( UTMP_FILE "Error" );
        exit(1);
    }

    while ( read( utmpfd, &current_record, reclen ) == reclen )
    {
        show_info( &current_record );
    }

    close( utmpfd );

    return EXIT_SUCCESS;
}
