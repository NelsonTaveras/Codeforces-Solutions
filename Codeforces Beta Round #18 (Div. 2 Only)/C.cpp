#include <cmath>
#include <ctime>
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

typedef unsigned long long ullong;
typedef long long llong;
typedef pair<int, int> PI;
typedef pair<int, PI> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define mp make_pair

llong arr[1000000];
llong sum[1000000];

inline llong s(int l, int r)
{
    return sum[r] - sum[l - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> arr[i];
    sum[1] = arr[0];
    for(int i = 2; i <= N; ++i)
        sum[i] = sum[i - 1] + arr[i - 1];
    int ret = 0;
    for(int i = 1; i < N; ++i)
    {
        int sumLeft = s(1, i);
        int sumRight = s(i + 1, N);
        if(sumLeft == sumRight)
            ret++;
    }
    cout << ret;
    return 0;
}