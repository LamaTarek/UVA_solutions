#include <iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include <set>
#include<vector>
#include <cmath>
#include <map>
#include <cstring>
#include <limits.h>
typedef long long ll;
using namespace std;
void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}
ll factorize(ll n) // sqrt(n)
{
    ll cnt=0;
    ll lpd=-1;
    for (int i = 2; i <= n / i; i += 1 + (i & 1))
    {
        if(n%i==0){cnt++;lpd=i;}
        while (n % i == 0) {
            n /= i;
        }
    }
    if(n>1){cnt++;lpd=n;}
    if(cnt>1)return lpd;
    else return -1;
}
int main() {
    init();
    ll n;
    while (cin >> n && n) {
        if(n<0)cout<<factorize(-1*n)<<"\n";
        else cout<<factorize(n)<<"\n";
    }
    return 0;
}
