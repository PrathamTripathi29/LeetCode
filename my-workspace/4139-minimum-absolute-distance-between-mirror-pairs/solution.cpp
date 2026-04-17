class Solution {
public:
    int reverse(int num){
        int revnum = 0;
        while(num > 0){
            revnum *= 10;
            revnum += num%10;
            num /= 10;
        }
        return revnum;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int minDist = INT_MAX;
        for(int i=0; i<n; i++){
            int revnum = reverse(nums[i]);
            if(mp.find(nums[i]) != mp.end()){
                minDist = min(minDist, i - mp[nums[i]]);
            }
            mp[revnum] = i;
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
};
