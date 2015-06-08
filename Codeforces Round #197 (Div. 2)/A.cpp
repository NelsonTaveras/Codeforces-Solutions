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
int main()
{
    ios_base::sync_with_stdio(false);

    string S;
    cin >> S;
    VI V;
    for(int i = 0; i < S.size(); ++i){
        if(S[i] != '+')
            V.push_back(S[i] - '0');
    }
    sort(V.begin(), V.end());
    for(int i = 0; i < V.size(); ++i){
        if(i)
            cout << '+';
        cout << V[i];
    }
    return 0;
}
