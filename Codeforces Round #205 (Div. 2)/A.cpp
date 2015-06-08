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

using namespace std;

#define mp make_pair

#define MAXN (int) 1e5 + 5
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 2e9;

int N;
int a[101];
int b[101];
int memo[101][601][601];
int dp(int idx, int sumup, int sumdown)
{
    if(idx >= N)
    {
        if(sumup % 2) return INF;
        if(sumdown % 2) return INF;
        //cout << sumup << " " << sumdown << endl;
        return 0;
    }
    if(memo[idx][sumup][sumdown] != -1) 
        return memo[idx][sumup][sumdown];
    int res = INF;
    res = min(res, dp(idx + 1, sumup + a[idx], sumdown + b[idx]));
    res = min(res, 1 + dp(idx + 1, sumup + b[idx], sumdown + a[idx]));
    return memo[idx][sumup][sumdown] = res;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> a[i] >> b[i];
    }
    memset(memo, -1, sizeof(memo));
    int ret = dp(0, 0, 0);
    if(ret == INF) cout << -1 << endl;
    else cout << ret << endl;
    return 0;
}