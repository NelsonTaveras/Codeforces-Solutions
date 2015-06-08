#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
#define mp make_pair
#define INF 1000000000000
llong arr[(int) 1e6];
llong sum[(int) 1e6];
llong memo[200001][2];
llong act[200001][2];
int N, K;
int printed = 0;
inline llong func(int l, int r)
{
    return sum[r] - sum[l - 1];
}
llong dp(int idx, int left)
{
    if(left == 0)
        return 0;
    if( idx >= N )
        return ( left ? -INF : 0 );
    if( memo[idx][left] != -1 )
        return memo[idx][left];
    llong res = 0;
    llong w = func(idx + 1, idx + K) + dp(idx + K, left - 1);
    if( w > res ){
        res = w;
        act[idx][left] = 1;
    }
    w = dp(idx + 1, left);
    if( w > res ){
        res = w;
        act[idx][left] = 0;
    }
    return memo[idx][left] = res;
}
void backtrack(int idx, int left){
    if(left == 0 || idx >= N)
        return ;
    if(printed >= 2)
        return ;
    if(act[idx][left]){
        cout << idx + 1 << ' ';
        backtrack(idx + K, left - 1);
        printed++;
    }
    else
        backtrack(idx + 1, left);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N >> K;
    for(int i = 0; i < N; ++i)
        cin >> arr[i];
    for(int i = 1; i <= N; ++i)
        sum[i] = sum[i - 1] + arr[i - 1];
    memset(memo, -1, sizeof(memo));
    dp(0, 2);
    backtrack(0, 2);
    return 0;
}
