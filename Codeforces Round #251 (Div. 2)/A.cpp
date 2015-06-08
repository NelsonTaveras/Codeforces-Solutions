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

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL<<62);
const int inf = (1LL<<30);
const int maxn = (int) 1e9 + 5;
const int MOD = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int n, d;
    cin >> n >> d;
    int used = 0;
    for(int i = 0; i < n; ++i){
        if(i > 0) used += 10;
        int t;
        cin >> t;
        used += t;
    }
    if(used > d){
        cout << -1 << endl;
        return 0;
    }
    int jokes = 0;
    while(used + 5 <= d)
        ++jokes, used += 5;
    cout << jokes + (n - 1)*2 << endl;
    return 0;
}