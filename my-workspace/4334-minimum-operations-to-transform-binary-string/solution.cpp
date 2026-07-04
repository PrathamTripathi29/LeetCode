class Solution {
public:
    int minOperations(string s1, string s2) {
        int count = 0;
        int n = s1.length();
        if(n == 1){
            if(s1[0] == s2[0]) return 0;
            if(s1[0] == '1' && s2[0] == '0') return -1;
            return 1;
        }
        for(int i=0; i<n; i++){
            if(s1[i] == '0' && s2[i] == '1'){
                count++;
            } else if(s1[i] == '1' && s2[i] == '0'){
                int continuous = 0;
                while(i<n && s1[i] == '1' && s2[i] == '0'){
                    continuous++;
                    i++;
                }
                count += continuous/2;
                if(continuous&1) count += 2;
                i--;
            }
        }
        return count;
    }
};
