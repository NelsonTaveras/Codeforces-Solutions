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
int ans[(int) 1e6 + 100];
int main()
{
    // freopen("input.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; ++i) cin >> arr[i];
    set<int> cur;
    for(int i = N - 1; i >= 0; --i){
        cur.insert(arr[i]);
        ans[i + 1] = (int) cur.size();
    }
    for(int i = 0; i < M; ++i){
        int l;
        cin >> l;
        cout << ans[l] << endl;
    }
    return 0;
}
