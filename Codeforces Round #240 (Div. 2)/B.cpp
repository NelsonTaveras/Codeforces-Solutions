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
#include <ctime>
#include <cctype>
#include <bitset>
using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<llong> VI;
typedef vector<VI> VVI;
const int INF = (llong) 1e9 + 50;
#define MOD (llong)  1000000007
const llong MAXN = 100050;

int main()
{
    // freopen("input.txt", "r", stdin);
    llong n, a, b;
    cin >> n >> a >> b;
    for(int i = 0; i < n; ++i){
        llong t;
        cin >> t;

        llong mx = t * a / b;
        llong lo = 0, hi = t;
        while(lo < hi){
            llong mid = lo + (hi-lo)/2;
             if( (mid * a / b) >= mx )
                 hi = mid;
              else
                 lo = mid+1;
        }
        cout << t - lo << ' ';
    }
    return 0;
}