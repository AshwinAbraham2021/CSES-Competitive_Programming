/*
 * AUTHOR: ASHWIN ABRAHAM
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> entries(n), exits(n);
    for(int i = 0; i<n; ++i)
    {
        cin >> entries[i] >> exits[i];
    }

    sort(entries.begin(), entries.end());
    sort(exits.begin(), exits.end());

    int enter_ind = 0, exit_ind = 0;
    int num_current = 0;
    int num_max = 0;
    while(enter_ind < n && exit_ind < n)
    {
        if(entries[enter_ind] < exits[exit_ind])
        {
            ++enter_ind;
            ++num_current;
        }
        else
        {
            --num_current;
            ++exit_ind;
        }
        num_max = max(num_current, num_max);
    }
    while(enter_ind < n)
    {
        ++enter_ind;
        ++num_current;
        num_max = max(num_current, num_max);
    }
    cout << num_max << '\n';
}