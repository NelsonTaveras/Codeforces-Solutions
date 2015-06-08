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

#define MOD 1000000009
#define mp make_pair
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef long long llong;
const int INF = 1e9;

using namespace std;
int freq[100];
int main()
{
    ios_base::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string S;
    int N;
    cin >> S >> N;
    for(int i = 0; i < (int) S.size(); ++i)
        freq[S[i]-'a']++;
    int diff = 0 ;
    for(int i = 0; i < 26; ++i)
        if(freq[i])
            diff++;
    if(diff > N)
    {
        cout << -1;
        return 0;
    }
    for(int cnt = 1; cnt <= (int) S.size() + 100; ++cnt)
    {
        int charsleft = N;
        bool pos = true;
        string ANS;
        for(int i = 0; i < 26 && pos; ++i)
        {
            int req = freq[i];
            if(req)
            {
                int need = -1;
                for(int j = 1; j <= N; ++j)
                    if(j * cnt >= req){
                        need = j;
                        break;
                    }
                if(need > charsleft || need == -1)
                    pos = false;
                else
                    charsleft -= need;
            }
        }
        if(pos){
            string ANS = "";
            for(int i = 0; i < 26 && pos; ++i)
            {
                int req = freq[i];
                if(req)
                {
                    int need = 0;
                    for(int j = 1; j <= N; ++j)
                        if(j * cnt >= req){
                            need = j;
                            break;
                        }
                    for(int j = 0; j < need; ++j)
                        ANS += ((char)(i + 'a'));
                }
            }
            cout << cnt << endl;
            while((int) ANS.size() < N )
                ANS += ANS[0];
            cout << ANS;
            return 0;
        }
    }
    cout << -1;
    return 0;
}