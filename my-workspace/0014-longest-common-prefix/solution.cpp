class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int count = 0;
        if(strs.size() == 1){
            return strs[0];
        }
        for(int i=0; i< strs.size()-1; i++){
            int j=0;
            string temp = "";
            while(j < strs[i].size() && j < strs[i+1].size() && strs[i][j] == strs[i+1][j]){
                temp += strs[i][j];
                j++;
            }
            if(count == 0){
                ans = temp;
                count++;
            }
            if(count == 1 && temp.size() < ans.size()){
                ans = temp;
            }
        }
        return ans;
    }
};
