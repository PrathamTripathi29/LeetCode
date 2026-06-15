class Solution {
public:
    void f(int idx, string digits, vector<string>& ans, string comb, unordered_map<char, vector<char>>& mp){
        if(idx == digits.length()){
            ans.push_back(comb);
            return;
        }
        char d = digits[idx];
        for(char ch : mp[d]){
            comb.push_back(ch);
            f(idx+1, digits, ans, comb, mp);
            comb.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> mp;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        vector<string> ans;
        f(0, digits, ans, {}, mp);
        return ans;
    }
};
