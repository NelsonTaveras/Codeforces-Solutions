#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int r;
    string e;
    cin >> e >> r;  
    if(e[0] == 'f')
    {
        if(r == 1 )
            cout << "L";
        else
            cout << "R";
    }
    else
    {
        if ( r == 1 )
            cout << "R";
        else
            cout << "L";
        }
    return 0;
}
 