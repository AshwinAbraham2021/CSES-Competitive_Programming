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
    int num = 0;
    while(n>0)
    {
        n/=5;
        num+=n;
    }
    cout << num;
    return 0;
}