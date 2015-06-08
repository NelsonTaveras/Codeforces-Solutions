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
typedef pair<PII, char> PIC;
typedef pair<int, char> PICD;
const int INF = (int) 2e9;

llong sum[1000010];
llong arr[1000010];
llong func(int l, int r)
{
    return sum[r] - (l ? sum[l - 1] : 0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; ++i) cin >> arr[i];
    for(int i = 1; i <= N; ++i) sum[i] = arr[i - 1] + sum[i - 1];
    llong ret = 1LL<<60;
    int b = 0;
    for(int i = 0; i <= N-K; ++i){
        llong f = func(i + 1, i + K);
        if(f < ret){
            ret = f;
            b = i + 1;
        }
    }
    cout << b << endl;
    return 0;
}
