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
bool is_prime(int n) {
    if (n <= 1)return 0;
    for (int i = 2; i <= n/i; i += 1 + (i & 1)) {
        if (n % i == 0)return 0;
    }
    return 1;
}
int factorize_(int n) {
    int cnt = 0;
    for (int i = 2; i <= n / i; i += 1 + (i & 1)) {
        if (n % i == 0) {
            cnt++;
            n = n % i;
        }
    }
    if (n > 1)cnt++;
    return cnt;
}
vector<ll> factorize(ll n) // sqrt(n)
{
    vector<ll> divisors;
    int cnt = 0;
    for (int i = 2; i <= n / i; i += 1 + (i & 1))
    {
        while (n % i == 0) {
            divisors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) divisors.push_back(n);
    return divisors;
}
int gen_divisors(int n) {         //O(sqrt(n))
    int cnt=0;
    for (int i = 1; i <= n/i; ++i) {
        if (n % i == 0) {
            cnt++;
            if (i * i != n)cnt++;
        }
    }
    return cnt;
}
int main() {
    init();
    ll n;
    bool flag= true;
    while (flag){
        cin>>n;
        if(n==0)flag= false;
        else{
            auto ret= factorize(abs(n));
            cout<<n<<" =";
            if(n<0)cout<<" -1 x";
            for (ll i=0;i<ret.size();i++) {
                if(i==0)cout<<" "<<ret[i];
                else cout<<" x "<<ret[i];
            }
            cout<<"\n";
        }
    }
    return 0;
}
