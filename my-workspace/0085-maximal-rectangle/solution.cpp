class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextSmaller(n);
        vector<int> prevSmaller(n);
        stack<int> s;
        for(int i=0; i<n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            prevSmaller[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while(s.size()) s.pop();
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            nextSmaller[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            int l = prevSmaller[i];
            int r = nextSmaller[i];
            ans = max(ans, (r-l-1)*heights[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};
