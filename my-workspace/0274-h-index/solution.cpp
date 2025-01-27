class Solution {
public:
    int hIndex(vector<int>& citations) {
        int hindex;
        int n = citations.size();
        sort(citations.begin(), citations.end());
        reverse(citations.begin(), citations.end());
        if(citations[0] == 0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(citations[n-1] >= n){
            return n;
        }
        for(int i=0; i<n; i++){
            if(citations[i] >= i+1){
                hindex = i+1;
            }
        }
        return hindex;
    }
};
