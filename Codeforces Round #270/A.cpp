#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <ctime>
#include <set>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>

using namespace std;

#define mp make_pair7
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (int) 1e5 + 5;
const int MOD = 1000000007;

using namespace std;

bool p[1234567];

int main() 
{
    int n;
    cin >> n;
    p[0] = p[1] = 1;
    for(llong i = 2; i <= 1000000; ++i)
        for(llong j = i * i; j <= 1000000; j += i)
            p[j] = 1;
    for(int i = 2; i <= 1000000; ++i){
        if(i >= n) break;
        int d = n - i;
        if(d > 1 && p[d] && p[i]){
            cout << i << ' ' << d << endl;
            return 0;
        }
    }
    return 0;
}
