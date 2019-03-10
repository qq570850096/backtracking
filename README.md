##递归与回溯

**1. 树型问题**
测试用例，[leetcode第17题](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/,"leetcode-cn")
　　**给出一个数字字符串，返回这个数字字符串表示的所有字母组合**
 <div align=center>![手机](https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)
>示例
>>输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
</div>
***
***
需要考虑

    1. 字符串的合法性
    2. 空字符串怎么办
    3. 多个解的顺序
***
***


**这是通过递归的方法进行解决问题**
```cpp
    class Solution {
    private:
        const string letterMap[10]={
            " ",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        	vector<string> res;
        // s 中保存了此时从digits[0...index]翻译得到的一个字母字符串
        // 寻找和digits[index]匹配的字母，获得digits[0...index]翻译得到的解
        void findCombination(const string &digits,int index,const string &s){

            if(index==digits.size()){
                //保存swenti
                res.push_back(s);
                return;
            }

            char c = digits[index];
            assert(c>='0'&&c<='9'&&c!='1');
            string letters=letterMap[c-'0'];
            for(int i=0;i<letters.size();i++){
                findCombination(digits,index+1,s+letters[i]);
            }
            return;
        }
    public:
        vector<string> letterCombinations(string digits) {
            res.clear();

            if(digits==""){
                return res;
            }
            findCombination(digits,0,"");
            return res;
        }
    };
```
  我们可以看到递归的一个重要特征－要返回（回溯），其中回溯的方法经常出现在需要查找数据的问题
  **在本算法中，时间复杂度 3<sup>n</sup>=O(2<sup>n</sup>) ,指数级的复杂度**
  回溯法是**暴力解法的一个重要实现手段**
  练习题，[Restore IP Adresses](https://leetcode-cn.com/problems/restore-ip-addresses/)
  以及[分割回文串](https://leetcode-cn.com/problems/palindrome-partitioning/)
  
***
***
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
**2. 排列问题**
>使用例题 leetcode 46题[全排列](https://leetcode-cn.com/problems/permutations/)
>给定一个没有重复数字的序列，返回其所有可能的全排列。

**示例:**
>输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
  [3,1,2],
  [3,2,1]
]

Perms(nums[0...n-1])={取出一个数字}+Perms(nums[0...n-1}-这个数字])
**代码:**
```cpp
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
```
***
***
在本题中的回溯与找电话号码最大的**区别**就是**如果其他的变量需要回去,那么也要进行重置**

>练习题
>>leetcode第47题[全排列II](https://leetcode-cn.com/problems/permutations-ii/)
>>这个问题中要进行全排列的数组有重复的数据，思考一下如何进行回溯的过程
>>**递归树很重要，如果思考不出来就画出递归树**

***
***
**3. 组合问题**

**用例:**

leetcode第77题[组合问题](https://leetcode-cn.com/problems/combinations/)
>给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
>
>**示例：**
>
>>输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

**代码:**

```cpp
class Solution {
private:
    vector<vector<int>> ret;
    // 求解ｃ（ｎ，ｋ），当前已经找到的组合存储在ｃ总，需要从start搜索新元素
    void generateCombinations(int n,int k,int start,vector<int>& c){
        if(c.size()==k){
            ret.push_back(c);
            return;
        }

        for(int i=start;i<=n;i++){
            c.push_back(i);
            generateCombinations(n,k,i+1,c);
            //这里的回溯很重要
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
```
***
***
**回溯法的重要优化--剪枝**
显然在本题中n代表了数的**分支数**,k代表了数的**深度**，显然当k很大的时候，最后一条特别深的路没有必要走，我们应该对其进行剪枝。

```cpp
// 还有k-c.size()个空位，所以[i...n]中至少要有k-c.size()个元素
// i最大就是n-(k-c.size())+1
 for(int i=start;i<=n-(k-c.size())+1;i++){
            c.push_back(i);
            generateCombinations(n,k,i+1,c);
            //这里的回溯很重要
            c.pop_back();
        }
       
```
>练习题：
>
>>leetcode第39题[组合总和](https://leetcode-cn.com/problems/combination-sum/)和[组合总和3](https://leetcode-cn.com/problems/combination-sum-iii/)
>>
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
>>candidates 中的数字可以无限制重复被选取。

**说明：**

* 所有数字（包括 target）都是正整数。
* 解集不能包含重复的组合。 

>**示例 1:**

>>输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]

>**示例 2:**

>>输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

***
***

**4.在二维平面上使用回溯法**

>例题: leetcode第79题[单词查找](https://leetcode-cn.com/problems/word-search/)
>
>给定一个二维网格和一个单词，找出该单词是否存在于网格中。
>
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

**示例:**

>board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.

**解题思路**
先找到第一个匹配的字符,然后从这个字符的上下左右开始寻找(**同时要判断不能越界**),递归结构

```cpp
class Solution {
private:
    int d[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    int m,n;
    vector<vector<bool>> visited;
    bool inArea(int x,int y){
        return x>=0&&x<m&&y>=0&&y<n;
    }
    //  从board[startx][starty]开始,寻找word[index....word.size()]
    bool searchWorld(const vector<vector<char>>& board,const string& word,int index,int startx,int starty){
        // 递归终止条件
        if(index==word.size()-1){
            return board[startx][starty]==word[index];
        }
        if(board[startx][starty]==word[index]){
            visited[startx][starty]=true;
            //从四个方向开始寻找
            for(int i=0;i<4;i++){
                int newx=startx+d[i][0];
                int newy=starty+d[i][1];
                if(inArea(newx,newy) && !visited[newx][newy] && searchWorld(board,word,index+1,newx,newy)){
                    return true;
                }
            }
            visited[startx][starty]=false;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        assert(m>0);
        n=board[0].size();
        visited=vector<vector<bool>>(m,vector<bool>(n,false));
        for(int i = 0; i < board.size(); i++)
        {
            for(int j=0;j<board[i].size();j++){
                if(searchWorld(board,word,0,i,j)){
                    return true;
                }
            }
        }
        return false;
    }
};
```
***
***
**5.floodfill算法,解决一类经典问题**

本质**深度优先遍历**

>例题:leetcode第200题[岛屿的数量](https://leetcode-cn.com/problems/number-of-islands/)
>
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

**示例 1:**

>输入:
11110
11010
11000
00000

>输出: 1

**示例 2:**

>输入:
11000
11000
00100
00011

>输出: 3

**思路:**


```cpp
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
```
练习题,leetcode130题与417题

###回溯法是经典人工智能的基础

**n皇后问题:**
leetcode第51题
**n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。**
<div align="center">![n皇后](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/8-queens.png)
</div>

>上图为 8 皇后问题的一种解法。
>
>给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

**示例:**

>输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

> ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
**解释: 4 皇后问题存在两个不同的解法。**

**剪枝的方法::**竖向和两条对角线使用辅助数组记录已经被占用的情况其中/方向对角线可用**i+j**计算出在哪个地方,\方向对角线i-j可得固定值**
(i-j)+n-1**

**代码:**
```cpp
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
```
**N皇后问题还有很多优化的思路**
**剪枝:如下图,只是其中一种优化思路**
<div align="center">![剪枝](https://img-blog.csdn.net/20180116200329031?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvd2VpeGluXzM4Mzc5Nzcy/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)</div>
<div align="center">
规模n|暴力法的节点|回溯法节点数|解个数|效率比
---|:--:|:--:|:--:|---:
4|340|60|2|17.6%
5|3905|220|10|5.6%
6|55986|894|4|1.6%
7|960799|3584|40|0.37
8|19173960|15720|92|0.082%

**我们还可以继续优化,因为棋盘是对称的,那么我们计算出上半部分的摆放方法时就可以得到全部的解,可估算算法效率能提升50%**



