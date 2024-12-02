class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(count == 0){
                candidate = nums.at(i);
                count++;
            }
            else{
                if(candidate == nums.at(i)){
                    count++;
                }
                else{
                    count--;
                }
            }
        }
     return candidate;
}
};
