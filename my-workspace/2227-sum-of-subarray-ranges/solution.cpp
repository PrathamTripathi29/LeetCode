class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long mnsum = 0;
        long long mxsum = 0;
        vector<int> nextSmaller(n);
        vector<int> prevSmaller(n);
        vector<int> nextGreater(n);
        vector<int> prevGreater(n);
        stack<int> s;
        for(int i=0; i<n; i++){
            while(!s.empty() && nums[s.top()] >= nums[i]){
                s.pop();
            }
            prevSmaller[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while(s.size()) s.pop();
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && nums[s.top()] > nums[i]){
                s.pop();
            }
            nextSmaller[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        while(s.size()) s.pop();
        for(int i=0; i<n; i++){
            while(!s.empty() && nums[s.top()] <= nums[i]){
                s.pop();
            }
            prevGreater[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while(s.size()) s.pop();
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && nums[s.top()] < nums[i]){
                s.pop();
            }
            nextGreater[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        for(int i=0; i<n; i++){
            long long l = i-prevSmaller[i];
            long long r = nextSmaller[i]-i;
            mnsum += l*r*nums[i];
            l = i-prevGreater[i];
            r = nextGreater[i]-i;
            mxsum += l*r*nums[i];
        }
        return mxsum-mnsum;
    }
};
