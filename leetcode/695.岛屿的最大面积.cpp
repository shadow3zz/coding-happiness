/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-03-15 16:02:34
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-03-15 16:29:26
 */
/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
private:
    int direction[4][2] = {
            {0,1},  //right
            {0,-1},  //left
            {-1,0},  //up
            {1,0}   //down
        };
    int row;
    int col;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        pair<int, int> start(0, 0);
        int maxStep = 0;
        for(int i = 0; i<row; i++){
            start.first = i; 
            for (int j = 0; j<col; j++){
                int step=0;
                start.second = j;
                if (grid[start.first][start.second]==0)
                    continue;
                maxAreaOfIslandDFS(grid, start, step);
                maxStep = maxStep < step ? step:maxStep;
            }
        }
        return maxStep;
    }
    //深度优先搜索
    void maxAreaOfIslandDFS(vector<vector<int>>& grid, pair<int, int> pos, int &step){
        if (grid[pos.first][pos.second]==1){
            step++;
            grid[pos.first][pos.second] = 0;

            pair<int, int> nextPos(pos);
            for(int k=0; k<4;++k){
                // 判断四个方向
                nextPos.first = pos.first + direction[k][0];
                nextPos.second = pos.second + direction[k][1];
                if (nextPos.first < 0 || nextPos.first >= row || nextPos.second < 0 || nextPos.second >= col)
                {
                    //超出索引
                    continue;
                }
                maxAreaOfIslandDFS(grid, nextPos, step);
            }
        }
        else{
            return;
        }

    }
};
// @lc code=end

