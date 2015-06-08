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
typedef unsigned long long llong;
typedef pair<llong, llong> PI;
typedef pair<PI, llong> PII;
typedef vector<llong> VI;
typedef vector<VI> VVI;
llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (llong) 1e5 + 5;
const int MOD = 1000000007;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<PI> tasks;
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        tasks.push_back(mp(h, i));
    }
    sort(tasks.begin(), tasks.end());
    VI V;
    for (int i = 0; i < n - 1; ++i) {
        if (tasks[i].first == tasks[i + 1].first)
            V.push_back(i);
    }

    if (V.size() < 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i)
            cout << tasks[i].second + 1 << ' ';
        cout << endl;
        swap(tasks[V[0]], tasks[V[0] + 1]);
        for (int i = 0; i < n; ++i)
            cout << tasks[i].second + 1 << ' ';
        cout << endl;
        swap(tasks[V[1]], tasks[V[1] + 1]);
        for (int i = 0; i < n; ++i)
            cout << tasks[i].second + 1 << ' ';
        cout << endl;
    }
    return 0;
}
