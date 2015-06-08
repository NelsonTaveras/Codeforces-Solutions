#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>

using namespace std;

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VII;

int main()
{
    llong x, y, m;
    cin >> x >> y >> m;

    if( x >= m || y >= m )
        cout << 0;
    else if( x <= 0 && y <= 0 )
        cout << -1;
    else
    {
        llong ans = 0;
        if( x < 0 )
        {
            ans += (-x/y);
            x += ( y * (-x/y) );
        }
        else if( y < 0 )
        {
            ans += (-y/x);
            y += ( x * (-y/x) );
        }

        while( x < m || y < m )
        {
            if( x > y )
                swap(x, y);
            x += y;
            ans++;
        }
        cout << ans - 1;
    }
    return 0;
}
