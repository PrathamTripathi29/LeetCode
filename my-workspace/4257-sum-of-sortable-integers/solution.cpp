class Solution {
public:
    bool check(vector<int>&nums, int k){
        int n = nums.size();
        int prevMax = INT_MIN;
        for(int i=0; i<n; i += k){
            int drops = 0;
            int currMax = nums[i];
            if(currMax < prevMax) return false;
            for(int j=i+1; j<i+k; j++){
                if(nums[j] < nums[j-1]) drops++;
                if(nums[j] < prevMax) return false;
                currMax = max(currMax, nums[j]);
            }
            if(drops > 1) return false;
            if(drops == 1){
                if(nums[i+k-1] > nums[i]) return false;
            }
            prevMax = currMax;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ks;
        for(int k=1; k<=n; k++){
            if(n%k==0) ks.push_back(k);
        }
        int sum = 0;
        for(int i=0; i<ks.size(); i++){
            int k = ks[i];
            if(check(nums, k)) sum += k;
        }
        return sum;
    }
};
