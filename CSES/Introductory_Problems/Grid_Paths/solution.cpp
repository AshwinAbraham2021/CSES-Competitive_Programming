/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <bits/stdc++.h>
using namespace std;
 
const int grid_size = 7;
 
void find_ways(const string& path_string, vector<vector<bool> >& grid, int& num_ways, int start_x = 0, int start_y = 0, int num_moves = 0)
{
    if(num_moves == grid_size*grid_size - 1)
    {
        if(start_x == 0 && start_y == grid_size-1) ++num_ways;
        return;
    }
    if(grid[0][grid_size-1]) return; //If final element has already been reached, invalid path
    bool R = 1+start_x < grid_size && !grid[1+start_x][start_y];
    bool L = -1+start_x >=0 && !grid[-1+start_x][start_y];
    bool U = -1+start_y >=0 && !grid[start_x][-1+start_y];
    bool D = 1+start_y < grid_size && !grid[start_x][1+start_y];
    if(!R && !L)
    {
        //if we can only move in 2 opposite directions
        //then graph is divided into 2 disjoint parts
        //1 of those parts must be completely filled for path to be valid
        if(D&&U) return;
    }
    if(!D && !U)
    {
        if(R && L) return;
    }
    if(R && (path_string[num_moves]=='?' || path_string[num_moves]=='R'))
    {
        grid[1+start_x][start_y] = true;
        find_ways(path_string, grid, num_ways, 1+start_x, start_y, 1+num_moves);
        grid[1+start_x][start_y] = false;
    }
    if(L && (path_string[num_moves]=='?' || path_string[num_moves]=='L'))
    {
        grid[-1+start_x][start_y] = true;
        find_ways(path_string, grid, num_ways, -1+start_x, start_y, 1+num_moves);
        grid[-1+start_x][start_y] = false;
    }
    if(D && (path_string[num_moves]=='?' || path_string[num_moves]=='D'))
    {
        grid[start_x][1+start_y] = true;
        find_ways(path_string, grid, num_ways, start_x, 1+start_y, 1+num_moves);
        grid[start_x][1+start_y] = false;
    }
    if(U && (path_string[num_moves]=='?' || path_string[num_moves]=='U'))
    {
        grid[start_x][-1+start_y] = true;
        find_ways(path_string, grid, num_ways, start_x, -1+start_y, 1+num_moves);
        grid[start_x][-1+start_y] = false;
    }
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string path_string;
    getline(cin, path_string);
    vector<vector<bool> > grid(grid_size, vector<bool>(grid_size, false));
    grid[0][0] = true;
    int num_ways = 0;
    find_ways(path_string, grid, num_ways);
    cout << num_ways << '\n';
    return 0;
}
