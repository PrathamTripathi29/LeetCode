class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        for(int weight : weights){
            sum += weight;
        }
        int low = 1;
        int high = sum;
        while(low <= high){
            int mid = low + (high-low)/2;
            int d = 1;
            int currw = 0;
            for(int i=0; i<n; i++){
                if(weights[i] > mid){
                    d = INT_MAX;
                    break;
                }
                currw += weights[i];
                if(currw > mid){
                    d++;
                    currw = weights[i];
                }
            }
            if(d <= days){
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};
