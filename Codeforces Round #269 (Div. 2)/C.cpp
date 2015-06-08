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

llong f(llong x){
    return (x * (x + 1)) + ((x - 1) * (x) / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    llong N;
    cin >> N;
    int res = 0;
    for(int i = 1; ; ++i){
        llong p = f(i);
        if(p > N) break;
        if(p == N){
            res++;
        }else{
            llong left = N - p;
            if(left % 3 == 0) res++;            
        }
    }
    cout << res << endl;
    return 0;
}
