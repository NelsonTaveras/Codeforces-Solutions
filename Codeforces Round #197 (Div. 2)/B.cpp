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
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef long long llong;

using namespace std;

llong arr[100005];
llong N, M;
llong dist(int cur, int i){
    llong d = 0;
    if(cur > i){
        d += abs(cur - N);
        d += i;
    }
    else
        d += abs(cur - i);
    return d;
}

int main()
{
    ios_base::sync_with_stdio(false);


    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        cin >> arr[i];
    }
    int cur = 1;
    llong res = 0;
    for(int i = 0; i < M; ++i){
        //cout << cur << ' ' << arr[i] << " - > " << dist(cur, arr[i]) << endl;
        res += dist(cur, arr[i]);
        cur = arr[i];
    }
    cout << res;
    return 0;
}
