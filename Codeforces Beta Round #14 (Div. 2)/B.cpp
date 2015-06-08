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

int A[100000];
int B[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    int N, X;
    cin >> N >> X;
    for(int i = 0; i < N; ++i)
        cin >> A[i] >> B[i];
    int mx = 1000000;
    for(int i = 0; i <= 1000; ++i)
    {
        bool pos = true;
        for(int j = 0; j < N; ++j)
        {
            int a = A[j];
            int b = B[j];
            if( a > b )
                swap(a, b);
            if( a > i || b < i )
                pos = false;
        }
        if(pos)
            mx = min(mx, abs(i-X));
    }
    cout << ( mx == 1000000 ? -1 : mx );
    return 0;
}
