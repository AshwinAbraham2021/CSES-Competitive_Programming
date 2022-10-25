/*
 * AUTHOR: ASHWIN ABRAHAM
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

// ll smallest_not_poss(ll* arr, int n, ll k) // returns smallest sum > k that cannot be constructed by first n coins in arr
// {
//     if(n == 1)
//     {
//         if(arr[0] == k+1) return k+2;
//         return k+1;
//     }
//     ll prev_sum = smallest_not_poss(arr, n-1, k);
//     if(prev_sum < arr[n-1]) return prev_sum;
//     if(prev_sum - arr[n-1] > k)
// }


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> coins(n);
    for(int i = 0; i<n; ++i)
    {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());

    cout << smallest_not_poss(&coins[0], n);
}