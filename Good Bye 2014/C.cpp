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

int weight[1234567];
int book[1234567];
int used[1234567];

int main() {

    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int w;
        cin >> w;
        weight[i] = w;
    }
    VI V;
    for (int i = 0; i < m; ++i) {
        int b;
        cin >> b;
        if(!used[b]){
            V.push_back(b);
        }
        used[b] = 1;
        book[i] = b;
    }
    int ans = 0;
    for(int i = 0; i < m; ++i){
        int b = book[i];
        for(int j = 0; j < n; ++j){
            if(V[j] == b){
                while(j > 0){
                    swap(V[j], V[j - 1]);
                    j--;
                }
                break;
            }else{
                ans += weight[V[j] - 1];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
