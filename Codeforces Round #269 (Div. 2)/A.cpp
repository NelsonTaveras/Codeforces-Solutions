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

int arr[123];

int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 6; ++i) {
        int x;
        cin >> x;
        arr[x]++;
    }
    for (int i = 0; i <= 9; ++i) {
        if (arr[i] >= 4) {
            if (arr[i] == 6) {
                cout << "Elephant" << endl;
                return 0;
            } else if (arr[i] == 5) {
                cout << "Bear" << endl;
                return 0;
            }
            for (int j = 0; j <= 9; ++j) {
                if (arr[j] == 2) {
                    cout << "Elephant" << endl;
                    return 0;
                }
            }
            cout << "Bear" << endl;
            return 0;
        }
    }
    cout << "Alien" << endl;
    return 0;
}
