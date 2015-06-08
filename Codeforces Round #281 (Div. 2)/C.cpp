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

int f[maxn], s[maxn];

int getScoreA(int d, int n) {
    if (f[0] > d)
        return 3 * n;
    if (f[n - 1] <= d)
        return 2 * n;
    int a = 0;
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (!(f[mid] <= d))
            hi = mid - 1;
        else
            lo = mid;
    }
    a += (lo + 1) * 2;
    a += (n - lo - 1) * 3;
    return a;
}
int getScoreB(int d, int n) {
    if (s[0] > d)
        return 3 * n;
    if (s[n - 1] <= d)
        return 2 * n;
    int b = 0;
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (!(s[mid] <= d))
            hi = mid - 1;
        else
            lo = mid;
    }
    b += (lo + 1) * 2;
    b += (n - lo - 1) * 3;
    return b;
}

PII func(int d, int n, int m) {
    if (d < 0)
        return make_pair(0, 0);
    int a = getScoreA(d, n);
    int b = getScoreB(d, m);
    return make_pair(a, b);
}
PII relax(PII ans, PII tmp) {
    PII res = ans;
    int ansdif = ans.first - ans.second;
    int tmpdif = tmp.first - tmp.second;
    if (tmpdif > ansdif)
        res = tmp;
    else if (tmpdif == ansdif && tmp.first > ans.first)
        res = tmp;
    return res;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &f[i]);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
        scanf("%d", &s[i]);
    sort(f, f + n);
    sort(s, s + m);

    func(3, n, m);

    PII ans = make_pair(-inf, inf);

    for (int i = 0; i < n; ++i) {
        PII tmp = func(f[i], n, m);
        ans = relax(ans, tmp);
        tmp = func(f[i] - 1, n, m);
        ans = relax(ans, tmp);
        tmp = func(f[i] + 1, n, m);
        ans = relax(ans, tmp);
    }
    for (int i = 0; i < m; ++i) {
        PII tmp = func(s[i], n, m);
        ans = relax(ans, tmp);
        tmp = func(s[i] - 1, n, m);
        ans = relax(ans, tmp);
        tmp = func(s[i] + 1, n, m);
        ans = relax(ans, tmp);
    }

    cout << ans.first << ':' << ans.second << endl;
    return 0;
}
