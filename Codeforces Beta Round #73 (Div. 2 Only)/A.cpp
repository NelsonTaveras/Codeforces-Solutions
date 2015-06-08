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
const int maxn = (int) 1e6 + 5;
const int MOD = 1000000007;

int n = 12;
string arr[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
int dist(string a, string b)
{
    int d = 0;
    int pos = 0;
    while(pos < 12)
    {
        if(arr[pos] == a) break;
        pos++;
    }
    while(arr[pos] != b){
        pos++;
        if(pos >= 12) pos = 0;
        ++d;
    }
    return d;
}
int main()
{
    ios_base::sync_with_stdio(false);
    string A, B, C;
    cin >> A >> B >> C;
    vector<string> V;
    V.push_back(A);
    V.push_back(B);
    V.push_back(C);
    sort(V.begin(), V.end());
    do{
        if(dist(V[0], V[1]) == 4 && dist(V[1], V[2]) == 3 ){
            cout << "major" << endl;
            return 0;
        }
    }while(next_permutation(V.begin(), V.end()));
    sort(V.begin(), V.end());
    do{
        if(dist(V[0], V[1]) == 3 && dist(V[1], V[2]) == 4 ){
            cout << "minor" << endl;
            return 0;
        }
    }while(next_permutation(V.begin(), V.end()));
    cout << "strange" << endl;
    return 0;
}

/*

10 5
1 1 1 1 1 2 8 2 9 9

 */
