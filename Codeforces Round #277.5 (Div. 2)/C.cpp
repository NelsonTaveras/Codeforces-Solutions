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

int length, sum;
int act[111][999];
bool cache[111][999];
bool memo[111][999];
bool minNumber(int id, int s) {
    if (s > sum)
        return 0;
    if (id >= length)
        return s == sum;
    if (cache[id][s])
        return memo[id][s];
    bool res = false;
    for (int i = (id == 0); i <= 9 && !res; ++i) {
        bool w = minNumber(id + 1, s + i);
        if (w) {
            res = w;
            act[id][s] = i;
        }
    }
    cache[id][s] = 1;
    return memo[id][s] = res;
}
bool maNumber(int id, int s) {
    if (s > sum)
        return 0;
    if (id >= length)
        return s == sum;
    if (cache[id][s])
        return memo[id][s];
    bool res = false;
    for (int i = 9; i >= (id == 0) && !res; --i) {
        bool w = maNumber(id + 1, s + i);
        if (w) {
            res = w;
            act[id][s] = i;
        }
    }
    cache[id][s] = 1;
    return memo[id][s] = res;
}
string getAns(int id, int s) {
    string res;
    while (1) {
        if (id >= length)
            break;
        int choice = act[id][s];
        res += (choice + '0');
        id++;
        s += choice;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> length >> sum;
    if(length == 1 && sum == 0){
        cout << 0 << ' ' << 0 << endl;
        return 0;
    }
    bool mi = minNumber(0, 0);
    if (mi) {
        cout << getAns(0, 0) << ' ';
    } else {
        cout << -1 << ' ';
    }
    memset(cache, 0, sizeof(cache));
    memset(act, 0, sizeof(act));
    bool ma = maNumber(0, 0);
    if (ma) {
        cout << getAns(0, 0) << ' ';
    } else {
        cout << -1;
    }
    return 0;
}
