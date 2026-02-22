class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        int score1 = 0;
        int score2 = 0;
        bool active = true;
        for(int i=0; i<n; i++){
            if(nums[i] % 2 != 0){
                active = !active;
            }
            if((i+1)%6 == 0){
                active = !active;
            }
            if(active){
                score1 += nums[i];
            } else {
                score2 += nums[i];
            }
        }
        return score1 - score2;
    }
};
