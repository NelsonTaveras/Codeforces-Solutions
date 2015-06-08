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
llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (int) 1e6 + 5;
const int MOD = 1000000007;

using namespace std;

llong p[2020][2020];
llong s[2020][2020];
int m[2020][2020];
llong ans[2020][2020];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
            p[i][j] = s[i][j] = m[i][j];
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i - 1 >= 0 && j - 1 >= 0)
                p[i][j] += p[i - 1][j - 1];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i - 1 >= 0 && j + 1 < n)
                s[i][j] += s[i - 1][j + 1];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int dp = min(n - i - 1, n - j - 1);
            int ds = min(n - i - 1, j);
            ans[i][j] += p[i + dp][j + dp];
            ans[i][j] += s[i + ds][j - ds];
            ans[i][j] -= m[i][j];
        }
    PI bw = mp(0, 0);
    PI bb = mp(0, 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if ((i + j) & 1) {
                if (ans[i][j] > ans[bw.first][bw.second])
                    bw = mp(i, j);
            } else {
                if (ans[i][j] > ans[bb.first][bb.second])
                    bb = mp(i, j);
            }
        }
    cout << ans[bw.first][bw.second] + ans[bb.first][bb.second] << endl;
    cout << bw.first + 1 << ' ' << bw.second + 1 << ' ' << bb.first + 1 << ' ' << bb.second + 1<< endl;
    return 0;
}
