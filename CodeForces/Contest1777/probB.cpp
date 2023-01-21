#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        int worst = 0, best = 0;
        // TODO
    }
}