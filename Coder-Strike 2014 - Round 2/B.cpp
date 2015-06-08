#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
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
llong INF = (1LL<<62);

int mat[30005][12];
int writed[30005][12];
int cnt[12];
int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            scanf("%d", &mat[i][j]);
    for(int i = 0; i < k; ++i){
        int x, y;
        scanf("%d %d", &x, &y);
        --x, --y;
        cnt[y]++;
        writed[x][y]++;
    }
    for(int i = 0; i < n; ++i){
        int ans = 0;
        for(int j = 0; j < m; ++j){
            if(mat[i][j] > 0){
                ans += cnt[j];
                ans -= writed[i][j];
            }
        }
        cout << ans << ' ';
    }
    return 0;
}