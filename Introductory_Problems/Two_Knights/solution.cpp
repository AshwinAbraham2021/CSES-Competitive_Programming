/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <bits/stdc++.h>
using namespace std;
typedef uint64_t ll;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n; 
    for(ll k = 1; k<=n; ++k)
    {
        ll total = ((k*k)*(k*k - 1))/2;
        ll capture;
        if(k<3) capture = 0;
        else capture = 4*(k-1)*(k-2);
        cout << total - capture << '\n';
    }
    return 0;
}