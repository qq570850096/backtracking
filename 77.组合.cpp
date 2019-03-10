/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (65.36%)
 * Total Accepted:    7.3K
 * Total Submissions: 11.1K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ret;
    // 求解ｃ（ｎ，ｋ），当前已经找到的组合存储在ｃ总，需要从start搜索新元素
    void generateCombinations(int n,int k,int start,vector<int>& c){
        
        if(c.size()==k){
            ret.push_back(c);
            return;
        }

        for(int i=start;i<=n-(k-c.size())+1;i++){
            c.push_back(i);
            generateCombinations(n,k,i+1,c);
            c.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        ret.clear();
        if(n<=0||k<=0||n<k){
            return ret;
        }
        vector<int> c;
        generateCombinations(n,k,1,c);
        return ret;
    }
};

