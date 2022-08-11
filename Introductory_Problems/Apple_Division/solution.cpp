/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
 
ll min(const ll& a, const ll& b)
{
    return a>b? b:a;
}
 
ll my_abs(const ll& a)
{
    return a>=0? a:-a;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<ll> weights;
    int n;
    ll sum = 0;
    cin >> n;
    for(int i = 0; i<n; ++i)
    {
        ll weight;
        cin >> weight;
        sum+=weight;
        weights.push_back(weight);
    }
    //binary expansion of i determines if element is in/out of the subset
    //let us consider only the subsets not containing the last element
    ll mini = sum, subsum = 0;
    for(int i = 1; i<(1<<(n-1)); ++i)
    {
        int diff = i^(i-1);
        for(int j = 0; j<(n-1); ++j)
        {
            int p = diff>>j;
            if(p==0) break;
            if(p&1)
            {
                if((i>>j)&1) subsum+=weights[j];
                else subsum-=weights[j];
            }
        }
        mini = min(my_abs(sum-2*subsum), mini);
    }
    cout << mini;
    return 0;
}