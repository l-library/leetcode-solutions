#include <vector>
#include <unordered_map>

using namespace std;

// 参考数据结构课程算法
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> count(numCourses, 0);
    unordered_map<int, vector<int>> edges;
    for (auto i : prerequisites)
    {
        count[i[0]]++;
        // 储存从该点出发指向的边
        if (edges.find(i[1]) != edges.end())
            edges.at(i[1]).push_back(i[0]);
        else
            edges.insert({i[1], {i[0]}});
    }
    int top = -1; // 表示空栈
    for (int i = 0; i < numCourses; ++i)
    {
        if (count[i] == 0)
        {
            count[i] = top;
            top = i;
        }
    }
    for (int i = 0; i < numCourses; ++i)
    {
        if (top == -1)
            return false;
        // 出栈
        int j = top;
        top = count[top];
        // 扫描出栈元素连接的元素
        if (edges.find(j) == edges.end()) /// 如果没有从这个点指向外的边，不需要继续操作
            continue;
        auto &links = edges.at(j);
        while (!links.empty())
        {
            int temp = --count[links.back()];
            if (temp == 0)
            {
                count[links.back()] = top;
                top = links.back();
            }
            links.pop_back();
        }
    }
    return true;
}