class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                if(str1[i] == str2[j]) dp[i+1][j+1] = 1 + dp[i][j];
                else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        string str = "";
        int i = n1-1;
        int j = n2-1;
        while(i >= 0 && j >= 0){
            if(str1[i] == str2[j]){
                str += str1[i];
                i--;
                j--;
            }
            else{
                if(dp[i+1][j] > dp[i][j+1]){
                    str += str2[j];
                        j--;
                    }else{
                        str += str1[i];
                        i--;
                    }
                }
        }
        while(i >= 0){
            str += str1[i];
            i--;
        }
        while(j >= 0){
            str += str2[j];
            j--;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
