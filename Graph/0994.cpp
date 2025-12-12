#include <vector>
#include <queue>
#include <map>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    if (grid.empty())
        return 0;
    queue<pair<int, int>> rotten;
    int num_unrot = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            if (grid[i][j] == 2)
                rotten.push({i, j});
            else if (grid[i][j] == 1)
                num_unrot++;
        }
    }
    int result = 0;
    while (!rotten.empty())
    {
        int num = rotten.size();
        while (num != 0)
        {
            int x = rotten.front().first;
            int y = rotten.front().second;
            if (x > 0 && grid[x - 1][y] == 1)
            {
                grid[x - 1][y] = 2;
                rotten.push({x - 1, y});
                num_unrot--;
            }
            if (x < grid.size() - 1 && grid[x + 1][y] == 1)
            {
                grid[x + 1][y] = 2;
                rotten.push({x + 1, y});
                num_unrot--;
            }
            if (y > 0 && grid[x][y - 1] == 1)
            {
                grid[x][y - 1] = 2;
                rotten.push({x, y - 1});
                num_unrot--;
            }
            if (y < grid[0].size() - 1 && grid[x][y + 1] == 1)
            {
                grid[x][y + 1] = 2;
                rotten.push({x, y + 1});
                num_unrot--;
            }
            rotten.pop();
            num--;
        }
        result++;
    }
    if (!num_unrot && result)
        return result - 1;
    else if (!result && !num_unrot)
        return result;
    else
        return -1;
}