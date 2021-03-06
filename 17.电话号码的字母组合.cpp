/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (47.50%)
 * Total Accepted:    16.6K
 * Total Submissions: 34.7K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */
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
