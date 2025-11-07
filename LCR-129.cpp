#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// 复杂的迭代求法（利用栈模拟递归）
bool wordPuzzle(vector<vector<char>>& grid, string target) {
  if (target.size() == 0 || grid.size() == 0) return false;
  const int directions[4][2] = {
      {1, 0}, {-1, 0}, {0, -1}, {0, 1}};  // 向上，下，左，右
  struct Frame {
    int x, y, next_dir;
  };  // 存储下次从该格子要尝试的方向
  char start_word = target[0];  // 查找初始位置
  vector<vector<int>> start_coordinate;
  for (int i = 0; i < grid.size(); ++i)
    for (int j = 0; j < grid[0].size(); ++j)
      if (grid[i][j] == start_word) {
        start_coordinate.push_back({i, j});
      }
  if (start_coordinate.empty()) return false;
  // 遍历不同的起始坐标
  for (auto first_word : start_coordinate) {
    vector<vector<bool>> visited(
        grid.size(),
        vector<bool>(grid[0].size(), false));  // 存储已经访问过的坐标
    int current_x = first_word[0], current_y = first_word[1];
    stack<int> coordinate_x;
    stack<int> coordinate_y;
    if (target.size() == 1) return true;
    size_t word = 1;  // 遍历targrt
    coordinate_x.push(first_word[0]);
    coordinate_y.push(first_word[1]);
    visited[first_word[0]][first_word[1]] = true;  // 起始坐标已经访问过
    vector<Frame> next_direction;                  // 下一次要尝试的方向索引
    next_direction.push_back(
        {first_word[0], first_word[1], 0});  // 第一次遍历方向
    while (true) {
      // 查找已经走过的方向
      int has_try = 0;
      if (next_direction.back().x == current_x &&
          next_direction.back().y == current_y)
        has_try = next_direction.back().next_dir;
      else  // 当前节点没有过搜索数据
        next_direction.push_back(
            {current_x, current_y, has_try});  // 当前搜索位置
      for (; has_try < 4; ++has_try) {         // 存储已经走过的方向数量
        auto direction = directions[has_try];
        // 存储本次搜索
        next_direction.back().next_dir = has_try + 1;
        int x = current_x + direction[0], y = current_y + direction[1];
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
            !visited[x][y] && grid[x][y] == target[word])  // 有路可走
        {
          coordinate_x.push(x);
          coordinate_y.push(y);  // 进栈
          word++;                // 检查下一个词
          visited[x][y] = true;
          current_x = x;
          current_y = y;
          break;
        }  // 坐标更新
      }  // end of for
      if (coordinate_x.size() ==
          target.size())  // 全部进栈（栈大小等于字符串大小）
        return true;
      if (has_try == 4)  // 死路
        if (coordinate_x.size() == 1 &&
            coordinate_y.size() == 1)  // 只有初始坐标且是死路
        {
          break;
        } else {
          next_direction.pop_back();  // 当前位置已经访问过的方向信息删除
          visited[current_x][current_y] = false;  // 本次所在位置当作没有访问过
          coordinate_x.pop();
          coordinate_y.pop();  // 无路可走，回溯
          current_x = coordinate_x.top();
          current_y = coordinate_y.top();
          word--;
        }
    }  // end of while
  }  // end of for
  return false;
}