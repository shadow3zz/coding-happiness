/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-18 22:04:49
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-02-21 22:51:25
 */
/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 *
 * [1260] 二维网格迁移
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int m, n;
        m = grid.size();
        n = grid[0].size();
        if (m == 0)
            return grid;
        for (; k > 0; k--)
        {
            vector<int> last_line;
            last_line.push_back(0);
            for (int i = 0; i < m; i++)
            {
                last_line.push_back(grid[i][n-1]);
            }
            for (int j = 0; j < m; j++)
            {
                for (int l = n-1; l > 0; l--)
                {
                    grid[j][l] = grid[j][l-1];
                }
                grid[j][0] = last_line[j];
            }
            grid[0][0] = last_line.back();
        }
        return grid;
    }
};
// @lc code=end
