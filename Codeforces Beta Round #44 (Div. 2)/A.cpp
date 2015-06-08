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

#define mp make_pair
typedef pair<int, int> PI;
typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;
int INF = 1e9;

int main()
{
    int N;
    cin >> N;
    string ans = "NO";
    for(int i = 1; i <= 500; ++i)
        if((i*(i+1))/2 == N)
            ans = "YES";
    cout << ans;
    return 0;
}
