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

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef pair<int, int> PII;
const int INF = 1e9;

string arr[] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    int ret = 0;
    while(N--){
        string S;
        cin >> S;
        if(S[0] >= '0' && S[0] <= '9'){
            int age = 0;
            for(int i = 0; i < S.size(); ++i){
                age *= 10;
                age += (S[i] - '0');
            }
            if(age < 18) ret++;
        }
        else{
            bool saw = false;
            for(int i = 0; i < 11; ++i)
                if(arr[i] == S)
                    saw = true;
            if(saw)
                ret++;

        }
    }
    cout << ret << endl;
    return 0;
}

