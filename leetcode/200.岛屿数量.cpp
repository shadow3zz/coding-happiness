/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-03-15 16:39:57
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-03-15 16:40:30
 */
/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量 
 * 同695相似 图的深度优先搜索
 */

// @lc code=start
class Solution {
private:
    int direction[4][2] = {
        {0,1},//right
        {0,-1},//left
        {-1,0},//up
        {1,0}//down
    };
    int row;
    int col;
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        row = grid.size();
        col = grid[0].size();

        pair<int, int> start;
        int sum = 0;
        for(int i = 0; i<row; i++){
            start.first = i; 
            for (int j = 0; j<col; j++){
                
                start.second = j;
                if (grid[start.first][start.second]=='0')
                    continue;
                sum++;
                numIslandsDFS(grid, start);
            }
        }
        return sum;
    }

    void numIslandsDFS(vector<vector<char>>& grid, pair<int, int> pos){
        if (grid[pos.first][pos.second]=='1'){
            grid[pos.first][pos.second] = '0';

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
                numIslandsDFS(grid, nextPos);
            }
        }
        else
            return;
    }
};
// @lc code=end

