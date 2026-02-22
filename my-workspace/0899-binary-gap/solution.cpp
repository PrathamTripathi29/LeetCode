class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        string binn;
        while(n > 0){
            int dig = n%2;
            binn.push_back(dig + '0');
            n /= 2;
        }
        int l = 0;
        bool flag = false;
        for(int i=0; i<binn.length(); i++){
            if(binn[i] == '1'){
                if(flag) ans = max(i-l, ans);
                l = i;
                flag = true;
            }
        }
        return ans;
    }
};
