#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <ctime>
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
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL<<62);
const int inf = (1LL<<30);
const int maxn = (int) 1e5 + 5;
const int MOD = 1000000007;

string arr[] = {"Vaporeon", "Jolteon", "Flareon", "Espeon", "Umbreon", "Leafeon", "Glaceon", "Sylveon"};

 
int main()
{
    for(int i = 0; i < 8; ++i)
        for(int j = 0; j < arr[i].size(); ++j)
            arr[i][j] = tolower(arr[i][j]);
    ios_base::sync_with_stdio(false);
    int n = 8;
    int l;
    cin >> l;
    string S;
    cin >> S;
    for(int i = 0; i < n; ++i){
        string tmp;
        for(int j = 0; j < l; ++j){
            if(S[j] == '.')
                tmp += arr[i][j];
            else
                tmp += S[j];
        }
        for(int i = 0; i < tmp.size(); ++i) tmp[i] = tolower(tmp[i]);
        if(tmp == arr[i]){
            for(int i = 0; i < tmp.size(); ++i) tmp[i] = tolower(tmp[i]);
            cout << tmp << endl;
            return 0;
        }
    }
    return 0;
}
