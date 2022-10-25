/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    char c, cprevious = '\0';
    int len = 0, maxlen = 1;
    while(cin >> c)
    {
        if(c == cprevious) ++len;
        else len = 0;
        maxlen = ((1+len)>maxlen? (1+len):maxlen);
        cprevious = c;
    }
    cout << maxlen;
    return 0;
}