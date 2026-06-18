class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> nextGreater(n);
        vector<int> prevGreater(n);
        int mx = 0;
        for(int i=0; i<n; i++){
            prevGreater[i] = mx;
            mx = max(mx, height[i]);
        }
        mx = 0;
        for(int i=n-1; i>=0; i--){
            nextGreater[i] = mx;
            mx = max(mx, height[i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            int w = min(nextGreater[i], prevGreater[i]);
            ans += max(0, (w-height[i]));
        }
        return ans;
    }
};
