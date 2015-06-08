#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define MOD 1000000007
typedef long long llong;

llong F[1000005];
llong fastexp(llong base, llong exp){
    if( exp == 0 )
        return 1;
    if( exp == 1 )
        return base;
    llong ret = fastexp(base, exp / 2);
    ret  = (ret * ret) % MOD;
    if( exp & 1 )
        ret = (ret * base) % MOD;
    return ret;
}
llong Choose(int N, int K){
    return F[N] * fastexp( (F[N - K] * F[K] ) % MOD, MOD - 2 );
}
bool func(llong sum, int a, int b){
    while(sum > 0){
        int d = sum % 10;
        if( d != a && d != b )
            return false;
        sum /= 10;
    }
    return true;
}
int main()
{
    int A, B, N;
    cin >> A >> B >> N;
    F[0] = 1;
    for(int i = 1; i <= N; ++i)
        F[i] = (F[i - 1] * i) % MOD;
    llong ret = 0;
    for(int i = 0; i <= N; ++i){
        int a = i;
        int b = N - i;
        if(func(a * A + b*B, A, B)){
            ret += Choose(N, a);
            ret %= MOD;
        }
    }
    cout << ret;
    return 0;
}
