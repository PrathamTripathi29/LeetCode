class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int i =0;
        string ans = "";
        while(i < strs[0].length() && i < strs[strs.size()-1].length()){
            if(strs[0][i] == strs[strs.size()-1][i]){
                ans += strs[0][i];
            }
            else{
                break;
            }
            i++;
        }
        return ans;
    }
};
