class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<pair<int,int>> countarr(size, {0,0});
        for(int a=0; a<size; a++){
            string str = strs[a];
            int count0 = 0, count1 = 0;
            for(int i=0; i<str.length(); i++){
                if(str[i] == '0'){
                    count0++;
                } else{
                    count1++;
                }
            }
            countarr[a] = {count0, count1};
        }
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=0; i<size; i++){
            for(int j = m; j >= countarr[i].first; j--){
                for(int k = n; k >= countarr[i].second; k--){
                    dp[j][k] = max(dp[j][k], dp[j-countarr[i].first][k-countarr[i].second] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
