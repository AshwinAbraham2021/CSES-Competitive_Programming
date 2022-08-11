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

    int t;
    cin >> t;
    ll y, x, n;
    for(int i = 0; i<t; ++i)
    {
        cin >> y >> x;
        n = (x>y? x:y);
        if(n%2)
        {
            if(x>y) cout << n*n + 1 - y << '\n';
            else cout << (n-1)*(n-1) + x << '\n';
        }
        else
        {
            if(x>y) cout << (n-1)*(n-1) + y << '\n';
            else cout << n*n + 1 - x << '\n';
        }
    }
    return 0;
}