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

int dis[555][555];
int arr[1234567];
int used[1234567];
string mat[1234567];

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < n; ++i)
        cin >> mat[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dis[i][j] = (mat[i][j] == '0' ? false : true);
    for (int i = 0; i < n; ++i)
        dis[i][i] = true;
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) 
                dis[i][j] = (dis[i][j]) || (dis[i][k] && dis[k][j]);
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            if(dis[j][i] && arr[j] < arr[i]){
                swap(arr[i], arr[j]);
            }
        }
    }
    for(int i = 0; i < n; ++i)
        cout << arr[i] << ' ';
    return 0;
}
