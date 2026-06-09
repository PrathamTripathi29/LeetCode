class Solution {
public:
    bool check(int mid, vector<int>& bloomDay, int m, int k){
        int bloomed = 0;;
        int bouqets = 0;
        for(int d : bloomDay){
            if(d <= mid){
                bloomed++;
            } else {
                bouqets += bloomed/k;
                bloomed = 0;
            }
        }
        bouqets += bloomed/k;
        return bouqets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n/k < m) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(mid, bloomDay, m, k)){
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};
