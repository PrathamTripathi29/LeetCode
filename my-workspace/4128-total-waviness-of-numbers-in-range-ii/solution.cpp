class Solution {
public:
    long long dp[30][30][11][11][2][2];
    long long f(string& num, int pos, int sum, int prev, int prev2, bool small, bool nz){
        if(pos == num.length()) return sum;
        if(dp[pos][sum][prev][prev2][small][nz] != -1){
            return dp[pos][sum][prev][prev2][small][nz];
        }
        int lim = small ? 9 : num[pos]-'0';
        long long ans = 0;
        for(int i=0; i<=lim; i++){
            bool nsmall = small || i < num[pos] - '0';
            bool nnz = nz || (i != 0);
            if(nnz){
                int nsum = sum;
                if(prev != 10 && prev2 != 10){
                    nsum += prev2 < prev && prev > i;
                    nsum += prev2 > prev && prev < i;
                }
                ans += f(num, pos+1, nsum, i, prev, nsmall, nnz);
            } else {
                ans += f(num, pos+1, sum, prev, prev2, nsmall, nnz);
            }
        }
        return dp[pos][sum][prev][prev2][small][nz] = ans;
    }
    long long totalWaviness(long long num1, long long num2) {
        string n1 = to_string(num1-1);
        string n2 = to_string(num2);
        memset(dp, -1, sizeof(dp));
        long long ans2 = f(n2, 0, 0, 10, 10, false, false);
        memset(dp, -1, sizeof(dp));
        long long ans1 = f(n1, 0, 0, 10, 10, false, false);
        return ans2 - ans1;
    }
};
