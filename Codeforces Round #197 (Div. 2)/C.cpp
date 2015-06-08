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

using namespace std;

int arr[20];
int memo[12][12][12][1002];
int act[12][12][12][1002];
int dp(int l, int r, int last, int left){
    if(left <= 0)
        return 1;
    if(memo[l][r][last + 1][left] != -1)
        return memo[l][r][last + 1][left];
    int ans = -10000000;
    if(l || (l + r == 0)){
        // turn left
        for(int i = 1; i <= 10; ++i)
            if(arr[i] && i > l && ( i != last || last == -1 ) ){
                int w = dp(0, i - l, i, left - 1);
                if(w > ans){
                    ans = w;
                    act[l][r][last + 1][left] = i;
                }
            }
    }
    else{
        // turn right
        for(int i = 1; i <= 10; ++i){
            if(arr[i] && i > r && ( i != last || last == -1 ) ){
                int w = dp(i - r, 0, i, left - 1);
                if(w > ans){
                    ans = w;
                    act[l][r][last + 1][left] = i;
                }
            }
        }
    }
    return memo[l][r][last + 1][left] = ans;
}
void go(int l, int r, int last, int left){
    while(left > 0){
        int choice = act[l][r][last + 1][left];
        cout << choice << ' ';
        if(l || (l + r == 0)){
            r = choice - l;
            l = 0;
            last = choice;
            left--;
        }
        else{
            l = choice - r;
            r = 0;
            last = choice;
            left--;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);

    string S;
    cin >> S;
    int M;
    cin >> M;
    for(int i = 1; i <= 10; ++i)
        arr[i] = S[i - 1] - '0';
    memset(memo, -1, sizeof(memo));
    if(dp(0, 0, -1, M) > 0){
        cout << "YES" << endl;
        go(0, 0, -1, M);
    }
    else{
        cout << "NO";
    }
    return 0;
}
