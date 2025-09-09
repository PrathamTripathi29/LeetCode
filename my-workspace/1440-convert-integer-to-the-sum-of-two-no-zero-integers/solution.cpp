class Solution {
public:
    bool nozero(int n){
        string num = to_string(n);
        for(int i=0; i<num.length(); i++){
            if(num[i] == '0') return false;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1; i<n; i++){
            int n1 = i;
            int n2 = n-i;
            if(nozero(n1) && nozero(n2)) return {n1, n2};
        }
        return {};
    }
};
