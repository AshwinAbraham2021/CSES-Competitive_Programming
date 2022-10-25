/*
 * AUTHOR: ASHWIN ABRAHAM
 */

#include <bits/stdc++.h>
using namespace std;
using ull = int64_t;


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

    int dptr = 0;
    int max_num = 0;
    for(int aptr = 0; aptr < m; ++aptr)
    {
        while (dptr < n && av_sizes[aptr] > des_sizes[dptr] + k) ++dptr;
        if(dptr >= n) break;
        else if(av_sizes[aptr] >= des_sizes[dptr] - k)
        {
            ++max_num;
            ++dptr;
        }
    }
    cout << max_num << '\n';
}