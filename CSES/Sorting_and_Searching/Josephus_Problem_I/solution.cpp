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
    if(n == 1)
    {
        cout << "1\n";
        return 0;
    }
    vector <int> succ(n);
    for(int i = 0; i < n; ++i) succ[i] = (i + 1) % n;
    vector<int> pred(n);
    pred[0] = n - 1;
    for(int i = 1; i < n; ++i) pred[i] = (i - 1) % n;

    int killed = 1;
    cout << "2";
    for(int i = 1; i < n ; ++i)
    {
        int next_to_killed = succ[killed];
        succ[pred[killed]] = succ[killed];
        pred[succ[killed]] = pred[killed];
        killed = succ[next_to_killed];
        cout << ' ' << killed + 1;
    }
    cout << '\n';
}