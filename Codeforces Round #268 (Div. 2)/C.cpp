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

int used[1234567];

/*
 1 2 3 4 5 6 7
 */

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n <= 3) {
        cout << "NO" << endl;
        return 0;
    }
    if (n == 4) {
        cout << "YES" << endl;
        cout << "3 * 2 = 6" << endl;
        cout << "6 * 1 = 6" << endl;
        cout << "6 * 4 = 24" << endl;
        return 0;
    }
    if (n == 5) {
        cout << "YES" << endl;
        cout << "5 + 1 = 6" << endl;
        cout << "6 * 4 = 24" << endl;
        cout << "3 - 2 = 1" << endl;
        cout << "24 * 1 = 24" << endl;
        return 0;
    }
    
    cout << "YES" << endl;
    cout << "6 * 4 = 24" << endl;
    int left = (n == 6 ? 5 : n);
    int top = left;
    used[6] = used[4] = used[top] = 1;
    int p = left - 1;
    while(left > 0){
        if(p == 6 || p == 4 || (left - p < 0)){
            p--;
            continue;
        }
        used[p] = 1;
        cout << left << " - " << p << " = " << left - p << endl;
        left -= p;
        p--;
    }
    for(int i = 1; i <= n; ++i){
        if(used[i] == 0){
            cout << 0 << " * " << i << " = " << 0 << endl;
            used[i] = 1;
        }
    }
    cout << "24 + 0 = 24" << endl;
    return 0;
}
