#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
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
const int INF = 1e9;

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    string last;
    cin >> last;
    int ret = 1;
    for(int i = 1; i < N; ++i)
    {
        string s;
        cin >> s;
        if(last[1] == s[0])
            ret++;
        last = s;
    }
    cout << ret;
    return 0;
}