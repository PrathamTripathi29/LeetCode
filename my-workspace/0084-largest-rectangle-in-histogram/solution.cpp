class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> nextSmaller(n,n);
        vector<int> prevSmaller(n, -1);
        for(int i=0; i<n; i++){
            while(!s.empty() && heights[s.top()] > heights[i]){
                nextSmaller[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while(s.size()) s.pop();
        for(int i= n-1; i>=0; i--){
            while(!s.empty() && heights[s.top()] > heights[i]){
                prevSmaller[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, (nextSmaller[i] - prevSmaller[i] - 1)*heights[i]);
        }
        return ans;
    }
};
