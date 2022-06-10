// Owner Hady Ahmed 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll tst;
    cin>>tst;
    while (tst--)
    {
        ll n ;
        cin>>n;
        ll sum = 0;
        for (long long int i = 1; i <= n; i++) {
            long long int gcd = __gcd(i, n);
            long long int lcm = (i * n) / gcd;
            sum = sum + lcm;
        }
        cout<<sum<<"\n";

    }
    return 0;
}
