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
    ll x;
    cin >> n >> x;
    vector<pair<ll, bool>> weights(n);
    for(int i = 0; i<n; ++i)
    {
        ll x;
        cin >> x;
        weights[i] = pair<ll, bool>(x, true); // second element checks whether it can be picked or not
    }

    sort(weights.begin(), weights.end());
    int num_gondolas = 0;
    bool just_keep_adding = false;
    for(auto iter = weights.begin(); iter != weights.end(); ++iter)
    {
        if(!iter->second) continue;
        iter->second = false;
        ++num_gondolas;
        if(just_keep_adding) continue;
        auto smallest_gthan = upper_bound(iter, weights.end(), pair<ll, bool>(x - iter->first, true)); // smallest element such that sum > x (may be picked or not)
        if(smallest_gthan == iter) just_keep_adding = true;
        else
        {
            --smallest_gthan; // largest element such that sum <= (may be picked or unpicked) (call the value in this element w)
            auto largest_leq = upper_bound(iter, smallest_gthan, pair<ll, bool>(smallest_gthan->first, false));
            // in [iter, smallest_gthan), all values are <= w
            // so this will return the smallest unpicked element (in closed interval [iter, smallest_gthan]) whose value is w (assuming there exists one)
            if(largest_leq->second) largest_leq->second = false;
            else
            {
                // all elements with value w had been picked
                while(largest_leq != iter && !largest_leq->second)
                {
                    smallest_gthan = lower_bound(iter, largest_leq, pair<ll, bool>(smallest_gthan->first, false));
                    // returns smallest element in the series with w (all of these have been picked)
                    if(smallest_gthan == iter)
                    {
                        just_keep_adding = true;
                        break;
                    }
                    --smallest_gthan; // largest element strictly less than w
                    largest_leq = upper_bound(iter, smallest_gthan, pair<ll, bool>(smallest_gthan->first, false));
                    // smallest unpicked element in [iter, smallest_gthan] with this value
                }
                largest_leq->second = false;
            }
        }
    }
    cout << num_gondolas << '\n';
}