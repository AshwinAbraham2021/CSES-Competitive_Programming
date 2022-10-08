#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    ull k;
    cin >> n >> m >> k;
    vector<ull> des_sizes(n);
    vector<ull> av_sizes(m);
    for(int i = 0; i<n; ++i) cin >> des_sizes[i];
    for(int i = 0; i<m; ++i) cin >> av_sizes[i];

    sort(des_sizes.begin(), des_sizes.end());
    sort(av_sizes.begin(), av_sizes.end());

    int lbound = 0, rbound = 0;
    vector<pair<int, int>> ranges(n);
    for(int i = 0; i<n; ++i)
    {
        if(i == 0)
        {
            while(lbound >= 0 && av_sizes[lbound] >= des_sizes[i] - k) --lbound;
            ++lbound;
            while(rbound < m && av_sizes[rbound] <= des_sizes[i] + k) ++rbound;
            --rbound;
            ranges[i] = pair<int, int>(lbound, rbound);
        }
        else
        {
            while(lbound < m && av_sizes[])
        }
    }
}