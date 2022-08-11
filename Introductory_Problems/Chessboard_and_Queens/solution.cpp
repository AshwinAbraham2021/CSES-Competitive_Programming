/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <bits/stdc++.h>
using namespace std;
 
const int board_size = 8;
 
vector<vector<bool> > add_queen(const vector<vector<bool> >& cb, int p, int q)
{
    vector<vector<bool> > added = cb;
    for(int i = 0; i<board_size; ++i)
    {
        added[p][i] = false;
        added[i][q] = false;
        if(p+q-i>=0 && p+q-i<board_size) added[i][p+q-i] = false;
        if(q-p+i>=0 && q-p+i<board_size) added[i][q-p+i] = false;
    }
    return added;
}
 
void numsolns(const vector<vector<bool> >& cb, int& num_solns, int num_queens_placed = 0)
{
    if(num_queens_placed == (board_size-1))
    {
        for(int i = 0; i<board_size; ++i)
        {
            if(cb[num_queens_placed][i]) ++num_solns;
        }
        return;
    }
    for(int i = 0; i<board_size; ++i)
    {
        if(cb[num_queens_placed][i]) numsolns(add_queen(cb, num_queens_placed, i), num_solns, 1+num_queens_placed);
    }
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<bool> > cb(board_size, vector<bool> (board_size));
    for(int i = 0; i<board_size; ++i)
    {
        for(int j = 0; j<board_size; ++j)
        {
            char c;
            cin >> c;
            cb[i][j] = (c=='.');
        }
    }
    int num_solns = 0;
    numsolns(cb, num_solns);
    cout << num_solns;
    return 0;
}