#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool wordPuzzle(vector<vector<char>>& grid, string target) {
  const int directions[4][2] = {
      {1, 0}, {-1, 0}, {0, -1}, {0, 1}};  // 向上，下，左，右
  char start_word = target[0];            // 查找初始位置
  vector<vector<int>> start_coordinate;
  for (int i = 0; i < grid.size(); ++i)
    for (int j = 0; j < grid[0].size(); ++j)
      if (grid[i][j] == start_word) {
        start_coordinate.push_back({i, j});
      }
  if (start_coordinate.empty()) return false;
  for (auto first_word : start_coordinate) {  // 起始坐标不同
    vector<vector<bool>> visited(
        grid.size(),
        vector<bool>(grid[0].size(), false));  // 存储已经访问过的坐标
    int current_x = first_word[0], current_y = first_word[1];
    stack<int> coordinate_x;
    stack<int> coordinate_y;
    size_t word = 1;  // 遍历targrt
    coordinate_x.push(first_word[0]);
    coordinate_y.push(first_word[1]);
    visited[first_word[0]][first_word[1]] = true;  // 起始坐标已经访问过
    while (true) {
      int barrier = 0;  // 存储无法前进的位置数量
      for (auto direction : directions) {
        int x = current_x + direction[0], y = current_y + direction[1];
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
            !visited[x][y] && grid[x][y] == target[word])  // 有路可走
        {
          coordinate_x.push(x);
          coordinate_y.push(y);                  // 进栈
          word++;                                // 检查下一个词
          visited[current_x][current_y] = true;  // 存储本次行动
          current_x = x;
          current_y = y;
          break;
        }  // 坐标更新
        else  // 无路可走
        {
          barrier++;
        }
      }  // end of for
      if (coordinate_x.size() ==
          target.size())  // 全部进栈（栈大小等于字符串大小）
        return true;
      if (barrier == 4)  // 死路
        if (coordinate_x.size() == 1 &&
            coordinate_y.size() == 1)  // 只有初始坐标且是死路
        {
          break;
        } else {
          coordinate_x.pop();
          coordinate_y.pop();  // 无路可走，回溯
          current_x = coordinate_x.top();
          current_y = coordinate_y.top();
          visited[current_x][current_y] = false;  // 上次所在位置当作没有访问过
          word--;
        }
    }  // end of while
  }  // end of for
  return false;
}