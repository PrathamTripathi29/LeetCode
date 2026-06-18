class Solution {
public:
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextSmaller(n);
        vector<int> prevSmaller(n);
        stack<int> s;
        for(int i=0; i<n; i++){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            prevSmaller[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while(s.size()) s.pop();
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && arr[s.top()] > arr[i]){
                s.pop();
            }
            nextSmaller[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            long long l = i - prevSmaller[i];
            long long r = nextSmaller[i] - i;
            long long val = (l*r*arr[i])%mod;
            ans = (ans + val)%mod;
        }
        return ans;
    }
};
