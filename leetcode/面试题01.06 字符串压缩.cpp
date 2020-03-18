/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-03-16 11:51:17
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-03-16 12:07:27
 */
class Solution {
public:
    string compressString(string S) {
        string result;
        int length = S.size();
        if ( length <=1 ) return S;
        char the_word = S[0];
        int count = 1;
        for (int i=1;i<length;++i){
            
            if (S[i] == the_word){
                count++;
            }
            if (S[i] != the_word){
                result += (the_word+to_string(count));
                count = 1;
            }
            the_word = S[i];
        }
        result += (the_word+to_string(count));
        return length <= result.size()?S:result;
    }
};