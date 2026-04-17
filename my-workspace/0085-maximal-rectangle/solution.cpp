class Solution {
public:
    int calcarea(vector<int>& heights){
        int n = heights.size();
        stack<int> s;
        int area = 0;
        for(int i=0; i<=n; i++){
            int h = (i==n) ? 0 : heights[i];
            while(!s.empty() && h < heights[s.top()]){
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                area = max(area, height*width);
            }
            s.push(i);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            ans = max(ans, calcarea(heights));
        }
        return ans;
    }
};
