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
llong INF = (1LL<<62);
const int inf = (1LL<<30);
const int maxn = (int) 1e5 + 5;
const int MOD = 1000000007;

int arr[maxn];
int li[maxn];
int ld[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = 0; i <= n; ++i) li[i] = ld[i] = 1;
    for(int i = 1; i < n; ++i)
        if(arr[i - 1] < arr[i])
            li[i] = max(li[i], li[i - 1] + 1);
    for(int i = n - 2; i >= 0; --i)
        if(arr[i] < arr[i + 1])
            ld[i] = max(ld[i], ld[i + 1] + 1);
//  for(int i = 0; i < n; ++i)
//      cout << li[i] << ' ';
//  cout << endl;
//  for(int i = 0; i < n; ++i)
//      cout << ld[i] << ' ';
//  cout << endl;
    int ma = (n == 1 ? 1 : 2);
    for(int i = 0; i < n; ++i){
        ma = max(ma, li[i]);
        if(i > 0) ma = max(ma, li[i - 1] + 1);
    }
    for(int i = 1; i < n; ++i)
        if(arr[i - 1] == arr[i])
            ma = max(ma, li[i - 1] + 1);
    for(int i = n - 2; i >= 0; --i){
        ma = max(ma, ld[i]);
        if(i + 1 < n) ma = max(ma, ld[i + 1] + 1);
    }
    for(int i = n - 2; i >= 0; --i)
        if(arr[i + 1] == arr[i])
            ma = max(ma, ld[i + 1] + 1);
    for(int i = 1; i < n - 1; ++i){
        if(arr[i - 1] + 1 < arr[i + 1])
            ma = max(ma, li[i - 1] + ld[i + 1] + 1);
    }
    cout << ma << endl;
    return 0;
}
