/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for(int i = 0; i<t; ++i)
    {
        int a, b;
        cin >> a >> b;
        if((a+b)%3!=0) cout << "NO\n";
        else if (2*a<b || 2*b < a) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}