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

int main() {
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    if (N == 0) {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 1 << endl;
        cout << 3 << endl;
        cout << 3 << endl;
        return 0;
    }
    VI V;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        V.push_back(x);
    }
    if (N == 1) {
        for (int a = 1; a <= 2000; ++a) {
            VI tmp = V;
            tmp.push_back(V[0]);
            tmp.push_back(a);
            tmp.push_back(a);
            if ((tmp[0] + tmp[1] + tmp[2] + a) % 4 != 0)
                continue;
            sort(tmp.begin(), tmp.end());
            if ((tmp[1] + tmp[2]) % 2 != 0)
                continue;
            int mean = (tmp[0] + tmp[1] + tmp[2] + tmp[3]) / 4;
            int median = (tmp[1] + tmp[2]) / 2;
            int range = tmp[3] - tmp[0];
            if (mean == median && median == range) {
                cout << "YES" << endl;
                cout << V[0] << endl;
                cout << a << endl;
                cout << a << endl;
                return 0;
            }
        }
    } else if (N == 2) {
        for (int a = 1; a <= 2000; ++a)
            for (int b = 1; b <= 2000; ++b) {
                VI tmp = V;
                if ((tmp[0] + tmp[1] + a + b) % 4 != 0)
                    continue;
                tmp.push_back(a);
                tmp.push_back(b);
                sort(tmp.begin(), tmp.end());
                if ((tmp[1] + tmp[2]) % 2 != 0)
                    continue;
                int mean = (tmp[0] + tmp[1] + tmp[2] + tmp[3]) / 4;
                int median = (tmp[1] + tmp[2]) / 2;
                int range = tmp[3] - tmp[0];
                if (mean == median && median == range) {
                    cout << "YES" << endl;
                    cout << a << endl;
                    cout << b << endl;
                    return 0;
                }

            }
    } else if (N == 3) {
        for (int a = 1; a <= 2000; ++a) {
            VI tmp = V;
            if ((tmp[0] + tmp[1] + tmp[2] + a) % 4 != 0)
                continue;
            tmp.push_back(a);
            sort(tmp.begin(), tmp.end());
            if ((tmp[1] + tmp[2]) % 2 != 0)
                continue;
            int mean = (tmp[0] + tmp[1] + tmp[2] + tmp[3]) / 4;
            int median = (tmp[1] + tmp[2]) / 2;
            int range = tmp[3] - tmp[0];
            if (mean == median && median == range) {
                cout << "YES" << endl;
                cout << a << endl;
                return 0;
            }
        }
    } else if (N == 4) {
        VI tmp = V;
        if ((tmp[0] + tmp[1] + tmp[2] + tmp[3]) % 4 == 0) {
            sort(tmp.begin(), tmp.end());
            if ((tmp[1] + tmp[2]) % 2 == 0) {
                int mean = (tmp[0] + tmp[1] + tmp[2] + tmp[3]) / 4;
                int median = (tmp[1] + tmp[2]) / 2;
                int range = tmp[3] - tmp[0];
                if (mean == median && median == range) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}