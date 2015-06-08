#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cctype>
#include <sstream>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;
int l[5001], r[5001], f[5001];
int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> l[i] >> r[i];
    VVI C(N);
    int ret = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(i != j)
            if( (l[j] >= l[i] && l[j] < r[i]) )
            {
                C[i].push_back(j);
                ret++;
                f[j]++;
            }

        }
    }
    if( ret == 0 )
    {
        cout << N << endl;
        for(int i = 1; i <= N; ++i)
            cout << i << ' ';
        return 0;
    }
    VI ans;
    for(int i = 0; i < N; ++i)
    {
        // try to quit i
        bool pos = true;
        for(int j = 0; j < N && pos; ++j)
        {
            if(i != j)
            {
                if(C[j].size() == 0 || (C[j].size() == 1 && C[j][0] == i))
                    continue;
                else
                    pos = false;
            }
        }
        if(pos)
            ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    return 0;
}
