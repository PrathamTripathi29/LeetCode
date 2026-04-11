class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        int minDist = INT_MAX;
        for(auto &it : mp){
            int num = it.first;
            if(it.second.size() >= 3){
                for(int i=2; i<it.second.size(); i++){
                    int p1 = it.second[i];
                    int p2 = it.second[i-1];
                    int p3 = it.second[i-2];
                    int dist = abs(p1-p2) + abs(p2-p3) + abs(p3-p1);
                    minDist=min(minDist, dist);
                }
            } 
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
};
