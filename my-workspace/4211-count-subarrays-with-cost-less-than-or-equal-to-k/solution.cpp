class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0;
        deque<int> mx, mn;
        int l = 0;
        for(int r = 0; r < n; r++){
            while(mx.size() && nums[mx.back()] <= nums[r]){
                mx.pop_back();
            }
            while(mn.size() && nums[mn.back()] >= nums[r]){
                mn.pop_back();
            }
            mx.push_back(r);
            mn.push_back(r);
            while((long long)(nums[mx.front()] - nums[mn.front()]) * (r - l + 1) > k){
                if(mx.front() == l){
                    mx.pop_front();
                }
                if(mn.front() == l){
                    mn.pop_front();
                }
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};
