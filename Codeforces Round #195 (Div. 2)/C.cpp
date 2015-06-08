#include <cmath>
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
typedef long long llong;
typedef unsigned long long ullong;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, llong> PII;
typedef pair<int, PII> PIP;
int arr[100009];
int main()
{
    //freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    for(int i = 30; i >= 0; --i)
    {
        int res = -1;
        int cnt = 0;
        for (int j = 0; j < N; ++j)
        {
            if(arr[j] & (1<<i))
            {
                if(res == -1)
                    res = arr[j];
                else
                    res &= arr[j];
                cnt++;
            }
        }
        if(!(res % (1<<i)))
        {
            cout << cnt << endl;
            for (int j = 0; j < N; ++j)
                if(arr[j] & (1<<i))
                    cout << arr[j] << ' ';
            return 0;
        }
    }
    return 0;
}