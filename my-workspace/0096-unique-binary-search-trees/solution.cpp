class Solution {
public:
    int numTrees(int n) {
        vector<int> uniqueBST(n+1, 0);
        uniqueBST[0] = uniqueBST[1] = 1;
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++){
                uniqueBST[i] += uniqueBST[j-1]*uniqueBST[i-j];
            }
        }
        return uniqueBST[n];
    }
};
