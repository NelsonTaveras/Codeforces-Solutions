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
llong INF = 4e18;

int saw[1001][1001];

int main()
{
    // ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);
    vector<PI> ans;
    memset(saw, -1, sizeof(saw));
    for(int i = 0; i < n; ++i){
        int tmp = k;
        for(int j = 0; j < n && tmp > 0; ++j){
            if(i != j && saw[i][j] == -1){
                tmp--;
                saw[i][j] = saw[j][i] = 1;
                ans.push_back(mp(i + 1, j + 1));
            }
        }
    }
    if((int)ans.size() != n * k){
        cout << -1 << endl;
        return 0;
    }
    cout << n * k << endl;
    for(int i = 0; i < ans.size(); ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}