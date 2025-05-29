class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        vector<int> temp;
        for(int i = (size - k); i<size; i++){
            int a = nums[i];
            temp.push_back(a);
        }
        for(int i = (size - k - 1); i>=0; i--){
            nums[i+k] = nums[i];
        }
        for(int i=0; i<k; i++){
            nums[i] = temp[i];
        }
    }
};
