#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

constexpr ll MAX_SIZE = 12;
ll costs[MAX_SIZE][MAX_SIZE];

// min cost of a path starting at vertex 0, then visiting every vertex in set \subseteq {1, 2 ... n - 1} - other_vertex, and then going to other vertex
ll min_cost(ll other_vertex, ll set_int, ll n)
{
    static ll min_cost_arr[MAX_SIZE - 1][1 << (MAX_SIZE - 2)];
    static bool memoized[MAX_SIZE - 1][1 << (MAX_SIZE - 2)];
    if(memoized[other_vertex][set_int]) return min_cost_arr[other_vertex][set_int];
    ll min_min_cost = INT64_MAX;
    for(ll i = 0; i < n; ++i)
    {
        if(set_int & (1 << i)) min_min_cost = min(costs[i][other_vertex] + min_cost(i, set_int & ~(1 << i), n), min_min_cost);
    }
    memoized[other_vertex][set_int] = true;
    min_cost_arr[other_vertex][set_int] = (min_min_cost == INT64_MAX ? costs[0][other_vertex] : min_min_cost);
    return min_cost_arr[other_vertex][set_int];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    cin >> N;
    for(ll i = 0; i < N; ++i)
    {
        for(ll j = 0; j < N; ++j)
        {
            cin >> costs[i][j];
        }
    }
    if(N == 2)
    {
        cout << costs[0][1] << '\n';
        return 0;
    }
    ll min_cost_cycle = INT64_MAX;
    for(ll other_vertex = 1; other_vertex < N; ++other_vertex)
    {
        min_cost_cycle = min(min_cost_cycle, min_cost(other_vertex, ~((1 << other_vertex) | 1), N) + costs[other_vertex][0]);
    }
    cout << min_cost_cycle << '\n';
}