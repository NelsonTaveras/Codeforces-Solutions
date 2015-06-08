#include <iostream>
#include <cstring>

using namespace std;
typedef long long llong;
llong P[100];
llong R[100];
int main()
{
    llong N;
    cin >> N;
    for(llong i = 1; i < N * (N - 1)/2; ++i)
    {
        llong u, v;
        cin >> u >> v;
        P[u] |= (1LL*1<<v);
        P[v] |= (1LL*1<<u);
        R[u] |= (1LL*1<<v);
    }
    llong f = -1, s = -1;
    bool ff = true;
    for(llong i = 1; i <= N && ff; ++i)
        for(llong j = 1; j <= N && ff; ++j)
            if( (P[i] & (1LL*1<<j)) == 0 && i != j){
                f = i, s = j;
                ff = false;
            }
    bool ok = false;
    for(llong i = 1; i <= N; ++i)
        if( (R[f] & (1LL*1<<i)) && (R[i] & (1LL*1<<s)) ){
            ok = true;
            break;
        }
    if(ok)
        cout << f << ' ' << s;
    else
        cout << s << ' ' << f;
    return 0;
}