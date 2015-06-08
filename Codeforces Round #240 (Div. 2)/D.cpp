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

VVI adj;
int n, k;
int memo[2001][2001];
int dp(int prev, int got){
    if(got == k) return 1;
    if(prev == n) return 1;
    if(memo[prev][got] != -1) return memo[prev][got];
    int ways = 0;
    for(int i = 0; i < adj[prev].size(); ++i){
        ways += dp(adj[prev][i], got + 1);
        if(ways >= MOD) ways -= MOD;
    }
    return memo[prev][got] = ways % MOD;
}
int main()
{
    // freopen("input.txt", "r", stdin);

    adj = VVI(2005);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            if(j % i == 0)
                adj[i].push_back(j);
        }
    }
    memset(memo, -1, sizeof(memo));
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += dp(i, 1);
        if(ans >= MOD) ans -= MOD;
    }
    cout << (ans + MOD)%MOD << endl;
    return 0;
}