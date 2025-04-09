class Solution {
public:
    bool check(vector<int> arr, int size){
        for(int i=0; i<size-1; i++){
            if(arr[i] > arr[i+1]){
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int k = 0;
        int size = nums.size();
        pair<int,int> indices;
        int sum = INT_MAX;
        while(!check(nums,size)){
            for(int i=0; i<size-1; i++){
                if(nums[i] + nums[i+1] < sum){
                    sum = nums[i] + nums[i+1];
                    indices.first = i;
                    indices.second = i+1;
                }
            }
            nums[indices.first] = sum;
            for(int i=indices.second; i<size-1; i++){
                nums[i] = nums[i+1];
            }
            size--;
            sum = INT_MAX;
            k++;
        }
        return k;
    }
};
