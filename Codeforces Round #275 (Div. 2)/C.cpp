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
typedef pair<int, int> PI;
typedef pair<int, PI> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (int) 1e5 + 10;
const int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        for (int i = 1; i <= n; ++i)
            cout << i << ' ';
        return 0;
    }
    VI V;
    V.push_back(1);
    set<int> used;
    used.insert(1);
    int tmp = k;
    for (int i = 2; i <= n; ++i) {
        int prev = V.back();
        if (prev > k) {
            if (used.count(prev - k) == 0) {
                V.push_back(prev - k);
                used.insert(prev - k);
            } else {
                V.push_back(prev + k);
                used.insert(prev + k);
            }
        } else {
            if (used.count(prev + k) == 0) {
                V.push_back(prev + k);
                used.insert(prev + k);
            } else {
                V.push_back(prev - k);
                used.insert(prev - k);
            }
        }
        k--;
        if (k < 1) break;
    }
    set<int> left;
    for(int i = 1; i <= n; ++i)
        left.insert(i);
    for(int i = 0; i < V.size(); ++i)
        left.erase(V[i]);
    for(set<int>::iterator it = left.begin(); it != left.end(); ++it)
        V.push_back(*it);
    for (int i = 0; i < V.size(); ++i) {
        cout << V[i] << ' ';
    }
    return 0;
}
