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
    for (int i = 2; i <= n / i; i += 1 + (i & 1)) {
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
int gen_divisors(int n) {         //O(sqrt(n))
    int cnt = 0;
    for (int i = 1; i <= n / i; ++i) {
        if (n % i == 0) {
            cnt++;
            if (i * i != n)cnt++;
        }
    }
    return cnt;
}
const int NN = 1007;
int p[NN];
vector<int>primes;
void seive() {
    memset(p, 1, sizeof p);
    p[0] = p[1] = 0;
    for (int i = 2; i < NN / i; ++i) {
        if (p[i]) {
            for (int j = i * i; j < NN; j += i) {
                p[j] = 0;
            }
        }
    }
    for (int i = 0; i < NN; i++) {
        if (p[i])primes.push_back(i);
    }
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
