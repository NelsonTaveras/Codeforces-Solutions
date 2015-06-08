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
#include <cctype>

using namespace std;

#define mp make_pair
typedef pair<int, int> PI;
typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;
int INF = 1e9;
bool prime[2000];
int main()
{
    int N, K;
    cin >> N >> K;
    prime[0] = prime[1] = 1;
    for(int i = 2; i <= 1000; ++i)
        for(int j = i * i; j <= 1000; j += i)
            prime[j] = 1;
    VI V;
    for(int i = 2; i <= 1000; ++i)
        if(!prime[i])
            V.push_back(i);
    VI res;
    for(int i = 0; i <= (int) V.size() - 1; ++i)
    {
        int P = V[i] + V[i + 1] + 1;
        if(!prime[P])
            res.push_back(P);
    }
    for(int i = 0; i < res.size(); ++i)
        if(res[i] >= 2 && res[i] <= N)
            K--;
    cout << ( K <= 0 ? "YES" : "NO" );
    return 0;
}
