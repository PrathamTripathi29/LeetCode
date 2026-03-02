class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeroes(n);
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=n-1; j>=0; j--){
                if(grid[i][j] == 0){
                    count++;
                } else {
                    break;
                }
            }
            zeroes[i] = count;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            int req = n-1-i;
            int j = i;
            while(j < n && req > zeroes[j]) j++;
            if(j == n) return -1;
            while(j > i){
                swap(zeroes[j], zeroes[j-1]);
                j--;
                ans++;
            }
        }
        return ans;
    }
};
