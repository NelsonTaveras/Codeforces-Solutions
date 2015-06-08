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
int main()
{
    int N, K;
    cin >> N >> K;
    for(int i = 0; i <= N; ++i)
        for(int j = 0; j <= N; ++j)
            for(int k = 0; k <= N; ++k)
                for(int l = 0; l <= N; ++l)
                    if( i * 2 + 3 * j + 4 * k + 5 * l == K && i + j + k + l == N )
                    {
                        cout << i;
                        return 0;
                    }

    return 0;
}
