/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (66.01%)
 * Total Accepted:    16.1K
 * Total Submissions: 24.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */
class Solution {
private:
    vector<vector<int>> ret;
    vector<bool> used;
    void generatePermutation(const vector<int>& nums,int index,vector<int>& p){

        if(index==nums.size()){
            ret.push_back(p);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!used[i]){
                //将nums[i]添加到p中
                p.push_back(nums[i]);
                used[i]=true;
                generatePermutation(nums,index+1,p);
                //这里很重要，一定要注意回溯法一定要有返回的地方
                p.pop_back();
                used[i]=false;
            }
        }
        return;
    };
public:
    vector<vector<int>> permute(vector<int>& nums) {
        ret.clear();
        if(nums.size()==0){
            return ret;
        }

        used=vector<bool>(nums.size(), false);
        vector<int> p;
        generatePermutation(nums,0,p);
        return ret;
    }
};

