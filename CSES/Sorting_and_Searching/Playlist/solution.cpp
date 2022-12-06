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
    vector<ll> id(n);
    map<ll, vector<int>> pos;
    for(int i = 0; i<n; ++i)
    {
        cin >> id[i];
        pos[id[i]].push_back(i);
    }
    
    int max_len_i = 1; // max length of sequence of unique songs ending at i
    int max_len = 1; // max of above over all i
    for(int i = 1; i < n; ++i)
    {
        // [i - max_len_i, i) doesn't contain id[i]. i.e. pos[id[i]] doesn't contain any number in [i - max_len_i, i)
        const auto& x = pos[id[i]];
        if(*lower_bound(x.begin(), x.end(), i - max_len_i) == i) ++max_len_i;
        else
        {
            auto it = lower_bound(x.begin(), x.end(), i); // points to i
            --it; // points to largest element < i (el will be >= i - max_len_i)
            // interval is [*it + 1, i]
            max_len_i = i - *it;
        }

        if(max_len_i > max_len) max_len = max_len_i;
    }
    cout << max_len << '\n';
}