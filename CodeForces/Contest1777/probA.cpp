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
        int n;
        cin >> n;
        int x;
        cin >> x;
        bool curr_par = (x % 2);
        int num_ops = 0;
        for(int i = 1; i < n; ++i)
        {
            cin >> x;
            if(curr_par == x % 2) ++num_ops;
            curr_par = x % 2;
        }
        cout << num_ops << '\n';
    }
}