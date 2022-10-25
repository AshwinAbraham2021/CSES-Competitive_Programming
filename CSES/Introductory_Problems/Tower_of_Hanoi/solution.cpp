/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <bits/stdc++.h>
using namespace std;
 
void printmoves(int n, int initial, int final)
{
    if(n==2)
    { //moves for 2 blocks
        cout << initial << ' ' << 6 - initial - final << '\n';
        cout << initial << ' ' << final << '\n';
        cout << 6 - initial - final << ' ' << final << '\n';
        return;
    }
    //consider first n-1 blocks as 1 big block
    printmoves(n-1, initial, 6 - initial - final);
    cout << initial << ' ' << final << '\n';
    printmoves(n-1, 6 - initial - final, final);
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    cout << (1<<n)-1 << '\n'; //T_n = 2T_(n-1) + 1
    if(n==1)
    {
        cout << "1 3\n";
        return 0;
    }
    printmoves(n, 1, 3);
    return 0;
}