class Solution {
public:
    bool check(long long mid, int h, vector<int> piles){
        long long reqHours = 0;
        for(int pile : piles){
            reqHours += ceil((double)pile/mid);
        }
        return reqHours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            long long mid = low + (high-low)/2;
            if(check(mid, h, piles)){
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};
