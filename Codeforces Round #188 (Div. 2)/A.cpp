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
    long long N, K;
    cin >> N >> K;
    
    if( N%2 == 0 )
    {
        if( K <= N / 2 )
        {
            cout << (2 * K) - 1;
            return 0;
        }
        else
        {
            K -= (N/2);
            cout << 2 * K;
            return 0;
        }
            
    }
    else
    {
        if( K <= ((N/2) + 1 ) )
        {
            cout << (2 * K) - 1;
            return 0;
        }
        else
        {
            K -= ((N/2)+1);
            cout << 2 * K;
            return 0;
        }
    }
            
    return 0;
}
