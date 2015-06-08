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
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef long long llong;
const int INF = 1e9;

using namespace std;

int F[100];
int f[100000];
int s[100000];
int t[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);

    int N;
    cin >> N;
    
    for(int i = 0; i < N; ++i){
        int id;
        cin >> id;
        F[id]++;
        if(id == 5 || id == 7){
            cout << -1;
            return 0;
        }
    }

    int left = N / 3;
    int cur = 0;

    // Get rid of 3
    while(F[3]){
        // 1, 3, 6
        if(F[1] && F[3] && F[6]){
            f[cur] = 1;
            s[cur] = 3;
            t[cur] = 6;
            F[1]--;
            F[3]--;
            F[6]--;
            left--;
            cur++;
        }
        else{
            cout << -1;
            return 0;
        }
    }

    // Get rid of 4
     while(F[4]){
        // 1, 3, 6
        if(F[1] && F[2] && F[4]){
            f[cur] = 1;
            s[cur] = 2;
            t[cur] = 4;
            F[1]--;
            F[2]--;
            F[4]--;
            left--;
            cur++;
        }
        else{
            cout << -1;
            return 0;
        }
    }

    // Get rid of 6
    while(F[6]){
        // 1, 3, 6
        if(F[1] && F[2] && F[6]){
            f[cur] = 1;
            s[cur] = 2;
            t[cur] = 6;
            F[1]--;
            F[2]--;
            F[6]--;
            left--;
            cur++;
        }
        else{
            cout << -1;
            return 0;
        }
    }

    if(left)
        cout << -1;
    else
    {
        for(int i = 0; i < cur; ++i)
            cout << f[i] << ' ' << s[i] << ' ' << t[i] << endl;
    }
    return 0;
}