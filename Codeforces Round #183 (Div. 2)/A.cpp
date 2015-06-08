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

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VII;

int main()
{
    int N;
    cin >> N;

    int cnt = 0;
    for(int a = 1; a <= N; ++a)
    {
        for(int b = 1; b <= N; ++b)
        {
            int p = (a*a)+(b*b);
            int c = sqrt(p);
            if( (c*c == p) && c <= N )
                cnt++;
        }
    }
    cout << cnt / 2 << endl;
    return 0;
}
