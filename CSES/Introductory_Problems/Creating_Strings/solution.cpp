/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <bits/stdc++.h>
using namespace std;
 
int fact[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320}; //factorial lookup table
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int arr[26] = {};
    char c;
    string s = "";
    while(cin >> c)
    {
        s+=c;
        ++arr[c-97];
    }
    int num_strings = fact[s.length()];
    for(int i = 0; i<26; ++i) num_strings/=fact[arr[i]]; //n = N!/(n1!n2!...)
    cout << num_strings << '\n';
    sort(s.begin(), s.end());
    for(int i = 0; i<num_strings; ++i)
    {
        cout << s << '\n';
        next_permutation(s.begin(), s.end()); 
    }
    return 0;
}