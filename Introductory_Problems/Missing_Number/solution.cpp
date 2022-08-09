#include <bits/stdc++.h>
using namespace std;

typedef uint64_t ll;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    ll sum = 0;
    int num;
    for(int i = 0; i<(n-1); ++i)
    {
        cin >> num;
        sum+=num;
    }
    ll total = (n*(n+1))/2;
    cout << total-sum;
    return 0;
}