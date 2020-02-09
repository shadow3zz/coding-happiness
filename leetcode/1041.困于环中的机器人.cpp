/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-08 15:00:02
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-02-08 15:23:45
 */
/*
 * @lc app=leetcode.cn id=1041 lang=cpp
 *
 * [1041] 困于环中的机器人
 */

// @lc code=start
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0,y=0;
        double thea = M_PI/2;
        for (auto s:instructions)
        {
            if(thea >= M_PI*2) thea -= M_PI*2;
            if(thea < 0) thea += M_PI*2;
            switch (s)
            {
            case 'G':
                x += int(cos(thea));
                y += int(sin(thea));
                break;
            case 'L':
                thea += M_PI/2;
                break;
            case 'R':
                thea -= M_PI/2;
                break;
            default:
                break;
            }
        }
        if ((x != 0 || y != 0) && (thea == M_PI/2))
            return false;
        else 
            return true;
    }
};
// @lc code=end

