class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(auto str : strs){
            string temp;
            int i=0;
            while(i < ans.size() && i < str.size()){
                if(ans[i] == str[i]){
                    temp += ans[i];
                    i++;
                } else {
                    break;
                }
            }
            ans = temp;
        }
        return ans;
    }
};
