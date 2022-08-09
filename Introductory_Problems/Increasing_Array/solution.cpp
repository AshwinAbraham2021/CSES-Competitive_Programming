#include <bits/stdc++.h>
using namespace std;

typedef uint64_t ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    ll el;
    cin >> el;
    ll max = el, nummoves = 0;
    while(cin >> el)
    {
        max = (max>el? max:el);
        if(max>el) nummoves+= max-el;
    }
    cout << nummoves;
    return 0;
}