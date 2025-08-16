class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int prev = -1, prevtoprev = -1, left = 0, right = 0, maxfruit = 0;
        for(int i=0; i<fruits.size(); i++){
            if(fruits[i] == prev || fruits[i] == prevtoprev){
                right++;
            } else{
                right = left + 1;
            }
            if(fruits[i] == prev){
                left++;
            } else{
                left = 1;
                prevtoprev = prev;
                prev = fruits[i];
            }
            maxfruit = max(maxfruit, right);
        }
        return maxfruit;
    }
};
