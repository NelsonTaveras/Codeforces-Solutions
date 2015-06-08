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
typedef pair<llong, llong> PI;
typedef pair<llong, PI> PII;
typedef vector<llong> VI;
typedef vector<VI> VVI;
llong INF = (1LL << 62);
const int inf = (1LL << 30);
const llong maxn = (llong) 1e6 + 10;
const llong MOD = 1000000007;

llong n, l, x, y;
map<llong, bool> saw;
bool in(llong x) {
    return (x >= 0 && x <= l);
}
bool func(llong want, llong p) {
    if (in(p - want) && saw[p - want])
        return true;
    if (in(p + want) && saw[p + want])
        return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> l >> x >> y;
    VI V;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        saw[p] = 1;
        V.push_back(p);
    }
    for (int i = 0; i < n; ++i) {
        int p = V[i];
        saw[x] = saw[x] | func(x, p);
        saw[y] = saw[y] | func(y, p);
    }
    if (saw[x] && saw[y]) {
        cout << 0 << endl;
        return 0;
    }
    if (saw[x] && !saw[y]) {
        cout << 1 << endl;
        cout << y << endl;
        return 0;
    }
    if (!saw[x] && saw[y]) {
        cout << 1 << endl;
        cout << x << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        int p = V[i];
        if (in(p - x) && func(y, p - x)) {
            cout << 1 << endl;
            cout << p - x << endl;
            return 0;
        }
        if (in(p + x) && func(y, p + x)) {
            cout << 1 << endl;
            cout << p + x << endl;
            return 0;
        }
        if (in(p - y) && func(x, p - y)) {
            cout << 1 << endl;
            cout << p - y << endl;
            return 0;
        }
        if (in(p + y) && func(x, p + y)) {
            cout << 1 << endl;
            cout << p + y << endl;
            return 0;
        }
    }
    cout << 2 << endl;
    cout << x << ' ' << y << endl;
    return 0;
}
