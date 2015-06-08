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

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 2e9;
#define MOD (llong)  100999

struct Node{
    int mi;
    int gcd;
};

int arr[300010];
Node tree[4 * 300010];
int N;
void build(int idx = 1, int l = 0, int r = N - 1)
{
    if(l == r){
        tree[idx].mi = arr[l];
        tree[idx].gcd = arr[l];
    }
    else
    {
        int ll = 2 * idx;
        int rr = ll + 1;
        int mid = (l + r) / 2;
        build(ll, l, mid);
        build(rr, mid + 1, r);
        tree[idx].mi = min(tree[ll].mi, tree[rr].mi);
        tree[idx].gcd = __gcd(tree[idx].gcd, __gcd(tree[ll].gcd, tree[rr].gcd));
    }
}
Node query(int i, int j, int idx = 1, int l = 0, int r = N - 1)
{
    Node IMPOS;
    IMPOS.mi = INF;
    IMPOS.gcd = INF;
    if(i > r || j < l) return IMPOS;
    if(l >= i && r <= j) return tree[idx];
    int ll = 2 * idx;
    int rr = ll + 1;
    int mid = (l + r) / 2;
    Node son1 = query(i, j, ll, l, mid);
    Node son2 = query(i, j, rr, mid + 1, r);
    if(son1.mi == INF && son1.gcd == INF) return son2;
    if(son2.mi == INF && son2.gcd == INF) return son1;
    Node res;
    res.mi = min(son1.mi, son2.mi);
    res.gcd = __gcd(son1.gcd, son2.gcd);
    return res;
}
VI V;
bool check(int sz, int flag)
{
    for(int i = 0; i <= N - sz; ++i)
    {
        Node res = query(i, i + sz - 1);
        //cout << i << ' ' << i + sz - 1 << " - > " << res.mi << ' ' << res.gcd << endl;
        if(!flag && res.mi == res.gcd) return true;
        if(flag && res.mi == res.gcd) V.push_back(i + 1);
    }
    return false;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> N;
    for(int i = 0; i < N; ++i) scanf("%d", &arr[i]);
    build();

    int lo = 1, hi = N;
    while(lo < hi)
    {
        int mid = lo + (hi - lo + 1)/2;
        if(!check(mid, 0))
            hi = mid - 1;
        else
            lo = mid;
    }
    check(lo, 1);
    cout << V.size() << ' ' << lo - 1 << endl;
    for(int i = 0; i < V.size(); ++i){
        if(i) cout << ' ';
        cout << V[i];
    }
    return 0;
}