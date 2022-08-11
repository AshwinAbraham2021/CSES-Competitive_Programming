/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <bits/stdc++.h>
using namespace std;
 
const unsigned int mod = 1000000007;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    unsigned int ans = 1;
    int n;
    cin >> n;
    for(int i = 0; i<n/2; ++i)
    {
        ans<<=2;
        ans%=mod;
    }
    ans<<=(n%2);
    ans%=mod;
    cout << ans;
    return 0;
}