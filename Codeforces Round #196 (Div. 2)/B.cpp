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

struct Fraction{
    llong num;
    llong dem;
    Fraction(llong _num, llong _dem)
    {
        num = _num;
        dem = _dem;
    }
    bool operator<(Fraction f)const{
        return f.dem * num < f.num * dem;
    }
    Fraction operator+(Fraction f)const{
        return Fraction(num * f.dem + f.num * dem, f.dem * dem);
    }
    Fraction operator-(Fraction f)const{
        return Fraction(num * f.dem - f.num * dem, f.dem * dem);
    }
    Fraction operator*(Fraction f)const{
        return Fraction(num * f.num, dem * f.dem);
    }
    Fraction operator/(Fraction f)const{
        return Fraction(num, dem) * Fraction(f.dem, f.num);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    llong a, b, c, d;
    cin >> a >> b >> c >> d;
    Fraction r1(a, c);
    Fraction r2(b, d);
    if(r1 < r2)
    {
        Fraction num(Fraction(c, 1) * r1);
        Fraction dem(Fraction(d, 1) * r1);
        Fraction res = Fraction(1,1) - Fraction((num.num * dem.num), (num.dem * dem.dem)) / Fraction(a*b, 1);
        llong d = __gcd(res.num, res.dem);
        cout << res.num/d << '/' << res.dem/d << endl; 
    }
    else
    {
        Fraction num(Fraction(c, 1) * r2);
        Fraction dem(Fraction(d, 1) * r2);
        Fraction res = Fraction(1,1) - Fraction((num.num * dem.num), (num.dem * dem.dem)) / Fraction(a*b, 1);
        llong d = __gcd(res.num, res.dem);
        cout << res.num/d << '/' << res.dem/d << endl; 
    }
    return 0;
}