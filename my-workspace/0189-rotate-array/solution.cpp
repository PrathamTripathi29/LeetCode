class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k%size;
        for(int i=0; i<size/2; i++){
            swap(nums[i], nums[size-1-i]);
        }
        for(int i=0; i<k/2; i++){
            swap(nums[i], nums[k-1-i]);
        }
        for(int i=0; i<(size-k)/2; i++){
            swap(nums[k+i], nums[size-1-i]);
        }
    }
};
