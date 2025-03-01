class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> ans;
        int even, odd;
        even = 0, odd = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2 == 0){
                even++;
            }
            else{
                odd++;
            }
        }
        for(int i=0; i<even; i++){
            ans.push_back(0);
        }
        for(int i=0; i<odd; i++){
            ans.push_back(1);
        }
        return ans;
    }
};
