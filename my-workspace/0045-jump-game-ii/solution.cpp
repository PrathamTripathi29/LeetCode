class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, currentend = 0, farthest = 0, size = nums.size();
        for(int i=0; i<size-1; i++){
            farthest = max(farthest, i+nums[i]);
            if(i == currentend){
                jumps++;
                currentend = farthest;
            }
            if(currentend >= size-1){
                break;
            }
        }
        return jumps;
    }
};
