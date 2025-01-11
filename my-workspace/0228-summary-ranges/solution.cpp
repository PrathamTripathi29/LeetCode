class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int size = nums.size();
        vector<string> ans;
        string range = "";
        for(int i=0; i<size; i++){
            int j;
            j = i;
            while(j<size-1 && nums[j+1] == nums[j] + 1){
                j++;
            }
            if(j>i){
                range = range + to_string(nums[i]);
                range = range + "->";
                range = range + to_string(nums[j]);
            }
            else{
                range = range + to_string(nums[i]);
            }

            ans.push_back(range);
            range = "";
            i = j;
        }
        return ans;
    }
};
