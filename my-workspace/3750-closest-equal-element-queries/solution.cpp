class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);

        }
        vector<int> answer(m);
        for(int i=0; i<m; i++){
            int idx = queries[i];
            int num = nums[idx];
            if(mp.find(num) == mp.end() || mp[num].size() < 2){
                answer[i] = -1;
                continue;
            }
            vector<int>& indices = mp[num];
            int index = lower_bound(indices.begin(), indices.end(), idx) - indices.begin();
            int l = indices[(index-1+indices.size())%indices.size()];
            int r = indices[(index+1)%indices.size()];
            int dl = abs(idx - l);
            int dr = abs(idx - r);
            answer[i] = min({dl, n - dl, dr, n - dr});
        }
        return answer;
    }
};
