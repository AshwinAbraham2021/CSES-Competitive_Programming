/*
 * AUTHOR: ASHWIN ABRAHAM
 */

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = int64_t;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    if(n == 1)
    {
        for(int i = 0; i < m; ++i) cout << "1\n";
        return 0;
    }
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
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        if(a == b)
        {
            cout << rounds << '\n';
            continue;
        }
        --a; --b;
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
        pos[arr[a]] = a;
        pos[arr[b]] = b;
        // lots of cases :( (in hindsight this could've been implemented better)
        // initially pos[i] < pos[i + 1] and finally pos[i] > pos[i + 1] => ++rounds
        // initially pos[i] > pos[i + 1] and finally pos[i] < pos[i + 1] => --rounds
        // we change pos only at arr[a] and arr[b] (minimum 1 comp to be checked, max 4)
        // initially pos[arr[a]] = b, pos[arr[b]] = a, finally pos[arr[a]] = a, pos[arr[b]] = b
        if(arr[a] == 0)
        {
            if(arr[b] == 1)
            {
                if(a < b)
                {
                    --rounds;
                }
                else
                {
                    ++rounds;
                }

                if(n > 2)
                {
                    if(a < pos[2] && b > pos[2])
                    {
                        ++rounds;
                    }
                    else if(a > pos[2] && b < pos[2])
                    {
                        --rounds;
                    }
                }
            }
            else if(arr[b] == n - 1)
            {
                if(b < pos[1] && a > pos[1])
                {
                    ++rounds;
                }
                else if(b > pos[1] && a < pos[1])
                {
                    --rounds;
                }

                if(pos[n - 2] < a && pos[n - 2] > b)
                {
                    ++rounds;
                }
                else if(pos[n - 2] > a && pos[n - 2] < b)
                {
                    --rounds;
                }
            }
            else
            {
                if(b < pos[1] && a > pos[1])
                {
                    ++rounds;
                }
                else if(b > pos[1] && a < pos[1])
                {
                    --rounds;
                }

                if(pos[arr[b] - 1] < a && pos[arr[b] - 1] > b)
                {
                    ++rounds;
                }
                else if(pos[arr[b] - 1] > a && pos[arr[b] - 1] < b)
                {
                    --rounds;
                }

                if(a < pos[arr[b] + 1] && b > pos[arr[b] + 1])
                {
                    ++rounds;
                }
                else if(a > pos[arr[b] + 1] && b < pos[arr[b] + 1])
                {
                    --rounds;
                }
            }
        }
        else if(arr[a] == n - 1)
        {
            if(arr[b] == n - 2)
            {
                if(a < b)
                {
                    ++rounds;
                }
                else
                {
                    --rounds;
                }

                if(n > 2)
                {
                    if(pos[n - 3] < a && pos[n - 3] > b)
                    {
                        ++rounds;
                    }
                    else if(pos[n - 3] > a && pos[n - 3] < b)
                    {
                        --rounds;
                    }
                }
            }
            else if(arr[b] == 0)
            {
                if(pos[n - 2] < b && pos[n - 2] > a)
                {
                    ++rounds;
                }
                else if(pos[n - 2] > b && pos[n - 2] < a)
                {
                    --rounds;
                }

                if(a < pos[1] && b > pos[1])
                {
                    ++rounds;
                }
                else if(a > pos[1] && b < pos[1])
                {
                    --rounds;
                }
            }
            else
            {
                if(pos[n - 2] < b && pos[n - 2] > a)
                {
                    ++rounds;
                }
                else if(pos[n - 2] > b && pos[n - 2] < a)
                {
                    --rounds;
                }

                if(a < pos[arr[b] + 1] && b > pos[arr[b] + 1])
                {
                    ++rounds;
                }
                else if(a > pos[arr[b] + 1] && b < pos[arr[b] + 1])
                {
                    --rounds;
                }

                if(pos[arr[b] - 1] < a && pos[arr[b] - 1] > b)
                {
                    ++rounds;
                }
                else if(pos[arr[b] - 1] > a && pos[arr[b] - 1] < b)
                {
                    --rounds;
                }
            }
        }
        else
        {
            if(arr[b] == n - 1)
            {
                if(arr[a] == n - 2)
                {
                    if(pos[n - 3] < b && pos[n - 3] > a)
                    {
                        ++rounds;
                    }
                    else if(pos[n - 3] > b && pos[n - 3] < a)
                    {
                        --rounds;
                    }

                    if(b < a)
                    {
                        ++rounds;
                    }
                    else
                    {
                        --rounds;
                    }
                }
                else
                {
                    if(pos[n - 2] < a && pos[n - 2] > b)
                    {
                        ++rounds;
                    }
                    else if(pos[n - 2] > a && pos[n - 2] < b)
                    {
                        --rounds;
                    }

                    if(pos[arr[a] - 1] < b && pos[arr[a] - 1] > a)
                    {
                        ++rounds;
                    }
                    else if(pos[arr[a] - 1] > b && pos[arr[a] - 1] < a)
                    {
                        --rounds;
                    }

                    if(b < pos[arr[a] + 1] && a > pos[arr[a] + 1])
                    {
                        ++rounds;
                    }
                    else if(b > pos[arr[a] + 1] && a < pos[arr[a] + 1])
                    {
                        --rounds;
                    }
                }
            }
            else if(arr[b] == 0)
            {
                if(arr[a] == 1)
                {
                    if(a < b)
                    {
                        ++rounds;
                    }
                    else
                    {
                        --rounds;
                    }

                    if(b < pos[2] && a > pos[2])
                    {
                        ++rounds;
                    }
                    else if(b > pos[2] && a < pos[2])
                    {
                        --rounds;
                    }
                }
                else
                {
                    if(a < pos[1] && b > pos[1])
                    {
                        ++rounds;
                    }
                    else if(a > pos[1] && b < pos[1])
                    {
                        --rounds;
                    }

                    if(pos[arr[a] - 1] < b && pos[arr[a] - 1] > a)
                    {
                        ++rounds;
                    }
                    else if(pos[arr[a] - 1] > b && pos[arr[a] - 1] < a)
                    {
                        --rounds;
                    }

                    if(b < pos[arr[a] + 1] && a > pos[arr[a] + 1])
                    {
                        ++rounds;
                    }
                    else if(b > pos[arr[a] + 1] && a < pos[arr[a] + 1])
                    {
                        --rounds;
                    }
                }
            }
            else
            {
                if(arr[a] == arr[b] - 1)
                {
                    if(b < a)
                    {
                        ++rounds;
                    }
                    else
                    {
                        --rounds;
                    }

                    if(pos[arr[a] - 1] < b && pos[arr[a] - 1] > a)
                    {
                        ++rounds;
                    }
                    else if(pos[arr[a] - 1] > b && pos[arr[a] - 1] < a)
                    {
                        --rounds;
                    }

                    if(a < pos[arr[b] + 1] && b > pos[arr[b] + 1])
                    {
                        ++rounds;
                    }
                    else if(a > pos[arr[b] + 1] && b < pos[arr[b] + 1])
                    {
                        --rounds;
                    }
                }
                else if(arr[a] == arr[b] + 1)
                {
                    if(a < b)
                    {
                        ++rounds;
                    }
                    else
                    {
                        --rounds;
                    }

                    if(pos[arr[b] - 1] < a && pos[arr[b] - 1] > b)
                    {
                        ++rounds;
                    }
                    else if(pos[arr[b] - 1] > a && pos[arr[b] - 1] < b)
                    {
                        --rounds;
                    }

                    if(b < pos[arr[a] + 1] && a > pos[arr[a] + 1])
                    {
                        ++rounds;
                    }
                    else if(b > pos[arr[a] + 1] && a < pos[arr[a] + 1])
                    {
                        --rounds;
                    }
                }
                else
                {
                    if(pos[arr[a] - 1] < b && pos[arr[a] - 1] > a)
                    {
                        ++rounds;
                    }
                    else if(pos[arr[a] - 1] > b && pos[arr[a] - 1] < a)
                    {
                        --rounds;
                    }

                    if(b < pos[arr[a] + 1] && a > pos[arr[a] + 1])
                    {
                        ++rounds;
                    }
                    else if(b > pos[arr[a] + 1] && a < pos[arr[a] + 1])
                    {
                        --rounds;
                    }

                    if(pos[arr[b] - 1] < a && pos[arr[b] - 1] > b)
                    {
                        ++rounds;
                    }
                    else if(pos[arr[b] - 1] > a && pos[arr[b] - 1] < b)
                    {
                        --rounds;
                    }

                    if(a < pos[arr[b] + 1] && b > pos[arr[b] + 1])
                    {
                        ++rounds;
                    }
                    else if(a > pos[arr[b] + 1] && b < pos[arr[b] + 1])
                    {
                        --rounds;
                    }
                }
            }
        }
        cout << rounds << '\n';
    }
}