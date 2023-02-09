#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // we can calculate the factors of every integer upto M in O(M log M)
    constexpr int MAXM = 100'000;
    vector<vector<int>> factors(MAXM); // factors[i - 1] contains all the factors of i in a sorted manner
    for(int i = 1; i <= MAXM; ++i)
    {
        for(int j = i; j <= MAXM; j += i) factors[j - 1].push_back(i);
    }

    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        vector<int> counts(m);
        int tot_count = 0;
        int min_diff = 1'000'000;
        int lptr = 0, rptr = 0;
        for(auto x : factors[a[0] - 1])
        {
            if(x > m) break;
            if(counts[x - 1] == 0) ++tot_count;
            ++counts[x - 1];
        }
        if(tot_count == m)
        {
            cout << "0\n";
            continue;
        }
        while(true)
        {
            for(++rptr; rptr < n; ++rptr)
            {
                for(auto x : factors[a[rptr] - 1])
                {
                    if(x > m) break;
                    if(counts[x - 1] == 0) ++tot_count;
                    ++counts[x - 1];
                }
                if(tot_count == m) break;
            }
            if(rptr >= n) break;
            for(; tot_count == m; ++lptr)
            {
                min_diff = min(min_diff, a[rptr] - a[lptr]);
                for(auto x : factors[a[lptr] - 1])
                {
                    if(x > m) break;
                    if(counts[x - 1] == 1) --tot_count;
                    --counts[x - 1];
                }
            }
        }
        cout << (min_diff == 1'000'000 ? -1 : min_diff) << '\n';
    }
}
