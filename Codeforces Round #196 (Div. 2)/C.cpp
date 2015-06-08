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

#define MOD 1000000009
#define mp make_pair
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef long long llong;
const int INF = 1e9;
using namespace std;

llong func(llong base, llong exp)
{
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;
	llong ret = func(base, exp / 2);
	ret = ((ret%MOD) * (ret%MOD)) % MOD;
	if(exp & 1)
		ret = ((base%MOD) * (ret%MOD))%MOD;
	return ret % MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    llong tot, ans, K;
    cin >> tot >> ans >> K;
    llong gaps = tot / K;
    if(ans + gaps <= tot){
        cout << ans;
        return 0;
    }
    else
    {
        llong d = abs(ans - (tot - gaps));
        llong ret = func(2, d + 1) - 2;
        ret = ((ret%MOD) * (K%MOD))%MOD;
        llong extra = ((ans%MOD) - ((K%MOD)*(d%MOD)%MOD))%MOD;
        llong ANS = ret + extra;
        ANS %= MOD;
        if(ANS < 0)
        	ANS += MOD;
        cout << ANS % MOD;
    }
	return 0;
}