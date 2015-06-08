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

bool cached[1010][1010];
double memo[1010][1010];
double dp(int w, int b, int turn){
    if(w == 0) return 0;
    if(cached[w][b]) return memo[w][b];
    double p = 0;
    if(turn == 0){
        p += (1.0 * w/(w + b));
        if(b > 0) p += (1.0 * b/(w + b)) * (1 - dp(w, b - 1, turn ^ 1));
    }else{
        p += (1.0 * w/(w + b));
        if(b > 0){
            if(b > 1) p += (1.0 * b/(w + b)) * (1.0 * (b-1) / (w + b - 1)) * (1 - dp(w, b - 2, turn ^ 1));
            p += (1.0 * b/(w + b)) * (1.0 * w/(w + b - 1)) * (1 - dp(w - 1, b - 1, turn ^ 1));
        }
    }
    cached[w][b] = 1;
    return memo[w][b] = p;
}

int main(){
    int w, b;
    cin >> w >> b;
    printf("%.10lf\n", dp(w, b, 0));
    return 0;
}
