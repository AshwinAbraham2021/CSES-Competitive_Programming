/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    int current_val = arr[0];
    int num_unique = 1;
    for(int i = 1; i<n; ++i)
    {
        if(arr[i]!=current_val)
        {
            ++num_unique;
            current_val = arr[i];
        }
    }
    cout << num_unique << '\n';
    return 0;
}