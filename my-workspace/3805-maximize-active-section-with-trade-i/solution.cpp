class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int count1 = 0;
        for(char ch : s){
            if(ch == '1'){
                count1++;
            }
        }
        s = '1' + s;
        s = s + '1';
        int n = s.length();
        vector<int> lens;
        int count0 = 0;
        for(int i=1; i<n; i++){
            if(s[i] == '1'){
                if(count0 > 0){
                    lens.push_back(count0);
                    count0 = 0;
                }
            } else {
                count0++;
            }
        }
        int l = lens.size();
        int mx = 0;
        for(int i=0; i<l-1; i++){
            mx = max(mx, lens[i] + lens[i+1]);
        }
        return mx + count1;
    }
};
