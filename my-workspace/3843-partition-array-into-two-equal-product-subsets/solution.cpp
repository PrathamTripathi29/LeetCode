typedef __int128 ll;
class Solution {
public:
    bool helper(int i, ll product, ll target, vector<int> &nums){
        if(product > target){
            return false;
        }
        if(product == target){
            return true;
        }
        if(i == nums.size()){
            return false;
        }

        if(helper(i+1, product*nums[i], target, nums)){
            return true;
        }

        if(helper(i+1, product, target, nums)){
            return true;
        }
        return false;
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        ll product = 1;
        for(auto num : nums){
            product *= num;
        }
        if(product/(ll)target != (ll)target){
            return false;
        }

        return helper(0, 1, target, nums);
    }
};
