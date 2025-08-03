class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i < n-1 && nums[i+1] > nums[i]){
            i++;
        }
        if(i == 0){
            return false;
        }
        int check = i;
        while(i < n-1 && nums[i+1] < nums[i]){
            i++;
        }
        if(i == check){
            return false;
        }
        check = i;
        while(i < n-1 && nums[i+1] > nums[i]){
            i++;
        }
        if( i == check){
            return false;
        }
        if( i != n-1){
            return false;
        }
        return true;
    }
};
