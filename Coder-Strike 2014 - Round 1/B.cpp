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

int arr[150];

int main()
{
    // ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    int ma = 0;
    for(int i = 0; i < n; ++i){
        int wanted = arr[i];
        int cnt = 0;
        for(int j = 0; j < n; ++j){
            if(arr[j] >= wanted) cnt++;
        }
        if(cnt >= k) ma = max(ma, wanted);
    }
    cout << ma << endl;
    return 0;
}