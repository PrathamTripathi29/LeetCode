class Solution {
public:
    long long numOfSubsequences(string s) {
        int l = s.length();
        vector<long long> prefix(l+1, 0);
        vector<long long> suffix(l+1, 0);
        for(int i=0; i<l; i++){
            if(s[i] == 'L'){
                prefix[i+1] = 1;
            }
            prefix[i+1] += prefix[i];
        }
        for(int i=l-1; i>=0; i--){
            if(s[i] == 'T'){
                suffix[i] = 1;
            }
            suffix[i] += suffix[i+1];
        }
        long long combinationsWithC = 0;
        long long combinationsWithL = 0;
        long long combinationsWithT = 0;
        long long maxWithC = 0;
        for(int i=0; i<l; i++){
            if(s[i] == 'C'){
                combinationsWithC += prefix[i]*suffix[i+1];
                combinationsWithL += (prefix[i]+1)*suffix[i+1];
                combinationsWithT += (prefix[i])*(suffix[i+1] + 1);
            } else {
                maxWithC = max(maxWithC, prefix[i]*suffix[i]);
            }
        }
        combinationsWithC += maxWithC;
        return max({combinationsWithL, combinationsWithT, combinationsWithC});
    }
};
