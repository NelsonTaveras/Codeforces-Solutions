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

#define MAXN (int) 100005
#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 2e9;

int arr[MAXN];
int memo[MAXN][2][2];
int N;
int dp(int id, int type, int pos)
{
	if(id >= N) return ( (type == 0 || pos == 0) ? INF : 0 );
	if(memo[id][type][pos] != -1) return memo[id][type][pos];
	int ret = INF;
	if(type == 0)
	{
		ret = min(ret, (arr[id] >= 0 ? 1 : 0 ) + dp(id + 1, 0, pos));
		ret = min(ret, (arr[id] >= 0 ? 1 : 0 ) + dp(id + 1, 1, pos));
	}
	else
	{
		ret = min(ret, (arr[id] <= 0 ? 1 : 0) + dp(id + 1, 1, max(pos, 1)));
	}
	return memo[id][type][pos] = ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; ++i)
    	cin >> arr[i];
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0, 0) << endl;
    return 0;
}