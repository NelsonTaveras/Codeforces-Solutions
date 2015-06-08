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
const int maxn = (int) 3e5 + 5;
const int MOD = 1000000007;

using namespace std;

map<llong, llong> freq;

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<llong> V(n);
    for(int i = 0; i < n; ++i){
        cin >> V[i];
        freq[V[i]]++;
    }
    sort(V.begin(), V.end());
    llong ways = 0;
    if(V.front() == V.back()){
        ways = 1LL*n * (n - 1) / 2;
    }else{
        ways = freq[V.front()] * freq[V.back()];
    }
    cout << V.back() - V.front() << ' ' << ways << endl;
    return 0;
}
