#include <iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include <set>
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
int factorize(int n) // sqrt(n)
{
    int cnt=0;
    for (int i = 2; i <= n /i; i+= 1+(i&1))
    {
        if(n%i==0)cnt++;
        while (n % i == 0) n /= i;
    }
    if (n > 1) cnt++;
    return cnt;
}
int main() {
    init();
    int n;
    bool flag=true;
    while (flag){
        cin>>n;
        if(n==0)flag= false;
        else cout<<n<<" : "<<factorize(n)<<"\n";
    }
    return 0;
}
