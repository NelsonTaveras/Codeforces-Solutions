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

char ST[100001];
int main()
{
    //freopen("input.txt", "r", stdin);
    string S;
    cin >> S;
    ST[0] = S[0];
    int cur = 1;
    for(int i = 1; i < S.size(); ++i){
        if(cur == 0){
            ST[cur++] = S[i];
        }
        else if(ST[cur - 1] == S[i]){
            cur--;
        }
        else{
            ST[cur++] = S[i];
        }
    }
    cout << (cur == 0 ? "Yes" : "No") << endl;
    return 0;
}