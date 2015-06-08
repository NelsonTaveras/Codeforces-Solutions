#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIIP;
const int INF = (int) 2e9;

llong arr[1000010];

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    if(n == 1){
        cout << 1 << endl;
    }
    else if(n == 2){
        cout << 2 << endl;
    }
    else
    {
        int l = 0;
        int r = 0;
        int ma = 0;
        while(r < n){
            int sz = r - l + 1;
            if(sz < 2){
                r++;
            }
            else{
                if(r + 1 < n && arr[r+1] == arr[r] + arr[r - 1])
                    r++;
                else{
//                  cout << l << ' ' << r << endl;
                    l++;
                }
            }
            ma = max(ma, r - l + 1);
        }
        cout << ma << endl;
    }
    return 0;
}

/*
10
1 2 4 5 8 13 21 34 55 89
*/
