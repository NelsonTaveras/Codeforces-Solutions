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

int arr[maxn];

int main() {
    
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    for(int i = 0; i < n - 1; ++i){
        cin >> arr[i];
    }
    int cur = 1;
    while(cur <= n - 1 && cur != t){
        cur += arr[cur - 1];
    }
    cout << (cur == t ? "YES" : "NO") << endl;
    return 0;
}




