#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string S;
    cin >> S;

    int in = 0, out = 0;
    int cur = 0;
    for(int i = 0; i < S.size(); ++i)
    {
        if( S[i] == '+' )
        {
            if( out == 0 )
                cur++, in++;
            else
                out--, in++;
        }
        else
        {
            if( in == 0 )
                cur++, out++;
            else
                in--, out++;
        }
    }
    cout << cur;
    return 0;
}
