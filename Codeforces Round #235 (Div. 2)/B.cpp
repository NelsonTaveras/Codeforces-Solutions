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
#include <ctime>
#include <cctype>
#include <bitset>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<llong, llong> PII;
typedef pair<llong, PII> PIP;
typedef vector<llong> VI;
typedef vector<VI> VVI;
const llong INF = (llong) 1e9;
#define MOD (llong)  1000000007
const llong MAXN = 100050;

int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    arr[n] = 1;
    for(int i = 0; i < k; ++i){
        int t, div2, div1;
        cin >> t >> div2;
        arr[div2]++;
        if(t == 1){
            cin >> div1;
            arr[div1]++;
        }
    }
    int cur = 0;
    int mi = 0;
    for(int i = 1; i <= n; ++i){
        if(arr[i] == 0)
            ++cur;
    }
    for(int i = 1; i <= n; ++i){
        if(arr[i] != 0) continue;
        if(i + 1 <= n && arr[i] == 0 && arr[i + 1] == 0){
            mi++;
            arr[i + 1] = 2;
        }else{
            mi++;
        }
    }
    cout << mi << ' ' << cur << endl;
    return 0;
}