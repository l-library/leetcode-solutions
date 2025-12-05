#include <vector>

using namespace std;

void helper(vector<vector<char>> &grid, vector<vector<char>> &visited, int i, int j)
{
    if (visited[i][j] == 1 || grid[i][j] == '0')
        return;
    visited[i][j] = 1;
    if (i - 1 >= 0)
        helper(grid, visited, i - 1, j);
    if (i + 1 < grid.size())
        helper(grid, visited, i + 1, j);
    if (j - 1 >= 0)
        helper(grid, visited, i, j - 1);
    if (j + 1 < grid[0].size())
        helper(grid, visited, i, j + 1);
}

int numIslands(vector<vector<char>> &grid)
{
    vector<vector<char>> visited(grid.size(), vector<char>(grid[0].size(), 0));
    int count = 0;
    for (int i = 0; i < grid.size(); ++i)
        for (int j = 0; j < grid[0].size(); ++j)
            if (visited[i][j] != 1 && grid[i][j] == '1')
            {
                helper(grid, visited, i, j);
                count++;
            }
    return count;
}