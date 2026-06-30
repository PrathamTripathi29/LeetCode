class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int count = 0;
        vector<int> candies(n, 0);
        candies[0] = 1;
        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            } else {
                candies[i] = 1;
            }
        }
        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                if(candies[i] <= candies[i+1]) candies[i] = candies[i+1] + 1;
            }
        }
        for(int i=0; i<n; i++){
            count += candies[i];
        }
        return count;
    }
};
