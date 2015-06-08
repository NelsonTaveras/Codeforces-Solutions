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

typedef unsigned long long ullong;
typedef long long llong;
typedef pair<int, int> PI;
typedef pair<int, PI> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);
    int rows, cols;
    cin >> rows >> cols;
    vector<string> GRID(rows);
    for(int i = 0; i < rows; ++i)
        cin >> GRID[i];
    int leftc = 1000000;
    int upc = -1;
    for(int i = 0; i < rows; ++i)
    {
        if(GRID[i].find('*') != string::npos)
        {
            leftc = min(leftc, (int) GRID[i].find('*'));
            if(upc == -1)
                upc = i;
        }
    }
    int rightc = -1;
    int doc = -1;
    for(int i = rows - 1; i >= 0; i--)
    {
        string rev = GRID[i];
        reverse(rev.begin(), rev.end());
        if(rev.find('*') != string::npos)
        {
            rightc = max(rightc, cols - (int) rev.find('*') - 1);
            if(doc == -1)
            doc = i;
        }
    }
    for(int i = upc; i <= doc; ++i)
    {
        string cur;
        for(int j = leftc; j <= rightc; ++j)
            cur += GRID[i][j];
        cout << cur << endl;
    }
    return 0;
}
