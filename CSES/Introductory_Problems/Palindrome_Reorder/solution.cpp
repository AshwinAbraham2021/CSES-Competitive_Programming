/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int arr[26] = {};
    char c;
    int total_num = 0;

    while(cin >> c)
    {
        ++arr[c-65];
        ++total_num;
    }

    int num_odd = 0, el_odd;
    for(int i = 0; i<26; ++i)
    {
        if(arr[i]%2)
        {
            ++num_odd;
            el_odd = i;
        }
    }

    if(total_num%2)
    {
        if(num_odd!=1)
        {
            cout << "NO SOLUTION\n";
            return 0;
        }
        for(int i = 0; i<26; ++i)
        {
            for(int j = 0; j<arr[i]/2; ++j) cout << char(i+65);
        }
        cout << char(el_odd+65);
        for(int i = 25; i>=0; --i)
        {
            for(int j = 0; j<arr[i]/2; ++j) cout << char(i+65);
        }
        cout << '\n';
        return 0;
    }

    if(num_odd!=0)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }

    for(int i = 0; i<26; ++i)
    {
        for(int j = 0; j<arr[i]/2; ++j) cout << char(i+65);
    }

    for(int i = 25; i>=0; --i)
    {
        for(int j = 0; j<arr[i]/2; ++j) cout << char(i+65);
    }

    cout << '\n';
    
    return 0;
}