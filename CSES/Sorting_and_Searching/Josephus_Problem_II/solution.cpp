/*
 * AUTHOR: ASHWIN ABRAHAM
 */

#include <bits/stdc++.h>
#include "order_statistics_tree.hpp"
#include <unistd.h>
using namespace std;
using ll = int64_t;

int next_killed(int n, int k, int prev_killed, const Set<int> &killed)
{
    // there should be k + 1 alive elements in [prev_killed, ret_val] (cyclic range), ret_val should be alive
    // since num alive is monotonic wrt cyclic range we can use binary search
    cout << "\nFUNC " << n << ' ' << k << ' ' << prev_killed << ' ' << killed.greater(prev_killed) << " SET: ";
    for(int x: killed) cout << ' ' << x << ' ';
    cout << endl;
    cout << "\n LHS: " << n - prev_killed - 1 - killed.greater(prev_killed) << endl;
        if(n == 7 && k == 1 && prev_killed == 0) sleep(5);
    if(n - prev_killed - 1 - killed.greater(prev_killed) >= k + 1)
    {
        // our function is f(x) = x - prev_killed + 1 - killed.in_range(prev_killed, x), prev_killed <= x <= n - 1
        // We will find smallest x such that f(x) == k + 1 -> (this will be alive)
        int x_low = prev_killed; // f(x_low) < k + 1 invariant
        int x_high = n - 1; // f(x_high) >= k + 1 invariant
        while(x_high - x_low > 1)
        {
            int x_mid = (x_low + x_high)/2;
            cout << x_mid << ' ' << prev_killed << ' ' << killed.in_range(prev_killed, x_mid) << " BRUH LMAO\n";
            if(x_mid - prev_killed + 1 - killed.in_range(prev_killed, x_mid) >= k + 1) x_high = x_mid;
            else x_low = x_mid;
        }
        // finally x_high -> smallest val such that f(x) >= k + 1, x_low -> largest val such that f(x) < k + 1
        return x_high; // because equality is achieved
    }
    else
    {
        // our function is f(x) = x + 1 - killed.lesser(x + 1) + n - prev_killed - 1 - killed.greater(prev_killed), 0 <= x <= prev_killed - 1
        int const_term = n - prev_killed - 1 - killed.greater(prev_killed);
        int t_low = 0;
        int t_high = prev_killed;
        while(t_high - t_low > 1)
        {
            int t_mid = (t_high + t_low)/2;
            cout << t_mid << ' ' << killed.lesser(t_mid) << ' ' << const_term << " BRUH LMAO\n";
            if(t_mid - killed.lesser(t_mid) + const_term >= k + 1) t_high = t_mid;
            else t_low = t_mid;
        }
        return t_high - 1;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    if(n == 1)
    {
        cout << "1\n";
        return 0;
    }
    ll big_k;
    cin >> big_k;
    int k = (big_k % n);
    // set<int> alive;
    // for(int i = 0; i < n; ++i) alive.insert(i);
    Set<int> killed;
    int prev_killed = k;
    killed.insert(prev_killed);
    // alive.erase(k);
    cout << prev_killed + 1;
    for(int i = 1; i < n; ++i)
    {
        // int next = ((alive.upper_bound(prev_killed) == alive.end()) ? *alive.begin() : *alive.upper_bound(prev_killed));
        prev_killed = next_killed(n, k % (n - i), prev_killed, killed);
        killed.insert(prev_killed);
        cout << ' ' << prev_killed + 1;
    }
    cout << '\n';
}