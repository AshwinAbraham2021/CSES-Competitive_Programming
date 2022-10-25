/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int ll;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    unsigned int n;
    cin >> n;
    for(ll i = n; ; i = (i%2? (3*i+1):(i/2)))
    {
        std::cout << i << (i==1? '\n':' ');
        if(i==1) break;
    }
    return 0;
}
