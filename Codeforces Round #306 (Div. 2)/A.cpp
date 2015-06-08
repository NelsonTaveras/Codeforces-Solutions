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
#include <bitset>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;

llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (llong) 1e6 + 10;
const int MOD = 1000000007;

llong arr[20];

int main(){
    ios_base::sync_with_stdio(false);
    string S;
    cin >> S;
    int pos = 0;
    vector<int> AB;
    vector<int> BA;
    while(1){
        int p = S.find("AB", pos);
        if(p == string::npos){
            break;
        }
        pos = p + 2;
        AB.push_back(p);
    }
    pos = 0;
    while(1){
        int p = S.find("BA", pos);
        if(p == string::npos){
            break;
        }
        pos = p + 2;
        BA.push_back(p);
    }
    if(AB.size() == 0 || BA.size() == 0){
        cout << "NO" << endl;
        return 0;
    }
    sort(AB.begin(), AB.end());
    sort(BA.begin(), BA.end());
    int ABp = AB[0];
    int BAp = BA[BA.size() - 1];
    if(abs(BAp - ABp) > 1){
        cout << "YES" << endl;
        return 0;
    }
    ABp = AB[AB.size() - 1];
    BAp = BA[0];
    if(abs(BAp - ABp) > 1){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}
