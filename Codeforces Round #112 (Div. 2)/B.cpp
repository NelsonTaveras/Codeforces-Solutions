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

typedef unsigned long long ullong;
typedef long long llong;
typedef vector<llong> VI;
typedef vector<VI> VII;

llong N, K;
llong powM(llong a, llong b)
{
    llong ret = 1;
    while( b > 0 )
        ret *= a, b--;
    return ret;
}

bool check(llong v)
{
    int exp = 1;
    llong sum = v;
    while(true)
    {
        llong lines = v / (powM(K, exp));
        if( lines == 0 || sum >= N)
            break;
        sum += lines;
        exp++;
    }
    return sum >= N;
}

int main()
{
    cin >> N >> K;
    llong lo = 0, hi = 100000000000;
    while( lo < hi )
    {
        llong mid = lo + (hi - lo)/2;
        if(check(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo;
    return 0;
}
