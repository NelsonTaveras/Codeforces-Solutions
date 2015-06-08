#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;

int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    string S;
    cin >> N >> S;
    int cur = 0;
    int drank = 0;
    for(int i = 0; i < S.size(); ++i){
        if( cur == 0 && i >= 4 )
            if(S[i-1] == S[i-2] && S[i-2] == S[i-3])
                drank++;
        cur = ( i + 1 ) % N;
    }
    cout << drank;
    return 0;
}
