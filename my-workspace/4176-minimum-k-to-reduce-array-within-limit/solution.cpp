class Solution {
public:
    int minimumK(vector<int>& nums) {
        int n=nums.size();
        int maxVal = INT_MIN;
        for(auto num : nums){
            maxVal = max(maxVal, num);
        }
        auto fn=[&](long long k)->int{
            int ops=0;
            for(auto num:nums) ops+=((num+k-1)/k);
            return (ops<=k*k);
        };

        int left=1;
        int right=max(maxVal, n);
        int found=-1;
        while(left<=right){
            auto mid=left+(right-left)/2;
            if(fn(mid)){
                found=mid;
                right=mid-1;
            }else left=mid+1;
        }

        return found;
    }
};
