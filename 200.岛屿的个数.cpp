/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿的个数
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (40.91%)
 * Total Accepted:    9K
 * Total Submissions: 21.8K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给定一个由 '1'（陆地）和
 * '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
 * 
 * 示例 1:
 * 
 * 输入:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * 输出: 3
 * 
 * 
 */
#include<iostream>
#include<assert.h>
#include<vector>

using namespace std;

class Solution {
private:
    int d[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
    int m,n;
    vector<vector<bool>> visited;
    bool inArea(int x,int y){
        return x>=0 && x<m && y>=0 && y<n;
    }
    void floodfill(vector<vector<char>>& grid,int x,int y){
        visited[x][y]=true;
        for(int i=0;i<4;i++){
            int newx=x+d[i][0];
            int newy=y+d[i][1];
            if(inArea(newx,newy) && !visited[newx][newy] && grid[newx][newy]=='1'){
                floodfill(grid,newx,newy);
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        if(m==0){
            return 0;
        }
        n=grid[0].size();

        visited=vector<vector<bool>>(m,vector<bool>(n,false));

        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    res++;
                    // floodfill算法
                    floodfill(grid,i,j);
                }
            }
        }
        return res;
    }
};

