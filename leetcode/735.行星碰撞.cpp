/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-18 11:02:34
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-02-18 21:57:57
 */
/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

// @lc code=start
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> stk;
        stack<int> stk_;
        vector<int> result;
        for (int star : asteroids)
        {
            if (stk.empty())
                stk.push(star);
            else
            {
                int temp = stk.top();
                if (temp < 0) //栈顶为负数
                {
                    stk.push(star);
                    continue;
                }
                else //栈顶为正数
                {
                    if (star > 0) //目标为正数，直接入栈
                    {
                        stk.push(star);
                        continue;
                    }
                    else // 目标为负数，需要比较
                    {
                        int sum = temp + star;
                        if (sum > 0) //栈顶>目标，栈不变
                            continue;
                        else if (sum == 0) //栈顶==目标，栈顶弹出
                        {
                            stk.pop();
                            continue;
                        }
                        else
                        //栈顶<目标，栈顶弹出，检测栈顶是否仍旧小于目标，
                        //如果是继续弹出，直到栈顶大于目标或者栈为空或者
                        //栈顶为负数或者栈顶和目标相等
                        {
                            stk.pop();
                            while (!stk.empty())
                            {
                                if (stk.top() > 0 && stk.top() + star < 0)
                                    stk.pop();
                                else
                                    break;
                            }
                            if (stk.empty())
                            {
                                stk.push(star);
                                continue;
                            }
                            else if (stk.top() + star == 0)
                            {
                                stk.pop();
                                continue;
                            }
                            else if (stk.top() + star > 0)
                            {
                                continue;
                            }
                            else if (stk.top() < 0 || stk.empty())
                            {
                                stk.push(star);
                                continue;
                            }
                        }
                    }
                }
            }
        }

        while (!stk.empty())
        {
            stk_.push(stk.top());
            stk.pop();
        }
        while (!stk_.empty())
        {
            result.push_back(stk_.top());
            stk_.pop();
        }
        return result;
    }
};
// @lc code=end
