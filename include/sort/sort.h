/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-03-17 15:38:29
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-03-17 16:05:44
 */
template <typename Comparable>
void insertionSort(vector<Comparable> &a);

template <typename Comparable>
void insertionSort(vector<Comparable> &a){
    int j;
    for (int i = 1; i<a.size(); ++i){
        Comparable temp = a[i];
        for (j = i; j > 0&& temp < a[j-1]; j--){
            a[j] = a[j-1];
        }
        a[j] = temp;
        
    }
}