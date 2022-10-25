/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <bits/stdc++.h>
using namespace std;
typedef uint64_t ll;
 
ll S(int n)
{
    ll k = round(pow(10, n));
    return n*k - ((k-1)/9);
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> q;
    for(int i = 0; i<q; ++i)
    {
        ll k;
        cin >> k;
        int n = 1;
        for(; S(n)<k; ++n);
        k-=S(n-1);
        ll p = round(pow(10, n-1));
        p+=(k-1)/n;
        k = (k-1)%n;
        ll q = round(pow(10, n-1-k));
        cout << (p/q)%10 << '\n';
    }
    return 0;
}