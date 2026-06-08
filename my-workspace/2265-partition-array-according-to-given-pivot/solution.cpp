class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> right;
        int l=0;
        int mid=0;
        for(int num : nums){
            if(num < pivot){
                nums[l] = num;
                l++;
            } else if(num > pivot){
                right.push_back(num);
            } else {
                mid++;
            }
        }
        for(int i=0; i<mid; i++){
            nums[l] = pivot;
            l++;
        }
        for(int i=0; i<right.size(); i++){
            nums[l] = right[i];
            l++;
        }
        return nums;
    }
};
