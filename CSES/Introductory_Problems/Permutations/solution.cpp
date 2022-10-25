/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <bits/stdc++.h>
using namespace std;
 
void edgecases(int n)
{
    if(n==2 || n==3)
    {
        cout << "NO SOLUTION\n";
        return;
    }

    if(n==1)
    {
        cout << 1 << '\n';
        return;
    }

    if(n==4) cout << "2 4 1 3\n";

    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    if(n<5)
    {
        edgecases(n);
        return 0;
    }

    for(int i = 1; i<=n; i+=2) cout << i << ' ';
    for(int i = 2; i<=n; i+=2) cout << i << (i==n? '\n':' ');
    return 0;
}