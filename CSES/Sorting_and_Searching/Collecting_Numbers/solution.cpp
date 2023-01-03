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
    vector<int> arr(n);
    vector<int> pos(n); // arr[pos[i]] = i
    for(int i = 0; i<n; ++i)
    {
        cin >> arr[i];
        --arr[i];
        pos[arr[i]] = i;
    }
    int rounds = 1;
    for(int i = 0; i < n - 1; ++i)
    {
        if(pos[i] > pos[i+1]) ++rounds;
    }
    cout << rounds << '\n';
}