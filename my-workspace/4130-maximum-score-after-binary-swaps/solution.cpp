class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n = nums.size();
        int st = 0;
        int en = n-1;
        while(st < n && s[st] == '1'){
            st++;
        }
        while(en >= 0 && s[en] == '0'){
            en--;
        }
        long long score = 0;
        for(int i=0; i<st; i++){
            if(s[i] == '1'){
                score += nums[i];
            }
        }
        for(int i=en+1; i<n; i++){
            if(s[i] == '1'){
                score += nums[i];
            }
        }
        int currmax = INT_MIN;
        int idx = st;
        priority_queue<int> pq;
        for(int i = idx; i<= en; i++){
            pq.push(nums[i]);
            if(s[i] == '1'){
                score += pq.top();
                pq.pop();
            }
        }
        return score;
    }
};
