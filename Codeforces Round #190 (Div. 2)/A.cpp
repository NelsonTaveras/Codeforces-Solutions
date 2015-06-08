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
typedef vector<int> VI;
typedef vector<VI> VII;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int> > ret;
    set<int> girls;
    set<int> boys;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(!girls.count(j) || !boys.count(i))
            {
                ret.push_back(make_pair(i + 1, j + 1));
                girls.insert(j);
                boys.insert(i);
            }
        }
    }
    cout << ret.size() << endl;
    for(int i = 0; i < ret.size(); ++i)
        cout << ret[i].first << " " << ret[i].second << endl;

    return 0;
}