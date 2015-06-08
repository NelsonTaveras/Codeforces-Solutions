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
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (int) 1e6 + 5;
const int MOD = 1000000007;

using namespace std;

char arr[150];

int main() {
    int len;
    string S;
    cin >> len >> S;
    int f = 1;
    string tmp;
    for (int i = 0; i < len; ++i) {
        if (S[i] == '0')
            f--;
        if (f > 0)
            tmp += '0';
        else if (f == 0)
            tmp += '1';
        else
            tmp += S[i];
    }
    int ans = 0;
    for (int i = 0; i < len; ++i)
        if (S[i] != tmp[i])
            ++ans;
    cout << ans << endl;
    return 0;
}
