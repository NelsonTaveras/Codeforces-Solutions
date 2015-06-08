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

int N, M;
int tree[ 4 * (1<<17) ] ;
int arr[(1<<17)];
bool odd = false;
void build(int idx = 1, int lvl = 0, int l = 0, int r = N - 1){
    if(l == r){
        tree[idx] = arr[l];
        if(lvl % 2 == 0)
            odd = true;
    }
    else
    {
        build(idx << 1, lvl + 1, l, (l + r) / 2);
        build((idx << 1) + 1, lvl + 1, (l + r) / 2 + 1, r);
        if(odd){
            if(lvl & 1)
                tree[idx] = tree[idx << 1] | tree[(idx << 1) + 1];
            else
                tree[idx] = tree[idx << 1] ^ tree[(idx << 1) + 1];
        }
        else
        {
            if(lvl & 1)
                tree[idx] = tree[idx << 1] ^ tree[(idx << 1) + 1];
            else
                tree[idx] = tree[idx << 1] | tree[(idx << 1) + 1];
        }
    }
}
int query(int i, int j, int idx = 1, int lvl = 0, int l = 0, int r = N - 1){
    if(i > r || j < l)
        return -1;
    if(l >= i && r <= j)
        return tree[idx];
    int left = query(i, j, (idx << 1), lvl + 1, l, (l + r) / 2);
    int right = query(i, j, (idx << 1) + 1, lvl + 1, (l + r) / 2 + 1, r);
    if( left == -1 )
        return right;
    if( right == -1 )
        return left;
    if(odd){
        if(lvl & 1)
            return left | right;
        else
            return left ^ right;
    }
    else
    {
        if(lvl & 1)
            return left ^ right;
        else
            return left | right;
    }
}
void update(int pos, int val, int idx = 1, int lvl = 0, int l = 0, int r = N - 1){
    if(l > r || l > pos || r < pos)
        return ;
    if(l == r){
        tree[idx] = val;
        return ;
    }
    update(pos, val, idx << 1, lvl + 1, l, (l + r) / 2);
    update(pos, val, (idx << 1) + 1, lvl + 1, (l + r) / 2 + 1, r);
    if(odd){
        if(lvl & 1)
            tree[idx] = tree[idx << 1] | tree[(idx << 1) + 1];
        else
            tree[idx] = tree[idx << 1] ^ tree[(idx << 1) + 1];
    }
    else
    {
        if(lvl & 1)
            tree[idx] = tree[idx << 1] ^ tree[(idx << 1) + 1];
        else
            tree[idx] = tree[idx << 1] | tree[(idx << 1) + 1];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> N >> M;
    N = (1<<N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    build();
    while(M--){
        int pos, val;
        cin >> pos >> val;
        update(pos - 1, val);
        cout << query(0, N - 1) << endl;
    }
    return 0;
}
