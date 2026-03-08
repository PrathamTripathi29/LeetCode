class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        // int prev = stoi(nums[0], nullptr, 2);
        // string ans0(n, '0');
        // if(prev != 0) return ans0;
        // for(int i=1; i<n; i++){
        //     int num = stoi(nums[i], nullptr, 2);
        //     if(prev + 1 != num){
        //         string ans;
        //         int newNum = prev+1;
        //         while(newNum > 0){
        //             int dig = newNum%2;
        //             ans += (dig + '0');
        //             newNum /= 2;
        //         }
        //         while(ans.length() < n){
        //             ans += '0';
        //         }
        //         reverse(ans.begin(), ans.end());
        //         return ans;
        //     }
        //     prev = num;
        // }
        // string ans;
        // int newNum = stoi(nums[n-1], nullptr, 2) + 1;
        // while(newNum > 0){
        //     int dig = newNum%2;
        //     ans += (dig + '0');
        //     newNum /= 2;
        // }
        // while(ans.length() < n){
        //             ans += '0';
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;
        string ans;
        for(int i=0; i<n; i++){
            if(nums[i][i] == '0'){
                ans += '1';
            } else {
                ans += '0';
            }
        }
        return ans;
    }
};
