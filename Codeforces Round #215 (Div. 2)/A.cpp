#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIIP;
const int INF = (int) 2e9;

int arr[(int) 1e6 + 100];

int main()
{
    // freopen("input.txt", "r", stdin);
    int n, d;
    cin >> n >> d;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    int m;
    cin >> m;
    int cur = 0;
    int tot = 0;
    for(int i = 0; i < m; ++i){
        if(cur < n){
            tot += arr[cur];
            cur++;
        }
        else{
            tot -= d;
        }
    }
    cout << tot << endl;
    return 0;
}
