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
#include <bitset>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;

llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (llong) 1e6 + 10;
const int MOD = 1000000007;

int b[110][110];
int a[110][110];

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int z = 0;
            for (int k = 0; k < m; ++k)
                if (b[i][k] == 0)
                    z++;
            for (int k = 0; k < n; ++k)
                if (b[k][j] == 0)
                    z++;
            if (z == 0)
                a[i][j] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int res = 0;
            for (int k = 0; k < m; ++k)
                res |= a[i][k];
            for (int k = 0; k < n; ++k)
                res |= a[k][j];
            if (res != b[i][j]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
