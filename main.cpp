#include "common.h"
#include "func.h"
#include "stock.h"
#include "median.h"
#include "vector.h"
#include "container.h"
#include "date.h"
#include "stack.h"

#include <iostream>
#include <cmath>
#include <ctime>

int main( int argc, char *argv[] )
{
    using namespace std;

    try
    {
        const int MOD = 1000000;
        int n, S = 0;
        scanf("%d", &n);

        for( int i = 1; i <= n; i++ )
        {
            int factorial = 1;
            for( int j = 1; j <= i; j++ )
            {
                factorial = factorial * j % MOD;
            }
            S = (S + factorial) % MOD;
        }
        printf("%d\n", S);
        printf("time used = %.2f \n", (double)clock() / CLOCKS_PER_SEC);

        /*
        Stack st;
        char ch;
        unsigned long po;
        cout << "a for add, p for pop, q for Quit:";
        while( cin >> ch && toupper(ch) != 'Q')
        {
            switch ( ch )
            {
                case 'A':
                case 'a':
                    cout << "add: ";
                    cin >> po;
                    if( st.isfull() )
                        cout << "stack full" << endl;
                    else
                    {
                        st.push( po );
                    }
                    break;

                case 'P':
                case 'p':
                    if( st.isempty() )
                        cout << "stack is empty" << endl;
                    else
                    {
                        st.pop(po);
                        cout << "PO # " << po << "poped\n";
                    }
                    break;
            
                default:
                    break;
            }
            cout << "a for add, p for pop, q for Quit:";
        }
        */
        
        /*
        // 测试股票
        Stock fluffy_the_cat;
        fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
        fluffy_the_cat.show();

        fluffy_the_cat.buy( 15, 18.125 );
        fluffy_the_cat.show();

        fluffy_the_cat.sell(400, 20.00);
        fluffy_the_cat.show();

        fluffy_the_cat.buy(30000, 40.125);
        fluffy_the_cat.show();

        fluffy_the_cat.sell(30000, 0.125);
        fluffy_the_cat.show();

        Stock stock1("伊利", 12, 20.0);
        stock1.show();

        Stock stock2("蒙牛", 14, 34.0);
        stock2.show();

        stock2 = stock1;
        stock2.show();
        stock1.show();

        stock1 = Stock("Nify Foods", 10, 50.00);
        stock1.show();

        Stock hot_tip {"Derivate Plus Plus", 100, 45.09};
        hot_tip.show();


        Stock top = hot_tip.topval( stock1 );
        top.show();
        */

        /*
        double && rref = sqrt(36.00);
        double j = 15.0;
        double && jref = 2.0 * j + 18.5;

        cout << "rref : " << rref << " jref: " << jref << endl;
        */

        // array<double, Seasons> expenses;
        // fill( &expenses );
        // show( expenses );

        /*
        int *pt = new int {100};
        int *pt_arr = new int[10];

        int arr[10] = { 10, 23, 45, 56, 67, 76};

        cout << "sizeof pt_arr" << sizeof(pt_arr) << endl;
        cout << "sizeof arr" << sizeof(arr) << endl;
        cout << "*pt: " << *pt << endl;

        delete pt;
        delete [] pt_arr;
        */

        /*
        vector<string> test_str {"hello", "codekissyong", "very funny"};
        vector<int> test_int { 12, 34, 55, 67, 76, 32, 23 };

        print(test_int);
        print(test_str);
        */
        return 0;
    }
    catch( domain_error &e )
    {
        cout << e.what();
        cout << endl << "no homework grades" << endl;
    }
    catch( runtime_error &e )
    {
        cerr << "runtime error:" << e.what() << endl;
        return 1;
    }
    catch( ... )
    {
        cout << "unknown exception !" << endl;
        return 2;
    }
}

