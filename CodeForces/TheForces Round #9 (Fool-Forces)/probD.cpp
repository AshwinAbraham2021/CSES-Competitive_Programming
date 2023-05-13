#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

constexpr ll SIZE = 1000;
ll stars[SIZE][SIZE];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, M, Q;
    cin >> N >> M >> Q;
    for(ll i = 0; i < N; ++i)
    {
        ll x, y;
        cin >> x >> y;
        ++stars[x][y];
    }
    for(ll i = 0; i < M; ++i)
    {
        ll x, y;
        cin >> x >> y;
        if(x - 1 >= 0)
        {
            if(y - 1 >= 0)
            {
                stars[x - 1][y - 1] = 0;
            }
            stars[x - 1][y] = 0;
            if(y + 1 < SIZE)
            {
                stars[x - 1][y + 1] = 0;
            }
        }
        if(y - 1 >= 0)
        {
            stars[x][y - 1] = 0;
        }
        stars[x][y] = 0;
        if(y + 1 < SIZE)
        {
            stars[x][y + 1] = 0;
        }
        if(x + 1 < SIZE)
        {
            if(y - 1 >= 0)
            {
                stars[x + 1][y - 1] = 0;
            }
            stars[x + 1][y] = 0;
            if(y + 1 < SIZE)
            {
                stars[x + 1][y + 1] = 0;
            }
        }
    }
    // Now repurpose stars st stars[i][j] = total no of stars w/ x <= i and y <= j
    for(ll i = 1; i < SIZE; ++i) stars[i][0] += stars[i - 1][0];
    for(ll i = 1; i < SIZE; ++i) stars[0][i] += stars[0][i - 1];
    for(ll i = 1; i < SIZE; ++i)
    {
        for(ll j = 1; j < SIZE; ++j)
        {
            stars[i][j] += (stars[i][j - 1] + stars[i - 1][j] - stars[i - 1][j - 1]);
        }
    }

    for(ll i = 0; i < Q; ++i)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == 0)
        {
            if(y1 == 0)
            {
                cout << stars[x2][y2] << '\n';
            }
            else cout << stars[x2][y2] - stars[x2][y1 - 1] << '\n';
        }
        else if(y1 == 0)
        {
            cout << stars[x2][y2] - stars[x1 - 1][y2] << '\n';
        }
        else cout << stars[x2][y2] - stars[x1 - 1][y2] - stars[x2][y1 - 1] + stars[x1 - 1][y1 - 1] << '\n';
    }
}