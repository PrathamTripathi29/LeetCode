class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powers;
        int num = n;
        int val = 1;
        while(num > 0){
            if(num & 1){
                powers.push_back(val);
            }
            val = (val*2)%mod;
            num >>= 1;
        }
        int size = queries.size();
        vector<int> ans(size, 0);
        for(int i=0; i<size; i++){
            int prod = 1;
            for(int j = queries[i][0]; j<= queries[i][1]; j++){
                prod = (prod * powers[j]) % mod;
            }
            ans[i] = prod;
        }
        return ans;
    }
};
