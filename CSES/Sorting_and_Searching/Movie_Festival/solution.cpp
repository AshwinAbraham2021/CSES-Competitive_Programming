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
    vector<pair<ll, ll>> start_end(n);
    for(int i = 0; i<n; ++i)
    {
        cin >> start_end[i].first >> start_end[i].second;
    }
    sort(start_end.begin(), start_end.end(), [](const auto& v1, const auto& v2){ return v1.second < v2.second; });

    ll next_can_start = -1;
    int num_movies = 0;
    for(int i = 0; i<n; ++i)
    {
        if(start_end[i].first >= next_can_start)
        {
            ++num_movies;
            next_can_start = start_end[i].second;
        }
    }
    cout << num_movies << '\n';
}