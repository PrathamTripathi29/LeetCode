class Solution {
public:
    int reversenum(int num){
        int rev = 0;
        while(num > 0){
            rev = rev*10 + (num%10);
            num /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mindist = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            auto it = mp.find(num);
            if(it != mp.end()){
                mindist = min(mindist, abs(it->second - i));
            }
            int rev = reversenum(num);
            mp[rev] = i;
        }
        if(mindist == INT_MAX) return -1;
        return mindist;
    }
};
