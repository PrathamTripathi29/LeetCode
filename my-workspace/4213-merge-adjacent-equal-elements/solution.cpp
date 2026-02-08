class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans;
        stack<long long> s;
        for(int i=0; i<n; i++){
            if(s.empty()){
                s.push(nums[i]);
                continue;
            }
            while(i < n && s.top() == nums[i]){
                long long sum = s.top() + nums[i];
                s.pop();
                while(!s.empty() && s.top() == sum){
                    sum = sum + s.top();
                    s.pop();
                }
                s.push(sum);
                i++;
            }
            if(i < n) s.push(nums[i]);
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
