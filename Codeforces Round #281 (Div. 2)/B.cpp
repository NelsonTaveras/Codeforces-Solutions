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
typedef pair<llong, llong> PII;
typedef pair<llong, PII> PIP;
typedef vector<llong> VI;
typedef vector<VI> VVI;

llong INF = (1LL << 62);
const llong inf = (1LL << 30);
const llong maxn = (llong) 1e6 + 10;
const llong MOD = 1000000007;

int main() {
    llong n;
    cin >> n;
    VI v1, v2;
    llong suma = 0, sumb = 0;
    llong lasta;
    for (llong i = 0; i < n; ++i) {
        llong a;
        cin >> a;
        lasta = a;
        if (a < 0) {
            v2.push_back(-1 * a);
            sumb += v2.back();
        } else {
            v1.push_back(a);
            suma += v1.back();
        }
    }

    if (suma == sumb) {
        if (v1 == v2) {
            cout << (lasta < 0 ? "second" : "first") << endl;
            return 0;
        }
        llong mi = min((llong) v1.size(), (llong) v2.size());
        for (llong i = 0; i < mi; ++i) {
            if (v1[i] == v2[i])
                continue;
            if (v1[i] > v2[i]) {
                cout << "first" << endl;
                return 0;
            } else {
                cout << "second" << endl;
                return 0;
            }
        }
        if (v1.size() != mi) {
            cout << "first" << endl;
            return 0;
        }
        cout << "second" << endl;
        return 0;
    }else{
        cout << (sumb > suma ? "second" : "first") << endl;
    }

    return 0;
}