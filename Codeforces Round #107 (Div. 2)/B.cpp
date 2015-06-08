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

#define mp make_pair
typedef pair<int, int> PI;
typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;
int INF = 1e9;

bool isTaxi(string S)
{
    string temp;
    for(int i = 0; i < S.size(); ++i)
        if(S[i] != '-')
            temp += S[i];
    set<char> s(temp.begin(), temp.end());
    return ((int) s.size() == 1);
}
bool isPizza(string S)
{
    string temp, temps;
    for(int i = 0; i < S.size(); ++i)
        if(S[i] != '-')
            temp += S[i];
    temps = temp;
    sort(temps.rbegin(), temps.rend());
    set<char> s(temps.begin(), temps.end());
    return temps == temp && s.size() == 6;
}
int taxi[1001];
int pizza[1001];
int girls[1001];
string names[1001];
int main()
{
    int N;
    cin >> N;
    int mtaxi = 0, mpizza = 0, mgirls = 0;
    for(int i = 0; i < N; ++i)
    {
        int n;
        cin >> n >> names[i];
        for(int j = 0; j < n; ++j)
        {
            string S;
            cin >> S;
            if(isTaxi(S))
                taxi[i]++;
            else if(isPizza(S))
                pizza[i]++;
            else
                girls[i]++;
        }
        mtaxi = max(mtaxi, taxi[i]);
        mpizza = max(mpizza, pizza[i]);
        mgirls = max(mgirls, girls[i]);
    }
    int cnt = 0;
    cout << "If you want to call a taxi, you should call: ";
    for(int i = 0; i < N; ++i)
    {
        if(taxi[i] == mtaxi)
        {
            if(cnt)
                cout << ", ";
            cout << names[i];
            cnt++;
        }
    }
    cout << '.' << endl;
    cnt = 0;
    cout << "If you want to order a pizza, you should call: ";
    for(int i = 0; i < N; ++i)
    {
        if(pizza[i] == mpizza)
        {
            if(cnt)
                cout << ", ";
            cout << names[i];
            cnt++;
        }
    }
    cout << '.' << endl;
    cnt = 0;
    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    for(int i = 0; i < N; ++i)
    {
        if(girls[i] == mgirls)
        {
            if(cnt)
                cout << ", ";
            cout << names[i];
            cnt++;
        }
    }
    cout << '.';
    return 0;
}
