/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    if(n%4 && (n+1)%4)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if(n%4==0)
    {
        cout << n/2 << '\n';
        for(int i = 1; i<=n/4; ++i) cout << i << ' ' << n+1-i << (i==n/4? '\n':' ');
        cout << n/2 << '\n';
        for(int i = 1+(n/4); i<=n/2; ++i) cout << i << ' ' << n+1-i << (i==n/2? '\n':' ');
        return 0;
    }
    if(n==3)
    {
        cout << "2\n1 2\n1\n3\n";
        return 0;
    }
    cout << (n-1)/2 << '\n';
    for(int i = 1; i<(n+1)/4; ++i) cout << i << ' ' << n+1-i << ' ';
    cout << 3*(n+1)/4 << '\n' << (n+1)/2 << '\n';
    for(int i = 1 + (n+1)/4; i<=(n-1)/2; ++i) cout << i << ' ' << n+1-i << ' ';
    cout << (n+1)/4 << ' ' << (n+1)/2 << '\n'; 
    return 0;
}