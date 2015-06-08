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
    
llong N, M;
llong arr[MAXN];
llong pre[25];
set<llong> arr2[20];
llong lo(llong pos, llong N, llong bit){
    // left zero
    set<llong>::iterator it;
    it = arr2[bit].lower_bound(pos);
    if(it == arr2[bit].begin()) return pos;
    --it;
    //cout << pos << '*' << *it << endl;
    // 0-1-0 --> 0-1-1
    return pos - *it - 1;
}
llong hi(llong pos, llong N, llong bit){
    // right zero
    set<llong>::iterator it;
    it = arr2[bit].upper_bound(pos);
    if(it == arr2[bit].end()) return N - pos - 1;
    return *it - pos - 1;
}
llong get(llong cnt){
    return (cnt * (cnt+1))/2;
}
llong update(llong p, llong v, llong bit, llong last){
    llong bef = (arr[p] & (1<<bit)) != 0;
    if(v == 1 && bef == 0){
        // 0 to 1
        // 0 1 0 - > 0 1 1
        // cout << " - > " << last << endl;
        llong left = lo(p, N, bit);
        llong right = hi(p, N, bit);
        // cout << left << '-' << right << endl;
        last -= (1LL<<bit) * get(left);
        last -= (1LL<<bit) * get(right);
        last += (1LL<<bit) * get(left + right + 1);
        arr2[bit].erase(p);
    }else if(v == 0 && bef == 1){
        // 1 to 0
        arr2[bit].insert(p);
        llong left = lo(p, N, bit);
        llong right = hi(p, N, bit);
        last -= (1LL<<bit) * get(left + right + 1);
        last += (1LL<<bit) * get(left);
        last += (1LL<<bit) * get(right);
    }
    return last;
}
int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for(llong i = 0; i < N; ++i) cin >> arr[i];
    llong ans = 0;
    for(llong bit = 0; bit <= 19; ++bit){
        VI tmp;
        for(llong i = 0; i < N; ++i){
            if( (arr[i] & (1<<bit)) == 0 ) arr2[bit].insert(i);
            tmp.push_back( (arr[i] & (1<<bit)) != 0);
        }
        llong i = 0;
        while(i < tmp.size()){
            if(tmp[i] == 0){
                i++;
                continue;
            }
            llong cnt = 1;
            while(i + 1 < tmp.size() && tmp[i + 1] == 1)
                i++, cnt++;
            i++;
            pre[bit] += (1LL<<bit) * get(cnt);
        }
        // cout << bit << " - > ";
        // for(llong i = 0; i < tmp.size(); ++i) cout << tmp[i] << ' ';
        // cout << " = " << pre[bit];
        // cout << endl;
        ans += pre[bit];
    }
    while(M--){
        llong p, v;
        cin >> p >> v;
        --p;
        llong ans = 0;
        for(llong bit = 0; bit <= 19; ++bit){
            llong aux = update(p, (v & (1<<bit)) != 0, bit, pre[bit]);
            ans += aux;
            pre[bit] = aux;
        }
        arr[p] = v;
        cout << ans << endl;
    }
    return 0;
}