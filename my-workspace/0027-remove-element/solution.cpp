class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int size = nums.size();
        for(int i=0; i<size; i++){
            if(nums.at(i) == val){
                for(int j = i+1; j<size; j++){
                    nums.at(j-1) = nums.at(j);
                }
                k++;
                i--;
                size--;
            }
        }
        return nums.size() - k;
    }
};
