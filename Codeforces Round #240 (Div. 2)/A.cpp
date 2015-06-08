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

int ans[150];
int l[150];

int main()
{
    // freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    memset(ans, -1, sizeof(ans));
    for(int i = 0; i < m; ++i) cin >> l[i];
    for(int i = 0; i < m; ++i){
        for(int j = l[i]; j <= n; ++j)
            if(ans[j] == -1)
                ans[j] = l[i];
    }
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    return 0;
}