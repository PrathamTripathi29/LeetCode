class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr(n, 0);
         for(int i=0; i<n-1; i += 2){
             arr[i] = (i+1);
             arr[i+1] = -(i+1);
        }
        return arr;
    }
};
