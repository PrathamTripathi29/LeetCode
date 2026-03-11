class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k > n) return -1;
        int low = INT_MAX;
        int high = INT_MIN;
        for(int day : bloomDay){
            low = min(low, day);
            high = max(high, day);
        }
        while(low <= high){
            int mid = low + (high - low)/2;
            int consecKBlooms = 0;
            int consecBlooms = 0;
            for(int i=0; i<n; i++){
                if(bloomDay[i] <= mid){
                    consecBlooms++;
                } else {
                    consecKBlooms += consecBlooms/k;
                    consecBlooms = 0;
                }
            }
            consecKBlooms += consecBlooms/k;
            if(consecKBlooms >= m){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
