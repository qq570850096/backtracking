/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (58.77%)
 * Total Accepted:    5K
 * Total Submissions: 8.4K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 */
#include<iostream>
#include<vector>
#include<assert.h>
#include<string>

using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    vector<bool> col,dia1,dia2;
    // 尝试在n皇后的问题中,拜访第index个皇后的位置
    void putQueue(int n,int index,vector<int>& row){
        if(index==n){
            res.push_back(generateBoard(n,row));
            return;
        }
        for(int i=0;i<n;i++){
            //尝试将第index行的皇后拜访在第i列
            if(!col[i] && !dia1[index+i] && !dia2[index-i+n-1]){
                row.push_back(i);
                col[i]=true;
                dia1[index+i]=true;
                dia2[index-i+n-1]=true;
                putQueue(n,index+1,row);
                col[i]=false;
                dia1[index+i]=false;
                dia2[index-i+n-1]=false;
                row.pop_back();
            }
        }
        return;
    }
    vector<string> generateBoard(int n,vector<int>& row){
        assert(row.size()==n);
        vector<string> Board(n,string(n,'.'));
        for(int i=0;i<n;i++){
            Board[i][row[i]]='Q';
        }
        return Board;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();

        col=vector<bool>(n,false);
        dia1=vector<bool>(2*n-1,false);
        dia2=vector<bool>(2*n-1,false);
        vector<int> row;
        putQueue(n,0,row);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int n=4;
    vector<vector<string>> res=Solution().solveNQueens(n);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<n;j++){
            cout<<res[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}


