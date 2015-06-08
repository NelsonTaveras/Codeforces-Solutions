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
typedef pair<llong, llong> PII;
typedef pair<llong, PII> PIP;
typedef vector<llong> VI;
typedef vector<VI> VVI;
const int INF = (llong) 1e9;
#define MOD (llong)  1000000007
const llong MAXN = 100050;

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    while(tc--){
        int n, p;
        cin >> n >> p;
        int e = 2 * n + p;
        vector<PII> ANS;
        int cur = 0;
        for(int i = 1; i <= n && cur < e; ++i){
            for(int j = i + 1; j <= n && cur < e; ++j){
                cout << i << ' ' << j;
                cout << endl;
                cur++;
            }
        }
    }

    return 0;
}