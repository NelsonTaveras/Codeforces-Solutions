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

int used[1010];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    VI V(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }
    int M;
    cin >> M;
    VI V2(M);
    for (int i = 0; i < M; ++i) {
        cin >> V2[i];
    }
    sort(V.begin(), V.end());
    sort(V2.begin(), V2.end());
    int ans = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(used[j]) continue;
            if((abs(V[i] - V2[j]) <= 1)){
                ans++;
                used[j] = 1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

